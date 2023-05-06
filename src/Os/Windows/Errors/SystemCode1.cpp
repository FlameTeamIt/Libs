#include <FlameIDE/../../src/Os/Windows/SystemCode1.hpp>

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

// + https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--500-999-
enum class SystemCode: decltype(::GetLastError())
{
	USER_PROFILE_LOAD =
#	if defined ERROR_USER_PROFILE_LOAD
			ERROR_USER_PROFILE_LOAD
#	else
			0x1F4
#	endif
		// User profile cannot be loaded.

	, ARITHMETIC_OVERFLOW =
#	if defined ERROR_ARITHMETIC_OVERFLOW
			ERROR_ARITHMETIC_OVERFLOW
#	else
			0x216
#	endif
		// Arithmetic result exceeded 32 bits.

	, PIPE_CONNECTED =
	#	if defined ERROR_PIPE_CONNECTED
				ERROR_PIPE_CONNECTED
	#	else
				0x217
	#	endif
			// There is a process on other end of the pipe.

	, PIPE_LISTENING =
	#	if defined ERROR_PIPE_LISTENING
				ERROR_PIPE_LISTENING
	#	else
				0x218
	#	endif
			// Waiting for a process to open the other end of the pipe.

	, VERIFIER_STOP =
	#	if defined ERROR_VERIFIER_STOP
				ERROR_VERIFIER_STOP
	#	else
				0x219
	#	endif
			// Application verifier has found an error in the current process.

	, ABIOS_ERROR =
	#	if defined ERROR_ABIOS_ERROR
				ERROR_ABIOS_ERROR
	#	else
				0x21A
	#	endif
			// An error occurred in the ABIOS subsystem.

	, WX86_WARNING =
	#	if defined ERROR_WX86_WARNING
				ERROR_WX86_WARNING
	#	else
				0x21B
	#	endif
			// A warning occurred in the WX86 subsystem.

	, WX86_ERROR =
	#	if defined ERROR_WX86_ERROR
				ERROR_WX86_ERROR
	#	else
				0x21C
	#	endif
			// An error occurred in the WX86 subsystem.

	, TIMER_NOT_CANCELED =
	#	if defined ERROR_TIMER_NOT_CANCELED
				ERROR_TIMER_NOT_CANCELED
	#	else
				0x21D
	#	endif
			// An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.

	, UNWIND =
	#	if defined ERROR_UNWIND
				ERROR_UNWIND
	#	else
				0x21E
	#	endif
			// Unwind exception code.

	, BAD_STACK =
	#	if defined ERROR_BAD_STACK
				ERROR_BAD_STACK
	#	else
				0x21F
	#	endif
			// An invalid or unaligned stack was encountered during an unwind operation.

	, INVALID_UNWIND_TARGET =
	#	if defined ERROR_INVALID_UNWIND_TARGET
				ERROR_INVALID_UNWIND_TARGET
	#	else
				0x220
	#	endif
			// An invalid unwind target was encountered during an unwind operation.

	, INVALID_PORT_ATTRIBUTES =
	#	if defined ERROR_INVALID_PORT_ATTRIBUTES
				ERROR_INVALID_PORT_ATTRIBUTES
	#	else
				0x221
	#	endif
			// Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort

	, PORT_MESSAGE_TOO_LONG =
	#	if defined ERROR_PORT_MESSAGE_TOO_LONG
				ERROR_PORT_MESSAGE_TOO_LONG
	#	else
				0x222
	#	endif
			// Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.

	, INVALID_QUOTA_LOWER =
	#	if defined ERROR_INVALID_QUOTA_LOWER
				ERROR_INVALID_QUOTA_LOWER
	#	else
				0x223
	#	endif
			// An attempt was made to lower a quota limit below the current usage.

	, DEVICE_ALREADY_ATTACHED =
	#	if defined ERROR_DEVICE_ALREADY_ATTACHED
				ERROR_DEVICE_ALREADY_ATTACHED
	#	else
				0x224
	#	endif
			// An attempt was made to attach to a device that was already attached to another device.

	, INSTRUCTION_MISALIGNMENT =
	#	if defined ERROR_INSTRUCTION_MISALIGNMENT
				ERROR_INSTRUCTION_MISALIGNMENT
	#	else
				0x225
	#	endif
			// An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.

	, PROFILING_NOT_STARTED =
	#	if defined ERROR_PROFILING_NOT_STARTED
				ERROR_PROFILING_NOT_STARTED
	#	else
				0x226
	#	endif
			// Profiling not started.

	, PROFILING_NOT_STOPPED =
	#	if defined ERROR_PROFILING_NOT_STOPPED
				ERROR_PROFILING_NOT_STOPPED
	#	else
				0x227
	#	endif
			// Profiling not stopped.

	, COULD_NOT_INTERPRET =
	#	if defined ERROR_COULD_NOT_INTERPRET
				ERROR_COULD_NOT_INTERPRET
	#	else
				0x228
	#	endif
			// The passed ACL did not contain the minimum required information.

	, PROFILING_AT_LIMIT =
	#	if defined ERROR_PROFILING_AT_LIMIT
				ERROR_PROFILING_AT_LIMIT
	#	else
				0x229
	#	endif
			// The number of active profiling objects is at the maximum and no more may be started.

	, CANT_WAIT =
	#	if defined ERROR_CANT_WAIT
				ERROR_CANT_WAIT
	#	else
				0x22A
	#	endif
			// Used to indicate that an operation cannot continue without blocking for I/O.

	, CANT_TERMINATE_SELF =
	#	if defined ERROR_CANT_TERMINATE_SELF
				ERROR_CANT_TERMINATE_SELF
	#	else
				0x22B
	#	endif
			// Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.

	, UNEXPECTED_MM_CREATE_ERR =
	#	if defined ERROR_UNEXPECTED_MM_CREATE_ERR
				ERROR_UNEXPECTED_MM_CREATE_ERR
	#	else
				0x22C
	#	endif
			// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.

	, UNEXPECTED_MM_MAP_ERROR =
	#	if defined ERROR_UNEXPECTED_MM_MAP_ERROR
				ERROR_UNEXPECTED_MM_MAP_ERROR
	#	else
				0x22D
	#	endif
			// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.

	, UNEXPECTED_MM_EXTEND_ERR =
	#	if defined ERROR_UNEXPECTED_MM_EXTEND_ERR
				ERROR_UNEXPECTED_MM_EXTEND_ERR
	#	else
				0x22E
	#	endif
			// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.

	, BAD_FUNCTION_TABLE =
	#	if defined ERROR_BAD_FUNCTION_TABLE
				ERROR_BAD_FUNCTION_TABLE
	#	else
				0x22F
	#	endif
			// A malformed function table was encountered during an unwind operation.

	, NO_GUID_TRANSLATION =
	#	if defined ERROR_NO_GUID_TRANSLATION
				ERROR_NO_GUID_TRANSLATION
	#	else
				0x230
	#	endif
			// Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system. This causes the protection attempt to fail, which may cause a file creation attempt to fail.

	, INVALID_LDT_SIZE =
	#	if defined ERROR_INVALID_LDT_SIZE
				ERROR_INVALID_LDT_SIZE
	#	else
				0x231
	#	endif
			// Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.

	, INVALID_LDT_OFFSET =
	#	if defined ERROR_INVALID_LDT_OFFSET
				ERROR_INVALID_LDT_OFFSET
	#	else
				0x233
	#	endif
			// Indicates that the starting value for the LDT information was not an integral multiple of the selector size.

	, INVALID_LDT_DESCRIPTOR =
	#	if defined ERROR_INVALID_LDT_DESCRIPTOR
				ERROR_INVALID_LDT_DESCRIPTOR
	#	else
				0x234
	#	endif
			// Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.

	, TOO_MANY_THREADS =
	#	if defined ERROR_TOO_MANY_THREADS
				ERROR_TOO_MANY_THREADS
	#	else
				0x235
	#	endif
			// Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.

	, THREAD_NOT_IN_PROCESS =
	#	if defined ERROR_THREAD_NOT_IN_PROCESS
				ERROR_THREAD_NOT_IN_PROCESS
	#	else
				0x236
	#	endif
			// An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.

	, PAGEFILE_QUOTA_EXCEEDED =
	#	if defined ERROR_PAGEFILE_QUOTA_EXCEEDED
				ERROR_PAGEFILE_QUOTA_EXCEEDED
	#	else
				0x237
	#	endif
			// Page file quota was exceeded.

	, LOGON_SERVER_CONFLICT =
	#	if defined ERROR_LOGON_SERVER_CONFLICT
				ERROR_LOGON_SERVER_CONFLICT
	#	else
				0x238
	#	endif
			// The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.

	, SYNCHRONIZATION_REQUIRED =
	#	if defined ERROR_SYNCHRONIZATION_REQUIRED
				ERROR_SYNCHRONIZATION_REQUIRED
	#	else
				0x239
	#	endif
			// The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.

	, NET_OPEN_FAILED =
	#	if defined ERROR_NET_OPEN_FAILED
				ERROR_NET_OPEN_FAILED
	#	else
				0x23A
	#	endif
			// The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.

	, IO_PRIVILEGE_FAILED =
	#	if defined ERROR_IO_PRIVILEGE_FAILED
				ERROR_IO_PRIVILEGE_FAILED
	#	else
				0x23B
	#	endif
			// {Privilege Failed} The I/O permissions for the process could not be changed.

	, CTRL_C_EXIT =
	#	if defined ERROR_CONTROL_C_EXIT
				ERROR_CONTROL_C_EXIT
	#	else
				0x23C
	#	endif
			// {Application Exit by CTRL+C} The application terminated as a result of a CTRL+C.

	, MISSING_SYSTEMFILE =
	#	if defined ERROR_MISSING_SYSTEMFILE
				ERROR_MISSING_SYSTEMFILE
	#	else
				0x23D
	#	endif
			// {Missing System File} The required system file %hs is bad or missing.

	, UNHANDLED_EXCEPTION =
	#	if defined ERROR_UNHANDLED_EXCEPTION
				ERROR_UNHANDLED_EXCEPTION
	#	else
				0x23E
	#	endif
			// {Application Error} The exception %s (0x%08lx) occurred in the application at location 0x%08lx.

	, APP_INIT_FAILURE =
	#	if defined ERROR_APP_INIT_FAILURE
				ERROR_APP_INIT_FAILURE
	#	else
				0x23F
	#	endif
			// {Application Error} The application was unable to start correctly (0x%lx). Click OK to close the application.

	, PAGEFILE_CREATE_FAILED =
	#	if defined ERROR_PAGEFILE_CREATE_FAILED
				ERROR_PAGEFILE_CREATE_FAILED
	#	else
				0x240
	#	endif
			// {Unable to Create Paging File} The creation of the paging file %hs failed (%lx). The requested size was %ld.

	, INVALID_IMAGE_HASH =
	#	if defined ERROR_INVALID_IMAGE_HASH
				ERROR_INVALID_IMAGE_HASH
	#	else
				0x241
	#	endif
			// Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.

	, NO_PAGEFILE =
	#	if defined ERROR_NO_PAGEFILE
				ERROR_NO_PAGEFILE
	#	else
				0x242
	#	endif
			// {No Paging File Specified} No paging file was specified in the system configuration.

	, ILLEGAL_FLOAT_CONTEXT =
	#	if defined ERROR_ILLEGAL_FLOAT_CONTEXT
				ERROR_ILLEGAL_FLOAT_CONTEXT
	#	else
				0x243
	#	endif
			// {EXCEPTION} A real-mode application issued a floating-point instruction and floating-point hardware is not present.

	, NO_EVENT_PAIR =
	#	if defined ERROR_NO_EVENT_PAIR
				ERROR_NO_EVENT_PAIR
	#	else
				0x244
	#	endif
			// An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.

	, DOMAIN_CTRLR_CONFIG_ERROR =
	#	if defined ERROR_DOMAIN_CTRLR_CONFIG_ERROR
				ERROR_DOMAIN_CTRLR_CONFIG_ERROR
	#	else
				0x245
	#	endif
			// A Windows Server has an incorrect configuration.

	, ILLEGAL_CHARACTER =
	#	if defined ERROR_ILLEGAL_CHARACTER
				ERROR_ILLEGAL_CHARACTER
	#	else
				0x246
	#	endif
			// An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.

	, UNDEFINED_CHARACTER =
	#	if defined ERROR_UNDEFINED_CHARACTER
				ERROR_UNDEFINED_CHARACTER
	#	else
				0x247
	#	endif
			// The Unicode character is not defined in the Unicode character set installed on the system.

	, FLOPPY_VOLUME =
	#	if defined ERROR_FLOPPY_VOLUME
				ERROR_FLOPPY_VOLUME
	#	else
				0x248
	#	endif
			// The paging file cannot be created on a floppy diskette.

	, BIOS_FAILED_TO_CONNECT_INTERRUPT =
	#	if defined ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT
				ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT
	#	else
				0x249
	#	endif
			// The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.

	, BACKUP_CONTROLLER =
	#	if defined ERROR_BACKUP_CONTROLLER
				ERROR_BACKUP_CONTROLLER
	#	else
				0x24A
	#	endif
			// This operation is only allowed for the Primary Domain Controller of the domain.

	, MUTANT_LIMIT_EXCEEDED =
	#	if defined ERROR_MUTANT_LIMIT_EXCEEDED
				ERROR_MUTANT_LIMIT_EXCEEDED
	#	else
				0x24B
	#	endif
			// An attempt was made to acquire a mutant such that its maximum count would have been exceeded.

	, FS_DRIVER_REQUIRED =
	#	if defined ERROR_FS_DRIVER_REQUIRED
				ERROR_FS_DRIVER_REQUIRED
	#	else
				0x24C
	#	endif
			// A volume has been accessed for which a file system driver is required that has not yet been loaded.

	, CANNOT_LOAD_REGISTRY_FILE =
	#	if defined ERROR_CANNOT_LOAD_REGISTRY_FILE
				ERROR_CANNOT_LOAD_REGISTRY_FILE
	#	else
				0x24D
	#	endif
			// {Registry File Failure} The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable.

	, DEBUG_ATTACH_FAILED =
	#	if defined ERROR_DEBUG_ATTACH_FAILED
				ERROR_DEBUG_ATTACH_FAILED
	#	else
				0x24E
	#	endif
			// {Unexpected Failure in DebugActiveProcess} An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.

	, SYSTEM_PROCESS_TERMINATED =
	#	if defined ERROR_SYSTEM_PROCESS_TERMINATED
				ERROR_SYSTEM_PROCESS_TERMINATED
	#	else
				0x24F
	#	endif
			// {Fatal System Error} The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down.

	, DATA_NOT_ACCEPTED =
	#	if defined ERROR_DATA_NOT_ACCEPTED
				ERROR_DATA_NOT_ACCEPTED
	#	else
				0x250
	#	endif
			// {Data Not Accepted} The TDI client could not handle the data received during an indication.

