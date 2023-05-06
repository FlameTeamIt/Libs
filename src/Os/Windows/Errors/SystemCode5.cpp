#include <FlameIDE/../../src/Os/Windows/SystemCode5.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--4000-5999-
enum class SystemCode: decltype(::GetLastError())
{
	WINS_INTERNAL =
#	if defined ERROR_WINS_INTERNAL
			ERROR_WINS_INTERNAL
#	else
			0xFA0
#	endif
		// WINS encountered an error while processing the command.

	, CAN_NOT_DEL_LOCAL_WINS =
#	if defined ERROR_CAN_NOT_DEL_LOCAL_WINS
			ERROR_CAN_NOT_DEL_LOCAL_WINS
#	else
			0xFA1
#	endif
		// The local WINS cannot be deleted.

	, STATIC_INIT =
#	if defined ERROR_STATIC_INIT
			ERROR_STATIC_INIT
#	else
			0xFA2
#	endif
		// The importation from the file failed.

	, INC_BACKUP =
#	if defined ERROR_INC_BACKUP
			ERROR_INC_BACKUP
#	else
			0xFA3
#	endif
		// The backup failed. Was a full backup done before?

	, FULL_BACKUP =
#	if defined ERROR_FULL_BACKUP
			ERROR_FULL_BACKUP
#	else
			0xFA4
#	endif
		// The backup failed. Check the directory to which you are backing the database.

	, REC_NON_EXISTENT =
#	if defined ERROR_REC_NON_EXISTENT
			ERROR_REC_NON_EXISTENT
#	else
			0xFA5
#	endif
		// The name does not exist in the WINS database.

	, RPL_NOT_ALLOWED =
#	if defined ERROR_RPL_NOT_ALLOWED
			ERROR_RPL_NOT_ALLOWED
#	else
			0xFA6
#	endif
		// Replication with a nonconfigured partner is not allowed.

	, PEERDIST_CONTENTINFO_VERSION_UNSUPPORTED =
#	if defined PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED
			PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED
#	else
			0xFD2
#	endif
		// The version of the supplied content information is not supported.

	, PEERDIST_CANNOT_PARSE_CONTENTINFO =
#	if defined PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO
			PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO
#	else
			0xFD3
#	endif
		// The supplied content information is malformed.

	, PEERDIST_MISSING_DATA =
#	if defined PEERDIST_ERROR_MISSING_DATA
			PEERDIST_ERROR_MISSING_DATA
#	else
			0xFD4
#	endif
		// The requested data cannot be found in local or peer caches.

	, PEERDIST_NO_MORE =
#	if defined PEERDIST_ERROR_NO_MORE
			PEERDIST_ERROR_NO_MORE
#	else
			0xFD5
#	endif
		// No more data is available or required.

	, PEERDIST_NOT_INITIALIZED =
#	if defined PEERDIST_ERROR_NOT_INITIALIZED
			PEERDIST_ERROR_NOT_INITIALIZED
#	else
			0xFD6
#	endif
		// The supplied object has not been initialized.

	, PEERDIST_ALREADY_INITIALIZED =
#	if defined PEERDIST_ERROR_ALREADY_INITIALIZED
			PEERDIST_ERROR_ALREADY_INITIALIZED
#	else
			0xFD7
#	endif
		// The supplied object has already been initialized.

	, PEERDIST_SHUTDOWN_IN_PROGRESS =
#	if defined PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS
			PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS
#	else
			0xFD8
#	endif
		// A shutdown operation is already in progress.

	, PEERDIST_INVALIDATED =
#	if defined PEERDIST_ERROR_INVALIDATED
			PEERDIST_ERROR_INVALIDATED
#	else
			0xFD9
#	endif
		// The supplied object has already been invalidated.

	, PEERDIST_ALREADY_EXISTS =
#	if defined PEERDIST_ERROR_ALREADY_EXISTS
			PEERDIST_ERROR_ALREADY_EXISTS
#	else
			0xFDA
#	endif
		// An element already exists and was not replaced.

	, PEERDIST_OPERATION_NOTFOUND =
#	if defined PEERDIST_ERROR_OPERATION_NOTFOUND
			PEERDIST_ERROR_OPERATION_NOTFOUND
#	else
			0xFDB
#	endif
		// Can not cancel the requested operation as it has already been completed.

	, PEERDIST_ALREADY_COMPLETED =
#	if defined PEERDIST_ERROR_ALREADY_COMPLETED
			PEERDIST_ERROR_ALREADY_COMPLETED
#	else
			0xFDC
#	endif
		// Can not perform the reqested operation because it has already been carried out.

	, PEERDIST_OUT_OF_BOUNDS =
#	if defined PEERDIST_ERROR_OUT_OF_BOUNDS
			PEERDIST_ERROR_OUT_OF_BOUNDS
#	else
			0xFDD
#	endif
		// An operation accessed data beyond the bounds of valid data.

	, PEERDIST_VERSION_UNSUPPORTED =
#	if defined PEERDIST_ERROR_VERSION_UNSUPPORTED
			PEERDIST_ERROR_VERSION_UNSUPPORTED
#	else
			0xFDE
#	endif
		// The requested version is not supported.

	, PEERDIST_INVALID_CONFIGURATION =
#	if defined PEERDIST_ERROR_INVALID_CONFIGURATION
			PEERDIST_ERROR_INVALID_CONFIGURATION
#	else
			0xFDF
#	endif
		// A configuration value is invalid.

	, PEERDIST_NOT_LICENSED =
#	if defined PEERDIST_ERROR_NOT_LICENSED
			PEERDIST_ERROR_NOT_LICENSED
#	else
			0xFE0
#	endif
		// The SKU is not licensed.

	, PEERDIST_SERVICE_UNAVAILABLE =
#	if defined PEERDIST_ERROR_SERVICE_UNAVAILABLE
			PEERDIST_ERROR_SERVICE_UNAVAILABLE
#	else
			0xFE1
#	endif
		// PeerDist Service is still initializing and will be available shortly.

	, PEERDIST_TRUST_FAILURE =
#	if defined PEERDIST_ERROR_TRUST_FAILURE
			PEERDIST_ERROR_TRUST_FAILURE
#	else
			0xFE2
#	endif
		// Communication with one or more computers will be temporarily blocked due to recent errors.

	, DHCP_ADDRESS_CONFLICT =
#	if defined ERROR_DHCP_ADDRESS_CONFLICT
			ERROR_DHCP_ADDRESS_CONFLICT
#	else
			0x1004
#	endif
		// The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.

	, WMI_GUID_NOT_FOUND =
#	if defined ERROR_WMI_GUID_NOT_FOUND
			ERROR_WMI_GUID_NOT_FOUND
#	else
			0x1068
#	endif
		// The GUID passed was not recognized as valid by a WMI data provider.

	, WMI_INSTANCE_NOT_FOUND =
#	if defined ERROR_WMI_INSTANCE_NOT_FOUND
			ERROR_WMI_INSTANCE_NOT_FOUND
#	else
			0x1069
#	endif
		// The instance name passed was not recognized as valid by a WMI data provider.

	, WMI_ITEMID_NOT_FOUND =
#	if defined ERROR_WMI_ITEMID_NOT_FOUND
			ERROR_WMI_ITEMID_NOT_FOUND
#	else
			0x106A
#	endif
		// The data item ID passed was not recognized as valid by a WMI data provider.

	, WMI_TRY_AGAIN =
#	if defined ERROR_WMI_TRY_AGAIN
			ERROR_WMI_TRY_AGAIN
#	else
			0x106B
#	endif
		// The WMI request could not be completed and should be retried.

	, WMI_DP_NOT_FOUND =
#	if defined ERROR_WMI_DP_NOT_FOUND
			ERROR_WMI_DP_NOT_FOUND
#	else
			0x106C
#	endif
		// The WMI data provider could not be located.

	, WMI_UNRESOLVED_INSTANCE_REF =
#	if defined ERROR_WMI_UNRESOLVED_INSTANCE_REF
			ERROR_WMI_UNRESOLVED_INSTANCE_REF
#	else
			0x106D
#	endif
		// The WMI data provider references an instance set that has not been registered.

	, WMI_ALREADY_ENABLED =
#	if defined ERROR_WMI_ALREADY_ENABLED
			ERROR_WMI_ALREADY_ENABLED
#	else
			0x106E
#	endif
		// The WMI data block or event notification has already been enabled.

	, WMI_GUID_DISCONNECTED =
#	if defined ERROR_WMI_GUID_DISCONNECTED
			ERROR_WMI_GUID_DISCONNECTED
#	else
			0x106F
#	endif
		// The WMI data block is no longer available.

	, WMI_SERVER_UNAVAILABLE =
#	if defined ERROR_WMI_SERVER_UNAVAILABLE
			ERROR_WMI_SERVER_UNAVAILABLE
#	else
			0x1070
#	endif
		// The WMI data service is not available.

	, WMI_DP_FAILED =
#	if defined ERROR_WMI_DP_FAILED
			ERROR_WMI_DP_FAILED
#	else
			0x1071
#	endif
		// The WMI data provider failed to carry out the request.

	, WMI_INVALID_MOF =
#	if defined ERROR_WMI_INVALID_MOF
			ERROR_WMI_INVALID_MOF
#	else
			0x1072
#	endif
		// The WMI MOF information is not valid.

	, WMI_INVALID_REGINFO =
#	if defined ERROR_WMI_INVALID_REGINFO
			ERROR_WMI_INVALID_REGINFO
#	else
			0x1073
#	endif
		// The WMI registration information is not valid.

	, WMI_ALREADY_DISABLED =
#	if defined ERROR_WMI_ALREADY_DISABLED
			ERROR_WMI_ALREADY_DISABLED
#	else
			0x1074
#	endif
		// The WMI data block or event notification has already been disabled.

	, WMI_READ_ONLY =
#	if defined ERROR_WMI_READ_ONLY
			ERROR_WMI_READ_ONLY
#	else
			0x1075
#	endif
		// The WMI data item or data block is read only.

	, WMI_SET_FAILURE =
#	if defined ERROR_WMI_SET_FAILURE
			ERROR_WMI_SET_FAILURE
#	else
			0x1076
#	endif
		// The WMI data item or data block could not be changed.

	, NOT_APPCONTAINER =
#	if defined ERROR_NOT_APPCONTAINER
			ERROR_NOT_APPCONTAINER
#	else
			0x109A
#	endif
		// This operation is only valid in the context of an app container.

	, APPCONTAINER_REQUIRED =
#	if defined ERROR_APPCONTAINER_REQUIRED
			ERROR_APPCONTAINER_REQUIRED
#	else
			0x109B
#	endif
		// This application can only run in the context of an app container.

	, NOT_SUPPORTED_IN_APPCONTAINER =
#	if defined ERROR_NOT_SUPPORTED_IN_APPCONTAINER
			ERROR_NOT_SUPPORTED_IN_APPCONTAINER
#	else
			0x109C
#	endif
		// This functionality is not supported in the context of an app container.

	, INVALID_PACKAGE_SID_LENGTH =
#	if defined ERROR_INVALID_PACKAGE_SID_LENGTH
			ERROR_INVALID_PACKAGE_SID_LENGTH
#	else
			0x109D
#	endif
		// The length of the SID supplied is not a valid length for app container SIDs.

	, INVALID_MEDIA =
#	if defined ERROR_INVALID_MEDIA
			ERROR_INVALID_MEDIA
#	else
			0x10CC
#	endif
		// The media identifier does not represent a valid medium.

	, INVALID_LIBRARY =
#	if defined ERROR_INVALID_LIBRARY
			ERROR_INVALID_LIBRARY
#	else
			0x10CD
#	endif
		// The library identifier does not represent a valid library.

	, INVALID_MEDIA_POOL =
#	if defined ERROR_INVALID_MEDIA_POOL
			ERROR_INVALID_MEDIA_POOL
#	else
			0x10CE
#	endif
		// The media pool identifier does not represent a valid media pool.

	, DRIVE_MEDIA_MISMATCH =
#	if defined ERROR_DRIVE_MEDIA_MISMATCH
			ERROR_DRIVE_MEDIA_MISMATCH
#	else
			0x10CF
#	endif
		// The drive and medium are not compatible or exist in different libraries.

	, MEDIA_OFFLINE =
#	if defined ERROR_MEDIA_OFFLINE
			ERROR_MEDIA_OFFLINE
#	else
			0x10D0
#	endif
		// The medium currently exists in an offline library and must be online to perform this operation.

	, LIBRARY_OFFLINE =
#	if defined ERROR_LIBRARY_OFFLINE
			ERROR_LIBRARY_OFFLINE
#	else
			0x10D1
#	endif
		// The operation cannot be performed on an offline library.

	, EMPTY =
#	if defined ERROR_EMPTY
			ERROR_EMPTY
#	else
			0x10D2
#	endif
		// The library, drive, or media pool is empty.

	, NOT_EMPTY =
#	if defined ERROR_NOT_EMPTY
			ERROR_NOT_EMPTY
#	else
			0x10D3
#	endif
		// The library, drive, or media pool must be empty to perform this operation.

	, MEDIA_UNAVAILABLE =
#	if defined ERROR_MEDIA_UNAVAILABLE
			ERROR_MEDIA_UNAVAILABLE
#	else
			0x10D4
#	endif
		// No media is currently available in this media pool or library.

	, RESOURCE_DISABLED =
#	if defined ERROR_RESOURCE_DISABLED
			ERROR_RESOURCE_DISABLED
#	else
			0x10D5
#	endif
		// A resource required for this operation is disabled.

	, INVALID_CLEANER =
#	if defined ERROR_INVALID_CLEANER
			ERROR_INVALID_CLEANER
#	else
			0x10D6
#	endif
		// The media identifier does not represent a valid cleaner.

	, UNABLE_TO_CLEAN =
#	if defined ERROR_UNABLE_TO_CLEAN
			ERROR_UNABLE_TO_CLEAN
#	else
			0x10D7
#	endif
		// The drive cannot be cleaned or does not support cleaning.

