#include "TestCommon.h"

USING_NAMESPACE_KAI

struct TestString : TestCommon
{
protected:
	void AddrequiredClasses() override
	{
		Reg().AddClass<String>();
	}
};

TEST_F(TestString, TestCreation)
{
}

TEST_F(TestString, TestConcat)
{
}

TEST_F(TestString, TestLength)
{
}

TEST_F(TestString, TestComparison)
{
}

TEST_F(TestString, TestStringStreamInsert)
{
}

TEST_F(TestString, TestStringStreamExtract)
{
}