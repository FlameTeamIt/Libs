#include <FlameIDE/../../src/Os/Windows/SystemCode2.hpp>

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

// + https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--1000-1299-
enum class SystemCode: decltype(::GetLastError())
{
	STACK_OVERFLOW =
#	if defined ERROR_STACK_OVERFLOW
			ERROR_STACK_OVERFLOW
#	else
			0x3E9
#	endif
		// Recursion too deep; the stack overflowed.

	, INVALID_MESSAGE =
#	if defined ERROR_INVALID_MESSAGE
			ERROR_INVALID_MESSAGE
#	else
			0x3EA
#	endif
		// The window cannot act on the sent message.

	, CAN_NOT_COMPLETE =
#	if defined ERROR_CAN_NOT_COMPLETE
			ERROR_CAN_NOT_COMPLETE
#	else
			0x3EB
#	endif
		// Cannot complete this function.

	, INVALID_FLAGS =
#	if defined ERROR_INVALID_FLAGS
			ERROR_INVALID_FLAGS
#	else
			0x3EC
#	endif
		// Invalid flags.

	, UNRECOGNIZED_VOLUME =
#	if defined ERROR_UNRECOGNIZED_VOLUME
			ERROR_UNRECOGNIZED_VOLUME
#	else
			0x3ED
#	endif
		// The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted.

	, FILE_INVALID =
#	if defined ERROR_FILE_INVALID
			ERROR_FILE_INVALID
#	else
			0x3EE
#	endif
		// The volume for a file has been externally altered so that the opened file is no longer valid.

	, FULLSCREEN_MODE =
#	if defined ERROR_FULLSCREEN_MODE
			ERROR_FULLSCREEN_MODE
#	else
			0x3EF
#	endif
		// The requested operation cannot be performed in full-screen mode.

	, NO_TOKEN =
#	if defined ERROR_NO_TOKEN
			ERROR_NO_TOKEN
#	else
			0x3F0
#	endif
		// An attempt was made to reference a token that does not exist.

	, BADDB =
#	if defined ERROR_BADDB
			ERROR_BADDB
#	else
			0x3F1
#	endif
		// The configuration registry database is corrupt.

	, BADKEY =
#	if defined ERROR_BADKEY
			ERROR_BADKEY
#	else
			0x3F2
#	endif
		// The configuration registry key is invalid.

	, CANTOPEN =
#	if defined ERROR_CANTOPEN
			ERROR_CANTOPEN
#	else
			0x3F3
#	endif
		// The configuration registry key could not be opened.

	, CANTREAD =
#	if defined ERROR_CANTREAD
			ERROR_CANTREAD
#	else
			0x3F4
#	endif
		// The configuration registry key could not be read.

	, CANTWRITE =
#	if defined ERROR_CANTWRITE
			ERROR_CANTWRITE
#	else
			0x3F5
#	endif
		// The configuration registry key could not be written.

	, REGISTRY_RECOVERED =
#	if defined ERROR_REGISTRY_RECOVERED
			ERROR_REGISTRY_RECOVERED
#	else
			0x3F6
#	endif
		// One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.

	, REGISTRY_CORRUPT =
#	if defined ERROR_REGISTRY_CORRUPT
			ERROR_REGISTRY_CORRUPT
#	else
			0x3F7
#	endif
		// The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.

	, REGISTRY_IO_FAILED =
#	if defined ERROR_REGISTRY_IO_FAILED
			ERROR_REGISTRY_IO_FAILED
#	else
			0x3F8
#	endif
		// An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.

	, NOT_REGISTRY_FILE =
#	if defined ERROR_NOT_REGISTRY_FILE
			ERROR_NOT_REGISTRY_FILE
#	else
			0x3F9
#	endif
		// The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.

	, KEY_DELETED =
#	if defined ERROR_KEY_DELETED
			ERROR_KEY_DELETED
#	else
			0x3FA
#	endif
		// Illegal operation attempted on a registry key that has been marked for deletion.

	, NO_LOG_SPACE =
#	if defined ERROR_NO_LOG_SPACE
			ERROR_NO_LOG_SPACE
#	else
			0x3FB
#	endif
		// System could not allocate the required space in a registry log.

	, KEY_HAS_CHILDREN =
#	if defined ERROR_KEY_HAS_CHILDREN
			ERROR_KEY_HAS_CHILDREN
#	else
			0x3FC
#	endif
		// Cannot create a symbolic link in a registry key that already has subkeys or values.

	, CHILD_MUST_BE_VOLATILE =
#	if defined ERROR_CHILD_MUST_BE_VOLATILE
			ERROR_CHILD_MUST_BE_VOLATILE
#	else
			0x3FD
#	endif
		// Cannot create a stable subkey under a volatile parent key.

	, NOTIFY_ENUM_DIR =
#	if defined ERROR_NOTIFY_ENUM_DIR
			ERROR_NOTIFY_ENUM_DIR
#	else
			0x3FE
#	endif
		// A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.

	, DEPENDENT_SERVICES_RUNNING =
#	if defined ERROR_DEPENDENT_SERVICES_RUNNING
			ERROR_DEPENDENT_SERVICES_RUNNING
#	else
			0x41B
#	endif
		// A stop control has been sent to a service that other running services are dependent on.

	, INVALID_SERVICE_CONTROL =
#	if defined ERROR_INVALID_SERVICE_CONTROL
			ERROR_INVALID_SERVICE_CONTROL
#	else
			0x41C
#	endif
		// The requested control is not valid for this service.

	, SERVICE_REQUEST_TIMEOUT =
#	if defined ERROR_SERVICE_REQUEST_TIMEOUT
			ERROR_SERVICE_REQUEST_TIMEOUT
#	else
			0x41D
#	endif
		// The service did not respond to the start or control request in a timely fashion.

	, SERVICE_NO_THREAD =
#	if defined ERROR_SERVICE_NO_THREAD
			ERROR_SERVICE_NO_THREAD
#	else
			0x41E
#	endif
		// A thread could not be created for the service.

	, SERVICE_DATABASE_LOCKED =
#	if defined ERROR_SERVICE_DATABASE_LOCKED
			ERROR_SERVICE_DATABASE_LOCKED
#	else
			0x41F
#	endif
		// The service database is locked.

	, SERVICE_ALREADY_RUNNING =
#	if defined ERROR_SERVICE_ALREADY_RUNNING
			ERROR_SERVICE_ALREADY_RUNNING
#	else
			0x420
#	endif
		// An instance of the service is already running.

	, INVALID_SERVICE_ACCOUNT =
#	if defined ERROR_INVALID_SERVICE_ACCOUNT
			ERROR_INVALID_SERVICE_ACCOUNT
#	else
			0x421
#	endif
		// The account name is invalid or does not exist, or the password is invalid for the account name specified.

	, SERVICE_IS_DISABLED =
#	if defined ERROR_SERVICE_DISABLED
			ERROR_SERVICE_DISABLED
#	else
			0x422
#	endif
		// The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.

	, CIRCULAR_DEPENDENCY =
#	if defined ERROR_CIRCULAR_DEPENDENCY
			ERROR_CIRCULAR_DEPENDENCY
#	else
			0x423
#	endif
		// Circular service dependency was specified.

	, SERVICE_DOES_NOT_EXIST =
#	if defined ERROR_SERVICE_DOES_NOT_EXIST
			ERROR_SERVICE_DOES_NOT_EXIST
#	else
			0x424
#	endif
		// The specified service does not exist as an installed service.

	, SERVICE_CANNOT_ACCEPT_CTRL =
#	if defined ERROR_SERVICE_CANNOT_ACCEPT_CTRL
			ERROR_SERVICE_CANNOT_ACCEPT_CTRL
#	else
			0x425
#	endif
		// The service cannot accept control messages at this time.

	, SERVICE_NOT_ACTIVE =
#	if defined ERROR_SERVICE_NOT_ACTIVE
			ERROR_SERVICE_NOT_ACTIVE
#	else
			0x426
#	endif
		// The service has not been started.

	, FAILED_SERVICE_CONTROLLER_CONNECT =
#	if defined ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
			ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
#	else
			0x427
#	endif
		// The service process could not connect to the service controller.

	, EXCEPTION_IN_SERVICE =
#	if defined ERROR_EXCEPTION_IN_SERVICE
			ERROR_EXCEPTION_IN_SERVICE
#	else
			0x428
#	endif
		// An exception occurred in the service when handling the control request.

	, DATABASE_DOES_NOT_EXIST =
#	if defined ERROR_DATABASE_DOES_NOT_EXIST
			ERROR_DATABASE_DOES_NOT_EXIST
#	else
			0x429
#	endif
		// The database specified does not exist.

	, SERVICE_SPECIFIC_ERROR =
#	if defined ERROR_SERVICE_SPECIFIC_ERROR
			ERROR_SERVICE_SPECIFIC_ERROR
#	else
			0x42A
#	endif
		// The service has returned a service-specific error code.

	, PROCESS_ABORTED =
#	if defined ERROR_PROCESS_ABORTED
			ERROR_PROCESS_ABORTED
#	else
			0x42B
#	endif
		// The process terminated unexpectedly.

	, SERVICE_DEPENDENCY_FAIL =
#	if defined ERROR_SERVICE_DEPENDENCY_FAIL
			ERROR_SERVICE_DEPENDENCY_FAIL
#	else
			0x42C
#	endif
		// The dependency service or group failed to start.

	, SERVICE_LOGON_FAILED =
#	if defined ERROR_SERVICE_LOGON_FAILED
			ERROR_SERVICE_LOGON_FAILED
#	else
			0x42D
#	endif
		// The service did not start due to a logon failure.

	, SERVICE_START_HANG =
#	if defined ERROR_SERVICE_START_HANG
			ERROR_SERVICE_START_HANG
#	else
			0x42E
#	endif
		// After starting, the service hung in a start-pending state.

	, INVALID_SERVICE_LOCK =
#	if defined ERROR_INVALID_SERVICE_LOCK
			ERROR_INVALID_SERVICE_LOCK
#	else
			0x42F
#	endif
		// The specified service database lock is invalid.

	, SERVICE_MARKED_FOR_DELETE =
#	if defined ERROR_SERVICE_MARKED_FOR_DELETE
			ERROR_SERVICE_MARKED_FOR_DELETE
#	else
			0x430
#	endif
		// The specified service has been marked for deletion.

	, SERVICE_EXISTS =
#	if defined ERROR_SERVICE_EXISTS
			ERROR_SERVICE_EXISTS
#	else
			0x431
#	endif
		// The specified service already exists.

	, ALREADY_RUNNING_LKG =
#	if defined ERROR_ALREADY_RUNNING_LKG
			ERROR_ALREADY_RUNNING_LKG
#	else
			0x432
#	endif
		// The system is currently running with the last-known-good configuration.