	, OBJECT_NOT_FOUND =
#	if defined ERROR_OBJECT_NOT_FOUND
			ERROR_OBJECT_NOT_FOUND
#	else
			0x10D8
#	endif
		// The object identifier does not represent a valid object.

	, DATABASE_FAILURE =
#	if defined ERROR_DATABASE_FAILURE
			ERROR_DATABASE_FAILURE
#	else
			0x10D9
#	endif
		// Unable to read from or write to the database.

	, DATABASE_FULL =
#	if defined ERROR_DATABASE_FULL
			ERROR_DATABASE_FULL
#	else
			0x10DA
#	endif
		// The database is full.

	, MEDIA_INCOMPATIBLE =
#	if defined ERROR_MEDIA_INCOMPATIBLE
			ERROR_MEDIA_INCOMPATIBLE
#	else
			0x10DB
#	endif
		// The medium is not compatible with the device or media pool.

	, RESOURCE_NOT_PRESENT =
#	if defined ERROR_RESOURCE_NOT_PRESENT
			ERROR_RESOURCE_NOT_PRESENT
#	else
			0x10DC
#	endif
		// The resource required for this operation does not exist.

	, INVALID_OPERATION =
#	if defined ERROR_INVALID_OPERATION
			ERROR_INVALID_OPERATION
#	else
			0x10DD
#	endif
		// The operation identifier is not valid.

	, MEDIA_NOT_AVAILABLE =
#	if defined ERROR_MEDIA_NOT_AVAILABLE
			ERROR_MEDIA_NOT_AVAILABLE
#	else
			0x10DE
#	endif
		// The media is not mounted or ready for use.

	, DEVICE_NOT_AVAILABLE =
#	if defined ERROR_DEVICE_NOT_AVAILABLE
			ERROR_DEVICE_NOT_AVAILABLE
#	else
			0x10DF
#	endif
		// The device is not ready for use.

	, REQUEST_REFUSED =
#	if defined ERROR_REQUEST_REFUSED
			ERROR_REQUEST_REFUSED
#	else
			0x10E0
#	endif
		// The operator or administrator has refused the request.

	, INVALID_DRIVE_OBJECT =
#	if defined ERROR_INVALID_DRIVE_OBJECT
			ERROR_INVALID_DRIVE_OBJECT
#	else
			0x10E1
#	endif
		// The drive identifier does not represent a valid drive.

	, LIBRARY_FULL =
#	if defined ERROR_LIBRARY_FULL
			ERROR_LIBRARY_FULL
#	else
			0x10E2
#	endif
		// Library is full. No slot is available for use.

	, MEDIUM_NOT_ACCESSIBLE =
#	if defined ERROR_MEDIUM_NOT_ACCESSIBLE
			ERROR_MEDIUM_NOT_ACCESSIBLE
#	else
			0x10E3
#	endif
		// The transport cannot access the medium.

	, UNABLE_TO_LOAD_MEDIUM =
#	if defined ERROR_UNABLE_TO_LOAD_MEDIUM
			ERROR_UNABLE_TO_LOAD_MEDIUM
#	else
			0x10E4
#	endif
		// Unable to load the medium into the drive.

	, UNABLE_TO_INVENTORY_DRIVE =
#	if defined ERROR_UNABLE_TO_INVENTORY_DRIVE
			ERROR_UNABLE_TO_INVENTORY_DRIVE
#	else
			0x10E5
#	endif
		// Unable to retrieve the drive status.

	, UNABLE_TO_INVENTORY_SLOT =
#	if defined ERROR_UNABLE_TO_INVENTORY_SLOT
			ERROR_UNABLE_TO_INVENTORY_SLOT
#	else
			0x10E6
#	endif
		// Unable to retrieve the slot status.

	, UNABLE_TO_INVENTORY_TRANSPORT =
#	if defined ERROR_UNABLE_TO_INVENTORY_TRANSPORT
			ERROR_UNABLE_TO_INVENTORY_TRANSPORT
#	else
			0x10E7
#	endif
		// Unable to retrieve status about the transport.

	, TRANSPORT_FULL =
#	if defined ERROR_TRANSPORT_FULL
			ERROR_TRANSPORT_FULL
#	else
			0x10E8
#	endif
		// Cannot use the transport because it is already in use.

	, CONTROLLING_IEPORT =
#	if defined ERROR_CONTROLLING_IEPORT
			ERROR_CONTROLLING_IEPORT
#	else
			0x10E9
#	endif
		// Unable to open or close the inject/eject port.

	, UNABLE_TO_EJECT_MOUNTED_MEDIA =
#	if defined ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA
			ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA
#	else
			0x10EA
#	endif
		// Unable to eject the medium because it is in a drive.

	, CLEANER_SLOT_SET =
#	if defined ERROR_CLEANER_SLOT_SET
			ERROR_CLEANER_SLOT_SET
#	else
			0x10EB
#	endif
		// A cleaner slot is already reserved.

	, CLEANER_SLOT_NOT_SET =
#	if defined ERROR_CLEANER_SLOT_NOT_SET
			ERROR_CLEANER_SLOT_NOT_SET
#	else
			0x10EC
#	endif
		// A cleaner slot is not reserved.

	, CLEANER_CARTRIDGE_SPENT =
#	if defined ERROR_CLEANER_CARTRIDGE_SPENT
			ERROR_CLEANER_CARTRIDGE_SPENT
#	else
			0x10ED
#	endif
		// The cleaner cartridge has performed the maximum number of drive cleanings.

	, UNEXPECTED_OMID =
#	if defined ERROR_UNEXPECTED_OMID
			ERROR_UNEXPECTED_OMID
#	else
			0x10EE
#	endif
		// Unexpected on-medium identifier.

	, CANT_DELETE_LAST_ITEM =
#	if defined ERROR_CANT_DELETE_LAST_ITEM
			ERROR_CANT_DELETE_LAST_ITEM
#	else
			0x10EF
#	endif
		// The last remaining item in this group or resource cannot be deleted.

	, MESSAGE_EXCEEDS_MAX_SIZE =
#	if defined ERROR_MESSAGE_EXCEEDS_MAX_SIZE
			ERROR_MESSAGE_EXCEEDS_MAX_SIZE
#	else
			0x10F0
#	endif
		// The message provided exceeds the maximum size allowed for this parameter.

	, VOLUME_CONTAINS_SYS_FILES =
#	if defined ERROR_VOLUME_CONTAINS_SYS_FILES
			ERROR_VOLUME_CONTAINS_SYS_FILES
#	else
			0x10F1
#	endif
		// The volume contains system or paging files.

	, INDIGENOUS_TYPE =
#	if defined ERROR_INDIGENOUS_TYPE
			ERROR_INDIGENOUS_TYPE
#	else
			0x10F2
#	endif
		// The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.

	, NO_SUPPORTING_DRIVES =
#	if defined ERROR_NO_SUPPORTING_DRIVES
			ERROR_NO_SUPPORTING_DRIVES
#	else
			0x10F3
#	endif
		// This offline media cannot be mounted on this system since no enabled drives are present which can be used.

	, CLEANER_CARTRIDGE_INSTALLED =
#	if defined ERROR_CLEANER_CARTRIDGE_INSTALLED
			ERROR_CLEANER_CARTRIDGE_INSTALLED
#	else
			0x10F4
#	endif
		// A cleaner cartridge is present in the tape library.

	, IEPORT_FULL =
#	if defined ERROR_IEPORT_FULL
			ERROR_IEPORT_FULL
#	else
			0x10F5
#	endif
		// Cannot use the inject/eject port because it is not empty.

	, FILE_OFFLINE =
#	if defined ERROR_FILE_OFFLINE
			ERROR_FILE_OFFLINE
#	else
			0x10FE
#	endif
		// This file is currently not available for use on this computer.

	, REMOTE_STORAGE_NOT_ACTIVE =
#	if defined ERROR_REMOTE_STORAGE_NOT_ACTIVE
			ERROR_REMOTE_STORAGE_NOT_ACTIVE
#	else
			0x10FF
#	endif
		// The remote storage service is not operational at this time.

	, REMOTE_STORAGE_MEDIA_ERROR =
#	if defined ERROR_REMOTE_STORAGE_MEDIA_ERROR
			ERROR_REMOTE_STORAGE_MEDIA_ERROR
#	else
			0x1100
#	endif
		// The remote storage service encountered a media error.

	, NOT_A_REPARSE_POINT =
#	if defined ERROR_NOT_A_REPARSE_POINT
			ERROR_NOT_A_REPARSE_POINT
#	else
			0x1126
#	endif
		// The file or directory is not a reparse point.

	, REPARSE_ATTRIBUTE_CONFLICT =
#	if defined ERROR_REPARSE_ATTRIBUTE_CONFLICT
			ERROR_REPARSE_ATTRIBUTE_CONFLICT
#	else
			0x1127
#	endif
		// The reparse point attribute cannot be set because it conflicts with an existing attribute.

	, INVALID_REPARSE_DATA =
#	if defined ERROR_INVALID_REPARSE_DATA
			ERROR_INVALID_REPARSE_DATA
#	else
			0x1128
#	endif
		// The data present in the reparse point buffer is invalid.

	, REPARSE_TAG_INVALID =
#	if defined ERROR_REPARSE_TAG_INVALID
			ERROR_REPARSE_TAG_INVALID
#	else
			0x1129
#	endif
		// The tag present in the reparse point buffer is invalid.

	, REPARSE_TAG_MISMATCH =
#	if defined ERROR_REPARSE_TAG_MISMATCH
			ERROR_REPARSE_TAG_MISMATCH
#	else
			0x112A
#	endif
		// There is a mismatch between the tag specified in the request and the tag present in the reparse point.

	, APP_DATA_NOT_FOUND =
#	if defined ERROR_APP_DATA_NOT_FOUND
			ERROR_APP_DATA_NOT_FOUND
#	else
			0x1130
#	endif
		// Fast Cache data not found.

	, APP_DATA_EXPIRED =
#	if defined ERROR_APP_DATA_EXPIRED
			ERROR_APP_DATA_EXPIRED
#	else
			0x1131
#	endif
		// Fast Cache data expired.

	, APP_DATA_CORRUPT =
#	if defined ERROR_APP_DATA_CORRUPT
			ERROR_APP_DATA_CORRUPT
#	else
			0x1132
#	endif
		// Fast Cache data corrupt.

	, APP_DATA_LIMIT_EXCEEDED =
#	if defined ERROR_APP_DATA_LIMIT_EXCEEDED
			ERROR_APP_DATA_LIMIT_EXCEEDED
#	else
			0x1133
#	endif
		// Fast Cache data has exceeded its max size and cannot be updated.

	, APP_DATA_REBOOT_REQUIRED =
#	if defined ERROR_APP_DATA_REBOOT_REQUIRED
			ERROR_APP_DATA_REBOOT_REQUIRED
#	else
			0x1134
#	endif
		// Fast Cache has been ReArmed and requires a reboot until it can be updated.

	, SECUREBOOT_ROLLBACK_DETECTED =
#	if defined ERROR_SECUREBOOT_ROLLBACK_DETECTED
			ERROR_SECUREBOOT_ROLLBACK_DETECTED
#	else
			0x1144
#	endif
		// Secure Boot detected that rollback of protected data has been attempted.

	, SECUREBOOT_POLICY_VIOLATION =
#	if defined ERROR_SECUREBOOT_POLICY_VIOLATION
			ERROR_SECUREBOOT_POLICY_VIOLATION
#	else
			0x1145
#	endif
		// The value is protected by Secure Boot policy and cannot be modified or deleted.

	, SECUREBOOT_INVALID_POLICY =
#	if defined ERROR_SECUREBOOT_INVALID_POLICY
			ERROR_SECUREBOOT_INVALID_POLICY
#	else
			0x1146
#	endif
		// The Secure Boot policy is invalid.

	, SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND =
#	if defined ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND
			ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND
#	else
			0x1147
#	endif
		// A new Secure Boot policy did not contain the current publisher on its update list.

	, SECUREBOOT_POLICY_NOT_SIGNED =
#	if defined ERROR_SECUREBOOT_POLICY_NOT_SIGNED
			ERROR_SECUREBOOT_POLICY_NOT_SIGNED
#	else
			0x1148
#	endif
		// The Secure Boot policy is either not signed or is signed by a non-trusted signer.

	, SECUREBOOT_NOT_ENABLED =
#	if defined ERROR_SECUREBOOT_NOT_ENABLED
			ERROR_SECUREBOOT_NOT_ENABLED
#	else
			0x1149
#	endif
		// Secure Boot is not enabled on this machine.

	, SECUREBOOT_FILE_REPLACED =
#	if defined ERROR_SECUREBOOT_FILE_REPLACED
			ERROR_SECUREBOOT_FILE_REPLACED
#	else
			0x114A
#	endif
		// Secure Boot requires that certain files and drivers are not replaced by other files or drivers.

	, OFFLOAD_READ_FLT_NOT_SUPPORTED =
#	if defined ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED
			ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED
#	else
			0x1158
#	endif
		// The copy offload read operation is not supported by a filter.

	, OFFLOAD_WRITE_FLT_NOT_SUPPORTED =
#	if defined ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED
			ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED
#	else
			0x1159
#	endif
		// The copy offload write operation is not supported by a filter.

	, OFFLOAD_READ_FILE_NOT_SUPPORTED =
#	if defined ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED
			ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED
#	else
			0x115A
#	endif
		// The copy offload read operation is not supported for the file.

	, OFFLOAD_WRITE_FILE_NOT_SUPPORTED =
#	if defined ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED
			ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED
#	else
			0x115B
#	endif
		// The copy offload write operation is not supported for the file.

