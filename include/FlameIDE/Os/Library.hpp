#ifndef FLAMEIDE_OS_LIBRARY_HPP
#define FLAMEIDE_OS_LIBRARY_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

class Library
{
public:
	Library() noexcept;

	Library(Library &&library) noexcept;

	Library(const char *libraryPath);

	~Library() noexcept;

	Library &operator=(Library &&library) noexcept;

	operator bool() const noexcept;

	template<typename Symbol>
	Symbol find(const char *name) noexcept;

private:
	Library(LibraryHandle libraryHandle) noexcept;

	LibraryHandle::Symbol internalFind(const char *name) noexcept;

private:
	LibraryHandle handle;
};

}} // namespace flame_ide::os

namespace flame_ide
{namespace os
{

template<typename Symbol>
Symbol Library::find(const char *name) noexcept
{
	return reinterpret_cast<Symbol>(internalFind(name));
}

}}

#endif // FLAMEIDE_OS_LIBRARY_HPP
