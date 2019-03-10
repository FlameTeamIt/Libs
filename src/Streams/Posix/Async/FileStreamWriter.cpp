#include <FlameIDE/Streams/Async/FileStreamWriter.hpp>

namespace flame_ide
{namespace streams
{namespace async
{

FileStreamWriter::FileStreamWriter() noexcept :
		context(os::ASYNC_CONTEXT_INITIALIZER), own(false), inputRange()
{
}

FileStreamWriter::~FileStreamWriter() noexcept = default;

}}}