	, VDM_HARD_ERROR =
	#	if defined ERROR_VDM_HARD_ERROR
				ERROR_VDM_HARD_ERROR
	#	else
				0x251
	#	endif
			// NTVDM encountered a hard error.

	, DRIVER_CANCEL_TIMEOUT =
	#	if defined ERROR_DRIVER_CANCEL_TIMEOUT
				ERROR_DRIVER_CANCEL_TIMEOUT
	#	else
				0x252
	#	endif
			// {Cancel Timeout} The driver %hs failed to complete a cancelled I/O request in the allotted time.

	, REPLY_MESSAGE_MISMATCH =
	#	if defined ERROR_REPLY_MESSAGE_MISMATCH
				ERROR_REPLY_MESSAGE_MISMATCH
	#	else
				0x253
	#	endif
			// {Reply Message Mismatch} An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.

	, LOST_WRITEBEHIND_DATA =
	#	if defined ERROR_LOST_WRITEBEHIND_DATA
				ERROR_LOST_WRITEBEHIND_DATA
	#	else
				0x254
	#	endif
			// {Delayed Write Failed} Windows was unable to save all the data for the file %hs. The data has been lost. This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.

	, CLIENT_SERVER_PARAMETERS_INVALID =
	#	if defined ERROR_CLIENT_SERVER_PARAMETERS_INVALID
				ERROR_CLIENT_SERVER_PARAMETERS_INVALID
	#	else
				0x255
	#	endif
			// The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.

	, NOT_TINY_STREAM =
	#	if defined ERROR_NOT_TINY_STREAM
				ERROR_NOT_TINY_STREAM
	#	else
				0x256
	#	endif
			// The stream is not a tiny stream.

	, STACK_OVERFLOW_READ =
	#	if defined ERROR_STACK_OVERFLOW_READ
				ERROR_STACK_OVERFLOW_READ
	#	else
				0x257
	#	endif
			// The request must be handled by the stack overflow code.

	, CONVERT_TO_LARGE =
	#	if defined ERROR_CONVERT_TO_LARGE
				ERROR_CONVERT_TO_LARGE
	#	else
				0x258
	#	endif
			// Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.

	, FOUND_OUT_OF_SCOPE =
	#	if defined ERROR_FOUND_OUT_OF_SCOPE
				ERROR_FOUND_OUT_OF_SCOPE
	#	else
				0x259
	#	endif
			// The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.

	, ALLOCATE_BUCKET =
	#	if defined ERROR_ALLOCATE_BUCKET
				ERROR_ALLOCATE_BUCKET
	#	else
				0x25A
	#	endif
			// The bucket array must be grown. Retry transaction after doing so.

	, MARSHALL_OVERFLOW =
	#	if defined ERROR_MARSHALL_OVERFLOW
				ERROR_MARSHALL_OVERFLOW
	#	else
				0x25B
	#	endif
			// The user/kernel marshalling buffer has overflowed.

	, INVALID_VARIANT =
	#	if defined ERROR_INVALID_VARIANT
				ERROR_INVALID_VARIANT
	#	else
				0x25C
	#	endif
			// The supplied variant structure contains invalid data.

	, BAD_COMPRESSION_BUFFER =
	#	if defined ERROR_BAD_COMPRESSION_BUFFER
				ERROR_BAD_COMPRESSION_BUFFER
	#	else
				0x25D
	#	endif
			// The specified buffer contains ill-formed data.

	, AUDIT_FAILED =
	#	if defined ERROR_AUDIT_FAILED
				ERROR_AUDIT_FAILED
	#	else
				0x25E
	#	endif
			// {Audit Failed} An attempt to generate a security audit failed.

	, TIMER_RESOLUTION_NOT_SET =
	#	if defined ERROR_TIMER_RESOLUTION_NOT_SET
				ERROR_TIMER_RESOLUTION_NOT_SET
	#	else
				0x25F
	#	endif
			// The timer resolution was not previously set by the current process.

	, INSUFFICIENT_LOGON_INFO =
	#	if defined ERROR_INSUFFICIENT_LOGON_INFO
				ERROR_INSUFFICIENT_LOGON_INFO
	#	else
				0x260
	#	endif
			// There is insufficient account information to log you on.

	, BAD_DLL_ENTRYPOINT =
	#	if defined ERROR_BAD_DLL_ENTRYPOINT
				ERROR_BAD_DLL_ENTRYPOINT
	#	else
				0x261
	#	endif
			// {Invalid DLL Entrypoint} The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.

	, BAD_SERVICE_ENTRYPOINT =
	#	if defined ERROR_BAD_SERVICE_ENTRYPOINT
				ERROR_BAD_SERVICE_ENTRYPOINT
	#	else
				0x262
	#	endif
			// {Invalid Service Callback Entrypoint} The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.

	, IP_ADDRESS_CONFLICT1 =
	#	if defined ERROR_IP_ADDRESS_CONFLICT1
				ERROR_IP_ADDRESS_CONFLICT1
	#	else
				0x263
	#	endif
			// There is an IP address conflict with another system on the network.

	, IP_ADDRESS_CONFLICT2 =
	#	if defined ERROR_IP_ADDRESS_CONFLICT2
				ERROR_IP_ADDRESS_CONFLICT2
	#	else
				0x264
	#	endif
			// There is an IP address conflict with another system on the network.

	, REGISTRY_QUOTA_LIMIT =
	#	if defined ERROR_REGISTRY_QUOTA_LIMIT
				ERROR_REGISTRY_QUOTA_LIMIT
	#	else
				0x265
	#	endif
			// {Low On Registry Space} The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.

	, NO_CALLBACK_ACTIVE =
	#	if defined ERROR_NO_CALLBACK_ACTIVE
				ERROR_NO_CALLBACK_ACTIVE
	#	else
				0x266
	#	endif
			// A callback return system service cannot be executed when no callback is active.

	, PWD_TOO_SHORT =
	#	if defined ERROR_PWD_TOO_SHORT
				ERROR_PWD_TOO_SHORT
	#	else
				0x267
	#	endif
			// The password provided is too short to meet the policy of your user account. Please choose a longer password.

	, PWD_TOO_RECENT =
	#	if defined ERROR_PWD_TOO_RECENT
				ERROR_PWD_TOO_RECENT
	#	else
				0x268
	#	endif
			// The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.

	, PWD_HISTORY_CONFLICT =
	#	if defined ERROR_PWD_HISTORY_CONFLICT
				ERROR_PWD_HISTORY_CONFLICT
	#	else
				0x269
	#	endif
			// You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Please select a password that you have not previously used.

	, UNSUPPORTED_COMPRESSION =
	#	if defined ERROR_UNSUPPORTED_COMPRESSION
				ERROR_UNSUPPORTED_COMPRESSION
	#	else
				0x26A
	#	endif
			// The specified compression format is unsupported.

	, INVALID_HW_PROFILE =
	#	if defined ERROR_INVALID_HW_PROFILE
				ERROR_INVALID_HW_PROFILE
	#	else
				0x26B
	#	endif
			// The specified hardware profile configuration is invalid.

	, INVALID_PLUGPLAY_DEVICE_PATH =
	#	if defined ERROR_INVALID_PLUGPLAY_DEVICE_PATH
				ERROR_INVALID_PLUGPLAY_DEVICE_PATH
	#	else
				0x26C
	#	endif
			// The specified Plug and Play registry device path is invalid.

	, QUOTA_LIST_INCONSISTENT =
	#	if defined ERROR_QUOTA_LIST_INCONSISTENT
				ERROR_QUOTA_LIST_INCONSISTENT
	#	else
				0x26D
	#	endif
			// The specified quota list is internally inconsistent with its descriptor.

	, EVALUATION_EXPIRATION =
	#	if defined ERROR_EVALUATION_EXPIRATION
				ERROR_EVALUATION_EXPIRATION
	#	else
				0x26E
	#	endif
			// {Windows Evaluation Notification} The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.

	, ILLEGAL_DLL_RELOCATION =
	#	if defined ERROR_ILLEGAL_DLL_RELOCATION
				ERROR_ILLEGAL_DLL_RELOCATION
	#	else
				0x26F
	#	endif
			// {Illegal System DLL Relocation} The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.

	, DLL_INIT_FAILED_LOGOFF =
	#	if defined ERROR_DLL_INIT_FAILED_LOGOFF
				ERROR_DLL_INIT_FAILED_LOGOFF
	#	else
				0x270
	#	endif
			// {DLL Initialization Failed} The application failed to initialize because the window station is shutting down.

	, VALIDATE_CONTINUE =
	#	if defined ERROR_VALIDATE_CONTINUE
				ERROR_VALIDATE_CONTINUE
	#	else
				0x271
	#	endif
			// The validation process needs to continue on to the next step.

	, NO_MORE_MATCHES =
	#	if defined ERROR_NO_MORE_MATCHES
				ERROR_NO_MORE_MATCHES
	#	else
				0x272
	#	endif
			// There are no more matches for the current index enumeration.

	, RANGE_LIST_CONFLICT =
	#	if defined ERROR_RANGE_LIST_CONFLICT
				ERROR_RANGE_LIST_CONFLICT
	#	else
				0x273
	#	endif
			// The range could not be added to the range list because of a conflict.

	, SERVER_SID_MISMATCH =
	#	if defined ERROR_SERVER_SID_MISMATCH
				ERROR_SERVER_SID_MISMATCH
	#	else
				0x274
	#	endif
			// The server process is running under a SID different than that required by client.

	, CANT_ENABLE_DENY_ONLY =
	#	if defined ERROR_CANT_ENABLE_DENY_ONLY
				ERROR_CANT_ENABLE_DENY_ONLY
	#	else
				0x275
	#	endif
			// A group marked use for deny only cannot be enabled.

	, FLOAT_MULTIPLE_FAULTS =
	#	if defined ERROR_FLOAT_MULTIPLE_FAULTS
				ERROR_FLOAT_MULTIPLE_FAULTS
	#	else
				0x276
	#	endif
			// {EXCEPTION} Multiple floating point faults.

	, FLOAT_MULTIPLE_TRAPS =
	#	if defined ERROR_FLOAT_MULTIPLE_TRAPS
				ERROR_FLOAT_MULTIPLE_TRAPS
	#	else
				0x277
	#	endif
			// {EXCEPTION} Multiple floating point traps.

	, NOINTERFACE =
	#	if defined ERROR_NOINTERFACE
				ERROR_NOINTERFACE
	#	else
				0x278
	#	endif
			// The requested interface is not supported.

	, DRIVER_FAILED_SLEEP =
	#	if defined ERROR_DRIVER_FAILED_SLEEP
				ERROR_DRIVER_FAILED_SLEEP
	#	else
				0x279
	#	endif
			// {System Standby Failed} The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.

	, CORRUPT_SYSTEM_FILE =
	#	if defined ERROR_CORRUPT_SYSTEM_FILE
				ERROR_CORRUPT_SYSTEM_FILE
	#	else
				0x27A
	#	endif
			// The system file %1 has become corrupt and has been replaced.

	, COMMITMENT_MINIMUM =
	#	if defined ERROR_COMMITMENT_MINIMUM
				ERROR_COMMITMENT_MINIMUM
	#	else
				0x27B
	#	endif
			// {Virtual Memory Minimum Too Low} Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.

	, PNP_RESTART_ENUMERATION =
	#	if defined ERROR_PNP_RESTART_ENUMERATION
				ERROR_PNP_RESTART_ENUMERATION
	#	else
				0x27C
	#	endif
			// A device was removed so enumeration must be restarted.

	, SYSTEM_IMAGE_BAD_SIGNATURE =
	#	if defined ERROR_SYSTEM_IMAGE_BAD_SIGNATURE
				ERROR_SYSTEM_IMAGE_BAD_SIGNATURE
	#	else
				0x27D
	#	endif
			// {Fatal System Error} The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down.

	, PNP_REBOOT_REQUIRED =
	#	if defined ERROR_PNP_REBOOT_REQUIRED
				ERROR_PNP_REBOOT_REQUIRED
	#	else
				0x27E
	#	endif
			// Device will not start without a reboot.

	, INSUFFICIENT_POWER =
	#	if defined ERROR_INSUFFICIENT_POWER
				ERROR_INSUFFICIENT_POWER
	#	else
				0x27F
	#	endif
			// There is not enough power to complete the requested operation.

	, MULTIPLE_FAULT_VIOLATION =
	#	if defined ERROR_MULTIPLE_FAULT_VIOLATION
				ERROR_MULTIPLE_FAULT_VIOLATION
	#	else
				0x280
	#	endif
			// ERROR_MULTIPLE_FAULT_VIOLATION

	, SYSTEM_SHUTDOWN =
	#	if defined ERROR_SYSTEM_SHUTDOWN
				ERROR_SYSTEM_SHUTDOWN
	#	else
				0x281
	#	endif
			// The system is in the process of shutting down.

	, PORT_NOT_SET =
	#	if defined ERROR_PORT_NOT_SET
				ERROR_PORT_NOT_SET
	#	else
				0x282
	#	endif
			// An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.

	, DS_VERSION_CHECK_FAILURE =
	#	if defined ERROR_DS_VERSION_CHECK_FAILURE
				ERROR_DS_VERSION_CHECK_FAILURE
	#	else
				0x283
	#	endif
			// This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.

	, RANGE_NOT_FOUND =
	#	if defined ERROR_RANGE_NOT_FOUND
				ERROR_RANGE_NOT_FOUND
	#	else
				0x284
	#	endif
			// The specified range could not be found in the range list.

	, NOT_SAFE_MODE_DRIVER =
	#	if defined ERROR_NOT_SAFE_MODE_DRIVER
				ERROR_NOT_SAFE_MODE_DRIVER
	#	else
				0x286
	#	endif
			// The driver was not loaded because the system is booting into safe mode.

	, FAILED_DRIVER_ENTRY =
	#	if defined ERROR_FAILED_DRIVER_ENTRY
				ERROR_FAILED_DRIVER_ENTRY
	#	else
				0x287
	#	endif
			// The driver was not loaded because it failed its initialization call.

	, DEVICE_ENUMERATION_ERROR =
	#	if defined ERROR_DEVICE_ENUMERATION_ERROR
				ERROR_DEVICE_ENUMERATION_ERROR
	#	else
				0x288
	#	endif
			// The "%hs" encountered an error while applying power or reading the device configuration. This may be caused by a failure of your hardware or by a poor connection.

	, MOUNT_POINT_NOT_RESOLVED =
	#	if defined ERROR_MOUNT_POINT_NOT_RESOLVED
				ERROR_MOUNT_POINT_NOT_RESOLVED
	#	else
				0x289
	#	endif
			// The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.