	, VOLUME_NOT_SIS_ENABLED =
#	if defined ERROR_VOLUME_NOT_SIS_ENABLED
			ERROR_VOLUME_NOT_SIS_ENABLED
#	else
			0x1194
#	endif
		// Single Instance Storage is not available on this volume.

	, DEPENDENT_RESOURCE_EXISTS =
#	if defined ERROR_DEPENDENT_RESOURCE_EXISTS
			ERROR_DEPENDENT_RESOURCE_EXISTS
#	else
			0x1389
#	endif
		// The operation cannot be completed because other resources are dependent on this resource.

	, DEPENDENCY_NOT_FOUND =
#	if defined ERROR_DEPENDENCY_NOT_FOUND
			ERROR_DEPENDENCY_NOT_FOUND
#	else
			0x138A
#	endif
		// The cluster resource dependency cannot be found.

	, DEPENDENCY_ALREADY_EXISTS =
#	if defined ERROR_DEPENDENCY_ALREADY_EXISTS
			ERROR_DEPENDENCY_ALREADY_EXISTS
#	else
			0x138B
#	endif
		// The cluster resource cannot be made dependent on the specified resource because it is already dependent.

	, RESOURCE_NOT_ONLINE =
#	if defined ERROR_RESOURCE_NOT_ONLINE
			ERROR_RESOURCE_NOT_ONLINE
#	else
			0x138C
#	endif
		// The cluster resource is not online.

	, HOST_NODE_NOT_AVAILABLE =
#	if defined ERROR_HOST_NODE_NOT_AVAILABLE
			ERROR_HOST_NODE_NOT_AVAILABLE
#	else
			0x138D
#	endif
		// A cluster node is not available for this operation.

	, RESOURCE_NOT_AVAILABLE =
#	if defined ERROR_RESOURCE_NOT_AVAILABLE
			ERROR_RESOURCE_NOT_AVAILABLE
#	else
			0x138E
#	endif
		// The cluster resource is not available.

	, RESOURCE_NOT_FOUND =
#	if defined ERROR_RESOURCE_NOT_FOUND
			ERROR_RESOURCE_NOT_FOUND
#	else
			0x138F
#	endif
		// The cluster resource could not be found.

	, SHUTDOWN_CLUSTER =
#	if defined ERROR_SHUTDOWN_CLUSTER
			ERROR_SHUTDOWN_CLUSTER
#	else
			0x1390
#	endif
		// The cluster is being shut down.

	, CANT_EVICT_ACTIVE_NODE =
#	if defined ERROR_CANT_EVICT_ACTIVE_NODE
			ERROR_CANT_EVICT_ACTIVE_NODE
#	else
			0x1391
#	endif
		// A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.

	, OBJECT_ALREADY_EXISTS =
#	if defined ERROR_OBJECT_ALREADY_EXISTS
			ERROR_OBJECT_ALREADY_EXISTS
#	else
			0x1392
#	endif
		// The object already exists.

	, OBJECT_IN_LIST =
#	if defined ERROR_OBJECT_IN_LIST
			ERROR_OBJECT_IN_LIST
#	else
			0x1393
#	endif
		// The object is already in the list.

	, GROUP_NOT_AVAILABLE =
#	if defined ERROR_GROUP_NOT_AVAILABLE
			ERROR_GROUP_NOT_AVAILABLE
#	else
			0x1394
#	endif
		// The cluster group is not available for any new requests.

	, GROUP_NOT_FOUND =
#	if defined ERROR_GROUP_NOT_FOUND
			ERROR_GROUP_NOT_FOUND
#	else
			0x1395
#	endif
		// The cluster group could not be found.

	, GROUP_NOT_ONLINE =
#	if defined ERROR_GROUP_NOT_ONLINE
			ERROR_GROUP_NOT_ONLINE
#	else
			0x1396
#	endif
		// The operation could not be completed because the cluster group is not online.

	, HOST_NODE_NOT_RESOURCE_OWNER =
#	if defined ERROR_HOST_NODE_NOT_RESOURCE_OWNER
			ERROR_HOST_NODE_NOT_RESOURCE_OWNER
#	else
			0x1397
#	endif
		// The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.

	, HOST_NODE_NOT_GROUP_OWNER =
#	if defined ERROR_HOST_NODE_NOT_GROUP_OWNER
			ERROR_HOST_NODE_NOT_GROUP_OWNER
#	else
			0x1398
#	endif
		// The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.

	, RESMON_CREATE_FAILED =
#	if defined ERROR_RESMON_CREATE_FAILED
			ERROR_RESMON_CREATE_FAILED
#	else
			0x1399
#	endif
		// The cluster resource could not be created in the specified resource monitor.

	, RESMON_ONLINE_FAILED =
#	if defined ERROR_RESMON_ONLINE_FAILED
			ERROR_RESMON_ONLINE_FAILED
#	else
			0x139A
#	endif
		// The cluster resource could not be brought online by the resource monitor.

	, RESOURCE_ONLINE =
#	if defined ERROR_RESOURCE_ONLINE
			ERROR_RESOURCE_ONLINE
#	else
			0x139B
#	endif
		// The operation could not be completed because the cluster resource is online.

	, QUORUM_RESOURCE =
#	if defined ERROR_QUORUM_RESOURCE
			ERROR_QUORUM_RESOURCE
#	else
			0x139C
#	endif
		// The cluster resource could not be deleted or brought offline because it is the quorum resource.

	, NOT_QUORUM_CAPABLE =
#	if defined ERROR_NOT_QUORUM_CAPABLE
			ERROR_NOT_QUORUM_CAPABLE
#	else
			0x139D
#	endif
		// The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.

	, CLUSTER_SHUTTING_DOWN =
#	if defined ERROR_CLUSTER_SHUTTING_DOWN
			ERROR_CLUSTER_SHUTTING_DOWN
#	else
			0x139E
#	endif
		// The cluster software is shutting down.

	, INVALID_STATE =
#	if defined ERROR_INVALID_STATE
			ERROR_INVALID_STATE
#	else
			0x139F
#	endif
		// The group or resource is not in the correct state to perform the requested operation.

	, RESOURCE_PROPERTIES_STORED =
#	if defined ERROR_RESOURCE_PROPERTIES_STORED
			ERROR_RESOURCE_PROPERTIES_STORED
#	else
			0x13A0
#	endif
		// The properties were stored but not all changes will take effect until the next time the resource is brought online.

	, NOT_QUORUM_CLASS =
#	if defined ERROR_NOT_QUORUM_CLASS
			ERROR_NOT_QUORUM_CLASS
#	else
			0x13A1
#	endif
		// The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.

	, CORE_RESOURCE =
#	if defined ERROR_CORE_RESOURCE
			ERROR_CORE_RESOURCE
#	else
			0x13A2
#	endif
		// The cluster resource could not be deleted since it is a core resource.

	, QUORUM_RESOURCE_ONLINE_FAILED =
#	if defined ERROR_QUORUM_RESOURCE_ONLINE_FAILED
			ERROR_QUORUM_RESOURCE_ONLINE_FAILED
#	else
			0x13A3
#	endif
		// The quorum resource failed to come online.

	, QUORUMLOG_OPEN_FAILED =
#	if defined ERROR_QUORUMLOG_OPEN_FAILED
			ERROR_QUORUMLOG_OPEN_FAILED
#	else
			0x13A4
#	endif
		// The quorum log could not be created or mounted successfully.

	, CLUSTERLOG_CORRUPT =
#	if defined ERROR_CLUSTERLOG_CORRUPT
			ERROR_CLUSTERLOG_CORRUPT
#	else
			0x13A5
#	endif
		// The cluster log is corrupt.

	, CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE =
#	if defined ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE
			ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE
#	else
			0x13A6
#	endif
		// The record could not be written to the cluster log since it exceeds the maximum size.

	, CLUSTERLOG_EXCEEDS_MAXSIZE =
#	if defined ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE
			ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE
#	else
			0x13A7
#	endif
		// The cluster log exceeds its maximum size.

	, CLUSTERLOG_CHKPOINT_NOT_FOUND =
#	if defined ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND
			ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND
#	else
			0x13A8
#	endif
		// No checkpoint record was found in the cluster log.

	, CLUSTERLOG_NOT_ENOUGH_SPACE =
#	if defined ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE
			ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE
#	else
			0x13A9
#	endif
		// The minimum required disk space needed for logging is not available.

	, QUORUM_OWNER_ALIVE =
#	if defined ERROR_QUORUM_OWNER_ALIVE
			ERROR_QUORUM_OWNER_ALIVE
#	else
			0x13AA
#	endif
		// The cluster node failed to take control of the quorum resource because the resource is owned by another active node.

	, NETWORK_NOT_AVAILABLE =
#	if defined ERROR_NETWORK_NOT_AVAILABLE
			ERROR_NETWORK_NOT_AVAILABLE
#	else
			0x13AB
#	endif
		// A cluster network is not available for this operation.

	, NODE_NOT_AVAILABLE =
#	if defined ERROR_NODE_NOT_AVAILABLE
			ERROR_NODE_NOT_AVAILABLE
#	else
			0x13AC
#	endif
		// A cluster node is not available for this operation.

	, ALL_NODES_NOT_AVAILABLE =
#	if defined ERROR_ALL_NODES_NOT_AVAILABLE
			ERROR_ALL_NODES_NOT_AVAILABLE
#	else
			0x13AD
#	endif
		// All cluster nodes must be running to perform this operation.

	, RESOURCE_FAILED =
#	if defined ERROR_RESOURCE_FAILED
			ERROR_RESOURCE_FAILED
#	else
			0x13AE
#	endif
		// A cluster resource failed.

	, CLUSTER_INVALID_NODE =
#	if defined ERROR_CLUSTER_INVALID_NODE
			ERROR_CLUSTER_INVALID_NODE
#	else
			0x13AF
#	endif
		// The cluster node is not valid.

	, CLUSTER_NODE_EXISTS =
#	if defined ERROR_CLUSTER_NODE_EXISTS
			ERROR_CLUSTER_NODE_EXISTS
#	else
			0x13B0
#	endif
		// The cluster node already exists.

	, CLUSTER_JOIN_IN_PROGRESS =
#	if defined ERROR_CLUSTER_JOIN_IN_PROGRESS
			ERROR_CLUSTER_JOIN_IN_PROGRESS
#	else
			0x13B1
#	endif
		// A node is in the process of joining the cluster.

	, CLUSTER_NODE_NOT_FOUND =
#	if defined ERROR_CLUSTER_NODE_NOT_FOUND
			ERROR_CLUSTER_NODE_NOT_FOUND
#	else
			0x13B2
#	endif
		// The cluster node was not found.

	, CLUSTER_LOCAL_NODE_NOT_FOUND =
#	if defined ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND
			ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND
#	else
			0x13B3
#	endif
		// The cluster local node information was not found.

	, CLUSTER_NETWORK_EXISTS =
#	if defined ERROR_CLUSTER_NETWORK_EXISTS
			ERROR_CLUSTER_NETWORK_EXISTS
#	else
			0x13B4
#	endif
		// The cluster network already exists.

	, CLUSTER_NETWORK_NOT_FOUND =
#	if defined ERROR_CLUSTER_NETWORK_NOT_FOUND
			ERROR_CLUSTER_NETWORK_NOT_FOUND
#	else
			0x13B5
#	endif
		// The cluster network was not found.

	, CLUSTER_NETINTERFACE_EXISTS =
#	if defined ERROR_CLUSTER_NETINTERFACE_EXISTS
			ERROR_CLUSTER_NETINTERFACE_EXISTS
#	else
			0x13B6
#	endif
		// The cluster network interface already exists.

	, CLUSTER_NETINTERFACE_NOT_FOUND =
#	if defined ERROR_CLUSTER_NETINTERFACE_NOT_FOUND
			ERROR_CLUSTER_NETINTERFACE_NOT_FOUND
#	else
			0x13B7
#	endif
		// The cluster network interface was not found.

	, CLUSTER_INVALID_REQUEST =
#	if defined ERROR_CLUSTER_INVALID_REQUEST
			ERROR_CLUSTER_INVALID_REQUEST
#	else
			0x13B8
#	endif
		// The cluster request is not valid for this object.

	, CLUSTER_INVALID_NETWORK_PROVIDER =
#	if defined ERROR_CLUSTER_INVALID_NETWORK_PROVIDER
			ERROR_CLUSTER_INVALID_NETWORK_PROVIDER
#	else
			0x13B9
#	endif
		// The cluster network provider is not valid.

	, CLUSTER_NODE_DOWN =
#	if defined ERROR_CLUSTER_NODE_DOWN
			ERROR_CLUSTER_NODE_DOWN
#	else
			0x13BA
#	endif
		// The cluster node is down.

	, CLUSTER_NODE_UNREACHABLE =
#	if defined ERROR_CLUSTER_NODE_UNREACHABLE
			ERROR_CLUSTER_NODE_UNREACHABLE
#	else
			0x13BB
#	endif
		// The cluster node is not reachable.

	, CLUSTER_NODE_NOT_MEMBER =
#	if defined ERROR_CLUSTER_NODE_NOT_MEMBER
			ERROR_CLUSTER_NODE_NOT_MEMBER
#	else
			0x13BC
#	endif
		// The cluster node is not a member of the cluster.

	, CLUSTER_JOIN_NOT_IN_PROGRESS =
#	if defined ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS
			ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS
#	else
			0x13BD
#	endif
		// A cluster join operation is not in progress.

	, CLUSTER_INVALID_NETWORK =
#	if defined ERROR_CLUSTER_INVALID_NETWORK
			ERROR_CLUSTER_INVALID_NETWORK
#	else
			0x13BE
#	endif
		// The cluster network is not valid.

	, CLUSTER_NODE_UP =
#	if defined ERROR_CLUSTER_NODE_UP
			ERROR_CLUSTER_NODE_UP
#	else
			0x13C0
#	endif
		// The cluster node is up.

