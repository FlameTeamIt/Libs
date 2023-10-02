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
#include <errno.h>

namespace flame_ide
{

template<>
struct IsPrimitiveTrait<::LONG>: public TrueType
{};

template<>
struct IsPrimitiveTrait<::DWORD>: public TrueType
{};

template<>
struct IsSignedTrait<::LONG>: public TrueType
{};

template<>
struct IsSignedTrait<::DWORD>: public FalseType
{};

template<>
struct IsUnsignedTrait<::LONG>: public FalseType
{};

template<>
struct IsUnsignedTrait<::DWORD>: public TrueType
{};

template<>
struct NumberLimitTrait<::LONG>
{
	static constexpr ::LONG MIN_VALUE = INT32_MIN;
	static constexpr ::LONG MAX_VALUE = INT32_MAX;
};

template<>
struct NumberLimitTrait<::DWORD>
{
	static constexpr ::DWORD MIN_VALUE = 0;
	static constexpr ::DWORD MAX_VALUE = UINT32_MAX;
};

template<>
struct MakeSignedTrait<::LONG>
{
	using Type = ::LONG;
};

template<>
struct MakeSignedTrait<::DWORD>
{
	using Type = ::LONG;
};

template<>
struct MakeUnsignedTrait<::LONG>
{
	using Type = ::DWORD;
};

template<>
struct MakeUnsignedTrait<::DWORD>
{
	using Type = ::DWORD;
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

	constexpr bool operator==(const OsFileDescriptor &fd) const noexcept
	{
		return value == fd.value;
	}

	constexpr bool operator==(::HANDLE handle1) const noexcept
	{
		return handle == handle1;
	}

	constexpr bool operator==(flame_ide::ssize_t value1) const noexcept
	{
		return value == value1;
	}

	constexpr bool operator!=(const OsFileDescriptor &fd) const noexcept
	{
		return !operator==(fd);
	}

	constexpr bool operator!=(::HANDLE handle1) const noexcept
	{
		return !operator==(handle1);
	}

	constexpr bool operator!=(flame_ide::ssize_t value1) const noexcept
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

using OsSecurityAttributes = ::SECURITY_ATTRIBUTES;

using OsStatus = flame_ide::MakeSignedType<::DWORD>;

using OsSocketAddressIn = ::SOCKADDR_IN;
using OsSocketDescriptor = ::SOCKET;

struct OsSocketReceive;
struct OsSocket
{
	constexpr OsSocket() noexcept = default;
	OsSocket(const OsSocket &) noexcept = default;

	constexpr OsSocket(
			const OsSocketDescriptor descriptor, const OsSocketAddressIn address
	) noexcept : descriptor{descriptor}, address{address}
	{}

	OsSocket(const OsSocketReceive &) noexcept;

	OsSocket &operator=(const OsSocket &) noexcept = default;
	OsSocket &operator=(const OsSocketReceive &socketReceive) noexcept;

	OsSocketDescriptor descriptor = INVALID_SOCKET;
	OsSocketAddressIn address = {};
};
struct OsSocketReceive
{
	constexpr OsSocketReceive() noexcept = default;
	OsSocketReceive(const OsSocketReceive &) noexcept = default;
	OsSocketReceive(const OsSocket &) noexcept;

	OsSocketReceive &operator=(const OsSocketReceive &) noexcept = default;
	OsSocketReceive &operator=(const OsSocket &socket) noexcept;

	OsSocketAddressIn address = {};
	const OsSocketDescriptor *descriptor = nullptr;
};

using OsThreadId = ::DWORD;
struct OsThreadContext
{
	OsFileDescriptor object;
	OsThreadId id;

	constexpr bool operator==(const OsThreadContext &context) const noexcept
	{
		return (object.value == context.object.value) && (id == context.id);
	}

	constexpr bool operator!=(const OsThreadContext &context) const noexcept
	{
		return !operator==(context);
	}
};

struct OsThreadTaskTrait: public NonCreational
{
	using Return = DWORD;
	using Argument = LPVOID;
	using Task = Return(*)(Argument);
};

struct OsMutexContext
{
	OsFileDescriptor object;
};

using OsSemaphoreValue = ::LONG;
struct OsSemaphoreContext
{
	inline bool operator==(const OsSemaphoreContext &context) const
	{
		return (context.object.value == object.value)
				&& (context.value == value);
	}

	inline bool operator!=(const OsSemaphoreContext &context) const
	{
		return !operator==(context);
	}

	OsFileDescriptor object;
	OsSemaphoreValue value;
};

using OsSpinlockValue = ::LONG;
struct OsSpinlockContext
{
	OsSpinlockValue value;
};

struct OsLibraryHandle
{
	using Handle = decltype(LoadLibraryA(nullptr));
	using Symbol = decltype(GetProcAddress(Handle{}, nullptr));

	Handle address = Handle{};
};

using OsMessage = ::MSG;
using OsWindowHandle = ::HWND;
using OsWindowClass = ::WNDCLASSA;
using OsWindowCallback = ::WNDPROC;
using OsBrush = ::HBRUSH;
using OsAtom = ::ATOM;
struct OsWindow
{
	OsWindowHandle handle = {};
	OsAtom atom = {};
};

using OsResult = ::LRESULT;
using OsParam = ::LPARAM;

}}} // namespace flame_ide::os::windows

#define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::windows

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_OS_WINDOWS_TYPES_HPP