	, INVALID_DEVICE_OBJECT_PARAMETER =
	#	if defined ERROR_INVALID_DEVICE_OBJECT_PARAMETER
				ERROR_INVALID_DEVICE_OBJECT_PARAMETER
	#	else
				0x28A
	#	endif
			// The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.

	, MCA_OCCURED =
	#	if defined ERROR_MCA_OCCURED
				ERROR_MCA_OCCURED
	#	else
				0x28B
	#	endif
			// A Machine Check Error has occurred. Please check the system eventlog for additional information.

	, DRIVER_DATABASE_ERROR =
	#	if defined ERROR_DRIVER_DATABASE_ERROR
				ERROR_DRIVER_DATABASE_ERROR
	#	else
				0x28C
	#	endif
			// There was error [%2] processing the driver database.

	, SYSTEM_HIVE_TOO_LARGE =
	#	if defined ERROR_SYSTEM_HIVE_TOO_LARGE
				ERROR_SYSTEM_HIVE_TOO_LARGE
	#	else
				0x28D
	#	endif
			// System hive size has exceeded its limit.

	, DRIVER_FAILED_PRIOR_UNLOAD =
	#	if defined ERROR_DRIVER_FAILED_PRIOR_UNLOAD
				ERROR_DRIVER_FAILED_PRIOR_UNLOAD
	#	else
				0x28E
	#	endif
			// The driver could not be loaded because a previous version of the driver is still in memory.

	, VOLSNAP_PREPARE_HIBERNATE =
	#	if defined ERROR_VOLSNAP_PREPARE_HIBERNATE
				ERROR_VOLSNAP_PREPARE_HIBERNATE
	#	else
				0x28F
	#	endif
			// {Volume Shadow Copy Service} Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.

	, HIBERNATION_FAILURE =
	#	if defined ERROR_HIBERNATION_FAILURE
				ERROR_HIBERNATION_FAILURE
	#	else
				0x290
	#	endif
			// The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.

	, PWD_TOO_LONG =
	#	if defined ERROR_PWD_TOO_LONG
				ERROR_PWD_TOO_LONG
	#	else
				0x291
	#	endif
			// The password provided is too long to meet the policy of your user account. Please choose a shorter password.

	, FILE_SYSTEM_LIMITATION =
	#	if defined ERROR_FILE_SYSTEM_LIMITATION
				ERROR_FILE_SYSTEM_LIMITATION
	#	else
				0x299
	#	endif
			// The requested operation could not be completed due to a file system limitation.

	, ASSERTION_FAILURE =
	#	if defined ERROR_ASSERTION_FAILURE
				ERROR_ASSERTION_FAILURE
	#	else
				0x29C
	#	endif
			// An assertion failure has occurred.

	, ACPI_ERROR =
	#	if defined ERROR_ACPI_ERROR
				ERROR_ACPI_ERROR
	#	else
				0x29D
	#	endif
			// An error occurred in the ACPI subsystem.

	, WOW_ASSERTION =
	#	if defined ERROR_WOW_ASSERTION
				ERROR_WOW_ASSERTION
	#	else
				0x29E
	#	endif
			// WOW Assertion Error.

	, PNP_BAD_MPS_TABLE =
	#	if defined ERROR_PNP_BAD_MPS_TABLE
				ERROR_PNP_BAD_MPS_TABLE
	#	else
				0x29F
	#	endif
			// A device is missing in the system BIOS MPS table. This device will not be used. Please contact your system vendor for system BIOS update.

	, PNP_TRANSLATION_FAILED =
	#	if defined ERROR_PNP_TRANSLATION_FAILED
				ERROR_PNP_TRANSLATION_FAILED
	#	else
				0x2A0
	#	endif
			// A translator failed to translate resources.

	, PNP_IRQ_TRANSLATION_FAILED =
	#	if defined ERROR_PNP_IRQ_TRANSLATION_FAILED
				ERROR_PNP_IRQ_TRANSLATION_FAILED
	#	else
				0x2A1
	#	endif
			// A IRQ translator failed to translate resources.

	, PNP_INVALID_ID =
	#	if defined ERROR_PNP_INVALID_ID
				ERROR_PNP_INVALID_ID
	#	else
				0x2A2
	#	endif
			// Driver %2 returned invalid ID for a child device (%3).

	, WAKE_SYSTEM_DEBUGGER =
	#	if defined ERROR_WAKE_SYSTEM_DEBUGGER
				ERROR_WAKE_SYSTEM_DEBUGGER
	#	else
				0x2A3
	#	endif
			// {Kernel Debugger Awakened} the system debugger was awakened by an interrupt.

	, HANDLES_CLOSED =
	#	if defined ERROR_HANDLES_CLOSED
				ERROR_HANDLES_CLOSED
	#	else
				0x2A4
	#	endif
			// {Handles Closed} Handles to objects have been automatically closed as a result of the requested operation.

	, EXTRANEOUS_INFORMATION =
	#	if defined ERROR_EXTRANEOUS_INFORMATION
				ERROR_EXTRANEOUS_INFORMATION
	#	else
				0x2A5
	#	endif
			// {Too Much Information} The specified access control list (ACL) contained more information than was expected.

	, RXACT_COMMIT_NECESSARY =
	#	if defined ERROR_RXACT_COMMIT_NECESSARY
				ERROR_RXACT_COMMIT_NECESSARY
	#	else
				0x2A6
	#	endif
			// This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).

	, MEDIA_CHECK =
	#	if defined ERROR_MEDIA_CHECK
				ERROR_MEDIA_CHECK
	#	else
				0x2A7
	#	endif
			// {Media Changed} The media may have changed.

	, GUID_SUBSTITUTION_MADE =
	#	if defined ERROR_GUID_SUBSTITUTION_MADE
				ERROR_GUID_SUBSTITUTION_MADE
	#	else
				0x2A8
	#	endif
			// {GUID Substitution} During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.

	, STOPPED_ON_SYMLINK =
	#	if defined ERROR_STOPPED_ON_SYMLINK
				ERROR_STOPPED_ON_SYMLINK
	#	else
				0x2A9
	#	endif
			// The create operation stopped after reaching a symbolic link.

	, LONGJUMP =
	#	if defined ERROR_LONGJUMP
				ERROR_LONGJUMP
	#	else
				0x2AA
	#	endif
			// A long jump has been executed.

	, PLUGPLAY_QUERY_VETOED =
	#	if defined ERROR_PLUGPLAY_QUERY_VETOED
				ERROR_PLUGPLAY_QUERY_VETOED
	#	else
				0x2AB
	#	endif
			// The Plug and Play query operation was not successful.

	, UNWIND_CONSOLIDATE =
	#	if defined ERROR_UNWIND_CONSOLIDATE
				ERROR_UNWIND_CONSOLIDATE
	#	else
				0x2AC
	#	endif
			// A frame consolidation has been executed.

	, REGISTRY_HIVE_RECOVERED =
	#	if defined ERROR_REGISTRY_HIVE_RECOVERED
				ERROR_REGISTRY_HIVE_RECOVERED
	#	else
				0x2AD
	#	endif
			// {Registry Hive Recovered} Registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost.

	, DLL_MIGHT_BE_INSECURE =
	#	if defined ERROR_DLL_MIGHT_BE_INSECURE
				ERROR_DLL_MIGHT_BE_INSECURE
	#	else
				0x2AE
	#	endif
			// The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?

	, DLL_MIGHT_BE_INCOMPATIBLE =
	#	if defined ERROR_DLL_MIGHT_BE_INCOMPATIBLE
				ERROR_DLL_MIGHT_BE_INCOMPATIBLE
	#	else
				0x2AF
	#	endif
			// The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?

	, DEBUG_EXCEPTION_NOT_HANDLED =
	#	if defined ERROR_DBG_EXCEPTION_NOT_HANDLED
				ERROR_DBG_EXCEPTION_NOT_HANDLED
	#	else
				0x2B0
	#	endif
			// Debugger did not handle the exception.

	, DEBUG_REPLY_LATER =
	#	if defined ERROR_DBG_REPLY_LATER
				ERROR_DBG_REPLY_LATER
	#	else
				0x2B1
	#	endif
			// Debugger will reply later.

	, DEBUG_UNABLE_TO_PROVIDE_HANDLE =
	#	if defined ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE
				ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE
	#	else
				0x2B2
	#	endif
			// Debugger cannot provide handle.

	, DEBUG_TERMINATE_THREAD =
	#	if defined ERROR_DBG_TERMINATE_THREAD
				ERROR_DBG_TERMINATE_THREAD
	#	else
				0x2B3
	#	endif
			// Debugger terminated thread.

	, DEBUG_TERMINATE_PROCESS =
	#	if defined ERROR_DBG_TERMINATE_PROCESS
				ERROR_DBG_TERMINATE_PROCESS
	#	else
				0x2B4
	#	endif
			// Debugger terminated process.

	, DEBUG_CONTROL_C =
	#	if defined ERROR_DBG_CONTROL_C
				ERROR_DBG_CONTROL_C
	#	else
				0x2B5
	#	endif
			// Debugger got control C.

	, DEBUG_PRINTEXCEPTION_C =
	#	if defined ERROR_DBG_PRINTEXCEPTION_C
				ERROR_DBG_PRINTEXCEPTION_C
	#	else
				0x2B6
	#	endif
			// Debugger printed exception on control C.

	, DEBUG_RIPEXCEPTION =
	#	if defined ERROR_DBG_RIPEXCEPTION
				ERROR_DBG_RIPEXCEPTION
	#	else
				0x2B7
	#	endif
			// Debugger received RIP exception.

	, DEBUG_CONTROL_BREAK =
	#	if defined ERROR_DBG_CONTROL_BREAK
				ERROR_DBG_CONTROL_BREAK
	#	else
				0x2B8
	#	endif
			// Debugger received control break.

	, DEBUG_COMMAND_EXCEPTION =
	#	if defined ERROR_DBG_COMMAND_EXCEPTION
				ERROR_DBG_COMMAND_EXCEPTION
	#	else
				0x2B9
	#	endif
			// Debugger command communication exception.

	, OBJECT_NAME_EXISTS =
	#	if defined ERROR_OBJECT_NAME_EXISTS
				ERROR_OBJECT_NAME_EXISTS
	#	else
				0x2BA
	#	endif
			// {Object Exists} An attempt was made to create an object and the object name already existed.

	, THREAD_WAS_SUSPENDED =
	#	if defined ERROR_THREAD_WAS_SUSPENDED
				ERROR_THREAD_WAS_SUSPENDED
	#	else
				0x2BB
	#	endif
			// {Thread Suspended} A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.

	, IMAGE_NOT_AT_BASE =
	#	if defined ERROR_IMAGE_NOT_AT_BASE
				ERROR_IMAGE_NOT_AT_BASE
	#	else
				0x2BC
	#	endif
			// {Image Relocated} An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.

	, RXACT_STATE_CREATED =
	#	if defined ERROR_RXACT_STATE_CREATED
				ERROR_RXACT_STATE_CREATED
	#	else
				0x2BD
	#	endif
			// This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.

	, SEGMENT_NOTIFICATION =
	#	if defined ERROR_SEGMENT_NOTIFICATION
				ERROR_SEGMENT_NOTIFICATION
	#	else
				0x2BE
	#	endif
			// {Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image. An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.

	, BAD_CURRENT_DIRECTORY =
	#	if defined ERROR_BAD_CURRENT_DIRECTORY
				ERROR_BAD_CURRENT_DIRECTORY
	#	else
				0x2BF
	#	endif
			// {Invalid Current Directory} The process cannot switch to the startup current directory %hs. Select OK to set current directory to %hs, or select CANCEL to exit.

	, FT_READ_RECOVERY_FROM_BACKUP =
	#	if defined ERROR_FT_READ_RECOVERY_FROM_BACKUP
				ERROR_FT_READ_RECOVERY_FROM_BACKUP
	#	else
				0x2C0
	#	endif
			// {Redundant Read} To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.

	, FT_WRITE_RECOVERY =
	#	if defined ERROR_FT_WRITE_RECOVERY
				ERROR_FT_WRITE_RECOVERY
	#	else
				0x2C1
	#	endif
			// {Redundant Write} To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.

	, IMAGE_MACHINE_TYPE_MISMATCH =
	#	if defined ERROR_IMAGE_MACHINE_TYPE_MISMATCH
				ERROR_IMAGE_MACHINE_TYPE_MISMATCH
	#	else
				0x2C2
	#	endif
			// {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.

	, RECEIVE_PARTIAL =
	#	if defined ERROR_RECEIVE_PARTIAL
				ERROR_RECEIVE_PARTIAL
	#	else
				0x2C3
	#	endif
			// {Partial Data Received} The network transport returned partial data to its client. The remaining data will be sent later.

	, RECEIVE_EXPEDITED =
	#	if defined ERROR_RECEIVE_EXPEDITED
				ERROR_RECEIVE_EXPEDITED
	#	else
				0x2C4
	#	endif
			// {Expedited Data Received} The network transport returned data to its client that was marked as expedited by the remote system.

	, RECEIVE_PARTIAL_EXPEDITED =
	#	if defined ERROR_RECEIVE_PARTIAL_EXPEDITED
				ERROR_RECEIVE_PARTIAL_EXPEDITED
	#	else
				0x2C5
	#	endif
			// {Partial Expedited Data Received} The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.

	, EVENT_DONE =
	#	if defined ERROR_EVENT_DONE
				ERROR_EVENT_DONE
	#	else
				0x2C6
	#	endif
			// {TDI Event Done} The TDI indication has completed successfully.

	, EVENT_PENDING =
	#	if defined ERROR_EVENT_PENDING
				ERROR_EVENT_PENDING
	#	else
				0x2C7
	#	endif
			// {TDI Event Pending} The TDI indication has entered the pending state.

	, CHECKING_FILE_SYSTEM =
	#	if defined ERROR_CHECKING_FILE_SYSTEM
				ERROR_CHECKING_FILE_SYSTEM
	#	else
				0x2C8
	#	endif
			// Checking file system on %wZ.

	, FATAL_APP_EXIT =
	#	if defined ERROR_FATAL_APP_EXIT
				ERROR_FATAL_APP_EXIT
	#	else
				0x2C9
	#	endif
			// {Fatal Application Exit} %hs.

	, PREDEFINED_HANDLE =
	#	if defined ERROR_PREDEFINED_HANDLE
				ERROR_PREDEFINED_HANDLE
	#	else
				0x2CA
	#	endif
			// The specified registry key is referenced by a predefined handle.

	, WAS_UNLOCKED =
	#	if defined ERROR_WAS_UNLOCKED
				ERROR_WAS_UNLOCKED
	#	else
				0x2CB
	#	endif
			// {Page Unlocked} The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.

