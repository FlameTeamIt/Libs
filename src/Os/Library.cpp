#include <FlameIDE/Os/Library.hpp>

#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace os
{

namespace
{

LibraryHandle getHandle(const char *name, const char *directory)
{
	constexpr size_t maxPathLength = 2048;

	const char *libraryPrefix = os::LIBRARY_PREFIX;
	const char *librarySuffixShared = os::LIBRARY_SUFFIX_SHARED;

	const size_t directoryLength = templates::String::rawStringLength(directory);
	const size_t nameLength = templates::String::rawStringLength(name);
	const size_t nameFullLength = templates::String::rawStringLength(libraryPrefix)
			+ nameLength
			+ templates::String::rawStringLength(librarySuffixShared);

	const size_t fullPathLength = directoryLength + 1 + nameFullLength; // + slash
	if (fullPathLength > maxPathLength)
	{
		templates::Array<char, maxPathLength> fullPathStatic;
		if (directory)
		{
			fullPathStatic.insert(fullPathStatic.end()
					, directory, directory + directoryLength);
			fullPathStatic.pushBack(DIRECTORY_SLASH);
		}
		fullPathStatic.insert(fullPathStatic.end()
				, libraryPrefix
				, libraryPrefix + templates::String::rawStringLength(libraryPrefix));
		fullPathStatic.insert(fullPathStatic.end()
				, name, name + nameLength);
		fullPathStatic.insert(
				fullPathStatic.end()
				, librarySuffixShared
				, librarySuffixShared + templates::String::rawStringLength(
						librarySuffixShared
				)
		);

		fullPathStatic.insert(fullPathStatic.end(), char{});
		return library::open(fullPathStatic.data());
	}
	else
	{
		templates::String fullPathString;
		fullPathString.reserve(fullPathLength + 1);
		if (directory)
		{
			fullPathString += directory;
			fullPathString += DIRECTORY_SLASH;
		}
		fullPathString.insert(fullPathString.end(), libraryPrefix);
		fullPathString.insert(fullPathString.end(), name);
		fullPathString.insert(fullPathString.end(), librarySuffixShared);

		return library::open(fullPathString.data());
	}

}

} // namespace anonymous

Library::Library() noexcept : Library{ LIBRARY_HANDLE_INVALID }
{}

Library::Library(Library &&library) noexcept : handle{ library.handle }
{
	library.handle = LIBRARY_HANDLE_INVALID;
}

Library::Library(const char *name, const char *directory)
		: handle{ getHandle(name, directory) }
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
