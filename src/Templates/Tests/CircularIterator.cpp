#include "CircularIterator.hpp"

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
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

	return 0;
}

}}
