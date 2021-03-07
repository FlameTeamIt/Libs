#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

namespace flame_ide
{namespace os
{namespace library
{

LibraryHandle open(const char *path) noexcept
{
	return LibraryHandle{ LoadLibraryA(path) };
}

LibraryHandle::Symbol findSymbol(LibraryHandle handle, const char *name) noexcept
{
	return GetProcAddress(handle.address, name);
}

void close(LibraryHandle &handle) noexcept
{
	FreeLibrary(handle.address);
	handle = LIBRARY_HANDLE_INVALID;
}

}}}
