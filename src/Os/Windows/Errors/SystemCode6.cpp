#include <FlameIDE/../../src/Os/Windows/SystemCode6.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--6000-8199-
enum class SystemCode: decltype(::GetLastError())
{
	ENCRYPTION_FAILED =
#	if defined ERROR_ENCRYPTION_FAILED
			ERROR_ENCRYPTION_FAILED
#	else
			0x1770
#	endif
		// The specified file could not be encrypted.

	, DECRYPTION_FAILED =
#	if defined ERROR_DECRYPTION_FAILED
			ERROR_DECRYPTION_FAILED
#	else
			0x1771
#	endif
		// The specified file could not be decrypted.

	, FILE_ENCRYPTED =
#	if defined ERROR_FILE_ENCRYPTED
			ERROR_FILE_ENCRYPTED
#	else
			0x1772
#	endif
		// The specified file is encrypted and the user does not have the ability to decrypt it.

	, NO_RECOVERY_POLICY =
#	if defined ERROR_NO_RECOVERY_POLICY
			ERROR_NO_RECOVERY_POLICY
#	else
			0x1773
#	endif
		// There is no valid encryption recovery policy configured for this system.

	, NO_EFS =
#	if defined ERROR_NO_EFS
			ERROR_NO_EFS
#	else
			0x1774
#	endif
		// The required encryption driver is not loaded for this system.

	, WRONG_EFS =
#	if defined ERROR_WRONG_EFS
			ERROR_WRONG_EFS
#	else
			0x1775
#	endif
		// The file was encrypted with a different encryption driver than is currently loaded.

	, NO_USER_KEYS =
#	if defined ERROR_NO_USER_KEYS
			ERROR_NO_USER_KEYS
#	else
			0x1776
#	endif
		// There are no EFS keys defined for the user.

	, FILE_NOT_ENCRYPTED =
#	if defined ERROR_FILE_NOT_ENCRYPTED
			ERROR_FILE_NOT_ENCRYPTED
#	else
			0x1777
#	endif
		// The specified file is not encrypted.

	, NOT_EXPORT_FORMAT =
#	if defined ERROR_NOT_EXPORT_FORMAT
			ERROR_NOT_EXPORT_FORMAT
#	else
			0x1778
#	endif
		// The specified file is not in the defined EFS export format.

	, FILE_IS_READ_ONLY =
#	if defined ERROR_FILE_READ_ONLY
			ERROR_FILE_READ_ONLY
#	else
			0x1779
#	endif
		// The specified file is read only.

	, DIR_EFS_DISALLOWED =
#	if defined ERROR_DIR_EFS_DISALLOWED
			ERROR_DIR_EFS_DISALLOWED
#	else
			0x177A
#	endif
		// The directory has been disabled for encryption.

	, EFS_SERVER_NOT_TRUSTED =
#	if defined ERROR_EFS_SERVER_NOT_TRUSTED
			ERROR_EFS_SERVER_NOT_TRUSTED
#	else
			0x177B
#	endif
		// The server is not trusted for remote encryption operation.

	, BAD_RECOVERY_POLICY =
#	if defined ERROR_BAD_RECOVERY_POLICY
			ERROR_BAD_RECOVERY_POLICY
#	else
			0x177C
#	endif
		// Recovery policy configured for this system contains invalid recovery certificate.

	, EFS_ALG_BLOB_TOO_BIG =
#	if defined ERROR_EFS_ALG_BLOB_TOO_BIG
			ERROR_EFS_ALG_BLOB_TOO_BIG
#	else
			0x177D
#	endif
		// The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.

	, VOLUME_NOT_SUPPORT_EFS =
#	if defined ERROR_VOLUME_NOT_SUPPORT_EFS
			ERROR_VOLUME_NOT_SUPPORT_EFS
#	else
			0x177E
#	endif
		// The disk partition does not support file encryption.

	, EFS_DISABLED =
#	if defined ERROR_EFS_DISABLED
			ERROR_EFS_DISABLED
#	else
			0x177F
#	endif
		// This machine is disabled for file encryption.

	, EFS_VERSION_NOT_SUPPORT =
#	if defined ERROR_EFS_VERSION_NOT_SUPPORT
			ERROR_EFS_VERSION_NOT_SUPPORT
#	else
			0x1780
#	endif
		// A newer system is required to decrypt this encrypted file.

	, CS_ENCRYPTION_INVALID_SERVER_RESPONSE =
#	if defined ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE
			ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE
#	else
			0x1781
#	endif
		// The remote server sent an invalid response for a file being opened with Client Side Encryption.

	, CS_ENCRYPTION_UNSUPPORTED_SERVER =
#	if defined ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER
			ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER
#	else
			0x1782
#	endif
		// Client Side Encryption is not supported by the remote server even though it claims to support it.

	, CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE =
#	if defined ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE
			ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE
#	else
			0x1783
#	endif
		// File is encrypted and should be opened in Client Side Encryption mode.

	, CS_ENCRYPTION_NEW_ENCRYPTED_FILE =
#	if defined ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE
			ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE
#	else
			0x1784
#	endif
		// A new encrypted file is being created and a $EFS needs to be provided.

	, CS_ENCRYPTION_FILE_NOT_CSE =
#	if defined ERROR_CS_ENCRYPTION_FILE_NOT_CSE
			ERROR_CS_ENCRYPTION_FILE_NOT_CSE
#	else
			0x1785
#	endif
		// The SMB client requested a CSE FSCTL on a non-CSE file.

	, ENCRYPTION_POLICY_DENIES_OPERATION =
#	if defined ERROR_ENCRYPTION_POLICY_DENIES_OPERATION
			ERROR_ENCRYPTION_POLICY_DENIES_OPERATION
#	else
			0x1786
#	endif
		// The requested operation was blocked by policy. For more information, contact your system administrator.

	, NO_BROWSER_SERVERS_FOUND =
#	if defined ERROR_NO_BROWSER_SERVERS_FOUND
			ERROR_NO_BROWSER_SERVERS_FOUND
#	else
			0x17E6
#	endif
		// The list of servers for this workgroup is not currently available.

	, E_SERVICE_NOT_LOCALSYSTEM =
#	if defined SCHED_E_SERVICE_NOT_LOCALSYSTEM
			SCHED_E_SERVICE_NOT_LOCALSYSTEM
#	else
			0x1838
#	endif
		// The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.

	, LOG_SECTOR_INVALID =
#	if defined ERROR_LOG_SECTOR_INVALID
			ERROR_LOG_SECTOR_INVALID
#	else
			0x19C8
#	endif
		// Log service encountered an invalid log sector.

	, LOG_SECTOR_PARITY_INVALID =
#	if defined ERROR_LOG_SECTOR_PARITY_INVALID
			ERROR_LOG_SECTOR_PARITY_INVALID
#	else
			0x19C9
#	endif
		// Log service encountered a log sector with invalid block parity.

	, LOG_SECTOR_REMAPPED =
#	if defined ERROR_LOG_SECTOR_REMAPPED
			ERROR_LOG_SECTOR_REMAPPED
#	else
			0x19CA
#	endif
		// Log service encountered a remapped log sector.

	, LOG_BLOCK_INCOMPLETE =
#	if defined ERROR_LOG_BLOCK_INCOMPLETE
			ERROR_LOG_BLOCK_INCOMPLETE
#	else
			0x19CB
#	endif
		// Log service encountered a partial or incomplete log block.

	, LOG_INVALID_RANGE =
#	if defined ERROR_LOG_INVALID_RANGE
			ERROR_LOG_INVALID_RANGE
#	else
			0x19CC
#	endif
		// Log service encountered an attempt access data outside the active log range.

	, LOG_BLOCKS_EXHAUSTED =
#	if defined ERROR_LOG_BLOCKS_EXHAUSTED
			ERROR_LOG_BLOCKS_EXHAUSTED
#	else
			0x19CD
#	endif
		// Log service user marshalling buffers are exhausted.

	, LOG_READ_CONTEXT_INVALID =
#	if defined ERROR_LOG_READ_CONTEXT_INVALID
			ERROR_LOG_READ_CONTEXT_INVALID
#	else
			0x19CE
#	endif
		// Log service encountered an attempt read from a marshalling area with an invalid read context.

	, LOG_RESTART_INVALID =
#	if defined ERROR_LOG_RESTART_INVALID
			ERROR_LOG_RESTART_INVALID
#	else
			0x19CF
#	endif
		// Log service encountered an invalid log restart area.

	, LOG_BLOCK_VERSION =
#	if defined ERROR_LOG_BLOCK_VERSION
			ERROR_LOG_BLOCK_VERSION
#	else
			0x19D0
#	endif
		// Log service encountered an invalid log block version.

	, LOG_BLOCK_INVALID =
#	if defined ERROR_LOG_BLOCK_INVALID
			ERROR_LOG_BLOCK_INVALID
#	else
			0x19D1
#	endif
		// Log service encountered an invalid log block.

	, LOG_READ_MODE_INVALID =
#	if defined ERROR_LOG_READ_MODE_INVALID
			ERROR_LOG_READ_MODE_INVALID
#	else
			0x19D2
#	endif
		// Log service encountered an attempt to read the log with an invalid read mode.

	, LOG_NO_RESTART =
#	if defined ERROR_LOG_NO_RESTART
			ERROR_LOG_NO_RESTART
#	else
			0x19D3
#	endif
		// Log service encountered a log stream with no restart area.

	, LOG_METADATA_CORRUPT =
#	if defined ERROR_LOG_METADATA_CORRUPT
			ERROR_LOG_METADATA_CORRUPT
#	else
			0x19D4
#	endif
		// Log service encountered a corrupted metadata file.

	, LOG_METADATA_INVALID =
#	if defined ERROR_LOG_METADATA_INVALID
			ERROR_LOG_METADATA_INVALID
#	else
			0x19D5
#	endif
		// Log service encountered a metadata file that could not be created by the log file system.

	, LOG_METADATA_INCONSISTENT =
#	if defined ERROR_LOG_METADATA_INCONSISTENT
			ERROR_LOG_METADATA_INCONSISTENT
#	else
			0x19D6
#	endif
		// Log service encountered a metadata file with inconsistent data.

	, LOG_RESERVATION_INVALID =
#	if defined ERROR_LOG_RESERVATION_INVALID
			ERROR_LOG_RESERVATION_INVALID
#	else
			0x19D7
#	endif
		// Log service encountered an attempt to erroneous allocate or dispose reservation space.

	, LOG_CANT_DELETE =
#	if defined ERROR_LOG_CANT_DELETE
			ERROR_LOG_CANT_DELETE
#	else
			0x19D8
#	endif
		// Log service cannot delete log file or file system container.

	, LOG_CONTAINER_LIMIT_EXCEEDED =
#	if defined ERROR_LOG_CONTAINER_LIMIT_EXCEEDED
			ERROR_LOG_CONTAINER_LIMIT_EXCEEDED
#	else
			0x19D9
#	endif
		// Log service has reached the maximum allowable containers allocated to a log file.

	, LOG_START_OF_LOG =
#	if defined ERROR_LOG_START_OF_LOG
			ERROR_LOG_START_OF_LOG
#	else
			0x19DA
#	endif
		// Log service has attempted to read or write backward past the start of the log.

	, LOG_POLICY_ALREADY_INSTALLED =
#	if defined ERROR_LOG_POLICY_ALREADY_INSTALLED
			ERROR_LOG_POLICY_ALREADY_INSTALLED
#	else
			0x19DB
#	endif
		// Log policy could not be installed because a policy of the same type is already present.

	, LOG_POLICY_NOT_INSTALLED =
#	if defined ERROR_LOG_POLICY_NOT_INSTALLED
			ERROR_LOG_POLICY_NOT_INSTALLED
#	else
			0x19DC
#	endif
		// Log policy in question was not installed at the time of the request.

	, LOG_POLICY_INVALID =
#	if defined ERROR_LOG_POLICY_INVALID
			ERROR_LOG_POLICY_INVALID
#	else
			0x19DD
#	endif
		// The installed set of policies on the log is invalid.

	, LOG_POLICY_CONFLICT =
#	if defined ERROR_LOG_POLICY_CONFLICT
			ERROR_LOG_POLICY_CONFLICT
#	else
			0x19DE
#	endif
		// A policy on the log in question prevented the operation from completing.

	, LOG_PINNED_ARCHIVE_TAIL =
#	if defined ERROR_LOG_PINNED_ARCHIVE_TAIL
			ERROR_LOG_PINNED_ARCHIVE_TAIL
#	else
			0x19DF
#	endif
		// Log space cannot be reclaimed because the log is pinned by the archive tail.

