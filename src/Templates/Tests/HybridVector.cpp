#include <Templates/View.hpp>

#include "HybridVector.hpp"

namespace flame_ide
{namespace test
{

HybridVector::HybridVector() : AbstractTest("HybridVector")
{}

HybridVector::~HybridVector()
{}

int HybridVector::vStart()
{
	if (!iterators())
	{
		return -1;
	}

	if (!container())
	{
		return -1;
	}

	return 0;
}

bool HybridVector::iterators()
{
	log << std::endl;

	constexpr Types::size_t SIZE = 4;
	Vector vector;
	vector.reserve(SIZE);
	for (Types::size_t i = 0; i < SIZE; ++i)
	{
		vector.pushBack(Vector::Type(i));
	}
	static_assert(!isSameTypes<Array::Iterator, Vector::Iterator>(), "");

	{
		HybVectorIterator itBeign = vector.begin();
		HybVectorIterator itEnd = vector.end();
		for (auto it = vector.begin(); it != vector.end(); ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
		for (auto it = itBeign; it != itEnd; ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}

	ContainerTraits<Vector>::ConstReference cvector = vector;
	{
		HybConstVectorIterator itBeign = cvector.begin();
		HybConstVectorIterator itEnd = cvector.end();
		for (auto it = vector.begin(); it != vector.end(); ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
		for (auto it = itBeign; it != itEnd; ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}

	return true;
}

bool HybridVector::container()
{
	log << std::endl;

	{
		// Creating by array
		{
			Array array{{0, 1, 2, 3}};
			HybVector hybVector{array};
			for (auto it = hybVector.begin(); it != hybVector.end(); ++it)
			{
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
		}

		// Creating by vector
		{
			Vector vector{{0, 1, 2, 3}};
			HybVector hybVector{vector};
			for (auto i : hybVector)
			{
				std::cout << i << ' ';
			}
			std::cout << std::endl;
		}
	}

	return true;
}

}}
