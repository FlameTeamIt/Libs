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
using Status = FLAMEIDE_OS_NAMESPACE::OsStatus;

using Address = FLAMEIDE_OS_NAMESPACE::OsAddressContext;

/// @brief
using Socket = FLAMEIDE_OS_NAMESPACE::OsSocketContext;

/// @brief
using ThreadContext = FLAMEIDE_OS_NAMESPACE::OsThreadContext;

/// @brief
using ThreadAttributes = FLAMEIDE_OS_NAMESPACE::OsThreadAttributes;

/// @brief
using ThreadTaskTrait = FLAMEIDE_OS_NAMESPACE::OsThreadTaskTrait;

/// @brief
struct ThreadTask
{
public:
	inline operator bool()
	{
		return taskValue && argumentValue;
	}

public:
	ThreadTaskTrait::TaskType taskValue;
	ThreadTaskTrait::ArgumentType argumentValue;
};

/// @brief
using MutexContext = FLAMEIDE_OS_NAMESPACE::OsMutexContext;

/// @brief
using SemaphoreContext = FLAMEIDE_OS_NAMESPACE::OsSemaphoreContext;

/// @brief
using SemaphoreValue = FLAMEIDE_OS_NAMESPACE::OsSemaphoreValue;

/// @brief Library handler
using LibraryHandle = FLAMEIDE_OS_NAMESPACE::OsLibraryHandle;

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

/// @brief The DescriptorPair struct
struct DescriptorPair
{
	FileDescriptor descriptors[2];
};

}} // namespace flame_ide::os

#undef FLAMEIDE_OS_NAMESPACE

#endif // FLAMEIDE_OS_TYPES_HPP