	, SERVICE_DEPENDENCY_DELETED =
#	if defined ERROR_SERVICE_DEPENDENCY_DELETED
			ERROR_SERVICE_DEPENDENCY_DELETED
#	else
			0x433
#	endif
		// The dependency service does not exist or has been marked for deletion.

	, BOOT_ALREADY_ACCEPTED =
#	if defined ERROR_BOOT_ALREADY_ACCEPTED
			ERROR_BOOT_ALREADY_ACCEPTED
#	else
			0x434
#	endif
		// The current boot has already been accepted for use as the last-known-good control set.

	, SERVICE_NEVER_STARTED =
#	if defined ERROR_SERVICE_NEVER_STARTED
			ERROR_SERVICE_NEVER_STARTED
#	else
			0x435
#	endif
		// No attempts to start the service have been made since the last boot.

	, DUPLICATE_SERVICE_NAME =
#	if defined ERROR_DUPLICATE_SERVICE_NAME
			ERROR_DUPLICATE_SERVICE_NAME
#	else
			0x436
#	endif
		// The name is already in use as either a service name or a service display name.

	, DIFFERENT_SERVICE_ACCOUNT =
#	if defined ERROR_DIFFERENT_SERVICE_ACCOUNT
			ERROR_DIFFERENT_SERVICE_ACCOUNT
#	else
			0x437
#	endif
		// The account specified for this service is different from the account specified for other services running in the same process.

	, CANNOT_DETECT_DRIVER_FAILURE =
#	if defined ERROR_CANNOT_DETECT_DRIVER_FAILURE
			ERROR_CANNOT_DETECT_DRIVER_FAILURE
#	else
			0x438
#	endif
		// Failure actions can only be set for Win32 services, not for drivers.

	, CANNOT_DETECT_PROCESS_ABORT =
#	if defined ERROR_CANNOT_DETECT_PROCESS_ABORT
			ERROR_CANNOT_DETECT_PROCESS_ABORT
#	else
			0x439
#	endif
		// This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.

	, NO_RECOVERY_PROGRAM =
#	if defined ERROR_NO_RECOVERY_PROGRAM
			ERROR_NO_RECOVERY_PROGRAM
#	else
			0x43A
#	endif
		// No recovery program has been configured for this service.

	, SERVICE_NOT_IN_EXE =
#	if defined ERROR_SERVICE_NOT_IN_EXE
			ERROR_SERVICE_NOT_IN_EXE
#	else
			0x43B
#	endif
		// The executable program that this service is configured to run in does not implement the service.

	, NOT_SAFEBOOT_SERVICE =
#	if defined ERROR_NOT_SAFEBOOT_SERVICE
			ERROR_NOT_SAFEBOOT_SERVICE
#	else
			0x43C
#	endif
		// This service cannot be started in Safe Mode.

	, END_OF_MEDIA =
#	if defined ERROR_END_OF_MEDIA
			ERROR_END_OF_MEDIA
#	else
			0x44C
#	endif
		// The physical end of the tape has been reached.

	, FILEMARK_DETECTED =
#	if defined ERROR_FILEMARK_DETECTED
			ERROR_FILEMARK_DETECTED
#	else
			0x44D
#	endif
		// A tape access reached a filemark.

	, BEGINNING_OF_MEDIA =
#	if defined ERROR_BEGINNING_OF_MEDIA
			ERROR_BEGINNING_OF_MEDIA
#	else
			0x44E
#	endif
		// The beginning of the tape or a partition was encountered.

	, SETMARK_DETECTED =
#	if defined ERROR_SETMARK_DETECTED
			ERROR_SETMARK_DETECTED
#	else
			0x44F
#	endif
		// A tape access reached the end of a set of files.

	, NO_DATA_DETECTED =
#	if defined ERROR_NO_DATA_DETECTED
			ERROR_NO_DATA_DETECTED
#	else
			0x450
#	endif
		// No more data is on the tape.

	, PARTITION_FAILURE =
#	if defined ERROR_PARTITION_FAILURE
			ERROR_PARTITION_FAILURE
#	else
			0x451
#	endif
		// Tape could not be partitioned.

	, INVALID_BLOCK_LENGTH =
#	if defined ERROR_INVALID_BLOCK_LENGTH
			ERROR_INVALID_BLOCK_LENGTH
#	else
			0x452
#	endif
		// When accessing a new tape of a multivolume partition, the current block size is incorrect.

	, DEVICE_NOT_PARTITIONED =
#	if defined ERROR_DEVICE_NOT_PARTITIONED
			ERROR_DEVICE_NOT_PARTITIONED
#	else
			0x453
#	endif
		// Tape partition information could not be found when loading a tape.

	, UNABLE_TO_LOCK_MEDIA =
#	if defined ERROR_UNABLE_TO_LOCK_MEDIA
			ERROR_UNABLE_TO_LOCK_MEDIA
#	else
			0x454
#	endif
		// Unable to lock the media eject mechanism.

	, UNABLE_TO_UNLOAD_MEDIA =
#	if defined ERROR_UNABLE_TO_UNLOAD_MEDIA
			ERROR_UNABLE_TO_UNLOAD_MEDIA
#	else
			0x455
#	endif
		// Unable to unload the media.

	, MEDIA_CHANGED =
#	if defined ERROR_MEDIA_CHANGED
			ERROR_MEDIA_CHANGED
#	else
			0x456
#	endif
		// The media in the drive may have changed.

	, BUS_RESET =
#	if defined ERROR_BUS_RESET
			ERROR_BUS_RESET
#	else
			0x457
#	endif
		// The I/O bus was reset.

	, NO_MEDIA_IN_DRIVE =
#	if defined ERROR_NO_MEDIA_IN_DRIVE
			ERROR_NO_MEDIA_IN_DRIVE
#	else
			0x458
#	endif
		// No media in drive.

	, NO_UNICODE_TRANSLATION =
#	if defined ERROR_NO_UNICODE_TRANSLATION
			ERROR_NO_UNICODE_TRANSLATION
#	else
			0x459
#	endif
		// No mapping for the Unicode character exists in the target multi-byte code page.

	, DLL_INIT_FAILED =
#	if defined ERROR_DLL_INIT_FAILED
			ERROR_DLL_INIT_FAILED
#	else
			0x45A
#	endif
		// A dynamic link library (DLL) initialization routine failed.

	, SHUTDOWN_IN_PROGRESS =
#	if defined ERROR_SHUTDOWN_IN_PROGRESS
			ERROR_SHUTDOWN_IN_PROGRESS
#	else
			0x45B
#	endif
		// A system shutdown is in progress.

	, NO_SHUTDOWN_IN_PROGRESS =
#	if defined ERROR_NO_SHUTDOWN_IN_PROGRESS
			ERROR_NO_SHUTDOWN_IN_PROGRESS
#	else
			0x45C
#	endif
		// Unable to abort the system shutdown because no shutdown was in progress.

	, IO_DEVICE =
#	if defined ERROR_IO_DEVICE
			ERROR_IO_DEVICE
#	else
			0x45D
#	endif
		// The request could not be performed because of an I/O device error.

	, SERIAL_NO_DEVICE =
#	if defined ERROR_SERIAL_NO_DEVICE
			ERROR_SERIAL_NO_DEVICE
#	else
			0x45E
#	endif
		// No serial device was successfully initialized. The serial driver will unload.

	, IRQ_BUSY =
#	if defined ERROR_IRQ_BUSY
			ERROR_IRQ_BUSY
#	else
			0x45F
#	endif
		// Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.

	, MORE_WRITES =
#	if defined ERROR_MORE_WRITES
			ERROR_MORE_WRITES
#	else
			0x460
#	endif
		// A serial I/O operation was completed by another write to the serial port. The IOCTL_SERIAL_XOFF_COUNTER reached zero.)

	, COUNTER_TIMEOUT =
#	if defined ERROR_COUNTER_TIMEOUT
			ERROR_COUNTER_TIMEOUT
#	else
			0x461
#	endif
		// A serial I/O operation completed because the timeout period expired. The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)

	, FLOPPY_ID_MARK_NOT_FOUND =
#	if defined ERROR_FLOPPY_ID_MARK_NOT_FOUND
			ERROR_FLOPPY_ID_MARK_NOT_FOUND
#	else
			0x462
#	endif
		// No ID address mark was found on the floppy disk.

	, FLOPPY_WRONG_CYLINDER =
#	if defined ERROR_FLOPPY_WRONG_CYLINDER
			ERROR_FLOPPY_WRONG_CYLINDER
#	else
			0x463
#	endif
		// Mismatch between the floppy disk sector ID field and the floppy disk controller track address.

	, FLOPPY_UNKNOWN_ERROR =
#	if defined ERROR_FLOPPY_UNKNOWN_ERROR
			ERROR_FLOPPY_UNKNOWN_ERROR
#	else
			0x464
#	endif
		// The floppy disk controller reported an error that is not recognized by the floppy disk driver.

	, FLOPPY_BAD_REGISTERS =
#	if defined ERROR_FLOPPY_BAD_REGISTERS
			ERROR_FLOPPY_BAD_REGISTERS
#	else
			0x465
#	endif
		// The floppy disk controller returned inconsistent results in its registers.

	, DISK_RECALIBRATE_FAILED =
#	if defined ERROR_DISK_RECALIBRATE_FAILED
			ERROR_DISK_RECALIBRATE_FAILED
#	else
			0x466
#	endif
		// While accessing the hard disk, a recalibrate operation failed, even after retries.

	, DISK_OPERATION_FAILED =
#	if defined ERROR_DISK_OPERATION_FAILED
			ERROR_DISK_OPERATION_FAILED
#	else
			0x467
#	endif
		// While accessing the hard disk, a disk operation failed even after retries.

	, DISK_RESET_FAILED =
#	if defined ERROR_DISK_RESET_FAILED
			ERROR_DISK_RESET_FAILED
#	else
			0x468
#	endif
		// While accessing the hard disk, a disk controller reset was needed, but even that failed.

	, EOM_OVERFLOW =
#	if defined ERROR_EOM_OVERFLOW
			ERROR_EOM_OVERFLOW
#	else
			0x469
#	endif
		// Physical end of tape encountered.

	, NOT_ENOUGH_SERVER_MEMORY =
#	if defined ERROR_NOT_ENOUGH_SERVER_MEMORY
			ERROR_NOT_ENOUGH_SERVER_MEMORY
#	else
			0x46A
#	endif
		// Not enough server storage is available to process this command.