	, SERVICE_NOTIFICATION =
	#	if defined ERROR_SERVICE_NOTIFICATION
				ERROR_SERVICE_NOTIFICATION
	#	else
				0x2CC
	#	endif
			// %hs

	, WAS_LOCKED =
	#	if defined ERROR_WAS_LOCKED
				ERROR_WAS_LOCKED
	#	else
				0x2CD
	#	endif
			// {Page Locked} One of the pages to lock was already locked.

	, LOG_HARD_ERROR =
	#	if defined ERROR_LOG_HARD_ERROR
				ERROR_LOG_HARD_ERROR
	#	else
				0x2CE
	#	endif
			// Application popup: %1 : %2

	, ALREADY_WIN32 =
	#	if defined ERROR_ALREADY_WIN32
				ERROR_ALREADY_WIN32
	#	else
				0x2CF
	#	endif
			// ERROR_ALREADY_WIN32

	, IMAGE_MACHINE_TYPE_MISMATCH_EXE =
	#	if defined ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE
				ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE
	#	else
				0x2D0
	#	endif
			// {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine.

	, NO_YIELD_PERFORMED =
	#	if defined ERROR_NO_YIELD_PERFORMED
				ERROR_NO_YIELD_PERFORMED
	#	else
				0x2D1
	#	endif
			// A yield execution was performed and no thread was available to run.

	, TIMER_RESUME_IGNORED =
	#	if defined ERROR_TIMER_RESUME_IGNORED
				ERROR_TIMER_RESUME_IGNORED
	#	else
				0x2D2
	#	endif
			// The resumable flag to a timer API was ignored.

	, ARBITRATION_UNHANDLED =
	#	if defined ERROR_ARBITRATION_UNHANDLED
				ERROR_ARBITRATION_UNHANDLED
	#	else
				0x2D3
	#	endif
			// The arbiter has deferred arbitration of these resources to its parent.

	, CARDBUS_NOT_SUPPORTED =
	#	if defined ERROR_CARDBUS_NOT_SUPPORTED
				ERROR_CARDBUS_NOT_SUPPORTED
	#	else
				0x2D4
	#	endif
			// The inserted CardBus device cannot be started because of a configuration error on "%hs".

	, MP_PROCESSOR_MISMATCH =
	#	if defined ERROR_MP_PROCESSOR_MISMATCH
				ERROR_MP_PROCESSOR_MISMATCH
	#	else
				0x2D5
	#	endif
			// The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.

	, HIBERNATED =
	#	if defined ERROR_HIBERNATED
				ERROR_HIBERNATED
	#	else
				0x2D6
	#	endif
			// The system was put into hibernation.

	, RESUME_HIBERNATION =
	#	if defined ERROR_RESUME_HIBERNATION
				ERROR_RESUME_HIBERNATION
	#	else
				0x2D7
	#	endif
			// The system was resumed from hibernation.

	, FIRMWARE_UPDATED =
	#	if defined ERROR_FIRMWARE_UPDATED
				ERROR_FIRMWARE_UPDATED
	#	else
				0x2D8
	#	endif
			// Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].

	, DRIVERS_LEAKING_LOCKED_PAGES =
	#	if defined ERROR_DRIVERS_LEAKING_LOCKED_PAGES
				ERROR_DRIVERS_LEAKING_LOCKED_PAGES
	#	else
				0x2D9
	#	endif
			// A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.

	, WAKE_SYSTEM =
	#	if defined ERROR_WAKE_SYSTEM
				ERROR_WAKE_SYSTEM
	#	else
				0x2DA
	#	endif
			// The system has awoken.

	, WAIT_1 =
	#	if defined ERROR_WAIT_1
				ERROR_WAIT_1
	#	else
				0x2DB
	#	endif
			// ERROR_WAIT_1

	, WAIT_2 =
	#	if defined ERROR_WAIT_2
				ERROR_WAIT_2
	#	else
				0x2DC
	#	endif
			// ERROR_WAIT_2

	, WAIT_3 =
	#	if defined ERROR_WAIT_3
				ERROR_WAIT_3
	#	else
				0x2DD
	#	endif
			// ERROR_WAIT_3

	, WAIT_63 =
	#	if defined ERROR_WAIT_63
				ERROR_WAIT_63
	#	else
				0x2DE
	#	endif
			// ERROR_WAIT_63

	, ABANDONED_WAIT_0 =
	#	if defined ERROR_ABANDONED_WAIT_0
				ERROR_ABANDONED_WAIT_0
	#	else
				0x2DF
	#	endif
			// ERROR_ABANDONED_WAIT_0

	, ABANDONED_WAIT_63 =
	#	if defined ERROR_ABANDONED_WAIT_63
				ERROR_ABANDONED_WAIT_63
	#	else
				0x2E0
	#	endif
			// ERROR_ABANDONED_WAIT_63

	, USER_APC =
	#	if defined ERROR_USER_APC
				ERROR_USER_APC
	#	else
				0x2E1
	#	endif
			// ERROR_USER_APC

	, KERNEL_APC =
	#	if defined ERROR_KERNEL_APC
				ERROR_KERNEL_APC
	#	else
				0x2E2
	#	endif
			// ERROR_KERNEL_APC

	, ALERTED =
	#	if defined ERROR_ALERTED
				ERROR_ALERTED
	#	else
				0x2E3
	#	endif
			// ERROR_ALERTED

	, ELEVATION_REQUIRED =
	#	if defined ERROR_ELEVATION_REQUIRED
				ERROR_ELEVATION_REQUIRED
	#	else
				0x2E4
	#	endif
			// The requested operation requires elevation.

	, REPARSE =
	#	if defined ERROR_REPARSE
				ERROR_REPARSE
	#	else
				0x2E5
	#	endif
			// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.

	, OPLOCK_BREAK_IN_PROGRESS =
	#	if defined ERROR_OPLOCK_BREAK_IN_PROGRESS
				ERROR_OPLOCK_BREAK_IN_PROGRESS
	#	else
				0x2E6
	#	endif
			// An open/create operation completed while an oplock break is underway.

	, VOLUME_MOUNTED =
	#	if defined ERROR_VOLUME_MOUNTED
				ERROR_VOLUME_MOUNTED
	#	else
				0x2E7
	#	endif
			// A new volume has been mounted by a file system.

	, RXACT_COMMITTED =
	#	if defined ERROR_RXACT_COMMITTED
				ERROR_RXACT_COMMITTED
	#	else
				0x2E8
	#	endif
			// This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.

	, NOTIFY_CLEANUP =
	#	if defined ERROR_NOTIFY_CLEANUP
				ERROR_NOTIFY_CLEANUP
	#	else
				0x2E9
	#	endif
			// This indicates that a notify change request has been completed due to closing the handle which made the notify change request.

	, PRIMARY_TRANSPORT_CONNECT_FAILED =
	#	if defined ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED
				ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED
	#	else
				0x2EA
	#	endif
			// {Connect Failure on Primary Transport} An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed. The computer WAS able to connect on a secondary transport.

	, PAGE_FAULT_TRANSITION =
	#	if defined ERROR_PAGE_FAULT_TRANSITION
				ERROR_PAGE_FAULT_TRANSITION
	#	else
				0x2EB
	#	endif
			// Page fault was a transition fault.

	, PAGE_FAULT_DEMAND_ZERO =
	#	if defined ERROR_PAGE_FAULT_DEMAND_ZERO
				ERROR_PAGE_FAULT_DEMAND_ZERO
	#	else
				0x2EC
	#	endif
			// Page fault was a demand zero fault.

	, PAGE_FAULT_COPY_ON_WRITE =
	#	if defined ERROR_PAGE_FAULT_COPY_ON_WRITE
				ERROR_PAGE_FAULT_COPY_ON_WRITE
	#	else
				0x2ED
	#	endif
			// Page fault was a demand zero fault.

	, PAGE_FAULT_GUARD_PAGE =
	#	if defined ERROR_PAGE_FAULT_GUARD_PAGE
				ERROR_PAGE_FAULT_GUARD_PAGE
	#	else
				0x2EE
	#	endif
			// Page fault was a demand zero fault.

	, PAGE_FAULT_PAGING_FILE =
	#	if defined ERROR_PAGE_FAULT_PAGING_FILE
				ERROR_PAGE_FAULT_PAGING_FILE
	#	else
				0x2EF
	#	endif
			// Page fault was satisfied by reading from a secondary storage device.

	, CACHE_PAGE_LOCKED =
	#	if defined ERROR_CACHE_PAGE_LOCKED
				ERROR_CACHE_PAGE_LOCKED
	#	else
				0x2F0
	#	endif
			// Cached page was locked during operation.

	, CRASH_DUMP =
	#	if defined ERROR_CRASH_DUMP
				ERROR_CRASH_DUMP
	#	else
				0x2F1
	#	endif
			// Crash dump exists in paging file.

	, BUFFER_ALL_ZEROS =
	#	if defined ERROR_BUFFER_ALL_ZEROS
				ERROR_BUFFER_ALL_ZEROS
	#	else
				0x2F2
	#	endif
			// Specified buffer contains all zeros.

	, REPARSE_OBJECT =
	#	if defined ERROR_REPARSE_OBJECT
				ERROR_REPARSE_OBJECT
	#	else
				0x2F3
	#	endif
			// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.

	, RESOURCE_REQUIREMENTS_CHANGED =
	#	if defined ERROR_RESOURCE_REQUIREMENTS_CHANGED
				ERROR_RESOURCE_REQUIREMENTS_CHANGED
	#	else
				0x2F4
	#	endif
			// The device has succeeded a query-stop and its resource requirements have changed.

	, TRANSLATION_COMPLETE =
	#	if defined ERROR_TRANSLATION_COMPLETE
				ERROR_TRANSLATION_COMPLETE
	#	else
				0x2F5
	#	endif
			// The translator has translated these resources into the global space and no further translations should be performed.

	, NOTHING_TO_TERMINATE =
	#	if defined ERROR_NOTHING_TO_TERMINATE
				ERROR_NOTHING_TO_TERMINATE
	#	else
				0x2F6
	#	endif
			// A process being terminated has no threads to terminate.

	, PROCESS_NOT_IN_JOB =
	#	if defined ERROR_PROCESS_NOT_IN_JOB
				ERROR_PROCESS_NOT_IN_JOB
	#	else
				0x2F7
	#	endif
			// The specified process is not part of a job.

	, PROCESS_IN_JOB =
	#	if defined ERROR_PROCESS_IN_JOB
				ERROR_PROCESS_IN_JOB
	#	else
				0x2F8
	#	endif
			// The specified process is part of a job.

	, VOLSNAP_HIBERNATE_READY =
	#	if defined ERROR_VOLSNAP_HIBERNATE_READY
				ERROR_VOLSNAP_HIBERNATE_READY
	#	else
				0x2F9
	#	endif
			// {Volume Shadow Copy Service} The system is now ready for hibernation.

	, FSFILTER_OP_COMPLETED_SUCCESSFULLY =
	#	if defined ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY
				ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY
	#	else
				0x2FA
	#	endif
			// A file system or file system filter driver has successfully completed an FsFilter operation.

	, INTERRUPT_VECTOR_ALREADY_CONNECTED =
	#	if defined ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED
				ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED
	#	else
				0x2FB
	#	endif
			// The specified interrupt vector was already connected.

	, INTERRUPT_STILL_CONNECTED =
	#	if defined ERROR_INTERRUPT_STILL_CONNECTED
				ERROR_INTERRUPT_STILL_CONNECTED
	#	else
				0x2FC
	#	endif
			// The specified interrupt vector is still connected.

	, WAIT_FOR_OPLOCK =
	#	if defined ERROR_WAIT_FOR_OPLOCK
				ERROR_WAIT_FOR_OPLOCK
	#	else
				0x2FD
	#	endif
			// An operation is blocked waiting for an oplock.

	, DEBUG_EXCEPTION_HANDLED =
	#	if defined ERROR_DBG_EXCEPTION_HANDLED
				ERROR_DBG_EXCEPTION_HANDLED
	#	else
				0x2FE
	#	endif
			// Debugger handled exception.

	, DEBUG_CONTINUE =
	#	if defined ERROR_DBG_CONTINUE
				ERROR_DBG_CONTINUE
	#	else
				0x2FF
	#	endif
			// Debugger continued.

	, CALLBACK_POP_STACK =
	#	if defined ERROR_CALLBACK_POP_STACK
				ERROR_CALLBACK_POP_STACK
	#	else
				0x300
	#	endif
			// An exception occurred in a user mode callback and the kernel callback frame should be removed.

	, COMPRESSION_DISABLED =
	#	if defined ERROR_COMPRESSION_DISABLED
				ERROR_COMPRESSION_DISABLED
	#	else
				0x301
	#	endif
			// Compression is disabled for this volume.

	, CANTFETCHBACKWARDS =
	#	if defined ERROR_CANTFETCHBACKWARDS
				ERROR_CANTFETCHBACKWARDS
	#	else
				0x302
	#	endif
			// The data provider cannot fetch backwards through a result set.

	, CANTSCROLLBACKWARDS =
	#	if defined ERROR_CANTSCROLLBACKWARDS
				ERROR_CANTSCROLLBACKWARDS
	#	else
				0x303
	#	endif
			// The data provider cannot scroll backwards through a result set.

	, ROWSNOTRELEASED =
	#	if defined ERROR_ROWSNOTRELEASED
				ERROR_ROWSNOTRELEASED
	#	else
				0x304
	#	endif
			// The data provider requires that previously fetched data is released before asking for more data.

	, BAD_ACCESSOR_FLAGS =
	#	if defined ERROR_BAD_ACCESSOR_FLAGS
				ERROR_BAD_ACCESSOR_FLAGS
	#	else
				0x305
	#	endif
			// The data provider was not able to interpret the flags set for a column binding in an accessor.

	, ERRORS_ENCOUNTERED =
	#	if defined ERROR_ERRORS_ENCOUNTERED
				ERROR_ERRORS_ENCOUNTERED
	#	else
				0x306
	#	endif
			// One or more errors occurred while processing the request.

	, NOT_CAPABLE =
	#	if defined ERROR_NOT_CAPABLE
				ERROR_NOT_CAPABLE
	#	else
				0x307
	#	endif
			// The implementation is not capable of performing the request.

	, REQUEST_OUT_OF_SEQUENCE =
	#	if defined ERROR_REQUEST_OUT_OF_SEQUENCE
				ERROR_REQUEST_OUT_OF_SEQUENCE
	#	else
				0x308
	#	endif
			// The client of a component requested an operation which is not valid given the state of the component instance.

	, VERSION_PARSE_ERROR =
	#	if defined ERROR_VERSION_PARSE_ERROR
				ERROR_VERSION_PARSE_ERROR
	#	else
				0x309
	#	endif
			// A version number could not be parsed.

