#include <FlameIDE/Os/Library.hpp>

#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

namespace flame_ide
{namespace os
{

Library::Library() noexcept : Library{ LIBRARY_HANDLE_INVALID }
{}

Library::Library(Library &&library) noexcept : handle{ library.handle }
{
	library.handle = LIBRARY_HANDLE_INVALID;
}

Library::Library(const char *libraryPath)
		: handle{ library::open(libraryPath) }
{}

Library::Library(LibraryHandle libraryHandle) noexcept
		: handle{ libraryHandle }
{}

Library::~Library() noexcept
{
	if (*this)
	{
		library::close(handle);
	}
}

Library &Library::operator=(Library &&library) noexcept
{
	handle = library.handle;
	library.handle = LIBRARY_HANDLE_INVALID;
	return *this;
}

Library::operator bool() const noexcept
{
	return handle.address != LIBRARY_HANDLE_INVALID.address;
}

LibraryHandle::Symbol Library::internalFind(const char *name) noexcept
{
	return library::findSymbol(handle, name);
}

}}