	, POSSIBLE_DEADLOCK =
#	if defined ERROR_POSSIBLE_DEADLOCK
			ERROR_POSSIBLE_DEADLOCK
#	else
			0x46B
#	endif
		// A potential deadlock condition has been detected.

	, MAPPED_ALIGNMENT =
#	if defined ERROR_MAPPED_ALIGNMENT
			ERROR_MAPPED_ALIGNMENT
#	else
			0x46C
#	endif
		// The base address or the file offset specified does not have the proper alignment.

	, SET_POWER_STATE_VETOED =
#	if defined ERROR_SET_POWER_STATE_VETOED
			ERROR_SET_POWER_STATE_VETOED
#	else
			0x474
#	endif
		// An attempt to change the system power state was vetoed by another application or driver.

	, SET_POWER_STATE_FAILED =
#	if defined ERROR_SET_POWER_STATE_FAILED
			ERROR_SET_POWER_STATE_FAILED
#	else
			0x475
#	endif
		// The system BIOS failed an attempt to change the system power state.

	, TOO_MANY_LINKS =
#	if defined ERROR_TOO_MANY_LINKS
			ERROR_TOO_MANY_LINKS
#	else
			0x476
#	endif
		// An attempt was made to create more links on a file than the file system supports.

	, OLD_WIN_VERSION =
#	if defined ERROR_OLD_WIN_VERSION
			ERROR_OLD_WIN_VERSION
#	else
			0x47E
#	endif
		// The specified program requires a newer version of Windows.

	, APP_WRONG_OS =
#	if defined ERROR_APP_WRONG_OS
			ERROR_APP_WRONG_OS
#	else
			0x47F
#	endif
		// The specified program is not a Windows or MS-DOS program.

	, SINGLE_INSTANCE_APP =
#	if defined ERROR_SINGLE_INSTANCE_APP
			ERROR_SINGLE_INSTANCE_APP
#	else
			0x480
#	endif
		// Cannot start more than one instance of the specified program.

	, RMODE_APP =
#	if defined ERROR_RMODE_APP
			ERROR_RMODE_APP
#	else
			0x481
#	endif
		// The specified program was written for an earlier version of Windows.

	, INVALID_DLL =
#	if defined ERROR_INVALID_DLL
			ERROR_INVALID_DLL
#	else
			0x482
#	endif
		// One of the library files needed to run this application is damaged.

	, NO_ASSOCIATION =
#	if defined ERROR_NO_ASSOCIATION
			ERROR_NO_ASSOCIATION
#	else
			0x483
#	endif
		// No application is associated with the specified file for this operation.

	, DDE_FAIL =
#	if defined ERROR_DDE_FAIL
			ERROR_DDE_FAIL
#	else
			0x484
#	endif
		// An error occurred in sending the command to the application.

	, DLL_NOT_FOUND =
#	if defined ERROR_DLL_NOT_FOUND
			ERROR_DLL_NOT_FOUND
#	else
			0x485
#	endif
		// One of the library files needed to run this application cannot be found.

	, NO_MORE_USER_HANDLES =
#	if defined ERROR_NO_MORE_USER_HANDLES
			ERROR_NO_MORE_USER_HANDLES
#	else
			0x486
#	endif
		// The current process has used all of its system allowance of handles for Window Manager objects.

	, MESSAGE_SYNC_ONLY =
#	if defined ERROR_MESSAGE_SYNC_ONLY
			ERROR_MESSAGE_SYNC_ONLY
#	else
			0x487
#	endif
		// The message can be used only with synchronous operations.

	, SOURCE_ELEMENT_EMPTY =
#	if defined ERROR_SOURCE_ELEMENT_EMPTY
			ERROR_SOURCE_ELEMENT_EMPTY
#	else
			0x488
#	endif
		// The indicated source element has no media.

	, DESTINATION_ELEMENT_FULL =
#	if defined ERROR_DESTINATION_ELEMENT_FULL
			ERROR_DESTINATION_ELEMENT_FULL
#	else
			0x489
#	endif
		// The indicated destination element already contains media.

	, ILLEGAL_ELEMENT_ADDRESS =
#	if defined ERROR_ILLEGAL_ELEMENT_ADDRESS
			ERROR_ILLEGAL_ELEMENT_ADDRESS
#	else
			0x48A
#	endif
		// The indicated element does not exist.

	, MAGAZINE_NOT_PRESENT =
#	if defined ERROR_MAGAZINE_NOT_PRESENT
			ERROR_MAGAZINE_NOT_PRESENT
#	else
			0x48B
#	endif
		// The indicated element is part of a magazine that is not present.

	, DEVICE_REINITIALIZATION_NEEDED =
#	if defined ERROR_DEVICE_REINITIALIZATION_NEEDED
			ERROR_DEVICE_REINITIALIZATION_NEEDED
#	else
			0x48C
#	endif
		// The indicated device requires reinitialization due to hardware errors.

	, DEVICE_REQUIRES_CLEANING =
#	if defined ERROR_DEVICE_REQUIRES_CLEANING
			ERROR_DEVICE_REQUIRES_CLEANING
#	else
			0x48D
#	endif
		// The device has indicated that cleaning is required before further operations are attempted.

	, DEVICE_DOOR_OPEN =
#	if defined ERROR_DEVICE_DOOR_OPEN
			ERROR_DEVICE_DOOR_OPEN
#	else
			0x48E
#	endif
		// The device has indicated that its door is open.

	, DEVICE_NOT_CONNECTED =
#	if defined ERROR_DEVICE_NOT_CONNECTED
			ERROR_DEVICE_NOT_CONNECTED
#	else
			0x48F
#	endif
		// The device is not connected.

	, NOT_FOUND =
#	if defined ERROR_NOT_FOUND
			ERROR_NOT_FOUND
#	else
			0x490
#	endif
		// Element not found.

	, NO_MATCH =
#	if defined ERROR_NO_MATCH
			ERROR_NO_MATCH
#	else
			0x491
#	endif
		// There was no match for the specified key in the index.

	, SET_NOT_FOUND =
#	if defined ERROR_SET_NOT_FOUND
			ERROR_SET_NOT_FOUND
#	else
			0x492
#	endif
		// The property set specified does not exist on the object.

	, POINT_NOT_FOUND =
#	if defined ERROR_POINT_NOT_FOUND
			ERROR_POINT_NOT_FOUND
#	else
			0x493
#	endif
		// The point passed to GetMouseMovePoints is not in the buffer.

	, NO_TRACKING_SERVICE =
#	if defined ERROR_NO_TRACKING_SERVICE
			ERROR_NO_TRACKING_SERVICE
#	else
			0x494
#	endif
		// The tracking (workstation) service is not running.

	, NO_VOLUME_ID =
#	if defined ERROR_NO_VOLUME_ID
			ERROR_NO_VOLUME_ID
#	else
			0x495
#	endif
		// The Volume ID could not be found.

	, UNABLE_TO_REMOVE_REPLACED =
#	if defined ERROR_UNABLE_TO_REMOVE_REPLACED
			ERROR_UNABLE_TO_REMOVE_REPLACED
#	else
			0x497
#	endif
		// Unable to remove the file to be replaced.

	, UNABLE_TO_MOVE_REPLACEMENT =
#	if defined ERROR_UNABLE_TO_MOVE_REPLACEMENT
			ERROR_UNABLE_TO_MOVE_REPLACEMENT
#	else
			0x498
#	endif
		// Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.

	, UNABLE_TO_MOVE_REPLACEMENT_2 =
#	if defined ERROR_UNABLE_TO_MOVE_REPLACEMENT_2
			ERROR_UNABLE_TO_MOVE_REPLACEMENT_2
#	else
			0x499
#	endif
		// Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.

	, JOURNAL_DELETE_IN_PROGRESS =
#	if defined ERROR_JOURNAL_DELETE_IN_PROGRESS
			ERROR_JOURNAL_DELETE_IN_PROGRESS
#	else
			0x49A
#	endif
		// The volume change journal is being deleted.

	, JOURNAL_NOT_ACTIVE =
#	if defined ERROR_JOURNAL_NOT_ACTIVE
			ERROR_JOURNAL_NOT_ACTIVE
#	else
			0x49B
#	endif
		// The volume change journal is not active.

	, POTENTIAL_FILE_FOUND =
#	if defined ERROR_POTENTIAL_FILE_FOUND
			ERROR_POTENTIAL_FILE_FOUND
#	else
			0x49C
#	endif
		// A file was found, but it may not be the correct file.

	, JOURNAL_ENTRY_DELETED =
#	if defined ERROR_JOURNAL_ENTRY_DELETED
			ERROR_JOURNAL_ENTRY_DELETED
#	else
			0x49D
#	endif
		// The journal entry has been deleted from the journal.

	, SHUTDOWN_IS_SCHEDULED =
#	if defined ERROR_SHUTDOWN_IS_SCHEDULED
			ERROR_SHUTDOWN_IS_SCHEDULED
#	else
			0x4A6
#	endif
		// A system shutdown has already been scheduled.

	, SHUTDOWN_USERS_LOGGED_ON =
#	if defined ERROR_SHUTDOWN_USERS_LOGGED_ON
			ERROR_SHUTDOWN_USERS_LOGGED_ON
#	else
			0x4A7
#	endif
		// The system shutdown cannot be initiated because there are other users logged on to the computer.

	, BAD_DEVICE =
#	if defined ERROR_BAD_DEVICE
			ERROR_BAD_DEVICE
#	else
			0x4B0
#	endif
		// The specified device name is invalid.

	, CONNECTION_UNAVAIL =
#	if defined ERROR_CONNECTION_UNAVAIL
			ERROR_CONNECTION_UNAVAIL
#	else
			0x4B1
#	endif
		// The device is not currently connected but it is a remembered connection.

	, DEVICE_ALREADY_REMEMBERED =
#	if defined ERROR_DEVICE_ALREADY_REMEMBERED
			ERROR_DEVICE_ALREADY_REMEMBERED
#	else
			0x4B2
#	endif
		// The local device name has a remembered connection to another network resource.

	, NO_NET_OR_BAD_PATH =
#	if defined ERROR_NO_NET_OR_BAD_PATH
			ERROR_NO_NET_OR_BAD_PATH
#	else
			0x4B3
#	endif
		// The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.

	, BAD_PROVIDER =
#	if defined ERROR_BAD_PROVIDER
			ERROR_BAD_PROVIDER
#	else
			0x4B4
#	endif
		// The specified network provider name is invalid.

	, CANNOT_OPEN_PROFILE =
#	if defined ERROR_CANNOT_OPEN_PROFILE
			ERROR_CANNOT_OPEN_PROFILE
#	else
			0x4B5
#	endif
		// Unable to open the network connection profile.

