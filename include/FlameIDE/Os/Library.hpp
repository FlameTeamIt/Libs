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

	/// @brief Contructor
	/// @param[in] name Library name without suffix and prefix
	/// @param[in] directory Library location. Optional parameter
	Library(const char *name, const char *directory = nullptr);

	~Library() noexcept;

	Library &operator=(Library &&library) noexcept;

	operator bool() const noexcept;

	template<typename SymbolType>
	SymbolType find(const char *name) noexcept;

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

template<typename SymbolType>
SymbolType Library::find(const char *name) noexcept
{
	return reinterpret_cast<SymbolType>(internalFind(name));
}

}}

#endif // FLAMEIDE_OS_LIBRARY_HPP
