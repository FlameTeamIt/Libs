#include "FlameIDE/Common/PrimitiveTypes.hpp"
#include <FlameIDE/Os/Random.hpp>

#include <sys/random.h>

namespace flame_ide
{namespace os
{


flame_ide::primitive_types::ssize_t RandomRange(void *buf, flame_ide::primitive_types::size_t size)
{
	return getrandom(buf, size, 0);
}

}}
