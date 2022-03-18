#ifndef FLAMEIDE_OS_WINDOWS_TYPES_HPP
#define FLAMEIDE_OS_WINDOWS_TYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <winsock2.h>
#include <windows.h>
#include <winnt.h>

namespace flame_ide
{

template<>
struct NumberLimitTrait<LONG>
{
	static constexpr LONG MIN_VALUE = INT32_MIN;
	static constexpr LONG MAX_VALUE = INT32_MAX;
};

} // namespace flame_ide

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

using OsStatus = DWORD;

struct OsSocket
{
	::SOCKADDR_IN sockaddr;
	::SOCKET sock;
};

using OsThreadContext = OsFileDescriptor;

struct OsThreadTaskTrait : NonCreational
{
	using ReturnType = DWORD;
	using ArgumentType = LPVOID;
};

using OsMutexContext = OsFileDescriptor;

using OsSemaphoreValue = LONG;

struct OsSemaphoreContext
{
	OsFileDescriptor object;
	OsSemaphoreValue value;
};

struct OsLibraryHandle
{
	using Handle = decltype(LoadLibraryA(nullptr));
	using Symbol = void *; //decltype(GetProcAddress(Handle{}, nullptr));

	Handle address = Handle{};
};

}}} // namespace flame_ide::os::windows

#define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::windows

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_OS_WINDOWS_TYPES_HPP
