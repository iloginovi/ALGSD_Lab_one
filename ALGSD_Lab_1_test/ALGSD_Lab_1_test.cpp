#include "pch.h"
#include "CppUnitTest.h"
#include "..\ALGSD_Lab_1\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ALGSDLab1test
{
	TEST_CLASS(ALGSDLab1test)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			List List_one;
			Assert::IsTrue(List_one.isEmpty());
		}
		TEST_METHOD(Test_Push_front_NotEmpty)
		{
			List List_one;
			List_one.push_front(10);
			Assert::IsFalse(List_one.isEmpty());
			Assert::IsTrue(List_one.at(1) == 10);

		}
		TEST_METHOD(Test_Push_back_NotEmpty)
		{
			List List_one;
			List_one.push_back(10);
			Assert::IsFalse(List_one.isEmpty());
			Assert::IsTrue(List_one.at(1) == 10);
		}
		TEST_METHOD(Test_Pop_front)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.pop_front();
			List_one.pop_front();
			List_one.pop_front();
			Assert::IsTrue(List_one.isEmpty());
		}
		TEST_METHOD(Test_Pop_back)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.pop_back();
			List_one.pop_back();
			List_one.pop_back();
			Assert::IsTrue(List_one.isEmpty());
		}
		TEST_METHOD(Test_get_size)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			Assert::IsTrue(List_one.get_size() == 3);
			List_one.pop_back();
			Assert::IsTrue(List_one.get_size() == 2);
		}
		TEST_METHOD(Test_at)
		{	
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			Assert::IsTrue(List_one.at(1) == 12);
			Assert::IsTrue(List_one.at(3) == 11);
		}
		TEST_METHOD(Test_insert)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.insert(15, 1);
			List_one.insert(17, 4);
			Assert::IsTrue(List_one.at(1) == 15);
			Assert::IsTrue(List_one.at(4) == 17);
		}
		TEST_METHOD(Test_remove)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.insert(15, 1);
			List_one.insert(17, 4);
			List_one.remove(3);
			List_one.remove(1);
			List_one.remove(3);
			Assert::IsTrue(List_one.get_size() == 2);

		}
		TEST_METHOD(Test_clear)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.insert(15, 1);
			List_one.insert(17, 4);
			List_one.clear();
			Assert::IsTrue(List_one.isEmpty());
		}
		TEST_METHOD(Test_set_el)
		{
			List List_one;
			List_one.push_back(10);
			List_one.push_front(12);
			List_one.push_back(11);
			List_one.insert(15, 1);
			List_one.insert(17, 4);
			List_one.set_el(1, 8);
			List_one.set_el(2, 7);
			List_one.set_el(3, 9);
			Assert::IsTrue(List_one.at(1) == 8);
			Assert::IsTrue(List_one.at(2) == 7);
			Assert::IsTrue(List_one.at(3) == 9);
		}
		TEST_METHOD(Test_Contains)
		{
			List List_one;
			List_one.push_front(15);
			List_one.push_front(12);
			List_one.push_front(13);
			List_one.push_front(14);
			List_one.push_front(17);

			List List_two;
			List_two.push_front(12);
			List_two.push_front(13);
			List_two.push_front(14);
			Assert::IsTrue(List_one.Contains(&List_two));
			List_two.push_front(18);
			Assert::IsFalse(List_one.Contains(&List_two));
			List_two.pop_front();
			List_two.push_back(17);
			Assert::IsFalse(List_one.Contains(&List_two));
		}
		TEST_METHOD(TestMethod1)
		{

		}
	};
}
