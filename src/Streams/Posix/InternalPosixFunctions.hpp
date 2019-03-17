#ifndef INTERNALPOSIXFUNCTIONS_HPP
#define INTERNALPOSIXFUNCTIONS_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

os::FileDescriptor makeFifo(const char *fifoName, os::ActionType action) noexcept;
os::FileDescriptor removeFile(os::FileDescriptor fd) noexcept;

}}

#endif // INTERNALPOSIXFUNCTIONS_HPP
