#ifndef FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
#define FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP

#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Common/PrimitiveTypes.hpp>

#include <winsock2.h>
#include <windows.h>

#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{

template<>
struct NumberLimit<LONG>
{
	static constexpr LONG MIN_VALUE = INT32_MIN;
	static constexpr LONG MAX_VALUE = INT32_MAX;
};

}

namespace flame_ide
{namespace os
{namespace windows
{

union OsFileDescriptor
{
	constexpr OsFileDescriptor() noexcept : handle{}
	{}

	constexpr OsFileDescriptor(const OsFileDescriptor &fd) noexcept : value{ fd.value }
	{}

	constexpr OsFileDescriptor(flame_ide::ssize_t initValue) noexcept : value{ initValue }
	{}

	constexpr OsFileDescriptor(::HANDLE initHandle) noexcept : handle{ initHandle }
	{}

	constexpr OsFileDescriptor& operator=(const OsFileDescriptor &fd) noexcept
	{
		value = fd.value;
		return *this;
	}

	constexpr OsFileDescriptor& operator=(flame_ide::ssize_t newValue) noexcept
	{
		value = newValue;
		return *this;
	}

	constexpr OsFileDescriptor& operator=(::HANDLE newHandle) noexcept
	{
		handle = newHandle;
		return *this;
	}

	constexpr bool operator==(const OsFileDescriptor &fd) noexcept
	{
		return value == fd.value;
	}

	constexpr bool operator==(::HANDLE handle1) noexcept
	{
		return handle == handle1;
	}

	constexpr bool operator==(flame_ide::ssize_t value1) noexcept
	{
		return value == value1;
	}

	constexpr bool operator!=(const OsFileDescriptor &fd) noexcept
	{
		return !operator==(fd);
	}

	constexpr bool operator!=(::HANDLE handle1) noexcept
	{
		return !operator==(handle1);
	}

	constexpr bool operator!=(flame_ide::ssize_t value1) noexcept
	{
		return !operator==(value1);
	}

	constexpr operator ::HANDLE() noexcept
	{
		return handle;
	}

	constexpr operator flame_ide::ssize_t() noexcept
	{
		return value;
	}

	::HANDLE handle;
	flame_ide::ssize_t value;
};
constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = OsFileDescriptor(flame_ide::ssize_t(-1));
constexpr OsFileDescriptor OS_DESCRIPTOR_INITIALIZER = OsFileDescriptor(flame_ide::ssize_t{});

using OsStatus = DWORD;
constexpr OsStatus OS_STATUS_SUCCESS = 0;

struct OsSocket
{
	::SOCKADDR_IN sockaddr;
	::SOCKET sock;
};
constexpr OsSocket OS_SOCKET_INITIALIZER = OsSocket {
		::SOCKADDR_IN{}, ::SOCKET{}
};

struct OsAsyncIoContext: public ::OVERLAPPED
{
	constexpr OsAsyncIoContext() noexcept : ::OVERLAPPED{}
	{}
};
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

using OsThreadContext = OsFileDescriptor;
constexpr OsThreadContext OS_THREAD_CONTEXT_INITIALIZER = OS_DESCRIPTOR_INITIALIZER;

struct OsThreadTaskTrait : NonCreational
{
	using ReturnType = DWORD;
	using ArgumentType = LPVOID;
};

using OsMutexContext = OsFileDescriptor;
constexpr OsMutexContext OS_MUTEX_CONTEXT_INITIALIZER = OS_DESCRIPTOR_INITIALIZER;

using OsSemaphoreValue = LONG;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_DEFAULT = 1;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_INVALID = NumberLimit<OsSemaphoreValue>::MIN_VALUE;

struct OsSemaphoreContext
{
	OsFileDescriptor object;
	OsSemaphoreValue value;
};
constexpr OsSemaphoreContext OS_SEMAPHORE_CONTEXT_INITIALIZER = {
	OS_DESCRIPTOR_INITIALIZER, OS_SEMAPHORE_VALUE_INVALID
};

constexpr DWORD OS_INBOUND_BUFFER_SIZE = 1024;

constexpr char OS_PLATFORM_PREFIX[] = "\\\\.\\pipe\\";

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::windows

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
