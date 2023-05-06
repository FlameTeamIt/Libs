#ifndef HTTPCODE_HPP
#define HTTPCODE_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace error
{

const char *winHttpCodeToString(os::Status status) noexcept;

}}} // flame_ide::os::error

#endif // HTTPCODE_HPP
