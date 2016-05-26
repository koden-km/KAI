#include <KAI/Language/Common/ParserCommon.h>
#include <KAI/Language/Common/Structure.h>
#include <Tau/TauParser.h>

KAI_BEGIN

void TauParser::Process(std::shared_ptr<Lexer> lex, Structure st)
{
	current = 0;
	indent = 0;
	lexer = lex;

	if (lexer->Failed)
		return;

	// strip whitespace and comments
	for (auto tok : lexer->GetTokens())
		if (tok.type != TokenEnum::Whitespace && tok.type != TokenEnum::Comment)
			tokens.push_back(tok);

	root = NewNode(AstEnum::Program);

	KAI_UNUSED_1(st);
	Run(Structure::Program);
}

void TauParser::Run(Structure st)
{
	switch (st)
	{
	case Structure::Statement:
		if (!Statement(root))
		{
			CreateError("Statement expected");
			return;
		}
		break;

	case Structure::Expression:
		if (!Expression())
		{
			CreateError("Expression expected");
			return;
		}
		root->Add(Pop());
		break;

	case Structure::Function:
		Function(root);
		break;

	case Structure::Program:
		Program();
		break;
	}

	if (!stack.empty())
		Fail("Internal error: Stack not empty after parsing");
}

bool TauParser::Program()
{
	while (!Try(TokenType::None) && !Failed)
	{
		ConsumeNewLines();
		Statement(root);
	}

	return true;
}

void TauParser::Function(AstNodePtr node)
{
	ConsumeNewLines();

	Expect(TokenType::Fun);
	Expect(TokenType::Ident);
	TauToken name = Last();
	std::shared_ptr<AstNode> fun = NewNode(AstEnum::Function);
	fun->Add(name);
	Expect(TokenType::OpenParan);
	std::shared_ptr<AstNode> args = NewNode(AstEnum::None);
	fun->Add(args);

	if (Try(TokenType::Ident))
	{
		args->Add(Consume());
		while (Try(TokenType::Comma))
		{
			Consume();
			args->Add(Expect(TokenType::Ident));
		}
	}

	Expect(TokenType::CloseParan);
	Expect(TokenType::NewLine);
	
	AddBlock(fun);
	node->Add(fun);
}

void TauParser::Block(AstNodePtr node)
{
	ConsumeNewLines();

	++indent;
	while (!Failed)
	{
		int level = 0;
		while (Try(TokenType::Tab))
		{
			++level;
			Consume();
		}

		if (Try(TokenType::NewLine))
		{
			Consume();
			continue;
		}

		// close current block
		if (level < indent)
		{
			--indent;

			// rewind to start of tab sequence to determine next block
			--current;
			while (Try(TokenType::Tab))
				--current;

			++current;
			return;
		}

		if (level != indent)
		{
			Fail(Lexer::CreateErrorMessage(Current(), "Mismatch block indent"));
			return;
		}

		Statement(node);
	}
}

bool TauParser::Statement(AstNodePtr block)
{
	switch (Current().type)
	{
		case TokenType::Assert:
		{
			Consume();
			if (!Expression())
			{
				Fail(Lexer::CreateErrorMessage(Current(), "Assert needs an expression to test"));
				return false;
			}

			auto ass = NewNode(Consume());
			ass->Add(Pop());
			Push(ass);
			goto finis;
		}

		case TokenType::Return:
		case TokenType::Yield:
		{
			auto ret = NewNode(Consume());
			if (Expression())
				ret->Add(Pop());
			block->Add(ret);
			goto finis;
		}
		
		case TokenType::While:
		{
			While(block);
			return true;
		}

		case TokenType::For:
		{
			For(block);
			return true;
		}

		case TokenType::If:
		{
			IfCondition(block);
			return true;
		}
		
		case TokenType::Fun:
		{
			Function(block);
			return true;
		}
	}

	if (!Expression())
		return false;

	block->Add(Pop());

finis:
	// statements can end with an optional semi followed by a new line
	if (Try(TokenType::Semi))
		Consume();

	Expect(TokenType::NewLine);

	return true;
}

