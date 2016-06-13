#include <ctype.h>
#include "KAI/Core/BuiltinTypes.h"

KAI_BEGIN

const String::Char Pathname::Literals::Parent = '^';
const String::Char Pathname::Literals::This = '.';
const String::Char Pathname::Literals::Separator = '/';
const String::Char Pathname::Literals::Quote = '\'';
const String::Char Pathname::Literals::All[]= { Parent, This , Separator, Quote, 0 };
const String::Char Pathname::Literals::AllButQuote[]= { Parent, This , Separator, 0 };

Pathname::Pathname(const Elements &e)
	: elements(e)
{
}

Pathname::Pathname(const String &text)
{
	FromString(text);
}

bool Pathname::Quoted() const
{
	return !elements.empty() && elements.front().type == Element::Quote;
}

bool Pathname::Absolute() const
{
	if (elements.empty())
		return false;
	if (Quoted())
		return elements.size() > 1 && elements[1].type == Element::Separator;
	return elements.front().type == Element::Separator;
}

void Pathname::FromString2(String text)
{
	FromString(text);
}

void Pathname::FromString(const String &text)
{
	elements.clear();
	if (text.empty())
		return;

	const String::Char *S = text.c_str();

	StringStream name;
	for (; *S; ++S)
	{
		switch (*S)
		{
		case Literals::Parent:
			AddElement(name, Element::Parent);
			break;

		case Literals::Separator:
			if (S[1] != 0)
				AddElement(name, Element::Separator);
			break;

		case Literals::This:
			AddElement(name, Element::This);
			break;

		default:
			if (!isalnum(*S) && *S != '_')
			{
				elements.clear();
				KAI_THROW_1(InvalidPathname, text);
			}
			name.Append(*S);
			break;
		}
	}

	name << Ends;
	String s = name.ToString();
	if (!s.Empty())
		elements.push_back(Element(s));

	if (elements.empty())
		return;
	
	if (elements.back().type == Element::Separator)
		elements.pop_back();

	if (!Validate())
	{
		elements.clear();
		KAI_THROW_1(InvalidPathname, text);
	}
}

void Pathname::AddElement(StringStream &name, Element::Type type)
{
	if (!name.Empty())
	{
		name << Ends;
		elements.push_back(Element(name.ToString()));
	}

	elements.push_back(type);
	name.Clear();
}

String Pathname::ToString() const
{
	StringStream str;
	if (Absolute())
		str.Append(Literals::Separator);

	for (auto element : elements)
	{
		switch (element.type)
		{
		case Element::Separator: str.Append(Literals::Separator);
			break;
		
		case Element::Parent: str.Append(Literals::Parent); 
			break;

		case Element::This: str.Append(Literals::This); 
			break;

		case Element::Name: str << element.name.ToString(); 
			break;

		case Element::None:
			break;
		}
	}

	str << Ends;
	return str.ToString();
}

bool Pathname::Empty() const
{
	return elements.empty();
}

bool Pathname::Validate() const
{
	if (elements.empty())
		return true;
	// TODO
	return true;
}

StringStream &operator<<(StringStream &S, Pathname const &P)
{
	return S << P.ToString();
}

bool operator<(const Pathname &A, const Pathname &B)
{
	return A.elements < B.elements;
}

bool operator==(const Pathname &A, const Pathname &B)
{
	return A.elements == B.elements;
}

BinaryPacket &operator>>(BinaryPacket &, Pathname &)
{
	KAI_NOT_IMPLEMENTED();
}

BinaryStream &operator<<(BinaryStream &, const Pathname &)
{
	KAI_NOT_IMPLEMENTED();
}

StringStream &operator>>(StringStream &, Pathname &)
{
	KAI_NOT_IMPLEMENTED();
}

void Pathname::Register(Registry &R)
{
	ClassBuilder<Pathname>(R, Label("Pathname"))
		.Methods
			("Empty", &Pathname::Empty)
			("ToString", &Pathname::ToString)
			("FromString", &Pathname::FromString2)
			("absolute", &Pathname::Absolute)
			("quoted", &Pathname::Quoted)
		;
}

KAI_END

//EOF
