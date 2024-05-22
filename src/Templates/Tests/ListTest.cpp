#include "ListTest.hpp"

using namespace flame_ide;
using namespace flame_ide::templates::test;

ListTest::ListTest() : AbstractTest("List")
		, list {{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}}
		, stdlist {{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
  }}
{}

ListTest::~ListTest()
{}

int ListTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"initializing size"
		, [&]()
		{
			IN_CASE_CHECK_END(list.size() == stdlist.size());
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"initializing"
		, [&]()
	{
		return compareContainers(list, stdlist);
	}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"cloning"
		, [&]()
		{
			templates::List<TestClass> listClone = list.clone();
			CHECK_RESULT_SUCCESS(compareContainers(listClone, list));
			CHECK_RESULT_SUCCESS(compareContainers(listClone, stdlist));
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"copying"
		, [&]()
		{
			templates::List<TestClass> listCopy = list;
			CHECK_RESULT_SUCCESS(compareContainers(listCopy, list));
			CHECK_RESULT_SUCCESS(compareContainers(listCopy, stdlist));
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"moving"
		, [&]()
		{
			templates::List<TestClass> listMove = flame_ide::move(list);
			CHECK_RESULT_SUCCESS(compareContainers(listMove, stdlist));

			list = flame_ide::move(listMove);
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"reverse iterating", [&]()
		{
			auto range = templates::makeRange(list.rbegin(), list.rend());
			auto stdrange = templates::makeRange(stdlist.rbegin(), stdlist.rend());
			CHECK_RESULT_SUCCESS_END(compareContainers(range, stdrange));
		}
	));

	TestClass testLastObject = *list.rbegin();
	TestClass testFirstObject = *list.begin();

	CHECK_RESULT_SUCCESS(doTestCase(
		"popBack()"
		, [&]()
		{
			list.popBack();
			stdlist.pop_back();
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"pushBack()"
		, [&]()
		{
			list.pushBack(testLastObject);
			stdlist.push_back(testLastObject);
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"emplaceBack()"
		, [&]()
		{
			list.emplaceBack(long{ -6000 }, int{ -600 }, short{ -60 }, '6');
			stdlist.emplace_back(long{ -6000 }, int{ -600 }, short{ -60 }, '6');
			CHECK_RESULT_SUCCESS(compareContainers(list, stdlist));

			list.popBack();
			stdlist.pop_back();
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"popFront()"
		, [&]()
		{
			list.popFront();
			stdlist.pop_front();
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"pushFront()"
		, [&]()
		{
			list.pushFront(testFirstObject);
			stdlist.push_front(testFirstObject);
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"emplaceFront()"
		, [&]()
		{
			list.emplaceFront(long{ -6000 }, int{ -600 }, short{ -60 }, '6');
			stdlist.emplace_front(long{ -6000 }, int{ -600 }, short{ -60 }, '6');
			CHECK_RESULT_SUCCESS(compareContainers(list, stdlist));

			list.popFront();
			stdlist.pop_front();
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	TestClass testMiddleObject = { long{ -2500 }, int{ -250 }, short{ -25 }, 'M'};
	testFirstObject = { long{ -1000 }, int{ -100 }, short{ -10 }, 'F'};
	testLastObject = { long{ -5000 }, int{ -500 }, short{ -50 }, 'L'};

	CHECK_RESULT_SUCCESS(doTestCase(
		"insert()"
		, [&]()
		{
			list.insert(list.begin(), testFirstObject);
			list.insert(++(++(++list.begin())), testMiddleObject);
			list.insert(list.end(), testLastObject);

			stdlist.insert(stdlist.begin(), testFirstObject);
			stdlist.insert(++(++(++stdlist.begin())), testMiddleObject);
			stdlist.insert(stdlist.end(), testLastObject);

			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"erase()"
		, [&]()
		{
			list.erase(list.begin());
			list.erase(++(++list.begin()));
			list.erase(list.end());

			stdlist.erase(stdlist.begin());
			stdlist.erase(++(++stdlist.begin()));
			stdlist.erase(--stdlist.end());

			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"emplace()"
		, [&]()
		{
			list.emplace(list.begin(), testFirstObject);
			list.emplace(++(++(++list.begin())), testMiddleObject);
			list.emplace(list.end(), testLastObject);
			stdlist.emplace(stdlist.begin(), testFirstObject);
			stdlist.emplace(++(++(++stdlist.begin())), testMiddleObject);
			stdlist.emplace(stdlist.end(), testLastObject);
			CHECK_RESULT_SUCCESS(compareContainers(list, stdlist));

			list.erase(list.begin());
			list.erase(++(++list.begin()));
			list.erase(list.end());
			stdlist.erase(stdlist.begin());
			stdlist.erase(++(++stdlist.begin()));
			stdlist.erase(--stdlist.end());
			CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
		}
	));

	{
		TestClass testlist[] = {
			testFirstObject, testMiddleObject, testLastObject
		};
		constexpr size_t countObjects = sizeof(testlist) / sizeof(testlist[0]);

		CHECK_RESULT_SUCCESS(doTestCase(
			"insert range to begin()"
			, [&]()
			{
				list.insert(list.begin(), testlist, testlist + countObjects);
				stdlist.insert(stdlist.begin(), testlist, testlist + countObjects);
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"erase range from begin()"
			, [&]()
			{
				list.erase(list.begin(), ++(++(++list.begin())));
				stdlist.erase(stdlist.begin(), ++(++(++stdlist.begin())));
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			std::string("insert range to begin() + offset(") + std::to_string(countObjects) + ")"
			, [&]()
			{
				list.insert(++(++(++list.begin())), testlist, testlist + countObjects);
				stdlist.insert(++(++(++stdlist.begin())), testlist, testlist + countObjects);
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			std::string("erase range from begin() + offset(") + std::to_string(countObjects) + ")"
			, [&]()
			{
				list.erase(++(++(++list.begin()))
						, ++(++(++(++(++(++list.begin()))))) );
				stdlist.erase( ++(++(++stdlist.begin()))
						, ++(++(++(++(++(++stdlist.begin()))))) );
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"insert range to end()"
			, [&]()
			{
				list.insert(list.end(), testlist, testlist + countObjects);
				stdlist.insert(stdlist.end(), testlist, testlist + countObjects);
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"erase range from end()"
			, [&]()
			{
				list.erase(--(--(--list.end())), list.end());
				stdlist.erase(--(--(--stdlist.end())), stdlist.end());
				CHECK_RESULT_SUCCESS_END(compareContainers(list, stdlist));
			}
		));
	}

	return 0;
}
