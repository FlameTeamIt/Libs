#ifndef FLAMEIDE_COMMON_OSTYPES_HPP
#define FLAMEIDE_COMMON_OSTYPES_HPP

#include <FlameIDE/Common/OsTypes/Posix.hpp>
#include <FlameIDE/Common/OsTypes/Windows.hpp>

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
using AsyncIoContext = FLAMEIDE_OS_NAMESPACE::OsAsyncIoContext;

/// @brief
constexpr AsyncIoContext ASYNC_CONTEXT_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_ASYNC_CONTEXT_INITIALIZER;

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

}}

#endif // FLAMEIDE_COMMON_OSTYPES_HPP