	, BAD_PROFILE =
#	if defined ERROR_BAD_PROFILE
			ERROR_BAD_PROFILE
#	else
			0x4B6
#	endif
		// The network connection profile is corrupted.

	, NOT_CONTAINER =
#	if defined ERROR_NOT_CONTAINER
			ERROR_NOT_CONTAINER
#	else
			0x4B7
#	endif
		// Cannot enumerate a noncontainer.

	, EXTENDED_ERROR =
#	if defined ERROR_EXTENDED_ERROR
			ERROR_EXTENDED_ERROR
#	else
			0x4B8
#	endif
		// An extended error has occurred.

	, INVALID_GROUPNAME =
#	if defined ERROR_INVALID_GROUPNAME
			ERROR_INVALID_GROUPNAME
#	else
			0x4B9
#	endif
		// The format of the specified group name is invalid.

	, INVALID_COMPUTERNAME =
#	if defined ERROR_INVALID_COMPUTERNAME
			ERROR_INVALID_COMPUTERNAME
#	else
			0x4BA
#	endif
		// The format of the specified computer name is invalid.

	, INVALID_EVENTNAME =
#	if defined ERROR_INVALID_EVENTNAME
			ERROR_INVALID_EVENTNAME
#	else
			0x4BB
#	endif
		// The format of the specified event name is invalid.

	, INVALID_DOMAINNAME =
#	if defined ERROR_INVALID_DOMAINNAME
			ERROR_INVALID_DOMAINNAME
#	else
			0x4BC
#	endif
		// The format of the specified domain name is invalid.

	, INVALID_SERVICENAME =
#	if defined ERROR_INVALID_SERVICENAME
			ERROR_INVALID_SERVICENAME
#	else
			0x4BD
#	endif
		// The format of the specified service name is invalid.

	, INVALID_NETNAME =
#	if defined ERROR_INVALID_NETNAME
			ERROR_INVALID_NETNAME
#	else
			0x4BE
#	endif
		// The format of the specified network name is invalid.

	, INVALID_SHARENAME =
#	if defined ERROR_INVALID_SHARENAME
			ERROR_INVALID_SHARENAME
#	else
			0x4BF
#	endif
		// The format of the specified share name is invalid.

	, INVALID_PASSWORDNAME =
#	if defined ERROR_INVALID_PASSWORDNAME
			ERROR_INVALID_PASSWORDNAME
#	else
			0x4C0
#	endif
		// The format of the specified password is invalid.

	, INVALID_MESSAGENAME =
#	if defined ERROR_INVALID_MESSAGENAME
			ERROR_INVALID_MESSAGENAME
#	else
			0x4C1
#	endif
		// The format of the specified message name is invalid.

	, INVALID_MESSAGEDEST =
#	if defined ERROR_INVALID_MESSAGEDEST
			ERROR_INVALID_MESSAGEDEST
#	else
			0x4C2
#	endif
		// The format of the specified message destination is invalid.

	, SESSION_CREDENTIAL_CONFLICT =
#	if defined ERROR_SESSION_CREDENTIAL_CONFLICT
			ERROR_SESSION_CREDENTIAL_CONFLICT
#	else
			0x4C3
#	endif
		// Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.

	, REMOTE_SESSION_LIMIT_EXCEEDED =
#	if defined ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
			ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
#	else
			0x4C4
#	endif
		// An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.

	, DUP_DOMAINNAME =
#	if defined ERROR_DUP_DOMAINNAME
			ERROR_DUP_DOMAINNAME
#	else
			0x4C5
#	endif
		// The workgroup or domain name is already in use by another computer on the network.

	, NO_NETWORK =
#	if defined ERROR_NO_NETWORK
			ERROR_NO_NETWORK
#	else
			0x4C6
#	endif
		// The network is not present or not started.

	, CANCELLED =
#	if defined ERROR_CANCELLED
			ERROR_CANCELLED
#	else
			0x4C7
#	endif
		// The operation was canceled by the user.

	, USER_MAPPED_FILE =
#	if defined ERROR_USER_MAPPED_FILE
			ERROR_USER_MAPPED_FILE
#	else
			0x4C8
#	endif
		// The requested operation cannot be performed on a file with a user-mapped section open.

	, CONNECTION_REFUSED =
#	if defined ERROR_CONNECTION_REFUSED
			ERROR_CONNECTION_REFUSED
#	else
			0x4C9
#	endif
		// The remote computer refused the network connection.

	, GRACEFUL_DISCONNECT =
#	if defined ERROR_GRACEFUL_DISCONNECT
			ERROR_GRACEFUL_DISCONNECT
#	else
			0x4CA
#	endif
		// The network connection was gracefully closed.

	, ADDRESS_ALREADY_ASSOCIATED =
#	if defined ERROR_ADDRESS_ALREADY_ASSOCIATED
			ERROR_ADDRESS_ALREADY_ASSOCIATED
#	else
			0x4CB
#	endif
		// The network transport endpoint already has an address associated with it.

	, ADDRESS_NOT_ASSOCIATED =
#	if defined ERROR_ADDRESS_NOT_ASSOCIATED
			ERROR_ADDRESS_NOT_ASSOCIATED
#	else
			0x4CC
#	endif
		// An address has not yet been associated with the network endpoint.

	, CONNECTION_INVALID =
#	if defined ERROR_CONNECTION_INVALID
			ERROR_CONNECTION_INVALID
#	else
			0x4CD
#	endif
		// An operation was attempted on a nonexistent network connection.

	, CONNECTION_ACTIVE =
#	if defined ERROR_CONNECTION_ACTIVE
			ERROR_CONNECTION_ACTIVE
#	else
			0x4CE
#	endif
		// An invalid operation was attempted on an active network connection.

	, NETWORK_UNREACHABLE =
#	if defined ERROR_NETWORK_UNREACHABLE
			ERROR_NETWORK_UNREACHABLE
#	else
			0x4CF
#	endif
		// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

	, HOST_UNREACHABLE =
#	if defined ERROR_HOST_UNREACHABLE
			ERROR_HOST_UNREACHABLE
#	else
			0x4D0
#	endif
		// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

	, PROTOCOL_UNREACHABLE =
#	if defined ERROR_PROTOCOL_UNREACHABLE
			ERROR_PROTOCOL_UNREACHABLE
#	else
			0x4D1
#	endif
		// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

	, PORT_UNREACHABLE =
#	if defined ERROR_PORT_UNREACHABLE
			ERROR_PORT_UNREACHABLE
#	else
			0x4D2
#	endif
		// No service is operating at the destination network endpoint on the remote system.

	, REQUEST_ABORTED =
#	if defined ERROR_REQUEST_ABORTED
			ERROR_REQUEST_ABORTED
#	else
			0x4D3
#	endif
		// The request was aborted.

	, CONNECTION_ABORTED =
#	if defined ERROR_CONNECTION_ABORTED
			ERROR_CONNECTION_ABORTED
#	else
			0x4D4
#	endif
		// The network connection was aborted by the local system.

	, RETRY =
#	if defined ERROR_RETRY
			ERROR_RETRY
#	else
			0x4D5
#	endif
		// The operation could not be completed. A retry should be performed.

	, CONNECTION_COUNT_LIMIT =
#	if defined ERROR_CONNECTION_COUNT_LIMIT
			ERROR_CONNECTION_COUNT_LIMIT
#	else
			0x4D6
#	endif
		// A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.

	, LOGIN_TIME_RESTRICTION =
#	if defined ERROR_LOGIN_TIME_RESTRICTION
			ERROR_LOGIN_TIME_RESTRICTION
#	else
			0x4D7
#	endif
		// Attempting to log in during an unauthorized time of day for this account.

	, LOGIN_WKSTA_RESTRICTION =
#	if defined ERROR_LOGIN_WKSTA_RESTRICTION
			ERROR_LOGIN_WKSTA_RESTRICTION
#	else
			0x4D8
#	endif
		// The account is not authorized to log in from this station.

	, INCORRECT_ADDRESS =
#	if defined ERROR_INCORRECT_ADDRESS
			ERROR_INCORRECT_ADDRESS
#	else
			0x4D9
#	endif
		// The network address could not be used for the operation requested.

	, ALREADY_REGISTERED =
#	if defined ERROR_ALREADY_REGISTERED
			ERROR_ALREADY_REGISTERED
#	else
			0x4DA
#	endif
		// The service is already registered.

	, SERVICE_NOT_FOUND =
#	if defined ERROR_SERVICE_NOT_FOUND
			ERROR_SERVICE_NOT_FOUND
#	else
			0x4DB
#	endif
		// The specified service does not exist.

	, NOT_AUTHENTICATED =
#	if defined ERROR_NOT_AUTHENTICATED
			ERROR_NOT_AUTHENTICATED
#	else
			0x4DC
#	endif
		// The operation being requested was not performed because the user has not been authenticated.

	, NOT_LOGGED_ON =
#	if defined ERROR_NOT_LOGGED_ON
			ERROR_NOT_LOGGED_ON
#	else
			0x4DD
#	endif
		// The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.

	, CONTINUE =
#	if defined ERROR_CONTINUE
			ERROR_CONTINUE
#	else
			0x4DE
#	endif
		// Continue with work in progress.

	, ALREADY_INITIALIZED =
#	if defined ERROR_ALREADY_INITIALIZED
			ERROR_ALREADY_INITIALIZED
#	else
			0x4DF
#	endif
		// An attempt was made to perform an initialization operation when initialization has already been completed.

	, NO_MORE_DEVICES =
#	if defined ERROR_NO_MORE_DEVICES
			ERROR_NO_MORE_DEVICES
#	else
			0x4E0
#	endif
		// No more local devices.

	, NO_SUCH_SITE =
#	if defined ERROR_NO_SUCH_SITE
			ERROR_NO_SUCH_SITE
#	else
			0x4E1
#	endif
		// The specified site does not exist.

	, DOMAIN_CONTROLLER_EXISTS =
#	if defined ERROR_DOMAIN_CONTROLLER_EXISTS
			ERROR_DOMAIN_CONTROLLER_EXISTS
#	else
			0x4E2
#	endif
		// A domain controller with the specified name already exists.

	, ONLY_IF_CONNECTED =
#	if defined ERROR_ONLY_IF_CONNECTED
			ERROR_ONLY_IF_CONNECTED
#	else
			0x4E3
#	endif
		// This operation is supported only when you are connected to the server.

	, OVERRIDE_NOCHANGES =
#	if defined ERROR_OVERRIDE_NOCHANGES
			ERROR_OVERRIDE_NOCHANGES
#	else
			0x4E4
#	endif
		// The group policy framework should call the extension even if there are no changes.

