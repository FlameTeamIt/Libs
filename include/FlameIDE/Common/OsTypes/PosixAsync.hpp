#ifndef FLAMEIDE_COMMON_OSTYPES_POSIXASYNC_HPP
#define FLAMEIDE_COMMON_OSTYPES_POSIXASYNC_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#ifdef FLAMEIDE_ENABLE_ASYNC

#include <aio.h>

namespace flame_ide
{namespace os
{namespace posix
{

struct OsAsyncIoContext : public ::aiocb
{
	constexpr OsAsyncIoContext() : ::aiocb{}
	{
		aio_nbytes = 0;
		aio_fildes = -1;
		aio_offset = 0;
		aio_buf = nullptr;
	}
};
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

}}}

#endif // defined(FLAMEIDE_ENABLE_ASYNC)

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_COMMON_OSTYPES_POSIXASYNC_HPP