	, LOG_RECORD_NONEXISTENT =
#	if defined ERROR_LOG_RECORD_NONEXISTENT
			ERROR_LOG_RECORD_NONEXISTENT
#	else
			0x19E0
#	endif
		// Log record is not a record in the log file.

	, LOG_RECORDS_RESERVED_INVALID =
#	if defined ERROR_LOG_RECORDS_RESERVED_INVALID
			ERROR_LOG_RECORDS_RESERVED_INVALID
#	else
			0x19E1
#	endif
		// Number of reserved log records or the adjustment of the number of reserved log records is invalid.

	, LOG_SPACE_RESERVED_INVALID =
#	if defined ERROR_LOG_SPACE_RESERVED_INVALID
			ERROR_LOG_SPACE_RESERVED_INVALID
#	else
			0x19E2
#	endif
		// Reserved log space or the adjustment of the log space is invalid.

	, LOG_TAIL_INVALID =
#	if defined ERROR_LOG_TAIL_INVALID
			ERROR_LOG_TAIL_INVALID
#	else
			0x19E3
#	endif
		// An new or existing archive tail or base of the active log is invalid.

	, LOG_FULL =
#	if defined ERROR_LOG_FULL
			ERROR_LOG_FULL
#	else
			0x19E4
#	endif
		// Log space is exhausted.

	, COULD_NOT_RESIZE_LOG =
#	if defined ERROR_COULD_NOT_RESIZE_LOG
			ERROR_COULD_NOT_RESIZE_LOG
#	else
			0x19E5
#	endif
		// The log could not be set to the requested size.

	, LOG_MULTIPLEXED =
#	if defined ERROR_LOG_MULTIPLEXED
			ERROR_LOG_MULTIPLEXED
#	else
			0x19E6
#	endif
		// Log is multiplexed, no direct writes to the physical log is allowed.

	, LOG_DEDICATED =
#	if defined ERROR_LOG_DEDICATED
			ERROR_LOG_DEDICATED
#	else
			0x19E7
#	endif
		// The operation failed because the log is a dedicated log.

	, LOG_ARCHIVE_NOT_IN_PROGRESS =
#	if defined ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS
			ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS
#	else
			0x19E8
#	endif
		// The operation requires an archive context.

	, LOG_ARCHIVE_IN_PROGRESS =
#	if defined ERROR_LOG_ARCHIVE_IN_PROGRESS
			ERROR_LOG_ARCHIVE_IN_PROGRESS
#	else
			0x19E9
#	endif
		// Log archival is in progress.

	, LOG_EPHEMERAL =
#	if defined ERROR_LOG_EPHEMERAL
			ERROR_LOG_EPHEMERAL
#	else
			0x19EA
#	endif
		// The operation requires a non-ephemeral log, but the log is ephemeral.

	, LOG_NOT_ENOUGH_CONTAINERS =
#	if defined ERROR_LOG_NOT_ENOUGH_CONTAINERS
			ERROR_LOG_NOT_ENOUGH_CONTAINERS
#	else
			0x19EB
#	endif
		// The log must have at least two containers before it can be read from or written to.

	, LOG_CLIENT_ALREADY_REGISTERED =
#	if defined ERROR_LOG_CLIENT_ALREADY_REGISTERED
			ERROR_LOG_CLIENT_ALREADY_REGISTERED
#	else
			0x19EC
#	endif
		// A log client has already registered on the stream.

	, LOG_CLIENT_NOT_REGISTERED =
#	if defined ERROR_LOG_CLIENT_NOT_REGISTERED
			ERROR_LOG_CLIENT_NOT_REGISTERED
#	else
			0x19ED
#	endif
		// A log client has not been registered on the stream.

	, LOG_FULL_HANDLER_IN_PROGRESS =
#	if defined ERROR_LOG_FULL_HANDLER_IN_PROGRESS
			ERROR_LOG_FULL_HANDLER_IN_PROGRESS
#	else
			0x19EE
#	endif
		// A request has already been made to handle the log full condition.

	, LOG_CONTAINER_READ_FAILED =
#	if defined ERROR_LOG_CONTAINER_READ_FAILED
			ERROR_LOG_CONTAINER_READ_FAILED
#	else
			0x19EF
#	endif
		// Log service encountered an error when attempting to read from a log container.

	, LOG_CONTAINER_WRITE_FAILED =
#	if defined ERROR_LOG_CONTAINER_WRITE_FAILED
			ERROR_LOG_CONTAINER_WRITE_FAILED
#	else
			0x19F0
#	endif
		// Log service encountered an error when attempting to write to a log container.

	, LOG_CONTAINER_OPEN_FAILED =
#	if defined ERROR_LOG_CONTAINER_OPEN_FAILED
			ERROR_LOG_CONTAINER_OPEN_FAILED
#	else
			0x19F1
#	endif
		// Log service encountered an error when attempting open a log container.

	, LOG_CONTAINER_STATE_INVALID =
#	if defined ERROR_LOG_CONTAINER_STATE_INVALID
			ERROR_LOG_CONTAINER_STATE_INVALID
#	else
			0x19F2
#	endif
		// Log service encountered an invalid container state when attempting a requested action.

	, LOG_STATE_INVALID =
#	if defined ERROR_LOG_STATE_INVALID
			ERROR_LOG_STATE_INVALID
#	else
			0x19F3
#	endif
		// Log service is not in the correct state to perform a requested action.

	, LOG_PINNED =
#	if defined ERROR_LOG_PINNED
			ERROR_LOG_PINNED
#	else
			0x19F4
#	endif
		// Log space cannot be reclaimed because the log is pinned.

	, LOG_METADATA_FLUSH_FAILED =
#	if defined ERROR_LOG_METADATA_FLUSH_FAILED
			ERROR_LOG_METADATA_FLUSH_FAILED
#	else
			0x19F5
#	endif
		// Log metadata flush failed.

	, LOG_INCONSISTENT_SECURITY =
#	if defined ERROR_LOG_INCONSISTENT_SECURITY
			ERROR_LOG_INCONSISTENT_SECURITY
#	else
			0x19F6
#	endif
		// Security on the log and its containers is inconsistent.

	, LOG_APPENDED_FLUSH_FAILED =
#	if defined ERROR_LOG_APPENDED_FLUSH_FAILED
			ERROR_LOG_APPENDED_FLUSH_FAILED
#	else
			0x19F7
#	endif
		// Records were appended to the log or reservation changes were made, but the log could not be flushed.

	, LOG_PINNED_RESERVATION =
#	if defined ERROR_LOG_PINNED_RESERVATION
			ERROR_LOG_PINNED_RESERVATION
#	else
			0x19F8
#	endif
		// The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.

	, INVALID_TRANSACTION =
#	if defined ERROR_INVALID_TRANSACTION
			ERROR_INVALID_TRANSACTION
#	else
			0x1A2C
#	endif
		// The transaction handle associated with this operation is not valid.

	, TRANSACTION_NOT_ACTIVE =
#	if defined ERROR_TRANSACTION_NOT_ACTIVE
			ERROR_TRANSACTION_NOT_ACTIVE
#	else
			0x1A2D
#	endif
		// The requested operation was made in the context of a transaction that is no longer active.

	, TRANSACTION_REQUEST_NOT_VALID =
#	if defined ERROR_TRANSACTION_REQUEST_NOT_VALID
			ERROR_TRANSACTION_REQUEST_NOT_VALID
#	else
			0x1A2E
#	endif
		// The requested operation is not valid on the Transaction object in its current state.

	, TRANSACTION_NOT_REQUESTED =
#	if defined ERROR_TRANSACTION_NOT_REQUESTED
			ERROR_TRANSACTION_NOT_REQUESTED
#	else
			0x1A2F
#	endif
		// The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.

	, TRANSACTION_ALREADY_ABORTED =
#	if defined ERROR_TRANSACTION_ALREADY_ABORTED
			ERROR_TRANSACTION_ALREADY_ABORTED
#	else
			0x1A30
#	endif
		// It is too late to perform the requested operation, since the Transaction has already been aborted.

	, TRANSACTION_ALREADY_COMMITTED =
#	if defined ERROR_TRANSACTION_ALREADY_COMMITTED
			ERROR_TRANSACTION_ALREADY_COMMITTED
#	else
			0x1A31
#	endif
		// It is too late to perform the requested operation, since the Transaction has already been committed.

	, TM_INITIALIZATION_FAILED =
#	if defined ERROR_TM_INITIALIZATION_FAILED
			ERROR_TM_INITIALIZATION_FAILED
#	else
			0x1A32
#	endif
		// The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.

	, RESOURCEMANAGER_READ_ONLY =
#	if defined ERROR_RESOURCEMANAGER_READ_ONLY
			ERROR_RESOURCEMANAGER_READ_ONLY
#	else
			0x1A33
#	endif
		// The specified ResourceManager made no changes or updates to the resource under this transaction.

	, TRANSACTION_NOT_JOINED =
#	if defined ERROR_TRANSACTION_NOT_JOINED
			ERROR_TRANSACTION_NOT_JOINED
#	else
			0x1A34
#	endif
		// The resource manager has attempted to prepare a transaction that it has not successfully joined.

	, TRANSACTION_SUPERIOR_EXISTS =
#	if defined ERROR_TRANSACTION_SUPERIOR_EXISTS
			ERROR_TRANSACTION_SUPERIOR_EXISTS
#	else
			0x1A35
#	endif
		// The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.

	, CRM_PROTOCOL_ALREADY_EXISTS =
#	if defined ERROR_CRM_PROTOCOL_ALREADY_EXISTS
			ERROR_CRM_PROTOCOL_ALREADY_EXISTS
#	else
			0x1A36
#	endif
		// The RM tried to register a protocol that already exists.

	, TRANSACTION_PROPAGATION_FAILED =
#	if defined ERROR_TRANSACTION_PROPAGATION_FAILED
			ERROR_TRANSACTION_PROPAGATION_FAILED
#	else
			0x1A37
#	endif
		// The attempt to propagate the Transaction failed.

	, CRM_PROTOCOL_NOT_FOUND =
#	if defined ERROR_CRM_PROTOCOL_NOT_FOUND
			ERROR_CRM_PROTOCOL_NOT_FOUND
#	else
			0x1A38
#	endif
		// The requested propagation protocol was not registered as a CRM.

	, TRANSACTION_INVALID_MARSHALL_BUFFER =
#	if defined ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER
			ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER
#	else
			0x1A39
#	endif
		// The buffer passed in to PushTransaction or PullTransaction is not in a valid format.

	, CURRENT_TRANSACTION_NOT_VALID =
#	if defined ERROR_CURRENT_TRANSACTION_NOT_VALID
			ERROR_CURRENT_TRANSACTION_NOT_VALID
#	else
			0x1A3A
#	endif
		// The current transaction context associated with the thread is not a valid handle to a transaction object.

	, TRANSACTION_NOT_FOUND =
#	if defined ERROR_TRANSACTION_NOT_FOUND
			ERROR_TRANSACTION_NOT_FOUND
#	else
			0x1A3B
#	endif
		// The specified Transaction object could not be opened, because it was not found.

	, RESOURCEMANAGER_NOT_FOUND =
#	if defined ERROR_RESOURCEMANAGER_NOT_FOUND
			ERROR_RESOURCEMANAGER_NOT_FOUND
#	else
			0x1A3C
#	endif
		// The specified ResourceManager object could not be opened, because it was not found.

	, ENLISTMENT_NOT_FOUND =
#	if defined ERROR_ENLISTMENT_NOT_FOUND
			ERROR_ENLISTMENT_NOT_FOUND
#	else
			0x1A3D
#	endif
		// The specified Enlistment object could not be opened, because it was not found.

	, TRANSACTIONMANAGER_NOT_FOUND =
#	if defined ERROR_TRANSACTIONMANAGER_NOT_FOUND
			ERROR_TRANSACTIONMANAGER_NOT_FOUND
#	else
			0x1A3E
#	endif
		// The specified TransactionManager object could not be opened, because it was not found.

	, TRANSACTIONMANAGER_NOT_ONLINE =
#	if defined ERROR_TRANSACTIONMANAGER_NOT_ONLINE
			ERROR_TRANSACTIONMANAGER_NOT_ONLINE
#	else
			0x1A3F
#	endif
		// The object specified could not be created or opened, because its associated TransactionManager is not online. The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened. In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.

	, TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION =
#	if defined ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION
			ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION
#	else
			0x1A40
#	endif
		// The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.

	, TRANSACTION_NOT_ROOT =
#	if defined ERROR_TRANSACTION_NOT_ROOT
			ERROR_TRANSACTION_NOT_ROOT
#	else
			0x1A41
#	endif
		// The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.

	, TRANSACTION_OBJECT_EXPIRED =
#	if defined ERROR_TRANSACTION_OBJECT_EXPIRED
			ERROR_TRANSACTION_OBJECT_EXPIRED
#	else
			0x1A42
#	endif
		// Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.

	, TRANSACTION_RESPONSE_NOT_ENLISTED =
#	if defined ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED
			ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED
#	else
			0x1A43
#	endif
		// The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.

	, TRANSACTION_RECORD_TOO_LONG =
#	if defined ERROR_TRANSACTION_RECORD_TOO_LONG
			ERROR_TRANSACTION_RECORD_TOO_LONG
#	else
			0x1A44
#	endif
		// The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.

	, IMPLICIT_TRANSACTION_NOT_SUPPORTED =
#	if defined ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED
			ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED
#	else
			0x1A45
#	endif
		// Implicit transaction are not supported.

	, TRANSACTION_INTEGRITY_VIOLATED =
#	if defined ERROR_TRANSACTION_INTEGRITY_VIOLATED
			ERROR_TRANSACTION_INTEGRITY_VIOLATED
#	else
			0x1A46
#	endif
		// The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.

	, TRANSACTIONMANAGER_IDENTITY_MISMATCH =
#	if defined ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH
			ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH
#	else
			0x1A47
#	endif
		// The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.

	, RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT =
#	if defined ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT
			ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT
#	else
			0x1A48
#	endif
		// This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state. Please try again.

	, TRANSACTION_MUST_WRITETHROUGH =
#	if defined ERROR_TRANSACTION_MUST_WRITETHROUGH
			ERROR_TRANSACTION_MUST_WRITETHROUGH
#	else
			0x1A49
#	endif
		// The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase. In order to ensure correctness, the ResourceManager must switch to a write- through mode and cease caching data within this transaction. Enlisting for only subsequent transaction phases may still succeed.

	, TRANSACTION_NO_SUPERIOR =
#	if defined ERROR_TRANSACTION_NO_SUPERIOR
			ERROR_TRANSACTION_NO_SUPERIOR
#	else
			0x1A4A
#	endif
		// The transaction does not have a superior enlistment.

	, HEURISTIC_DAMAGE_POSSIBLE =
#	if defined ERROR_HEURISTIC_DAMAGE_POSSIBLE
			ERROR_HEURISTIC_DAMAGE_POSSIBLE
#	else
			0x1A4B
#	endif
		// The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics. Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency. If possible, check the consistency of the associated data.

	, TRANSACTIONAL_CONFLICT =
#	if defined ERROR_TRANSACTIONAL_CONFLICT
			ERROR_TRANSACTIONAL_CONFLICT
#	else
			0x1A90
#	endif
		// The function attempted to use a name that is reserved for use by another transaction.

	, RM_NOT_ACTIVE =
#	if defined ERROR_RM_NOT_ACTIVE
			ERROR_RM_NOT_ACTIVE
#	else
			0x1A91
#	endif
		// Transaction support within the specified resource manager is not started or was shut down due to an error.

	, RM_METADATA_CORRUPT =
#	if defined ERROR_RM_METADATA_CORRUPT
			ERROR_RM_METADATA_CORRUPT
#	else
			0x1A92
#	endif
		// The metadata of the RM has been corrupted. The RM will not function.

	, DIRECTORY_NOT_RM =
#	if defined ERROR_DIRECTORY_NOT_RM
			ERROR_DIRECTORY_NOT_RM
#	else
			0x1A93
#	endif
		// The specified directory does not contain a resource manager.

	, TRANSACTIONS_UNSUPPORTED_REMOTE =
#	if defined ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE
			ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE
#	else
			0x1A95
#	endif
		// The remote server or share does not support transacted file operations.

	, LOG_RESIZE_INVALID_SIZE =
#	if defined ERROR_LOG_RESIZE_INVALID_SIZE
			ERROR_LOG_RESIZE_INVALID_SIZE
#	else
			0x1A96
#	endif
		// The requested log size is invalid.

	, OBJECT_NO_LONGER_EXISTS =
#	if defined ERROR_OBJECT_NO_LONGER_EXISTS
			ERROR_OBJECT_NO_LONGER_EXISTS
#	else
			0x1A97
#	endif
		// The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.

	, STREAM_MINIVERSION_NOT_FOUND =
#	if defined ERROR_STREAM_MINIVERSION_NOT_FOUND
			ERROR_STREAM_MINIVERSION_NOT_FOUND
#	else
			0x1A98
#	endif
		// The specified file miniversion was not found for this transacted file open.

	, STREAM_MINIVERSION_NOT_VALID =
#	if defined ERROR_STREAM_MINIVERSION_NOT_VALID
			ERROR_STREAM_MINIVERSION_NOT_VALID
#	else
			0x1A99
#	endif
		// The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.

	, MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION =
#	if defined ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION
			ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION
#	else
			0x1A9A
#	endif
		// A miniversion may only be opened in the context of the transaction that created it.

	, CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT =
#	if defined ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT
			ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT
#	else
			0x1A9B
#	endif
		// It is not possible to open a miniversion with modify access.

	, CANT_CREATE_MORE_STREAM_MINIVERSIONS =
#	if defined ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS
			ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS
#	else
			0x1A9C
#	endif
		// It is not possible to create any more miniversions for this stream.

	, REMOTE_FILE_VERSION_MISMATCH =
#	if defined ERROR_REMOTE_FILE_VERSION_MISMATCH
			ERROR_REMOTE_FILE_VERSION_MISMATCH
#	else
			0x1A9E
#	endif
		// The remote server sent mismatching version number or Fid for a file opened with transactions.

	, HANDLE_NO_LONGER_VALID =
#	if defined ERROR_HANDLE_NO_LONGER_VALID
			ERROR_HANDLE_NO_LONGER_VALID
#	else
			0x1A9F
#	endif
		// The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.

	, NO_TXF_METADATA =
#	if defined ERROR_NO_TXF_METADATA
			ERROR_NO_TXF_METADATA
#	else
			0x1AA0
#	endif
		// There is no transaction metadata on the file.

	, LOG_CORRUPTION_DETECTED =
#	if defined ERROR_LOG_CORRUPTION_DETECTED
			ERROR_LOG_CORRUPTION_DETECTED
#	else
			0x1AA1
#	endif
		// The log data is corrupt.

	, CANT_RECOVER_WITH_HANDLE_OPEN =
#	if defined ERROR_CANT_RECOVER_WITH_HANDLE_OPEN
			ERROR_CANT_RECOVER_WITH_HANDLE_OPEN
#	else
			0x1AA2
#	endif
		// The file can't be recovered because there is a handle still open on it.

	, RM_DISCONNECTED =
#	if defined ERROR_RM_DISCONNECTED
			ERROR_RM_DISCONNECTED
#	else
			0x1AA3
#	endif
		// The transaction outcome is unavailable because the resource manager responsible for it has disconnected.

	, ENLISTMENT_NOT_SUPERIOR =
#	if defined ERROR_ENLISTMENT_NOT_SUPERIOR
			ERROR_ENLISTMENT_NOT_SUPERIOR
#	else
			0x1AA4
#	endif
		// The request was rejected because the enlistment in question is not a superior enlistment.

	, RECOVERY_NOT_NEEDED =
#	if defined ERROR_RECOVERY_NOT_NEEDED
			ERROR_RECOVERY_NOT_NEEDED
#	else
			0x1AA5
#	endif
		// The transactional resource manager is already consistent. Recovery is not needed.

	, RM_ALREADY_STARTED =
#	if defined ERROR_RM_ALREADY_STARTED
			ERROR_RM_ALREADY_STARTED
#	else
			0x1AA6
#	endif
		// The transactional resource manager has already been started.

	, FILE_IDENTITY_NOT_PERSISTENT =
#	if defined ERROR_FILE_IDENTITY_NOT_PERSISTENT
			ERROR_FILE_IDENTITY_NOT_PERSISTENT
#	else
			0x1AA7
#	endif
		// The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.

	, CANT_BREAK_TRANSACTIONAL_DEPENDENCY =
#	if defined ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY
			ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY
#	else
			0x1AA8
#	endif
		// The operation cannot be performed because another transaction is depending on the fact that this property will not change.

	, CANT_CROSS_RM_BOUNDARY =
#	if defined ERROR_CANT_CROSS_RM_BOUNDARY
			ERROR_CANT_CROSS_RM_BOUNDARY
#	else
			0x1AA9
#	endif
		// The operation would involve a single file with two transactional resource managers and is therefore not allowed.

	, TXF_DIR_NOT_EMPTY =
#	if defined ERROR_TXF_DIR_NOT_EMPTY
			ERROR_TXF_DIR_NOT_EMPTY
#	else
			0x1AAA
#	endif
		// The $Txf directory must be empty for this operation to succeed.

	, INDOUBT_TRANSACTIONS_EXIST =
#	if defined ERROR_INDOUBT_TRANSACTIONS_EXIST
			ERROR_INDOUBT_TRANSACTIONS_EXIST
#	else
			0x1AAB
#	endif
		// The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.

	, TM_VOLATILE =
#	if defined ERROR_TM_VOLATILE
			ERROR_TM_VOLATILE
#	else
			0x1AAC
#	endif
		// The operation could not be completed because the transaction manager does not have a log.

	, ROLLBACK_TIMER_EXPIRED =
#	if defined ERROR_ROLLBACK_TIMER_EXPIRED
			ERROR_ROLLBACK_TIMER_EXPIRED
#	else
			0x1AAD
#	endif
		// A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.

	, TXF_ATTRIBUTE_CORRUPT =
#	if defined ERROR_TXF_ATTRIBUTE_CORRUPT
			ERROR_TXF_ATTRIBUTE_CORRUPT
#	else
			0x1AAE
#	endif
		// The transactional metadata attribute on the file or directory is corrupt and unreadable.

	, EFS_NOT_ALLOWED_IN_TRANSACTION =
#	if defined ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION
			ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION
#	else
			0x1AAF
#	endif
		// The encryption operation could not be completed because a transaction is active.

	, TRANSACTIONAL_OPEN_NOT_ALLOWED =
#	if defined ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED
			ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED
#	else
			0x1AB0
#	endif
		// This object is not allowed to be opened in a transaction.

	, LOG_GROWTH_FAILED =
#	if defined ERROR_LOG_GROWTH_FAILED
			ERROR_LOG_GROWTH_FAILED
#	else
			0x1AB1
#	endif
		// An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.

	, TRANSACTED_MAPPING_UNSUPPORTED_REMOTE =
#	if defined ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE
			ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE
#	else
			0x1AB2
#	endif
		// Memory mapping (creating a mapped section) a remote file under a transaction is not supported.

	, TXF_METADATA_ALREADY_PRESENT =
#	if defined ERROR_TXF_METADATA_ALREADY_PRESENT
			ERROR_TXF_METADATA_ALREADY_PRESENT
#	else
			0x1AB3
#	endif
		// Transaction metadata is already present on this file and cannot be superseded.

	, TRANSACTION_SCOPE_CALLBACKS_NOT_SET =
#	if defined ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET
			ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET
#	else
			0x1AB4
#	endif
		// A transaction scope could not be entered because the scope handler has not been initialized.

	, TRANSACTION_REQUIRED_PROMOTION =
#	if defined ERROR_TRANSACTION_REQUIRED_PROMOTION
			ERROR_TRANSACTION_REQUIRED_PROMOTION
#	else
			0x1AB5
#	endif
		// Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.

	, CANNOT_EXECUTE_FILE_IN_TRANSACTION =
#	if defined ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION
			ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION
#	else
			0x1AB6
#	endif
		// This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.

	, TRANSACTIONS_NOT_FROZEN =
#	if defined ERROR_TRANSACTIONS_NOT_FROZEN
			ERROR_TRANSACTIONS_NOT_FROZEN
#	else
			0x1AB7
#	endif
		// The request to thaw frozen transactions was ignored because transactions had not previously been frozen.

