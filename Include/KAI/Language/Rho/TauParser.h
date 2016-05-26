#pragma once

#include "KAI/Language/Rho/RhoAstNode.h"
#include "KAI/Language/Rho/TauLexer.h"

KAI_BEGIN

// parser specific to the in-fix Rho language
class RhoParser : public ParserCommon<RhoLexer, RhoAstNodeEnumType>
{
public:
	typedef ParserCommon<RhoLexer, RhoAstNodeEnumType> Parent;
	using typename Parent::TokenEnum;
	using typename Parent::TokenNode;
	using typename Parent::Lexer;
	using typename Parent::AstNode;
	using typename Parent::AstNodePtr;

	typedef RhoAstNodeEnumType NodeType; 
	typedef RhoTokenEnumType TokenType;

	RhoParser(Registry &r) : Parent(r) { }

	virtual void Process(std::shared_ptr<Lexer> lex, Structure st) override;

protected:
	void Process(Structure);

private:
	void Run(Structure st);
	bool Program();
	bool Statement(AstNodePtr );
	bool Expression();
	bool Logical();
	bool Relational();
	bool Additive();
	bool Term();
	bool Factor();
	void ConsumeNewLines();
	void Block(AstNodePtr block);
	bool ParseFactorIdent();
	void ParseGetMember();
	void ParseMethodCall();
	void Function(AstNodePtr);
	void AddBlock(AstNodePtr fun);
	void IfCondition(AstNodePtr block);
	void ParseIndexOp();
	void Assignment(AstNodePtr);
	void For(AstNodePtr block);
	void While(AstNodePtr block);
	bool CreateError(const char *text);
};

KAI_END