#ifndef FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
#define FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP

#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <windows.h>

namespace flame_ide
{namespace os
{namespace windows
{

struct OsAsyncIoContext: public ::OVERLAPPED
{
	constexpr OsAsyncIoContext() noexcept : ::OVERLAPPED{}
	{}
};
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

}}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // LAMEIDE_COMMON_OSTYPES_WINDOWSASYNC_HPP
