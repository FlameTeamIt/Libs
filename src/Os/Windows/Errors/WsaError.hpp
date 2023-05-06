#ifndef WSAERROR_HPP
#define WSAERROR_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace error
{

const char *wsaCodeToString(os::Status status) noexcept;

}}} // flame_ide::os::error

#endif // WSAERROR_HPP