	, TRANSACTION_FREEZE_IN_PROGRESS =
#	if defined ERROR_TRANSACTION_FREEZE_IN_PROGRESS
			ERROR_TRANSACTION_FREEZE_IN_PROGRESS
#	else
			0x1AB8
#	endif
		// Transactions cannot be frozen because a freeze is already in progress.

	, NOT_SNAPSHOT_VOLUME =
#	if defined ERROR_NOT_SNAPSHOT_VOLUME
			ERROR_NOT_SNAPSHOT_VOLUME
#	else
			0x1AB9
#	endif
		// The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.

	, NO_SAVEPOINT_WITH_OPEN_FILES =
#	if defined ERROR_NO_SAVEPOINT_WITH_OPEN_FILES
			ERROR_NO_SAVEPOINT_WITH_OPEN_FILES
#	else
			0x1ABA
#	endif
		// The savepoint operation failed because files are open on the transaction. This is not permitted.

	, DATA_LOST_REPAIR =
#	if defined ERROR_DATA_LOST_REPAIR
			ERROR_DATA_LOST_REPAIR
#	else
			0x1ABB
#	endif
		// Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.

	, SPARSE_NOT_ALLOWED_IN_TRANSACTION =
#	if defined ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION
			ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION
#	else
			0x1ABC
#	endif
		// The sparse operation could not be completed because a transaction is active on the file.

	, TM_IDENTITY_MISMATCH =
#	if defined ERROR_TM_IDENTITY_MISMATCH
			ERROR_TM_IDENTITY_MISMATCH
#	else
			0x1ABD
#	endif
		// The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.

	, FLOATED_SECTION =
#	if defined ERROR_FLOATED_SECTION
			ERROR_FLOATED_SECTION
#	else
			0x1ABE
#	endif
		// I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.

	, CANNOT_ACCEPT_TRANSACTED_WORK =
#	if defined ERROR_CANNOT_ACCEPT_TRANSACTED_WORK
			ERROR_CANNOT_ACCEPT_TRANSACTED_WORK
#	else
			0x1ABF
#	endif
		// The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.

	, CANNOT_ABORT_TRANSACTIONS =
#	if defined ERROR_CANNOT_ABORT_TRANSACTIONS
			ERROR_CANNOT_ABORT_TRANSACTIONS
#	else
			0x1AC0
#	endif
		// The transactional resource manager had too many tranactions outstanding that could not be aborted. The transactional resource manger has been shut down.

	, BAD_CLUSTERS =
#	if defined ERROR_BAD_CLUSTERS
			ERROR_BAD_CLUSTERS
#	else
			0x1AC1
#	endif
		// The operation could not be completed due to bad clusters on disk.

	, COMPRESSION_NOT_ALLOWED_IN_TRANSACTION =
#	if defined ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION
			ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION
#	else
			0x1AC2
#	endif
		// The compression operation could not be completed because a transaction is active on the file.

	, VOLUME_DIRTY =
#	if defined ERROR_VOLUME_DIRTY
			ERROR_VOLUME_DIRTY
#	else
			0x1AC3
#	endif
		// The operation could not be completed because the volume is dirty. Please run chkdsk and try again.

	, NO_LINK_TRACKING_IN_TRANSACTION =
#	if defined ERROR_NO_LINK_TRACKING_IN_TRANSACTION
			ERROR_NO_LINK_TRACKING_IN_TRANSACTION
#	else
			0x1AC4
#	endif
		// The link tracking operation could not be completed because a transaction is active.

	, OPERATION_NOT_SUPPORTED_IN_TRANSACTION =
#	if defined ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION
			ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION
#	else
			0x1AC5
#	endif
		// This operation cannot be performed in a transaction.

	, EXPIRED_HANDLE =
#	if defined ERROR_EXPIRED_HANDLE
			ERROR_EXPIRED_HANDLE
#	else
			0x1AC6
#	endif
		// The handle is no longer properly associated with its transaction. It may have been opened in a transactional resource manager that was subsequently forced to restart. Please close the handle and open a new one.

	, TRANSACTION_NOT_ENLISTED =
#	if defined ERROR_TRANSACTION_NOT_ENLISTED
			ERROR_TRANSACTION_NOT_ENLISTED
#	else
			0x1AC7
#	endif
		// The specified operation could not be performed because the resource manager is not enlisted in the transaction.

	, CTX_WINSTATION_NAME_INVALID =
#	if defined ERROR_CTX_WINSTATION_NAME_INVALID
			ERROR_CTX_WINSTATION_NAME_INVALID
#	else
			0x1B59
#	endif
		// The specified session name is invalid.

	, CTX_INVALID_PD =
#	if defined ERROR_CTX_INVALID_PD
			ERROR_CTX_INVALID_PD
#	else
			0x1B5A
#	endif
		// The specified protocol driver is invalid.

	, CTX_PD_NOT_FOUND =
#	if defined ERROR_CTX_PD_NOT_FOUND
			ERROR_CTX_PD_NOT_FOUND
#	else
			0x1B5B
#	endif
		// The specified protocol driver was not found in the system path.

	, CTX_WD_NOT_FOUND =
#	if defined ERROR_CTX_WD_NOT_FOUND
			ERROR_CTX_WD_NOT_FOUND
#	else
			0x1B5C
#	endif
		// The specified terminal connection driver was not found in the system path.

	, CTX_CANNOT_MAKE_EVENTLOG_ENTRY =
#	if defined ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY
			ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY
#	else
			0x1B5D
#	endif
		// A registry key for event logging could not be created for this session.

	, CTX_SERVICE_NAME_COLLISION =
#	if defined ERROR_CTX_SERVICE_NAME_COLLISION
			ERROR_CTX_SERVICE_NAME_COLLISION
#	else
			0x1B5E
#	endif
		// A service with the same name already exists on the system.

	, CTX_CLOSE_PENDING =
#	if defined ERROR_CTX_CLOSE_PENDING
			ERROR_CTX_CLOSE_PENDING
#	else
			0x1B5F
#	endif
		// A close operation is pending on the session.

	, CTX_NO_OUTBUF =
#	if defined ERROR_CTX_NO_OUTBUF
			ERROR_CTX_NO_OUTBUF
#	else
			0x1B60
#	endif
		// There are no free output buffers available.

	, CTX_MODEM_INF_NOT_FOUND =
#	if defined ERROR_CTX_MODEM_INF_NOT_FOUND
			ERROR_CTX_MODEM_INF_NOT_FOUND
#	else
			0x1B61
#	endif
		// The MODEM.INF file was not found.

	, CTX_INVALID_MODEMNAME =
#	if defined ERROR_CTX_INVALID_MODEMNAME
			ERROR_CTX_INVALID_MODEMNAME
#	else
			0x1B62
#	endif
		// The modem name was not found in MODEM.INF.

	, CTX_MODEM_RESPONSE_ERROR =
#	if defined ERROR_CTX_MODEM_RESPONSE_ERROR
			ERROR_CTX_MODEM_RESPONSE_ERROR
#	else
			0x1B63
#	endif
		// The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.

	, CTX_MODEM_RESPONSE_TIMEOUT =
#	if defined ERROR_CTX_MODEM_RESPONSE_TIMEOUT
			ERROR_CTX_MODEM_RESPONSE_TIMEOUT
#	else
			0x1B64
#	endif
		// The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.

	, CTX_MODEM_RESPONSE_NO_CARRIER =
#	if defined ERROR_CTX_MODEM_RESPONSE_NO_CARRIER
			ERROR_CTX_MODEM_RESPONSE_NO_CARRIER
#	else
			0x1B65
#	endif
		// Carrier detect has failed or carrier has been dropped due to disconnect.

	, CTX_MODEM_RESPONSE_NO_DIALTONE =
#	if defined ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE
			ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE
#	else
			0x1B66
#	endif
		// Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.

	, CTX_MODEM_RESPONSE_BUSY =
#	if defined ERROR_CTX_MODEM_RESPONSE_BUSY
			ERROR_CTX_MODEM_RESPONSE_BUSY
#	else
			0x1B67
#	endif
		// Busy signal detected at remote site on callback.

	, CTX_MODEM_RESPONSE_VOICE =
#	if defined ERROR_CTX_MODEM_RESPONSE_VOICE
			ERROR_CTX_MODEM_RESPONSE_VOICE
#	else
			0x1B68
#	endif
		// Voice detected at remote site on callback.

	, CTX_TD_ERROR =
#	if defined ERROR_CTX_TD_ERROR
			ERROR_CTX_TD_ERROR
#	else
			0x1B69
#	endif
		// Transport driver error.

	, CTX_WINSTATION_NOT_FOUND =
#	if defined ERROR_CTX_WINSTATION_NOT_FOUND
			ERROR_CTX_WINSTATION_NOT_FOUND
#	else
			0x1B6E
#	endif
		// The specified session cannot be found.

	, CTX_WINSTATION_ALREADY_EXISTS =
#	if defined ERROR_CTX_WINSTATION_ALREADY_EXISTS
			ERROR_CTX_WINSTATION_ALREADY_EXISTS
#	else
			0x1B6F
#	endif
		// The specified session name is already in use.

	, CTX_WINSTATION_BUSY =
#	if defined ERROR_CTX_WINSTATION_BUSY
			ERROR_CTX_WINSTATION_BUSY
#	else
			0x1B70
#	endif
		// The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.

	, CTX_BAD_VIDEO_MODE =
#	if defined ERROR_CTX_BAD_VIDEO_MODE
			ERROR_CTX_BAD_VIDEO_MODE
#	else
			0x1B71
#	endif
		// An attempt has been made to connect to a session whose video mode is not supported by the current client.

	, CTX_GRAPHICS_INVALID =
#	if defined ERROR_CTX_GRAPHICS_INVALID
			ERROR_CTX_GRAPHICS_INVALID
#	else
			0x1B7B
#	endif
		// The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.

	, CTX_LOGON_DISABLED =
#	if defined ERROR_CTX_LOGON_DISABLED
			ERROR_CTX_LOGON_DISABLED
#	else
			0x1B7D
#	endif
		// Your interactive logon privilege has been disabled. Please contact your administrator.

	, CTX_NOT_CONSOLE =
#	if defined ERROR_CTX_NOT_CONSOLE
			ERROR_CTX_NOT_CONSOLE
#	else
			0x1B7E
#	endif
		// The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.

	, CTX_CLIENT_QUERY_TIMEOUT =
#	if defined ERROR_CTX_CLIENT_QUERY_TIMEOUT
			ERROR_CTX_CLIENT_QUERY_TIMEOUT
#	else
			0x1B80
#	endif
		// The client failed to respond to the server connect message.

	, CTX_CONSOLE_DISCONNECT =
#	if defined ERROR_CTX_CONSOLE_DISCONNECT
			ERROR_CTX_CONSOLE_DISCONNECT
#	else
			0x1B81
#	endif
		// Disconnecting the console session is not supported.

	, CTX_CONSOLE_CONNECT =
#	if defined ERROR_CTX_CONSOLE_CONNECT
			ERROR_CTX_CONSOLE_CONNECT
#	else
			0x1B82
#	endif
		// Reconnecting a disconnected session to the console is not supported.

	, CTX_SHADOW_DENIED =
#	if defined ERROR_CTX_SHADOW_DENIED
			ERROR_CTX_SHADOW_DENIED
#	else
			0x1B84
#	endif
		// The request to control another session remotely was denied.

	, CTX_WINSTATION_ACCESS_DENIED =
#	if defined ERROR_CTX_WINSTATION_ACCESS_DENIED
			ERROR_CTX_WINSTATION_ACCESS_DENIED
#	else
			0x1B85
#	endif
		// The requested session access is denied.

	, CTX_INVALID_WD =
#	if defined ERROR_CTX_INVALID_WD
			ERROR_CTX_INVALID_WD
#	else
			0x1B89
#	endif
		// The specified terminal connection driver is invalid.

	, CTX_SHADOW_INVALID =
#	if defined ERROR_CTX_SHADOW_INVALID
			ERROR_CTX_SHADOW_INVALID
#	else
			0x1B8A
#	endif
		// The requested session cannot be controlled remotely. This may be because the session is disconnected or does not currently have a user logged on.

	, CTX_SHADOW_DISABLED =
#	if defined ERROR_CTX_SHADOW_DISABLED
			ERROR_CTX_SHADOW_DISABLED
#	else
			0x1B8B
#	endif
		// The requested session is not configured to allow remote control.

	, CTX_CLIENT_LICENSE_IN_USE =
#	if defined ERROR_CTX_CLIENT_LICENSE_IN_USE
			ERROR_CTX_CLIENT_LICENSE_IN_USE
#	else
			0x1B8C
#	endif
		// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.

