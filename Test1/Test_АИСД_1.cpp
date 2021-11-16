#include "pch.h"
#include "CppUnitTest.h"

#include "../АИСД_1/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_file_Classcpp
{
	TEST_CLASS(Test_push_back)
	{
	public:
		
		TEST_METHOD(push_back_Test)
		{
			List templist;
			int i;
			for (i = 0; i < 12; i = i + 3)
				templist.push_back(i);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 3);
			Assert::AreEqual(templist.at(2), 6);
			Assert::AreEqual(templist.at(3), 9);
		}
	};
	TEST_CLASS(Test_push_front)
	{
	public:

		TEST_METHOD(push_front_Test) 
		{
			List templist;
			int i;
			i = 0;
		    templist.push_front(i);
			Assert::AreEqual(templist.at(0), 0);
			i = 10;
			templist.push_front(i);
			Assert::AreEqual(templist.at(0), 10);
			Assert::AreEqual(templist.at(1), 0);
			i = 100;
			templist.push_front(i);
			Assert::AreEqual(templist.at(0), 100);
			Assert::AreEqual(templist.at(1), 10);
			Assert::AreEqual(templist.at(2), 0);
		}
	};
	TEST_CLASS(Test_pop_back)
	{
	public:

		TEST_METHOD(pop_back_Test_standart) 
		{
			List templist;
			int i;
			bool elem = false;
			for (i = 0; i < 12; i = i + 3)
				templist.push_back(i);
			templist.pop_back();
			if (templist.get_size() == 3)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 3);
			Assert::AreEqual(templist.at(2), 6);
			elem = false;
			templist.pop_back();
			if (templist.get_size() == 2)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 3);
			elem = false;
			templist.pop_back();
			if (templist.get_size() == 1)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 0);
			elem = false;
			templist.pop_back();
			if (templist.get_size() == 0)
				elem = true;
			Assert::AreEqual(elem, true);
		}
		TEST_METHOD(pop_back_Test_1_if_empty) 
		{
			List templist;
			try {
				templist.pop_back();
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("deletion isn't possible, the list is empty", expection.what());
			}
		}
	};

	TEST_CLASS(Test_pop_front)
	{
	public:

		TEST_METHOD(pop_front_Test_standart) 
		{
			List templist;
			int i;
			bool elem = false;
			for (i = 0; i < 12; i = i + 3)
				templist.push_back(i);
			templist.pop_front();
			if (templist.get_size() == 3)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 3);
			Assert::AreEqual(templist.at(1), 6);
			Assert::AreEqual(templist.at(2), 9);
			elem = false;
			templist.pop_front();
			if (templist.get_size() == 2)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 6);
			Assert::AreEqual(templist.at(1), 9);
			elem = false;
			templist.pop_front();
			if (templist.get_size() == 1)
				elem = true;
			Assert::AreEqual(elem, true);
			Assert::AreEqual(templist.at(0), 9);
			elem = false;
			templist.pop_front();
			if (templist.get_size() == 0)
				elem = true;
			Assert::AreEqual(elem, true);
		}
		TEST_METHOD(pop_front_Test_if_empty)
		{
			List templist;
			try {
				templist.pop_back();
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("deletion isn't possible, the list is empty", expection.what());
			}
		}
	};

	TEST_CLASS(Test_insert)
	{
	public:

		TEST_METHOD(insert_Test_standart)
		{
			List templist;
			int i;
			for (i = 0; i < 12; i = i + 3)
				templist.push_back(i);
			templist.insert(100, 1);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 100);
			Assert::AreEqual(templist.at(2), 3);
			Assert::AreEqual(templist.at(3), 6);
			Assert::AreEqual(templist.at(4), 9);
			templist.insert(666, 0);
			Assert::AreEqual(templist.at(0), 666);
			Assert::AreEqual(templist.at(1), 0);
			Assert::AreEqual(templist.at(2), 100);
			Assert::AreEqual(templist.at(3), 3);
			Assert::AreEqual(templist.at(4), 6);
			Assert::AreEqual(templist.at(5), 9);
			templist.insert(11, 5);
			Assert::AreEqual(templist.at(0), 666);
			Assert::AreEqual(templist.at(1), 0);
			Assert::AreEqual(templist.at(2), 100);
			Assert::AreEqual(templist.at(3), 3);
			Assert::AreEqual(templist.at(4), 6);
			Assert::AreEqual(templist.at(5), 11);
			Assert::AreEqual(templist.at(6), 9);
		}
		TEST_METHOD(insert_Test_if_invalid_index) 
		{
			List templist;
			try {
				templist.insert(100, 666);
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("Invalid index entered", expection.what());
			}
		}
	};

	TEST_CLASS(Test_at)
	{
	public:

		TEST_METHOD(at_Test_standart)
		{
			List templist;
		    templist.push_back(1);
			templist.push_back(10);
			templist.push_back(100);
			Assert::AreEqual(templist.at(0), 1);
			Assert::AreEqual(templist.at(1), 10);
			Assert::AreEqual(templist.at(2), 100);
		}
		TEST_METHOD(at_Test_if_invalid_index)
		{
			List templist;
			try {
				templist.at(666);
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("Invalid index entered", expection.what());
			}
		}
	};

	TEST_CLASS(Test_remove)
	{
	public:

		TEST_METHOD(remove_Test_standart)
		{
			List templist;
			templist.push_back(0);
			templist.push_back(10);
			templist.push_back(100);
			templist.push_back(1000);
			templist.push_back(10000);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 10);
			Assert::AreEqual(templist.at(2), 100);
			Assert::AreEqual(templist.at(3), 1000);
			Assert::AreEqual(templist.at(4), 10000);
			templist.remove(3);
			Assert::AreEqual(templist.at(0), 0);
			Assert::AreEqual(templist.at(1), 10);
			Assert::AreEqual(templist.at(2), 100);
			Assert::AreEqual(templist.at(3), 10000);
			templist.remove(0);
			Assert::AreEqual(templist.at(0), 10);
			Assert::AreEqual(templist.at(1), 100);
			Assert::AreEqual(templist.at(2), 10000);
			templist.remove(2);
			Assert::AreEqual(templist.at(0), 10);
			Assert::AreEqual(templist.at(1), 100);
		}
		TEST_METHOD(remove_Test_if_invalid_index)
		{
			List templist;
			try {
				templist.remove(666);
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("Invalid index entered", expection.what());
			}
		}
	};

	TEST_CLASS(Test_get_size)
	{
	public:

		TEST_METHOD(get_size_Test)
		{
			List templist;
			bool elem;
			elem = false;
			int i;
			for (i = 0; i < 12; i = i + 3)
				templist.push_back(i);
			if (templist.get_size() == 4)
				elem = true;
			Assert::AreEqual(elem, true);
			elem = false;
			templist.pop_front();
			if (templist.get_size() == 3)
				elem = true;
			Assert::AreEqual(elem, true);
			elem = false;
			templist.pop_front();
			if (templist.get_size() == 2)
				elem = true;
			Assert::AreEqual(elem, true);
		}
	};

	TEST_CLASS(Test_clear)
	{
	public:

		TEST_METHOD(clear_Test)
		{
			List templist;
			bool elem = false;
			templist.push_back(10);
			templist.push_back(100);
			templist.clear();
			if ((templist.get_size() == 0) && (templist.isEmpty()))
				elem = true;
			Assert::AreEqual(elem, true);
		}
	};

	TEST_CLASS(Test_set)
	{
	public:

		TEST_METHOD(set_Test_standart)
		{
			List templist;
			bool elem = false;
			templist.push_back(10);
			templist.push_back(100);
			templist.push_back(1000);
			templist.push_back(10000);
			templist.set(0, 666);
			Assert::AreEqual(templist.at(0), 666);
			Assert::AreEqual(templist.at(1), 100);
			Assert::AreEqual(templist.at(2), 1000);
			Assert::AreEqual(templist.at(3), 10000);
			templist.set(3, 13);
			Assert::AreEqual(templist.at(0), 666);
			Assert::AreEqual(templist.at(1), 100);
			Assert::AreEqual(templist.at(2), 1000);
			Assert::AreEqual(templist.at(3), 13);
			templist.set(1, 4);
			Assert::AreEqual(templist.at(0), 666);
			Assert::AreEqual(templist.at(1), 4);
			Assert::AreEqual(templist.at(2), 1000);
			Assert::AreEqual(templist.at(3), 13);
		}
		TEST_METHOD(set_Test_if_invalid_index)
		{
			List templist;
			try {
				templist.set(666, 600);
			}
			catch (const out_of_range expection)
			{
				Assert::AreEqual("Invalid index entered", expection.what());
			}
		}
	};
	TEST_CLASS(Test_push_back_list)
	{
	public:

		TEST_METHOD(push_back_list_Test_standart)
		{
			List onelist;
			List twolist;
			bool elem = false;
			onelist.push_back(10);
			onelist.push_back(100);
			onelist.push_back(1000);
			twolist.push_back(2);
			twolist.push_back(4);
			onelist.push_back(&twolist);
			Assert::AreEqual(onelist.at(0), 10);
			Assert::AreEqual(onelist.at(1), 100);
			Assert::AreEqual(onelist.at(2), 1000);
			Assert::AreEqual(onelist.at(3), 2);
			Assert::AreEqual(onelist.at(4), 4);
			if (onelist.get_size() == 5)
				elem = true;
			Assert::AreEqual(elem, true);
		}
		TEST_METHOD(push_back_list_Test_if_first_list_empty)
		{
			List onelist;
			List twolist;
			bool elem = false;
			twolist.push_back(2);
			twolist.push_back(4);
			onelist.push_back(&twolist);
			Assert::AreEqual(onelist.at(0), 2);
			Assert::AreEqual(onelist.at(1), 4);
			if (onelist.get_size() == 2)
				elem = true;
			Assert::AreEqual(elem, true);
		}
		TEST_METHOD(push_back_list_Test_if_second_list_empty)
		{
			List onelist;
			List twolist;
			bool elem = false;
			onelist.push_back(2);
			onelist.push_back(4);
			onelist.push_back(&twolist);
			Assert::AreEqual(onelist.at(0), 2);
			Assert::AreEqual(onelist.at(1), 4);
			if (onelist.get_size() == 2)
				elem = true;
			Assert::AreEqual(elem, true);
		}
	};
}
