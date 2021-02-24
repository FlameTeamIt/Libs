#ifndef FLAMEIDE_OS_TYPES_HPP
#define FLAMEIDE_OS_TYPES_HPP

#include <FlameIDE/Os/Posix/Types.hpp>
#include <FlameIDE/Os/Windows/Types.hpp>

namespace flame_ide
{namespace os
{

/// @brief
using FileDescriptor = FLAMEIDE_OS_NAMESPACE::OsFileDescriptor;

/// @brief
constexpr FileDescriptor INVALID_DESCRIPTOR =
		FLAMEIDE_OS_NAMESPACE::OS_INVALID_DESCRIPTOR;

/// @brief
using Status = FLAMEIDE_OS_NAMESPACE::OsStatus;

/// @brief
constexpr Status STATUS_SUCCESS =
		FLAMEIDE_OS_NAMESPACE::OS_STATUS_SUCCESS;

/// @brief
using Socket = FLAMEIDE_OS_NAMESPACE::OsSocket;
constexpr Socket SOCKET_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_SOCKET_INITIALIZER;

/// @brief
using ThreadContext = FLAMEIDE_OS_NAMESPACE::OsThreadContext;

/// @brief
constexpr ThreadContext THREAD_CONTEXT_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_THREAD_CONTEXT_INITIALIZER;

/// @brief
using ThreadTaskTrait = FLAMEIDE_OS_NAMESPACE::OsThreadTaskTrait;

/// @brief
using MutexContext = FLAMEIDE_OS_NAMESPACE::OsMutexContext;

/// @brief
constexpr MutexContext MUTEX_CONTEXT_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_MUTEX_CONTEXT_INITIALIZER;

/// @brief
using SemaphoreContext = FLAMEIDE_OS_NAMESPACE::OsSemaphoreContext;

/// @brief
constexpr SemaphoreContext SEMAPHORE_CONTEXT_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_SEMAPHORE_CONTEXT_INITIALIZER;

/// @brief
using SemaphoreValue = FLAMEIDE_OS_NAMESPACE::OsSemaphoreValue;

/// @brief
constexpr SemaphoreValue SEMAPHORE_VALUE_DEFAULT =
		FLAMEIDE_OS_NAMESPACE::OS_SEMAPHORE_VALUE_DEFAULT;

/// @brief
constexpr SemaphoreValue SEMAPHORE_VALUE_INVALID =
		FLAMEIDE_OS_NAMESPACE::OS_SEMAPHORE_VALUE_INVALID;

/// @brief The ActionType enum
enum class ActionType
{
	READER
	, WRITER
	, BIDIRECTIONAL
};

/// @brief The ActionMethod enum
enum class ActionMethod
{
	SYNCHRONOUS
	, ASYNCHRONOUS
};

/// @brief The StreamType enum
enum class StreamType
{
	MEMORY
	, PIPE
	, NAMED_PIPE
	, FILE
	, SOCKET
};

/// @brief PLATFORM_PREFIX
constexpr auto PIPE_NAME_PREFIX = FLAMEIDE_OS_NAMESPACE::OS_PLATFORM_PREFIX;

/// @brief Library handler
using LibraryHandle = FLAMEIDE_OS_NAMESPACE::OsLibraryHandle;
constexpr auto LIBRARY_HANDLE_INVALID = FLAMEIDE_OS_NAMESPACE::OS_LIBRARY_HANDLE_INVALID;

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_TYPES_HPP