	, BAD_USER_PROFILE =
#	if defined ERROR_BAD_USER_PROFILE
			ERROR_BAD_USER_PROFILE
#	else
			0x4E5
#	endif
		// The specified user does not have a valid profile.

	, NOT_SUPPORTED_ON_SBS =
#	if defined ERROR_NOT_SUPPORTED_ON_SBS
			ERROR_NOT_SUPPORTED_ON_SBS
#	else
			0x4E6
#	endif
		// This operation is not supported on a computer running Windows Server 2003 for Small Business Server.

	, SERVER_SHUTDOWN_IN_PROGRESS =
#	if defined ERROR_SERVER_SHUTDOWN_IN_PROGRESS
			ERROR_SERVER_SHUTDOWN_IN_PROGRESS
#	else
			0x4E7
#	endif
		// The server machine is shutting down.

	, HOST_DOWN =
#	if defined ERROR_HOST_DOWN
			ERROR_HOST_DOWN
#	else
			0x4E8
#	endif
		// The remote system is not available. For information about network troubleshooting, see Windows Help.

	, NON_ACCOUNT_SID =
#	if defined ERROR_NON_ACCOUNT_SID
			ERROR_NON_ACCOUNT_SID
#	else
			0x4E9
#	endif
		// The security identifier provided is not from an account domain.

	, NON_DOMAIN_SID =
#	if defined ERROR_NON_DOMAIN_SID
			ERROR_NON_DOMAIN_SID
#	else
			0x4EA
#	endif
		// The security identifier provided does not have a domain component.

	, APPHELP_BLOCK =
#	if defined ERROR_APPHELP_BLOCK
			ERROR_APPHELP_BLOCK
#	else
			0x4EB
#	endif
		// AppHelp dialog canceled thus preventing the application from starting.

	, ACCESS_DISABLED_BY_POLICY =
#	if defined ERROR_ACCESS_DISABLED_BY_POLICY
			ERROR_ACCESS_DISABLED_BY_POLICY
#	else
			0x4EC
#	endif
		// This program is blocked by group policy. For more information, contact your system administrator.

	, REG_NAT_CONSUMPTION =
#	if defined ERROR_REG_NAT_CONSUMPTION
			ERROR_REG_NAT_CONSUMPTION
#	else
			0x4ED
#	endif
		// A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.

	, CSCSHARE_OFFLINE =
#	if defined ERROR_CSCSHARE_OFFLINE
			ERROR_CSCSHARE_OFFLINE
#	else
			0x4EE
#	endif
		// The share is currently offline or does not exist.

	, PKINIT_FAILURE =
#	if defined ERROR_PKINIT_FAILURE
			ERROR_PKINIT_FAILURE
#	else
			0x4EF
#	endif
		// The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.

	, SMARTCARD_SUBSYSTEM_FAILURE =
#	if defined ERROR_SMARTCARD_SUBSYSTEM_FAILURE
			ERROR_SMARTCARD_SUBSYSTEM_FAILURE
#	else
			0x4F0
#	endif
		// The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.

	, DOWNGRADE_DETECTED =
#	if defined ERROR_DOWNGRADE_DETECTED
			ERROR_DOWNGRADE_DETECTED
#	else
			0x4F1
#	endif
		// The system cannot contact a domain controller to service the authentication request. Please try again later.

	, MACHINE_LOCKED =
#	if defined ERROR_MACHINE_LOCKED
			ERROR_MACHINE_LOCKED
#	else
			0x4F7
#	endif
		// The machine is locked and cannot be shut down without the force option.

	, CALLBACK_SUPPLIED_INVALID_DATA =
#	if defined ERROR_CALLBACK_SUPPLIED_INVALID_DATA
			ERROR_CALLBACK_SUPPLIED_INVALID_DATA
#	else
			0x4F9
#	endif
		// An application-defined callback gave invalid data when called.

	, SYNC_FOREGROUND_REFRESH_REQUIRED =
#	if defined ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED
			ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED
#	else
			0x4FA
#	endif
		// The group policy framework should call the extension in the synchronous foreground policy refresh.

	, DRIVER_BLOCKED =
#	if defined ERROR_DRIVER_BLOCKED
			ERROR_DRIVER_BLOCKED
#	else
			0x4FB
#	endif
		// This driver has been blocked from loading.

	, INVALID_IMPORT_OF_NON_DLL =
#	if defined ERROR_INVALID_IMPORT_OF_NON_DLL
			ERROR_INVALID_IMPORT_OF_NON_DLL
#	else
			0x4FC
#	endif
		// A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.

	, ACCESS_DISABLED_WEBBLADE =
#	if defined ERROR_ACCESS_DISABLED_WEBBLADE
			ERROR_ACCESS_DISABLED_WEBBLADE
#	else
			0x4FD
#	endif
		// Windows cannot open this program since it has been disabled.

	, ACCESS_DISABLED_WEBBLADE_TAMPER =
#	if defined ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER
			ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER
#	else
			0x4FE
#	endif
		// Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.

	, RECOVERY_FAILURE =
#	if defined ERROR_RECOVERY_FAILURE
			ERROR_RECOVERY_FAILURE
#	else
			0x4FF
#	endif
		// A transaction recover failed.

	, ALREADY_FIBER =
#	if defined ERROR_ALREADY_FIBER
			ERROR_ALREADY_FIBER
#	else
			0x500
#	endif
		// The current thread has already been converted to a fiber.

	, ALREADY_THREAD =
#	if defined ERROR_ALREADY_THREAD
			ERROR_ALREADY_THREAD
#	else
			0x501
#	endif
		// The current thread has already been converted from a fiber.

	, STACK_BUFFER_OVERRUN =
#	if defined ERROR_STACK_BUFFER_OVERRUN
			ERROR_STACK_BUFFER_OVERRUN
#	else
			0x502
#	endif
		// The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.

	, PARAMETER_QUOTA_EXCEEDED =
#	if defined ERROR_PARAMETER_QUOTA_EXCEEDED
			ERROR_PARAMETER_QUOTA_EXCEEDED
#	else
			0x503
#	endif
		// Data present in one of the parameters is more than the function can operate on.

	, DEBUGGER_INACTIVE =
#	if defined ERROR_DEBUGGER_INACTIVE
			ERROR_DEBUGGER_INACTIVE
#	else
			0x504
#	endif
		// An attempt to do an operation on a debug object failed because the object is in the process of being deleted.

	, DELAY_LOAD_FAILED =
#	if defined ERROR_DELAY_LOAD_FAILED
			ERROR_DELAY_LOAD_FAILED
#	else
			0x505
#	endif
		// An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.

	, VDM_DISALLOWED =
#	if defined ERROR_VDM_DISALLOWED
			ERROR_VDM_DISALLOWED
#	else
			0x506
#	endif
		// %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.

	, UNIDENTIFIED_ERROR =
#	if defined ERROR_UNIDENTIFIED_ERROR
			ERROR_UNIDENTIFIED_ERROR
#	else
			0x507
#	endif
		// Insufficient information exists to identify the cause of failure.

	, INVALID_CRUNTIME_PARAMETER =
#	if defined ERROR_INVALID_CRUNTIME_PARAMETER
			ERROR_INVALID_CRUNTIME_PARAMETER
#	else
			0x508
#	endif
		// The parameter passed to a C runtime function is incorrect.

	, BEYOND_VDL =
#	if defined ERROR_BEYOND_VDL
			ERROR_BEYOND_VDL
#	else
			0x509
#	endif
		// The operation occurred beyond the valid data length of the file.

	, INCOMPATIBLE_SERVICE_SID_TYPE =
#	if defined ERROR_INCOMPATIBLE_SERVICE_SID_TYPE
			ERROR_INCOMPATIBLE_SERVICE_SID_TYPE
#	else
			0x50A
#	endif
		// The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service. On Windows Server 2003 and Windows XP, an unrestricted service cannot coexist in the same process with other services. The service with the unrestricted service SID type must be moved to an owned process in order to start this service.

	, DRIVER_PROCESS_TERMINATED =
#	if defined ERROR_DRIVER_PROCESS_TERMINATED
			ERROR_DRIVER_PROCESS_TERMINATED
#	else
			0x50B
#	endif
		// The process hosting the driver for this device has been terminated.

	, IMPLEMENTATION_LIMIT =
#	if defined ERROR_IMPLEMENTATION_LIMIT
			ERROR_IMPLEMENTATION_LIMIT
#	else
			0x50C
#	endif
		// An operation attempted to exceed an implementation-defined limit.

	, PROCESS_IS_PROTECTED =
#	if defined ERROR_PROCESS_IS_PROTECTED
			ERROR_PROCESS_IS_PROTECTED
#	else
			0x50D
#	endif
		// Either the target process, or the target thread's containing process, is a protected process.

	, SERVICE_NOTIFY_CLIENT_LAGGING =
#	if defined ERROR_SERVICE_NOTIFY_CLIENT_LAGGING
			ERROR_SERVICE_NOTIFY_CLIENT_LAGGING
#	else
			0x50E
#	endif
		// The service notification client is lagging too far behind the current state of services in the machine.

	, DISK_QUOTA_EXCEEDED =
#	if defined ERROR_DISK_QUOTA_EXCEEDED
			ERROR_DISK_QUOTA_EXCEEDED
#	else
			0x50F
#	endif
		// The requested file operation failed because the storage quota was exceeded. To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.

	, CONTENT_BLOCKED =
#	if defined ERROR_CONTENT_BLOCKED
			ERROR_CONTENT_BLOCKED
#	else
			0x510
#	endif
		// The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.

	, INCOMPATIBLE_SERVICE_PRIVILEGE =
#	if defined ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE
			ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE
#	else
			0x511
#	endif
		// A privilege that the service requires to function properly does not exist in the service account configuration. You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.

	, APP_HANG =
#	if defined ERROR_APP_HANG
			ERROR_APP_HANG
#	else
			0x512
#	endif
		// A thread involved in this operation appears to be unresponsive.