	, CLUSTER_IPADDR_IN_USE =
#	if defined ERROR_CLUSTER_IPADDR_IN_USE
			ERROR_CLUSTER_IPADDR_IN_USE
#	else
			0x13C1
#	endif
		// The cluster IP address is already in use.

	, CLUSTER_NODE_NOT_PAUSED =
#	if defined ERROR_CLUSTER_NODE_NOT_PAUSED
			ERROR_CLUSTER_NODE_NOT_PAUSED
#	else
			0x13C2
#	endif
		// The cluster node is not paused.

	, CLUSTER_NO_SECURITY_CONTEXT =
#	if defined ERROR_CLUSTER_NO_SECURITY_CONTEXT
			ERROR_CLUSTER_NO_SECURITY_CONTEXT
#	else
			0x13C3
#	endif
		// No cluster security context is available.

	, CLUSTER_NETWORK_NOT_INTERNAL =
#	if defined ERROR_CLUSTER_NETWORK_NOT_INTERNAL
			ERROR_CLUSTER_NETWORK_NOT_INTERNAL
#	else
			0x13C4
#	endif
		// The cluster network is not configured for internal cluster communication.

	, CLUSTER_NODE_ALREADY_UP =
#	if defined ERROR_CLUSTER_NODE_ALREADY_UP
			ERROR_CLUSTER_NODE_ALREADY_UP
#	else
			0x13C5
#	endif
		// The cluster node is already up.

	, CLUSTER_NODE_ALREADY_DOWN =
#	if defined ERROR_CLUSTER_NODE_ALREADY_DOWN
			ERROR_CLUSTER_NODE_ALREADY_DOWN
#	else
			0x13C6
#	endif
		// The cluster node is already down.

	, CLUSTER_NETWORK_ALREADY_ONLINE =
#	if defined ERROR_CLUSTER_NETWORK_ALREADY_ONLINE
			ERROR_CLUSTER_NETWORK_ALREADY_ONLINE
#	else
			0x13C7
#	endif
		// The cluster network is already online.

	, CLUSTER_NETWORK_ALREADY_OFFLINE =
#	if defined ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE
			ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE
#	else
			0x13C8
#	endif
		// The cluster network is already offline.

	, CLUSTER_NODE_ALREADY_MEMBER =
#	if defined ERROR_CLUSTER_NODE_ALREADY_MEMBER
			ERROR_CLUSTER_NODE_ALREADY_MEMBER
#	else
			0x13C9
#	endif
		// The cluster node is already a member of the cluster.

	, CLUSTER_LAST_INTERNAL_NETWORK =
#	if defined ERROR_CLUSTER_LAST_INTERNAL_NETWORK
			ERROR_CLUSTER_LAST_INTERNAL_NETWORK
#	else
			0x13CA
#	endif
		// The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.

	, CLUSTER_NETWORK_HAS_DEPENDENTS =
#	if defined ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS
			ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS
#	else
			0x13CB
#	endif
		// One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.

	, INVALID_OPERATION_ON_QUORUM =
#	if defined ERROR_INVALID_OPERATION_ON_QUORUM
			ERROR_INVALID_OPERATION_ON_QUORUM
#	else
			0x13CC
#	endif
		// This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.

	, DEPENDENCY_NOT_ALLOWED =
#	if defined ERROR_DEPENDENCY_NOT_ALLOWED
			ERROR_DEPENDENCY_NOT_ALLOWED
#	else
			0x13CD
#	endif
		// The cluster quorum resource is not allowed to have any dependencies.

	, CLUSTER_NODE_PAUSED =
#	if defined ERROR_CLUSTER_NODE_PAUSED
			ERROR_CLUSTER_NODE_PAUSED
#	else
			0x13CE
#	endif
		// The cluster node is paused.

	, NODE_CANT_HOST_RESOURCE =
#	if defined ERROR_NODE_CANT_HOST_RESOURCE
			ERROR_NODE_CANT_HOST_RESOURCE
#	else
			0x13CF
#	endif
		// The cluster resource cannot be brought online. The owner node cannot run this resource.

	, CLUSTER_NODE_NOT_READY =
#	if defined ERROR_CLUSTER_NODE_NOT_READY
			ERROR_CLUSTER_NODE_NOT_READY
#	else
			0x13D0
#	endif
		// The cluster node is not ready to perform the requested operation.

	, CLUSTER_NODE_SHUTTING_DOWN =
#	if defined ERROR_CLUSTER_NODE_SHUTTING_DOWN
			ERROR_CLUSTER_NODE_SHUTTING_DOWN
#	else
			0x13D1
#	endif
		// The cluster node is shutting down.

	, CLUSTER_JOIN_ABORTED =
#	if defined ERROR_CLUSTER_JOIN_ABORTED
			ERROR_CLUSTER_JOIN_ABORTED
#	else
			0x13D2
#	endif
		// The cluster join operation was aborted.

	, CLUSTER_INCOMPATIBLE_VERSIONS =
#	if defined ERROR_CLUSTER_INCOMPATIBLE_VERSIONS
			ERROR_CLUSTER_INCOMPATIBLE_VERSIONS
#	else
			0x13D3
#	endif
		// The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.

	, CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED =
#	if defined ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED
			ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED
#	else
			0x13D4
#	endif
		// This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.

	, CLUSTER_SYSTEM_CONFIG_CHANGED =
#	if defined ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED
			ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED
#	else
			0x13D5
#	endif
		// The system configuration changed during the cluster join or form operation. The join or form operation was aborted.

	, CLUSTER_RESOURCE_TYPE_NOT_FOUND =
#	if defined ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND
			ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND
#	else
			0x13D6
#	endif
		// The specified resource type was not found.

	, CLUSTER_RESTYPE_NOT_SUPPORTED =
#	if defined ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED
			ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED
#	else
			0x13D7
#	endif
		// The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.

	, CLUSTER_RESNAME_NOT_FOUND =
#	if defined ERROR_CLUSTER_RESNAME_NOT_FOUND
			ERROR_CLUSTER_RESNAME_NOT_FOUND
#	else
			0x13D8
#	endif
		// The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.

	, CLUSTER_NO_RPC_PACKAGES_REGISTERED =
#	if defined ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED
			ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED
#	else
			0x13D9
#	endif
		// No authentication package could be registered with the RPC server.

	, CLUSTER_OWNER_NOT_IN_PREFLIST =
#	if defined ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST
			ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST
#	else
			0x13DA
#	endif
		// You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.

	, CLUSTER_DATABASE_SEQMISMATCH =
#	if defined ERROR_CLUSTER_DATABASE_SEQMISMATCH
			ERROR_CLUSTER_DATABASE_SEQMISMATCH
#	else
			0x13DB
#	endif
		// The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.

	, RESMON_INVALID_STATE =
#	if defined ERROR_RESMON_INVALID_STATE
			ERROR_RESMON_INVALID_STATE
#	else
			0x13DC
#	endif
		// The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.

	, CLUSTER_GUM_NOT_LOCKER =
#	if defined ERROR_CLUSTER_GUM_NOT_LOCKER
			ERROR_CLUSTER_GUM_NOT_LOCKER
#	else
			0x13DD
#	endif
		// A non locker code got a request to reserve the lock for making global updates.

	, QUORUM_DISK_NOT_FOUND =
#	if defined ERROR_QUORUM_DISK_NOT_FOUND
			ERROR_QUORUM_DISK_NOT_FOUND
#	else
			0x13DE
#	endif
		// The quorum disk could not be located by the cluster service.

	, DATABASE_BACKUP_CORRUPT =
#	if defined ERROR_DATABASE_BACKUP_CORRUPT
			ERROR_DATABASE_BACKUP_CORRUPT
#	else
			0x13DF
#	endif
		// The backed up cluster database is possibly corrupt.

	, CLUSTER_NODE_ALREADY_HAS_DFS_ROOT =
#	if defined ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT
			ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT
#	else
			0x13E0
#	endif
		// A DFS root already exists in this cluster node.

	, RESOURCE_PROPERTY_UNCHANGEABLE =
#	if defined ERROR_RESOURCE_PROPERTY_UNCHANGEABLE
			ERROR_RESOURCE_PROPERTY_UNCHANGEABLE
#	else
			0x13E1
#	endif
		// An attempt to modify a resource property failed because it conflicts with another existing property.

	, CLUSTER_MEMBERSHIP_INVALID_STATE =
#	if defined ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE
			ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE
#	else
			0x1702
#	endif
		// An operation was attempted that is incompatible with the current membership state of the node.

	, CLUSTER_QUORUMLOG_NOT_FOUND =
#	if defined ERROR_CLUSTER_QUORUMLOG_NOT_FOUND
			ERROR_CLUSTER_QUORUMLOG_NOT_FOUND
#	else
			0x1703
#	endif
		// The quorum resource does not contain the quorum log.

	, CLUSTER_MEMBERSHIP_HALT =
#	if defined ERROR_CLUSTER_MEMBERSHIP_HALT
			ERROR_CLUSTER_MEMBERSHIP_HALT
#	else
			0x1704
#	endif
		// The membership engine requested shutdown of the cluster service on this node.

	, CLUSTER_INSTANCE_ID_MISMATCH =
#	if defined ERROR_CLUSTER_INSTANCE_ID_MISMATCH
			ERROR_CLUSTER_INSTANCE_ID_MISMATCH
#	else
			0x1705
#	endif
		// The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.

	, CLUSTER_NETWORK_NOT_FOUND_FOR_IP =
#	if defined ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP
			ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP
#	else
			0x1706
#	endif
		// A matching cluster network for the specified IP address could not be found.

	, CLUSTER_PROPERTY_DATA_TYPE_MISMATCH =
#	if defined ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH
			ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH
#	else
			0x1707
#	endif
		// The actual data type of the property did not match the expected data type of the property.

	, CLUSTER_EVICT_WITHOUT_CLEANUP =
#	if defined ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP
			ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP
#	else
			0x1708
#	endif
		// The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.

	, CLUSTER_PARAMETER_MISMATCH =
#	if defined ERROR_CLUSTER_PARAMETER_MISMATCH
			ERROR_CLUSTER_PARAMETER_MISMATCH
#	else
			0x1709
#	endif
		// Two or more parameter values specified for a resource's properties are in conflict.

	, NODE_CANNOT_BE_CLUSTERED =
#	if defined ERROR_NODE_CANNOT_BE_CLUSTERED
			ERROR_NODE_CANNOT_BE_CLUSTERED
#	else
			0x170A
#	endif
		// This computer cannot be made a member of a cluster.

	, CLUSTER_WRONG_OS_VERSION =
#	if defined ERROR_CLUSTER_WRONG_OS_VERSION
			ERROR_CLUSTER_WRONG_OS_VERSION
#	else
			0x170B
#	endif
		// This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.

	, CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME =
#	if defined ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME
			ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME
#	else
			0x170C
#	endif
		// A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.

	, CLUSCFG_ALREADY_COMMITTED =
#	if defined ERROR_CLUSCFG_ALREADY_COMMITTED
			ERROR_CLUSCFG_ALREADY_COMMITTED
#	else
			0x170D
#	endif
		// The cluster configuration action has already been committed.

	, CLUSCFG_ROLLBACK_FAILED =
#	if defined ERROR_CLUSCFG_ROLLBACK_FAILED
			ERROR_CLUSCFG_ROLLBACK_FAILED
#	else
			0x170E
#	endif
		// The cluster configuration action could not be rolled back.

	, CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT =
#	if defined ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT
			ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT
#	else
			0x170F
#	endif
		// The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.

	, CLUSTER_OLD_VERSION =
#	if defined ERROR_CLUSTER_OLD_VERSION
			ERROR_CLUSTER_OLD_VERSION
#	else
			0x1710
#	endif
		// One or more nodes in the cluster are running a version of Windows that does not support this operation.

	, CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME =
#	if defined ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME
			ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME
#	else
			0x1711
#	endif
		// The name of the corresponding computer account doesn't match the Network Name for this resource.

	, CLUSTER_NO_NET_ADAPTERS =
#	if defined ERROR_CLUSTER_NO_NET_ADAPTERS
			ERROR_CLUSTER_NO_NET_ADAPTERS
#	else
			0x1712
#	endif
		// No network adapters are available.

	, CLUSTER_POISONED =
#	if defined ERROR_CLUSTER_POISONED
			ERROR_CLUSTER_POISONED
#	else
			0x1713
#	endif
		// The cluster node has been poisoned.

	, CLUSTER_GROUP_MOVING =
#	if defined ERROR_CLUSTER_GROUP_MOVING
			ERROR_CLUSTER_GROUP_MOVING
#	else
			0x1714
#	endif
		// The group is unable to accept the request since it is moving to another node.

	, CLUSTER_RESOURCE_TYPE_BUSY =
#	if defined ERROR_CLUSTER_RESOURCE_TYPE_BUSY
			ERROR_CLUSTER_RESOURCE_TYPE_BUSY
#	else
			0x1715
#	endif
		// The resource type cannot accept the request since is too busy performing another operation.

	, RESOURCE_CALL_TIMED_OUT =
#	if defined ERROR_RESOURCE_CALL_TIMED_OUT
			ERROR_RESOURCE_CALL_TIMED_OUT
#	else
			0x1716
#	endif
		// The call to the cluster resource DLL timed out.

	, INVALID_CLUSTER_IPV6_ADDRESS =
#	if defined ERROR_INVALID_CLUSTER_IPV6_ADDRESS
			ERROR_INVALID_CLUSTER_IPV6_ADDRESS
#	else
			0x1717
#	endif
		// The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.

	, CLUSTER_INTERNAL_INVALID_FUNCTION =
#	if defined ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION
			ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION
#	else
			0x1718
#	endif
		// An internal cluster error occurred. A call to an invalid function was attempted.

	, CLUSTER_PARAMETER_OUT_OF_BOUNDS =
#	if defined ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS
			ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS
#	else
			0x1719
#	endif
		// A parameter value is out of acceptable range.