	, BADSTARTPOSITION =
	#	if defined ERROR_BADSTARTPOSITION
				ERROR_BADSTARTPOSITION
	#	else
				0x30A
	#	endif
			// The iterator's start position is invalid.

	, MEMORY_HARDWARE =
	#	if defined ERROR_MEMORY_HARDWARE
				ERROR_MEMORY_HARDWARE
	#	else
				0x30B
	#	endif
			// The hardware has reported an uncorrectable memory error.

	, DISK_REPAIR_DISABLED =
	#	if defined ERROR_DISK_REPAIR_DISABLED
				ERROR_DISK_REPAIR_DISABLED
	#	else
				0x30C
	#	endif
			// The attempted operation required self healing to be enabled.

	, INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE =
	#	if defined ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE
				ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE
	#	else
				0x30D
	#	endif
			// The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.

	, SYSTEM_POWERSTATE_TRANSITION =
	#	if defined ERROR_SYSTEM_POWERSTATE_TRANSITION
				ERROR_SYSTEM_POWERSTATE_TRANSITION
	#	else
				0x30E
	#	endif
			// The system power state is transitioning from %2 to %3.

	, SYSTEM_POWERSTATE_COMPLEX_TRANSITION =
	#	if defined ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION
				ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION
	#	else
				0x30F
	#	endif
			// The system power state is transitioning from %2 to %3 but could enter %4.

	, MCA_EXCEPTION =
	#	if defined ERROR_MCA_EXCEPTION
				ERROR_MCA_EXCEPTION
	#	else
				0x310
	#	endif
			// A thread is getting dispatched with MCA EXCEPTION because of MCA.

	, ACCESS_AUDIT_BY_POLICY =
	#	if defined ERROR_ACCESS_AUDIT_BY_POLICY
				ERROR_ACCESS_AUDIT_BY_POLICY
	#	else
				0x311
	#	endif
			// Access to %1 is monitored by policy rule %2.

	, ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY =
	#	if defined ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY
				ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY
	#	else
				0x312
	#	endif
			// Access to %1 has been restricted by your Administrator by policy rule %2.

	, ABANDON_HIBERFILE =
	#	if defined ERROR_ABANDON_HIBERFILE
				ERROR_ABANDON_HIBERFILE
	#	else
				0x313
	#	endif
			// A valid hibernation file has been invalidated and should be abandoned.

	, LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED =
	#	if defined ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED
				ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED
	#	else
				0x314
	#	endif
			// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused by network connectivity issues. Please try to save this file elsewhere.

	, LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR =
	#	if defined ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR
				ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR
	#	else
				0x315
	#	endif
			// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error was returned by the server on which the file exists. Please try to save this file elsewhere.

	, LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR =
	#	if defined ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR
				ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR
	#	else
				0x316
	#	endif
			// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused if the device has been removed or the media is write-protected.

	, BAD_MCFG_TABLE =
	#	if defined ERROR_BAD_MCFG_TABLE
				ERROR_BAD_MCFG_TABLE
	#	else
				0x317
	#	endif
			// The resources required for this device conflict with the MCFG table.

	, DISK_REPAIR_REDIRECTED =
	#	if defined ERROR_DISK_REPAIR_REDIRECTED
				ERROR_DISK_REPAIR_REDIRECTED
	#	else
				0x318
	#	endif
			// The volume repair could not be performed while it is online. Please schedule to take the volume offline so that it can be repaired.

	, DISK_REPAIR_UNSUCCESSFUL =
	#	if defined ERROR_DISK_REPAIR_UNSUCCESSFUL
				ERROR_DISK_REPAIR_UNSUCCESSFUL
	#	else
				0x319
	#	endif
			// The volume repair was not successful.

	, CORRUPT_LOG_OVERFULL =
	#	if defined ERROR_CORRUPT_LOG_OVERFULL
				ERROR_CORRUPT_LOG_OVERFULL
	#	else
				0x31A
	#	endif
			// One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.

	, CORRUPT_LOG_CORRUPTED =
	#	if defined ERROR_CORRUPT_LOG_CORRUPTED
				ERROR_CORRUPT_LOG_CORRUPTED
	#	else
				0x31B
	#	endif
			// One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.

	, CORRUPT_LOG_UNAVAILABLE =
	#	if defined ERROR_CORRUPT_LOG_UNAVAILABLE
				ERROR_CORRUPT_LOG_UNAVAILABLE
	#	else
				0x31C
	#	endif
			// One of the volume corruption logs is unavailable for being operated on.

	, CORRUPT_LOG_DELETED_FULL =
	#	if defined ERROR_CORRUPT_LOG_DELETED_FULL
				ERROR_CORRUPT_LOG_DELETED_FULL
	#	else
				0x31D
	#	endif
			// One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.

	, CORRUPT_LOG_CLEARED =
	#	if defined ERROR_CORRUPT_LOG_CLEARED
				ERROR_CORRUPT_LOG_CLEARED
	#	else
				0x31E
	#	endif
			// One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.

	, ORPHAN_NAME_EXHAUSTED =
	#	if defined ERROR_ORPHAN_NAME_EXHAUSTED
				ERROR_ORPHAN_NAME_EXHAUSTED
	#	else
				0x31F
	#	endif
			// Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.

	, OPLOCK_SWITCHED_TO_NEW_HANDLE =
	#	if defined ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE
				ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE
	#	else
				0x320
	#	endif
			// The oplock that was associated with this handle is now associated with a different handle.

	, CANNOT_GRANT_REQUESTED_OPLOCK =
	#	if defined ERROR_CANNOT_GRANT_REQUESTED_OPLOCK
				ERROR_CANNOT_GRANT_REQUESTED_OPLOCK
	#	else
				0x321
	#	endif
			// An oplock of the requested level cannot be granted. An oplock of a lower level may be available.

	, CANNOT_BREAK_OPLOCK =
	#	if defined ERROR_CANNOT_BREAK_OPLOCK
				ERROR_CANNOT_BREAK_OPLOCK
	#	else
				0x322
	#	endif
			// The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.

	, OPLOCK_HANDLE_CLOSED =
	#	if defined ERROR_OPLOCK_HANDLE_CLOSED
				ERROR_OPLOCK_HANDLE_CLOSED
	#	else
				0x323
	#	endif
			// The handle with which this oplock was associated has been closed. The oplock is now broken.

	, NO_ACE_CONDITION =
	#	if defined ERROR_NO_ACE_CONDITION
				ERROR_NO_ACE_CONDITION
	#	else
				0x324
	#	endif
			// The specified access control entry (ACE) does not contain a condition.

	, INVALID_ACE_CONDITION =
	#	if defined ERROR_INVALID_ACE_CONDITION
				ERROR_INVALID_ACE_CONDITION
	#	else
				0x325
	#	endif
			// The specified access control entry (ACE) contains an invalid condition.

	, FILE_HANDLE_REVOKED =
	#	if defined ERROR_FILE_HANDLE_REVOKED
				ERROR_FILE_HANDLE_REVOKED
	#	else
				0x326
	#	endif
			// Access to the specified file handle has been revoked.

	, IMAGE_AT_DIFFERENT_BASE =
	#	if defined ERROR_IMAGE_AT_DIFFERENT_BASE
				ERROR_IMAGE_AT_DIFFERENT_BASE
	#	else
				0x327
	#	endif
			// An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.

	, EA_ACCESS_DENIED =
	#	if defined ERROR_EA_ACCESS_DENIED
				ERROR_EA_ACCESS_DENIED
	#	else
				0x3E2
	#	endif
			// Access to the extended attribute was denied.

	, OPERATION_ABORTED =
	#	if defined ERROR_OPERATION_ABORTED
				ERROR_OPERATION_ABORTED
	#	else
				0x3E3
	#	endif
			// The I/O operation has been aborted because of either a thread exit or an application request.

	, IO_INCOMPLETE =
	#	if defined ERROR_IO_INCOMPLETE
				ERROR_IO_INCOMPLETE
	#	else
				0x3E4
	#	endif
			// Overlapped I/O event is not in a signaled state.

	, IO_PENDING =
	#	if defined ERROR_IO_PENDING
				ERROR_IO_PENDING
	#	else
				0x3E5
	#	endif
			// Overlapped I/O operation is in progress.

	, NOACCESS =
	#	if defined ERROR_NOACCESS
				ERROR_NOACCESS
	#	else
				0x3E6
	#	endif
			// Invalid access to memory location.