	, INVALID_LABEL =
#	if defined ERROR_INVALID_LABEL
			ERROR_INVALID_LABEL
#	else
			0x513
#	endif
		// Indicates a particular Security ID may not be assigned as the label of an object.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString2(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::STACK_OVERFLOW:
			RETURN_STATIC_STRING(
					"Recursion too deep; the stack overflowed"
			);
		case SystemCode::INVALID_MESSAGE:
			RETURN_STATIC_STRING(
					"The window cannot act on the sent message"
			);
		case SystemCode::CAN_NOT_COMPLETE:
			RETURN_STATIC_STRING(
					"Cannot complete this function"
			);
		case SystemCode::INVALID_FLAGS:
			RETURN_STATIC_STRING(
					"Invalid flags"
			);
		case SystemCode::UNRECOGNIZED_VOLUME:
			RETURN_STATIC_STRING(
					"The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted"
			);
		case SystemCode::FILE_INVALID:
			RETURN_STATIC_STRING(
					"The volume for a file has been externally altered so that the opened file is no longer valid"
			);
		case SystemCode::FULLSCREEN_MODE:
			RETURN_STATIC_STRING(
					"The requested operation cannot be performed in full-screen mode"
			);
		case SystemCode::NO_TOKEN:
			RETURN_STATIC_STRING(
					"An attempt was made to reference a token that does not exist"
			);
		case SystemCode::BADDB:
			RETURN_STATIC_STRING(
					"The configuration registry database is corrupt"
			);
		case SystemCode::BADKEY:
			RETURN_STATIC_STRING(
					"The configuration registry key is invalid"
			);
		case SystemCode::CANTOPEN:
			RETURN_STATIC_STRING(
					"The configuration registry key could not be opened"
			);
		case SystemCode::CANTREAD:
			RETURN_STATIC_STRING(
					"The configuration registry key could not be read"
			);
		case SystemCode::CANTWRITE:
			RETURN_STATIC_STRING(
					"The configuration registry key could not be written"
			);
		case SystemCode::REGISTRY_RECOVERED:
			RETURN_STATIC_STRING(
					"One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful"
			);
		case SystemCode::REGISTRY_CORRUPT:
			RETURN_STATIC_STRING(
					"The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted"
			);
		case SystemCode::REGISTRY_IO_FAILED:
			RETURN_STATIC_STRING(
					"An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry"
			);
		case SystemCode::NOT_REGISTRY_FILE:
			RETURN_STATIC_STRING(
					"The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format"
			);
		case SystemCode::KEY_DELETED:
			RETURN_STATIC_STRING(
					"Illegal operation attempted on a registry key that has been marked for deletion"
			);
		case SystemCode::NO_LOG_SPACE:
			RETURN_STATIC_STRING(
					"System could not allocate the required space in a registry log"
			);
		case SystemCode::KEY_HAS_CHILDREN:
			RETURN_STATIC_STRING(
					"Cannot create a symbolic link in a registry key that already has subkeys or values"
			);
		case SystemCode::CHILD_MUST_BE_VOLATILE:
			RETURN_STATIC_STRING(
					"Cannot create a stable subkey under a volatile parent key"
			);
		case SystemCode::NOTIFY_ENUM_DIR:
			RETURN_STATIC_STRING(
					"A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes"
			);
		case SystemCode::DEPENDENT_SERVICES_RUNNING:
			RETURN_STATIC_STRING(
					"A stop control has been sent to a service that other running services are dependent on"
			);
		case SystemCode::INVALID_SERVICE_CONTROL:
			RETURN_STATIC_STRING(
					"The requested control is not valid for this service"
			);
		case SystemCode::SERVICE_REQUEST_TIMEOUT:
			RETURN_STATIC_STRING(
					"The service did not respond to the start or control request in a timely fashion"
			);
		case SystemCode::SERVICE_NO_THREAD:
			RETURN_STATIC_STRING(
					"A thread could not be created for the service"
			);
		case SystemCode::SERVICE_DATABASE_LOCKED:
			RETURN_STATIC_STRING(
					"The service database is locked"
			);
		case SystemCode::SERVICE_ALREADY_RUNNING:
			RETURN_STATIC_STRING(
					"An instance of the service is already running"
			);
		case SystemCode::INVALID_SERVICE_ACCOUNT:
			RETURN_STATIC_STRING(
					"The account name is invalid or does not exist, or the password is invalid for the account name specified"
			);
		case SystemCode::SERVICE_IS_DISABLED:
			RETURN_STATIC_STRING(
					"The service cannot be started, either because it is disabled or because it has no enabled devices associated with it"
			);
		case SystemCode::CIRCULAR_DEPENDENCY:
			RETURN_STATIC_STRING(
					"Circular service dependency was specified"
			);
		case SystemCode::SERVICE_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"The specified service does not exist as an installed service"
			);
		case SystemCode::SERVICE_CANNOT_ACCEPT_CTRL:
			RETURN_STATIC_STRING(
					"The service cannot accept control messages at this time"
			);
		case SystemCode::SERVICE_NOT_ACTIVE:
			RETURN_STATIC_STRING(
					"The service has not been started"
			);
		case SystemCode::FAILED_SERVICE_CONTROLLER_CONNECT:
			RETURN_STATIC_STRING(
					"The service process could not connect to the service controller"
			);
		case SystemCode::EXCEPTION_IN_SERVICE:
			RETURN_STATIC_STRING(
					"An exception occurred in the service when handling the control request"
			);
		case SystemCode::DATABASE_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"The database specified does not exist"
			);
		case SystemCode::SERVICE_SPECIFIC_ERROR:
			RETURN_STATIC_STRING(
					"The service has returned a service-specific error code"
			);
		case SystemCode::PROCESS_ABORTED:
			RETURN_STATIC_STRING(
					"The process terminated unexpectedly"
			);
		case SystemCode::SERVICE_DEPENDENCY_FAIL:
			RETURN_STATIC_STRING(
					"The dependency service or group failed to start"
			);
		case SystemCode::SERVICE_LOGON_FAILED:
			RETURN_STATIC_STRING(
					"The service did not start due to a logon failure"
			);
		case SystemCode::SERVICE_START_HANG:
			RETURN_STATIC_STRING(
					"After starting, the service hung in a start-pending state"
			);
		case SystemCode::INVALID_SERVICE_LOCK:
			RETURN_STATIC_STRING(
					"The specified service database lock is invalid"
			);
		case SystemCode::SERVICE_MARKED_FOR_DELETE:
			RETURN_STATIC_STRING(
					"The specified service has been marked for deletion"
			);
		case SystemCode::SERVICE_EXISTS:
			RETURN_STATIC_STRING(
					"The specified service already exists"
			);
		case SystemCode::ALREADY_RUNNING_LKG:
			RETURN_STATIC_STRING(
					"The system is currently running with the last-known-good configuration"
			);
		case SystemCode::SERVICE_DEPENDENCY_DELETED:
			RETURN_STATIC_STRING(
					"The dependency service does not exist or has been marked for deletion"
			);
		case SystemCode::BOOT_ALREADY_ACCEPTED:
			RETURN_STATIC_STRING(
					"The current boot has already been accepted for use as the last-known-good control set"
			);
		case SystemCode::SERVICE_NEVER_STARTED:
			RETURN_STATIC_STRING(
					"No attempts to start the service have been made since the last boot"
			);
		case SystemCode::DUPLICATE_SERVICE_NAME:
			RETURN_STATIC_STRING(
					"The name is already in use as either a service name or a service display name"
			);
		case SystemCode::DIFFERENT_SERVICE_ACCOUNT:
			RETURN_STATIC_STRING(
					"The account specified for this service is different from the account specified for other services running in the same process"
			);
		case SystemCode::CANNOT_DETECT_DRIVER_FAILURE:
			RETURN_STATIC_STRING(
					"Failure actions can only be set for Win32 services, not for drivers"
			);
		case SystemCode::CANNOT_DETECT_PROCESS_ABORT:
			RETURN_STATIC_STRING(
					"This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly"
			);
		case SystemCode::NO_RECOVERY_PROGRAM:
			RETURN_STATIC_STRING(
					"No recovery program has been configured for this service"
			);
		case SystemCode::SERVICE_NOT_IN_EXE:
			RETURN_STATIC_STRING(
					"The executable program that this service is configured to run in does not implement the service"
			);
		case SystemCode::NOT_SAFEBOOT_SERVICE:
			RETURN_STATIC_STRING(
					"This service cannot be started in Safe Mode"
			);
		case SystemCode::END_OF_MEDIA:
			RETURN_STATIC_STRING(
					"The physical end of the tape has been reached"
			);
		case SystemCode::FILEMARK_DETECTED:
			RETURN_STATIC_STRING(
					"A tape access reached a filemark"
			);
		case SystemCode::BEGINNING_OF_MEDIA:
			RETURN_STATIC_STRING(
					"The beginning of the tape or a partition was encountered"
			);
		case SystemCode::SETMARK_DETECTED:
			RETURN_STATIC_STRING(
					"A tape access reached the end of a set of files"
			);
		case SystemCode::NO_DATA_DETECTED:
			RETURN_STATIC_STRING(
					"No more data is on the tape"
			);
		case SystemCode::PARTITION_FAILURE:
			RETURN_STATIC_STRING(
					"Tape could not be partitioned"
			);
		case SystemCode::INVALID_BLOCK_LENGTH:
			RETURN_STATIC_STRING(
					"When accessing a new tape of a multivolume partition, the current block size is incorrect"
			);
		case SystemCode::DEVICE_NOT_PARTITIONED:
			RETURN_STATIC_STRING(
					"Tape partition information could not be found when loading a tape"
			);
		case SystemCode::UNABLE_TO_LOCK_MEDIA:
			RETURN_STATIC_STRING(
					"Unable to lock the media eject mechanism"
			);
		case SystemCode::UNABLE_TO_UNLOAD_MEDIA:
			RETURN_STATIC_STRING(
					"Unable to unload the media"
			);
		case SystemCode::MEDIA_CHANGED:
			RETURN_STATIC_STRING(
					"The media in the drive may have changed"
			);
		case SystemCode::BUS_RESET:
			RETURN_STATIC_STRING(
					"The I/O bus was reset"
			);
		case SystemCode::NO_MEDIA_IN_DRIVE:
			RETURN_STATIC_STRING(
					"No media in drive"
			);
		case SystemCode::NO_UNICODE_TRANSLATION:
			RETURN_STATIC_STRING(
					"No mapping for the Unicode character exists in the target multi-byte code page"
			);
		case SystemCode::DLL_INIT_FAILED:
			RETURN_STATIC_STRING(
					"A dynamic link library (DLL) initialization routine failed"
			);
		case SystemCode::SHUTDOWN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A system shutdown is in progress"
			);
		case SystemCode::NO_SHUTDOWN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Unable to abort the system shutdown because no shutdown was in progress"
			);
		case SystemCode::IO_DEVICE:
			RETURN_STATIC_STRING(
					"The request could not be performed because of an I/O device error"
			);
		case SystemCode::SERIAL_NO_DEVICE:
			RETURN_STATIC_STRING(
					"No serial device was successfully initialized. The serial driver will unload"
			);
		case SystemCode::IRQ_BUSY:
			RETURN_STATIC_STRING(
					"Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened"
			);
		case SystemCode::MORE_WRITES:
			RETURN_STATIC_STRING(
					"A serial I/O operation was completed by another write to the serial port. The IOCTL_SERIAL_XOFF_COUNTER reached zero."
			);
		case SystemCode::COUNTER_TIMEOUT:
			RETURN_STATIC_STRING(
					"A serial I/O operation completed because the timeout period expired. The IOCTL_SERIAL_XOFF_COUNTER did not reach zero."
			);
		case SystemCode::FLOPPY_ID_MARK_NOT_FOUND:
			RETURN_STATIC_STRING(
					"No ID address mark was found on the floppy disk"
			);
		case SystemCode::FLOPPY_WRONG_CYLINDER:
			RETURN_STATIC_STRING(
					"Mismatch between the floppy disk sector ID field and the floppy disk controller track address"
			);
		case SystemCode::FLOPPY_UNKNOWN_ERROR:
			RETURN_STATIC_STRING(
					"The floppy disk controller reported an error that is not recognized by the floppy disk driver"
			);
		case SystemCode::FLOPPY_BAD_REGISTERS:
			RETURN_STATIC_STRING(
					"The floppy disk controller returned inconsistent results in its registers"
			);
		case SystemCode::DISK_RECALIBRATE_FAILED:
			RETURN_STATIC_STRING(
					"While accessing the hard disk, a recalibrate operation failed, even after retries"
			);
		case SystemCode::DISK_OPERATION_FAILED:
			RETURN_STATIC_STRING(
					"While accessing the hard disk, a disk operation failed even after retries"
			);
		case SystemCode::DISK_RESET_FAILED:
			RETURN_STATIC_STRING(
					"While accessing the hard disk, a disk controller reset was needed, but even that failed"
			);
		case SystemCode::EOM_OVERFLOW:
			RETURN_STATIC_STRING(
					"Physical end of tape encountered"
			);
		case SystemCode::NOT_ENOUGH_SERVER_MEMORY:
			RETURN_STATIC_STRING(
					"Not enough server storage is available to process this command"
			);
		case SystemCode::POSSIBLE_DEADLOCK:
			RETURN_STATIC_STRING(
					"A potential deadlock condition has been detected"
			);
		case SystemCode::MAPPED_ALIGNMENT:
			RETURN_STATIC_STRING(
					"The base address or the file offset specified does not have the proper alignment"
			);
		case SystemCode::SET_POWER_STATE_VETOED:
			RETURN_STATIC_STRING(
					"An attempt to change the system power state was vetoed by another application or driver"
			);
		case SystemCode::SET_POWER_STATE_FAILED:
			RETURN_STATIC_STRING(
					"The system BIOS failed an attempt to change the system power state"
			);
		case SystemCode::TOO_MANY_LINKS:
			RETURN_STATIC_STRING(
					"An attempt was made to create more links on a file than the file system supports"
			);
		case SystemCode::OLD_WIN_VERSION:
			RETURN_STATIC_STRING(
					"The specified program requires a newer version of Windows"
			);
		case SystemCode::APP_WRONG_OS:
			RETURN_STATIC_STRING(
					"The specified program is not a Windows or MS-DOS program"
			);
		case SystemCode::SINGLE_INSTANCE_APP:
			RETURN_STATIC_STRING(
					"Cannot start more than one instance of the specified program"
			);
		case SystemCode::RMODE_APP:
			RETURN_STATIC_STRING(
					"The specified program was written for an earlier version of Windows"
			);
		case SystemCode::INVALID_DLL:
			RETURN_STATIC_STRING(
					"One of the library files needed to run this application is damaged"
			);
		case SystemCode::NO_ASSOCIATION:
			RETURN_STATIC_STRING(
					"No application is associated with the specified file for this operation"
			);
		case SystemCode::DDE_FAIL:
			RETURN_STATIC_STRING(
					"An error occurred in sending the command to the application"
			);
		case SystemCode::DLL_NOT_FOUND:
			RETURN_STATIC_STRING(
					"One of the library files needed to run this application cannot be found"
			);
		case SystemCode::NO_MORE_USER_HANDLES:
			RETURN_STATIC_STRING(
					"The current process has used all of its system allowance of handles for Window Manager objects"
			);
		case SystemCode::MESSAGE_SYNC_ONLY:
			RETURN_STATIC_STRING(
					"The message can be used only with synchronous operations"
			);
		case SystemCode::SOURCE_ELEMENT_EMPTY:
			RETURN_STATIC_STRING(
					"The indicated source element has no media"
			);
		case SystemCode::DESTINATION_ELEMENT_FULL:
			RETURN_STATIC_STRING(
					"The indicated destination element already contains media"
			);
		case SystemCode::ILLEGAL_ELEMENT_ADDRESS:
			RETURN_STATIC_STRING(
					"The indicated element does not exist"
			);
		case SystemCode::MAGAZINE_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"The indicated element is part of a magazine that is not present"
			);
		case SystemCode::DEVICE_REINITIALIZATION_NEEDED:
			RETURN_STATIC_STRING(
					"The indicated device requires reinitialization due to hardware errors"
			);
		case SystemCode::DEVICE_REQUIRES_CLEANING:
			RETURN_STATIC_STRING(
					"The device has indicated that cleaning is required before further operations are attempted"
			);
		case SystemCode::DEVICE_DOOR_OPEN:
			RETURN_STATIC_STRING(
					"The device has indicated that its door is open"
			);
		case SystemCode::DEVICE_NOT_CONNECTED:
			RETURN_STATIC_STRING(
					"The device is not connected"
			);
		case SystemCode::NOT_FOUND:
			RETURN_STATIC_STRING(
					"Element not found"
			);
		case SystemCode::NO_MATCH:
			RETURN_STATIC_STRING(
					"There was no match for the specified key in the index"
			);
		case SystemCode::SET_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The property set specified does not exist on the object"
			);
		case SystemCode::POINT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The point passed to GetMouseMovePoints is not in the buffer"
			);
		case SystemCode::NO_TRACKING_SERVICE:
			RETURN_STATIC_STRING(
					"The tracking (workstation) service is not running"
			);
		case SystemCode::NO_VOLUME_ID:
			RETURN_STATIC_STRING(
					"The Volume ID could not be found"
			);
		case SystemCode::UNABLE_TO_REMOVE_REPLACED:
			RETURN_STATIC_STRING(
					"Unable to remove the file to be replaced"
			);
		case SystemCode::UNABLE_TO_MOVE_REPLACEMENT:
			RETURN_STATIC_STRING(
					"Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name"
			);
		case SystemCode::UNABLE_TO_MOVE_REPLACEMENT_2:
			RETURN_STATIC_STRING(
					"Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name"
			);
		case SystemCode::JOURNAL_DELETE_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The volume change journal is being deleted"
			);
		case SystemCode::JOURNAL_NOT_ACTIVE:
			RETURN_STATIC_STRING(
					"The volume change journal is not active"
			);
		case SystemCode::POTENTIAL_FILE_FOUND:
			RETURN_STATIC_STRING(
					"A file was found, but it may not be the correct file"
			);
		case SystemCode::JOURNAL_ENTRY_DELETED:
			RETURN_STATIC_STRING(
					"The journal entry has been deleted from the journal"
			);
		case SystemCode::SHUTDOWN_IS_SCHEDULED:
			RETURN_STATIC_STRING(
					"A system shutdown has already been scheduled"
			);
		case SystemCode::SHUTDOWN_USERS_LOGGED_ON:
			RETURN_STATIC_STRING(
					"The system shutdown cannot be initiated because there are other users logged on to the computer"
			);
		case SystemCode::BAD_DEVICE:
			RETURN_STATIC_STRING(
					"The specified device name is invalid"
			);
		case SystemCode::CONNECTION_UNAVAIL:
			RETURN_STATIC_STRING(
					"The device is not currently connected but it is a remembered connection"
			);
		case SystemCode::DEVICE_ALREADY_REMEMBERED:
			RETURN_STATIC_STRING(
					"The local device name has a remembered connection to another network resource"
			);
		case SystemCode::NO_NET_OR_BAD_PATH:
			RETURN_STATIC_STRING(
					"The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator"
			);
		case SystemCode::BAD_PROVIDER:
			RETURN_STATIC_STRING(
					"The specified network provider name is invalid"
			);
		case SystemCode::CANNOT_OPEN_PROFILE:
			RETURN_STATIC_STRING(
					"Unable to open the network connection profile"
			);
		case SystemCode::BAD_PROFILE:
			RETURN_STATIC_STRING(
					"The network connection profile is corrupted"
			);
		case SystemCode::NOT_CONTAINER:
			RETURN_STATIC_STRING(
					"Cannot enumerate a noncontainer"
			);
		case SystemCode::EXTENDED_ERROR:
			RETURN_STATIC_STRING(
					"An extended error has occurred"
			);
		case SystemCode::INVALID_GROUPNAME:
			RETURN_STATIC_STRING(
					"The format of the specified group name is invalid"
			);
		case SystemCode::INVALID_COMPUTERNAME:
			RETURN_STATIC_STRING(
					"The format of the specified computer name is invalid"
			);
		case SystemCode::INVALID_EVENTNAME:
			RETURN_STATIC_STRING(
					"The format of the specified event name is invalid"
			);
		case SystemCode::INVALID_DOMAINNAME:
			RETURN_STATIC_STRING(
					"The format of the specified domain name is invalid"
			);
		case SystemCode::INVALID_SERVICENAME:
			RETURN_STATIC_STRING(
					"The format of the specified service name is invalid"
			);
		case SystemCode::INVALID_NETNAME:
			RETURN_STATIC_STRING(
					"The format of the specified network name is invalid"
			);
		case SystemCode::INVALID_SHARENAME:
			RETURN_STATIC_STRING(
					"The format of the specified share name is invalid"
			);
		case SystemCode::INVALID_PASSWORDNAME:
			RETURN_STATIC_STRING(
					"The format of the specified password is invalid"
			);
		case SystemCode::INVALID_MESSAGENAME:
			RETURN_STATIC_STRING(
					"The format of the specified message name is invalid"
			);
		case SystemCode::INVALID_MESSAGEDEST:
			RETURN_STATIC_STRING(
					"The format of the specified message destination is invalid"
			);
		case SystemCode::SESSION_CREDENTIAL_CONFLICT:
			RETURN_STATIC_STRING(
					"Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again"
			);
		case SystemCode::REMOTE_SESSION_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"An attempt was made to establish a session to a network server, but there are already too many sessions established to that server"
			);
		case SystemCode::DUP_DOMAINNAME:
			RETURN_STATIC_STRING(
					"The workgroup or domain name is already in use by another computer on the network"
			);
		case SystemCode::NO_NETWORK:
			RETURN_STATIC_STRING(
					"The network is not present or not started"
			);
		case SystemCode::CANCELLED:
			RETURN_STATIC_STRING(
					"The operation was canceled by the user"
			);
		case SystemCode::USER_MAPPED_FILE:
			RETURN_STATIC_STRING(
					"The requested operation cannot be performed on a file with a user-mapped section open"
			);
		case SystemCode::CONNECTION_REFUSED:
			RETURN_STATIC_STRING(
					"The remote computer refused the network connection"
			);
		case SystemCode::GRACEFUL_DISCONNECT:
			RETURN_STATIC_STRING(
					"The network connection was gracefully closed"
			);
		case SystemCode::ADDRESS_ALREADY_ASSOCIATED:
			RETURN_STATIC_STRING(
					"The network transport endpoint already has an address associated with it"
			);
		case SystemCode::ADDRESS_NOT_ASSOCIATED:
			RETURN_STATIC_STRING(
					"An address has not yet been associated with the network endpoint"
			);
		case SystemCode::CONNECTION_INVALID:
			RETURN_STATIC_STRING(
					"An operation was attempted on a nonexistent network connection"
			);
		case SystemCode::CONNECTION_ACTIVE:
			RETURN_STATIC_STRING(
					"An invalid operation was attempted on an active network connection"
			);
		case SystemCode::NETWORK_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The network location cannot be reached. For information about network troubleshooting, see Windows Help"
			);
		case SystemCode::HOST_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The network location cannot be reached. For information about network troubleshooting, see Windows Help"
			);
		case SystemCode::PROTOCOL_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The network location cannot be reached. For information about network troubleshooting, see Windows Help"
			);
		case SystemCode::PORT_UNREACHABLE:
			RETURN_STATIC_STRING(
					"No service is operating at the destination network endpoint on the remote system"
			);
		case SystemCode::REQUEST_ABORTED:
			RETURN_STATIC_STRING(
					"The request was aborted"
			);
		case SystemCode::CONNECTION_ABORTED:
			RETURN_STATIC_STRING(
					"The network connection was aborted by the local system"
			);
		case SystemCode::RETRY:
			RETURN_STATIC_STRING(
					"The operation could not be completed. A retry should be performed"
			);
		case SystemCode::CONNECTION_COUNT_LIMIT:
			RETURN_STATIC_STRING(
					"A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached"
			);
		case SystemCode::LOGIN_TIME_RESTRICTION:
			RETURN_STATIC_STRING(
					"Attempting to log in during an unauthorized time of day for this account"
			);
		case SystemCode::LOGIN_WKSTA_RESTRICTION:
			RETURN_STATIC_STRING(
					"The account is not authorized to log in from this station"
			);
		case SystemCode::INCORRECT_ADDRESS:
			RETURN_STATIC_STRING(
					"The network address could not be used for the operation requested"
			);
		case SystemCode::ALREADY_REGISTERED:
			RETURN_STATIC_STRING(
					"The service is already registered"
			);
		case SystemCode::SERVICE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified service does not exist"
			);
		case SystemCode::NOT_AUTHENTICATED:
			RETURN_STATIC_STRING(
					"The operation being requested was not performed because the user has not been authenticated"
			);
		case SystemCode::NOT_LOGGED_ON:
			RETURN_STATIC_STRING(
					"The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist"
			);
		case SystemCode::CONTINUE:
			RETURN_STATIC_STRING(
					"Continue with work in progress"
			);
		case SystemCode::ALREADY_INITIALIZED:
			RETURN_STATIC_STRING(
					"An attempt was made to perform an initialization operation when initialization has already been completed"
			);
		case SystemCode::NO_MORE_DEVICES:
			RETURN_STATIC_STRING(
					"No more local devices"
			);
		case SystemCode::NO_SUCH_SITE:
			RETURN_STATIC_STRING(
					"The specified site does not exist"
			);
		case SystemCode::DOMAIN_CONTROLLER_EXISTS:
			RETURN_STATIC_STRING(
					"A domain controller with the specified name already exists"
			);
		case SystemCode::ONLY_IF_CONNECTED:
			RETURN_STATIC_STRING(
					"This operation is supported only when you are connected to the server"
			);
		case SystemCode::OVERRIDE_NOCHANGES:
			RETURN_STATIC_STRING(
					"The group policy framework should call the extension even if there are no changes"
			);
		case SystemCode::BAD_USER_PROFILE:
			RETURN_STATIC_STRING(
					"The specified user does not have a valid profile"
			);
		case SystemCode::NOT_SUPPORTED_ON_SBS:
			RETURN_STATIC_STRING(
					"This operation is not supported on a computer running Windows Server 2003 for Small Business Server"
			);
		case SystemCode::SERVER_SHUTDOWN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The server machine is shutting down"
			);
		case SystemCode::HOST_DOWN:
			RETURN_STATIC_STRING(
					"The remote system is not available. For information about network troubleshooting, see Windows Help"
			);
		case SystemCode::NON_ACCOUNT_SID:
			RETURN_STATIC_STRING(
					"The security identifier provided is not from an account domain"
			);
		case SystemCode::NON_DOMAIN_SID:
			RETURN_STATIC_STRING(
					"The security identifier provided does not have a domain component"
			);
		case SystemCode::APPHELP_BLOCK:
			RETURN_STATIC_STRING(
					"AppHelp dialog canceled thus preventing the application from starting"
			);
		case SystemCode::ACCESS_DISABLED_BY_POLICY:
			RETURN_STATIC_STRING(
					"This program is blocked by group policy. For more information, contact your system administrator"
			);
		case SystemCode::REG_NAT_CONSUMPTION:
			RETURN_STATIC_STRING(
					"A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific"
			);
		case SystemCode::CSCSHARE_OFFLINE:
			RETURN_STATIC_STRING(
					"The share is currently offline or does not exist"
			);
		case SystemCode::PKINIT_FAILURE:
			RETURN_STATIC_STRING(
					"The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log"
			);
		case SystemCode::SMARTCARD_SUBSYSTEM_FAILURE:
			RETURN_STATIC_STRING(
					"The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem"
			);
		case SystemCode::DOWNGRADE_DETECTED:
			RETURN_STATIC_STRING(
					"The system cannot contact a domain controller to service the authentication request. Please try again later"
			);
		case SystemCode::MACHINE_LOCKED:
			RETURN_STATIC_STRING(
					"The machine is locked and cannot be shut down without the force option"
			);
		case SystemCode::CALLBACK_SUPPLIED_INVALID_DATA:
			RETURN_STATIC_STRING(
					"An application-defined callback gave invalid data when called"
			);
		case SystemCode::SYNC_FOREGROUND_REFRESH_REQUIRED:
			RETURN_STATIC_STRING(
					"The group policy framework should call the extension in the synchronous foreground policy refresh"
			);
		case SystemCode::DRIVER_BLOCKED:
			RETURN_STATIC_STRING(
					"This driver has been blocked from loading"
			);
		case SystemCode::INVALID_IMPORT_OF_NON_DLL:
			RETURN_STATIC_STRING(
					"A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image"
			);
		case SystemCode::ACCESS_DISABLED_WEBBLADE:
			RETURN_STATIC_STRING(
					"Windows cannot open this program since it has been disabled"
			);
		case SystemCode::ACCESS_DISABLED_WEBBLADE_TAMPER:
			RETURN_STATIC_STRING(
					"Windows cannot open this program because the license enforcement system has been tampered with or become corrupted"
			);
		case SystemCode::RECOVERY_FAILURE:
			RETURN_STATIC_STRING(
					"A transaction recover failed"
			);
		case SystemCode::ALREADY_FIBER:
			RETURN_STATIC_STRING(
					"The current thread has already been converted to a fiber"
			);
		case SystemCode::ALREADY_THREAD:
			RETURN_STATIC_STRING(
					"The current thread has already been converted from a fiber"
			);
		case SystemCode::STACK_BUFFER_OVERRUN:
			RETURN_STATIC_STRING(
					"The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application"
			);
		case SystemCode::PARAMETER_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"Data present in one of the parameters is more than the function can operate on"
			);
		case SystemCode::DEBUGGER_INACTIVE:
			RETURN_STATIC_STRING(
					"An attempt to do an operation on a debug object failed because the object is in the process of being deleted"
			);
		case SystemCode::DELAY_LOAD_FAILED:
			RETURN_STATIC_STRING(
					"An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed"
			);
		case SystemCode::VDM_DISALLOWED:
			RETURN_STATIC_STRING(
					"%1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator"
			);
		case SystemCode::UNIDENTIFIED_ERROR:
			RETURN_STATIC_STRING(
					"Insufficient information exists to identify the cause of failure"
			);
		case SystemCode::INVALID_CRUNTIME_PARAMETER:
			RETURN_STATIC_STRING(
					"The parameter passed to a C runtime function is incorrect"
			);
		case SystemCode::BEYOND_VDL:
			RETURN_STATIC_STRING(
					"The operation occurred beyond the valid data length of the file"
			);
		case SystemCode::INCOMPATIBLE_SERVICE_SID_TYPE:
			RETURN_STATIC_STRING(
					"The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service. On Windows Server 2003 and Windows XP, an unrestricted service cannot coexist in the same process with other services. The service with the unrestricted service SID type must be moved to an owned process in order to start this service"
			);
		case SystemCode::DRIVER_PROCESS_TERMINATED:
			RETURN_STATIC_STRING(
					"The process hosting the driver for this device has been terminated"
			);
		case SystemCode::IMPLEMENTATION_LIMIT:
			RETURN_STATIC_STRING(
					"An operation attempted to exceed an implementation-defined limit"
			);
		case SystemCode::PROCESS_IS_PROTECTED:
			RETURN_STATIC_STRING(
					"Either the target process, or the target thread's containing process, is a protected process"
			);
		case SystemCode::SERVICE_NOTIFY_CLIENT_LAGGING:
			RETURN_STATIC_STRING(
					"The service notification client is lagging too far behind the current state of services in the machine"
			);
		case SystemCode::DISK_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"The requested file operation failed because the storage quota was exceeded. To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator"
			);
		case SystemCode::CONTENT_BLOCKED:
			RETURN_STATIC_STRING(
					"The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator"
			);
		case SystemCode::INCOMPATIBLE_SERVICE_PRIVILEGE:
			RETURN_STATIC_STRING(
					"A privilege that the service requires to function properly does not exist in the service account configuration. You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration"
			);
		case SystemCode::APP_HANG:
			RETURN_STATIC_STRING(
					"A thread involved in this operation appears to be unresponsive"
			);
		case SystemCode::INVALID_LABEL:
			RETURN_STATIC_STRING(
					"Indicates a particular Security ID may not be assigned as the label of an object"
			);
	}
	return nullptr;
}

}}} // flame_ide::os::error
