#include "CircularIteratorTest.hpp"

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

int CircularIteratorTest::vStart()
{
	using Array = templates::Array<int, 5>;
	using CircularIterator = templates::CircularIterator<
		Array::Iterator, Array::Iterator::CATEGORY
	>;

	Array array{{ 1, 2, 3, 4, 5 }};
	CircularIterator it(array.begin() + 2
			, templates::makeRange(array.begin(), array.end()));

	auto range = templates::makeRange(
		templates::SizeTypeIterator(0)
		, templates::SizeTypeIterator(5)
	);

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		it += 3;
	}
	std::cout << std::endl;

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		--it;
	}
	std::cout << std::endl;

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		it -= 3;
	}
	std::cout << std::endl;

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		it += 9;
	}
	std::cout << std::endl;

	for (auto i : range)
	{
		(void)i;
		std::cout << *it << ' ';
		it -= 9;
	}
	std::cout << std::endl;

	it = CircularIterator(array.begin() + 2
			, templates::makeRange(array.begin(), array.end())
	);
	std::cout << it[1] << std::endl;
	std::cout << it[9] << std::endl;

	using ReverseCircularIterator = templates::ReverseIterator<CircularIterator>;
	auto reverseRange = templates::makeRange(
		ReverseCircularIterator(
				CircularIterator(
					--array.end(), templates::makeRange(--array.begin(), array.end())
				)
		)
		, ReverseCircularIterator(
				CircularIterator(
					--array.begin(), templates::makeRange(--array.begin(), array.end())
				)
		)
	);

	std::cout << std::endl;
	for (auto i : reverseRange)
	{
		std::cout << i << std::endl;
	}

	return 0;
}

}}}
