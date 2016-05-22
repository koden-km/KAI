#include "KAI/Console/ConsoleColor.h"

KAI_BEGIN

#ifdef WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>

static WORD colors[Color::Last];
static HANDLE hstdout;
static CONSOLE_SCREEN_BUFFER_INFO orig;

Color::Color()
{
	WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	colors[Prompt] = FOREGROUND_GREEN | FOREGROUND_RED;
	colors[Input] = white;
	colors[Trace] = FOREGROUND_BLUE | FOREGROUND_GREEN;
	colors[Error] = BACKGROUND_RED | white;
	colors[Warning] = FOREGROUND_GREEN | FOREGROUND_BLUE;
	colors[StackEntry] = FOREGROUND_GREEN;
	colors[StackIndex] = FOREGROUND_GREEN | FOREGROUND_RED;
	colors[LanguageName] = FOREGROUND_RED;
	colors[NumObjects] = FOREGROUND_GREEN | FOREGROUND_RED;
	colors[Pathname] = FOREGROUND_GREEN | FOREGROUND_BLUE;

	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were when we started
	GetConsoleScreenBufferInfo(hstdout, &orig);
}

Color::~Color()
{
	SetConsoleTextAttribute(hstdout, orig.wAttributes);
}

void Color::SetColor(Type c)
{
	SetConsoleTextAttribute(hstdout, colors[c]);
}

#else

// WTF this is an error with Clang++
//#pragma message Color is not suported on this platform

Color::Color()
{
}

Color::~Color()
{
}

void Color::SetColor(Type c)
{
}

#endif

KAI_END