	, CTX_CLIENT_LICENSE_NOT_SET =
#	if defined ERROR_CTX_CLIENT_LICENSE_NOT_SET
			ERROR_CTX_CLIENT_LICENSE_NOT_SET
#	else
			0x1B8D
#	endif
		// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.

	, CTX_LICENSE_NOT_AVAILABLE =
#	if defined ERROR_CTX_LICENSE_NOT_AVAILABLE
			ERROR_CTX_LICENSE_NOT_AVAILABLE
#	else
			0x1B8E
#	endif
		// The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.

	, CTX_LICENSE_CLIENT_INVALID =
#	if defined ERROR_CTX_LICENSE_CLIENT_INVALID
			ERROR_CTX_LICENSE_CLIENT_INVALID
#	else
			0x1B8F
#	endif
		// The client you are using is not licensed to use this system. Your logon request is denied.

	, CTX_LICENSE_EXPIRED =
#	if defined ERROR_CTX_LICENSE_EXPIRED
			ERROR_CTX_LICENSE_EXPIRED
#	else
			0x1B90
#	endif
		// The system license has expired. Your logon request is denied.

	, CTX_SHADOW_NOT_RUNNING =
#	if defined ERROR_CTX_SHADOW_NOT_RUNNING
			ERROR_CTX_SHADOW_NOT_RUNNING
#	else
			0x1B91
#	endif
		// Remote control could not be terminated because the specified session is not currently being remotely controlled.

	, CTX_SHADOW_ENDED_BY_MODE_CHANGE =
#	if defined ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE
			ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE
#	else
			0x1B92
#	endif
		// The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.

	, ACTIVATION_COUNT_EXCEEDED =
#	if defined ERROR_ACTIVATION_COUNT_EXCEEDED
			ERROR_ACTIVATION_COUNT_EXCEEDED
#	else
			0x1B93
#	endif
		// Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.

	, CTX_WINSTATIONS_DISABLED =
#	if defined ERROR_CTX_WINSTATIONS_DISABLED
			ERROR_CTX_WINSTATIONS_DISABLED
#	else
			0x1B94
#	endif
		// Remote logins are currently disabled.

	, CTX_ENCRYPTION_LEVEL_REQUIRED =
#	if defined ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED
			ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED
#	else
			0x1B95
#	endif
		// You do not have the proper encryption level to access this Session.

	, CTX_SESSION_IN_USE =
#	if defined ERROR_CTX_SESSION_IN_USE
			ERROR_CTX_SESSION_IN_USE
#	else
			0x1B96
#	endif
		// The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.

	, CTX_NO_FORCE_LOGOFF =
#	if defined ERROR_CTX_NO_FORCE_LOGOFF
			ERROR_CTX_NO_FORCE_LOGOFF
#	else
			0x1B97
#	endif
		// The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.

	, CTX_ACCOUNT_RESTRICTION =
#	if defined ERROR_CTX_ACCOUNT_RESTRICTION
			ERROR_CTX_ACCOUNT_RESTRICTION
#	else
			0x1B98
#	endif
		// Unable to log you on because of an account restriction.

	, RDP_PROTOCOL_ERROR =
#	if defined ERROR_RDP_PROTOCOL_ERROR
			ERROR_RDP_PROTOCOL_ERROR
#	else
			0x1B99
#	endif
		// The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.

	, CTX_CDM_CONNECT =
#	if defined ERROR_CTX_CDM_CONNECT
			ERROR_CTX_CDM_CONNECT
#	else
			0x1B9A
#	endif
		// The Client Drive Mapping Service Has Connected on Terminal Connection.

	, CTX_CDM_DISCONNECT =
#	if defined ERROR_CTX_CDM_DISCONNECT
			ERROR_CTX_CDM_DISCONNECT
#	else
			0x1B9B
#	endif
		// The Client Drive Mapping Service Has Disconnected on Terminal Connection.

	, CTX_SECURITY_LAYER_ERROR =
#	if defined ERROR_CTX_SECURITY_LAYER_ERROR
			ERROR_CTX_SECURITY_LAYER_ERROR
#	else
			0x1B9C
#	endif
		// The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.

	, TS_INCOMPATIBLE_SESSIONS =
#	if defined ERROR_TS_INCOMPATIBLE_SESSIONS
			ERROR_TS_INCOMPATIBLE_SESSIONS
#	else
			0x1B9D
#	endif
		// The target session is incompatible with the current session.

	, TS_VIDEO_SUBSYSTEM_ERROR =
#	if defined ERROR_TS_VIDEO_SUBSYSTEM_ERROR
			ERROR_TS_VIDEO_SUBSYSTEM_ERROR
#	else
			0x1B9E
#	endif
		// Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.

	, FRS_INVALID_API_SEQUENCE =
#	if defined FRS_ERR_INVALID_API_SEQUENCE
			FRS_ERR_INVALID_API_SEQUENCE
#	else
			0x1F41
#	endif
		// The file replication service API was called incorrectly.

	, FRS_STARTING_SERVICE =
#	if defined FRS_ERR_STARTING_SERVICE
			FRS_ERR_STARTING_SERVICE
#	else
			0x1F42
#	endif
		// The file replication service cannot be started.

	, FRS_STOPPING_SERVICE =
#	if defined FRS_ERR_STOPPING_SERVICE
			FRS_ERR_STOPPING_SERVICE
#	else
			0x1F43
#	endif
		// The file replication service cannot be stopped.

	, FRS_INTERNAL_API =
#	if defined FRS_ERR_INTERNAL_API
			FRS_ERR_INTERNAL_API
#	else
			0x1F44
#	endif
		// The file replication service API terminated the request. The event log may have more information.

	, FRS_INTERNAL =
#	if defined FRS_ERR_INTERNAL
			FRS_ERR_INTERNAL
#	else
			0x1F45
#	endif
		// The file replication service terminated the request. The event log may have more information.

	, FRS_SERVICE_COMM =
#	if defined FRS_ERR_SERVICE_COMM
			FRS_ERR_SERVICE_COMM
#	else
			0x1F46
#	endif
		// The file replication service cannot be contacted. The event log may have more information.

	, FRS_INSUFFICIENT_PRIV =
#	if defined FRS_ERR_INSUFFICIENT_PRIV
			FRS_ERR_INSUFFICIENT_PRIV
#	else
			0x1F47
#	endif
		// The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information.

	, FRS_AUTHENTICATION =
#	if defined FRS_ERR_AUTHENTICATION
			FRS_ERR_AUTHENTICATION
#	else
			0x1F48
#	endif
		// The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information.

	, FRS_PARENT_INSUFFICIENT_PRIV =
#	if defined FRS_ERR_PARENT_INSUFFICIENT_PRIV
			FRS_ERR_PARENT_INSUFFICIENT_PRIV
#	else
			0x1F49
#	endif
		// The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information.

	, FRS_PARENT_AUTHENTICATION =
#	if defined FRS_ERR_PARENT_AUTHENTICATION
			FRS_ERR_PARENT_AUTHENTICATION
#	else
			0x1F4A
#	endif
		// The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information.

	, FRS_CHILD_TO_PARENT_COMM =
#	if defined FRS_ERR_CHILD_TO_PARENT_COMM
			FRS_ERR_CHILD_TO_PARENT_COMM
#	else
			0x1F4B
#	endif
		// The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information.

	, FRS_PARENT_TO_CHILD_COMM =
#	if defined FRS_ERR_PARENT_TO_CHILD_COMM
			FRS_ERR_PARENT_TO_CHILD_COMM
#	else
			0x1F4C
#	endif
		// The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information.

	, FRS_SYSVOL_POPULATE =
#	if defined FRS_ERR_SYSVOL_POPULATE
			FRS_ERR_SYSVOL_POPULATE
#	else
			0x1F4D
#	endif
		// The file replication service cannot populate the system volume because of an internal error. The event log may have more information.

	, FRS_SYSVOL_POPULATE_TIMEOUT =
#	if defined FRS_ERR_SYSVOL_POPULATE_TIMEOUT
			FRS_ERR_SYSVOL_POPULATE_TIMEOUT
#	else
			0x1F4E
#	endif
		// The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information.

	, FRS_SYSVOL_IS_BUSY =
#	if defined FRS_ERR_SYSVOL_IS_BUSY
			FRS_ERR_SYSVOL_IS_BUSY
#	else
			0x1F4F
#	endif
		// The file replication service cannot process the request. The system volume is busy with a previous request.

	, FRS_SYSVOL_DEMOTE =
#	if defined FRS_ERR_SYSVOL_DEMOTE
			FRS_ERR_SYSVOL_DEMOTE
#	else
			0x1F50
#	endif
		// The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information.

