#include <FlameIDE/../../src/Os/Windows/SystemCode0.hpp>

#include <FlameIDE/Os/Types.hpp>

#define RETURN_STATIC_STRING(string) \
{ \
	static const char returnString[] = string; \
	return &returnString[0]; \
}

namespace flame_ide
{namespace os
{namespace error
{

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
enum class SystemCode: decltype(::GetLastError())
{
	SUCCESS =
#	if defined ERROR_SUCCESS
			ERROR_SUCCESS
#	else
			0x0
#	endif
		// The operation completed successfully.

	, INVALID_FUNCTION =
#	if defined ERROR_INVALID_FUNCTION
			ERROR_INVALID_FUNCTION
#	else
		0x1
#	endif
		// Incorrect function.

	, FILE_NOT_FOUND =
#	if defined ERROR_FILE_NOT_FOUND
			ERROR_FILE_NOT_FOUND
#	else
		0x2
#	endif
		// The system cannot find the file specified.

	, PATH_NOT_FOUND =
#	if defined ERROR_PATH_NOT_FOUND
			ERROR_PATH_NOT_FOUND
#	else
		0x3
#	endif
		// The system cannot find the path specified.

	, TOO_MANY_OPEN_FILES =
#	if defined ERROR_TOO_MANY_OPEN_FILES
			ERROR_TOO_MANY_OPEN_FILES
#	else
			0x4
#	endif
		// The system cannot open the file.

	, ACCESS_DENIED =
#	if defined ERROR_ACCESS_DENIED
			ERROR_ACCESS_DENIED
#	else
			0x5
#	endif
		// Access is denied.

	, INVALID_HANDLE =
#	if defined ERROR_INVALID_HANDLE
			ERROR_INVALID_HANDLE
#	else
			0x6
#	endif
		// The handle is invalid.

	, ARENA_TRASHED =
#	if defined ERROR_ARENA_TRASHED
			ERROR_ARENA_TRASHED
#	else
			0x7
#	endif
		// The storage control blocks were destroyed.

	, NOT_ENOUGH_MEMORY =
#	if defined ERROR_NOT_ENOUGH_MEMORY
			ERROR_NOT_ENOUGH_MEMORY
#	else
			0x8
#	endif
		// Not enough memory resources are available to process this command.

	, INVALID_BLOCK =
#	if defined ERROR_INVALID_BLOCK
			ERROR_INVALID_BLOCK
#	else
			0x9
#	endif
		// The storage control block address is invalid.

	, BAD_ENVIRONMENT =
#	if defined ERROR_BAD_ENVIRONMENT
			ERROR_BAD_ENVIRONMENT
#	else
			0xA
#	endif
		// The environment is incorrect.

	, BAD_FORMAT =
#	if defined ERROR_BAD_FORMAT
			ERROR_BAD_FORMAT
#	else
			0xB
#	endif
		// An attempt was made to load a program with an incorrect format.

	, INVALID_ACCESS =
#	if defined ERROR_INVALID_ACCESS
			ERROR_INVALID_ACCESS
#	else
			0xC
#	endif
		// The access code is invalid.

	, INVALID_DATA =
#	if defined ERROR_INVALID_DATA
			ERROR_INVALID_DATA
#	else
			0xD
#	endif
		// The data is invalid.

	, OUTOFMEMORY =
#	if defined ERROR_OUTOFMEMORY
			ERROR_OUTOFMEMORY
#	else
			0xE
#	endif
		// Not enough storage is available to complete this operation.

	, INVALID_DRIVE =
#	if defined ERROR_INVALID_DRIVE
			ERROR_INVALID_DRIVE
#	else
			0xF
#	endif
		// The system cannot find the drive specified.

	, CURRENT_DIRECTORY =
#	if defined ERROR_CURRENT_DIRECTORY
			ERROR_CURRENT_DIRECTORY
#	else
			0x10
#	endif
		// The directory cannot be removed.

	, NOT_SAME_DEVICE =
#	if defined ERROR_NOT_SAME_DEVICE
			ERROR_NOT_SAME_DEVICE
#	else
			0x11
#	endif
		// The system cannot move the file to a different disk drive.

	, NO_MORE_FILES =
#	if defined ERROR_NO_MORE_FILES
			ERROR_NO_MORE_FILES
#	else
			0x12
#	endif
		// There are no more files.

	, WRITE_PROTECT =
#	if defined ERROR_WRITE_PROTECT
			ERROR_WRITE_PROTECT
#	else
			0x13
#	endif
		// The media is write protected.

	, BAD_UNIT =
#	if defined ERROR_BAD_UNIT
			ERROR_BAD_UNIT
#	else
			0x14
#	endif
		// The system cannot find the device specified.

	, NOT_READY =
#	if defined ERROR_NOT_READY
			ERROR_NOT_READY
#	else
			0x15
#	endif
		// The device is not ready.

	, BAD_COMMAND =
#	if defined ERROR_BAD_COMMAND
			ERROR_BAD_COMMAND
#	else
			0x16
#	endif
		// The device does not recognize the command.

	, CRC =
#	if defined ERROR_CRC
			ERROR_CRC
#	else
			0x17
#	endif
		// Data error (cyclic redundancy check).

	, BAD_LENGTH =
#	if defined ERROR_BAD_LENGTH
			ERROR_BAD_LENGTH
#	else
			0x18
#	endif
		// The program issued a command but the command length is incorrect.

	, SEEK =
#	if defined ERROR_SEEK
			ERROR_SEEK
#	else
			0x19
#	endif
		// The drive cannot locate a specific area or track on the disk.

	, NOT_DOS_DISK =
#	if defined ERROR_NOT_DOS_DISK
			ERROR_NOT_DOS_DISK
#	else
			0x1A
#	endif
		// The specified disk or diskette cannot be accessed.

	, SECTOR_NOT_FOUND =
#	if defined ERROR_SECTOR_NOT_FOUND
			ERROR_SECTOR_NOT_FOUND
#	else
			0x1B
#	endif
		// The drive cannot find the sector requested.

	, OUT_OF_PAPER =
#	if defined ERROR_OUT_OF_PAPER
			ERROR_OUT_OF_PAPER
#	else
			0x1C
#	endif
		// The printer is out of paper.

	, WRITE_FAULT =
#	if defined ERROR_WRITE_FAULT
			ERROR_WRITE_FAULT
#	else
			0x1D
#	endif
		// The system cannot write to the specified device.

	, READ_FAULT =
#	if defined ERROR_READ_FAULT
			ERROR_READ_FAULT
#	else
			0x1E
#	endif
		// The system cannot read from the specified device.

	, GEN_FAILURE =
#	if defined ERROR_GEN_FAILURE
			ERROR_GEN_FAILURE
#	else
			0x1F
#	endif
		// A device attached to the system is not functioning.

	, SHARING_VIOLATION =
#	if defined ERROR_SHARING_VIOLATION
			ERROR_SHARING_VIOLATION
#	else
			0x20
#	endif
		// The process cannot access the file because it is being used by another process.

	, LOCK_VIOLATION =
#	if defined ERROR_LOCK_VIOLATION
			ERROR_LOCK_VIOLATION
#	else
			0x21
#	endif
		// The process cannot access the file because another process has locked a portion of the file.

	, WRONG_DISK =
#	if defined ERROR_WRONG_DISK
			ERROR_WRONG_DISK
#	else
			0x22
#	endif
		// The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1.

	, SHARING_BUFFER_EXCEEDED =
#	if defined ERROR_SHARING_BUFFER_EXCEEDED
			ERROR_SHARING_BUFFER_EXCEEDED
#	else
			0x24
#	endif
		// Too many files opened for sharing.

	, HANDLE_EOF =
#	if defined ERROR_HANDLE_EOF
			ERROR_HANDLE_EOF
#	else
			0x26
#	endif
		// Reached the end of the file.

	, HANDLE_DISK_FULL =
#	if defined ERROR_HANDLE_DISK_FULL
			ERROR_HANDLE_DISK_FULL
#	else
			0x27
#	endif
		// The disk is full.

	, NOT_SUPPORTED =
#	if defined ERROR_NOT_SUPPORTED
			ERROR_NOT_SUPPORTED
#	else
			0x32
#	endif
		// The request is not supported.

	, REM_NOT_LIST =
#	if defined ERROR_REM_NOT_LIST
			ERROR_REM_NOT_LIST
#	else
			0x33
#	endif
		// Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.

	, DUP_NAME =
#	if defined ERROR_DUP_NAME
			ERROR_DUP_NAME
#	else
			0x34
#	endif
		// You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.

	, BAD_NETPATH =
#	if defined ERROR_BAD_NETPATH
			ERROR_BAD_NETPATH
#	else
			0x35
#	endif
		// The network path was not found.

	, NETWORK_BUSY =
#	if defined ERROR_NETWORK_BUSY
			ERROR_NETWORK_BUSY
#	else
			0x36
#	endif
		// The network is busy.

	, DEV_NOT_EXIST =
#	if defined ERROR_DEV_NOT_EXIST
			ERROR_DEV_NOT_EXIST
#	else
			0x37
#	endif
		// The specified network resource or device is no longer available.

	, TOO_MANY_CMDS =
#	if defined ERROR_TOO_MANY_CMDS
			ERROR_TOO_MANY_CMDS
#	else
			0x38
#	endif
		// The network BIOS command limit has been reached.

	, ADAP_HDW_ERR =
#	if defined ERROR_ADAP_HDW_ERR
			ERROR_ADAP_HDW_ERR
#	else
			0x39
#	endif
		// A network adapter hardware error occurred.

	, BAD_NET_RESP =
#	if defined ERROR_BAD_NET_RESP
			ERROR_BAD_NET_RESP
#	else
			0x3A
#	endif
		// The specified server cannot perform the requested operation.

	, UNEXP_NET_ERR =
#	if defined ERROR_UNEXP_NET_ERR
			ERROR_UNEXP_NET_ERR
#	else
			0x3B
#	endif
		// An unexpected network error occurred.

	, BAD_REM_ADAP =
#	if defined ERROR_BAD_REM_ADAP
			ERROR_BAD_REM_ADAP
#	else
			0x3C
#	endif
		// The remote adapter is not compatible.

	, PRINTQ_FULL =
#	if defined ERROR_PRINTQ_FULL
			ERROR_PRINTQ_FULL
#	else
			0x3D
#	endif
		// The printer queue is full.

	, NO_SPOOL_SPACE =
#	if defined ERROR_NO_SPOOL_SPACE
			ERROR_NO_SPOOL_SPACE
#	else
			0x3E
#	endif
		// Space to store the file waiting to be printed is not available on the server.

	, PRINT_CANCELLED =
#	if defined ERROR_PRINT_CANCELLED
			ERROR_PRINT_CANCELLED
#	else
			0x3F
#	endif
		// Your file waiting to be printed was deleted.

	, NETNAME_DELETED =
#	if defined ERROR_NETNAME_DELETED
			ERROR_NETNAME_DELETED
#	else
			0x40
#	endif
		// The specified network name is no longer available.

	, NETWORK_ACCESS_DENIED =
#	if defined ERROR_NETWORK_ACCESS_DENIED
			ERROR_NETWORK_ACCESS_DENIED
#	else
			0x41
#	endif
		// Network access is denied.

	, BAD_DEV_TYPE =
#	if defined ERROR_BAD_DEV_TYPE
			ERROR_BAD_DEV_TYPE
#	else
			0x42
#	endif
		// The network resource type is not correct.

	, BAD_NET_NAME =
#	if defined ERROR_BAD_NET_NAME
			ERROR_BAD_NET_NAME
#	else
			0x43
#	endif
		// The network name cannot be found.

	, TOO_MANY_NAMES =
#	if defined ERROR_TOO_MANY_NAMES
			ERROR_TOO_MANY_NAMES
#	else
			0x44
#	endif
		// The name limit for the local computer network adapter card was exceeded.

	, TOO_MANY_SESS =
#	if defined ERROR_TOO_MANY_SESS
			ERROR_TOO_MANY_SESS
#	else
			0x45
#	endif
		// The network BIOS session limit was exceeded.

	, SHARING_PAUSED =
#	if defined ERROR_SHARING_PAUSED
			ERROR_SHARING_PAUSED
#	else
			0x46
#	endif
		// The remote server has been paused or is in the process of being started.

	, REQ_NOT_ACCEP =
#	if defined ERROR_REQ_NOT_ACCEP
			ERROR_REQ_NOT_ACCEP
#	else
			0x47
#	endif
		// No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.

	, REDIR_PAUSED =
#	if defined ERROR_REDIR_PAUSED
			ERROR_REDIR_PAUSED
#	else
			0x48
#	endif
		// The specified printer or disk device has been paused.

	, FILE_EXISTS =
#	if defined ERROR_FILE_EXISTS
			ERROR_FILE_EXISTS
#	else
			0x50
#	endif
		// The file exists.

	, CANNOT_MAKE =
#	if defined ERROR_CANNOT_MAKE
			ERROR_CANNOT_MAKE
#	else
			0x52
#	endif
		// The directory or file cannot be created.

	, FAIL_I24 =
#	if defined ERROR_FAIL_I24
			ERROR_FAIL_I24
#	else
			0x53
#	endif
		// Fail on INT 24.

	, OUT_OF_STRUCTURES =
#	if defined ERROR_OUT_OF_STRUCTURES
			ERROR_OUT_OF_STRUCTURES
#	else
			0x54
#	endif
		// Storage to process this request is not available.

	, ALREADY_ASSIGNED =
#	if defined ERROR_ALREADY_ASSIGNED
			ERROR_ALREADY_ASSIGNED
#	else
			0x55
#	endif
		// The local device name is already in use.

	, INVALID_PASSWORD =
#	if defined ERROR_INVALID_PASSWORD
			ERROR_INVALID_PASSWORD
#	else
			0x56
#	endif
		// The specified network password is not correct.

	, INVALID_PARAMETER =
#	if defined ERROR_INVALID_PARAMETER
			ERROR_INVALID_PARAMETER
#	else
			0x57
#	endif
		// The parameter is incorrect.

	, NET_WRITE_FAULT =
#	if defined ERROR_NET_WRITE_FAULT
			ERROR_NET_WRITE_FAULT
#	else
			0x58
#	endif
		// A write fault occurred on the network.

	, NO_PROC_SLOTS =
#	if defined ERROR_NO_PROC_SLOTS
			ERROR_NO_PROC_SLOTS
#	else
			0x59
#	endif
		// The system cannot start another process at this time.

	, TOO_MANY_SEMAPHORES =
#	if defined ERROR_TOO_MANY_SEMAPHORES
			ERROR_TOO_MANY_SEMAPHORES
#	else
			0x64
#	endif
		// Cannot create another system semaphore.

	, EXCL_SEM_ALREADY_OWNED =
#	if defined ERROR_EXCL_SEM_ALREADY_OWNED
			ERROR_EXCL_SEM_ALREADY_OWNED
#	else
			0x65
#	endif
		// The exclusive semaphore is owned by another process.

	, SEM_IS_SET =
#	if defined ERROR_SEM_IS_SET
			ERROR_SEM_IS_SET
#	else
			0x66
#	endif
		// The semaphore is set and cannot be closed.

	, TOO_MANY_SEM_REQUESTS =
#	if defined ERROR_TOO_MANY_SEM_REQUESTS
			ERROR_TOO_MANY_SEM_REQUESTS
#	else
			0x67
#	endif
		// The semaphore cannot be set again.

	, INVALID_AT_INTERRUPT_TIME =
#	if defined ERROR_INVALID_AT_INTERRUPT_TIME
			ERROR_INVALID_AT_INTERRUPT_TIME
#	else
			0x68
#	endif
		// Cannot request exclusive semaphores at interrupt time.

	, SEM_OWNER_DIED =
#	if defined ERROR_SEM_OWNER_DIED
			ERROR_SEM_OWNER_DIED
#	else
			0x69
#	endif
		// The previous ownership of this semaphore has ended.

	, SEM_USER_LIMIT =
#	if defined ERROR_SEM_USER_LIMIT
			ERROR_SEM_USER_LIMIT
#	else
			0x6A
#	endif
		// Insert the diskette for drive %1.

	, DISK_CHANGE =
#	if defined ERROR_DISK_CHANGE
			ERROR_DISK_CHANGE
#	else
			0x6B
#	endif
		// The program stopped because an alternate diskette was not inserted.

	, DRIVE_LOCKED =
#	if defined ERROR_DRIVE_LOCKED
			ERROR_DRIVE_LOCKED
#	else
			0x6C
#	endif
		// The disk is in use or locked by another process.

	, BROKEN_PIPE =
#	if defined ERROR_BROKEN_PIPE
			ERROR_BROKEN_PIPE
#	else
			0x6D
#	endif
		// The pipe has been ended.

	, OPEN_FAILED =
#	if defined ERROR_OPEN_FAILED
			ERROR_OPEN_FAILED
#	else
			0x6E
#	endif
		// The system cannot open the device or file specified.

	, BUFFER_OVERFLOW =
#	if defined ERROR_BUFFER_OVERFLOW
			ERROR_BUFFER_OVERFLOW
#	else
			0x6F
#	endif
		// The file name is too long.

	, DISK_FULL =
#	if defined ERROR_DISK_FULL
			ERROR_DISK_FULL
#	else
			0x70
#	endif
		// There is not enough space on the disk.

	, NO_MORE_SEARCH_HANDLES =
#	if defined ERROR_NO_MORE_SEARCH_HANDLES
			ERROR_NO_MORE_SEARCH_HANDLES
#	else
			0x71
#	endif
		// No more internal file identifiers available.

	, INVALID_TARGET_HANDLE =
#	if defined ERROR_INVALID_TARGET_HANDLE
			ERROR_INVALID_TARGET_HANDLE
#	else
			0x72
#	endif
		// The target internal file identifier is incorrect.

	, INVALID_CATEGORY =
#	if defined ERROR_INVALID_CATEGORY
			ERROR_INVALID_CATEGORY
#	else
			0x75
#	endif
		// The IOCTL call made by the application program is not correct.

	, INVALID_VERIFY_SWITCH =
#	if defined ERROR_INVALID_VERIFY_SWITCH
			ERROR_INVALID_VERIFY_SWITCH
#	else
			0x76
#	endif
		// The verify-on-write switch parameter value is not correct.

	, BAD_DRIVER_LEVEL =
#	if defined ERROR_BAD_DRIVER_LEVEL
			ERROR_BAD_DRIVER_LEVEL
#	else
			0x77
#	endif
		// The system does not support the command requested.

	, CALL_NOT_IMPLEMENTED =
#	if defined ERROR_CALL_NOT_IMPLEMENTED
			ERROR_CALL_NOT_IMPLEMENTED
#	else
			0x78
#	endif
		// This function is not supported on this system.

	, SEM_TIMEOUT =
#	if defined ERROR_SEM_TIMEOUT
			ERROR_SEM_TIMEOUT
#	else
			0x79
#	endif
		// The semaphore timeout period has expired.

	, INSUFFICIENT_BUFFER =
#	if defined ERROR_INSUFFICIENT_BUFFER
			ERROR_INSUFFICIENT_BUFFER
#	else
			0x7A
#	endif
		// The data area passed to a system call is too small.

	, INVALID_NAME =
#	if defined ERROR_INVALID_NAME
			ERROR_INVALID_NAME
#	else
			0x7B
#	endif
		// The filename, directory name, or volume label syntax is incorrect.

	, INVALID_LEVEL =
#	if defined ERROR_INVALID_LEVEL
			ERROR_INVALID_LEVEL
#	else
			0x7C
#	endif
		// The system call level is not correct.

	, NO_VOLUME_LABEL =
#	if defined ERROR_NO_VOLUME_LABEL
			ERROR_NO_VOLUME_LABEL
#	else
			0x7D
#	endif
		// The disk has no volume label.

	, MOD_NOT_FOUND =
#	if defined ERROR_MOD_NOT_FOUND
			ERROR_MOD_NOT_FOUND
#	else
			0x7E
#	endif
		// The specified module could not be found.

	, PROC_NOT_FOUND =
#	if defined ERROR_PROC_NOT_FOUND
			ERROR_PROC_NOT_FOUND
#	else
			0x7F
#	endif
		// The specified procedure could not be found.

	, WAIT_NO_CHILDREN =
#	if defined ERROR_WAIT_NO_CHILDREN
			ERROR_WAIT_NO_CHILDREN
#	else
			0x80
#	endif
		// There are no child processes to wait for.

	, CHILD_NOT_COMPLETE =
#	if defined ERROR_CHILD_NOT_COMPLETE
			ERROR_CHILD_NOT_COMPLETE
#	else
			0x81
#	endif
		// The %1 application cannot be run in Win32 mode.

	, DIRECT_ACCESS_HANDLE =
#	if defined ERROR_DIRECT_ACCESS_HANDLE
			ERROR_DIRECT_ACCESS_HANDLE
#	else
			0x82
#	endif
		// Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.

	, NEGATIVE_SEEK =
#	if defined ERROR_NEGATIVE_SEEK
			ERROR_NEGATIVE_SEEK
#	else
			0x83
#	endif
		// An attempt was made to move the file pointer before the beginning of the file.

	, SEEK_ON_DEVICE =
#	if defined ERROR_SEEK_ON_DEVICE
			ERROR_SEEK_ON_DEVICE
#	else
			0x84
#	endif
		// The file pointer cannot be set on the specified device or file.

	, IS_JOIN_TARGET =
#	if defined ERROR_IS_JOIN_TARGET
			ERROR_IS_JOIN_TARGET
#	else
			0x85
#	endif
		// A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.

	, IS_JOINED =
#	if defined ERROR_IS_JOINED
			ERROR_IS_JOINED
#	else
			0x86
#	endif
		// An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.

	, IS_SUBSTED =
#	if defined ERROR_IS_SUBSTED
			ERROR_IS_SUBSTED
#	else
			0x87
#	endif
		// An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.

	, NOT_JOINED =
#	if defined ERROR_NOT_JOINED
			ERROR_NOT_JOINED
#	else
			0x88
#	endif
		// The system tried to delete the JOIN of a drive that is not joined.

	, NOT_SUBSTED =
#	if defined ERROR_NOT_SUBSTED
			ERROR_NOT_SUBSTED
#	else
			0x89
#	endif
		// The system tried to delete the substitution of a drive that is not substituted.

	, JOIN_TO_JOIN =
#	if defined ERROR_JOIN_TO_JOIN
			ERROR_JOIN_TO_JOIN
#	else
			0x8A
#	endif
		// The system tried to join a drive to a directory on a joined drive.

	, SUBST_TO_SUBST =
#	if defined ERROR_SUBST_TO_SUBST
			ERROR_SUBST_TO_SUBST
#	else
			0x8B
#	endif
		// The system tried to substitute a drive to a directory on a substituted drive.

	, JOIN_TO_SUBST =
#	if defined ERROR_JOIN_TO_SUBST
			ERROR_JOIN_TO_SUBST
#	else
			0x8C
#	endif
		// The system tried to join a drive to a directory on a substituted drive.

	, SUBST_TO_JOIN =
#	if defined ERROR_SUBST_TO_JOIN
			ERROR_SUBST_TO_JOIN
#	else
			0x8D
#	endif
		// The system tried to SUBST a drive to a directory on a joined drive.

	, BUSY_DRIVE =
#	if defined ERROR_BUSY_DRIVE
			ERROR_BUSY_DRIVE
#	else
			0x8E
#	endif
		// The system cannot perform a JOIN or SUBST at this time.

	, SAME_DRIVE =
#	if defined ERROR_SAME_DRIVE
			ERROR_SAME_DRIVE
#	else
			0x8F
#	endif
		// The system cannot join or substitute a drive to or for a directory on the same drive.

	, DIR_NOT_ROOT =
#	if defined ERROR_DIR_NOT_ROOT
			ERROR_DIR_NOT_ROOT
#	else
			0x90
#	endif
		// The directory is not a subdirectory of the root directory.

	, DIR_NOT_EMPTY =
#	if defined ERROR_DIR_NOT_EMPTY
			ERROR_DIR_NOT_EMPTY
#	else
			0x91
#	endif
		// The directory is not empty.

	, IS_SUBST_PATH =
#	if defined ERROR_IS_SUBST_PATH
			ERROR_IS_SUBST_PATH
#	else
			0x92
#	endif
		// The path specified is being used in a substitute.

	, IS_JOIN_PATH =
#	if defined ERROR_IS_JOIN_PATH
			ERROR_IS_JOIN_PATH
#	else
			0x93
#	endif
		// Not enough resources are available to process this command.

	, PATH_BUSY =
#	if defined ERROR_PATH_BUSY
			ERROR_PATH_BUSY
#	else
			0x94
#	endif
		// The path specified cannot be used at this time.

	, IS_SUBST_TARGET =
#	if defined ERROR_IS_SUBST_TARGET
			ERROR_IS_SUBST_TARGET
#	else
			0x95
#	endif
		// An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.

	, SYSTEM_TRACE =
#	if defined ERROR_SYSTEM_TRACE
			ERROR_SYSTEM_TRACE
#	else
			0x96
#	endif
		// System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.

	, INVALID_EVENT_COUNT =
#	if defined ERROR_INVALID_EVENT_COUNT
			ERROR_INVALID_EVENT_COUNT
#	else
			0x97
#	endif
		// The number of specified semaphore events for DosMuxSemWait is not correct.

	, TOO_MANY_MUXWAITERS =
#	if defined ERROR_TOO_MANY_MUXWAITERS
			ERROR_TOO_MANY_MUXWAITERS
#	else
			0x98
#	endif
		// DosMuxSemWait did not execute; too many semaphores are already set.

	, INVALID_LIST_FORMAT =
#	if defined ERROR_INVALID_LIST_FORMAT
			ERROR_INVALID_LIST_FORMAT
#	else
			0x99
#	endif
		// The DosMuxSemWait list is not correct.

	, LABEL_TOO_LONG =
#	if defined ERROR_LABEL_TOO_LONG
			ERROR_LABEL_TOO_LONG
#	else
			0x9A
#	endif
		// The volume label you entered exceeds the label character limit of the target file system.

	, TOO_MANY_TCBS =
#	if defined ERROR_TOO_MANY_TCBS
			ERROR_TOO_MANY_TCBS
#	else
			0x9B
#	endif
		// Cannot create another thread.

	, SIGNAL_REFUSED =
#	if defined ERROR_SIGNAL_REFUSED
			ERROR_SIGNAL_REFUSED
#	else
			0x9C
#	endif
		// The recipient process has refused the signal.

	, DISCARDED =
#	if defined ERROR_DISCARDED
			ERROR_DISCARDED
#	else
			0x9D
#	endif
		// The segment is already discarded and cannot be locked.

	, NOT_LOCKED =
#	if defined ERROR_NOT_LOCKED
			ERROR_NOT_LOCKED
#	else
			0x9E
#	endif
		// The segment is already unlocked.

	, BAD_THREADID_ADDR =
#	if defined ERROR_BAD_THREADID_ADDR
			ERROR_BAD_THREADID_ADDR
#	else
			0x9F
#	endif
		// The address for the thread ID is not correct.

	, BAD_ARGUMENTS =
#	if defined ERROR_BAD_ARGUMENTS
			ERROR_BAD_ARGUMENTS
#	else
			0xA0
#	endif
		// One or more arguments are not correct.

	, BAD_PATHNAME =
#	if defined ERROR_BAD_PATHNAME
			ERROR_BAD_PATHNAME
#	else
			0xA1
#	endif
		// The specified path is invalid.

	, SIGNAL_PENDING =
#	if defined ERROR_SIGNAL_PENDING
			ERROR_SIGNAL_PENDING
#	else
			0xA2
#	endif
		// A signal is already pending.

	, MAX_THRDS_REACHED =
#	if defined ERROR_MAX_THRDS_REACHED
			ERROR_MAX_THRDS_REACHED
#	else
			0xA4
#	endif
		// No more threads can be created in the system.

	, LOCK_FAILED =
#	if defined ERROR_LOCK_FAILED
			ERROR_LOCK_FAILED
#	else
			0xA7
#	endif
		// Unable to lock a region of a file.

	, BUSY =
#	if defined ERROR_BUSY
			ERROR_BUSY
#	else
			0xAA
#	endif
		// The requested resource is in use.

	, DEVICE_SUPPORT_IN_PROGRESS =
#	if defined ERROR_DEVICE_SUPPORT_IN_PROGRESS
			ERROR_DEVICE_SUPPORT_IN_PROGRESS
#	else
			0xAB
#	endif
		// Device's command support detection is in progress.

	, CANCEL_VIOLATION =
#	if defined ERROR_CANCEL_VIOLATION
			ERROR_CANCEL_VIOLATION
#	else
			0xAD
#	endif
		// A lock request was not outstanding for the supplied cancel region.

	, ATOMIC_LOCKS_NOT_SUPPORTED =
#	if defined ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
			ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
#	else
			0xAE
#	endif
		// The file system does not support atomic changes to the lock type.

	, INVALID_SEGMENT_NUMBER =
#	if defined ERROR_INVALID_SEGMENT_NUMBER
			ERROR_INVALID_SEGMENT_NUMBER
#	else
			0xB4
#	endif
		// The system detected a segment number that was not correct.

	, INVALID_ORDINAL =
#	if defined ERROR_INVALID_ORDINAL
			ERROR_INVALID_ORDINAL
#	else
			0xB6
#	endif
		// The operating system cannot run %1.

	, ALREADY_EXISTS =
#	if defined ERROR_ALREADY_EXISTS
			ERROR_ALREADY_EXISTS
#	else
			0xB7
#	endif
		// Cannot create a file when that file already exists.

	, INVALID_FLAG_NUMBER =
#	if defined ERROR_INVALID_FLAG_NUMBER
			ERROR_INVALID_FLAG_NUMBER
#	else
			0xBA
#	endif
		// The flag passed is not correct.

	, SEM_NOT_FOUND =
#	if defined ERROR_SEM_NOT_FOUND
			ERROR_SEM_NOT_FOUND
#	else
			0xBB
#	endif
		// The specified system semaphore name was not found.

	, INVALID_STARTING_CODESEG =
#	if defined ERROR_INVALID_STARTING_CODESEG
			ERROR_INVALID_STARTING_CODESEG
#	else
			0xBC
#	endif
		// The operating system cannot run %1.

	, INVALID_STACKSEG =
#	if defined ERROR_INVALID_STACKSEG
			ERROR_INVALID_STACKSEG
#	else
			0xBD
#	endif
		// The operating system cannot run %1.

	, INVALID_MODULETYPE =
#	if defined ERROR_INVALID_MODULETYPE
			ERROR_INVALID_MODULETYPE
#	else
			0xBE
#	endif
		// The operating system cannot run %1.

	, INVALID_EXE_SIGNATURE =
#	if defined ERROR_INVALID_EXE_SIGNATURE
			ERROR_INVALID_EXE_SIGNATURE
#	else
			0xBF
#	endif
		// Cannot run %1 in Win32 mode.

	, EXE_MARKED_INVALID =
#	if defined ERROR_EXE_MARKED_INVALID
			ERROR_EXE_MARKED_INVALID
#	else
			0xC0
#	endif
		// The operating system cannot run %1.

	, BAD_EXE_FORMAT =
#	if defined ERROR_BAD_EXE_FORMAT
			ERROR_BAD_EXE_FORMAT
#	else
			0xC1
#	endif
		// %1 is not a valid Win32 application.

	, ITERATED_DATA_EXCEEDS_64k =
#	if defined ERROR_ITERATED_DATA_EXCEEDS_64k
			ERROR_ITERATED_DATA_EXCEEDS_64k
#	else
			0xC2
#	endif
		// The operating system cannot run %1.

	, INVALID_MINALLOCSIZE =
#	if defined ERROR_INVALID_MINALLOCSIZE
			ERROR_INVALID_MINALLOCSIZE
#	else
			0xC3
#	endif
		// The operating system cannot run %1.

	, DYNLINK_FROM_INVALID_RING =
#	if defined ERROR_DYNLINK_FROM_INVALID_RING
			ERROR_DYNLINK_FROM_INVALID_RING
#	else
			0xC4
#	endif
		// The operating system cannot run this application program.

	, IOPL_NOT_ENABLED =
#	if defined ERROR_IOPL_NOT_ENABLED
			ERROR_IOPL_NOT_ENABLED
#	else
			0xC5
#	endif
		// The operating system is not presently configured to run this application.

	, INVALID_SEGDPL =
#	if defined ERROR_INVALID_SEGDPL
			ERROR_INVALID_SEGDPL
#	else
			0xC6
#	endif
		// The operating system cannot run %1.

	, AUTODATASEG_EXCEEDS_64k =
#	if defined ERROR_AUTODATASEG_EXCEEDS_64k
			ERROR_AUTODATASEG_EXCEEDS_64k
#	else
			0xC7
#	endif
		// The operating system cannot run this application program.

	, RING2SEG_MUST_BE_MOVABLE =
#	if defined ERROR_RING2SEG_MUST_BE_MOVABLE
			ERROR_RING2SEG_MUST_BE_MOVABLE
#	else
			0xC8
#	endif
		// The code segment cannot be greater than or equal to 64K.

	, RELOC_CHAIN_XEEDS_SEGLIM =
#	if defined ERROR_RELOC_CHAIN_XEEDS_SEGLIM
			ERROR_RELOC_CHAIN_XEEDS_SEGLIM
#	else
			0xC9
#	endif
		// The operating system cannot run %1.

	, INFLOOP_IN_RELOC_CHAIN =
#	if defined ERROR_INFLOOP_IN_RELOC_CHAIN
			ERROR_INFLOOP_IN_RELOC_CHAIN
#	else
			0xCA
#	endif
		// The operating system cannot run %1.

	, ENVVAR_NOT_FOUND =
#	if defined ERROR_ENVVAR_NOT_FOUND
			ERROR_ENVVAR_NOT_FOUND
#	else
			0xCB
#	endif
		// The system could not find the environment option that was entered.

	, NO_SIGNAL_SENT =
#	if defined ERROR_NO_SIGNAL_SENT
			ERROR_NO_SIGNAL_SENT
#	else
			0xCD
#	endif
		// No process in the command subtree has a signal handler.

	, FILENAME_EXCED_RANGE =
#	if defined ERROR_FILENAME_EXCED_RANGE
			ERROR_FILENAME_EXCED_RANGE
#	else
			0xCE
#	endif
		// The filename or extension is too long.

	, RING2_STACK_IN_USE =
#	if defined ERROR_RING2_STACK_IN_USE
			ERROR_RING2_STACK_IN_USE
#	else
			0xCF
#	endif
		// The ring 2 stack is in use.

	, META_EXPANSION_TOO_LONG =
#	if defined ERROR_META_EXPANSION_TOO_LONG
			ERROR_META_EXPANSION_TOO_LONG
#	else
			0xD0
#	endif
		// The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.

	, INVALID_SIGNAL_NUMBER =
#	if defined ERROR_INVALID_SIGNAL_NUMBER
			ERROR_INVALID_SIGNAL_NUMBER
#	else
			0xD1
#	endif
		// The signal being posted is not correct.

	, THREAD_1_INACTIVE =
#	if defined ERROR_THREAD_1_INACTIVE
			ERROR_THREAD_1_INACTIVE
#	else
			0xD2
#	endif
		// The signal handler cannot be set.

	, LOCKED =
#	if defined ERROR_LOCKED
			ERROR_LOCKED
#	else
			0xD4
#	endif
		// The segment is locked and cannot be reallocated.

	, TOO_MANY_MODULES =
#	if defined ERROR_TOO_MANY_MODULES
			ERROR_TOO_MANY_MODULES
#	else
			0xD6
#	endif
		// Too many dynamic-link modules are attached to this program or dynamic-link module.

	, NESTING_NOT_ALLOWED =
#	if defined ERROR_NESTING_NOT_ALLOWED
			ERROR_NESTING_NOT_ALLOWED
#	else
			0xD7
#	endif
		// Cannot nest calls to LoadModule.

	, EXE_MACHINE_TYPE_MISMATCH =
#	if defined ERROR_EXE_MACHINE_TYPE_MISMATCH
			ERROR_EXE_MACHINE_TYPE_MISMATCH
#	else
			0xD8
#	endif
		// This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.

	, EXE_CANNOT_MODIFY_SIGNED_BINARY =
#	if defined ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
			ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
#	else
			0xD9
#	endif
		// The image file %1 is signed, unable to modify.

	, EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY =
#	if defined ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
			ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
#	else
			0xDA
#	endif
		// The image file %1 is strong signed, unable to modify.

	, FILE_CHECKED_OUT =
#	if defined ERROR_FILE_CHECKED_OUT
			ERROR_FILE_CHECKED_OUT
#	else
			0xDC
#	endif
		// This file is checked out or locked for editing by another user.

	, CHECKOUT_REQUIRED =
#	if defined ERROR_CHECKOUT_REQUIRED
			ERROR_CHECKOUT_REQUIRED
#	else
			0xDD
#	endif
		// The file must be checked out before saving changes.

	, BAD_FILE_TYPE =
#	if defined ERROR_BAD_FILE_TYPE
			ERROR_BAD_FILE_TYPE
#	else
			0xDE
#	endif
		// The file type being saved or retrieved has been blocked.

	, FILE_TOO_LARGE =
#	if defined ERROR_FILE_TOO_LARGE
			ERROR_FILE_TOO_LARGE
#	else
			0xDF
#	endif
		// The file size exceeds the limit allowed and cannot be saved.

	, FORMS_AUTH_REQUIRED =
#	if defined ERROR_FORMS_AUTH_REQUIRED
			ERROR_FORMS_AUTH_REQUIRED
#	else
			0xE0
#	endif
		// Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.

	, VIRUS_INFECTED =
#	if defined ERROR_VIRUS_INFECTED
			ERROR_VIRUS_INFECTED
#	else
			0xE1
#	endif
		// Operation did not complete successfully because the file contains a virus or potentially unwanted software.

	, VIRUS_DELETED =
#	if defined ERROR_VIRUS_DELETED
			ERROR_VIRUS_DELETED
#	else
			0xE2
#	endif
		// This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.

	, PIPE_LOCAL =
#	if defined ERROR_PIPE_LOCAL
			ERROR_PIPE_LOCAL
#	else
			0xE5
#	endif
		// The pipe is local.

	, BAD_PIPE =
#	if defined ERROR_BAD_PIPE
			ERROR_BAD_PIPE
#	else
			0xE6
#	endif
		// The pipe state is invalid.

	, PIPE_BUSY =
#	if defined ERROR_PIPE_BUSY
			ERROR_PIPE_BUSY
#	else
			0xE7
#	endif
		// All pipe instances are busy.

	, PIPE_NO_DATA =
#	if defined ERROR_NO_DATA
			ERROR_NO_DATA
#	else
			0xE8
#	endif
		// The pipe is being closed.

	, PIPE_NOT_CONNECTED =
#	if defined ERROR_PIPE_NOT_CONNECTED
			ERROR_PIPE_NOT_CONNECTED
#	else
			0xE9
#	endif
		// No process is on the other end of the pipe.

	, MORE_DATA =
#	if defined ERROR_MORE_DATA
			ERROR_MORE_DATA
#	else
			0xEA
#	endif
		// More data is available.

	, VC_DISCONNECTED =
#	if defined ERROR_VC_DISCONNECTED
			ERROR_VC_DISCONNECTED
#	else
			0xF0
#	endif
		// The session was canceled.

	, INVALID_EA_NAME =
#	if defined ERROR_INVALID_EA_NAME
			ERROR_INVALID_EA_NAME
#	else
			0xFE
#	endif
		// The specified extended attribute name was invalid.

	, EA_LIST_INCONSISTENT =
#	if defined ERROR_EA_LIST_INCONSISTENT
			ERROR_EA_LIST_INCONSISTENT
#	else
			0xFF
#	endif
		// The extended attributes are inconsistent.

	, TIMEOUT =
#	if defined WAIT_TIMEOUT
			WAIT_TIMEOUT
#	else
			0x102
#	endif
		// The wait operation timed out.

	, NO_MORE_ITEMS =
#	if defined ERROR_NO_MORE_ITEMS
			ERROR_NO_MORE_ITEMS
#	else
			0x103
#	endif
		// No more data is available.

	, CANNOT_COPY =
#	if defined ERROR_CANNOT_COPY
			ERROR_CANNOT_COPY
#	else
			0x10A
#	endif
		// The copy functions cannot be used.

	, DIRECTORY =
#	if defined ERROR_DIRECTORY
			ERROR_DIRECTORY
#	else
			0x10B
#	endif
		// The directory name is invalid.

	, EAS_DIDNT_FIT =
#	if defined ERROR_EAS_DIDNT_FIT
			ERROR_EAS_DIDNT_FIT
#	else
			0x113
#	endif
		// The extended attributes did not fit in the buffer.

	, EA_FILE_CORRUPT =
#	if defined ERROR_EA_FILE_CORRUPT
			ERROR_EA_FILE_CORRUPT
#	else
			0x114
#	endif
		// The extended attribute file on the mounted file system is corrupt.

	, EA_TABLE_FULL =
#	if defined ERROR_EA_TABLE_FULL
			ERROR_EA_TABLE_FULL
#	else
			0x115
#	endif
		// The extended attribute table file is full.

	, INVALID_EA_HANDLE =
#	if defined ERROR_INVALID_EA_HANDLE
			ERROR_INVALID_EA_HANDLE
#	else
			0x116
#	endif
		// The specified extended attribute handle is invalid.

	, EAS_NOT_SUPPORTED =
#	if defined ERROR_EAS_NOT_SUPPORTED
			ERROR_EAS_NOT_SUPPORTED
#	else
			0x11A
#	endif
		// The mounted file system does not support extended attributes.

	, NOT_OWNER =
#	if defined ERROR_NOT_OWNER
			ERROR_NOT_OWNER
#	else
			0x120
#	endif
		// Attempt to release mutex not owned by caller.

	, TOO_MANY_POSTS =
#	if defined ERROR_TOO_MANY_POSTS
			ERROR_TOO_MANY_POSTS
#	else
			0x12A
#	endif
		// Too many posts were made to a semaphore.

	, PARTIAL_COPY =
#	if defined ERROR_PARTIAL_COPY
			ERROR_PARTIAL_COPY
#	else
			0x12B
#	endif
		// Only part of a ReadProcessMemory or WriteProcessMemory request was completed.

	, OPLOCK_NOT_GRANTED =
#	if defined ERROR_OPLOCK_NOT_GRANTED
			ERROR_OPLOCK_NOT_GRANTED
#	else
			0x12C
#	endif
		// The oplock request is denied.

	, INVALID_OPLOCK_PROTOCOL =
#	if defined ERROR_INVALID_OPLOCK_PROTOCOL
			ERROR_INVALID_OPLOCK_PROTOCOL
#	else
			0x12D
#	endif
		// An invalid oplock acknowledgment was received by the system.

	, DISK_TOO_FRAGMENTED =
#	if defined ERROR_DISK_TOO_FRAGMENTED
			ERROR_DISK_TOO_FRAGMENTED
#	else
			0x12E
#	endif
		// The volume is too fragmented to complete this operation.

	, DELETE_PENDING =
#	if defined ERROR_DELETE_PENDING
			ERROR_DELETE_PENDING
#	else
			0x12F
#	endif
		// The file cannot be opened because it is in the process of being deleted.

	, INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING =
#	if defined ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING
			ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING
#	else
			0x130
#	endif
		// Short name settings may not be changed on this volume due to the global registry setting.

	, SHORT_NAMES_NOT_ENABLED_ON_VOLUME =
#	if defined ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME
			ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME
#	else
			0x131
#	endif
		// Short names are not enabled on this volume.

	, SECURITY_STREAM_IS_INCONSISTENT =
#	if defined ERROR_SECURITY_STREAM_IS_INCONSISTENT
			ERROR_SECURITY_STREAM_IS_INCONSISTENT
#	else
			0x132
#	endif
		// The security stream for the given volume is in an inconsistent state. Please run CHKDSK on the volume.

	, INVALID_LOCK_RANGE =
#	if defined ERROR_INVALID_LOCK_RANGE
			ERROR_INVALID_LOCK_RANGE
#	else
			0x133
#	endif
		// A requested file lock operation cannot be processed due to an invalid byte range.

	, IMAGE_SUBSYSTEM_NOT_PRESENT =
#	if defined ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT
			ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT
#	else
			0x134
#	endif
		// The subsystem needed to support the image type is not present.

	, NOTIFICATION_GUID_ALREADY_DEFINED =
#	if defined ERROR_NOTIFICATION_GUID_ALREADY_DEFINED
			ERROR_NOTIFICATION_GUID_ALREADY_DEFINED
#	else
			0x135
#	endif
		// The specified file already has a notification GUID associated with it.

	, INVALID_EXCEPTION_HANDLER =
#	if defined ERROR_INVALID_EXCEPTION_HANDLER
			ERROR_INVALID_EXCEPTION_HANDLER
#	else
			0x136
#	endif
		// An invalid exception handler routine has been detected.

	, DUPLICATE_PRIVILEGES =
#	if defined ERROR_DUPLICATE_PRIVILEGES
			ERROR_DUPLICATE_PRIVILEGES
#	else
			0x137
#	endif
		// Duplicate privileges were specified for the token.

	, NO_RANGES_PROCESSED =
#	if defined ERROR_NO_RANGES_PROCESSED
			ERROR_NO_RANGES_PROCESSED
#	else
			0x138
#	endif
		// No ranges for the specified operation were able to be processed.

	, NOT_ALLOWED_ON_SYSTEM_FILE =
#	if defined ERROR_NOT_ALLOWED_ON_SYSTEM_FILE
			ERROR_NOT_ALLOWED_ON_SYSTEM_FILE
#	else
			0x139
#	endif
		// Operation is not allowed on a file system internal file.

	, DISK_RESOURCES_EXHAUSTED =
#	if defined ERROR_DISK_RESOURCES_EXHAUSTED
			ERROR_DISK_RESOURCES_EXHAUSTED
#	else
			0x13A
#	endif
		// The physical resources of this disk have been exhausted.

	, INVALID_TOKEN =
#	if defined ERROR_INVALID_TOKEN
			ERROR_INVALID_TOKEN
#	else
			0x13B
#	endif
		// The token representing the data is invalid.

	, DEVICE_FEATURE_NOT_SUPPORTED =
#	if defined ERROR_DEVICE_FEATURE_NOT_SUPPORTED
			ERROR_DEVICE_FEATURE_NOT_SUPPORTED
#	else
			0x13C
#	endif
		// The device does not support the command feature.

	, MR_MID_NOT_FOUND =
#	if defined ERROR_MR_MID_NOT_FOUND
			ERROR_MR_MID_NOT_FOUND
#	else
			0x13D
#	endif
		// The system cannot find message text for message number 0x%1 in the message file for %2.

	, SCOPE_NOT_FOUND =
#	if defined ERROR_SCOPE_NOT_FOUND
			ERROR_SCOPE_NOT_FOUND
#	else
			0x13E
#	endif
		// The scope specified was not found.

	, UNDEFINED_SCOPE =
#	if defined ERROR_UNDEFINED_SCOPE
			ERROR_UNDEFINED_SCOPE
#	else
			0x13F
#	endif
		// The Central Access Policy specified is not defined on the target machine.

	, INVALID_CAP =
#	if defined ERROR_INVALID_CAP
			ERROR_INVALID_CAP
#	else
			0x140
#	endif
		// The Central Access Policy obtained from Active Directory is invalid.

	, DEVICE_UNREACHABLE =
#	if defined ERROR_DEVICE_UNREACHABLE
			ERROR_DEVICE_UNREACHABLE
#	else
			0x141
#	endif
		// The device is unreachable.

	, DEVICE_NO_RESOURCES =
#	if defined ERROR_DEVICE_NO_RESOURCES
			ERROR_DEVICE_NO_RESOURCES
#	else
			0x142
#	endif
		// The target device has insufficient resources to complete the operation.

	, DATA_CHECKSUM_ERROR =
#	if defined ERROR_DATA_CHECKSUM_ERROR
			ERROR_DATA_CHECKSUM_ERROR
#	else
			0x143
#	endif
		// A data integrity checksum error occurred. Data in the file stream is corrupt.

	, INTERMIXED_KERNEL_EA_OPERATION =
#	if defined ERROR_INTERMIXED_KERNEL_EA_OPERATION
			ERROR_INTERMIXED_KERNEL_EA_OPERATION
#	else
			0x144
#	endif
		// An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.

	, FILE_LEVEL_TRIM_NOT_SUPPORTED =
#	if defined ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED
			ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED
#	else
			0x146
#	endif
		// Device does not support file-level TRIM.

	, OFFSET_ALIGNMENT_VIOLATION =
#	if defined ERROR_OFFSET_ALIGNMENT_VIOLATION
			ERROR_OFFSET_ALIGNMENT_VIOLATION
#	else
			0x147
#	endif
		// The command specified a data offset that does not align to the device's granularity/alignment.

	, INVALID_FIELD_IN_PARAMETER_LIST =
#	if defined ERROR_INVALID_FIELD_IN_PARAMETER_LIST
			ERROR_INVALID_FIELD_IN_PARAMETER_LIST
#	else
			0x148
#	endif
		// The command specified an invalid field in its parameter list.

	, OPERATION_IN_PROGRESS =
#	if defined ERROR_OPERATION_IN_PROGRESS
			ERROR_OPERATION_IN_PROGRESS
#	else
			0x149
#	endif
		// An operation is currently in progress with the device.

	, BAD_DEVICE_PATH =
#	if defined ERROR_BAD_DEVICE_PATH
			ERROR_BAD_DEVICE_PATH
#	else
			0x14A
#	endif
		// An attempt was made to send down the command via an invalid path to the target device.

	, TOO_MANY_DESCRIPTORS =
#	if defined ERROR_TOO_MANY_DESCRIPTORS
			ERROR_TOO_MANY_DESCRIPTORS
#	else
			0x14B
#	endif
		// The command specified a number of descriptors that exceeded the maximum supported by the device.

	, SCRUB_DATA_DISABLED =
#	if defined ERROR_SCRUB_DATA_DISABLED
			ERROR_SCRUB_DATA_DISABLED
#	else
			0x14C
#	endif
		// Scrub is disabled on the specified file.

	, NOT_REDUNDANT_STORAGE =
#	if defined ERROR_NOT_REDUNDANT_STORAGE
			ERROR_NOT_REDUNDANT_STORAGE
#	else
			0x14D
#	endif
		// The storage device does not provide redundancy.

	, RESIDENT_FILE_NOT_SUPPORTED =
#	if defined ERROR_RESIDENT_FILE_NOT_SUPPORTED
			ERROR_RESIDENT_FILE_NOT_SUPPORTED
#	else
			0x14E
#	endif
		// An operation is not supported on a resident file.

	, COMPRESSED_FILE_NOT_SUPPORTED =
#	if defined ERROR_COMPRESSED_FILE_NOT_SUPPORTED
			ERROR_COMPRESSED_FILE_NOT_SUPPORTED
#	else
			0x14F
#	endif
		// An operation is not supported on a compressed file.

	, DIRECTORY_NOT_SUPPORTED =
#	if defined ERROR_DIRECTORY_NOT_SUPPORTED
			ERROR_DIRECTORY_NOT_SUPPORTED
#	else
			0x150
#	endif
		// An operation is not supported on a directory.

	, NOT_READ_FROM_COPY =
#	if defined ERROR_NOT_READ_FROM_COPY
			ERROR_NOT_READ_FROM_COPY
#	else
			0x151
#	endif
		// The specified copy of the requested data could not be read.

	, FAIL_NOACTION_REBOOT =
#	if defined ERROR_FAIL_NOACTION_REBOOT
			ERROR_FAIL_NOACTION_REBOOT
#	else
			0x15E
#	endif
		// No action was taken as a system reboot is required.

	, FAIL_SHUTDOWN =
#	if defined ERROR_FAIL_SHUTDOWN
			ERROR_FAIL_SHUTDOWN
#	else
			0x15F
#	endif
		// The shutdown operation failed.

	, FAIL_RESTART =
#	if defined ERROR_FAIL_RESTART
			ERROR_FAIL_RESTART
#	else
			0x160
#	endif
		// The restart operation failed.

	, MAX_SESSIONS_REACHED =
#	if defined ERROR_MAX_SESSIONS_REACHED
			ERROR_MAX_SESSIONS_REACHED
#	else
			0x161
#	endif
		// The maximum number of sessions has been reached.

	, THREAD_MODE_ALREADY_BACKGROUND =
#	if defined ERROR_THREAD_MODE_ALREADY_BACKGROUND
			ERROR_THREAD_MODE_ALREADY_BACKGROUND
#	else
			0x190
#	endif
		// The thread is already in background processing mode.

	, THREAD_MODE_NOT_BACKGROUND =
#	if defined ERROR_THREAD_MODE_NOT_BACKGROUND
			ERROR_THREAD_MODE_NOT_BACKGROUND
#	else
			0x191
#	endif
		// The thread is not in background processing mode.

	, PROCESS_MODE_ALREADY_BACKGROUND =
#	if defined ERROR_PROCESS_MODE_ALREADY_BACKGROUND
			ERROR_PROCESS_MODE_ALREADY_BACKGROUND
#	else
			0x192
#	endif
		// The process is already in background processing mode.

	, PROCESS_MODE_NOT_BACKGROUND =
#	if defined ERROR_PROCESS_MODE_NOT_BACKGROUND
			ERROR_PROCESS_MODE_NOT_BACKGROUND
#	else
			0x193
#	endif
		// The process is not in background processing mode.

	, INVALID_ADDRESS =
#	if defined ERROR_INVALID_ADDRESS
			ERROR_INVALID_ADDRESS
#	else
			0x1E7
#	endif
		// Attempt to access invalid address.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString0(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::SUCCESS:
			RETURN_STATIC_STRING(
					"The operation completed successfully"
			);
		case SystemCode::INVALID_FUNCTION:
			RETURN_STATIC_STRING(
					"Incorrect function"
			);
		case SystemCode::FILE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The system cannot find the file specified"
			);
		case SystemCode::PATH_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The system cannot find the path specified"
			);
		case SystemCode::TOO_MANY_OPEN_FILES:
			RETURN_STATIC_STRING(
					"The system cannot open the file"
			);
		case SystemCode::ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"Access is denied"
			);
		case SystemCode::INVALID_HANDLE:
			RETURN_STATIC_STRING(
					"The handle is invalid"
			);
		case SystemCode::ARENA_TRASHED:
			RETURN_STATIC_STRING(
					"The storage control blocks were destroyed"
			);
		case SystemCode::NOT_ENOUGH_MEMORY:
			RETURN_STATIC_STRING(
					"Not enough memory resources are available to process this command"
			);
		case SystemCode::INVALID_BLOCK:
			RETURN_STATIC_STRING(
					"The storage control block address is invalid"
			);
		case SystemCode::BAD_ENVIRONMENT:
			RETURN_STATIC_STRING(
					"The environment is incorrect"
			);
		case SystemCode::BAD_FORMAT:
			RETURN_STATIC_STRING(
					"An attempt was made to load a program with an incorrect format"
			);
		case SystemCode::INVALID_ACCESS:
			RETURN_STATIC_STRING(
					"The access code is invalid"
			);
		case SystemCode::INVALID_DATA:
			RETURN_STATIC_STRING(
					"The data is invalid"
			);
		case SystemCode::OUTOFMEMORY:
			RETURN_STATIC_STRING(
					"Not enough storage is available to complete this operation"
			);
		case SystemCode::INVALID_DRIVE:
			RETURN_STATIC_STRING(
					"The system cannot find the drive specified"
			);
		case SystemCode::CURRENT_DIRECTORY:
			RETURN_STATIC_STRING(
					"The directory cannot be removed"
			);
		case SystemCode::NOT_SAME_DEVICE:
			RETURN_STATIC_STRING(
					"The system cannot move the file to a different disk drive"
			);
		case SystemCode::NO_MORE_FILES:
			RETURN_STATIC_STRING(
					"There are no more files"
			);
		case SystemCode::WRITE_PROTECT:
			RETURN_STATIC_STRING(
					"The media is write protected"
			);
		case SystemCode::BAD_UNIT:
			RETURN_STATIC_STRING(
					"The system cannot find the device specified"
			);
		case SystemCode::NOT_READY:
			RETURN_STATIC_STRING(
					"The device is not ready"
			);
		case SystemCode::BAD_COMMAND:
			RETURN_STATIC_STRING(
					"The device does not recognize the command"
			);
		case SystemCode::CRC:
			RETURN_STATIC_STRING(
					"Data error (cyclic redundancy check)"
			);
		case SystemCode::BAD_LENGTH:
			RETURN_STATIC_STRING(
					"The program issued a command but the command length is incorrect"
			);
		case SystemCode::SEEK:
			RETURN_STATIC_STRING(
					"The drive cannot locate a specific area or track on the disk"
			);
		case SystemCode::NOT_DOS_DISK:
			RETURN_STATIC_STRING(
					"The specified disk or diskette cannot be accessed"
			);
		case SystemCode::SECTOR_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The drive cannot find the sector requested"
			);
		case SystemCode::OUT_OF_PAPER:
			RETURN_STATIC_STRING(
					"The printer is out of paper"
			);
		case SystemCode::WRITE_FAULT:
			RETURN_STATIC_STRING(
					"The system cannot write to the specified device"
			);
		case SystemCode::READ_FAULT:
			RETURN_STATIC_STRING(
					"The system cannot read from the specified device"
			);
		case SystemCode::GEN_FAILURE:
			RETURN_STATIC_STRING(
					"A device attached to the system is not functioning"
			);
		case SystemCode::SHARING_VIOLATION:
			RETURN_STATIC_STRING(
					"The process cannot access the file because it is being used by another process"
			);
		case SystemCode::LOCK_VIOLATION:
			RETURN_STATIC_STRING(
					"The process cannot access the file because another process has locked a"
					" portion of the file"
			);
		case SystemCode::WRONG_DISK:
			RETURN_STATIC_STRING(
					"The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into"
					"drive %1"
			);
		case SystemCode::SHARING_BUFFER_EXCEEDED:
			RETURN_STATIC_STRING(
					"Too many files opened for sharing"
			);
		case SystemCode::HANDLE_EOF:
			RETURN_STATIC_STRING(
					"Reached the end of the file"
			);
		case SystemCode::HANDLE_DISK_FULL:
			RETURN_STATIC_STRING(
					"The disk is full"
			);
		case SystemCode::NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The request is not supported"
			);
		case SystemCode::REM_NOT_LIST:
			RETURN_STATIC_STRING(
					"Windows cannot find the network path. Verify that the network path is correct"
					" and the destination computer is not busy or turned off. If Windows still"
					" cannot find the network path, contact your network administrator"
			);
		case SystemCode::DUP_NAME:
			RETURN_STATIC_STRING(
					"You were not connected because a duplicate name exists on the network. If"
					" joining a domain, go to System in Control Panel to change the computer name"
					" and try again. If joining a workgroup, choose another workgroup name"
			);
		case SystemCode::BAD_NETPATH:
			RETURN_STATIC_STRING(
					"The network path was not found"
			);
		case SystemCode::NETWORK_BUSY:
			RETURN_STATIC_STRING(
					"The network is busy"
			);
		case SystemCode::DEV_NOT_EXIST:
			RETURN_STATIC_STRING(
					"The specified network resource or device is no longer available"
			);
		case SystemCode::TOO_MANY_CMDS:
			RETURN_STATIC_STRING(
					"The network BIOS command limit has been reached"
			);
		case SystemCode::ADAP_HDW_ERR:
			RETURN_STATIC_STRING(
					"A network adapter hardware error occurred"
			);
		case SystemCode::BAD_NET_RESP:
			RETURN_STATIC_STRING(
					"The specified server cannot perform the requested operation"
			);
		case SystemCode::UNEXP_NET_ERR:
			RETURN_STATIC_STRING(
					"An unexpected network error occurred"
			);
		case SystemCode::BAD_REM_ADAP:
			RETURN_STATIC_STRING(
					"The remote adapter is not compatible"
			);
		case SystemCode::PRINTQ_FULL:
			RETURN_STATIC_STRING(
					"The printer queue is full"
			);
		case SystemCode::NO_SPOOL_SPACE:
			RETURN_STATIC_STRING(
					"Space to store the file waiting to be printed is not available on the server"
			);
		case SystemCode::PRINT_CANCELLED:
			RETURN_STATIC_STRING(
					"Your file waiting to be printed was deleted"
			);
		case SystemCode::NETNAME_DELETED:
			RETURN_STATIC_STRING(
					"The specified network name is no longer available"
			);
		case SystemCode::NETWORK_ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"Network access is denied"
			);
		case SystemCode::BAD_DEV_TYPE:
			RETURN_STATIC_STRING(
					"The network resource type is not correct"
			);
		case SystemCode::BAD_NET_NAME:
			RETURN_STATIC_STRING(
					"The network name cannot be found"
			);
		case SystemCode::TOO_MANY_NAMES:
			RETURN_STATIC_STRING(
					"The name limit for the local computer network adapter card was exceeded"
			);
		case SystemCode::TOO_MANY_SESS:
			RETURN_STATIC_STRING(
					"The network BIOS session limit was exceeded"
			);
		case SystemCode::SHARING_PAUSED:
			RETURN_STATIC_STRING(
					"The remote server has been paused or is in the process of being started"
			);
		case SystemCode::REQ_NOT_ACCEP:
			RETURN_STATIC_STRING(
					"No more connections can be made to this remote computer at this time because"
					" there are already as many connections as the computer can accept"
			);
		case SystemCode::REDIR_PAUSED:
			RETURN_STATIC_STRING(
					"The specified printer or disk device has been paused"
			);
		case SystemCode::FILE_EXISTS:
			RETURN_STATIC_STRING(
					"The file exists"
			);
		case SystemCode::CANNOT_MAKE:
			RETURN_STATIC_STRING(
					"The directory or file cannot be created"
			);
		case SystemCode::FAIL_I24:
			RETURN_STATIC_STRING(
					"Fail on INT 24"
			);
		case SystemCode::OUT_OF_STRUCTURES:
			RETURN_STATIC_STRING(
					"Storage to process this request is not available"
			);
		case SystemCode::ALREADY_ASSIGNED:
			RETURN_STATIC_STRING(
					"The local device name is already in use"
			);
		case SystemCode::INVALID_PASSWORD:
			RETURN_STATIC_STRING(
					"The specified network password is not correct"
			);
		case SystemCode::INVALID_PARAMETER:
			RETURN_STATIC_STRING(
					"The parameter is incorrect"
			);
		case SystemCode::NET_WRITE_FAULT:
			RETURN_STATIC_STRING(
					"A write fault occurred on the network"
			);
		case SystemCode::NO_PROC_SLOTS:
			RETURN_STATIC_STRING(
					"The system cannot start another process at this time"
			);
		case SystemCode::TOO_MANY_SEMAPHORES:
			RETURN_STATIC_STRING(
					"Cannot create another system semaphore"
			);
		case SystemCode::EXCL_SEM_ALREADY_OWNED:
			RETURN_STATIC_STRING(
					"The exclusive semaphore is owned by another process"
			);
		case SystemCode::SEM_IS_SET:
			RETURN_STATIC_STRING(
					"The semaphore is set and cannot be closed"
			);
		case SystemCode::TOO_MANY_SEM_REQUESTS:
			RETURN_STATIC_STRING(
					"The semaphore cannot be set again"
			);
		case SystemCode::INVALID_AT_INTERRUPT_TIME:
			RETURN_STATIC_STRING(
					"Cannot request exclusive semaphores at interrupt time"
			);
		case SystemCode::SEM_OWNER_DIED:
			RETURN_STATIC_STRING(
					"The previous ownership of this semaphore has ended"
			);
		case SystemCode::SEM_USER_LIMIT:
			RETURN_STATIC_STRING(
					"Insert the diskette for drive %1"
			);
		case SystemCode::DISK_CHANGE:
			RETURN_STATIC_STRING(
					"The program stopped because an alternate diskette was not inserted"
			);
		case SystemCode::DRIVE_LOCKED:
			RETURN_STATIC_STRING(
					"The disk is in use or locked by another process"
			);
		case SystemCode::BROKEN_PIPE:
			RETURN_STATIC_STRING(
					"The pipe has been ended"
			);
		case SystemCode::OPEN_FAILED:
			RETURN_STATIC_STRING(
					"The system cannot open the device or file specified"
			);
		case SystemCode::BUFFER_OVERFLOW:
			RETURN_STATIC_STRING(
					"The file name is too long"
			);
		case SystemCode::DISK_FULL:
			RETURN_STATIC_STRING(
					"There is not enough space on the disk"
			);
		case SystemCode::NO_MORE_SEARCH_HANDLES:
			RETURN_STATIC_STRING(
					"No more internal file identifiers available"
			);
		case SystemCode::INVALID_TARGET_HANDLE:
			RETURN_STATIC_STRING(
					"The target internal file identifier is incorrect"
			);
		case SystemCode::INVALID_CATEGORY:
			RETURN_STATIC_STRING(
					"The IOCTL call made by the application program is not correct"
			);
		case SystemCode::INVALID_VERIFY_SWITCH:
			RETURN_STATIC_STRING(
					"The verify-on-write switch parameter value is not correct"
			);
		case SystemCode::BAD_DRIVER_LEVEL:
			RETURN_STATIC_STRING(
					"The system does not support the command requested"
			);
		case SystemCode::CALL_NOT_IMPLEMENTED:
			RETURN_STATIC_STRING(
					"This function is not supported on this system"
			);
		case SystemCode::SEM_TIMEOUT:
			RETURN_STATIC_STRING(
					"The semaphore timeout period has expired"
			);
		case SystemCode::INSUFFICIENT_BUFFER:
			RETURN_STATIC_STRING(
					"The data area passed to a system call is too small"
			);
		case SystemCode::INVALID_NAME:
			RETURN_STATIC_STRING(
					"The filename, directory name, or volume label syntax is incorrect"
			);
		case SystemCode::INVALID_LEVEL:
			RETURN_STATIC_STRING(
					"The system call level is not correct"
			);
		case SystemCode::NO_VOLUME_LABEL:
			RETURN_STATIC_STRING(
					"The disk has no volume label"
			);
		case SystemCode::MOD_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified module could not be found"
			);
		case SystemCode::PROC_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified procedure could not be found"
			);
		case SystemCode::WAIT_NO_CHILDREN:
			RETURN_STATIC_STRING(
					"There are no child processes to wait for"
			);
		case SystemCode::CHILD_NOT_COMPLETE:
			RETURN_STATIC_STRING(
					"The %1 application cannot be run in Win32 mode"
			);
		case SystemCode::DIRECT_ACCESS_HANDLE:
			RETURN_STATIC_STRING(
					"Attempt to use a file handle to an open disk partition for an operation other"
					" than raw disk I/O"
			);
		case SystemCode::NEGATIVE_SEEK:
			RETURN_STATIC_STRING(
					"An attempt was made to move the file pointer before the beginning of the file"
			);
		case SystemCode::SEEK_ON_DEVICE:
			RETURN_STATIC_STRING(
					"The file pointer cannot be set on the specified device or file"
			);
		case SystemCode::IS_JOIN_TARGET:
			RETURN_STATIC_STRING(
					"A JOIN or SUBST command cannot be used for a drive that contains previously"
					" joined drives"
			);
		case SystemCode::IS_JOINED:
			RETURN_STATIC_STRING(
					"An attempt was made to use a JOIN or SUBST command on a drive that has already"
					" been joined"
			);
		case SystemCode::IS_SUBSTED:
			RETURN_STATIC_STRING(
					"An attempt was made to use a JOIN or SUBST command on a drive that has already"
					" been substituted"
			);
		case SystemCode::NOT_JOINED:
			RETURN_STATIC_STRING(
					"The system tried to delete the JOIN of a drive that is not joined"
			);
		case SystemCode::NOT_SUBSTED:
			RETURN_STATIC_STRING(
					"The system tried to delete the substitution of a drive that is not substituted"
			);
		case SystemCode::JOIN_TO_JOIN:
			RETURN_STATIC_STRING(
					"The system tried to join a drive to a directory on a joined drive"
			);
		case SystemCode::SUBST_TO_SUBST:
			RETURN_STATIC_STRING(
					"The system tried to substitute a drive to a directory on a substituted drive"
			);
		case SystemCode::JOIN_TO_SUBST:
			RETURN_STATIC_STRING(
					"The system tried to join a drive to a directory on a substituted drive"
			);
		case SystemCode::SUBST_TO_JOIN:
			RETURN_STATIC_STRING(
					"The system tried to SUBST a drive to a directory on a joined drive"
			);
		case SystemCode::BUSY_DRIVE:
			RETURN_STATIC_STRING(
					"The system cannot perform a JOIN or SUBST at this time"
			);
		case SystemCode::SAME_DRIVE:
			RETURN_STATIC_STRING(
					"The system cannot join or substitute a drive to or for a directory on the same"
					" drive"
			);
		case SystemCode::DIR_NOT_ROOT:
			RETURN_STATIC_STRING(
					"The directory is not a subdirectory of the root directory"
			);
		case SystemCode::DIR_NOT_EMPTY:
			RETURN_STATIC_STRING(
					"The directory is not empty"
			);
		case SystemCode::IS_SUBST_PATH:
			RETURN_STATIC_STRING(
					"The path specified is being used in a substitute"
			);
		case SystemCode::IS_JOIN_PATH:
			RETURN_STATIC_STRING(
					"Not enough resources are available to process this command"
			);
		case SystemCode::PATH_BUSY:
			RETURN_STATIC_STRING(
					"The path specified cannot be used at this time"
			);
		case SystemCode::IS_SUBST_TARGET:
			RETURN_STATIC_STRING(
					"An attempt was made to join or substitute a drive for which a directory on the"
					" drive is the target of a previous substitute"
			);
		case SystemCode::SYSTEM_TRACE:
			RETURN_STATIC_STRING(
					"System trace information was not specified in your CONFIG.SYS file, or tracing"
					" is disallowed"
			);
		case SystemCode::INVALID_EVENT_COUNT:
			RETURN_STATIC_STRING(
					"The number of specified semaphore events for DosMuxSemWait is not correct"
			);
		case SystemCode::TOO_MANY_MUXWAITERS:
			RETURN_STATIC_STRING(
					"DosMuxSemWait did not execute; too many semaphores are already set"
			);
		case SystemCode::INVALID_LIST_FORMAT:
			RETURN_STATIC_STRING(
					"The DosMuxSemWait list is not correct"
			);
		case SystemCode::LABEL_TOO_LONG:
			RETURN_STATIC_STRING(
					"The volume label you entered exceeds the label character limit of the target"
					" file system"
			);
		case SystemCode::TOO_MANY_TCBS:
			RETURN_STATIC_STRING(
					"Cannot create another thread"
			);
		case SystemCode::SIGNAL_REFUSED:
			RETURN_STATIC_STRING(
					"The recipient process has refused the signal"
			);
		case SystemCode::DISCARDED:
			RETURN_STATIC_STRING(
					"The segment is already discarded and cannot be locked"
			);
		case SystemCode::NOT_LOCKED:
			RETURN_STATIC_STRING(
					"The segment is already unlocked"
			);
		case SystemCode::BAD_THREADID_ADDR:
			RETURN_STATIC_STRING(
					"The address for the thread ID is not correct"
			);
		case SystemCode::BAD_ARGUMENTS:
			RETURN_STATIC_STRING(
					"One or more arguments are not correct"
			);
		case SystemCode::BAD_PATHNAME:
			RETURN_STATIC_STRING(
					"The specified path is invalid"
			);
		case SystemCode::SIGNAL_PENDING:
			RETURN_STATIC_STRING(
					"A signal is already pending"
			);
		case SystemCode::MAX_THRDS_REACHED:
			RETURN_STATIC_STRING(
					"No more threads can be created in the system"
			);
		case SystemCode::LOCK_FAILED:
			RETURN_STATIC_STRING(
					"Unable to lock a region of a file"
			);
		case SystemCode::BUSY:
			RETURN_STATIC_STRING(
					"The requested resource is in use"
			);
		case SystemCode::DEVICE_SUPPORT_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Device's command support detection is in progress"
			);
		case SystemCode::CANCEL_VIOLATION:
			RETURN_STATIC_STRING(
					"A lock request was not outstanding for the supplied cancel region"
			);
		case SystemCode::ATOMIC_LOCKS_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The file system does not support atomic changes to the lock type"
			);
		case SystemCode::INVALID_SEGMENT_NUMBER:
			RETURN_STATIC_STRING(
					"The system detected a segment number that was not correct"
			);
		case SystemCode::INVALID_ORDINAL:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"Cannot create a file when that file already exists"
			);
		case SystemCode::INVALID_FLAG_NUMBER:
			RETURN_STATIC_STRING(
					"The flag passed is not correct"
			);
		case SystemCode::SEM_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified system semaphore name was not found"
			);
		case SystemCode::INVALID_STARTING_CODESEG:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::INVALID_STACKSEG:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::INVALID_MODULETYPE:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::INVALID_EXE_SIGNATURE:
			RETURN_STATIC_STRING(
					"Cannot run %1 in Win32 mode"
			);
		case SystemCode::EXE_MARKED_INVALID:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::BAD_EXE_FORMAT:
			RETURN_STATIC_STRING(
					"%1 is not a valid Win32 application"
			);
		case SystemCode::ITERATED_DATA_EXCEEDS_64k:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::INVALID_MINALLOCSIZE:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::DYNLINK_FROM_INVALID_RING:
			RETURN_STATIC_STRING(
					"The operating system cannot run this application program"
			);
		case SystemCode::IOPL_NOT_ENABLED:
			RETURN_STATIC_STRING(
					"The operating system is not presently configured to run this application"
			);
		case SystemCode::INVALID_SEGDPL:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::AUTODATASEG_EXCEEDS_64k:
			RETURN_STATIC_STRING(
					"The operating system cannot run this application program"
			);
		case SystemCode::RING2SEG_MUST_BE_MOVABLE:
			RETURN_STATIC_STRING(
					"The code segment cannot be greater than or equal to 64K"
			);
		case SystemCode::RELOC_CHAIN_XEEDS_SEGLIM:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::INFLOOP_IN_RELOC_CHAIN:
			RETURN_STATIC_STRING(
					"The operating system cannot run %1"
			);
		case SystemCode::ENVVAR_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The system could not find the environment option that was entered"
			);
		case SystemCode::NO_SIGNAL_SENT:
			RETURN_STATIC_STRING(
					"No process in the command subtree has a signal handler"
			);
		case SystemCode::FILENAME_EXCED_RANGE:
			RETURN_STATIC_STRING(
					"The filename or extension is too long"
			);
		case SystemCode::RING2_STACK_IN_USE:
			RETURN_STATIC_STRING(
					"The ring 2 stack is in use"
			);
		case SystemCode::META_EXPANSION_TOO_LONG:
			RETURN_STATIC_STRING(
					"The global filename characters, * or ?, are entered incorrectly or too many"
					" global filename characters are specified"
			);
		case SystemCode::INVALID_SIGNAL_NUMBER:
			RETURN_STATIC_STRING(
					"The signal being posted is not correct"
			);
		case SystemCode::THREAD_1_INACTIVE:
			RETURN_STATIC_STRING(
					"The signal handler cannot be set"
			);
		case SystemCode::LOCKED:
			RETURN_STATIC_STRING(
					"The segment is locked and cannot be reallocated"
			);
		case SystemCode::TOO_MANY_MODULES:
			RETURN_STATIC_STRING(
					"Too many dynamic-link modules are attached to this program or dynamic-link"
					" module"
			);
		case SystemCode::NESTING_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"Cannot nest calls to LoadModule"
			);
		case SystemCode::EXE_MACHINE_TYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"This version of %1 is not compatible with the version of Windows you're"
					" running. Check your computer's system information and then contact the"
					" software publisher"
			);
		case SystemCode::EXE_CANNOT_MODIFY_SIGNED_BINARY:
			RETURN_STATIC_STRING(
					"The image file %1 is signed, unable to modify"
			);
		case SystemCode::EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY:
			RETURN_STATIC_STRING(
					"The image file %1 is strong signed, unable to modify"
			);
		case SystemCode::FILE_CHECKED_OUT:
			RETURN_STATIC_STRING(
					"This file is checked out or locked for editing by another user"
			);
		case SystemCode::CHECKOUT_REQUIRED:
			RETURN_STATIC_STRING(
					"The file must be checked out before saving changes"
			);
		case SystemCode::BAD_FILE_TYPE:
			RETURN_STATIC_STRING(
					"The file type being saved or retrieved has been blocked"
			);
		case SystemCode::FILE_TOO_LARGE:
			RETURN_STATIC_STRING(
					"The file size exceeds the limit allowed and cannot be saved"
			);
		case SystemCode::FORMS_AUTH_REQUIRED:
			RETURN_STATIC_STRING(
					"Access Denied. Before opening files in this location, you must first add the"
					" web site to your trusted sites list, browse to the web site, and select the"
					" option to login automatically"
			);
		case SystemCode::VIRUS_INFECTED:
			RETURN_STATIC_STRING(
					"Operation did not complete successfully because the file contains a virus or"
					" potentially unwanted software"
			);
		case SystemCode::VIRUS_DELETED:
			RETURN_STATIC_STRING(
					"This file contains a virus or potentially unwanted software and cannot be"
					" opened. Due to the nature of this virus or potentially unwanted software, the"
					" file has been removed from this location"
			);
		case SystemCode::PIPE_LOCAL:
			RETURN_STATIC_STRING(
					"The pipe is local"
			);
		case SystemCode::BAD_PIPE:
			RETURN_STATIC_STRING(
					"The pipe state is invalid"
			);
		case SystemCode::PIPE_BUSY:
			RETURN_STATIC_STRING(
					"All pipe instances are busy"
			);
		case SystemCode::PIPE_NO_DATA:
			RETURN_STATIC_STRING(
					"The pipe is being closed"
			);
		case SystemCode::PIPE_NOT_CONNECTED:
			RETURN_STATIC_STRING(
					"No process is on the other end of the pipe"
			);
		case SystemCode::MORE_DATA:
			RETURN_STATIC_STRING(
					"More data is available"
			);
		case SystemCode::VC_DISCONNECTED:
			RETURN_STATIC_STRING(
					"The session was canceled"
			);
		case SystemCode::INVALID_EA_NAME:
			RETURN_STATIC_STRING(
					"The specified extended attribute name was invalid"
			);
		case SystemCode::EA_LIST_INCONSISTENT:
			RETURN_STATIC_STRING(
					"The extended attributes are inconsistent"
			);
		case SystemCode::TIMEOUT:
			RETURN_STATIC_STRING(
					"The wait operation timed out"
			);
		case SystemCode::NO_MORE_ITEMS:
			RETURN_STATIC_STRING(
					"No more data is available"
			);
		case SystemCode::CANNOT_COPY:
			RETURN_STATIC_STRING(
					"The copy functions cannot be used"
			);
		case SystemCode::DIRECTORY:
			RETURN_STATIC_STRING(
					"The directory name is invalid"
			);
		case SystemCode::EAS_DIDNT_FIT:
			RETURN_STATIC_STRING(
					"The extended attributes did not fit in the buffer"
			);
		case SystemCode::EA_FILE_CORRUPT:
			RETURN_STATIC_STRING(
					"The extended attribute file on the mounted file system is corrupt"
			);
		case SystemCode::EA_TABLE_FULL:
			RETURN_STATIC_STRING(
					"The extended attribute table file is full"
			);
		case SystemCode::INVALID_EA_HANDLE:
			RETURN_STATIC_STRING(
					"The specified extended attribute handle is invalid"
			);
		case SystemCode::EAS_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The mounted file system does not support extended attributes"
			);
		case SystemCode::NOT_OWNER:
			RETURN_STATIC_STRING(
					"Attempt to release mutex not owned by caller"
			);
		case SystemCode::TOO_MANY_POSTS:
			RETURN_STATIC_STRING(
					"Too many posts were made to a semaphore"
			);
		case SystemCode::PARTIAL_COPY:
			RETURN_STATIC_STRING(
					"Only part of a ReadProcessMemory or WriteProcessMemory request was completed"
			);
		case SystemCode::OPLOCK_NOT_GRANTED:
			RETURN_STATIC_STRING(
					"The oplock request is denied"
			);
		case SystemCode::INVALID_OPLOCK_PROTOCOL:
			RETURN_STATIC_STRING(
					"An invalid oplock acknowledgment was received by the system"
			);
		case SystemCode::DISK_TOO_FRAGMENTED:
			RETURN_STATIC_STRING(
					"The volume is too fragmented to complete this operation"
			);
		case SystemCode::DELETE_PENDING:
			RETURN_STATIC_STRING(
					"The file cannot be opened because it is in the process of being deleted"
			);
		case SystemCode::INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING:
			RETURN_STATIC_STRING(
					"Short name settings may not be changed on this volume due to the global"
					" registry setting"
			);
		case SystemCode::SHORT_NAMES_NOT_ENABLED_ON_VOLUME:
			RETURN_STATIC_STRING(
					"Short names are not enabled on this volume"
			);
		case SystemCode::SECURITY_STREAM_IS_INCONSISTENT:
			RETURN_STATIC_STRING(
					"The security stream for the given volume is in an inconsistent state. Please"
					" run CHKDSK on the volume"
			);
		case SystemCode::INVALID_LOCK_RANGE:
			RETURN_STATIC_STRING(
					"A requested file lock operation cannot be processed due to an invalid byte"
					" range"
			);
		case SystemCode::IMAGE_SUBSYSTEM_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"The subsystem needed to support the image type is not present"
			);
		case SystemCode::NOTIFICATION_GUID_ALREADY_DEFINED:
			RETURN_STATIC_STRING(
					"The specified file already has a notification GUID associated with it"
			);
		case SystemCode::INVALID_EXCEPTION_HANDLER:
			RETURN_STATIC_STRING(
					"An invalid exception handler routine has been detected"
			);
		case SystemCode::DUPLICATE_PRIVILEGES:
			RETURN_STATIC_STRING(
					"Duplicate privileges were specified for the token"
			);
		case SystemCode::NO_RANGES_PROCESSED:
			RETURN_STATIC_STRING(
					"No ranges for the specified operation were able to be processed"
			);
		case SystemCode::NOT_ALLOWED_ON_SYSTEM_FILE:
			RETURN_STATIC_STRING(
					"Operation is not allowed on a file system internal file"
			);
		case SystemCode::DISK_RESOURCES_EXHAUSTED:
			RETURN_STATIC_STRING(
					"The physical resources of this disk have been exhausted"
			);
		case SystemCode::INVALID_TOKEN:
			RETURN_STATIC_STRING(
					"The token representing the data is invalid"
			);
		case SystemCode::DEVICE_FEATURE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The device does not support the command feature"
			);
		case SystemCode::MR_MID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The system cannot find message text for message number 0x%1 in the message"
					" file for %2"
			);
		case SystemCode::SCOPE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The scope specified was not found"
			);
		case SystemCode::UNDEFINED_SCOPE:
			RETURN_STATIC_STRING(
					"The Central Access Policy specified is not defined on the target machine"
			);
		case SystemCode::INVALID_CAP:
			RETURN_STATIC_STRING(
					"The Central Access Policy obtained from Active Directory is invalid"
			);
		case SystemCode::DEVICE_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The device is unreachable"
			);
		case SystemCode::DEVICE_NO_RESOURCES:
			RETURN_STATIC_STRING(
					"The target device has insufficient resources to complete the operation"
			);
		case SystemCode::DATA_CHECKSUM_ERROR:
			RETURN_STATIC_STRING(
					"A data integrity checksum error occurred. Data in the file stream is corrupt"
			);
		case SystemCode::INTERMIXED_KERNEL_EA_OPERATION:
			RETURN_STATIC_STRING(
					"An attempt was made to modify both a KERNEL and normal Extended Attribute (EA)"
					" in the same operation"
			);
		case SystemCode::FILE_LEVEL_TRIM_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"Device does not support file-level TRIM"
			);
		case SystemCode::OFFSET_ALIGNMENT_VIOLATION:
			RETURN_STATIC_STRING(
					"The command specified a data offset that does not align to the device's"
					" granularity/alignment"
			);
		case SystemCode::INVALID_FIELD_IN_PARAMETER_LIST:
			RETURN_STATIC_STRING(
					"The command specified an invalid field in its parameter list"
			);
		case SystemCode::OPERATION_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"An operation is currently in progress with the device"
			);
		case SystemCode::BAD_DEVICE_PATH:
			RETURN_STATIC_STRING(
					"An attempt was made to send down the command via an invalid path to the target"
					" device"
			);
		case SystemCode::TOO_MANY_DESCRIPTORS:
			RETURN_STATIC_STRING(
					"The command specified a number of descriptors that exceeded the maximum"
					" supported by the device"
			);
		case SystemCode::SCRUB_DATA_DISABLED:
			RETURN_STATIC_STRING(
					"Scrub is disabled on the specified file"
			);
		case SystemCode::NOT_REDUNDANT_STORAGE:
			RETURN_STATIC_STRING(
					"The storage device does not provide redundancy"
			);
		case SystemCode::RESIDENT_FILE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"An operation is not supported on a resident file"
			);
		case SystemCode::COMPRESSED_FILE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"An operation is not supported on a compressed file"
			);
		case SystemCode::DIRECTORY_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"An operation is not supported on a directory"
			);
		case SystemCode::NOT_READ_FROM_COPY:
			RETURN_STATIC_STRING(
					"The specified copy of the requested data could not be read"
			);
		case SystemCode::FAIL_NOACTION_REBOOT:
			RETURN_STATIC_STRING(
					"No action was taken as a system reboot is required"
			);
		case SystemCode::FAIL_SHUTDOWN:
			RETURN_STATIC_STRING(
					"The shutdown operation failed"
			);
		case SystemCode::FAIL_RESTART:
			RETURN_STATIC_STRING(
					"The restart operation failed"
			);
		case SystemCode::MAX_SESSIONS_REACHED:
			RETURN_STATIC_STRING(
					"The maximum number of sessions has been reached"
			);
		case SystemCode::THREAD_MODE_ALREADY_BACKGROUND:
			RETURN_STATIC_STRING(
					"The thread is already in background processing mode"
			);
		case SystemCode::THREAD_MODE_NOT_BACKGROUND:
			RETURN_STATIC_STRING(
					"The thread is not in background processing mode"
			);
		case SystemCode::PROCESS_MODE_ALREADY_BACKGROUND:
			RETURN_STATIC_STRING(
					"The process is already in background processing mode"
			);
		case SystemCode::PROCESS_MODE_NOT_BACKGROUND:
			RETURN_STATIC_STRING(
					"The process is not in background processing mode"
			);
		case SystemCode::INVALID_ADDRESS:
			RETURN_STATIC_STRING(
					"Attempt to access invalid address"
			);
		default:
			return nullptr;
	};
}

}}} // flame_ide::os::error
