#include "TestLangCommon.h"

using namespace kai;
using namespace std;

struct TestPi : TestLangCommon
{
};

TEST_F(TestPi, TestArithmetic)
{
	TranslatorCommon::trace = 1;

	_console->SetLanguage(Language::Pi);
	_data->Clear();
	_console->Execute("1 2 +");
	auto result = AtData<int>(0);
	ASSERT_EQ(result, 3);

	_data->Clear();
	_console->Execute("1 2 -");
	ASSERT_EQ(AtData<int>(0), -1);

	_data->Clear();
	_console->Execute("2 2 *");
	ASSERT_EQ(AtData<int>(0), 4);

	// TODONOW

	// _data->Clear();
	// _console->Execute("6 2 div");
	// ASSERT_EQ(AtData<int>(0), 3);

	// _data->Clear();
	// _console->Execute("3 2 + 2 2 * * 2 div");
	// ASSERT_EQ(AtData<int>(0), 10);
}

TEST_F(TestPi, TestAssignment)
{
	_console->SetLanguage(Language::Pi);
	_console->Execute("3 'a");

	Label name("a");
	Object scope = GetContext().GetScope();
	ASSERT_TRUE(scope.HasChild(name));
	ASSERT_EQ(Deref<int>(scope.GetChild(name)), 3);
}

