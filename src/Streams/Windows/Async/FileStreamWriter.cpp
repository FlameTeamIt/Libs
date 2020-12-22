#include <FlameIDE/Streams/Async/FileStreamWriter.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

namespace flame_ide
{namespace streams
{namespace async
{

//FileStreamWriter::FileStreamWriter() noexcept :
//		context(os::ASYNC_CONTEXT_INITIALIZER), own(false), inputRange()
//{}

//FileStreamWriter::~FileStreamWriter() noexcept = default;

}}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
