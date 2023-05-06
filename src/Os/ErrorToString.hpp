#ifndef ERRORTOSTRING_HPP
#define ERRORTOSTRING_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace error
{

const char *errorInfo(Status status) noexcept;

}}} // namespace flame_ide::os::error

#endif // ERRORTOSTRING_HPP
