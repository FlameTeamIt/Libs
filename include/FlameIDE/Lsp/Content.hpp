#ifndef FLAMEIDE_LSP_TYPES_CONTENT_HPP
#define FLAMEIDE_LSP_TYPES_CONTENT_HPP

#include <FlameIDE/Lsp/Types/AbstractMessage.hpp>

namespace flame_ide
{namespace lsp
{namespace types
{

class Content
{
public:
	Content(const AbstractMessage &);
	~Content() = default;

private:
	integer length = 0;
	const AbstractMessage *message;
};

}}} // namespace flame_ide::lsp::types

#endif // FLAMEIDE_LSP_TYPES_CONTENT_HPP