bool TauParser::Expression()
{
	bool paran = Try(TokenType::OpenParan);
	if (paran)
	{
		Consume();
		if (!Expression())
			return false;

		Expect(TokenType::CloseParan);
		return true;
	}

	if (!Logical())
		return false;

	if (Try(TokenType::Assign) || Try(TokenType::PlusAssign) || Try(TokenType::MinusAssign) || Try(TokenType::MulAssign) || Try(TokenType::DivAssign))
	{
		auto node = NewNode(Consume());
		auto ident = Pop();
		if (!Logical())
		{
			Fail(Lexer::CreateErrorMessage(Current(), "Assignment requires an expression"));
			return false;
		}

		node->Add(Pop());
		node->Add(ident);
		Push(node);
	}

	return true;
}

bool TauParser::Logical()
{
	if (!Relational())
		return false;

	while (Try(TokenType::And) || Try(TokenType::Or))
	{
		auto node = NewNode(Consume());
		node->Add(Pop());
		if (!Relational())
			return Fail(Lexer::CreateErrorMessage(Current(), "Relational expected"));

		node->Add(Pop());
		Push(node);
	}

	return true;
}

bool TauParser::Relational()
{
	if (!Additive())
		return false;

	while (Try(TokenType::Less) || Try(TokenType::Greater) || Try(TokenType::Equiv) || Try(TokenType::NotEquiv)
		|| Try(TokenType::LessEquiv) || Try(TokenType::GreaterEquiv))
	{
		auto node = NewNode(Consume());
		node->Add(Pop());
		if (!Additive())
			return CreateError("Additive expected");

		node->Add(Pop());
		Push(node);
	}

	return true;
}

bool TauParser::Additive()
{
	// unary +/- operator
	if (Try(TokenType::Plus) || Try(TokenType::Minus))
	{
		auto ty = Consume().type;
		Consume();
		if (!Term())
			return CreateError("Term expected");

		auto node = new AstNode(ty == TokenType::Plus ? NodeType::Positive : NodeType::Negative);
		node->Add(Pop());
		return true;
	}

	if (!Term())
		return false;

	while (Try(TokenType::Plus) || Try(TokenType::Minus))
	{
		auto node = NewNode(Consume());
		node->Add(Pop());
		if (!Term())
			return CreateError("Term expected");

		node->Add(Pop());
		Push(node);
	}

	return true;
}

bool TauParser::Term()
{
	if (!Factor())
		return false;

	while (Try(TokenType::Mul) || Try(TokenType::Divide))
	{
		auto node = NewNode(Consume());
		node->Add(Pop());
		if (!Factor())
			return CreateError("Factor expected with a term");

		node->Add(Pop());
		Push(node);
	}

	return true;
}

bool TauParser::Factor()
{
	if (Try(TokenType::OpenParan))
	{
		Consume();
		if (!Expression())
		{
			CreateError("Expected an expression for a factor in parenthesis");

			return false;
		}

		Expect(TokenType::CloseParan);
		return true;
	}

	if (Try(TokenType::OpenSquareBracket))
	{
		auto list = NewNode(NodeType::List);
		do
		{
			Consume();
			if (Expression())
				list->Add(Pop());
			else
				list->Add(0);
		}
		while (Try(TokenType::Comma));

		Expect(TokenType::CloseSquareBracket);
		Push(list);

		return true;
	}

	if (Try(TokenType::Int) || Try(TokenType::Float) || Try(TokenType::String) || Try(TokenType::True) || Try(TokenType::False))
		return PushConsume();

	if (Try(TokenType::Self))
		return PushConsume();

	while (Try(TokenType::Lookup))
		PushConsume();

	if (Try(TokenType::Ident))
		return ParseFactorIdent();

	return false;
}

//warning C4127: conditional expression is constant
#pragma warning (disable:4127)

