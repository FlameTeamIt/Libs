#include <FlameIDE/Streams/Async/FileStreamReader.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{namespace async
{

FileStreamReader::FileStreamReader() noexcept :
		context(os::ASYNC_CONTEXT_INITIALIZER), own(false), outputRange()
{}

FileStreamReader::~FileStreamReader() = default;

}}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
