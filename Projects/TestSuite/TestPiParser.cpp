#include "TestBase.h"
#include "KAI/Registry.h"

using namespace kai;
using namespace std;

namespace
{
	TEST(PiParser, TestSimple)
	{
		auto input = "1";
		Registry reg;

		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_FALSE(parse->Failed);

		auto root = parse->GetRoot();
		ASSERT_TRUE(root);
		ASSERT_EQ(root->GetChildren().size(), 2);
		ASSERT_EQ(root->GetChild(0)->GetToken().type, PiTokens::Int);
		ASSERT_EQ(root->GetChild(1)->GetToken().type, PiTokens::NewLine);
	}

	TEST(PiParser, TestCompoundWorks)
	{
		auto input = "[[[]]]";
		Registry reg;
		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());
		if (lex->Failed)
			KAI_TRACE_1(lex->Error);

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_FALSE(parse->Failed);

		auto root = parse->GetRoot();
		ASSERT_EQ(root->GetChildren().size(), 2);

		auto ch0 = root->GetChildren()[0];
		auto ch1 = ch0->GetChildren()[0];
		auto ch2 = ch1->GetChildren()[0];

		// CBF
		//ASSERT_EQ(ch0->GetTye(), PiAstNodes::Array);
		//ASSERT_EQ(ch1->GetTye(), PiAstNodes::Array);
		//ASSERT_EQ(ch2->GetTye(), PiAstNodes::Array);
	}

	TEST(PiParser, TestMixedCompound)
	{
		auto input = "{ [ 1 2 3 ] 'a # }";
		Registry reg;

		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());
		if (lex->Failed)
			KAI_TRACE_1(lex->Error);

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_FALSE(parse->Failed);
	}

	TEST(PiParser, TestCompoundFail)
	{
		auto input = "[";
		Registry reg;
		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());
		if (lex->Failed)
			KAI_TRACE_1(lex->Error);

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_TRUE(parse->Failed);
	}

	TEST(PiParser, TestCompoundFail2)
	{
		auto input = "[[]";
		Registry reg;

		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());
		if (lex->Failed)
			KAI_TRACE_1(lex->Error);

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_TRUE(parse->Failed);
	}

	TEST(PiParser, TestCompoundFail3)
	{
		auto input = "]";
		Registry reg;

		shared_ptr<PiLexer> lex = make_shared<PiLexer>(input);
		lex->Process();
		KAI_TRACE_1(lex->Print());
		if (lex->Failed)
			KAI_TRACE_1(lex->Error);

		shared_ptr<PiParser> parse = make_shared<PiParser>(reg);
		parse->Process(lex, Structure::Sequence);

		KAI_TRACE_1(parse->Print());
		ASSERT_FALSE(lex->Failed);
		ASSERT_TRUE(parse->Failed);
	}
}