	, FRS_INVALID_SERVICE_PARAMETER =
#	if defined FRS_ERR_INVALID_SERVICE_PARAMETER
			FRS_ERR_INVALID_SERVICE_PARAMETER
#	else
			0x1F51
#	endif
		// The file replication service detected an invalid parameter.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString6(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::ENCRYPTION_FAILED:
			RETURN_STATIC_STRING(
					"The specified file could not be encrypted"
			);
		case SystemCode::DECRYPTION_FAILED:
			RETURN_STATIC_STRING("The specified file could not be decrypted");
		case SystemCode::FILE_ENCRYPTED:
			RETURN_STATIC_STRING(
					"The specified file is encrypted and the user does not have the ability to"
					" decrypt it"
			);
		case SystemCode::NO_RECOVERY_POLICY:
			RETURN_STATIC_STRING(
					"There is no valid encryption recovery policy configured for this system"
			);
		case SystemCode::NO_EFS:
			RETURN_STATIC_STRING(
					"The required encryption driver is not loaded for this system"
			);
		case SystemCode::WRONG_EFS:
			RETURN_STATIC_STRING(
					"The file was encrypted with a different encryption driver than is currently"
					" loaded"
			);
		case SystemCode::NO_USER_KEYS:
			RETURN_STATIC_STRING(
					"There are no EFS keys defined for the user"
			);
		case SystemCode::FILE_NOT_ENCRYPTED:
			RETURN_STATIC_STRING(
					"The specified file is not encrypted"
			);
		case SystemCode::NOT_EXPORT_FORMAT:
			RETURN_STATIC_STRING(
					"The specified file is not in the defined EFS export format"
			);
		case SystemCode::FILE_IS_READ_ONLY:
			RETURN_STATIC_STRING(
					"The specified file is read only"
			);
		case SystemCode::DIR_EFS_DISALLOWED:
			RETURN_STATIC_STRING(
					"The directory has been disabled for encryption"
			);
		case SystemCode::EFS_SERVER_NOT_TRUSTED:
			RETURN_STATIC_STRING(
					"The server is not trusted for remote encryption operation"
			);
		case SystemCode::BAD_RECOVERY_POLICY:
			RETURN_STATIC_STRING(
					"Recovery policy configured for this system contains invalid recovery"
					" certificate"
			);
		case SystemCode::EFS_ALG_BLOB_TOO_BIG:
			RETURN_STATIC_STRING(
					"The encryption algorithm used on the source file needs a bigger key buffer"
					" than the one on the destination file"
			);
		case SystemCode::VOLUME_NOT_SUPPORT_EFS:
			RETURN_STATIC_STRING(
					"The disk partition does not support file encryption"
			);
		case SystemCode::EFS_DISABLED:
			RETURN_STATIC_STRING(
					"This machine is disabled for file encryption"
			);
		case SystemCode::EFS_VERSION_NOT_SUPPORT:
			RETURN_STATIC_STRING(
					"A newer system is required to decrypt this encrypted file"
			);
		case SystemCode::CS_ENCRYPTION_INVALID_SERVER_RESPONSE:
			RETURN_STATIC_STRING(
					"The remote server sent an invalid response for a file being opened with Client"
					" Side Encryption"
			);
		case SystemCode::CS_ENCRYPTION_UNSUPPORTED_SERVER:
			RETURN_STATIC_STRING(
					"Client Side Encryption is not supported by the remote server even though it"
					" claims to support it"
			);
		case SystemCode::CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE:
			RETURN_STATIC_STRING(
					"File is encrypted and should be opened in Client Side Encryption mode"
			);
		case SystemCode::CS_ENCRYPTION_NEW_ENCRYPTED_FILE:
			RETURN_STATIC_STRING(
					"A new encrypted file is being created and a $EFS needs to be provided"
			);
		case SystemCode::CS_ENCRYPTION_FILE_NOT_CSE:
			RETURN_STATIC_STRING(
					"The SMB client requested a CSE FSCTL on a non-CSE file"
			);
		case SystemCode::ENCRYPTION_POLICY_DENIES_OPERATION:
			RETURN_STATIC_STRING(
					"The requested operation was blocked by policy. For more information, contact your system administrator"
			);
		case SystemCode::NO_BROWSER_SERVERS_FOUND:
			RETURN_STATIC_STRING(
					"The list of servers for this workgroup is not currently available"
			);
		case SystemCode::E_SERVICE_NOT_LOCALSYSTEM:
			RETURN_STATIC_STRING(
					"The Task Scheduler service must be configured to run in the System account to"
					" function properly. Individual tasks may be configured to run in other"
					" accounts"
			);
		case SystemCode::LOG_SECTOR_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an invalid log sector"
			);
		case SystemCode::LOG_SECTOR_PARITY_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered a log sector with invalid block parity"
			);
		case SystemCode::LOG_SECTOR_REMAPPED:
			RETURN_STATIC_STRING(
					"Log service encountered a remapped log sector"
			);
		case SystemCode::LOG_BLOCK_INCOMPLETE:
			RETURN_STATIC_STRING(
					"Log service encountered a partial or incomplete log block"
			);
		case SystemCode::LOG_INVALID_RANGE:
			RETURN_STATIC_STRING(
					"Log service encountered an attempt access data outside the active log range"
			);
		case SystemCode::LOG_BLOCKS_EXHAUSTED:
			RETURN_STATIC_STRING(
					"Log service user marshalling buffers are exhausted"
			);
		case SystemCode::LOG_READ_CONTEXT_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an attempt read from a marshalling area with an"
					" invalid read context"
			);
		case SystemCode::LOG_RESTART_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an invalid log restart area"
			);
		case SystemCode::LOG_BLOCK_VERSION:
			RETURN_STATIC_STRING(
					"Log service encountered an invalid log block version"
			);
		case SystemCode::LOG_BLOCK_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an invalid log block"
			);
		case SystemCode::LOG_READ_MODE_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an attempt to read the log with an invalid read mode"
			);
		case SystemCode::LOG_NO_RESTART:
			RETURN_STATIC_STRING(
					"Log service encountered a log stream with no restart area"
			);
		case SystemCode::LOG_METADATA_CORRUPT:
			RETURN_STATIC_STRING(
					"Log service encountered a corrupted metadata file"
			);
		case SystemCode::LOG_METADATA_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered a metadata file that could not be created by the log"
					" file system"
			);
		case SystemCode::LOG_METADATA_INCONSISTENT:
			RETURN_STATIC_STRING(
					"Log service encountered a metadata file with inconsistent data"
			);
		case SystemCode::LOG_RESERVATION_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an attempt to erroneous allocate or dispose"
					" reservation space"
			);
		case SystemCode::LOG_CANT_DELETE:
			RETURN_STATIC_STRING(
					"Log service cannot delete log file or file system container"
			);
		case SystemCode::LOG_CONTAINER_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"Log service has reached the maximum allowable containers allocated to a log"
					" file"
			);
		case SystemCode::LOG_START_OF_LOG:
			RETURN_STATIC_STRING(
					"Log service has attempted to read or write backward past the start of the log"
			);
		case SystemCode::LOG_POLICY_ALREADY_INSTALLED:
			RETURN_STATIC_STRING(
					"Log policy could not be installed because a policy of the same type is already"
					" present"
			);
		case SystemCode::LOG_POLICY_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"Log policy in question was not installed at the time of the request"
			);
		case SystemCode::LOG_POLICY_INVALID:
			RETURN_STATIC_STRING(
					"The installed set of policies on the log is invalid"
			);
		case SystemCode::LOG_POLICY_CONFLICT:
			RETURN_STATIC_STRING(
					"A policy on the log in question prevented the operation from completing"
			);
		case SystemCode::LOG_PINNED_ARCHIVE_TAIL:
			RETURN_STATIC_STRING(
					"Log space cannot be reclaimed because the log is pinned by the archive tail"
			);
		case SystemCode::LOG_RECORD_NONEXISTENT:
			RETURN_STATIC_STRING(
					"Log record is not a record in the log file"
			);
		case SystemCode::LOG_RECORDS_RESERVED_INVALID:
			RETURN_STATIC_STRING(
					"Number of reserved log records or the adjustment of the number of reserved log"
					" records is invalid"
			);
		case SystemCode::LOG_SPACE_RESERVED_INVALID:
			RETURN_STATIC_STRING(
					"Reserved log space or the adjustment of the log space is invalid"
			);
		case SystemCode::LOG_TAIL_INVALID:
			RETURN_STATIC_STRING(
					"An new or existing archive tail or base of the active log is invalid"
			);
		case SystemCode::LOG_FULL:
			RETURN_STATIC_STRING(
					"Log space is exhausted"
			);
		case SystemCode::COULD_NOT_RESIZE_LOG:
			RETURN_STATIC_STRING(
					"The log could not be set to the requested size"
			);
		case SystemCode::LOG_MULTIPLEXED:
			RETURN_STATIC_STRING(
					"Log is multiplexed, no direct writes to the physical log is allowed"
			);
		case SystemCode::LOG_DEDICATED:
			RETURN_STATIC_STRING(
					"The operation failed because the log is a dedicated log"
			);
		case SystemCode::LOG_ARCHIVE_NOT_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The operation requires an archive context"
			);
		case SystemCode::LOG_ARCHIVE_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Log archival is in progress"
			);
		case SystemCode::LOG_EPHEMERAL:
			RETURN_STATIC_STRING(
					"The operation requires a non-ephemeral log, but the log is ephemeral"
			);
		case SystemCode::LOG_NOT_ENOUGH_CONTAINERS:
			RETURN_STATIC_STRING(
					"The log must have at least two containers before it can be read from or"
					" written to"
			);
		case SystemCode::LOG_CLIENT_ALREADY_REGISTERED:
			RETURN_STATIC_STRING(
					"A log client has already registered on the stream"
			);
		case SystemCode::LOG_CLIENT_NOT_REGISTERED:
			RETURN_STATIC_STRING(
					"A log client has not been registered on the stream"
			);
		case SystemCode::LOG_FULL_HANDLER_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A request has already been made to handle the log full condition"
			);
		case SystemCode::LOG_CONTAINER_READ_FAILED:
			RETURN_STATIC_STRING(
					"Log service encountered an error when attempting to read from a log container"
			);
		case SystemCode::LOG_CONTAINER_WRITE_FAILED:
			RETURN_STATIC_STRING(
					"Log service encountered an error when attempting to write to a log container"
			);
		case SystemCode::LOG_CONTAINER_OPEN_FAILED:
			RETURN_STATIC_STRING(
					"Log service encountered an error when attempting open a log container"
			);
		case SystemCode::LOG_CONTAINER_STATE_INVALID:
			RETURN_STATIC_STRING(
					"Log service encountered an invalid container state when attempting a requested"
					" action"
			);
		case SystemCode::LOG_STATE_INVALID:
			RETURN_STATIC_STRING(
					"Log service is not in the correct state to perform a requested action"
			);
		case SystemCode::LOG_PINNED:
			RETURN_STATIC_STRING(
					"Log space cannot be reclaimed because the log is pinned"
			);
		case SystemCode::LOG_METADATA_FLUSH_FAILED:
			RETURN_STATIC_STRING(
					"Log metadata flush failed"
			);
		case SystemCode::LOG_INCONSISTENT_SECURITY:
			RETURN_STATIC_STRING(
					"Security on the log and its containers is inconsistent"
			);
		case SystemCode::LOG_APPENDED_FLUSH_FAILED:
			RETURN_STATIC_STRING(
					"Records were appended to the log or reservation changes were made, but the log"
					" could not be flushed"
			);
		case SystemCode::LOG_PINNED_RESERVATION:
			RETURN_STATIC_STRING(
					"The log is pinned due to reservation consuming most of the log space. Free"
					" some reserved records to make space available"
			);
		case SystemCode::INVALID_TRANSACTION:
			RETURN_STATIC_STRING(
					"The transaction handle associated with this operation is not valid"
			);
		case SystemCode::TRANSACTION_NOT_ACTIVE:
			RETURN_STATIC_STRING(
					"The requested operation was made in the context of a transaction that is no"
					" longer active"
			);
		case SystemCode::TRANSACTION_REQUEST_NOT_VALID:
			RETURN_STATIC_STRING(
					"The requested operation is not valid on the Transaction object in its current"
					" state"
			);
		case SystemCode::TRANSACTION_NOT_REQUESTED:
			RETURN_STATIC_STRING(
					"The caller has called a response API, but the response is not expected because"
					" the TM did not issue the corresponding request to the caller"
			);
		case SystemCode::TRANSACTION_ALREADY_ABORTED:
			RETURN_STATIC_STRING(
					"It is too late to perform the requested operation, since the Transaction has"
					" already been aborted"
			);
		case SystemCode::TRANSACTION_ALREADY_COMMITTED:
			RETURN_STATIC_STRING(
					"It is too late to perform the requested operation, since the Transaction has"
					" already been committed"
			);
		case SystemCode::TM_INITIALIZATION_FAILED:
			RETURN_STATIC_STRING(
					"The Transaction Manager was unable to be successfully initialized. Transacted"
					" operations are not supported"
			);
		case SystemCode::RESOURCEMANAGER_READ_ONLY:
			RETURN_STATIC_STRING(
					"The specified ResourceManager made no changes or updates to the resource under"
					" this transaction"
			);
		case SystemCode::TRANSACTION_NOT_JOINED:
			RETURN_STATIC_STRING(
					"The resource manager has attempted to prepare a transaction that it has not"
					" successfully joined"
			);
		case SystemCode::TRANSACTION_SUPERIOR_EXISTS:
			RETURN_STATIC_STRING(
					"The Transaction object already has a superior enlistment, and the caller"
					" attempted an operation that would have created a new superior. Only a single"
					" superior enlistment is allow"
			);
		case SystemCode::CRM_PROTOCOL_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The RM tried to register a protocol that already exists"
			);
		case SystemCode::TRANSACTION_PROPAGATION_FAILED:
			RETURN_STATIC_STRING(
					"The attempt to propagate the Transaction failed"
			);
		case SystemCode::CRM_PROTOCOL_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested propagation protocol was not registered as a CRM"
			);
		case SystemCode::TRANSACTION_INVALID_MARSHALL_BUFFER:
			RETURN_STATIC_STRING(
					"The buffer passed in to PushTransaction or PullTransaction is not in a valid"
					" format"
			);
		case SystemCode::CURRENT_TRANSACTION_NOT_VALID:
			RETURN_STATIC_STRING(
					"The current transaction context associated with the thread is not a valid"
					" handle to a transaction object"
			);
		case SystemCode::TRANSACTION_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified Transaction object could not be opened, because it was not found"
			);
		case SystemCode::RESOURCEMANAGER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified ResourceManager object could not be opened, because it was not"
					" found"
			);
		case SystemCode::ENLISTMENT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified Enlistment object could not be opened, because it was not found"
			);
		case SystemCode::TRANSACTIONMANAGER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified TransactionManager object could not be opened, because it was"
					" not found"
			);
		case SystemCode::TRANSACTIONMANAGER_NOT_ONLINE:
			RETURN_STATIC_STRING(
					"The object specified could not be created or opened, because its associated"
					" TransactionManager is not online. The TransactionManager must be brought"
					" fully Online by calling RecoverTransactionManager to recover to the end of"
					" its LogFile before objects in its Transaction or ResourceManager namespaces"
					" can be opened. In addition, errors in writing records to its LogFile can"
					" cause a TransactionManager to go offline"
			);
		case SystemCode::TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION:
			RETURN_STATIC_STRING(
					"The specified TransactionManager was unable to create the objects contained in"
					" its logfile in the Ob namespace. Therefore, the TransactionManager was unable"
					" to recover"
			);
		case SystemCode::TRANSACTION_NOT_ROOT:
			RETURN_STATIC_STRING(
					"The call to create a superior Enlistment on this Transaction object could not"
					" be completed, because the Transaction object specified for the enlistment is"
					" a subordinate branch of the Transaction. Only the root of the Transaction can"
					" be enlisted on as a superior"
			);
		case SystemCode::TRANSACTION_OBJECT_EXPIRED:
			RETURN_STATIC_STRING(
					"Because the associated transaction manager or resource manager has been"
					" closed, the handle is no longer valid"
			);
		case SystemCode::TRANSACTION_RESPONSE_NOT_ENLISTED:
			RETURN_STATIC_STRING(
					"The specified operation could not be performed on this Superior enlistment,"
					" because the enlistment was not created with the corresponding completion"
					" response in the NotificationMask"
			);
		case SystemCode::TRANSACTION_RECORD_TOO_LONG:
			RETURN_STATIC_STRING(
					"The specified operation could not be performed, because the record that would"
					" be logged was too long. This can occur because of two conditions: either"
					" there are too many Enlistments on this Transaction, or the combined"
					" RecoveryInformation being logged on behalf of those Enlistments is too long"
			);
		case SystemCode::IMPLICIT_TRANSACTION_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"Implicit transaction are not supported"
			);
		case SystemCode::TRANSACTION_INTEGRITY_VIOLATED:
			RETURN_STATIC_STRING(
					"The kernel transaction manager had to abort or forget the transaction because"
					" it blocked forward progress"
			);
		case SystemCode::TRANSACTIONMANAGER_IDENTITY_MISMATCH:
			RETURN_STATIC_STRING(
					"The TransactionManager identity that was supplied did not match the one"
					" recorded in the TransactionManager's log file"
			);
		case SystemCode::RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT:
			RETURN_STATIC_STRING(
					"This snapshot operation cannot continue because a transactional resource"
					" manager cannot be frozen in its current state. Please try again"
			);
		case SystemCode::TRANSACTION_MUST_WRITETHROUGH:
			RETURN_STATIC_STRING(
					"The transaction cannot be enlisted on with the specified EnlistmentMask,"
					" because the transaction has already completed the PrePrepare phase. In order"
					" to ensure correctness, the ResourceManager must switch to a write- through"
					" mode and cease caching data within this transaction. Enlisting for only"
					" subsequent transaction phases may still succeed"
			);
		case SystemCode::TRANSACTION_NO_SUPERIOR:
			RETURN_STATIC_STRING(
					"The transaction does not have a superior enlistment"
			);
		case SystemCode::HEURISTIC_DAMAGE_POSSIBLE:
			RETURN_STATIC_STRING(
					"The attempt to commit the Transaction completed, but it is possible that some"
					" portion of the transaction tree did not commit successfully due to"
					" heuristics. Therefore it is possible that some data modified in the"
					" transaction may not have committed, resulting in transactional inconsistency."
					" If possible, check the consistency of the associated data"
			);
		case SystemCode::TRANSACTIONAL_CONFLICT:
			RETURN_STATIC_STRING(
					"The function attempted to use a name that is reserved for use by another"
					" transaction"
			);
		case SystemCode::RM_NOT_ACTIVE:
			RETURN_STATIC_STRING(
					"Transaction support within the specified resource manager is not started or"
					" was shut down due to an error"
			);
		case SystemCode::RM_METADATA_CORRUPT:
			RETURN_STATIC_STRING(
					"The metadata of the RM has been corrupted. The RM will not function"
			);
		case SystemCode::DIRECTORY_NOT_RM:
			RETURN_STATIC_STRING(
					"The specified directory does not contain a resource manager"
			);
		case SystemCode::TRANSACTIONS_UNSUPPORTED_REMOTE:
			RETURN_STATIC_STRING(
					"The remote server or share does not support transacted file operations"
			);
		case SystemCode::LOG_RESIZE_INVALID_SIZE:
			RETURN_STATIC_STRING(
					"The requested log size is invalid"
			);
		case SystemCode::OBJECT_NO_LONGER_EXISTS:
			RETURN_STATIC_STRING(
					"The object (file, stream, link) corresponding to the handle has been deleted"
					" by a Transaction Savepoint Rollback"
			);
		case SystemCode::STREAM_MINIVERSION_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified file miniversion was not found for this transacted file open"
			);
		case SystemCode::STREAM_MINIVERSION_NOT_VALID:
			RETURN_STATIC_STRING(
					"The specified file miniversion was found but has been invalidated. Most likely"
					" cause is a transaction savepoint rollback"
			);
		case SystemCode::MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION:
			RETURN_STATIC_STRING(
					"A miniversion may only be opened in the context of the transaction that"
					" created it"
			);
		case SystemCode::CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT:
			RETURN_STATIC_STRING(
					"It is not possible to open a miniversion with modify access"
			);
		case SystemCode::CANT_CREATE_MORE_STREAM_MINIVERSIONS:
			RETURN_STATIC_STRING(
					"It is not possible to create any more miniversions for this stream"
			);
		case SystemCode::REMOTE_FILE_VERSION_MISMATCH:
			RETURN_STATIC_STRING(
					"The remote server sent mismatching version number or Fid for a file opened"
					" with transactions"
			);
		case SystemCode::HANDLE_NO_LONGER_VALID:
			RETURN_STATIC_STRING(
					"The handle has been invalidated by a transaction. The most likely cause is"
					" the presence of memory mapping on a file or an open handle when the"
					" transaction ended or rolled back to savepoint"
			);
		case SystemCode::NO_TXF_METADATA:
			RETURN_STATIC_STRING(
					"There is no transaction metadata on the file"
			);
		case SystemCode::LOG_CORRUPTION_DETECTED:
			RETURN_STATIC_STRING(
					"The log data is corrupt"
			);
		case SystemCode::CANT_RECOVER_WITH_HANDLE_OPEN:
			RETURN_STATIC_STRING(
					"The file can't be recovered because there is a handle still open on it"
			);
		case SystemCode::RM_DISCONNECTED:
			RETURN_STATIC_STRING(
					"The transaction outcome is unavailable because the resource manager"
					" responsible for it has disconnected"
			);
		case SystemCode::ENLISTMENT_NOT_SUPERIOR:
			RETURN_STATIC_STRING(
					"The request was rejected because the enlistment in question is not a superior"
					" enlistment"
			);
		case SystemCode::RECOVERY_NOT_NEEDED:
			RETURN_STATIC_STRING(
					"The transactional resource manager is already consistent. Recovery is not"
					" needed"
			);
		case SystemCode::RM_ALREADY_STARTED:
			RETURN_STATIC_STRING(
					"The transactional resource manager has already been started"
			);
		case SystemCode::FILE_IDENTITY_NOT_PERSISTENT:
			RETURN_STATIC_STRING(
					"The file cannot be opened transactionally, because its identity depends on the"
					" outcome of an unresolved transaction"
			);
		case SystemCode::CANT_BREAK_TRANSACTIONAL_DEPENDENCY:
			RETURN_STATIC_STRING(
					"The operation cannot be performed because another transaction is depending on"
					" the fact that this property will not change"
			);
		case SystemCode::CANT_CROSS_RM_BOUNDARY:
			RETURN_STATIC_STRING(
					"The operation would involve a single file with two transactional resource"
					" managers and is therefore not allowed"
			);
		case SystemCode::TXF_DIR_NOT_EMPTY:
			RETURN_STATIC_STRING(
					"The $Txf directory must be empty for this operation to succeed"
			);
		case SystemCode::INDOUBT_TRANSACTIONS_EXIST:
			RETURN_STATIC_STRING(
					"The operation would leave a transactional resource manager in an inconsistent"
					" state and is therefore not allowed"
			);
		case SystemCode::TM_VOLATILE:
			RETURN_STATIC_STRING(
					"The operation could not be completed because the transaction manager does not"
					" have a log"
			);
		case SystemCode::ROLLBACK_TIMER_EXPIRED:
			RETURN_STATIC_STRING(
					"A rollback could not be scheduled because a previously scheduled rollback has"
					" already executed or been queued for execution"
			);
		case SystemCode::TXF_ATTRIBUTE_CORRUPT:
			RETURN_STATIC_STRING(
					"The transactional metadata attribute on the file or directory is corrupt and"
					" unreadable"
			);
		case SystemCode::EFS_NOT_ALLOWED_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"The encryption operation could not be completed because a transaction is"
					" active"
			);
		case SystemCode::TRANSACTIONAL_OPEN_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"This object is not allowed to be opened in a transaction"
			);
		case SystemCode::LOG_GROWTH_FAILED:
			RETURN_STATIC_STRING(
					"An attempt to create space in the transactional resource manager's log failed."
					" The failure status has been recorded in the event log"
			);
		case SystemCode::TRANSACTED_MAPPING_UNSUPPORTED_REMOTE:
			RETURN_STATIC_STRING(
					"Memory mapping (creating a mapped section) a remote file under a transaction"
					" is not supported"
			);
		case SystemCode::TXF_METADATA_ALREADY_PRESENT:
			RETURN_STATIC_STRING(
					"Transaction metadata is already present on this file and cannot be superseded"
			);
		case SystemCode::TRANSACTION_SCOPE_CALLBACKS_NOT_SET:
			RETURN_STATIC_STRING(
					"A transaction scope could not be entered because the scope handler has not"
					" been initialized"
			);
		case SystemCode::TRANSACTION_REQUIRED_PROMOTION:
			RETURN_STATIC_STRING(
					"Promotion was required in order to allow the resource manager to enlist, but"
					" the transaction was set to disallow it"
			);
		case SystemCode::CANNOT_EXECUTE_FILE_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"This file is open for modification in an unresolved transaction and may be"
					" opened for execute only by a transacted reader"
			);
		case SystemCode::TRANSACTIONS_NOT_FROZEN:
			RETURN_STATIC_STRING(
					"The request to thaw frozen transactions was ignored because transactions had"
					" not previously been frozen"
			);
		case SystemCode::TRANSACTION_FREEZE_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Transactions cannot be frozen because a freeze is already in progress"
			);
		case SystemCode::NOT_SNAPSHOT_VOLUME:
			RETURN_STATIC_STRING(
					"The target volume is not a snapshot volume. This operation is only valid on a"
					" volume mounted as a snapshot"
			);
		case SystemCode::NO_SAVEPOINT_WITH_OPEN_FILES:
			RETURN_STATIC_STRING(
					"The savepoint operation failed because files are open on the transaction. This"
					" is not permitted"
			);
		case SystemCode::DATA_LOST_REPAIR:
			RETURN_STATIC_STRING(
					"Windows has discovered corruption in a file, and that file has since been"
					" repaired. Data loss may have occurred"
			);
		case SystemCode::SPARSE_NOT_ALLOWED_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"The sparse operation could not be completed because a transaction is active"
					" on the file"
			);
		case SystemCode::TM_IDENTITY_MISMATCH:
			RETURN_STATIC_STRING(
					"The call to create a TransactionManager object failed because the Tm Identity"
					" stored in the logfile does not match the Tm Identity that was passed in as an"
					" argument"
			);
		case SystemCode::FLOATED_SECTION:
			RETURN_STATIC_STRING(
					"I/O was attempted on a section object that has been floated as a result of a"
					" transaction ending. There is no valid data"
			);
		case SystemCode::CANNOT_ACCEPT_TRANSACTED_WORK:
			RETURN_STATIC_STRING(
					"The transactional resource manager cannot currently accept transacted work due"
					" to a transient condition such as low resources"
			);
		case SystemCode::CANNOT_ABORT_TRANSACTIONS:
			RETURN_STATIC_STRING(
					"The transactional resource manager had too many tranactions outstanding that"
					" could not be aborted. The transactional resource manger has been shut down"
			);
		case SystemCode::BAD_CLUSTERS:
			RETURN_STATIC_STRING(
					"The operation could not be completed due to bad clusters on disk"
			);
		case SystemCode::COMPRESSION_NOT_ALLOWED_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"The compression operation could not be completed because a transaction is"
					" active on the file"
			);
		case SystemCode::VOLUME_DIRTY:
			RETURN_STATIC_STRING(
					"The operation could not be completed because the volume is dirty. Please run"
					" chkdsk and try again"
			);
		case SystemCode::NO_LINK_TRACKING_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"The link tracking operation could not be completed because a transaction is"
					" active"
			);
		case SystemCode::OPERATION_NOT_SUPPORTED_IN_TRANSACTION:
			RETURN_STATIC_STRING(
					"This operation cannot be performed in a transaction"
			);
		case SystemCode::EXPIRED_HANDLE:
			RETURN_STATIC_STRING(
					"The handle is no longer properly associated with its transaction. It may have"
					" been opened in a transactional resource manager that was subsequently forced"
					" to restart. Please close the handle and open a new one"
			);
		case SystemCode::TRANSACTION_NOT_ENLISTED:
			RETURN_STATIC_STRING(
					"The specified operation could not be performed because the resource manager is"
					" not enlisted in the transaction"
			);
		case SystemCode::CTX_WINSTATION_NAME_INVALID:
			RETURN_STATIC_STRING(
					"The specified session name is invalid"
			);
		case SystemCode::CTX_INVALID_PD:
			RETURN_STATIC_STRING(
					"The specified protocol driver is invalid"
			);
		case SystemCode::CTX_PD_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified protocol driver was not found in the system path"
			);
		case SystemCode::CTX_WD_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified terminal connection driver was not found in the system path"
			);
		case SystemCode::CTX_CANNOT_MAKE_EVENTLOG_ENTRY:
			RETURN_STATIC_STRING(
					"A registry key for event logging could not be created for this session"
			);
		case SystemCode::CTX_SERVICE_NAME_COLLISION:
			RETURN_STATIC_STRING(
					"A service with the same name already exists on the system"
			);
		case SystemCode::CTX_CLOSE_PENDING:
			RETURN_STATIC_STRING(
					"A close operation is pending on the session"
			);
		case SystemCode::CTX_NO_OUTBUF:
			RETURN_STATIC_STRING(
					"There are no free output buffers available"
			);
		case SystemCode::CTX_MODEM_INF_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The MODEM.INF file was not found"
			);
		case SystemCode::CTX_INVALID_MODEMNAME:
			RETURN_STATIC_STRING(
					"The modem name was not found in MODEM.INF"
			);
		case SystemCode::CTX_MODEM_RESPONSE_ERROR:
			RETURN_STATIC_STRING(
					"The modem did not accept the command sent to it. Verify that the configured"
					" modem name matches the attached modem"
			);
		case SystemCode::CTX_MODEM_RESPONSE_TIMEOUT:
			RETURN_STATIC_STRING(
					"The modem did not respond to the command sent to it. Verify that the modem is"
					" properly cabled and powered on"
			);
		case SystemCode::CTX_MODEM_RESPONSE_NO_CARRIER:
			RETURN_STATIC_STRING(
					"Carrier detect has failed or carrier has been dropped due to disconnect"
			);
		case SystemCode::CTX_MODEM_RESPONSE_NO_DIALTONE:
			RETURN_STATIC_STRING(
					"Dial tone not detected within the required time. Verify that the phone cable"
					" is properly attached and functional"
			);
		case SystemCode::CTX_MODEM_RESPONSE_BUSY:
			RETURN_STATIC_STRING(
					"Busy signal detected at remote site on callback"
			);
		case SystemCode::CTX_MODEM_RESPONSE_VOICE:
			RETURN_STATIC_STRING(
					"Voice detected at remote site on callback"
			);
		case SystemCode::CTX_TD_ERROR:
			RETURN_STATIC_STRING(
					"Transport driver error"
			);
		case SystemCode::CTX_WINSTATION_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified session cannot be found"
			);
		case SystemCode::CTX_WINSTATION_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified session name is already in use"
			);
		case SystemCode::CTX_WINSTATION_BUSY:
			RETURN_STATIC_STRING(
					"The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on"
			);
		case SystemCode::CTX_BAD_VIDEO_MODE:
			RETURN_STATIC_STRING(
					"An attempt has been made to connect to a session whose video mode is not"
					" supported by the current client"
			);
		case SystemCode::CTX_GRAPHICS_INVALID:
			RETURN_STATIC_STRING(
					"The application attempted to enable DOS graphics mode. DOS graphics mode is"
					" not supported"
			);
		case SystemCode::CTX_LOGON_DISABLED:
			RETURN_STATIC_STRING(
					"Your interactive logon privilege has been disabled. Please contact your"
					" administrator"
			);
		case SystemCode::CTX_NOT_CONSOLE:
			RETURN_STATIC_STRING(
					"The requested operation can be performed only on the system console. This is"
					" most often the result of a driver or system DLL requiring direct console"
					" access"
			);
		case SystemCode::CTX_CLIENT_QUERY_TIMEOUT:
			RETURN_STATIC_STRING(
					"The client failed to respond to the server connect message"
			);
		case SystemCode::CTX_CONSOLE_DISCONNECT:
			RETURN_STATIC_STRING(
					"Disconnecting the console session is not supported"
			);
		case SystemCode::CTX_CONSOLE_CONNECT:
			RETURN_STATIC_STRING(
					"Reconnecting a disconnected session to the console is not supported"
			);
		case SystemCode::CTX_SHADOW_DENIED:
			RETURN_STATIC_STRING(
					"The request to control another session remotely was denied"
			);
		case SystemCode::CTX_WINSTATION_ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"The requested session access is denied"
			);
		case SystemCode::CTX_INVALID_WD:
			RETURN_STATIC_STRING(
					"The specified terminal connection driver is invalid"
			);
		case SystemCode::CTX_SHADOW_INVALID:
			RETURN_STATIC_STRING(
					"The requested session cannot be controlled remotely. This may be because the"
					" session is disconnected or does not currently have a user logged on"
			);
		case SystemCode::CTX_SHADOW_DISABLED:
			RETURN_STATIC_STRING(
					"The requested session is not configured to allow remote control"
			);
		case SystemCode::CTX_CLIENT_LICENSE_IN_USE:
			RETURN_STATIC_STRING(
					"Your request to connect to this Terminal Server has been rejected. Your"
					" Terminal Server client license number is currently being used by another"
					" user. Please call your system administrator to obtain a unique license number"
			);
		case SystemCode::CTX_CLIENT_LICENSE_NOT_SET:
			RETURN_STATIC_STRING(
					"Your request to connect to this Terminal Server has been rejected. Your"
					" Terminal Server client license number has not been entered for this copy of"
					" the Terminal Server client. Please contact your system administrator"
			);
		case SystemCode::CTX_LICENSE_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The number of connections to this computer is limited and all connections are"
					" in use right now. Try connecting later or contact your system administrator"
			);
		case SystemCode::CTX_LICENSE_CLIENT_INVALID:
			RETURN_STATIC_STRING(
					"The client you are using is not licensed to use this system. Your logon"
					" request is denied"
			);
		case SystemCode::CTX_LICENSE_EXPIRED:
			RETURN_STATIC_STRING(
					"The system license has expired. Your logon request is denied"
			);
		case SystemCode::CTX_SHADOW_NOT_RUNNING:
			RETURN_STATIC_STRING(
					"Remote control could not be terminated because the specified session is not"
					" currently being remotely controlled"
			);
		case SystemCode::CTX_SHADOW_ENDED_BY_MODE_CHANGE:
			RETURN_STATIC_STRING(
					"The remote control of the console was terminated because the display mode was"
					" changed. Changing the display mode in a remote control session is not"
					" supported"
			);
		case SystemCode::ACTIVATION_COUNT_EXCEEDED:
			RETURN_STATIC_STRING(
					"Activation has already been reset the maximum number of times for this"
					" installation. Your activation timer will not be cleared"
			);
		case SystemCode::CTX_WINSTATIONS_DISABLED:
			RETURN_STATIC_STRING(
					"Remote logins are currently disabled"
			);
		case SystemCode::CTX_ENCRYPTION_LEVEL_REQUIRED:
			RETURN_STATIC_STRING(
					"You do not have the proper encryption level to access this Session"
			);
		case SystemCode::CTX_SESSION_IN_USE:
			RETURN_STATIC_STRING(
					"The user %s\\%s is currently logged on to this computer. Only the current user"
					" or an administrator can log on to this computer"
			);
		case SystemCode::CTX_NO_FORCE_LOGOFF:
			RETURN_STATIC_STRING(
					"The user %s\\%s is already logged on to the console of this computer. You do"
					" not have permission to log in at this time. To resolve this issue, contact"
					" %s\\%s and have them log off"
			);
		case SystemCode::CTX_ACCOUNT_RESTRICTION:
			RETURN_STATIC_STRING(
					"Unable to log you on because of an account restriction"
			);
		case SystemCode::RDP_PROTOCOL_ERROR:
			RETURN_STATIC_STRING(
					"The RDP protocol component %2 detected an error in the protocol stream and has"
					" disconnected the client"
			);
		case SystemCode::CTX_CDM_CONNECT:
			RETURN_STATIC_STRING(
					"The Client Drive Mapping Service Has Connected on Terminal Connection"
			);
		case SystemCode::CTX_CDM_DISCONNECT:
			RETURN_STATIC_STRING(
					"The Client Drive Mapping Service Has Disconnected on Terminal Connection"
			);
		case SystemCode::CTX_SECURITY_LAYER_ERROR:
			RETURN_STATIC_STRING(
					"The Terminal Server security layer detected an error in the protocol stream"
					" and has disconnected the client"
			);
		case SystemCode::TS_INCOMPATIBLE_SESSIONS:
			RETURN_STATIC_STRING(
					"The target session is incompatible with the current session"
			);
		case SystemCode::TS_VIDEO_SUBSYSTEM_ERROR:
			RETURN_STATIC_STRING(
					"Windows can't connect to your session because a problem occurred in the"
					" Windows video subsystem. Try connecting again later, or contact the server"
					" administrator for assistance"
			);
		case SystemCode::FRS_INVALID_API_SEQUENCE:
			RETURN_STATIC_STRING(
					"The file replication service API was called incorrectly"
			);
		case SystemCode::FRS_STARTING_SERVICE:
			RETURN_STATIC_STRING(
					"The file replication service cannot be started"
			);
		case SystemCode::FRS_STOPPING_SERVICE:
			RETURN_STATIC_STRING(
					"The file replication service cannot be stopped"
			);
		case SystemCode::FRS_INTERNAL_API:
			RETURN_STATIC_STRING(
					"The file replication service API terminated the request. The event log may"
					" have more information"
			);
		case SystemCode::FRS_INTERNAL:
			RETURN_STATIC_STRING(
					"The file replication service terminated the request. The event log may have"
					" more information"
			);
		case SystemCode::FRS_SERVICE_COMM:
			RETURN_STATIC_STRING(
					"The file replication service cannot be contacted. The event log may have more"
					" information"
			);
		case SystemCode::FRS_INSUFFICIENT_PRIV:
			RETURN_STATIC_STRING(
					"The file replication service cannot satisfy the request because the user has"
					" insufficient privileges. The event log may have more information"
			);
		case SystemCode::FRS_AUTHENTICATION:
			RETURN_STATIC_STRING(
					"The file replication service cannot satisfy the request because authenticated"
					" RPC is not available. The event log may have more information"
			);
		case SystemCode::FRS_PARENT_INSUFFICIENT_PRIV:
			RETURN_STATIC_STRING(
					"The file replication service cannot satisfy the request because the user has"
					" insufficient privileges on the domain controller. The event log may have more"
					" information"
			);
		case SystemCode::FRS_PARENT_AUTHENTICATION:
			RETURN_STATIC_STRING(
					"The file replication service cannot satisfy the request because authenticated"
					" RPC is not available on the domain controller. The event log may have more"
					" information"
			);
		case SystemCode::FRS_CHILD_TO_PARENT_COMM:
			RETURN_STATIC_STRING(
					"The file replication service cannot communicate with the file replication"
					" service on the domain controller. The event log may have more information"
			);
		case SystemCode::FRS_PARENT_TO_CHILD_COMM:
			RETURN_STATIC_STRING(
					"The file replication service on the domain controller cannot communicate with"
					" the file replication service on this computer. The event log may have more"
					" information"
			);
		case SystemCode::FRS_SYSVOL_POPULATE:
			RETURN_STATIC_STRING(
					"The file replication service cannot populate the system volume because of an"
					" internal error. The event log may have more information"
			);
		case SystemCode::FRS_SYSVOL_POPULATE_TIMEOUT:
			RETURN_STATIC_STRING(
					"The file replication service cannot populate the system volume because of an"
					" internal timeout. The event log may have more information"
			);
		case SystemCode::FRS_SYSVOL_IS_BUSY:
			RETURN_STATIC_STRING(
					"The file replication service cannot process the request. The system volume is"
					" busy with a previous request"
			);
		case SystemCode::FRS_SYSVOL_DEMOTE:
			RETURN_STATIC_STRING(
					"The file replication service cannot stop replicating the system volume because"
					" of an internal error. The event log may have more information"
			);
		case SystemCode::FRS_INVALID_SERVICE_PARAMETER:
			RETURN_STATIC_STRING(
					"The file replication service detected an invalid parameter"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
