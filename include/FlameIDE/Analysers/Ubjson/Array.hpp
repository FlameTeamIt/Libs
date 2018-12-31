#ifndef ANALYSERS_UBJSON_ARRAY_HPP
#define ANALYSERS_UBJSON_ARRAY_HPP

#include <FlameIDE/Analysers/Ubjson/Settings.hpp>
#include <FlameIDE/Analysers/Ubjson/Types.hpp>
#include <FlameIDE/Analysers/Ubjson/Traits.hpp>
#include <FlameIDE/Analysers/Ubjson/ValueSpecializations.hpp>

#include <FlameIDE/Templates/HybridVector.hpp>

namespace flame_ide
{namespace ubjson
{namespace utils
{

template<typename ValueVariantType>
class Array
{
public:
	enum
	{
		ArrayIndex
		, VectorIndex
	};

	using Type = ValueVariantType;
	using Container = templates::HybridVector<Type, Settings::MAX_STATIC_SIZE>;

	Array() : container()
	{}

	~Array()
	{}

	void pushBack(const Type &value)
	{
		container.template pushBack(value);
	}

private:
	Container container;
};

}}}

#endif // ANALYSERS_UBJSON_ARRAY_HPP
