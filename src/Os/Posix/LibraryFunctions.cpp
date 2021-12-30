#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace library
{

LibraryHandle open(const char *path) noexcept
{
	return LibraryHandle{
		dlopen(path, LibraryHandle::OPEN_FLAG)
	};
}

LibraryHandle::Symbol findSymbol(LibraryHandle handle, const char *name) noexcept
{
	return dlsym(handle.address, name);
}

void close(LibraryHandle &handle) noexcept
{
	dlclose(handle.address);
	handle = LIBRARY_HANDLE_INVALID;
}

}}} // namespace flame_ide::os::library

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
