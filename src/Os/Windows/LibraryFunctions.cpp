#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

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
	return reinterpret_cast<LibraryHandle::Symbol>(
			GetProcAddress(handle.address, name)
	);
}

void close(LibraryHandle &handle) noexcept
{
	FreeLibrary(handle.address);
	handle = LIBRARY_HANDLE_INVALID;
}

}}}
