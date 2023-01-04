#ifndef FLAMEIDE_OS_LIBRARY_HPP
#define FLAMEIDE_OS_LIBRARY_HPP

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>

namespace flame_ide
{namespace os
{

class Library: public flame_ide::NonCopy
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

	/// @brief Check library loaded
	operator bool() const noexcept;

	/// @brief Find typed symbols
	/// @tparam SymbolType Symbol type
	/// @param name Symbol name
	/// @return Symbol pointer, which can be nullptr if not found
	template<typename SymbolType>
	SymbolType find(const char *name) noexcept;

private:
	void *internalFind(const char *name) noexcept;

private:
	void *handle;
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

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_LIBRARY_HPP