bool TauParser::ParseFactorIdent()
{
	PushConsume();

	while (true)
	{
		if (Try(TokenType::Dot))
		{
			ParseGetMember();
			continue;
		}

		if (Try(TokenType::OpenParan))
		{
			ParseMethodCall();
			continue;
		}

		if (Try(TokenType::OpenSquareBracket))
		{
			ParseIndexOp();
			continue;
		}

		break;
	}

	return true;
}

void TauParser::ParseMethodCall()
{
	Consume();
	auto call = NewNode(NodeType::Call);
	call->Add(Pop());
	auto args = NewNode(NodeType::ArgList);
	call->Add(args);

	if (Expression())
	{
		args->Add(Pop());
		while (Try(TokenType::Comma))
		{
			Consume();
			if (!Expression())
			{
				Fail("What is the next argument?");
				return;
			}

			args->Add(Pop());
		}
	}

	Push(call);
	Expect(TokenType::CloseParan);

	if (Try(TokenType::Replace))
		call->Add(Consume());
}

void TauParser::ParseGetMember()
{
	Consume();
	auto get = NewNode(NodeType::GetMember);
	get->Add(Pop());
	get->Add(Expect(TokenType::Ident));
	Push(get);
}

void TauParser::IfCondition(AstNodePtr block)
{
	if (!Try(TokenType::If))
		return;

	Consume();

	// get the test expression
	if (!Expression())
	{
		CreateError("If what?");
		return;
	}

	auto condition = Pop();
	//Expect(TokenType::CloseParan);

	// get the true-clause
	auto trueClause = NewNode(NodeType::Block);
	Block(trueClause);

	// make the conditional node in AST
	auto cond = NewNode(NodeType::Conditional);
	cond->Add(condition);
	cond->Add(trueClause);

	// if there's an else, add it as well
	if (Try(TokenType::Else))
	{
		Consume();
		auto falseClause = NewNode(NodeType::Block);
		Block(falseClause);
		cond->Add(falseClause);
	}

	block->Add(cond);
}

void TauParser::ParseIndexOp()
{
	Consume();
	auto index = NewNode(NodeType::IndexOp);
	index->Add(Pop());
	if (!Expression())
	{
		CreateError("Index what?");
		return;
	}

	Expect(TokenType::CloseSquareBracket);
	index->Add(Pop());
	Push(index);
}

void TauParser::For(AstNodePtr block)
{
	if (!Try(TokenType::For))
		return;

	Consume();

	auto f = NewNode(TauAstNodeEnumType::For);
	if (!Expression())
	{
		CreateError("For what?");
		return;
	}

	if (Try(TokenType::In))
	{
		Consume();
		f->Add(Pop());

		if (!Expression())
		{
			CreateError("For each in what?");
			return;
		}

		f->Add(Pop());
	}
	else
	{
		Expect(TokenType::Semi);
		f->Add(Pop());

		if (!Expression())
		{
			CreateError("When does the for statement stop?");
			return;
		}

		f->Add(Pop());
		Expect(TokenType::Semi);

		if (!Expression())
		{
			CreateError("What happens when a for statement ends?");
			return;
		}

		f->Add(Pop());
	}

	Expect(TokenType::NewLine);
	AddBlock(f);
	block->Add(f);
}

void TauParser::While(AstNodePtr block)
{
	auto w = NewNode(Consume());
	if (!Expression())
	{
		CreateError("While what?");
		return;
	}

	w->Add(Pop());
	block->Add(w);
}

bool TauParser::CreateError(const char *text)
{
	return Fail(Lexer::CreateErrorMessage(Current(), text));
}

void TauParser::AddBlock(AstNodePtr fun)
{
	auto block = NewNode(TauAstNodeEnumType::Block);
	Block(block);
	fun->Add(block);
}

void TauParser::ConsumeNewLines()
{
	while (Try(TokenType::NewLine))
		Consume();
}
KAI_END