	, CLUSTER_PARTIAL_SEND =
#	if defined ERROR_CLUSTER_PARTIAL_SEND
			ERROR_CLUSTER_PARTIAL_SEND
#	else
			0x171A
#	endif
		// A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.

	, CLUSTER_REGISTRY_INVALID_FUNCTION =
#	if defined ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION
			ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION
#	else
			0x171B
#	endif
		// An invalid cluster registry operation was attempted.

	, CLUSTER_INVALID_STRING_TERMINATION =
#	if defined ERROR_CLUSTER_INVALID_STRING_TERMINATION
			ERROR_CLUSTER_INVALID_STRING_TERMINATION
#	else
			0x171C
#	endif
		// An input string of characters is not properly terminated.

	, CLUSTER_INVALID_STRING_FORMAT =
#	if defined ERROR_CLUSTER_INVALID_STRING_FORMAT
			ERROR_CLUSTER_INVALID_STRING_FORMAT
#	else
			0x171D
#	endif
		// An input string of characters is not in a valid format for the data it represents.

	, CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS =
#	if defined ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS
			ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS
#	else
			0x171E
#	endif
		// An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.

	, CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS =
#	if defined ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS
			ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS
#	else
			0x171F
#	endif
		// An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.

	, CLUSTER_NULL_DATA =
#	if defined ERROR_CLUSTER_NULL_DATA
			ERROR_CLUSTER_NULL_DATA
#	else
			0x1720
#	endif
		// An internal cluster error occurred. Data was not properly initialized.

	, CLUSTER_PARTIAL_READ =
#	if defined ERROR_CLUSTER_PARTIAL_READ
			ERROR_CLUSTER_PARTIAL_READ
#	else
			0x1721
#	endif
		// An error occurred while reading from a stream of data. An unexpected number of bytes was returned.

	, CLUSTER_PARTIAL_WRITE =
#	if defined ERROR_CLUSTER_PARTIAL_WRITE
			ERROR_CLUSTER_PARTIAL_WRITE
#	else
			0x1722
#	endif
		// An error occurred while writing to a stream of data. The required number of bytes could not be written.

	, CLUSTER_CANT_DESERIALIZE_DATA =
#	if defined ERROR_CLUSTER_CANT_DESERIALIZE_DATA
			ERROR_CLUSTER_CANT_DESERIALIZE_DATA
#	else
			0x1723
#	endif
		// An error occurred while deserializing a stream of cluster data.

	, DEPENDENT_RESOURCE_PROPERTY_CONFLICT =
#	if defined ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT
			ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT
#	else
			0x1724
#	endif
		// One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).

	, CLUSTER_NO_QUORUM =
#	if defined ERROR_CLUSTER_NO_QUORUM
			ERROR_CLUSTER_NO_QUORUM
#	else
			0x1725
#	endif
		// A quorum of cluster nodes was not present to form a cluster.

	, CLUSTER_INVALID_IPV6_NETWORK =
#	if defined ERROR_CLUSTER_INVALID_IPV6_NETWORK
			ERROR_CLUSTER_INVALID_IPV6_NETWORK
#	else
			0x1726
#	endif
		// The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.

	, CLUSTER_INVALID_IPV6_TUNNEL_NETWORK =
#	if defined ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK
			ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK
#	else
			0x1727
#	endif
		// The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.

	, QUORUM_NOT_ALLOWED_IN_THIS_GROUP =
#	if defined ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP
			ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP
#	else
			0x1728
#	endif
		// Quorum resource cannot reside in the Available Storage group.

	, DEPENDENCY_TREE_TOO_COMPLEX =
#	if defined ERROR_DEPENDENCY_TREE_TOO_COMPLEX
			ERROR_DEPENDENCY_TREE_TOO_COMPLEX
#	else
			0x1729
#	endif
		// The dependencies for this resource are nested too deeply.

	, EXCEPTION_IN_RESOURCE_CALL =
#	if defined ERROR_EXCEPTION_IN_RESOURCE_CALL
			ERROR_EXCEPTION_IN_RESOURCE_CALL
#	else
			0x172A
#	endif
		// The call into the resource DLL raised an unhandled exception.

	, CLUSTER_RHS_FAILED_INITIALIZATION =
#	if defined ERROR_CLUSTER_RHS_FAILED_INITIALIZATION
			ERROR_CLUSTER_RHS_FAILED_INITIALIZATION
#	else
			0x172B
#	endif
		// The RHS process failed to initialize.

	, CLUSTER_NOT_INSTALLED =
#	if defined ERROR_CLUSTER_NOT_INSTALLED
			ERROR_CLUSTER_NOT_INSTALLED
#	else
			0x172C
#	endif
		// The Failover Clustering feature is not installed on this node.

	, CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE =
#	if defined ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE
			ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE
#	else
			0x172D
#	endif
		// The resources must be online on the same node for this operation.

	, CLUSTER_MAX_NODES_IN_CLUSTER =
#	if defined ERROR_CLUSTER_MAX_NODES_IN_CLUSTER
			ERROR_CLUSTER_MAX_NODES_IN_CLUSTER
#	else
			0x172E
#	endif
		// A new node can not be added since this cluster is already at its maximum number of nodes.

	, CLUSTER_TOO_MANY_NODES =
#	if defined ERROR_CLUSTER_TOO_MANY_NODES
			ERROR_CLUSTER_TOO_MANY_NODES
#	else
			0x172F
#	endif
		// This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.

	, CLUSTER_OBJECT_ALREADY_USED =
#	if defined ERROR_CLUSTER_OBJECT_ALREADY_USED
			ERROR_CLUSTER_OBJECT_ALREADY_USED
#	else
			0x1730
#	endif
		// An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.

	, NONCORE_GROUPS_FOUND =
#	if defined ERROR_NONCORE_GROUPS_FOUND
			ERROR_NONCORE_GROUPS_FOUND
#	else
			0x1731
#	endif
		// This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.

	, FILE_SHARE_RESOURCE_CONFLICT =
#	if defined ERROR_FILE_SHARE_RESOURCE_CONFLICT
			ERROR_FILE_SHARE_RESOURCE_CONFLICT
#	else
			0x1732
#	endif
		// File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.

	, CLUSTER_EVICT_INVALID_REQUEST =
#	if defined ERROR_CLUSTER_EVICT_INVALID_REQUEST
			ERROR_CLUSTER_EVICT_INVALID_REQUEST
#	else
			0x1733
#	endif
		// Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown. If it is the last node in the cluster, destroy cluster command should be used.

	, CLUSTER_SINGLETON_RESOURCE =
#	if defined ERROR_CLUSTER_SINGLETON_RESOURCE
			ERROR_CLUSTER_SINGLETON_RESOURCE
#	else
			0x1734
#	endif
		// Only one instance of this resource type is allowed in the cluster.

	, CLUSTER_GROUP_SINGLETON_RESOURCE =
#	if defined ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE
			ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE
#	else
			0x1735
#	endif
		// Only one instance of this resource type is allowed per resource group.

	, CLUSTER_RESOURCE_PROVIDER_FAILED =
#	if defined ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED
			ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED
#	else
			0x1736
#	endif
		// The resource failed to come online due to the failure of one or more provider resources.

	, CLUSTER_RESOURCE_CONFIGURATION_ERROR =
#	if defined ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR
			ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR
#	else
			0x1737
#	endif
		// The resource has indicated that it cannot come online on any node.

	, CLUSTER_GROUP_BUSY =
#	if defined ERROR_CLUSTER_GROUP_BUSY
			ERROR_CLUSTER_GROUP_BUSY
#	else
			0x1738
#	endif
		// The current operation cannot be performed on this group at this time.

	, CLUSTER_NOT_SHARED_VOLUME =
#	if defined ERROR_CLUSTER_NOT_SHARED_VOLUME
			ERROR_CLUSTER_NOT_SHARED_VOLUME
#	else
			0x1739
#	endif
		// The directory or file is not located on a cluster shared volume.

	, CLUSTER_INVALID_SECURITY_DESCRIPTOR =
#	if defined ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR
			ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR
#	else
			0x173A
#	endif
		// The Security Descriptor does not meet the requirements for a cluster.

	, CLUSTER_SHARED_VOLUMES_IN_USE =
#	if defined ERROR_CLUSTER_SHARED_VOLUMES_IN_USE
			ERROR_CLUSTER_SHARED_VOLUMES_IN_USE
#	else
			0x173B
#	endif
		// There is one or more shared volumes resources configured in the cluster. Those resources must be moved to available storage in order for operation to succeed.

	, CLUSTER_USE_SHARED_VOLUMES_API =
#	if defined ERROR_CLUSTER_USE_SHARED_VOLUMES_API
			ERROR_CLUSTER_USE_SHARED_VOLUMES_API
#	else
			0x173C
#	endif
		// This group or resource cannot be directly manipulated. Use shared volume APIs to perform desired operation.

	, CLUSTER_BACKUP_IN_PROGRESS =
#	if defined ERROR_CLUSTER_BACKUP_IN_PROGRESS
			ERROR_CLUSTER_BACKUP_IN_PROGRESS
#	else
			0x173D
#	endif
		// Back up is in progress. Please wait for backup completion before trying this operation again.

	, NON_CSV_PATH =
#	if defined ERROR_NON_CSV_PATH
			ERROR_NON_CSV_PATH
#	else
			0x173E
#	endif
		// The path does not belong to a cluster shared volume.

	, CSV_VOLUME_NOT_LOCAL =
#	if defined ERROR_CSV_VOLUME_NOT_LOCAL
			ERROR_CSV_VOLUME_NOT_LOCAL
#	else
			0x173F
#	endif
		// The cluster shared volume is not locally mounted on this node.

	, CLUSTER_WATCHDOG_TERMINATING =
#	if defined ERROR_CLUSTER_WATCHDOG_TERMINATING
			ERROR_CLUSTER_WATCHDOG_TERMINATING
#	else
			0x1740
#	endif
		// The cluster watchdog is terminating.

	, CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES =
#	if defined ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES
			ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES
#	else
			0x1741
#	endif
		// A resource vetoed a move between two nodes because they are incompatible.

	, CLUSTER_INVALID_NODE_WEIGHT =
#	if defined ERROR_CLUSTER_INVALID_NODE_WEIGHT
			ERROR_CLUSTER_INVALID_NODE_WEIGHT
#	else
			0x1742
#	endif
		// The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.

	, CLUSTER_RESOURCE_VETOED_CALL =
#	if defined ERROR_CLUSTER_RESOURCE_VETOED_CALL
			ERROR_CLUSTER_RESOURCE_VETOED_CALL
#	else
			0x1743
#	endif
		// The resource vetoed the call.

	, RESMON_SYSTEM_RESOURCES_LACKING =
#	if defined ERROR_RESMON_SYSTEM_RESOURCES_LACKING
			ERROR_RESMON_SYSTEM_RESOURCES_LACKING
#	else
			0x1744
#	endif
		// Resource could not start or run because it could not reserve sufficient system resources.

	, CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION =
#	if defined ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION
			ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION
#	else
			0x1745
#	endif
		// A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.

	, CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE =
#	if defined ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE
			ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE
#	else
			0x1746
#	endif
		// A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.

	, CLUSTER_GROUP_QUEUED =
#	if defined ERROR_CLUSTER_GROUP_QUEUED
			ERROR_CLUSTER_GROUP_QUEUED
#	else
			0x1747
#	endif
		// The requested operation can not be completed because the group is queued for an operation.

	, CLUSTER_RESOURCE_LOCKED_STATUS =
#	if defined ERROR_CLUSTER_RESOURCE_LOCKED_STATUS
			ERROR_CLUSTER_RESOURCE_LOCKED_STATUS
#	else
			0x1748
#	endif
		// The requested operation can not be completed because a resource has locked status.

	, CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED =
#	if defined ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED
			ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED
#	else
			0x1749
#	endif
		// The resource cannot move to another node because a cluster shared volume vetoed the operation.

	, CLUSTER_NODE_DRAIN_IN_PROGRESS =
#	if defined ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS
			ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS
#	else
			0x174A
#	endif
		// A node drain is already in progress. This value was also named ERROR_CLUSTER_NODE_EVACUATION_IN_PROGRESS

	, CLUSTER_DISK_NOT_CONNECTED =
#	if defined ERROR_CLUSTER_DISK_NOT_CONNECTED
			ERROR_CLUSTER_DISK_NOT_CONNECTED
#	else
			0x174B
#	endif
		// Clustered storage is not connected to the node.

	, DISK_NOT_CSV_CAPABLE =
#	if defined ERROR_DISK_NOT_CSV_CAPABLE
			ERROR_DISK_NOT_CSV_CAPABLE
#	else
			0x174C
#	endif
		// The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS.

	, RESOURCE_NOT_IN_AVAILABLE_STORAGE =
#	if defined ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE
			ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE
#	else
			0x174D
#	endif
		// The resource must be part of the Available Storage group to complete this action.

	, CLUSTER_SHARED_VOLUME_REDIRECTED =
#	if defined ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED
			ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED
#	else
			0x174E
#	endif
		// CSVFS failed operation as volume is in redirected mode.

	, CLUSTER_SHARED_VOLUME_NOT_REDIRECTED =
#	if defined ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED
			ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED
#	else
			0x174F
#	endif
		// CSVFS failed operation as volume is not in redirected mode.

	, CLUSTER_CANNOT_RETURN_PROPERTIES =
#	if defined ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES
			ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES
#	else
			0x1750
#	endif
		// Cluster properties cannot be returned at this time.

	, CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES =
#	if defined ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES
			ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES
#	else
			0x1751
#	endif
		// The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.

	, CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE =
#	if defined ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE
			ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE
#	else
			0x1752
#	endif
		// The operation cannot be completed because the resource is in maintenance mode.