	, SWAPERROR =
	#	if defined ERROR_SWAPERROR
				ERROR_SWAPERROR
	#	else
				0x3E7
	#	endif
			// Error performing inpage operation.

};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString1(os::Status status) noexcept
{
	auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::USER_PROFILE_LOAD:
			RETURN_STATIC_STRING(
					"User profile cannot be loaded"
			);
		case SystemCode::ARITHMETIC_OVERFLOW:
			RETURN_STATIC_STRING(
					"Arithmetic result exceeded 32 bits"
			);
		case SystemCode::PIPE_CONNECTED:
			RETURN_STATIC_STRING(
					"There is a process on other end of the pipe"
			);
		case SystemCode::PIPE_LISTENING:
			RETURN_STATIC_STRING(
					"Waiting for a process to open the other end of the pipe"
			);
		case SystemCode::VERIFIER_STOP:
			RETURN_STATIC_STRING(
					"Application verifier has found an error in the current process"
			);
		case SystemCode::ABIOS_ERROR:
			RETURN_STATIC_STRING(
					"An error occurred in the ABIOS subsystem"
			);
		case SystemCode::WX86_WARNING:
			RETURN_STATIC_STRING(
					"A warning occurred in the WX86 subsystem"
			);
		case SystemCode::WX86_ERROR:
			RETURN_STATIC_STRING(
					"An error occurred in the WX86 subsystem"
			);
		case SystemCode::TIMER_NOT_CANCELED:
			RETURN_STATIC_STRING(
					"An attempt was made to cancel or set a timer that has an associated APC and"
					" the subject thread is not the thread that originally set the timer with an"
					" associated APC routine"
			);
		case SystemCode::UNWIND:
			RETURN_STATIC_STRING(
					"Unwind exception code"
			);
		case SystemCode::BAD_STACK:
			RETURN_STATIC_STRING(
					"An invalid or unaligned stack was encountered during an unwind operation"
			);
		case SystemCode::INVALID_UNWIND_TARGET:
			RETURN_STATIC_STRING(
					"An invalid unwind target was encountered during an unwind operation"
			);
		case SystemCode::INVALID_PORT_ATTRIBUTES:
			RETURN_STATIC_STRING(
					"Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes"
					" specified to NtConnectPor"
			);
		case SystemCode::PORT_MESSAGE_TOO_LONG:
			RETURN_STATIC_STRING(
					"Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer"
					" than the maximum message allowed by the port"
			);
		case SystemCode::INVALID_QUOTA_LOWER:
			RETURN_STATIC_STRING(
					"An attempt was made to lower a quota limit below the current usage"
			);
		case SystemCode::DEVICE_ALREADY_ATTACHED:
			RETURN_STATIC_STRING(
					"An attempt was made to attach to a device that was already attached to another"
					" device"
			);
		case SystemCode::INSTRUCTION_MISALIGNMENT:
			RETURN_STATIC_STRING(
					"An attempt was made to execute an instruction at an unaligned address and the"
					" host system does not support unaligned instruction references"
			);
		case SystemCode::PROFILING_NOT_STARTED:
			RETURN_STATIC_STRING(
					"Profiling not started"
			);
		case SystemCode::PROFILING_NOT_STOPPED:
			RETURN_STATIC_STRING(
					"Profiling not stopped"
			);
		case SystemCode::COULD_NOT_INTERPRET:
			RETURN_STATIC_STRING(
					"The passed ACL did not contain the minimum required information"
			);
		case SystemCode::PROFILING_AT_LIMIT:
			RETURN_STATIC_STRING(
					"The number of active profiling objects is at the maximum and no more may be"
					" started"
			);
		case SystemCode::CANT_WAIT:
			RETURN_STATIC_STRING(
					"Used to indicate that an operation cannot continue without blocking for I/O"
			);
		case SystemCode::CANT_TERMINATE_SELF:
			RETURN_STATIC_STRING(
					"Indicates that a thread attempted to terminate itself by default (called"
					" NtTerminateThread with NULL) and it was the last thread in the current"
					" process"
			);
		case SystemCode::UNEXPECTED_MM_CREATE_ERR:
			RETURN_STATIC_STRING(
					"If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception"
			);
		case SystemCode::UNEXPECTED_MM_MAP_ERROR:
			RETURN_STATIC_STRING(
					"If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception"
			);
		case SystemCode::UNEXPECTED_MM_EXTEND_ERR:
			RETURN_STATIC_STRING(
					"If an MM error is returned which is not defined in the standard FsRtl filter,"
					" it is converted to one of the following errors which is guaranteed to be in"
					" the filter. In this case information is lost, however, the filter correctly"
					" handles the exception"
			);
		case SystemCode::BAD_FUNCTION_TABLE:
			RETURN_STATIC_STRING(
					"A malformed function table was encountered during an unwind operation"
			);
		case SystemCode::NO_GUID_TRANSLATION:
			RETURN_STATIC_STRING(
					"Indicates that an attempt was made to assign protection to a file system file"
					" or directory and one of the SIDs in the security descriptor could not be"
					" translated into a GUID that could be stored by the file system. This causes"
					" the protection attempt to fail, which may cause a file creation attempt to"
					" fail"
			);
		case SystemCode::INVALID_LDT_SIZE:
			RETURN_STATIC_STRING(
					"Indicates that an attempt was made to grow an LDT by setting its size, or that"
					" the size was not an even number of selectors"
			);
		case SystemCode::INVALID_LDT_OFFSET:
			RETURN_STATIC_STRING(
					"Indicates that the starting value for the LDT information was not an integral"
					" multiple of the selector size"
			);
		case SystemCode::INVALID_LDT_DESCRIPTOR:
			RETURN_STATIC_STRING(
					"Indicates that the user supplied an invalid descriptor when trying to set up"
					" Ldt descriptors"
			);
		case SystemCode::TOO_MANY_THREADS:
			RETURN_STATIC_STRING(
					"Indicates a process has too many threads to perform the requested action. For"
					" example, assignment of a primary token may only be performed when a process"
					" has zero or one threads"
			);
		case SystemCode::THREAD_NOT_IN_PROCESS:
			RETURN_STATIC_STRING(
					"An attempt was made to operate on a thread within a specific process, but the"
					" thread specified is not in the process specified"
			);
		case SystemCode::PAGEFILE_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"Page file quota was exceeded"
			);
		case SystemCode::LOGON_SERVER_CONFLICT:
			RETURN_STATIC_STRING(
					"The Netlogon service cannot start because another Netlogon service running in"
					" the domain conflicts with the specified role"
			);
		case SystemCode::SYNCHRONIZATION_REQUIRED:
			RETURN_STATIC_STRING(
					"The SAM database on a Windows Server is significantly out of synchronization"
					" with the copy on the Domain Controller. A complete synchronization is"
					" required"
			);
		case SystemCode::NET_OPEN_FAILED:
			RETURN_STATIC_STRING(
					"The NtCreateFile API failed. This error should never be returned to an"
					" application, it is a place holder for the Windows Lan Manager Redirector to"
					" use in its internal error mapping routines"
			);
		case SystemCode::IO_PRIVILEGE_FAILED:
			RETURN_STATIC_STRING(
					"{Privilege Failed} The I/O permissions for the process could not be changed"
			);
		case SystemCode::CTRL_C_EXIT:
			RETURN_STATIC_STRING(
					"{Application Exit by CTRL+C} The application terminated as a result of a"
					" CTRL+C"
			);
		case SystemCode::MISSING_SYSTEMFILE:
			RETURN_STATIC_STRING(
					"{Missing System File} The required system file %hs is bad or missing"
			);
		case SystemCode::UNHANDLED_EXCEPTION:
			RETURN_STATIC_STRING(
					"{Application Error} The exception %s (0x%08lx) occurred in the application at"
					" location 0x%08lx"
			);
		case SystemCode::APP_INIT_FAILURE:
			RETURN_STATIC_STRING(
					"{Application Error} The application was unable to start correctly (0x%lx)."
					" Click OK to close the application"
			);
		case SystemCode::PAGEFILE_CREATE_FAILED:
			RETURN_STATIC_STRING(
					"{Unable to Create Paging File} The creation of the paging file %hs failed"
					" (%lx). The requested size was %ld"
			);
		case SystemCode::INVALID_IMAGE_HASH:
			RETURN_STATIC_STRING(
					"Windows cannot verify the digital signature for this file. A recent hardware"
					" or software change might have installed a file that is signed incorrectly or"
					" damaged, or that might be malicious software from an unknown source"
			);
		case SystemCode::NO_PAGEFILE:
			RETURN_STATIC_STRING(
					"{No Paging File Specified} No paging file was specified in the system"
					" configuration"
			);
		case SystemCode::ILLEGAL_FLOAT_CONTEXT:
			RETURN_STATIC_STRING(
					"{EXCEPTION} A real-mode application issued a floating-point instruction and"
					" floating-point hardware is not present"
			);
		case SystemCode::NO_EVENT_PAIR:
			RETURN_STATIC_STRING(
					"An event pair synchronization operation was performed using the thread"
					" specific client/server event pair object, but no event pair object was"
					" associated with the thread"
			);
		case SystemCode::DOMAIN_CTRLR_CONFIG_ERROR:
			RETURN_STATIC_STRING(
					"A Windows Server has an incorrect configuration"
			);
		case SystemCode::ILLEGAL_CHARACTER:
			RETURN_STATIC_STRING(
					"An illegal character was encountered. For a multi-byte character set this"
					" includes a lead byte without a succeeding trail byte. For the Unicode"
					" character set this includes the characters 0xFFFF and 0xFFFE"
			);
		case SystemCode::UNDEFINED_CHARACTER:
			RETURN_STATIC_STRING(
					"The Unicode character is not defined in the Unicode character set installed"
					" on the system"
			);
		case SystemCode::FLOPPY_VOLUME:
			RETURN_STATIC_STRING(
					"The paging file cannot be created on a floppy diskette"
			);
		case SystemCode::BIOS_FAILED_TO_CONNECT_INTERRUPT:
			RETURN_STATIC_STRING(
					"The system BIOS failed to connect a system interrupt to the device or bus for"
					" which the device is connected"
			);
		case SystemCode::BACKUP_CONTROLLER:
			RETURN_STATIC_STRING(
					"This operation is only allowed for the Primary Domain Controller of the domain"
			);
		case SystemCode::MUTANT_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"An attempt was made to acquire a mutant such that its maximum count would have"
					" been exceeded"
			);
		case SystemCode::FS_DRIVER_REQUIRED:
			RETURN_STATIC_STRING(
					"A volume has been accessed for which a file system driver is required that has"
					" not yet been loaded"
			);
		case SystemCode::CANNOT_LOAD_REGISTRY_FILE:
			RETURN_STATIC_STRING(
					"{Registry File Failure} The registry cannot load the hive (file): %hs or its"
					" log or alternate. It is corrupt, absent, or not writable"
			);
		case SystemCode::DEBUG_ATTACH_FAILED:
			RETURN_STATIC_STRING(
					"{Unexpected Failure in DebugActiveProcess} An unexpected failure occurred"
					" while processing a DebugActiveProcess API request. You may choose OK to"
					" terminate the process, or Cancel to ignore the error"
			);
		case SystemCode::SYSTEM_PROCESS_TERMINATED:
			RETURN_STATIC_STRING(
					"{Fatal System Error} The %hs system process terminated unexpectedly with a"
					" status of 0x%08x (0x%08x 0x%08x). The system has been shut down"
			);
		case SystemCode::DATA_NOT_ACCEPTED:
			RETURN_STATIC_STRING(
					"{Data Not Accepted} The TDI client could not handle the data received during"
					" an indication"
			);
		case SystemCode::VDM_HARD_ERROR:
			RETURN_STATIC_STRING(
					"NTVDM encountered a hard error"
			);
		case SystemCode::DRIVER_CANCEL_TIMEOUT:
			RETURN_STATIC_STRING(
					"{Cancel Timeout} The driver %hs failed to complete a cancelled I/O request in"
					" the allotted time"
			);
		case SystemCode::REPLY_MESSAGE_MISMATCH:
			RETURN_STATIC_STRING(
					"{Reply Message Mismatch} An attempt was made to reply to an LPC message, but"
					" the thread specified by the client ID in the message was not waiting on that"
					" message"
			);
		case SystemCode::LOST_WRITEBEHIND_DATA:
			RETURN_STATIC_STRING(
					"{Delayed Write Failed} Windows was unable to save all the data for the file"
					" %hs. The data has been lost. This error may be caused by a failure of your"
					" computer hardware or network connection. Please try to save this file"
					" elsewhere"
			);
		case SystemCode::CLIENT_SERVER_PARAMETERS_INVALID:
			RETURN_STATIC_STRING(
					"The parameter(s) passed to the server in the client/server shared memory"
					" window were invalid. Too much data may have been put in the shared memory"
					" window"
			);
		case SystemCode::NOT_TINY_STREAM:
			RETURN_STATIC_STRING(
					"The stream is not a tiny stream"
			);
		case SystemCode::STACK_OVERFLOW_READ:
			RETURN_STATIC_STRING(
					"The request must be handled by the stack overflow code"
			);
		case SystemCode::CONVERT_TO_LARGE:
			RETURN_STATIC_STRING(
					"Internal OFS status codes indicating how an allocation operation is handled."
					" Either it is retried after the containing onode is moved or the extent stream"
					" is converted to a large stream"
			);
		case SystemCode::FOUND_OUT_OF_SCOPE:
			RETURN_STATIC_STRING(
					"The attempt to find the object found an object matching by ID on the volume"
					" but it is out of the scope of the handle used for the operation"
			);
		case SystemCode::ALLOCATE_BUCKET:
			RETURN_STATIC_STRING(
					"The bucket array must be grown. Retry transaction after doing so"
			);
		case SystemCode::MARSHALL_OVERFLOW:
			RETURN_STATIC_STRING(
					"The user/kernel marshalling buffer has overflowed"
			);
		case SystemCode::INVALID_VARIANT:
			RETURN_STATIC_STRING(
					"The supplied variant structure contains invalid data"
			);
		case SystemCode::BAD_COMPRESSION_BUFFER:
			RETURN_STATIC_STRING(
					"The specified buffer contains ill-formed data"
			);
		case SystemCode::AUDIT_FAILED:
			RETURN_STATIC_STRING(
					"{Audit Failed} An attempt to generate a security audit failed"
			);
		case SystemCode::TIMER_RESOLUTION_NOT_SET:
			RETURN_STATIC_STRING(
					"The timer resolution was not previously set by the current process"
			);
		case SystemCode::INSUFFICIENT_LOGON_INFO:
			RETURN_STATIC_STRING(
					"There is insufficient account information to log you on"
			);
		case SystemCode::BAD_DLL_ENTRYPOINT:
			RETURN_STATIC_STRING(
					"{Invalid DLL Entrypoint} The dynamic link library %hs is not written"
					" correctly. The stack pointer has been left in an inconsistent state. The"
					" entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the"
					" DLL load. Select NO to continue execution. Selecting NO may cause the"
					" application to operate incorrectly"
			);
		case SystemCode::BAD_SERVICE_ENTRYPOINT:
			RETURN_STATIC_STRING(
					"{Invalid Service Callback Entrypoint} The %hs service is not written"
					" correctly. The stack pointer has been left in an inconsistent state. The"
					" callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK"
					" will cause the service to continue operation. However, the service process"
					" may operate incorrectly"
			);
		case SystemCode::IP_ADDRESS_CONFLICT1:
			RETURN_STATIC_STRING(
					"There is an IP address conflict with another system on the network"
			);
		case SystemCode::IP_ADDRESS_CONFLICT2:
			RETURN_STATIC_STRING(
					"There is an IP address conflict with another system on the network"
			);
		case SystemCode::REGISTRY_QUOTA_LIMIT:
			RETURN_STATIC_STRING(
					"{Low On Registry Space} The system has reached the maximum size allowed for"
					" the system part of the registry. Additional storage requests will be ignored"
			);
		case SystemCode::NO_CALLBACK_ACTIVE:
			RETURN_STATIC_STRING(
					"A callback return system service cannot be executed when no callback is active"
			);
		case SystemCode::PWD_TOO_SHORT:
			RETURN_STATIC_STRING(
					"The password provided is too short to meet the policy of your user account."
					" Please choose a longer password"
			);
		case SystemCode::PWD_TOO_RECENT:
			RETURN_STATIC_STRING(
					"The policy of your user account does not allow you to change passwords too"
					" frequently. This is done to prevent users from changing back to a familiar,"
					" but potentially discovered, password. If you feel your password has been"
					" compromised then please contact your administrator immediately to have a"
					" new one assigned"
			);
		case SystemCode::PWD_HISTORY_CONFLICT:
			RETURN_STATIC_STRING(
					"You have attempted to change your password to one that you have used in the"
					" past. The policy of your user account does not allow this. Please select a"
					" password that you have not previously used"
			);
		case SystemCode::UNSUPPORTED_COMPRESSION:
			RETURN_STATIC_STRING(
					"The specified compression format is unsupported"
			);
		case SystemCode::INVALID_HW_PROFILE:
			RETURN_STATIC_STRING(
					"The specified hardware profile configuration is invalid"
			);
		case SystemCode::INVALID_PLUGPLAY_DEVICE_PATH:
			RETURN_STATIC_STRING(
					"The specified Plug and Play registry device path is invalid"
			);
		case SystemCode::QUOTA_LIST_INCONSISTENT:
			RETURN_STATIC_STRING(
					"The specified quota list is internally inconsistent with its descriptor"
			);
		case SystemCode::EVALUATION_EXPIRATION:
			RETURN_STATIC_STRING(
					"{Windows Evaluation Notification} The evaluation period for this installation"
					" of Windows has expired. This system will shutdown in 1 hour. To restore"
					" access to this installation of Windows, please upgrade this installation"
					" using a licensed distribution of this product"
			);
		case SystemCode::ILLEGAL_DLL_RELOCATION:
			RETURN_STATIC_STRING(
					"{Illegal System DLL Relocation} The system DLL %hs was relocated in memory."
					" The application will not run properly. The relocation occurred because the"
					" DLL %hs occupied an address range reserved for Windows system DLLs. The"
					" vendor supplying the DLL should be contacted for a new DLL"
			);
		case SystemCode::DLL_INIT_FAILED_LOGOFF:
			RETURN_STATIC_STRING(
					"{DLL Initialization Failed} The application failed to initialize because the"
					" window station is shutting down"
			);
		case SystemCode::VALIDATE_CONTINUE:
			RETURN_STATIC_STRING(
					"The validation process needs to continue on to the next step"
			);
		case SystemCode::NO_MORE_MATCHES:
			RETURN_STATIC_STRING(
					"There are no more matches for the current index enumeration"
			);
		case SystemCode::RANGE_LIST_CONFLICT:
			RETURN_STATIC_STRING(
					"The range could not be added to the range list because of a conflict"
			);
		case SystemCode::SERVER_SID_MISMATCH:
			RETURN_STATIC_STRING(
					"The server process is running under a SID different than that required by"
					" client"
			);
		case SystemCode::CANT_ENABLE_DENY_ONLY:
			RETURN_STATIC_STRING(
					"A group marked use for deny only cannot be enabled"
			);
		case SystemCode::FLOAT_MULTIPLE_FAULTS:
			RETURN_STATIC_STRING(
					"{EXCEPTION} Multiple floating point faults"
			);
		case SystemCode::FLOAT_MULTIPLE_TRAPS:
			RETURN_STATIC_STRING(
					"{EXCEPTION} Multiple floating point traps"
			);
		case SystemCode::NOINTERFACE:
			RETURN_STATIC_STRING(
					"The requested interface is not supported"
			);
		case SystemCode::DRIVER_FAILED_SLEEP:
			RETURN_STATIC_STRING(
					"{System Standby Failed} The driver %hs does not support standby mode. Updating"
					" this driver may allow the system to go to standby mode"
			);
		case SystemCode::CORRUPT_SYSTEM_FILE:
			RETURN_STATIC_STRING(
					"The system file %1 has become corrupt and has been replaced"
			);
		case SystemCode::COMMITMENT_MINIMUM:
			RETURN_STATIC_STRING(
					"{Virtual Memory Minimum Too Low} Your system is low on virtual memory. Windows"
					" is increasing the size of your virtual memory paging file. During this"
					" process, memory requests for some applications may be denied. For more"
					" information, see Help"
			);
		case SystemCode::PNP_RESTART_ENUMERATION:
			RETURN_STATIC_STRING(
					"A device was removed so enumeration must be restarted"
			);
		case SystemCode::SYSTEM_IMAGE_BAD_SIGNATURE:
			RETURN_STATIC_STRING(
					"{Fatal System Error} The system image %s is not properly signed. The file has"
					" been replaced with the signed file. The system has been shut down"
			);
		case SystemCode::PNP_REBOOT_REQUIRED:
			RETURN_STATIC_STRING(
					"Device will not start without a reboot"
			);
		case SystemCode::INSUFFICIENT_POWER:
			RETURN_STATIC_STRING(
					"There is not enough power to complete the requested operation"
			);
		case SystemCode::MULTIPLE_FAULT_VIOLATION:
			RETURN_STATIC_STRING(
					"ERROR_MULTIPLE_FAULT_VIOLATIO"
			);
		case SystemCode::SYSTEM_SHUTDOWN:
			RETURN_STATIC_STRING(
					"The system is in the process of shutting down"
			);
		case SystemCode::PORT_NOT_SET:
			RETURN_STATIC_STRING(
					"An attempt to remove a processes DebugPort was made, but a port was not"
					" already associated with the process"
			);
		case SystemCode::DS_VERSION_CHECK_FAILURE:
			RETURN_STATIC_STRING(
					"This version of Windows is not compatible with the behavior version of"
					" directory forest, domain or domain controller"
			);
		case SystemCode::RANGE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified range could not be found in the range list"
			);
		case SystemCode::NOT_SAFE_MODE_DRIVER:
			RETURN_STATIC_STRING(
					"The driver was not loaded because the system is booting into safe mode"
			);
		case SystemCode::FAILED_DRIVER_ENTRY:
			RETURN_STATIC_STRING(
					"The driver was not loaded because it failed its initialization call"
			);
		case SystemCode::DEVICE_ENUMERATION_ERROR:
			RETURN_STATIC_STRING(
					"The '%hs' encountered an error while applying power or reading the device"
					" configuration. This may be caused by a failure of your hardware or by a poor"
					" connection"
			);
		case SystemCode::MOUNT_POINT_NOT_RESOLVED:
			RETURN_STATIC_STRING(
					"The create operation failed because the name contained at least one mount"
					" point which resolves to a volume to which the specified device object is"
					" not attached"
			);
		case SystemCode::INVALID_DEVICE_OBJECT_PARAMETER:
			RETURN_STATIC_STRING(
					"The device object parameter is either not a valid device object or is not"
					" attached to the volume specified by the file name"
			);
		case SystemCode::MCA_OCCURED:
			RETURN_STATIC_STRING(
					"A Machine Check Error has occurred. Please check the system eventlog for"
					" additional information"
			);
		case SystemCode::DRIVER_DATABASE_ERROR:
			RETURN_STATIC_STRING(
					"There was error [%2] processing the driver database"
			);
		case SystemCode::SYSTEM_HIVE_TOO_LARGE:
			RETURN_STATIC_STRING(
					"System hive size has exceeded its limit"
			);
		case SystemCode::DRIVER_FAILED_PRIOR_UNLOAD:
			RETURN_STATIC_STRING(
					"The driver could not be loaded because a previous version of the driver is"
					" still in memory"
			);
		case SystemCode::VOLSNAP_PREPARE_HIBERNATE:
			RETURN_STATIC_STRING(
					"{Volume Shadow Copy Service} Please wait while the Volume Shadow Copy Service"
					" prepares volume %hs for hibernation"
			);
		case SystemCode::HIBERNATION_FAILURE:
			RETURN_STATIC_STRING(
					"The system has failed to hibernate (The error code is %hs). Hibernation will"
					" be disabled until the system is restarted"
			);
		case SystemCode::PWD_TOO_LONG:
			RETURN_STATIC_STRING(
					"The password provided is too long to meet the policy of your user account."
					" Please choose a shorter password"
			);
		case SystemCode::FILE_SYSTEM_LIMITATION:
			RETURN_STATIC_STRING(
					"The requested operation could not be completed due to a file system limitation"
			);
		case SystemCode::ASSERTION_FAILURE:
			RETURN_STATIC_STRING(
					"An assertion failure has occurred"
			);
		case SystemCode::ACPI_ERROR:
			RETURN_STATIC_STRING(
					"An error occurred in the ACPI subsystem"
			);
		case SystemCode::WOW_ASSERTION:
			RETURN_STATIC_STRING(
					"WOW Assertion Error"
			);
		case SystemCode::PNP_BAD_MPS_TABLE:
			RETURN_STATIC_STRING(
					"A device is missing in the system BIOS MPS table. This device will not be"
					" used. Please contact your system vendor for system BIOS update"
			);
		case SystemCode::PNP_TRANSLATION_FAILED:
			RETURN_STATIC_STRING(
					"A translator failed to translate resources"
			);
		case SystemCode::PNP_IRQ_TRANSLATION_FAILED:
			RETURN_STATIC_STRING(
					"A IRQ translator failed to translate resources"
			);
		case SystemCode::PNP_INVALID_ID:
			RETURN_STATIC_STRING(
					"Driver %2 returned invalid ID for a child device (%3)"
			);
		case SystemCode::WAKE_SYSTEM_DEBUGGER:
			RETURN_STATIC_STRING(
					"{Kernel Debugger Awakened} the system debugger was awakened by an interrupt"
			);
		case SystemCode::HANDLES_CLOSED:
			RETURN_STATIC_STRING(
					"{Handles Closed} Handles to objects have been automatically closed as a result"
					" of the requested operation"
			);
		case SystemCode::EXTRANEOUS_INFORMATION:
			RETURN_STATIC_STRING(
					"{Too Much Information} The specified access control list (ACL) contained more"
					" information than was expected"
			);
		case SystemCode::RXACT_COMMIT_NECESSARY:
			RETURN_STATIC_STRING(
					"This warning level status indicates that the transaction state already exists"
					" for the registry sub-tree, but that a transaction commit was previously"
					" aborted. The commit has NOT been completed, but has not been rolled back"
					" either (so it may still be committed if desired)"
			);
		case SystemCode::MEDIA_CHECK:
			RETURN_STATIC_STRING(
					"{Media Changed} The media may have changed"
			);
		case SystemCode::GUID_SUBSTITUTION_MADE:
			RETURN_STATIC_STRING(
					"{GUID Substitution} During the translation of a global identifier (GUID) to a"
					" Windows security ID (SID), no administratively-defined GUID prefix was found."
					" A substitute prefix was used, which will not compromise system security."
					" However, this may provide a more restrictive access than intended"
			);
		case SystemCode::STOPPED_ON_SYMLINK:
			RETURN_STATIC_STRING(
					"The create operation stopped after reaching a symbolic link"
			);
		case SystemCode::LONGJUMP:
			RETURN_STATIC_STRING(
					"A long jump has been executed"
			);
		case SystemCode::PLUGPLAY_QUERY_VETOED:
			RETURN_STATIC_STRING(
					"The Plug and Play query operation was not successful"
			);
		case SystemCode::UNWIND_CONSOLIDATE:
			RETURN_STATIC_STRING(
					"A frame consolidation has been executed"
			);
		case SystemCode::REGISTRY_HIVE_RECOVERED:
			RETURN_STATIC_STRING(
					"{Registry Hive Recovered} Registry hive (file): %hs was corrupted and it has"
					" been recovered. Some data might have been lost"
			);
		case SystemCode::DLL_MIGHT_BE_INSECURE:
			RETURN_STATIC_STRING(
					"The application is attempting to run executable code from the module %hs. This"
					" may be insecure. An alternative, %hs, is available. Should the application"
					" use the secure module %hs"
			);
		case SystemCode::DLL_MIGHT_BE_INCOMPATIBLE:
			RETURN_STATIC_STRING(
					"The application is loading executable code from the module %hs. This is"
					" secure, but may be incompatible with previous releases of the operating"
					" system. An alternative, %hs, is available. Should the application use the"
					" secure module %hs"
			);
		case SystemCode::DEBUG_EXCEPTION_NOT_HANDLED:
			RETURN_STATIC_STRING(
					"Debugger did not handle the exception"
			);
		case SystemCode::DEBUG_REPLY_LATER:
			RETURN_STATIC_STRING(
					"Debugger will reply later"
			);
		case SystemCode::DEBUG_UNABLE_TO_PROVIDE_HANDLE:
			RETURN_STATIC_STRING(
					"Debugger cannot provide handle"
			);
		case SystemCode::DEBUG_TERMINATE_THREAD:
			RETURN_STATIC_STRING(
					"Debugger terminated thread"
			);
		case SystemCode::DEBUG_TERMINATE_PROCESS:
			RETURN_STATIC_STRING(
					"Debugger terminated process"
			);
		case SystemCode::DEBUG_CONTROL_C:
			RETURN_STATIC_STRING(
					"Debugger got control C"
			);
		case SystemCode::DEBUG_PRINTEXCEPTION_C:
			RETURN_STATIC_STRING(
					"Debugger printed exception on control C"
			);
		case SystemCode::DEBUG_RIPEXCEPTION:
			RETURN_STATIC_STRING(
					"Debugger received RIP exception"
			);
		case SystemCode::DEBUG_CONTROL_BREAK:
			RETURN_STATIC_STRING(
					"Debugger received control break"
			);
		case SystemCode::DEBUG_COMMAND_EXCEPTION:
			RETURN_STATIC_STRING(
					"Debugger command communication exception"
			);
		case SystemCode::OBJECT_NAME_EXISTS:
			RETURN_STATIC_STRING(
					"{Object Exists} An attempt was made to create an object and the object name"
					" already existed"
			);
		case SystemCode::THREAD_WAS_SUSPENDED:
			RETURN_STATIC_STRING(
					"{Thread Suspended} A thread termination occurred while the thread was"
					" suspended. The thread was resumed, and termination proceeded"
			);
		case SystemCode::IMAGE_NOT_AT_BASE:
			RETURN_STATIC_STRING(
					"{Image Relocated} An image file could not be mapped at the address specified"
					" in the image file. Local fixups must be performed on this image"
			);
		case SystemCode::RXACT_STATE_CREATED:
			RETURN_STATIC_STRING(
					"This informational level status indicates that a specified registry sub-tree"
					" transaction state did not yet exist and had to be created"
			);
		case SystemCode::SEGMENT_NOTIFICATION:
			RETURN_STATIC_STRING(
					"{Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an"
					" MS-DOS or Win16 program segment image. An exception is raised so a debugger"
					" can load, unload or track symbols and breakpoints within these 16-bit"
					" segments"
			);
		case SystemCode::BAD_CURRENT_DIRECTORY:
			RETURN_STATIC_STRING(
					"{Invalid Current Directory} The process cannot switch to the startup current"
					" directory %hs. Select OK to set current directory to %hs, or select CANCEL"
					" to exit"
			);
		case SystemCode::FT_READ_RECOVERY_FROM_BACKUP:
			RETURN_STATIC_STRING(
					"{Redundant Read} To satisfy a read request, the NT fault-tolerant file system"
					" successfully read the requested data from a redundant copy. This was done"
					" because the file system encountered a failure on a member of the"
					" fault-tolerant volume, but was unable to reassign the failing area of the"
					" device"
			);
		case SystemCode::FT_WRITE_RECOVERY:
			RETURN_STATIC_STRING(
					"{Redundant Write} To satisfy a write request, the NT fault-tolerant file"
					" system successfully wrote a redundant copy of the information. This was done"
					" because the file system encountered a failure on a member of the"
					" fault-tolerant volume, but was not able to reassign the failing area of the"
					" device"
			);
		case SystemCode::IMAGE_MACHINE_TYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"{Machine Type Mismatch} The image file %hs is valid, but is for a machine type"
					" other than the current machine. Select OK to continue, or CANCEL to fail the"
					" DLL load"
			);
		case SystemCode::RECEIVE_PARTIAL:
			RETURN_STATIC_STRING(
					"{Partial Data Received} The network transport returned partial data to its"
					" client. The remaining data will be sent later"
			);
		case SystemCode::RECEIVE_EXPEDITED:
			RETURN_STATIC_STRING(
					"{Expedited Data Received} The network transport returned data to its client"
					" that was marked as expedited by the remote system"
			);
		case SystemCode::RECEIVE_PARTIAL_EXPEDITED:
			RETURN_STATIC_STRING(
					"{Partial Expedited Data Received} The network transport returned partial data"
					" to its client and this data was marked as expedited by the remote system. The"
					" remaining data will be sent later"
			);
		case SystemCode::EVENT_DONE:
			RETURN_STATIC_STRING(
					"{TDI Event Done} The TDI indication has completed successfully"
			);
		case SystemCode::EVENT_PENDING:
			RETURN_STATIC_STRING(
					"{TDI Event Pending} The TDI indication has entered the pending state"
			);
		case SystemCode::CHECKING_FILE_SYSTEM:
			RETURN_STATIC_STRING(
					"Checking file system on %wZ"
			);
		case SystemCode::FATAL_APP_EXIT:
			RETURN_STATIC_STRING(
					"{Fatal Application Exit} %hs"
			);
		case SystemCode::PREDEFINED_HANDLE:
			RETURN_STATIC_STRING(
					"The specified registry key is referenced by a predefined handle"
			);
		case SystemCode::WAS_UNLOCKED:
			RETURN_STATIC_STRING(
					"{Page Unlocked} The page protection of a locked page was changed to 'No"
					" Access' and the page was unlocked from memory and from the process"
			);
		case SystemCode::SERVICE_NOTIFICATION:
			RETURN_STATIC_STRING(
					"%h"
			);
		case SystemCode::WAS_LOCKED:
			RETURN_STATIC_STRING(
					"{Page Locked} One of the pages to lock was already locked"
			);
		case SystemCode::LOG_HARD_ERROR:
			RETURN_STATIC_STRING(
					"Application popup: %1 : %"
			);
		case SystemCode::ALREADY_WIN32:
			RETURN_STATIC_STRING(
					"ERROR_ALREADY_WIN3"
			);
		case SystemCode::IMAGE_MACHINE_TYPE_MISMATCH_EXE:
			RETURN_STATIC_STRING(
					"{Machine Type Mismatch} The image file %hs is valid, but is for a machine type"
					" other than the current machine"
			);
		case SystemCode::NO_YIELD_PERFORMED:
			RETURN_STATIC_STRING(
					"A yield execution was performed and no thread was available to run"
			);
		case SystemCode::TIMER_RESUME_IGNORED:
			RETURN_STATIC_STRING(
					"The resumable flag to a timer API was ignored"
			);
		case SystemCode::ARBITRATION_UNHANDLED:
			RETURN_STATIC_STRING(
					"The arbiter has deferred arbitration of these resources to its parent"
			);
		case SystemCode::CARDBUS_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The inserted CardBus device cannot be started because of a configuration error on \"%hs\""
			);
		case SystemCode::MP_PROCESSOR_MISMATCH:
			RETURN_STATIC_STRING(
					"The CPUs in this multiprocessor system are not all the same revision level."
					" To use all processors the operating system restricts itself to the features"
					" of the least capable processor in the system. Should problems occur with this"
					" system, contact the CPU manufacturer to see if this mix of processors is"
					" supported"
			);
		case SystemCode::HIBERNATED:
			RETURN_STATIC_STRING(
					"The system was put into hibernation"
			);
		case SystemCode::RESUME_HIBERNATION:
			RETURN_STATIC_STRING(
					"The system was resumed from hibernation"
			);
		case SystemCode::FIRMWARE_UPDATED:
			RETURN_STATIC_STRING(
					"Windows has detected that the system firmware (BIOS) was updated [previous"
					" firmware date = %2, current firmware date %3]"
			);
		case SystemCode::DRIVERS_LEAKING_LOCKED_PAGES:
			RETURN_STATIC_STRING(
					"A device driver is leaking locked I/O pages causing system degradation. The"
					" system has automatically enabled tracking code in order to try and catch the"
					" culprit"
			);
		case SystemCode::WAKE_SYSTEM:
			RETURN_STATIC_STRING(
					"The system has awoken"
			);
		case SystemCode::WAIT_1:
			RETURN_STATIC_STRING(
					"ERROR_WAIT_1"
			);
		case SystemCode::WAIT_2:
			RETURN_STATIC_STRING(
					"ERROR_WAIT_2"
			);
		case SystemCode::WAIT_3:
			RETURN_STATIC_STRING(
					"ERROR_WAIT_3"
			);
		case SystemCode::WAIT_63:
			RETURN_STATIC_STRING(
					"ERROR_WAIT_63"
			);
		case SystemCode::ABANDONED_WAIT_0:
			RETURN_STATIC_STRING(
					"ERROR_ABANDONED_WAIT_0"
			);
		case SystemCode::ABANDONED_WAIT_63:
			RETURN_STATIC_STRING(
					"ERROR_ABANDONED_WAIT_63"
			);
		case SystemCode::USER_APC:
			RETURN_STATIC_STRING(
					"ERROR_USER_APC"
			);
		case SystemCode::KERNEL_APC:
			RETURN_STATIC_STRING(
					"ERROR_KERNEL_APC"
			);
		case SystemCode::ALERTED:
			RETURN_STATIC_STRING(
					"ERROR_ALERTED"
			);
		case SystemCode::ELEVATION_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation requires elevation"
			);
		case SystemCode::REPARSE:
			RETURN_STATIC_STRING(
					"A reparse should be performed by the Object Manager since the name of the file"
					" resulted in a symbolic link"
			);
		case SystemCode::OPLOCK_BREAK_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"An open/create operation completed while an oplock break is underway"
			);
		case SystemCode::VOLUME_MOUNTED:
			RETURN_STATIC_STRING(
					"A new volume has been mounted by a file system"
			);
		case SystemCode::RXACT_COMMITTED:
			RETURN_STATIC_STRING(
					"This success level status indicates that the transaction state already exists"
					" for the registry sub-tree, but that a transaction commit was previously"
					" aborted. The commit has now been completed"
			);
		case SystemCode::NOTIFY_CLEANUP:
			RETURN_STATIC_STRING(
					"This indicates that a notify change request has been completed due to closing"
					" the handle which made the notify change request"
			);
		case SystemCode::PRIMARY_TRANSPORT_CONNECT_FAILED:
			RETURN_STATIC_STRING(
					"{Connect Failure on Primary Transport} An attempt was made to connect to the"
					" remote server %hs on the primary transport, but the connection failed. The"
					" computer WAS able to connect on a secondary transport"
			);
		case SystemCode::PAGE_FAULT_TRANSITION:
			RETURN_STATIC_STRING(
					"Page fault was a transition fault"
			);
		case SystemCode::PAGE_FAULT_DEMAND_ZERO:
			RETURN_STATIC_STRING(
					"Page fault was a demand zero fault"
			);
		case SystemCode::PAGE_FAULT_COPY_ON_WRITE:
			RETURN_STATIC_STRING(
					"Page fault was a demand zero fault"
			);
		case SystemCode::PAGE_FAULT_GUARD_PAGE:
			RETURN_STATIC_STRING(
					"Page fault was a demand zero fault"
			);
		case SystemCode::PAGE_FAULT_PAGING_FILE:
			RETURN_STATIC_STRING(
					"Page fault was satisfied by reading from a secondary storage device"
			);
		case SystemCode::CACHE_PAGE_LOCKED:
			RETURN_STATIC_STRING(
					"Cached page was locked during operation"
			);
		case SystemCode::CRASH_DUMP:
			RETURN_STATIC_STRING(
					"Crash dump exists in paging file"
			);
		case SystemCode::BUFFER_ALL_ZEROS:
			RETURN_STATIC_STRING(
					"Specified buffer contains all zeros"
			);
		case SystemCode::REPARSE_OBJECT:
			RETURN_STATIC_STRING(
					"A reparse should be performed by the Object Manager since the name of the file"
					" resulted in a symbolic link"
			);
		case SystemCode::RESOURCE_REQUIREMENTS_CHANGED:
			RETURN_STATIC_STRING(
					"The device has succeeded a query-stop and its resource requirements have"
					" changed"
			);
		case SystemCode::TRANSLATION_COMPLETE:
			RETURN_STATIC_STRING(
					"The translator has translated these resources into the global space and no"
					" further translations should be performed"
			);
		case SystemCode::NOTHING_TO_TERMINATE:
			RETURN_STATIC_STRING(
					"A process being terminated has no threads to terminate"
			);
		case SystemCode::PROCESS_NOT_IN_JOB:
			RETURN_STATIC_STRING(
					"The specified process is not part of a job"
			);
		case SystemCode::PROCESS_IN_JOB:
			RETURN_STATIC_STRING(
					"The specified process is part of a job"
			);
		case SystemCode::VOLSNAP_HIBERNATE_READY:
			RETURN_STATIC_STRING(
					"{Volume Shadow Copy Service} The system is now ready for hibernation"
			);
		case SystemCode::FSFILTER_OP_COMPLETED_SUCCESSFULLY:
			RETURN_STATIC_STRING(
					"A file system or file system filter driver has successfully completed an"
					" FsFilter operation"
			);
		case SystemCode::INTERRUPT_VECTOR_ALREADY_CONNECTED:
			RETURN_STATIC_STRING(
					"The specified interrupt vector was already connected"
			);
		case SystemCode::INTERRUPT_STILL_CONNECTED:
			RETURN_STATIC_STRING(
					"The specified interrupt vector is still connected"
			);
		case SystemCode::WAIT_FOR_OPLOCK:
			RETURN_STATIC_STRING(
					"An operation is blocked waiting for an oplock"
			);
		case SystemCode::DEBUG_EXCEPTION_HANDLED:
			RETURN_STATIC_STRING(
					"Debugger handled exception"
			);
		case SystemCode::DEBUG_CONTINUE:
			RETURN_STATIC_STRING(
					"Debugger continued"
			);
		case SystemCode::CALLBACK_POP_STACK:
			RETURN_STATIC_STRING(
					"An exception occurred in a user mode callback and the kernel callback frame"
					" should be removed"
			);
		case SystemCode::COMPRESSION_DISABLED:
			RETURN_STATIC_STRING(
					"Compression is disabled for this volume"
			);
		case SystemCode::CANTFETCHBACKWARDS:
			RETURN_STATIC_STRING(
					"The data provider cannot fetch backwards through a result set"
			);
		case SystemCode::CANTSCROLLBACKWARDS:
			RETURN_STATIC_STRING(
					"The data provider cannot scroll backwards through a result set"
			);
		case SystemCode::ROWSNOTRELEASED:
			RETURN_STATIC_STRING(
					"The data provider requires that previously fetched data is released before"
					" asking for more data"
			);
		case SystemCode::BAD_ACCESSOR_FLAGS:
			RETURN_STATIC_STRING(
					"The data provider was not able to interpret the flags set for a column binding"
					" in an accessor"
			);
		case SystemCode::ERRORS_ENCOUNTERED:
			RETURN_STATIC_STRING(
					"One or more errors occurred while processing the request"
			);
		case SystemCode::NOT_CAPABLE:
			RETURN_STATIC_STRING(
					"The implementation is not capable of performing the request"
			);
		case SystemCode::REQUEST_OUT_OF_SEQUENCE:
			RETURN_STATIC_STRING(
					"The client of a component requested an operation which is not valid given the"
					" state of the component instance"
			);
		case SystemCode::VERSION_PARSE_ERROR:
			RETURN_STATIC_STRING(
					"A version number could not be parsed"
			);
		case SystemCode::BADSTARTPOSITION:
			RETURN_STATIC_STRING(
					"The iterator's start position is invalid"
			);
		case SystemCode::MEMORY_HARDWARE:
			RETURN_STATIC_STRING(
					"The hardware has reported an uncorrectable memory error"
			);
		case SystemCode::DISK_REPAIR_DISABLED:
			RETURN_STATIC_STRING(
					"The attempted operation required self healing to be enabled"
			);
		case SystemCode::INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE:
			RETURN_STATIC_STRING(
					"The Desktop heap encountered an error while allocating session memory. There"
					" is more information in the system event log"
			);
		case SystemCode::SYSTEM_POWERSTATE_TRANSITION:
			RETURN_STATIC_STRING(
					"The system power state is transitioning from %2 to %3"
			);
		case SystemCode::SYSTEM_POWERSTATE_COMPLEX_TRANSITION:
			RETURN_STATIC_STRING(
					"The system power state is transitioning from %2 to %3 but could enter %4"
			);
		case SystemCode::MCA_EXCEPTION:
			RETURN_STATIC_STRING(
					"A thread is getting dispatched with MCA EXCEPTION because of MCA"
			);
		case SystemCode::ACCESS_AUDIT_BY_POLICY:
			RETURN_STATIC_STRING(
					"Access to %1 is monitored by policy rule %2"
			);
		case SystemCode::ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY:
			RETURN_STATIC_STRING(
					"Access to %1 has been restricted by your Administrator by policy rule %2"
			);
		case SystemCode::ABANDON_HIBERFILE:
			RETURN_STATIC_STRING(
					"A valid hibernation file has been invalidated and should be abandoned"
			);
		case SystemCode::LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED:
			RETURN_STATIC_STRING(
					"{Delayed Write Failed} Windows was unable to save all the data for the file"
					" %hs; the data has been lost. This error may be caused by network"
					" connectivity issues. Please try to save this file elsewhere"
			);
		case SystemCode::LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR:
			RETURN_STATIC_STRING(
					"{Delayed Write Failed} Windows was unable to save all the data for the file"
					" %hs; the data has been lost. This error was returned by the server on which"
					" the file exists. Please try to save this file elsewhere"
			);
		case SystemCode::LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR:
			RETURN_STATIC_STRING(
					"{Delayed Write Failed} Windows was unable to save all the data for the file"
					" %hs; the data has been lost. This error may be caused if the device has been"
					" removed or the media is write-protected"
			);
		case SystemCode::BAD_MCFG_TABLE:
			RETURN_STATIC_STRING(
					"The resources required for this device conflict with the MCFG table"
			);
		case SystemCode::DISK_REPAIR_REDIRECTED:
			RETURN_STATIC_STRING(
					"The volume repair could not be performed while it is online. Please schedule"
					" to take the volume offline so that it can be repaired"
			);
		case SystemCode::DISK_REPAIR_UNSUCCESSFUL:
			RETURN_STATIC_STRING(
					"The volume repair was not successful"
			);
		case SystemCode::CORRUPT_LOG_OVERFULL:
			RETURN_STATIC_STRING(
					"One of the volume corruption logs is full. Further corruptions that may be"
					" detected won't be logged"
			);
		case SystemCode::CORRUPT_LOG_CORRUPTED:
			RETURN_STATIC_STRING(
					"One of the volume corruption logs is internally corrupted and needs to be"
					" recreated. The volume may contain undetected corruptions and must be scanned"
			);
		case SystemCode::CORRUPT_LOG_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"One of the volume corruption logs is unavailable for being operated on"
			);
		case SystemCode::CORRUPT_LOG_DELETED_FULL:
			RETURN_STATIC_STRING(
					"One of the volume corruption logs was deleted while still having corruption"
					" records in them. The volume contains detected corruptions and must be scanned"
			);
		case SystemCode::CORRUPT_LOG_CLEARED:
			RETURN_STATIC_STRING(
					"One of the volume corruption logs was cleared by chkdsk and no longer contains"
					" real corruptions"
			);
		case SystemCode::ORPHAN_NAME_EXHAUSTED:
			RETURN_STATIC_STRING(
					"Orphaned files exist on the volume but could not be recovered because no more"
					" new names could be created in the recovery directory. Files must be moved"
					" from the recovery directory"
			);
		case SystemCode::OPLOCK_SWITCHED_TO_NEW_HANDLE:
			RETURN_STATIC_STRING(
					"The oplock that was associated with this handle is now associated with a"
					" different handle"
			);
		case SystemCode::CANNOT_GRANT_REQUESTED_OPLOCK:
			RETURN_STATIC_STRING(
					"An oplock of the requested level cannot be granted. An oplock of a lower"
					" level may be available"
			);
		case SystemCode::CANNOT_BREAK_OPLOCK:
			RETURN_STATIC_STRING(
					"The operation did not complete successfully because it would cause an oplock"
					" to be broken. The caller has requested that existing oplocks not be broken"
			);
		case SystemCode::OPLOCK_HANDLE_CLOSED:
			RETURN_STATIC_STRING(
					"The handle with which this oplock was associated has been closed. The oplock"
					" is now broken"
			);
		case SystemCode::NO_ACE_CONDITION:
			RETURN_STATIC_STRING(
					"The specified access control entry (ACE) does not contain a condition"
			);
		case SystemCode::INVALID_ACE_CONDITION:
			RETURN_STATIC_STRING(
					"The specified access control entry (ACE) contains an invalid condition"
			);
		case SystemCode::FILE_HANDLE_REVOKED:
			RETURN_STATIC_STRING(
					"Access to the specified file handle has been revoked"
			);
		case SystemCode::IMAGE_AT_DIFFERENT_BASE:
			RETURN_STATIC_STRING(
					"An image file was mapped at a different address from the one specified in the"
					" image file but fixups will still be automatically performed on the image"
			);
		case SystemCode::EA_ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"Access to the extended attribute was denied"
			);
		case SystemCode::OPERATION_ABORTED:
			RETURN_STATIC_STRING(
					"The I/O operation has been aborted because of either a thread exit or an"
					" application request"
			);
		case SystemCode::IO_INCOMPLETE:
			RETURN_STATIC_STRING(
					"Overlapped I/O event is not in a signaled state"
			);
		case SystemCode::IO_PENDING:
			RETURN_STATIC_STRING(
					"Overlapped I/O operation is in progress"
			);
		case SystemCode::NOACCESS:
			RETURN_STATIC_STRING(
					"Invalid access to memory location"
			);
		case SystemCode::SWAPERROR:
			RETURN_STATIC_STRING(
					"Error performing inpage operation"
			);
		default:
			return nullptr;
	}
}

}}} // flame_ide::os::error
