#include <FlameIDE/../../src/Os/FileFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <fileapi.h>

namespace flame_ide
{namespace os
{namespace file
{
namespace
{

enum class OpenType: ::DWORD
{
	// Creates a new file, always.
	// File exists:
	// * function truncates the file
	// * the function succeeds
	// * ::GetLastErroro() == ERROR_ALREADY_EXISTS (183)
	WIN_CREATE_ALWAYS = CREATE_ALWAYS

	// Creates a new file, only if it does not already exist.
	// File exists:
	// * function fails
	// * ::GetLastErroro() == ERROR_FILE_EXISTS (80)
	, WIN_CREATE_NEW = CREATE_NEW

	// Opens a file, always.
	// File exists:
	// * function succeeds
	// * ::GetLastErroro() == ERROR_ALREADY_EXISTS (183)
	// File does not exist && path is valid:
	// * function creates a file
	// * ::GetLastErroro() == 0
	, WIN_OPEN_ALWAYS = OPEN_ALWAYS

	// Opens a file or device, only if it exists.
	// Аile or device does not exist:
	// * function fails
	// * ::GetLastErroro() == ERROR_FILE_NOT_FOUND (2)
	, WIN_OPEN_EXISTING = OPEN_EXISTING

	// Opens a file and truncates it so that its size is zero bytes, only if it exists
	// File does not exist:
	// * function fails
	// * ::GetLastErroro() == ERROR_FILE_NOT_FOUND (2)
	, WIN_TRUNCATE_EXISTING = TRUNCATE_EXISTING
};

enum class Flags: ::DWORD
{
	// Attributes

	//
	WIN_FILE_ATTRIBUTE_ARCHIVE = FILE_ATTRIBUTE_ARCHIVE

	//
	, WIN_FILE_ATTRIBUTE_ENCRYPTED = FILE_ATTRIBUTE_ENCRYPTED

	//
	, WIN_FILE_ATTRIBUTE_HIDDEN = FILE_ATTRIBUTE_HIDDEN

	//
	, WIN_FILE_ATTRIBUTE_NORMAL = FILE_ATTRIBUTE_NORMAL

	//
	, WIN_FILE_ATTRIBUTE_OFFLINE = FILE_ATTRIBUTE_OFFLINE

	//
	, WIN_FILE_ATTRIBUTE_READONLY = FILE_ATTRIBUTE_READONLY

	//
	, WIN_FILE_ATTRIBUTE_SYSTEM = FILE_ATTRIBUTE_SYSTEM

	//
	, WIN_FILE_ATTRIBUTE_TEMPORARY = FILE_ATTRIBUTE_TEMPORARY

	// Flags

	//
	, WIN_FILE_FLAG_BACKUP_SEMANTICS = FILE_FLAG_BACKUP_SEMANTICS

	//
	, WIN_FILE_FLAG_DELETE_ON_CLOSE = FILE_FLAG_DELETE_ON_CLOSE

	//
	, WIN_FILE_FLAG_NO_BUFFERING = FILE_FLAG_NO_BUFFERING

	//
	, WIN_FILE_FLAG_OPEN_NO_RECALL = FILE_FLAG_OPEN_NO_RECALL

	//
	, WIN_FILE_FLAG_OPEN_REPARSE_POINT = FILE_FLAG_OPEN_REPARSE_POINT

	//
	, WIN_FILE_FLAG_OVERLAPPED = FILE_FLAG_OVERLAPPED

	//
	, WIN_FILE_FLAG_POSIX_SEMANTICS = FILE_FLAG_POSIX_SEMANTICS

	//
	, WIN_FILE_FLAG_RANDOM_ACCESS = FILE_FLAG_RANDOM_ACCESS

	//
	, WIN_FILE_FLAG_SESSION_AWARE = FILE_FLAG_SESSION_AWARE

	//
	, WIN_FILE_FLAG_SEQUENTIAL_SCAN = FILE_FLAG_SEQUENTIAL_SCAN

	//
	, WIN_FILE_FLAG_WRITE_THROUGH = FILE_FLAG_WRITE_THROUGH
};

inline Flags operator|(Flags access1, Flags access2)
{
	using UnderlyingType = ::DWORD;
	return static_cast<Flags>(
			static_cast<UnderlyingType>(access1) | static_cast<UnderlyingType>(access2)
	);
}

inline Flags operator&(Flags access1, Flags access2)
{
	using UnderlyingType = ::DWORD;
	return static_cast<Flags>(
			static_cast<UnderlyingType>(access1) & static_cast<UnderlyingType>(access2)
	);
}

inline Access operator|(Access access1, Access access2)
{
	using UnderlyingType = int;
	return static_cast<Access>(
			static_cast<UnderlyingType>(access1) | static_cast<UnderlyingType>(access2)
	);
}

inline Access operator&(Access access1, Access access2)
{
	using UnderlyingType = int;
	return static_cast<Access>(
			static_cast<UnderlyingType>(access1) & static_cast<UnderlyingType>(access2)
	);
}

auto toWinApi(Access access)
{
	DWORD winApiAccess{};
	if ((access & Access::READ) == Access::READ)
	{
		winApiAccess |= GENERIC_READ;
	}
	if ((access & Access::WRITE) == Access::WRITE)
	{
		winApiAccess |= GENERIC_WRITE;
	}
	return winApiAccess;
}

ExpectedFile file(const char *name, Access access)
{
	using ResultType = decltype(open(name, access));

	ResultType result;

	// https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea
	/*
	os::FileDescriptor descriptor = ::CreateFileA(
			// [in]           LPCSTR                lpFileName,
			// [in]           DWORD                 dwDesiredAccess,
			// [in]           DWORD                 dwShareMode,
			// [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
			// [in]           DWORD                 dwCreationDisposition,
			// [in]           DWORD                 dwFlagsAndAttributes,
			// [in, optional] HANDLE                hTemplateFile
	);
	*/
	os::FileDescriptor descriptor = os::INVALID_DESCRIPTOR;
	if (descriptor == os::INVALID_DESCRIPTOR)
	{
		os::Status status = ::GetLastError();
		result = status;
		return result;
	}
	result = descriptor;
	return result;
}

using LargeInteger = ::LARGE_INTEGER;

}
}}} // namespace flame_ide::os::file


namespace flame_ide
{namespace os
{namespace file
{

ExpectedFile open(const char *name, Access access) noexcept
{
	return file(name, access);
}

ExpectedFile create(const char *name, Access access) noexcept
{
	return file(name, access);
}

bool close(os::FileDescriptor &desciptor) noexcept
{
	os::FileDescriptor tmp = desciptor;

	desciptor = os::INVALID_DESCRIPTOR;

	return (::CloseHandle(tmp) != 0);
}

bool remove(const char *name) noexcept
{
	return (::DeleteFileA(name) != 0);
}

// GetFileSizeEx
ExpectedFileSize size(os::FileDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);

	ExpectedFileSize fileSize;
	fileSize = os::STATUS_FAILED;
	return fileSize;
}

// ReadFile
void read(os::FileDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
}

// WriteFile
void write(os::FileDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
}

// SetFilePointerEx
void position(os::FileDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
}

}}} // namespace flame_ide::os::file
