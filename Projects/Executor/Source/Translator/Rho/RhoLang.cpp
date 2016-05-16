#include "KAI/ExecutorPCH.h"

#include <fstream>
#include <iostream>


using namespace std;

KAI_BEGIN

RhoLang::RhoLang(Registry &r)
	: reg(r)
{
}

void RhoLang::Print()
{
	/*
	cout << "Input--" << endl;
	cout << lex->GetInput() << endl;

	cout << "Lexer--" << endl;
	lex->Print();

	cout << "Parser--" << endl;
	parse->Print();

	cout << "Trans--" << endl;
	cout << trans->Result() << endl;
	 */
}

bool RhoLang::TranslateFile(const char *name, Structure st)
{
	ifstream file(name, ios::binary);
	if (!file)
		return false;

	file.seekg(0, ios::end);
	int len = (int)file.tellg();
	char *text = new char[len + 1];
	file.seekg(0, ios::beg);
	file.read(text, len);
	text[len] = 0;

	return Translate(text, st);
}

bool RhoLang::Translate(const char *text, Structure st)
{
	KAI_UNUSED_2(text, st);
	return false;

	//trans = std::make_shared<Translator>(reg);
	//trans->Translate(text);

	//if (lex->Failed)
	//	Fail(lex->Error);

	//if (parse->Failed)
	//	Fail(parse->Error);

	//if (trans->Failed)
	//	Fail(trans->Error);

	//return !Failed;
}

KAI_END
