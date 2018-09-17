#ifndef ANALYSERS_UBJSON_SETTINGS_HPP
#define ANALYSERS_UBJSON_SETTINGS_HPP

#include <Common/PrimitiveTypes.hpp>
#include <Common/Traits.hpp>

namespace flame_ide
{namespace ubjson
{

struct Settings : public NonCreational
{
	static constexpr size_t MAX_STATIC_SIZE = 32;
};

}}

#endif // ANALYSERS_UBJSON_SETTINGS_HPP
