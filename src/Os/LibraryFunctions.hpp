#ifndef LIBRARYFUNCTIONS_HPP
#define LIBRARYFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace library
{

LibraryHandle open(const char *path) noexcept;

LibraryHandle::Symbol findSymbol(LibraryHandle handle, const char *name) noexcept;

void close(LibraryHandle &handle) noexcept;

}}} // namespace flame_ide::os::library

#endif // LIBRARYFUNCTIONS_HPP
