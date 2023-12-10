#ifndef FLAMEIDE_LSP_TYPES_BASETYPES_HPP
#define FLAMEIDE_LSP_TYPES_BASETYPES_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Variant.hpp>

namespace flame_ide
{namespace lsp
{namespace types
{

using integer = flame_ide::Types::int_t;
using uinteger = flame_ide::Types::uint_t;
using decimal = integer;
using boolean = bool;

struct string {};
struct null {};

struct LspObject {};
struct LspArray {};
using LspAny = flame_ide::templates::Variant<
	LspObject, LspArray, string, integer, uinteger,	decimal, boolean, null
>;

}}} // namespace flame_ide::lsp::types

#endif // FLAMEIDE_LSP_TYPES_BASETYPES_HPP
