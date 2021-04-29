#ifndef FLAMEIDE_OS_WINDOWS_CONSTANTS_HPP
#define FLAMEIDE_OS_WINDOWS_CONSTANTS_HPP

#include <FlameIDE/Os/Windows/Types.hpp>
#include <FlameIDE/Common/Macros/DetectCompiler.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

namespace flame_ide
{namespace os
{namespace windows
{

constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = OsFileDescriptor(flame_ide::ssize_t(-1));
constexpr OsFileDescriptor OS_DESCRIPTOR_INITIALIZER = OsFileDescriptor(flame_ide::ssize_t{});

constexpr OsStatus OS_STATUS_SUCCESS = 0;

constexpr OsSocket OS_SOCKET_INITIALIZER = OsSocket {
		::SOCKADDR_IN{}, ::SOCKET{}
};

constexpr OsThreadContext OS_THREAD_CONTEXT_INITIALIZER = OS_DESCRIPTOR_INITIALIZER;

constexpr OsMutexContext OS_MUTEX_CONTEXT_INITIALIZER = OS_DESCRIPTOR_INITIALIZER;

constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_DEFAULT = 1;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_INVALID = NumberLimitTrait<
	OsSemaphoreValue
>::MIN_VALUE;

constexpr OsSemaphoreContext OS_SEMAPHORE_CONTEXT_INITIALIZER = {
	OS_DESCRIPTOR_INITIALIZER, OS_SEMAPHORE_VALUE_INVALID
};

constexpr DWORD OS_INBOUND_BUFFER_SIZE = 1024;

constexpr char OS_PLATFORM_PREFIX[] = "\\\\.\\pipe\\";

constexpr OsLibraryHandle OS_LIBRARY_HANDLE_INVALID = OsLibraryHandle{};

#if FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_MSVC
constexpr char OS_LIBRARY_PREFIX[] = "";
#else // FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_MSVC
constexpr char OS_LIBRARY_PREFIX[] = "lib";
#endif // FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_MSVC
constexpr char OS_LIBRARY_SUFFIX_SHARED[] = ".dll";

constexpr char OS_DIRECTORY_SLASH = '\\';

}}}

#ifndef FLAMEIDE_OS_NAMESPACE
#	define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::windows
#endif // FLAMEIDE_OS_NAMESPACE

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_OS_WINDOWS_CONSTANTS_HPP
