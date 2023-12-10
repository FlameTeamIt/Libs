#ifndef FLAMEIDE_LSP_TYPES_ABSTRACTMESSAGE_HPP
#define FLAMEIDE_LSP_TYPES_ABSTRACTMESSAGE_HPP

#include <FlameIDE/Lsp/Types/BaseTypes.hpp>

namespace flame_ide
{namespace lsp
{namespace types
{

class AbstractMessage
{
public:
	AbstractMessage() = default;
	virtual ~AbstractMessage() = default;

	virtual string contentData() const;

	const string jsonrpc; ///< NEED "2.0"
};

}}} // namespace flame_ide::lsp::types

#endif // FLAMEIDE_LSP_TYPES_ABSTRACTMESSAGE_HPP
