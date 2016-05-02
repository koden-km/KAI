#include "KAI/ExecutorPCH.h"
#include "KAI/Translator/Pi/PiToken.h"

#include <string>
#include <algorithm>
#include <memory>
#include <ctype.h>

using namespace std;

KAI_BEGIN

const char *ToString(PiTokenEnumType::Enum t)
{
	switch (t)
	{
		#define CASE(N) case PiTokens::N : return #N;
		#define CASE_LOWER(N) case PiTokens::N : return ToLower(#N);
		#define CASE_REPLACE(N, M) case PiTokens::N : return M;

		CASE_LOWER(None)
		CASE_LOWER(Whitespace)
		CASE_LOWER(Int)
		CASE_LOWER(Float)
		CASE_LOWER(String)
		CASE_LOWER(True)
		CASE_LOWER(False)
		CASE_REPLACE(Suspend, "&")
		CASE_REPLACE(Resume, "...")
		CASE_REPLACE(Replace, "!")
		CASE_LOWER(Ident)
		CASE_LOWER(QuotedIdent, "'")
		CASE_REPLACE(Dot, ".")
		CASE_REPLACE(Comma, ",")
		CASE_LOWER(If)
		CASE_LOWER(IfElse)
		CASE_LOWER(For)
		CASE_LOWER(While)
		CASE_REPLACE(OpenBrace, "{")
		CASE_REPLACE(CloseBrace, "}")
		CASE_REPLACE(OpenParan, "(")
		CASE_REPLACE(CloseParan, ")")
		CASE_REPLACE(Plus, "+")
		CASE_REPLACE(Minus, "-")
		CASE_REPLACE(Mul, "*")
		CASE_REPLACE(Divide, "div")
		CASE_REPLACE(Assign, "=")
		CASE_REPLACE(Less, "<")
		CASE_REPLACE(Equiv, "==")
		CASE_REPLACE(NotEquiv, "!=")
		CASE_REPLACE(LessEquiv, "le")
		CASE_REPLACE(GreaterEquiv, "ge")
		CASE_LOWER(Not)
		CASE_LOWER(And)
		CASE_LOWER(Or)
		CASE_LOWER(Xor)
		CASE_REPLACE(OpenSquareBracket, "[")
		CASE_REPLACE(CloseSquareBracket, "]")
		CASE_REPLACE(Increment, "++")
		CASE_REPLACE(Decrement, "--")
		CASE_LOWER(BitAnd)
		CASE_LOWER(BitOr)
		CASE_LOWER(BitXor)
		CASE_LOWER(Self)
		CASE_LOWER(Lookup)
		CASE(Tab)
		CASE(NewLine)
		CASE(Comment)
		CASE_REPLACE(PlusAssign, "+=")
		CASE_REPLACE(MinusAssign, "-=")
		CASE_REPLACE(MulAssign, "*=")
		CASE_REPLACE(DivAssign, "/=")
		CASE_REPLACE(In, ":")
		CASE_LOWER(Colon)
		CASE_LOWER(Assert)
		CASE_LOWER(Pathname)
		CASE_LOWER(Drop)
		CASE_LOWER(Dup)
		CASE_LOWER(Over)
		CASE_LOWER(OverM)
		CASE_LOWER(PickN)
		CASE_LOWER(Depth)
		CASE_LOWER(Swap)
		CASE_LOWER(Rot)
		CASE_LOWER(RotN)
		CASE_LOWER(Clear)
		CASE_LOWER(Expand)
		CASE_LOWER(ToArray)
		CASE_LOWER(ToList)
		CASE_LOWER(ToMap)
		CASE_LOWER(ToSet)
		CASE_LOWER(ToHashMap)
		CASE_LOWER(ToPair)
		CASE_LOWER(ToVector2)
		CASE_LOWER(ToVector3)
		CASE_LOWER(ToVector4)
		CASE_LOWER(ToQuaternion)
		CASE_LOWER(RunScript)
		CASE_LOWER(Name)
		CASE_LOWER(Fullname)
		CASE_LOWER(GetProperty)
		CASE_LOWER(SetProperty)
		CASE_LOWER(GarbageCollect)
		CASE_LOWER(ChangeFolder)
		CASE_LOWER(PrintFolder)
		CASE_LOWER(Pipe)
		CASE_LOWER(DirectIn)
		CASE_LOWER(DirectOut)
		CASE_LOWER(DirectInOut)
		CASE_LOWER(GetPath)
		CASE_LOWER(GetName)
		CASE_LOWER(SplitPathName)
		CASE_LOWER(MakePathName)
		CASE_LOWER(Setname)
		CASE_LOWER(SetChild)
		CASE_LOWER(GetChild)
		CASE_LOWER(GetChildren)
		CASE_LOWER(GetMethods)
		CASE_LOWER(GetProperties)
		CASE_LOWER(GetType)
		CASE_LOWER(GetSignature)
		CASE_LOWER(StringtoType)
		CASE_LOWER(TypeToString)
		CASE_LOWER(Version)
		CASE_LOWER(DateNowSimple)
		CASE_LOWER(DateNow)
		CASE_LOWER(DurationSinceStart)
		CASE_LOWER(DeltaTime)
		CASE_LOWER(PushFolder)
		CASE_LOWER(PopFolder)
		CASE_LOWER(History)
		CASE_LOWER(Jobs)
		CASE_LOWER(Store)
	}
	
	static char b[100];
	_itoa_s(t, b, 100, 10);
	return b;
}

std::ostream &operator<<(std::ostream &out, PiToken const &node)
{
	if (node.type == PiTokenEnumType::None)
		return out << "<None>";

	switch (node.type)
	{
	case PiTokenEnumType::True: { out << "true"; return out; }
	case PiTokenEnumType::False: { out << "false"; return out; }
	}

	out << ToString(node.type);

	switch (node.type)
	{
	case PiTokenEnumType::Int:
	case PiTokenEnumType::Float:
	case PiTokenEnumType::Pathname:
	case PiTokenEnumType::String:
	case PiTokenEnumType::Ident:
		out << "=" << node.Text();
		break;
	case PiTokenEnumType::QuotedIdent:
		out << "='" << node.Text();
		break;
	}

	return out;
}

KAI_END
