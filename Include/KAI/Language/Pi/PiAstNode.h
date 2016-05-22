#pragma once

#include "KAI/Language/Common/AstNodeBase.h"
#include "KAI/Language/Pi/PiToken.h"

KAI_BEGIN

// A node in the AST generated by a Parser
struct PiAstNodeEnumType
{
	enum Enum
	{
		None,
		Program,
		Operation,
		List,
		Map,
		Set,
		Array,
		Continuation,
		TokenType,
	};

	struct Node : AstNodeBase<PiToken, PiAstNodeEnumType>
	{
		typedef AstNodeBase<PiToken, PiAstNodeEnumType> Parent;
		using typename Parent::Token;

		Node() : Parent(Enum::None) {  }
		Node(Enum e) : Parent(e) { }
		Node(Enum e, Token &tok) : Parent(e, tok) { }
		Node(Parent::Token tok) : Parent(tok) { }
	};

	static const char *ToString(Enum val);
};

typedef PiAstNodeEnumType PiAstNodes;
typedef PiAstNodeEnumType::Node PiAstNode;


KAI_END
