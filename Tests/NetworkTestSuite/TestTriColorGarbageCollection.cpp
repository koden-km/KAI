#include "TestBase.h"
#include "KAI/Tree.h"
#include "KAI/DotGraph.h"

using namespace kai;

struct TriColor : ::testing::Test
{
	TriColor()
	{
		test_number = 0;
		ClassBuilder<TriColor>(_reg, "TestTriColor")
			.Methods
				("Test", &TriColor::Test)
				("TestNested", &TriColor::TestNested)
				("TestMultipleReferences", &TriColor::TestMultipleReferences)
				("TestOverride", &TriColor::TestOverride)
				("TestContainers", &TriColor::TestContainers)
			;
	}

	void Test();
	void TestNested();
	void TestMultipleReferences();
	void TestOverride();
	void TestContainers();

	//void TriColor(Registry &);

	int test_number;
	Registry _reg;
	Tree *tree;
};

struct TriColorStruct
{
	Pointer<List> contained;
	Object other;
};

KAI_BEGIN
KAI_TYPE_TRAITS(TriColorStruct, 666, Properties::Nothing);
KAI_TYPE_TRAITS(TriColor, 777, Properties::Nothing);
KAI_END

TEST_F(TestTriColor, TestRegistration)
{
	Registry R;
	Tree tree;
	ClassBuilder<TriColorStruct>(R, "TriColorStruct")
		.Methods
		.Properties
			("contained", &TriColorStruct::contained, "", CreateParams::Create)
			("other", &TriColorStruct::other)
		;

	R.AddClass<void>();
	R.AddClass<Object>();
	R.AddClass<int>();
	List::Register(R);

	Object root = R.New<void>();
	tree.SetRoot(root);
	R.SetTree(tree);

	Object N = R.New<int>();
	ASSERT_TRUE(N.Exists());

	R.TriColor();
	ASSERT_FALSE(N.Exists());

	N = R.New<int>();
	Object M = R.New<int>();
	N.SetChild("M", M);
	root.SetChild("N", N);

	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(N.Exists());
	ASSERT_TRUE(M.Exists());

	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(N.Exists());
	ASSERT_TRUE(M.Exists());

	root.RemoveChild("N");
	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_FALSE(N.Exists());
	ASSERT_FALSE(M.Exists());

	Pointer<TriColorStruct> tcs = R.New<TriColorStruct>();
	Object T0 = R.New<int>();
	Object T1 = R.New<int>();
	Object T2 = R.New<int>();
	tcs->contained->Append(T0);
	tcs->contained->Append(T1);
	tcs->contained->Append(T2);
	root.SetChild("tcs", tcs);

	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(tcs->contained.Exists());
	if (tcs->contained.Exists())
	{
		EXPECT_EQ(tcs->contained->Size(), 3);
	}

	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_TRUE(T2.Exists());

	root.RemoveChild("tcs");

	TriColor(R);

	ASSERT_TRUE(root.Exists());
	ASSERT_FALSE(tcs.Exists());
	ASSERT_FALSE(T0.Exists());
	ASSERT_FALSE(T1.Exists());
	ASSERT_FALSE(T2.Exists());

	tcs = R.New<TriColorStruct>();
	T0 = R.New<int>();
	T1 = R.New<int>();
	T2 = R.New<int>();
	tcs->contained->Append(T0);
	tcs->contained->Append(T1);
	tcs->contained->Append(T2);
	root.SetChild("tcs", tcs);

	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(tcs->contained.Exists());
	if (tcs->contained.Exists())
	{
		EXPECT_EQ(tcs->contained->Size(), 3);
	}
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_TRUE(T2.Exists());

	T2.Delete();
	R.TriColor();
	DotGraph(root, "\\TestTriColor1.graph");

	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(tcs->contained.Exists());
	if (tcs->contained.Exists())
	{
		EXPECT_EQ(tcs->contained->Size(), 2);
	}
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_TRUE(!T2.Exists());

	M = R.New<int>();
	tcs.SetChild("M", M);
	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(tcs->contained.Exists());
	if (tcs->contained.Exists())
	{
		EXPECT_EQ(tcs->contained->Size(), 2);
	}
	ASSERT_TRUE(M.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_FALSE(T2.Exists());

	M.Delete();

	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_FALSE(M.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_FALSE(T2.Exists());

	Object other = R.New<int>();
	tcs.SetPropertyObject("other", other);
	ASSERT_TRUE(other.Exists());
	R.TriColor();
	ASSERT_TRUE(root.Exists());
	ASSERT_TRUE(tcs.Exists());
	ASSERT_FALSE(M.Exists());
	ASSERT_TRUE(other.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());
	ASSERT_FALSE(T2.Exists());

	tcs.Delete();
	R.TriColor();
	ASSERT_FALSE(other.Exists());
	ASSERT_FALSE(tcs.Exists());
}

TEST_F(TestTriColor, TestNested)
{
	Registry R;
	Tree tree;
	ClassBuilder<TriColorStruct>(R, "TriColorStruct")
		.Methods
		.Properties
		("contained", &TriColorStruct::contained, "", CreateParams::Create)
		("other", &TriColorStruct::other)
		;
	R.AddClass<void>();
	R.AddClass<Object>();
	R.AddClass<int>();
	List::Register(R);

	Object root = R.New<void>();
	tree.SetRoot(root);
	R.SetTree(tree);

	Pointer<TriColorStruct> tcs = R.New<TriColorStruct>();
	Pointer<List> list = R.New<List>();
	tcs->other = list;
	Object T0 = R.New<int>();
	Object T1 = R.New<int>();
	list->Append(T0);
	list->Append(T1);

	root.SetChild("tcs", tcs);
	R.GarbageCollect(root);
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(list.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());

	list->Erase(T1);
	R.GarbageCollect(root);
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(list.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(!T1.Exists());

	T1 = R.New<int>();
	root.SetChild("T1", T1);
	if (list.Exists())
		list->Append(T1);
	R.GarbageCollect(root);
	ASSERT_TRUE(tcs.Exists());
	ASSERT_TRUE(list.Exists());
	ASSERT_TRUE(T0.Exists());
	ASSERT_TRUE(T1.Exists());

	if (list.Exists())
		list->Erase(T1);
	R.GarbageCollect(root);
	ASSERT_TRUE(T1.Exists());
	ASSERT_TRUE(list.Exists());

	root.RemoveChild("T1");
	R.GarbageCollect(root);
	ASSERT_TRUE(!T1.Exists());

	Pointer<List> list2 = R.New<List>();
	T1 = R.New<void>();
	list2->Append(T1);
	if (list.Exists())
		list->Append(T1);

	ASSERT_TRUE(T1.Exists());
	R.GarbageCollect();
	ASSERT_TRUE(T1.Exists());
	ASSERT_TRUE(list.Exists());

	if (list.Exists())
		list->Erase(T1);
	R.GarbageCollect();
	ASSERT_TRUE(!list2.Exists());
	ASSERT_TRUE(!T1.Exists());
}

TEST_F(TestTriColor, TestMultipleReferences)
{
	Registry R;
	Tree tree;
	ClassBuilder<TriColorStruct>(R, "TriColorStruct")
		.Methods
		.Properties
		("contained", &TriColorStruct::contained, "", CreateParams::Create)
		("other", &TriColorStruct::other)
		;
	R.AddClass<void>();
	R.AddClass<Object>();
	R.AddClass<int>();
	List::Register(R);

	Object root = R.New<void>();
	tree.SetRoot(root);
	R.SetTree(tree);
	R.TriColor();

	Pointer<TriColorStruct> tcs1 = R.New<TriColorStruct>();
	Pointer<TriColorStruct> tcs2 = R.New<TriColorStruct>();

	tcs1->other = tcs2;
	Object Q = R.New<int>();
	tcs2->other = Q;
	tcs2->contained->Append(Q);
	Object Q2 = R.New<int>();
	Q.SetChild("Q2", Q2);

	root.SetChild("tcs1", tcs1);
	R.TriColor();

	ASSERT_TRUE(tcs1.Exists());
	ASSERT_TRUE(tcs2.Exists());
	ASSERT_TRUE(tcs1->contained.Exists());
	ASSERT_TRUE(tcs2->contained.Exists());
	ASSERT_TRUE(Q.Exists());
	ASSERT_TRUE(Q2.Exists());

	tcs2->other = Object();
	R.TriColor();
	ASSERT_TRUE(tcs1.Exists());
	ASSERT_TRUE(tcs2.Exists());
	ASSERT_TRUE(tcs1->contained.Exists());
	ASSERT_TRUE(tcs2->contained.Exists());
	ASSERT_TRUE(!tcs2->other.Exists());
	ASSERT_TRUE(Q.Exists());
	ASSERT_TRUE(Q2.Exists());

	tcs2->contained->Erase(Q);
	R.TriColor();
	ASSERT_TRUE(tcs1.Exists());
	ASSERT_TRUE(tcs2.Exists());
	ASSERT_TRUE(tcs1->contained.Exists());
	ASSERT_TRUE(tcs2->contained.Exists());
	ASSERT_TRUE(!Q.Exists());
	ASSERT_TRUE(!Q2.Exists());

	tcs2.Delete();
	R.TriColor();
	ASSERT_TRUE(tcs1.Exists());
	ASSERT_TRUE(!tcs2.Exists());
	ASSERT_TRUE(!tcs1->other.Exists());


	Object A = R.New<int>();
	Object B = R.New<int>();
	Object C = R.New<int>();

	root.SetChild("A", A);
	A.SetChild("B", B);
	B.SetChild("C", C);
	R.TriColor();
	ASSERT_TRUE(A);
	ASSERT_TRUE(B);
	ASSERT_TRUE(C);

	B.Delete();
	R.TriColor();
	ASSERT_TRUE(A);
	ASSERT_TRUE(!B.Exists());
	ASSERT_TRUE(!C.Exists());

	A.Delete();
	B.Delete();
	C.Delete();
	R.TriColor();
	ASSERT_TRUE(!A);
	ASSERT_TRUE(!B);
	ASSERT_TRUE(!C);
	ASSERT_TRUE(!root.Has("A"));

	A = R.New<int>();
	B = R.New<int>();
	C = R.New<int>();

	root.SetChild("A", A);
	root.SetChild("C", C);
	A.SetChild("B", B);
	B.SetChild("C", C);

	A.Delete();
	R.TriColor();

	ASSERT_TRUE(!A);
	ASSERT_TRUE(!B);
	ASSERT_TRUE(C);
}

TEST_F(TestTriColor, TestOverride)
{
	Registry R;
	Tree tree;
	ClassBuilder<TriColorStruct>(R, "TriColorStruct")
		.Methods
		.Properties
			("contained", &TriColorStruct::contained)
			("other", &TriColorStruct::other)
		;
	R.AddClass<void>();
	R.AddClass<Object>();
	R.AddClass<int>();
	List::Register(R);

	Object root = R.New<void>();
	tree.SetRoot(root);
	R.SetTree(tree);
	R.TriColor();

	Object A = R.New<int>();
	Object B = R.New<int>();
	A.SetChild("B", B);
	root.SetChild("A", A);

	R.TriColor();
	ASSERT_TRUE(A);
	ASSERT_TRUE(B);

	Object B2 = R.New<int>();
	A.SetChild("B", B2);
	R.TriColor();
	ASSERT_TRUE(A);
	ASSERT_TRUE(B2);
	ASSERT_TRUE(!B);

	// test properties
	Pointer<TriColorStruct> tcs = R.New<TriColorStruct>();
	Object N = R.New<int>();

	tcs->other = N;
	root.SetChild("tcs", tcs);

	R.TriColor();
	ASSERT_TRUE(tcs);
	ASSERT_TRUE(tcs->other);

	Object N2 = R.New<int>();
	tcs->other = N2;
	R.TriColor();
	ASSERT_TRUE(tcs);
	ASSERT_TRUE(tcs->other);
	ASSERT_FALSE(N);
	ASSERT_TRUE(N2);
}

TEST_F(TestTriColor, TestContainers)
{
	Registry R;
	Tree tree;
	ClassBuilder<TriColorStruct>(R, "TriColorStruct")
		.Methods
		.Properties
			("contained", &TriColorStruct::contained)
			("other", &TriColorStruct::other)
		;
	R.AddClass<void>();
	R.AddClass<Object>();
	R.AddClass<int>();
	List::Register(R);

	Pointer<List> list = R.New<List>();
	Pointer<int> n0 = R.New(123);
	Pointer<int> n1 = R.New(456);
	list->Append(n0);
	list->Append(n1);
	R.AddRoot(list);

	R.TriColor();
	ASSERT_TRUE(list);
	ASSERT_TRUE(n0);
	ASSERT_TRUE(n1);
	ASSERT_TRUE(list->Contains(n0));
	ASSERT_TRUE(list->Contains(n1));
	EXPECT_EQ(list->Size(), 2);

	n0.Delete();
	R.TriColor();
	ASSERT_TRUE(list);
	ASSERT_FALSE(n0);
	ASSERT_TRUE(n1);
	ASSERT_FALSE(list->Contains(n0));
	ASSERT_TRUE(list->Contains(n1));
	EXPECT_EQ(list->Size(), 1);

	//foreach (Pointer<const int> num, *list)
	//{
	//	int N = *num;
	//}
}

void TestTriColor::TriColor(Registry &R)
{
	R.TriColor();
}