	, CLUSTER_AFFINITY_CONFLICT =
#	if defined ERROR_CLUSTER_AFFINITY_CONFLICT
			ERROR_CLUSTER_AFFINITY_CONFLICT
#	else
			0x1753
#	endif
		// The operation cannot be completed because of cluster affinity conflicts.

	, CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE =
#	if defined ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE
			ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE
#	else
			0x1754
#	endif
		// The operation cannot be completed because the resource is a replica virtual machine.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString5(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::WINS_INTERNAL:
			RETURN_STATIC_STRING(
					"WINS encountered an error while processing the command"
			);
		case SystemCode::CAN_NOT_DEL_LOCAL_WINS:
			RETURN_STATIC_STRING(
					"The local WINS cannot be deleted"
			);
		case SystemCode::STATIC_INIT:
			RETURN_STATIC_STRING(
					"The importation from the file failed"
			);
		case SystemCode::INC_BACKUP:
			RETURN_STATIC_STRING(
					"The backup failed. Was a full backup done before"
			);
		case SystemCode::FULL_BACKUP:
			RETURN_STATIC_STRING(
					"The backup failed. Check the directory to which you are backing the database"
			);
		case SystemCode::REC_NON_EXISTENT:
			RETURN_STATIC_STRING(
					"The name does not exist in the WINS database"
			);
		case SystemCode::RPL_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"Replication with a nonconfigured partner is not allowed"
			);
		case SystemCode::PEERDIST_CONTENTINFO_VERSION_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"The version of the supplied content information is not supported"
			);
		case SystemCode::PEERDIST_CANNOT_PARSE_CONTENTINFO:
			RETURN_STATIC_STRING(
					"The supplied content information is malformed"
			);
		case SystemCode::PEERDIST_MISSING_DATA:
			RETURN_STATIC_STRING(
					"The requested data cannot be found in local or peer caches"
			);
		case SystemCode::PEERDIST_NO_MORE:
			RETURN_STATIC_STRING(
					"No more data is available or required"
			);
		case SystemCode::PEERDIST_NOT_INITIALIZED:
			RETURN_STATIC_STRING(
					"The supplied object has not been initialized"
			);
		case SystemCode::PEERDIST_ALREADY_INITIALIZED:
			RETURN_STATIC_STRING(
					"The supplied object has already been initialized"
			);
		case SystemCode::PEERDIST_SHUTDOWN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A shutdown operation is already in progress"
			);
		case SystemCode::PEERDIST_INVALIDATED:
			RETURN_STATIC_STRING(
					"The supplied object has already been invalidated"
			);
		case SystemCode::PEERDIST_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"An element already exists and was not replaced"
			);
		case SystemCode::PEERDIST_OPERATION_NOTFOUND:
			RETURN_STATIC_STRING(
					"Can not cancel the requested operation as it has already been completed"
			);
		case SystemCode::PEERDIST_ALREADY_COMPLETED:
			RETURN_STATIC_STRING(
					"Can not perform the reqested operation because it has already been carried out"
			);
		case SystemCode::PEERDIST_OUT_OF_BOUNDS:
			RETURN_STATIC_STRING(
					"An operation accessed data beyond the bounds of valid data"
			);
		case SystemCode::PEERDIST_VERSION_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"The requested version is not supported"
			);
		case SystemCode::PEERDIST_INVALID_CONFIGURATION:
			RETURN_STATIC_STRING(
					"A configuration value is invalid"
			);
		case SystemCode::PEERDIST_NOT_LICENSED:
			RETURN_STATIC_STRING(
					"The SKU is not licensed"
			);
		case SystemCode::PEERDIST_SERVICE_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"PeerDist Service is still initializing and will be available shortly"
			);
		case SystemCode::PEERDIST_TRUST_FAILURE:
			RETURN_STATIC_STRING(
					"Communication with one or more computers will be temporarily blocked due to recent errors"
			);
		case SystemCode::DHCP_ADDRESS_CONFLICT:
			RETURN_STATIC_STRING(
					"The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address"
			);
		case SystemCode::WMI_GUID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The GUID passed was not recognized as valid by a WMI data provider"
			);
		case SystemCode::WMI_INSTANCE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The instance name passed was not recognized as valid by a WMI data provider"
			);
		case SystemCode::WMI_ITEMID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The data item ID passed was not recognized as valid by a WMI data provider"
			);
		case SystemCode::WMI_TRY_AGAIN:
			RETURN_STATIC_STRING(
					"The WMI request could not be completed and should be retried"
			);
		case SystemCode::WMI_DP_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The WMI data provider could not be located"
			);
		case SystemCode::WMI_UNRESOLVED_INSTANCE_REF:
			RETURN_STATIC_STRING(
					"The WMI data provider references an instance set that has not been registered"
			);
		case SystemCode::WMI_ALREADY_ENABLED:
			RETURN_STATIC_STRING(
					"The WMI data block or event notification has already been enabled"
			);
		case SystemCode::WMI_GUID_DISCONNECTED:
			RETURN_STATIC_STRING(
					"The WMI data block is no longer available"
			);
		case SystemCode::WMI_SERVER_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"The WMI data service is not available"
			);
		case SystemCode::WMI_DP_FAILED:
			RETURN_STATIC_STRING(
					"The WMI data provider failed to carry out the request"
			);
		case SystemCode::WMI_INVALID_MOF:
			RETURN_STATIC_STRING(
					"The WMI MOF information is not valid"
			);
		case SystemCode::WMI_INVALID_REGINFO:
			RETURN_STATIC_STRING(
					"The WMI registration information is not valid"
			);
		case SystemCode::WMI_ALREADY_DISABLED:
			RETURN_STATIC_STRING(
					"The WMI data block or event notification has already been disabled"
			);
		case SystemCode::WMI_READ_ONLY:
			RETURN_STATIC_STRING(
					"The WMI data item or data block is read only"
			);
		case SystemCode::WMI_SET_FAILURE:
			RETURN_STATIC_STRING(
					"The WMI data item or data block could not be changed"
			);
		case SystemCode::NOT_APPCONTAINER:
			RETURN_STATIC_STRING(
					"This operation is only valid in the context of an app container"
			);
		case SystemCode::APPCONTAINER_REQUIRED:
			RETURN_STATIC_STRING(
					"This application can only run in the context of an app container"
			);
		case SystemCode::NOT_SUPPORTED_IN_APPCONTAINER:
			RETURN_STATIC_STRING(
					"This functionality is not supported in the context of an app container"
			);
		case SystemCode::INVALID_PACKAGE_SID_LENGTH:
			RETURN_STATIC_STRING(
					"The length of the SID supplied is not a valid length for app container SIDs"
			);
		case SystemCode::INVALID_MEDIA:
			RETURN_STATIC_STRING(
					"The media identifier does not represent a valid medium"
			);
		case SystemCode::INVALID_LIBRARY:
			RETURN_STATIC_STRING(
					"The library identifier does not represent a valid library"
			);
		case SystemCode::INVALID_MEDIA_POOL:
			RETURN_STATIC_STRING(
					"The media pool identifier does not represent a valid media pool"
			);
		case SystemCode::DRIVE_MEDIA_MISMATCH:
			RETURN_STATIC_STRING(
					"The drive and medium are not compatible or exist in different libraries"
			);
		case SystemCode::MEDIA_OFFLINE:
			RETURN_STATIC_STRING(
					"The medium currently exists in an offline library and must be online to perform this operation"
			);
		case SystemCode::LIBRARY_OFFLINE:
			RETURN_STATIC_STRING(
					"The operation cannot be performed on an offline library"
			);
		case SystemCode::EMPTY:
			RETURN_STATIC_STRING(
					"The library, drive, or media pool is empty"
			);
		case SystemCode::NOT_EMPTY:
			RETURN_STATIC_STRING(
					"The library, drive, or media pool must be empty to perform this operation"
			);
		case SystemCode::MEDIA_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"No media is currently available in this media pool or library"
			);
		case SystemCode::RESOURCE_DISABLED:
			RETURN_STATIC_STRING(
					"A resource required for this operation is disabled"
			);
		case SystemCode::INVALID_CLEANER:
			RETURN_STATIC_STRING(
					"The media identifier does not represent a valid cleaner"
			);
		case SystemCode::UNABLE_TO_CLEAN:
			RETURN_STATIC_STRING(
					"The drive cannot be cleaned or does not support cleaning"
			);
		case SystemCode::OBJECT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The object identifier does not represent a valid object"
			);
		case SystemCode::DATABASE_FAILURE:
			RETURN_STATIC_STRING(
					"Unable to read from or write to the database"
			);
		case SystemCode::DATABASE_FULL:
			RETURN_STATIC_STRING(
					"The database is full"
			);
		case SystemCode::MEDIA_INCOMPATIBLE:
			RETURN_STATIC_STRING(
					"The medium is not compatible with the device or media pool"
			);
		case SystemCode::RESOURCE_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"The resource required for this operation does not exist"
			);
		case SystemCode::INVALID_OPERATION:
			RETURN_STATIC_STRING(
					"The operation identifier is not valid"
			);
		case SystemCode::MEDIA_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The media is not mounted or ready for use"
			);
		case SystemCode::DEVICE_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The device is not ready for use"
			);
		case SystemCode::REQUEST_REFUSED:
			RETURN_STATIC_STRING(
					"The operator or administrator has refused the request"
			);
		case SystemCode::INVALID_DRIVE_OBJECT:
			RETURN_STATIC_STRING(
					"The drive identifier does not represent a valid drive"
			);
		case SystemCode::LIBRARY_FULL:
			RETURN_STATIC_STRING(
					"Library is full. No slot is available for use"
			);
		case SystemCode::MEDIUM_NOT_ACCESSIBLE:
			RETURN_STATIC_STRING(
					"The transport cannot access the medium"
			);
		case SystemCode::UNABLE_TO_LOAD_MEDIUM:
			RETURN_STATIC_STRING(
					"Unable to load the medium into the drive"
			);
		case SystemCode::UNABLE_TO_INVENTORY_DRIVE:
			RETURN_STATIC_STRING(
					"Unable to retrieve the drive status"
			);
		case SystemCode::UNABLE_TO_INVENTORY_SLOT:
			RETURN_STATIC_STRING(
					"Unable to retrieve the slot status"
			);
		case SystemCode::UNABLE_TO_INVENTORY_TRANSPORT:
			RETURN_STATIC_STRING(
					"Unable to retrieve status about the transport"
			);
		case SystemCode::TRANSPORT_FULL:
			RETURN_STATIC_STRING(
					"Cannot use the transport because it is already in use"
			);
		case SystemCode::CONTROLLING_IEPORT:
			RETURN_STATIC_STRING(
					"Unable to open or close the inject/eject port"
			);
		case SystemCode::UNABLE_TO_EJECT_MOUNTED_MEDIA:
			RETURN_STATIC_STRING(
					"Unable to eject the medium because it is in a drive"
			);
		case SystemCode::CLEANER_SLOT_SET:
			RETURN_STATIC_STRING(
					"A cleaner slot is already reserved"
			);
		case SystemCode::CLEANER_SLOT_NOT_SET:
			RETURN_STATIC_STRING(
					"A cleaner slot is not reserved"
			);
		case SystemCode::CLEANER_CARTRIDGE_SPENT:
			RETURN_STATIC_STRING(
					"The cleaner cartridge has performed the maximum number of drive cleanings"
			);
		case SystemCode::UNEXPECTED_OMID:
			RETURN_STATIC_STRING(
					"Unexpected on-medium identifier"
			);
		case SystemCode::CANT_DELETE_LAST_ITEM:
			RETURN_STATIC_STRING(
					"The last remaining item in this group or resource cannot be deleted"
			);
		case SystemCode::MESSAGE_EXCEEDS_MAX_SIZE:
			RETURN_STATIC_STRING(
					"The message provided exceeds the maximum size allowed for this parameter"
			);
		case SystemCode::VOLUME_CONTAINS_SYS_FILES:
			RETURN_STATIC_STRING(
					"The volume contains system or paging files"
			);
		case SystemCode::INDIGENOUS_TYPE:
			RETURN_STATIC_STRING(
					"The media type cannot be removed from this library since at least one drive in the library reports it can support this media type"
			);
		case SystemCode::NO_SUPPORTING_DRIVES:
			RETURN_STATIC_STRING(
					"This offline media cannot be mounted on this system since no enabled drives are present which can be used"
			);
		case SystemCode::CLEANER_CARTRIDGE_INSTALLED:
			RETURN_STATIC_STRING(
					"A cleaner cartridge is present in the tape library"
			);
		case SystemCode::IEPORT_FULL:
			RETURN_STATIC_STRING(
					"Cannot use the inject/eject port because it is not empty"
			);
		case SystemCode::FILE_OFFLINE:
			RETURN_STATIC_STRING(
					"This file is currently not available for use on this computer"
			);
		case SystemCode::REMOTE_STORAGE_NOT_ACTIVE:
			RETURN_STATIC_STRING(
					"The remote storage service is not operational at this time"
			);
		case SystemCode::REMOTE_STORAGE_MEDIA_ERROR:
			RETURN_STATIC_STRING(
					"The remote storage service encountered a media error"
			);
		case SystemCode::NOT_A_REPARSE_POINT:
			RETURN_STATIC_STRING(
					"The file or directory is not a reparse point"
			);
		case SystemCode::REPARSE_ATTRIBUTE_CONFLICT:
			RETURN_STATIC_STRING(
					"The reparse point attribute cannot be set because it conflicts with an existing attribute"
			);
		case SystemCode::INVALID_REPARSE_DATA:
			RETURN_STATIC_STRING(
					"The data present in the reparse point buffer is invalid"
			);
		case SystemCode::REPARSE_TAG_INVALID:
			RETURN_STATIC_STRING(
					"The tag present in the reparse point buffer is invalid"
			);
		case SystemCode::REPARSE_TAG_MISMATCH:
			RETURN_STATIC_STRING(
					"There is a mismatch between the tag specified in the request and the tag present in the reparse point"
			);
		case SystemCode::APP_DATA_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Fast Cache data not found"
			);
		case SystemCode::APP_DATA_EXPIRED:
			RETURN_STATIC_STRING(
					"Fast Cache data expired"
			);
		case SystemCode::APP_DATA_CORRUPT:
			RETURN_STATIC_STRING(
					"Fast Cache data corrupt"
			);
		case SystemCode::APP_DATA_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"Fast Cache data has exceeded its max size and cannot be updated"
			);
		case SystemCode::APP_DATA_REBOOT_REQUIRED:
			RETURN_STATIC_STRING(
					"Fast Cache has been ReArmed and requires a reboot until it can be updated"
			);
		case SystemCode::SECUREBOOT_ROLLBACK_DETECTED:
			RETURN_STATIC_STRING(
					"Secure Boot detected that rollback of protected data has been attempted"
			);
		case SystemCode::SECUREBOOT_POLICY_VIOLATION:
			RETURN_STATIC_STRING(
					"The value is protected by Secure Boot policy and cannot be modified or deleted"
			);
		case SystemCode::SECUREBOOT_INVALID_POLICY:
			RETURN_STATIC_STRING(
					"The Secure Boot policy is invalid"
			);
		case SystemCode::SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"A new Secure Boot policy did not contain the current publisher on its update list"
			);
		case SystemCode::SECUREBOOT_POLICY_NOT_SIGNED:
			RETURN_STATIC_STRING(
					"The Secure Boot policy is either not signed or is signed by a non-trusted signer"
			);
		case SystemCode::SECUREBOOT_NOT_ENABLED:
			RETURN_STATIC_STRING(
					"Secure Boot is not enabled on this machine"
			);
		case SystemCode::SECUREBOOT_FILE_REPLACED:
			RETURN_STATIC_STRING(
					"Secure Boot requires that certain files and drivers are not replaced by other files or drivers"
			);
		case SystemCode::OFFLOAD_READ_FLT_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The copy offload read operation is not supported by a filter"
			);
		case SystemCode::OFFLOAD_WRITE_FLT_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The copy offload write operation is not supported by a filter"
			);
		case SystemCode::OFFLOAD_READ_FILE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The copy offload read operation is not supported for the file"
			);
		case SystemCode::OFFLOAD_WRITE_FILE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The copy offload write operation is not supported for the file"
			);
		case SystemCode::VOLUME_NOT_SIS_ENABLED:
			RETURN_STATIC_STRING(
					"Single Instance Storage is not available on this volume"
			);
		case SystemCode::DEPENDENT_RESOURCE_EXISTS:
			RETURN_STATIC_STRING(
					"The operation cannot be completed because other resources are dependent on this resource"
			);
		case SystemCode::DEPENDENCY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster resource dependency cannot be found"
			);
		case SystemCode::DEPENDENCY_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The cluster resource cannot be made dependent on the specified resource because it is already dependent"
			);
		case SystemCode::RESOURCE_NOT_ONLINE:
			RETURN_STATIC_STRING(
					"The cluster resource is not online"
			);
		case SystemCode::HOST_NODE_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"A cluster node is not available for this operation"
			);
		case SystemCode::RESOURCE_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The cluster resource is not available"
			);
		case SystemCode::RESOURCE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster resource could not be found"
			);
		case SystemCode::SHUTDOWN_CLUSTER:
			RETURN_STATIC_STRING(
					"The cluster is being shut down"
			);
		case SystemCode::CANT_EVICT_ACTIVE_NODE:
			RETURN_STATIC_STRING(
					"A cluster node cannot be evicted from the cluster unless the node is down or it is the last node"
			);
		case SystemCode::OBJECT_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The object already exists"
			);
		case SystemCode::OBJECT_IN_LIST:
			RETURN_STATIC_STRING(
					"The object is already in the list"
			);
		case SystemCode::GROUP_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The cluster group is not available for any new requests"
			);
		case SystemCode::GROUP_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster group could not be found"
			);
		case SystemCode::GROUP_NOT_ONLINE:
			RETURN_STATIC_STRING(
					"The operation could not be completed because the cluster group is not online"
			);
		case SystemCode::HOST_NODE_NOT_RESOURCE_OWNER:
			RETURN_STATIC_STRING(
					"The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource"
			);
		case SystemCode::HOST_NODE_NOT_GROUP_OWNER:
			RETURN_STATIC_STRING(
					"The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group"
			);
		case SystemCode::RESMON_CREATE_FAILED:
			RETURN_STATIC_STRING(
					"The cluster resource could not be created in the specified resource monitor"
			);
		case SystemCode::RESMON_ONLINE_FAILED:
			RETURN_STATIC_STRING(
					"The cluster resource could not be brought online by the resource monitor"
			);
		case SystemCode::RESOURCE_ONLINE:
			RETURN_STATIC_STRING(
					"The operation could not be completed because the cluster resource is online"
			);
		case SystemCode::QUORUM_RESOURCE:
			RETURN_STATIC_STRING(
					"The cluster resource could not be deleted or brought offline because it is the quorum resource"
			);
		case SystemCode::NOT_QUORUM_CAPABLE:
			RETURN_STATIC_STRING(
					"The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource"
			);
		case SystemCode::CLUSTER_SHUTTING_DOWN:
			RETURN_STATIC_STRING(
					"The cluster software is shutting down"
			);
		case SystemCode::INVALID_STATE:
			RETURN_STATIC_STRING(
					"The group or resource is not in the correct state to perform the requested operation"
			);
		case SystemCode::RESOURCE_PROPERTIES_STORED:
			RETURN_STATIC_STRING(
					"The properties were stored but not all changes will take effect until the next time the resource is brought online"
			);
		case SystemCode::NOT_QUORUM_CLASS:
			RETURN_STATIC_STRING(
					"The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class"
			);
		case SystemCode::CORE_RESOURCE:
			RETURN_STATIC_STRING(
					"The cluster resource could not be deleted since it is a core resource"
			);
		case SystemCode::QUORUM_RESOURCE_ONLINE_FAILED:
			RETURN_STATIC_STRING(
					"The quorum resource failed to come online"
			);
		case SystemCode::QUORUMLOG_OPEN_FAILED:
			RETURN_STATIC_STRING(
					"The quorum log could not be created or mounted successfully"
			);
		case SystemCode::CLUSTERLOG_CORRUPT:
			RETURN_STATIC_STRING(
					"The cluster log is corrupt"
			);
		case SystemCode::CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE:
			RETURN_STATIC_STRING(
					"The record could not be written to the cluster log since it exceeds the maximum size"
			);
		case SystemCode::CLUSTERLOG_EXCEEDS_MAXSIZE:
			RETURN_STATIC_STRING(
					"The cluster log exceeds its maximum size"
			);
		case SystemCode::CLUSTERLOG_CHKPOINT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"No checkpoint record was found in the cluster log"
			);
		case SystemCode::CLUSTERLOG_NOT_ENOUGH_SPACE:
			RETURN_STATIC_STRING(
					"The minimum required disk space needed for logging is not available"
			);
		case SystemCode::QUORUM_OWNER_ALIVE:
			RETURN_STATIC_STRING(
					"The cluster node failed to take control of the quorum resource because the resource is owned by another active node"
			);
		case SystemCode::NETWORK_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"A cluster network is not available for this operation"
			);
		case SystemCode::NODE_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"A cluster node is not available for this operation"
			);
		case SystemCode::ALL_NODES_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"All cluster nodes must be running to perform this operation"
			);
		case SystemCode::RESOURCE_FAILED:
			RETURN_STATIC_STRING(
					"A cluster resource failed"
			);
		case SystemCode::CLUSTER_INVALID_NODE:
			RETURN_STATIC_STRING(
					"The cluster node is not valid"
			);
		case SystemCode::CLUSTER_NODE_EXISTS:
			RETURN_STATIC_STRING(
					"The cluster node already exists"
			);
		case SystemCode::CLUSTER_JOIN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A node is in the process of joining the cluster"
			);
		case SystemCode::CLUSTER_NODE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster node was not found"
			);
		case SystemCode::CLUSTER_LOCAL_NODE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster local node information was not found"
			);
		case SystemCode::CLUSTER_NETWORK_EXISTS:
			RETURN_STATIC_STRING(
					"The cluster network already exists"
			);
		case SystemCode::CLUSTER_NETWORK_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster network was not found"
			);
		case SystemCode::CLUSTER_NETINTERFACE_EXISTS:
			RETURN_STATIC_STRING(
					"The cluster network interface already exists"
			);
		case SystemCode::CLUSTER_NETINTERFACE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The cluster network interface was not found"
			);
		case SystemCode::CLUSTER_INVALID_REQUEST:
			RETURN_STATIC_STRING(
					"The cluster request is not valid for this object"
			);
		case SystemCode::CLUSTER_INVALID_NETWORK_PROVIDER:
			RETURN_STATIC_STRING(
					"The cluster network provider is not valid"
			);
		case SystemCode::CLUSTER_NODE_DOWN:
			RETURN_STATIC_STRING(
					"The cluster node is down"
			);
		case SystemCode::CLUSTER_NODE_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The cluster node is not reachable"
			);
		case SystemCode::CLUSTER_NODE_NOT_MEMBER:
			RETURN_STATIC_STRING(
					"The cluster node is not a member of the cluster"
			);
		case SystemCode::CLUSTER_JOIN_NOT_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A cluster join operation is not in progress"
			);
		case SystemCode::CLUSTER_INVALID_NETWORK:
			RETURN_STATIC_STRING(
					"The cluster network is not valid"
			);
		case SystemCode::CLUSTER_NODE_UP:
			RETURN_STATIC_STRING(
					"The cluster node is up"
			);
		case SystemCode::CLUSTER_IPADDR_IN_USE:
			RETURN_STATIC_STRING(
					"The cluster IP address is already in use"
			);
		case SystemCode::CLUSTER_NODE_NOT_PAUSED:
			RETURN_STATIC_STRING(
					"The cluster node is not paused"
			);
		case SystemCode::CLUSTER_NO_SECURITY_CONTEXT:
			RETURN_STATIC_STRING(
					"No cluster security context is available"
			);
		case SystemCode::CLUSTER_NETWORK_NOT_INTERNAL:
			RETURN_STATIC_STRING(
					"The cluster network is not configured for internal cluster communication"
			);
		case SystemCode::CLUSTER_NODE_ALREADY_UP:
			RETURN_STATIC_STRING(
					"The cluster node is already up"
			);
		case SystemCode::CLUSTER_NODE_ALREADY_DOWN:
			RETURN_STATIC_STRING(
					"The cluster node is already down"
			);
		case SystemCode::CLUSTER_NETWORK_ALREADY_ONLINE:
			RETURN_STATIC_STRING(
					"The cluster network is already online"
			);
		case SystemCode::CLUSTER_NETWORK_ALREADY_OFFLINE:
			RETURN_STATIC_STRING(
					"The cluster network is already offline"
			);
		case SystemCode::CLUSTER_NODE_ALREADY_MEMBER:
			RETURN_STATIC_STRING(
					"The cluster node is already a member of the cluster"
			);
		case SystemCode::CLUSTER_LAST_INTERNAL_NETWORK:
			RETURN_STATIC_STRING(
					"The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network"
			);
		case SystemCode::CLUSTER_NETWORK_HAS_DEPENDENTS:
			RETURN_STATIC_STRING(
					"One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network"
			);
		case SystemCode::INVALID_OPERATION_ON_QUORUM:
			RETURN_STATIC_STRING(
					"This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list"
			);
		case SystemCode::DEPENDENCY_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"The cluster quorum resource is not allowed to have any dependencies"
			);
		case SystemCode::CLUSTER_NODE_PAUSED:
			RETURN_STATIC_STRING(
					"The cluster node is paused"
			);
		case SystemCode::NODE_CANT_HOST_RESOURCE:
			RETURN_STATIC_STRING(
					"The cluster resource cannot be brought online. The owner node cannot run this resource"
			);
		case SystemCode::CLUSTER_NODE_NOT_READY:
			RETURN_STATIC_STRING(
					"The cluster node is not ready to perform the requested operation"
			);
		case SystemCode::CLUSTER_NODE_SHUTTING_DOWN:
			RETURN_STATIC_STRING(
					"The cluster node is shutting down"
			);
		case SystemCode::CLUSTER_JOIN_ABORTED:
			RETURN_STATIC_STRING(
					"The cluster join operation was aborted"
			);
		case SystemCode::CLUSTER_INCOMPATIBLE_VERSIONS:
			RETURN_STATIC_STRING(
					"The cluster join operation failed due to incompatible software versions between the joining node and its sponsor"
			);
		case SystemCode::CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED:
			RETURN_STATIC_STRING(
					"This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor"
			);
		case SystemCode::CLUSTER_SYSTEM_CONFIG_CHANGED:
			RETURN_STATIC_STRING(
					"The system configuration changed during the cluster join or form operation. The join or form operation was aborted"
			);
		case SystemCode::CLUSTER_RESOURCE_TYPE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified resource type was not found"
			);
		case SystemCode::CLUSTER_RESTYPE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node"
			);
		case SystemCode::CLUSTER_RESNAME_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL"
			);
		case SystemCode::CLUSTER_NO_RPC_PACKAGES_REGISTERED:
			RETURN_STATIC_STRING(
					"No authentication package could be registered with the RPC server"
			);
		case SystemCode::CLUSTER_OWNER_NOT_IN_PREFLIST:
			RETURN_STATIC_STRING(
					"You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group"
			);
		case SystemCode::CLUSTER_DATABASE_SEQMISMATCH:
			RETURN_STATIC_STRING(
					"The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join"
			);
		case SystemCode::RESMON_INVALID_STATE:
			RETURN_STATIC_STRING(
					"The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state"
			);
		case SystemCode::CLUSTER_GUM_NOT_LOCKER:
			RETURN_STATIC_STRING(
					"A non locker code got a request to reserve the lock for making global updates"
			);
		case SystemCode::QUORUM_DISK_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The quorum disk could not be located by the cluster service"
			);
		case SystemCode::DATABASE_BACKUP_CORRUPT:
			RETURN_STATIC_STRING(
					"The backed up cluster database is possibly corrupt"
			);
		case SystemCode::CLUSTER_NODE_ALREADY_HAS_DFS_ROOT:
			RETURN_STATIC_STRING(
					"A DFS root already exists in this cluster node"
			);
		case SystemCode::RESOURCE_PROPERTY_UNCHANGEABLE:
			RETURN_STATIC_STRING(
					"An attempt to modify a resource property failed because it conflicts with another existing property"
			);
		case SystemCode::CLUSTER_MEMBERSHIP_INVALID_STATE:
			RETURN_STATIC_STRING(
					"An operation was attempted that is incompatible with the current membership state of the node"
			);
		case SystemCode::CLUSTER_QUORUMLOG_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The quorum resource does not contain the quorum log"
			);
		case SystemCode::CLUSTER_MEMBERSHIP_HALT:
			RETURN_STATIC_STRING(
					"The membership engine requested shutdown of the cluster service on this node"
			);
		case SystemCode::CLUSTER_INSTANCE_ID_MISMATCH:
			RETURN_STATIC_STRING(
					"The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node"
			);
		case SystemCode::CLUSTER_NETWORK_NOT_FOUND_FOR_IP:
			RETURN_STATIC_STRING(
					"A matching cluster network for the specified IP address could not be found"
			);
		case SystemCode::CLUSTER_PROPERTY_DATA_TYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"The actual data type of the property did not match the expected data type of the property"
			);
		case SystemCode::CLUSTER_EVICT_WITHOUT_CLEANUP:
			RETURN_STATIC_STRING(
					"The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer"
			);
		case SystemCode::CLUSTER_PARAMETER_MISMATCH:
			RETURN_STATIC_STRING(
					"Two or more parameter values specified for a resource's properties are in conflict"
			);
		case SystemCode::NODE_CANNOT_BE_CLUSTERED:
			RETURN_STATIC_STRING(
					"This computer cannot be made a member of a cluster"
			);
		case SystemCode::CLUSTER_WRONG_OS_VERSION:
			RETURN_STATIC_STRING(
					"This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed"
			);
		case SystemCode::CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME:
			RETURN_STATIC_STRING(
					"A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster"
			);
		case SystemCode::CLUSCFG_ALREADY_COMMITTED:
			RETURN_STATIC_STRING(
					"The cluster configuration action has already been committed"
			);
		case SystemCode::CLUSCFG_ROLLBACK_FAILED:
			RETURN_STATIC_STRING(
					"The cluster configuration action could not be rolled back"
			);
		case SystemCode::CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT:
			RETURN_STATIC_STRING(
					"The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node"
			);
		case SystemCode::CLUSTER_OLD_VERSION:
			RETURN_STATIC_STRING(
					"One or more nodes in the cluster are running a version of Windows that does not support this operation"
			);
		case SystemCode::CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME:
			RETURN_STATIC_STRING(
					"The name of the corresponding computer account doesn't match the Network Name for this resource"
			);
		case SystemCode::CLUSTER_NO_NET_ADAPTERS:
			RETURN_STATIC_STRING(
					"No network adapters are available"
			);
		case SystemCode::CLUSTER_POISONED:
			RETURN_STATIC_STRING(
					"The cluster node has been poisoned"
			);
		case SystemCode::CLUSTER_GROUP_MOVING:
			RETURN_STATIC_STRING(
					"The group is unable to accept the request since it is moving to another node"
			);
		case SystemCode::CLUSTER_RESOURCE_TYPE_BUSY:
			RETURN_STATIC_STRING(
					"The resource type cannot accept the request since is too busy performing another operation"
			);
		case SystemCode::RESOURCE_CALL_TIMED_OUT:
			RETURN_STATIC_STRING(
					"The call to the cluster resource DLL timed out"
			);
		case SystemCode::INVALID_CLUSTER_IPV6_ADDRESS:
			RETURN_STATIC_STRING(
					"The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted"
			);
		case SystemCode::CLUSTER_INTERNAL_INVALID_FUNCTION:
			RETURN_STATIC_STRING(
					"An internal cluster error occurred. A call to an invalid function was attempted"
			);
		case SystemCode::CLUSTER_PARAMETER_OUT_OF_BOUNDS:
			RETURN_STATIC_STRING(
					"A parameter value is out of acceptable range"
			);
		case SystemCode::CLUSTER_PARTIAL_SEND:
			RETURN_STATIC_STRING(
					"A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required"
			);
		case SystemCode::CLUSTER_REGISTRY_INVALID_FUNCTION:
			RETURN_STATIC_STRING(
					"An invalid cluster registry operation was attempted"
			);
		case SystemCode::CLUSTER_INVALID_STRING_TERMINATION:
			RETURN_STATIC_STRING(
					"An input string of characters is not properly terminated"
			);
		case SystemCode::CLUSTER_INVALID_STRING_FORMAT:
			RETURN_STATIC_STRING(
					"An input string of characters is not in a valid format for the data it represents"
			);
		case SystemCode::CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress"
			);
		case SystemCode::CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress"
			);
		case SystemCode::CLUSTER_NULL_DATA:
			RETURN_STATIC_STRING(
					"An internal cluster error occurred. Data was not properly initialized"
			);
		case SystemCode::CLUSTER_PARTIAL_READ:
			RETURN_STATIC_STRING(
					"An error occurred while reading from a stream of data. An unexpected number of bytes was returned"
			);
		case SystemCode::CLUSTER_PARTIAL_WRITE:
			RETURN_STATIC_STRING(
					"An error occurred while writing to a stream of data. The required number of bytes could not be written"
			);
		case SystemCode::CLUSTER_CANT_DESERIALIZE_DATA:
			RETURN_STATIC_STRING(
					"An error occurred while deserializing a stream of cluster data"
			);
		case SystemCode::DEPENDENT_RESOURCE_PROPERTY_CONFLICT:
			RETURN_STATIC_STRING(
					"One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s)"
			);
		case SystemCode::CLUSTER_NO_QUORUM:
			RETURN_STATIC_STRING(
					"A quorum of cluster nodes was not present to form a cluster"
			);
		case SystemCode::CLUSTER_INVALID_IPV6_NETWORK:
			RETURN_STATIC_STRING(
					"The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address"
			);
		case SystemCode::CLUSTER_INVALID_IPV6_TUNNEL_NETWORK:
			RETURN_STATIC_STRING(
					"The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends"
			);
		case SystemCode::QUORUM_NOT_ALLOWED_IN_THIS_GROUP:
			RETURN_STATIC_STRING(
					"Quorum resource cannot reside in the Available Storage group"
			);
		case SystemCode::DEPENDENCY_TREE_TOO_COMPLEX:
			RETURN_STATIC_STRING(
					"The dependencies for this resource are nested too deeply"
			);
		case SystemCode::EXCEPTION_IN_RESOURCE_CALL:
			RETURN_STATIC_STRING(
					"The call into the resource DLL raised an unhandled exception"
			);
		case SystemCode::CLUSTER_RHS_FAILED_INITIALIZATION:
			RETURN_STATIC_STRING(
					"The RHS process failed to initialize"
			);
		case SystemCode::CLUSTER_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"The Failover Clustering feature is not installed on this node"
			);
		case SystemCode::CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE:
			RETURN_STATIC_STRING(
					"The resources must be online on the same node for this operation"
			);
		case SystemCode::CLUSTER_MAX_NODES_IN_CLUSTER:
			RETURN_STATIC_STRING(
					"A new node can not be added since this cluster is already at its maximum number of nodes"
			);
		case SystemCode::CLUSTER_TOO_MANY_NODES:
			RETURN_STATIC_STRING(
					"This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit"
			);
		case SystemCode::CLUSTER_OBJECT_ALREADY_USED:
			RETURN_STATIC_STRING(
					"An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain"
			);
		case SystemCode::NONCORE_GROUPS_FOUND:
			RETURN_STATIC_STRING(
					"This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed"
			);
		case SystemCode::FILE_SHARE_RESOURCE_CONFLICT:
			RETURN_STATIC_STRING(
					"File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes"
			);
		case SystemCode::CLUSTER_EVICT_INVALID_REQUEST:
			RETURN_STATIC_STRING(
					"Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown. If it is the last node in the cluster, destroy cluster command should be used"
			);
		case SystemCode::CLUSTER_SINGLETON_RESOURCE:
			RETURN_STATIC_STRING(
					"Only one instance of this resource type is allowed in the cluster"
			);
		case SystemCode::CLUSTER_GROUP_SINGLETON_RESOURCE:
			RETURN_STATIC_STRING(
					"Only one instance of this resource type is allowed per resource group"
			);
		case SystemCode::CLUSTER_RESOURCE_PROVIDER_FAILED:
			RETURN_STATIC_STRING(
					"The resource failed to come online due to the failure of one or more provider resources"
			);
		case SystemCode::CLUSTER_RESOURCE_CONFIGURATION_ERROR:
			RETURN_STATIC_STRING(
					"The resource has indicated that it cannot come online on any node"
			);
		case SystemCode::CLUSTER_GROUP_BUSY:
			RETURN_STATIC_STRING(
					"The current operation cannot be performed on this group at this time"
			);
		case SystemCode::CLUSTER_NOT_SHARED_VOLUME:
			RETURN_STATIC_STRING(
					"The directory or file is not located on a cluster shared volume"
			);
		case SystemCode::CLUSTER_INVALID_SECURITY_DESCRIPTOR:
			RETURN_STATIC_STRING(
					"The Security Descriptor does not meet the requirements for a cluster"
			);
		case SystemCode::CLUSTER_SHARED_VOLUMES_IN_USE:
			RETURN_STATIC_STRING(
					"There is one or more shared volumes resources configured in the cluster. Those resources must be moved to available storage in order for operation to succeed"
			);
		case SystemCode::CLUSTER_USE_SHARED_VOLUMES_API:
			RETURN_STATIC_STRING(
					"This group or resource cannot be directly manipulated. Use shared volume APIs to perform desired operation"
			);
		case SystemCode::CLUSTER_BACKUP_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Back up is in progress. Please wait for backup completion before trying this operation again"
			);
		case SystemCode::NON_CSV_PATH:
			RETURN_STATIC_STRING(
					"The path does not belong to a cluster shared volume"
			);
		case SystemCode::CSV_VOLUME_NOT_LOCAL:
			RETURN_STATIC_STRING(
					"The cluster shared volume is not locally mounted on this node"
			);
		case SystemCode::CLUSTER_WATCHDOG_TERMINATING:
			RETURN_STATIC_STRING(
					"The cluster watchdog is terminating"
			);
		case SystemCode::CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES:
			RETURN_STATIC_STRING(
					"A resource vetoed a move between two nodes because they are incompatible"
			);
		case SystemCode::CLUSTER_INVALID_NODE_WEIGHT:
			RETURN_STATIC_STRING(
					"The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements"
			);
		case SystemCode::CLUSTER_RESOURCE_VETOED_CALL:
			RETURN_STATIC_STRING(
					"The resource vetoed the call"
			);
		case SystemCode::RESMON_SYSTEM_RESOURCES_LACKING:
			RETURN_STATIC_STRING(
					"Resource could not start or run because it could not reserve sufficient system resources"
			);
		case SystemCode::CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION:
			RETURN_STATIC_STRING(
					"A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation"
			);
		case SystemCode::CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE:
			RETURN_STATIC_STRING(
					"A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation"
			);
		case SystemCode::CLUSTER_GROUP_QUEUED:
			RETURN_STATIC_STRING(
					"The requested operation can not be completed because the group is queued for an operation"
			);
		case SystemCode::CLUSTER_RESOURCE_LOCKED_STATUS:
			RETURN_STATIC_STRING(
					"The requested operation can not be completed because a resource has locked status"
			);
		case SystemCode::CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"The resource cannot move to another node because a cluster shared volume vetoed the operation"
			);
		case SystemCode::CLUSTER_NODE_DRAIN_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A node drain is already in progress. This value was also named ERROR_CLUSTER_NODE_EVACUATION_IN_PROGRES"
			);
		case SystemCode::CLUSTER_DISK_NOT_CONNECTED:
			RETURN_STATIC_STRING(
					"Clustered storage is not connected to the node"
			);
		case SystemCode::DISK_NOT_CSV_CAPABLE:
			RETURN_STATIC_STRING(
					"The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS"
			);
		case SystemCode::RESOURCE_NOT_IN_AVAILABLE_STORAGE:
			RETURN_STATIC_STRING(
					"The resource must be part of the Available Storage group to complete this action"
			);
		case SystemCode::CLUSTER_SHARED_VOLUME_REDIRECTED:
			RETURN_STATIC_STRING(
					"CSVFS failed operation as volume is in redirected mode"
			);
		case SystemCode::CLUSTER_SHARED_VOLUME_NOT_REDIRECTED:
			RETURN_STATIC_STRING(
					"CSVFS failed operation as volume is not in redirected mode"
			);
		case SystemCode::CLUSTER_CANNOT_RETURN_PROPERTIES:
			RETURN_STATIC_STRING(
					"Cluster properties cannot be returned at this time"
			);
		case SystemCode::CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES:
			RETURN_STATIC_STRING(
					"The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes"
			);
		case SystemCode::CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE:
			RETURN_STATIC_STRING(
					"The operation cannot be completed because the resource is in maintenance mode"
			);
		case SystemCode::CLUSTER_AFFINITY_CONFLICT:
			RETURN_STATIC_STRING(
					"The operation cannot be completed because of cluster affinity conflicts"
			);
		case SystemCode::CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE:
			RETURN_STATIC_STRING(
					"The operation cannot be completed because the resource is a replica virtual machine"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
