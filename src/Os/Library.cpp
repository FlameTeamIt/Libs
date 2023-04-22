#include "FlameIDE/Common/Traits/ContainerTraits.hpp"
#include "FlameIDE/Templates/Allocator/ObjectAllocator.hpp"
#include <FlameIDE/Os/Library.hpp>

#include <FlameIDE/../../src/Os/LibraryFunctions.hpp>

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace os
{namespace
{

LibraryHandle getHandle(const char *name, const char *directory) noexcept;

LibraryHandle &handleRef(void *input)
{
	return *static_cast<LibraryHandle *>(input);
}

}}} // namespace anonymous

namespace flame_ide
{namespace os
{

Library::Library() noexcept
{
	handle = templates::allocator::ObjectAllocator<LibraryHandle>().construct();
	handleRef(handle) = LIBRARY_HANDLE_INVALID;
}

Library::Library(Library &&library) noexcept : handle{ library.handle }
{
	library.handle = nullptr;
}

Library::Library(const char *name, const char *directory)
		: Library()
{
	handleRef(handle) = getHandle(name, directory);
}

Library::~Library() noexcept
{
	if (*this)
	{
		library::close(handleRef(handle));
		ContainerTraits<LibraryHandle>::Pointer pointer = &handleRef(handle);
		templates::allocator::ObjectAllocator<LibraryHandle>{}.destroy(pointer);
	}
}

Library &Library::operator=(Library &&library) noexcept
{
	handle = library.handle;
	library.handle = nullptr;
	return *this;
}

Library::operator bool() const noexcept
{
	return handleRef(handle).address != LIBRARY_HANDLE_INVALID.address;
}

LibraryHandle::Symbol Library::internalFind(const char *name) noexcept
{
	return library::findSymbol(handleRef(handle), name);
}

}}


namespace flame_ide
{namespace os
{namespace
{

LibraryHandle getHandle(const char *name, const char *directory) noexcept
{
	constexpr size_t maxPathLength = Constants::MAX_STATIC_STRING_SIZE;

	const char *libraryPrefix = os::LIBRARY_PREFIX;
	const char *librarySuffixShared = os::LIBRARY_SUFFIX_SHARED;

	const size_t directoryLength = templates::String::rawStringLength(directory);
	const size_t nameLength = templates::String::rawStringLength(name);
	const size_t nameFullLength = templates::String::rawStringLength(libraryPrefix)
			+ nameLength
			+ templates::String::rawStringLength(librarySuffixShared)
			+ 1; // + '\0'

	const size_t fullPathLength = directoryLength + 1 + nameFullLength; // + slash
	if (fullPathLength < maxPathLength)
	{
		templates::Array<Types::char_t, maxPathLength> fullPathStatic;
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

		fullPathStatic.insert(fullPathStatic.end(), Types::char_t{});
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

}}} // namespace anonymous
