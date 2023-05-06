#include <FlameIDE/../../src/Os/Windows/SystemCode3.hpp>

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

// + https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--1300-1699-
enum class SystemCode: decltype(::GetLastError())
{
	NOT_ALL_ASSIGNED =
#	if defined ERROR_NOT_ALL_ASSIGNED
			ERROR_NOT_ALL_ASSIGNED
#	else
				0x514
#	endif
		// Not all privileges or groups referenced are assigned to the caller.

	, SOME_NOT_MAPPED =
#	if defined ERROR_SOME_NOT_MAPPED
			ERROR_SOME_NOT_MAPPED
#	else
				0x515
#	endif
		// Some mapping between account names and security IDs was not done.

	, NO_QUOTAS_FOR_ACCOUNT =
#	if defined ERROR_NO_QUOTAS_FOR_ACCOUNT
			ERROR_NO_QUOTAS_FOR_ACCOUNT
#	else
				0x516
#	endif
		// No system quota limits are specifically set for this account.

	, LOCAL_USER_SESSION_KEY =
#	if defined ERROR_LOCAL_USER_SESSION_KEY
			ERROR_LOCAL_USER_SESSION_KEY
#	else
				0x517
#	endif
		// No encryption key is available. A well-known encryption key was returned.

	, NULL_LM_PASSWORD =
#	if defined ERROR_NULL_LM_PASSWORD
			ERROR_NULL_LM_PASSWORD
#	else
				0x518
#	endif
		// The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.

	, UNKNOWN_REVISION =
#	if defined ERROR_UNKNOWN_REVISION
			ERROR_UNKNOWN_REVISION
#	else
				0x519
#	endif
		// The revision level is unknown.

	, REVISION_MISMATCH =
#	if defined ERROR_REVISION_MISMATCH
			ERROR_REVISION_MISMATCH
#	else
				0x51A
#	endif
		// Indicates two revision levels are incompatible.

	, INVALID_OWNER =
#	if defined ERROR_INVALID_OWNER
			ERROR_INVALID_OWNER
#	else
				0x51B
#	endif
		// This security ID may not be assigned as the owner of this object.

	, INVALID_PRIMARY_GROUP =
#	if defined ERROR_INVALID_PRIMARY_GROUP
			ERROR_INVALID_PRIMARY_GROUP
#	else
				0x51C
#	endif
		// This security ID may not be assigned as the primary group of an object.

	, NO_IMPERSONATION_TOKEN =
#	if defined ERROR_NO_IMPERSONATION_TOKEN
			ERROR_NO_IMPERSONATION_TOKEN
#	else
				0x51D
#	endif
		// An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.

	, CANT_DISABLE_MANDATORY =
#	if defined ERROR_CANT_DISABLE_MANDATORY
			ERROR_CANT_DISABLE_MANDATORY
#	else
				0x51E
#	endif
		// The group may not be disabled.

	, NO_LOGON_SERVERS =
#	if defined ERROR_NO_LOGON_SERVERS
			ERROR_NO_LOGON_SERVERS
#	else
				0x51F
#	endif
		// There are currently no logon servers available to service the logon request.

	, NO_SUCH_LOGON_SESSION =
#	if defined ERROR_NO_SUCH_LOGON_SESSION
			ERROR_NO_SUCH_LOGON_SESSION
#	else
				0x520
#	endif
		// A specified logon session does not exist. It may already have been terminated.

	, NO_SUCH_PRIVILEGE =
#	if defined ERROR_NO_SUCH_PRIVILEGE
			ERROR_NO_SUCH_PRIVILEGE
#	else
				0x521
#	endif
		// A specified privilege does not exist.

	, PRIVILEGE_NOT_HELD =
#	if defined ERROR_PRIVILEGE_NOT_HELD
			ERROR_PRIVILEGE_NOT_HELD
#	else
				0x522
#	endif
		// A required privilege is not held by the client.

	, INVALID_ACCOUNT_NAME =
#	if defined ERROR_INVALID_ACCOUNT_NAME
			ERROR_INVALID_ACCOUNT_NAME
#	else
				0x523
#	endif
		// The name provided is not a properly formed account name.

	, USER_EXISTS =
#	if defined ERROR_USER_EXISTS
			ERROR_USER_EXISTS
#	else
				0x524
#	endif
		// The specified account already exists.

	, NO_SUCH_USER =
#	if defined ERROR_NO_SUCH_USER
			ERROR_NO_SUCH_USER
#	else
				0x525
#	endif
		// The specified account does not exist.

	, GROUP_EXISTS =
#	if defined ERROR_GROUP_EXISTS
			ERROR_GROUP_EXISTS
#	else
				0x526
#	endif
		// The specified group already exists.

	, NO_SUCH_GROUP =
#	if defined ERROR_NO_SUCH_GROUP
			ERROR_NO_SUCH_GROUP
#	else
				0x527
#	endif
		// The specified group does not exist.

	, MEMBER_IN_GROUP =
#	if defined ERROR_MEMBER_IN_GROUP
			ERROR_MEMBER_IN_GROUP
#	else
				0x528
#	endif
		// Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.

	, MEMBER_NOT_IN_GROUP =
#	if defined ERROR_MEMBER_NOT_IN_GROUP
			ERROR_MEMBER_NOT_IN_GROUP
#	else
				0x529
#	endif
		// The specified user account is not a member of the specified group account.

	, LAST_ADMIN =
#	if defined ERROR_LAST_ADMIN
			ERROR_LAST_ADMIN
#	else
				0x52A
#	endif
		// This operation is disallowed as it could result in an administration account being disabled, deleted or unable to log on.

	, WRONG_PASSWORD =
#	if defined ERROR_WRONG_PASSWORD
			ERROR_WRONG_PASSWORD
#	else
				0x52B
#	endif
		// Unable to update the password. The value provided as the current password is incorrect.

	, ILL_FORMED_PASSWORD =
#	if defined ERROR_ILL_FORMED_PASSWORD
			ERROR_ILL_FORMED_PASSWORD
#	else
				0x52C
#	endif
		// Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.

	, PASSWORD_RESTRICTION =
#	if defined ERROR_PASSWORD_RESTRICTION
			ERROR_PASSWORD_RESTRICTION
#	else
				0x52D
#	endif
		// Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.

	, LOGON_FAILURE =
#	if defined ERROR_LOGON_FAILURE
			ERROR_LOGON_FAILURE
#	else
				0x52E
#	endif
		// The user name or password is incorrect.

	, ACCOUNT_RESTRICTION =
#	if defined ERROR_ACCOUNT_RESTRICTION
			ERROR_ACCOUNT_RESTRICTION
#	else
				0x52F
#	endif
		// Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.

	, INVALID_LOGON_HOURS =
#	if defined ERROR_INVALID_LOGON_HOURS
			ERROR_INVALID_LOGON_HOURS
#	else
				0x530
#	endif
		// Your account has time restrictions that keep you from signing in right now.

	, INVALID_WORKSTATION =
#	if defined ERROR_INVALID_WORKSTATION
			ERROR_INVALID_WORKSTATION
#	else
				0x531
#	endif
		// This user isn't allowed to sign in to this computer.

	, PASSWORD_EXPIRED =
#	if defined ERROR_PASSWORD_EXPIRED
			ERROR_PASSWORD_EXPIRED
#	else
				0x532
#	endif
		// The password for this account has expired.

	, ACCOUNT_DISABLED =
#	if defined ERROR_ACCOUNT_DISABLED
			ERROR_ACCOUNT_DISABLED
#	else
				0x533
#	endif
		// This user can't sign in because this account is currently disabled.

	, NONE_MAPPED =
#	if defined ERROR_NONE_MAPPED
			ERROR_NONE_MAPPED
#	else
				0x534
#	endif
		// No mapping between account names and security IDs was done.

	, TOO_MANY_LUIDS_REQUESTED =
#	if defined ERROR_TOO_MANY_LUIDS_REQUESTED
			ERROR_TOO_MANY_LUIDS_REQUESTED
#	else
				0x535
#	endif
		// Too many local user identifiers (LUIDs) were requested at one time.

	, LUIDS_EXHAUSTED =
#	if defined ERROR_LUIDS_EXHAUSTED
			ERROR_LUIDS_EXHAUSTED
#	else
				0x536
#	endif
		// No more local user identifiers (LUIDs) are available.

	, INVALID_SUB_AUTHORITY =
#	if defined ERROR_INVALID_SUB_AUTHORITY
			ERROR_INVALID_SUB_AUTHORITY
#	else
				0x537
#	endif
		// The subauthority part of a security ID is invalid for this particular use.

	, INVALID_ACL =
#	if defined ERROR_INVALID_ACL
			ERROR_INVALID_ACL
#	else
				0x538
#	endif
		// The access control list (ACL) structure is invalid.

	, INVALID_SID =
#	if defined ERROR_INVALID_SID
			ERROR_INVALID_SID
#	else
				0x539
#	endif
		// The security ID structure is invalid.

	, INVALID_SECURITY_DESCR =
#	if defined ERROR_INVALID_SECURITY_DESCR
			ERROR_INVALID_SECURITY_DESCR
#	else
				0x53A
#	endif
		// The security descriptor structure is invalid.

	, BAD_INHERITANCE_ACL =
#	if defined ERROR_BAD_INHERITANCE_ACL
			ERROR_BAD_INHERITANCE_ACL
#	else
				0x53C
#	endif
		// The inherited access control list (ACL) or access control entry (ACE) could not be built.

	, SERVER_DISABLED =
#	if defined ERROR_SERVER_DISABLED
			ERROR_SERVER_DISABLED
#	else
				0x53D
#	endif
		// The server is currently disabled.

	, SERVER_NOT_DISABLED =
#	if defined ERROR_SERVER_NOT_DISABLED
			ERROR_SERVER_NOT_DISABLED
#	else
				0x53E
#	endif
		// The server is currently enabled.

	, INVALID_ID_AUTHORITY =
#	if defined ERROR_INVALID_ID_AUTHORITY
			ERROR_INVALID_ID_AUTHORITY
#	else
				0x53F
#	endif
		// The value provided was an invalid value for an identifier authority.

	, ALLOTTED_SPACE_EXCEEDED =
#	if defined ERROR_ALLOTTED_SPACE_EXCEEDED
			ERROR_ALLOTTED_SPACE_EXCEEDED
#	else
				0x540
#	endif
		// No more memory is available for security information updates.

	, INVALID_GROUP_ATTRIBUTES =
#	if defined ERROR_INVALID_GROUP_ATTRIBUTES
			ERROR_INVALID_GROUP_ATTRIBUTES
#	else
				0x541
#	endif
		// The specified attributes are invalid, or incompatible with the attributes for the group as a whole.

	, BAD_IMPERSONATION_LEVEL =
#	if defined ERROR_BAD_IMPERSONATION_LEVEL
			ERROR_BAD_IMPERSONATION_LEVEL
#	else
				0x542
#	endif
		// Either a required impersonation level was not provided, or the provided impersonation level is invalid.

	, CANT_OPEN_ANONYMOUS =
#	if defined ERROR_CANT_OPEN_ANONYMOUS
			ERROR_CANT_OPEN_ANONYMOUS
#	else
				0x543
#	endif
		// Cannot open an anonymous level security token.

	, BAD_VALIDATION_CLASS =
#	if defined ERROR_BAD_VALIDATION_CLASS
			ERROR_BAD_VALIDATION_CLASS
#	else
				0x544
#	endif
		// The validation information class requested was invalid.

	, BAD_TOKEN_TYPE =
#	if defined ERROR_BAD_TOKEN_TYPE
			ERROR_BAD_TOKEN_TYPE
#	else
				0x545
#	endif
		// The type of the token is inappropriate for its attempted use.

	, NO_SECURITY_ON_OBJECT =
#	if defined ERROR_NO_SECURITY_ON_OBJECT
			ERROR_NO_SECURITY_ON_OBJECT
#	else
				0x546
#	endif
		// Unable to perform a security operation on an object that has no associated security.

	, CANT_ACCESS_DOMAIN_INFO =
#	if defined ERROR_CANT_ACCESS_DOMAIN_INFO
			ERROR_CANT_ACCESS_DOMAIN_INFO
#	else
				0x547
#	endif
		// Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.

	, INVALID_SERVER_STATE =
#	if defined ERROR_INVALID_SERVER_STATE
			ERROR_INVALID_SERVER_STATE
#	else
				0x548
#	endif
		// The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.

	, INVALID_DOMAIN_STATE =
#	if defined ERROR_INVALID_DOMAIN_STATE
			ERROR_INVALID_DOMAIN_STATE
#	else
				0x549
#	endif
		// The domain was in the wrong state to perform the security operation.

	, INVALID_DOMAIN_ROLE =
#	if defined ERROR_INVALID_DOMAIN_ROLE
			ERROR_INVALID_DOMAIN_ROLE
#	else
				0x54A
#	endif
		// This operation is only allowed for the Primary Domain Controller of the domain.

	, NO_SUCH_DOMAIN =
#	if defined ERROR_NO_SUCH_DOMAIN
			ERROR_NO_SUCH_DOMAIN
#	else
				0x54B
#	endif
		// The specified domain either does not exist or could not be contacted.

	, DOMAIN_EXISTS =
#	if defined ERROR_DOMAIN_EXISTS
			ERROR_DOMAIN_EXISTS
#	else
				0x54C
#	endif
		// The specified domain already exists.

	, DOMAIN_LIMIT_EXCEEDED =
#	if defined ERROR_DOMAIN_LIMIT_EXCEEDED
			ERROR_DOMAIN_LIMIT_EXCEEDED
#	else
				0x54D
#	endif
		// An attempt was made to exceed the limit on the number of domains per server.

	, INTERNAL_DB_CORRUPTION =
#	if defined ERROR_INTERNAL_DB_CORRUPTION
			ERROR_INTERNAL_DB_CORRUPTION
#	else
				0x54E
#	endif
		// Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.

	, INTERNAL_ERROR =
#	if defined ERROR_INTERNAL_ERROR
			ERROR_INTERNAL_ERROR
#	else
				0x54F
#	endif
		// An internal error occurred.

	, GENERIC_NOT_MAPPED =
#	if defined ERROR_GENERIC_NOT_MAPPED
			ERROR_GENERIC_NOT_MAPPED
#	else
				0x550
#	endif
		// Generic access types were contained in an access mask which should already be mapped to nongeneric types.

	, BAD_DESCRIPTOR_FORMAT =
#	if defined ERROR_BAD_DESCRIPTOR_FORMAT
			ERROR_BAD_DESCRIPTOR_FORMAT
#	else
				0x551
#	endif
		// A security descriptor is not in the right format (absolute or self-relative).

	, NOT_LOGON_PROCESS =
#	if defined ERROR_NOT_LOGON_PROCESS
			ERROR_NOT_LOGON_PROCESS
#	else
				0x552
#	endif
		// The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.

	, LOGON_SESSION_EXISTS =
#	if defined ERROR_LOGON_SESSION_EXISTS
			ERROR_LOGON_SESSION_EXISTS
#	else
				0x553
#	endif
		// Cannot start a new logon session with an ID that is already in use.

	, NO_SUCH_PACKAGE =
#	if defined ERROR_NO_SUCH_PACKAGE
			ERROR_NO_SUCH_PACKAGE
#	else
				0x554
#	endif
		// A specified authentication package is unknown.

	, BAD_LOGON_SESSION_STATE =
#	if defined ERROR_BAD_LOGON_SESSION_STATE
			ERROR_BAD_LOGON_SESSION_STATE
#	else
				0x555
#	endif
		// The logon session is not in a state that is consistent with the requested operation.

	, LOGON_SESSION_COLLISION =
#	if defined ERROR_LOGON_SESSION_COLLISION
			ERROR_LOGON_SESSION_COLLISION
#	else
				0x556
#	endif
		// The logon session ID is already in use.

	, INVALID_LOGON_TYPE =
#	if defined ERROR_INVALID_LOGON_TYPE
			ERROR_INVALID_LOGON_TYPE
#	else
				0x557
#	endif
		// A logon request contained an invalid logon type value.

	, CANNOT_IMPERSONATE =
#	if defined ERROR_CANNOT_IMPERSONATE
			ERROR_CANNOT_IMPERSONATE
#	else
				0x558
#	endif
		// Unable to impersonate using a named pipe until data has been read from that pipe.

	, RXACT_INVALID_STATE =
#	if defined ERROR_RXACT_INVALID_STATE
			ERROR_RXACT_INVALID_STATE
#	else
				0x559
#	endif
		// The transaction state of a registry subtree is incompatible with the requested operation.

	, RXACT_COMMIT_FAILURE =
#	if defined ERROR_RXACT_COMMIT_FAILURE
			ERROR_RXACT_COMMIT_FAILURE
#	else
				0x55A
#	endif
		// An internal security database corruption has been encountered.

	, SPECIAL_ACCOUNT =
#	if defined ERROR_SPECIAL_ACCOUNT
			ERROR_SPECIAL_ACCOUNT
#	else
				0x55B
#	endif
		// Cannot perform this operation on built-in accounts.

	, SPECIAL_GROUP =
#	if defined ERROR_SPECIAL_GROUP
			ERROR_SPECIAL_GROUP
#	else
				0x55C
#	endif
		// Cannot perform this operation on this built-in special group.

	, SPECIAL_USER =
#	if defined ERROR_SPECIAL_USER
			ERROR_SPECIAL_USER
#	else
				0x55D
#	endif
		// Cannot perform this operation on this built-in special user.

	, MEMBERS_PRIMARY_GROUP =
#	if defined ERROR_MEMBERS_PRIMARY_GROUP
			ERROR_MEMBERS_PRIMARY_GROUP
#	else
				0x55E
#	endif
		// The user cannot be removed from a group because the group is currently the user's primary group.

	, TOKEN_ALREADY_IN_USE =
#	if defined ERROR_TOKEN_ALREADY_IN_USE
			ERROR_TOKEN_ALREADY_IN_USE
#	else
				0x55F
#	endif
		// The token is already in use as a primary token.

	, NO_SUCH_ALIAS =
#	if defined ERROR_NO_SUCH_ALIAS
			ERROR_NO_SUCH_ALIAS
#	else
				0x560
#	endif
		// The specified local group does not exist.

	, MEMBER_NOT_IN_ALIAS =
#	if defined ERROR_MEMBER_NOT_IN_ALIAS
			ERROR_MEMBER_NOT_IN_ALIAS
#	else
				0x561
#	endif
		// The specified account name is not a member of the group.

	, MEMBER_IN_ALIAS =
#	if defined ERROR_MEMBER_IN_ALIAS
			ERROR_MEMBER_IN_ALIAS
#	else
				0x562
#	endif
		// The specified account name is already a member of the group.

	, ALIAS_EXISTS =
#	if defined ERROR_ALIAS_EXISTS
			ERROR_ALIAS_EXISTS
#	else
				0x563
#	endif
		// The specified local group already exists.

	, LOGON_NOT_GRANTED =
#	if defined ERROR_LOGON_NOT_GRANTED
			ERROR_LOGON_NOT_GRANTED
#	else
				0x564
#	endif
		// Logon failure: the user has not been granted the requested logon type at this computer.

	, TOO_MANY_SECRETS =
#	if defined ERROR_TOO_MANY_SECRETS
			ERROR_TOO_MANY_SECRETS
#	else
				0x565
#	endif
		// The maximum number of secrets that may be stored in a single system has been exceeded.

	, SECRET_TOO_LONG =
#	if defined ERROR_SECRET_TOO_LONG
			ERROR_SECRET_TOO_LONG
#	else
				0x566
#	endif
		// The length of a secret exceeds the maximum length allowed.

	, INTERNAL_DB_ERROR =
#	if defined ERROR_INTERNAL_DB_ERROR
			ERROR_INTERNAL_DB_ERROR
#	else
				0x567
#	endif
		// The local security authority database contains an internal inconsistency.

	, TOO_MANY_CONTEXT_IDS =
#	if defined ERROR_TOO_MANY_CONTEXT_IDS
			ERROR_TOO_MANY_CONTEXT_IDS
#	else
				0x568
#	endif
		// During a logon attempt, the user's security context accumulated too many security IDs.

	, LOGON_TYPE_NOT_GRANTED =
#	if defined ERROR_LOGON_TYPE_NOT_GRANTED
			ERROR_LOGON_TYPE_NOT_GRANTED
#	else
				0x569
#	endif
		// Logon failure: the user has not been granted the requested logon type at this computer.

	, NT_CROSS_ENCRYPTION_REQUIRED =
#	if defined ERROR_NT_CROSS_ENCRYPTION_REQUIRED
			ERROR_NT_CROSS_ENCRYPTION_REQUIRED
#	else
				0x56A
#	endif
		// A cross-encrypted password is necessary to change a user password.

	, NO_SUCH_MEMBER =
#	if defined ERROR_NO_SUCH_MEMBER
			ERROR_NO_SUCH_MEMBER
#	else
				0x56B
#	endif
		// A member could not be added to or removed from the local group because the member does not exist.

	, INVALID_MEMBER =
#	if defined ERROR_INVALID_MEMBER
			ERROR_INVALID_MEMBER
#	else
				0x56C
#	endif
		// A new member could not be added to a local group because the member has the wrong account type.

	, TOO_MANY_SIDS =
#	if defined ERROR_TOO_MANY_SIDS
			ERROR_TOO_MANY_SIDS
#	else
				0x56D
#	endif
		// Too many security IDs have been specified.

	, LM_CROSS_ENCRYPTION_REQUIRED =
#	if defined ERROR_LM_CROSS_ENCRYPTION_REQUIRED
			ERROR_LM_CROSS_ENCRYPTION_REQUIRED
#	else
				0x56E
#	endif
		// A cross-encrypted password is necessary to change this user password.

	, NO_INHERITANCE =
#	if defined ERROR_NO_INHERITANCE
			ERROR_NO_INHERITANCE
#	else
				0x56F
#	endif
		// Indicates an ACL contains no inheritable components.

	, FILE_CORRUPT =
#	if defined ERROR_FILE_CORRUPT
			ERROR_FILE_CORRUPT
#	else
				0x570
#	endif
		// The file or directory is corrupted and unreadable.

	, DISK_CORRUPT =
#	if defined ERROR_DISK_CORRUPT
			ERROR_DISK_CORRUPT
#	else
				0x571
#	endif
		// The disk structure is corrupted and unreadable.

	, NO_USER_SESSION_KEY =
#	if defined ERROR_NO_USER_SESSION_KEY
			ERROR_NO_USER_SESSION_KEY
#	else
				0x572
#	endif
		// There is no user session key for the specified logon session.

	, LICENSE_QUOTA_EXCEEDED =
#	if defined ERROR_LICENSE_QUOTA_EXCEEDED
			ERROR_LICENSE_QUOTA_EXCEEDED
#	else
				0x573
#	endif
		// The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.

	, WRONG_TARGET_NAME =
#	if defined ERROR_WRONG_TARGET_NAME
			ERROR_WRONG_TARGET_NAME
#	else
				0x574
#	endif
		// The target account name is incorrect.

	, MUTUAL_AUTH_FAILED =
#	if defined ERROR_MUTUAL_AUTH_FAILED
			ERROR_MUTUAL_AUTH_FAILED
#	else
				0x575
#	endif
		// Mutual Authentication failed. The server's password is out of date at the domain controller.

	, TIME_SKEW =
#	if defined ERROR_TIME_SKEW
			ERROR_TIME_SKEW
#	else
				0x576
#	endif
		// There is a time and/or date difference between the client and server.

	, CURRENT_DOMAIN_NOT_ALLOWED =
#	if defined ERROR_CURRENT_DOMAIN_NOT_ALLOWED
			ERROR_CURRENT_DOMAIN_NOT_ALLOWED
#	else
				0x577
#	endif
		// This operation cannot be performed on the current domain.

	, INVALID_WINDOW_HANDLE =
#	if defined ERROR_INVALID_WINDOW_HANDLE
			ERROR_INVALID_WINDOW_HANDLE
#	else
				0x578
#	endif
		// Invalid window handle.

	, INVALID_MENU_HANDLE =
#	if defined ERROR_INVALID_MENU_HANDLE
			ERROR_INVALID_MENU_HANDLE
#	else
				0x579
#	endif
		// Invalid menu handle.

	, INVALID_CURSOR_HANDLE =
#	if defined ERROR_INVALID_CURSOR_HANDLE
			ERROR_INVALID_CURSOR_HANDLE
#	else
				0x57A
#	endif
		// Invalid cursor handle.

	, INVALID_ACCEL_HANDLE =
#	if defined ERROR_INVALID_ACCEL_HANDLE
			ERROR_INVALID_ACCEL_HANDLE
#	else
				0x57B
#	endif
		// Invalid accelerator table handle.

	, INVALID_HOOK_HANDLE =
#	if defined ERROR_INVALID_HOOK_HANDLE
			ERROR_INVALID_HOOK_HANDLE
#	else
				0x57C
#	endif
		// Invalid hook handle.

	, INVALID_DWP_HANDLE =
#	if defined ERROR_INVALID_DWP_HANDLE
			ERROR_INVALID_DWP_HANDLE
#	else
				0x57D
#	endif
		// Invalid handle to a multiple-window position structure.

	, TLW_WITH_WSCHILD =
#	if defined ERROR_TLW_WITH_WSCHILD
			ERROR_TLW_WITH_WSCHILD
#	else
				0x57E
#	endif
		// Cannot create a top-level child window.

	, CANNOT_FIND_WND_CLASS =
#	if defined ERROR_CANNOT_FIND_WND_CLASS
			ERROR_CANNOT_FIND_WND_CLASS
#	else
				0x57F
#	endif
		// Cannot find window class.

	, WINDOW_OF_OTHER_THREAD =
#	if defined ERROR_WINDOW_OF_OTHER_THREAD
			ERROR_WINDOW_OF_OTHER_THREAD
#	else
				0x580
#	endif
		// Invalid window; it belongs to other thread.

	, HOTKEY_ALREADY_REGISTERED =
#	if defined ERROR_HOTKEY_ALREADY_REGISTERED
			ERROR_HOTKEY_ALREADY_REGISTERED
#	else
				0x581
#	endif
		// Hot key is already registered.

	, CLASS_ALREADY_EXISTS =
#	if defined ERROR_CLASS_ALREADY_EXISTS
			ERROR_CLASS_ALREADY_EXISTS
#	else
				0x582
#	endif
		// Class already exists.

	, CLASS_DOES_NOT_EXIST =
#	if defined ERROR_CLASS_DOES_NOT_EXIST
			ERROR_CLASS_DOES_NOT_EXIST
#	else
				0x583
#	endif
		// Class does not exist.

	, CLASS_HAS_WINDOWS =
#	if defined ERROR_CLASS_HAS_WINDOWS
			ERROR_CLASS_HAS_WINDOWS
#	else
				0x584
#	endif
		// Class still has open windows.

	, INVALID_INDEX =
#	if defined ERROR_INVALID_INDEX
			ERROR_INVALID_INDEX
#	else
				0x585
#	endif
		// Invalid index.

	, INVALID_ICON_HANDLE =
#	if defined ERROR_INVALID_ICON_HANDLE
			ERROR_INVALID_ICON_HANDLE
#	else
				0x586
#	endif
		// Invalid icon handle.

	, PRIVATE_DIALOG_INDEX =
#	if defined ERROR_PRIVATE_DIALOG_INDEX
			ERROR_PRIVATE_DIALOG_INDEX
#	else
				0x587
#	endif
		// Using private DIALOG window words.

	, LISTBOX_ID_NOT_FOUND =
#	if defined ERROR_LISTBOX_ID_NOT_FOUND
			ERROR_LISTBOX_ID_NOT_FOUND
#	else
				0x588
#	endif
		// The list box identifier was not found.

	, NO_WILDCARD_CHARACTERS =
#	if defined ERROR_NO_WILDCARD_CHARACTERS
			ERROR_NO_WILDCARD_CHARACTERS
#	else
				0x589
#	endif
		// No wildcards were found.

	, CLIPBOARD_NOT_OPEN =
#	if defined ERROR_CLIPBOARD_NOT_OPEN
			ERROR_CLIPBOARD_NOT_OPEN
#	else
				0x58A
#	endif
		// Thread does not have a clipboard open.

	, HOTKEY_NOT_REGISTERED =
#	if defined ERROR_HOTKEY_NOT_REGISTERED
			ERROR_HOTKEY_NOT_REGISTERED
#	else
				0x58B
#	endif
		// Hot key is not registered.

	, WINDOW_NOT_DIALOG =
#	if defined ERROR_WINDOW_NOT_DIALOG
			ERROR_WINDOW_NOT_DIALOG
#	else
				0x58C
#	endif
		// The window is not a valid dialog window.

	, CONTROL_ID_NOT_FOUND =
#	if defined ERROR_CONTROL_ID_NOT_FOUND
			ERROR_CONTROL_ID_NOT_FOUND
#	else
				0x58D
#	endif
		// Control ID not found.

	, INVALID_COMBOBOX_MESSAGE =
#	if defined ERROR_INVALID_COMBOBOX_MESSAGE
			ERROR_INVALID_COMBOBOX_MESSAGE
#	else
				0x58E
#	endif
		// Invalid message for a combo box because it does not have an edit control.

	, WINDOW_NOT_COMBOBOX =
#	if defined ERROR_WINDOW_NOT_COMBOBOX
			ERROR_WINDOW_NOT_COMBOBOX
#	else
				0x58F
#	endif
		// The window is not a combo box.

	, INVALID_EDIT_HEIGHT =
#	if defined ERROR_INVALID_EDIT_HEIGHT
			ERROR_INVALID_EDIT_HEIGHT
#	else
				0x590
#	endif
		// Height must be less than 256.

	, DC_NOT_FOUND =
#	if defined ERROR_DC_NOT_FOUND
			ERROR_DC_NOT_FOUND
#	else
				0x591
#	endif
		// Invalid device context (DC) handle.

	, INVALID_HOOK_FILTER =
#	if defined ERROR_INVALID_HOOK_FILTER
			ERROR_INVALID_HOOK_FILTER
#	else
				0x592
#	endif
		// Invalid hook procedure type.

	, INVALID_FILTER_PROC =
#	if defined ERROR_INVALID_FILTER_PROC
			ERROR_INVALID_FILTER_PROC
#	else
				0x593
#	endif
		// Invalid hook procedure.

	, HOOK_NEEDS_HMOD =
#	if defined ERROR_HOOK_NEEDS_HMOD
			ERROR_HOOK_NEEDS_HMOD
#	else
				0x594
#	endif
		// Cannot set nonlocal hook without a module handle.

	, GLOBAL_ONLY_HOOK =
#	if defined ERROR_GLOBAL_ONLY_HOOK
			ERROR_GLOBAL_ONLY_HOOK
#	else
				0x595
#	endif
		// This hook procedure can only be set globally.

	, JOURNAL_HOOK_SET =
#	if defined ERROR_JOURNAL_HOOK_SET
			ERROR_JOURNAL_HOOK_SET
#	else
				0x596
#	endif
		// The journal hook procedure is already installed.

	, HOOK_NOT_INSTALLED =
#	if defined ERROR_HOOK_NOT_INSTALLED
			ERROR_HOOK_NOT_INSTALLED
#	else
				0x597
#	endif
		// The hook procedure is not installed.

	, INVALID_LB_MESSAGE =
#	if defined ERROR_INVALID_LB_MESSAGE
			ERROR_INVALID_LB_MESSAGE
#	else
				0x598
#	endif
		// Invalid message for single-selection list box.

	, SETCOUNT_ON_BAD_LB =
#	if defined ERROR_SETCOUNT_ON_BAD_LB
			ERROR_SETCOUNT_ON_BAD_LB
#	else
				0x599
#	endif
		// LB_SETCOUNT sent to non-lazy list box.

	, LB_WITHOUT_TABSTOPS =
#	if defined ERROR_LB_WITHOUT_TABSTOPS
			ERROR_LB_WITHOUT_TABSTOPS
#	else
				0x59A
#	endif
		// This list box does not support tab stops.

	, DESTROY_OBJECT_OF_OTHER_THREAD =
#	if defined ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
			ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
#	else
				0x59B
#	endif
		// Cannot destroy object created by another thread.

	, CHILD_WINDOW_MENU =
#	if defined ERROR_CHILD_WINDOW_MENU
			ERROR_CHILD_WINDOW_MENU
#	else
				0x59C
#	endif
		// Child windows cannot have menus.

	, NO_SYSTEM_MENU =
#	if defined ERROR_NO_SYSTEM_MENU
			ERROR_NO_SYSTEM_MENU
#	else
				0x59D
#	endif
		// The window does not have a system menu.

	, INVALID_MSGBOX_STYLE =
#	if defined ERROR_INVALID_MSGBOX_STYLE
			ERROR_INVALID_MSGBOX_STYLE
#	else
				0x59E
#	endif
		// Invalid message box style.

	, INVALID_SPI_VALUE =
#	if defined ERROR_INVALID_SPI_VALUE
			ERROR_INVALID_SPI_VALUE
#	else
				0x59F
#	endif
		// Invalid system-wide (SPI_*) parameter.

	, SCREEN_ALREADY_LOCKED =
#	if defined ERROR_SCREEN_ALREADY_LOCKED
			ERROR_SCREEN_ALREADY_LOCKED
#	else
				0x5A0
#	endif
		// Screen already locked.

	, HWNDS_HAVE_DIFF_PARENT =
#	if defined ERROR_HWNDS_HAVE_DIFF_PARENT
			ERROR_HWNDS_HAVE_DIFF_PARENT
#	else
				0x5A1
#	endif
		// All handles to windows in a multiple-window position structure must have the same parent.

	, NOT_CHILD_WINDOW =
#	if defined ERROR_NOT_CHILD_WINDOW
			ERROR_NOT_CHILD_WINDOW
#	else
				0x5A2
#	endif
		// The window is not a child window.

	, INVALID_GW_COMMAND =
#	if defined ERROR_INVALID_GW_COMMAND
			ERROR_INVALID_GW_COMMAND
#	else
				0x5A3
#	endif
		// Invalid GW_* command.

	, INVALID_THREAD_ID =
#	if defined ERROR_INVALID_THREAD_ID
			ERROR_INVALID_THREAD_ID
#	else
				0x5A4
#	endif
		// Invalid thread identifier.

	, NON_MDICHILD_WINDOW =
#	if defined ERROR_NON_MDICHILD_WINDOW
			ERROR_NON_MDICHILD_WINDOW
#	else
				0x5A5
#	endif
		// Cannot process a message from a window that is not a multiple document interface (MDI) window.

	, POPUP_ALREADY_ACTIVE =
#	if defined ERROR_POPUP_ALREADY_ACTIVE
			ERROR_POPUP_ALREADY_ACTIVE
#	else
				0x5A6
#	endif
		// Popup menu already active.

	, NO_SCROLLBARS =
#	if defined ERROR_NO_SCROLLBARS
			ERROR_NO_SCROLLBARS
#	else
				0x5A7
#	endif
		// The window does not have scroll bars.

	, INVALID_SCROLLBAR_RANGE =
#	if defined ERROR_INVALID_SCROLLBAR_RANGE
			ERROR_INVALID_SCROLLBAR_RANGE
#	else
				0x5A8
#	endif
		// Scroll bar range cannot be greater than MAXLONG.

	, INVALID_SHOWWIN_COMMAND =
#	if defined ERROR_INVALID_SHOWWIN_COMMAND
			ERROR_INVALID_SHOWWIN_COMMAND
#	else
				0x5A9
#	endif
		// Cannot show or remove the window in the way specified.

	, NO_SYSTEM_RESOURCES =
#	if defined ERROR_NO_SYSTEM_RESOURCES
			ERROR_NO_SYSTEM_RESOURCES
#	else
				0x5AA
#	endif
		// Insufficient system resources exist to complete the requested service.

	, NONPAGED_SYSTEM_RESOURCES =
#	if defined ERROR_NONPAGED_SYSTEM_RESOURCES
			ERROR_NONPAGED_SYSTEM_RESOURCES
#	else
				0x5AB
#	endif
		// Insufficient system resources exist to complete the requested service.

	, PAGED_SYSTEM_RESOURCES =
#	if defined ERROR_PAGED_SYSTEM_RESOURCES
			ERROR_PAGED_SYSTEM_RESOURCES
#	else
				0x5AC
#	endif
		// Insufficient system resources exist to complete the requested service.

	, WORKING_SET_QUOTA =
#	if defined ERROR_WORKING_SET_QUOTA
			ERROR_WORKING_SET_QUOTA
#	else
				0x5AD
#	endif
		// Insufficient quota to complete the requested service.

	, PAGEFILE_QUOTA =
#	if defined ERROR_PAGEFILE_QUOTA
			ERROR_PAGEFILE_QUOTA
#	else
				0x5AE
#	endif
		// Insufficient quota to complete the requested service.

	, COMMITMENT_LIMIT =
#	if defined ERROR_COMMITMENT_LIMIT
			ERROR_COMMITMENT_LIMIT
#	else
				0x5AF
#	endif
		// The paging file is too small for this operation to complete.

	, MENU_ITEM_NOT_FOUND =
#	if defined ERROR_MENU_ITEM_NOT_FOUND
			ERROR_MENU_ITEM_NOT_FOUND
#	else
				0x5B0
#	endif
		// A menu item was not found.

	, INVALID_KEYBOARD_HANDLE =
#	if defined ERROR_INVALID_KEYBOARD_HANDLE
			ERROR_INVALID_KEYBOARD_HANDLE
#	else
				0x5B1
#	endif
		// Invalid keyboard layout handle.

	, HOOK_TYPE_NOT_ALLOWED =
#	if defined ERROR_HOOK_TYPE_NOT_ALLOWED
			ERROR_HOOK_TYPE_NOT_ALLOWED
#	else
				0x5B2
#	endif
		// Hook type not allowed.

	, REQUIRES_INTERACTIVE_WINDOWSTATION =
#	if defined ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
			ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
#	else
				0x5B3
#	endif
		// This operation requires an interactive window station.

	, TIMEOUT =
#	if defined ERROR_TIMEOUT
			ERROR_TIMEOUT
#	else
				0x5B4
#	endif
		// This operation returned because the timeout period expired.

	, INVALID_MONITOR_HANDLE =
#	if defined ERROR_INVALID_MONITOR_HANDLE
			ERROR_INVALID_MONITOR_HANDLE
#	else
				0x5B5
#	endif
		// Invalid monitor handle.

	, INCORRECT_SIZE =
#	if defined ERROR_INCORRECT_SIZE
			ERROR_INCORRECT_SIZE
#	else
				0x5B6
#	endif
		// Incorrect size argument.

	, SYMLINK_CLASS_DISABLED =
#	if defined ERROR_SYMLINK_CLASS_DISABLED
			ERROR_SYMLINK_CLASS_DISABLED
#	else
				0x5B7
#	endif
		// The symbolic link cannot be followed because its type is disabled.

	, SYMLINK_NOT_SUPPORTED =
#	if defined ERROR_SYMLINK_NOT_SUPPORTED
			ERROR_SYMLINK_NOT_SUPPORTED
#	else
				0x5B8
#	endif
		// This application does not support the current operation on symbolic links.

	, XML_PARSE_ERROR =
#	if defined ERROR_XML_PARSE_ERROR
			ERROR_XML_PARSE_ERROR
#	else
				0x5B9
#	endif
		// Windows was unable to parse the requested XML data.

	, XMLDSIG_ERROR =
#	if defined ERROR_XMLDSIG_ERROR
			ERROR_XMLDSIG_ERROR
#	else
				0x5BA
#	endif
		// An error was encountered while processing an XML digital signature.

	, RESTART_APPLICATION =
#	if defined ERROR_RESTART_APPLICATION
			ERROR_RESTART_APPLICATION
#	else
				0x5BB
#	endif
		// This application must be restarted.

	, WRONG_COMPARTMENT =
#	if defined ERROR_WRONG_COMPARTMENT
			ERROR_WRONG_COMPARTMENT
#	else
				0x5BC
#	endif
		// The caller made the connection request in the wrong routing compartment.

	, AUTHIP_FAILURE =
#	if defined ERROR_AUTHIP_FAILURE
			ERROR_AUTHIP_FAILURE
#	else
				0x5BD
#	endif
		// There was an AuthIP failure when attempting to connect to the remote host.

	, NO_NVRAM_RESOURCES =
#	if defined ERROR_NO_NVRAM_RESOURCES
			ERROR_NO_NVRAM_RESOURCES
#	else
				0x5BE
#	endif
		// Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.

	, NOT_GUI_PROCESS =
#	if defined ERROR_NOT_GUI_PROCESS
			ERROR_NOT_GUI_PROCESS
#	else
				0x5BF
#	endif
		// Unable to finish the requested operation because the specified process is not a GUI process.

	, EVENTLOG_FILE_CORRUPT =
#	if defined ERROR_EVENTLOG_FILE_CORRUPT
			ERROR_EVENTLOG_FILE_CORRUPT
#	else
				0x5DC
#	endif
		// The event log file is corrupted.

	, EVENTLOG_CANT_START =
#	if defined ERROR_EVENTLOG_CANT_START
			ERROR_EVENTLOG_CANT_START
#	else
				0x5DD
#	endif
		// No event log file could be opened, so the event logging service did not start.

	, LOG_FILE_FULL =
#	if defined ERROR_LOG_FILE_FULL
			ERROR_LOG_FILE_FULL
#	else
				0x5DE
#	endif
		// The event log file is full.

	, EVENTLOG_FILE_CHANGED =
#	if defined ERROR_EVENTLOG_FILE_CHANGED
			ERROR_EVENTLOG_FILE_CHANGED
#	else
				0x5DF
#	endif
		// The event log file has changed between read operations.

	, INVALID_TASK_NAME =
#	if defined ERROR_INVALID_TASK_NAME
			ERROR_INVALID_TASK_NAME
#	else
				0x60E
#	endif
		// The specified task name is invalid.

	, INVALID_TASK_INDEX =
#	if defined ERROR_INVALID_TASK_INDEX
			ERROR_INVALID_TASK_INDEX
#	else
				0x60F
#	endif
		// The specified task index is invalid.

	, THREAD_ALREADY_IN_TASK =
#	if defined ERROR_THREAD_ALREADY_IN_TASK
			ERROR_THREAD_ALREADY_IN_TASK
#	else
				0x610
#	endif
		// The specified thread is already joining a task.

	, INSTALL_SERVICE_FAILURE =
#	if defined ERROR_INSTALL_SERVICE_FAILURE
			ERROR_INSTALL_SERVICE_FAILURE
#	else
				0x641
#	endif
		// The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.

	, INSTALL_USEREXIT =
#	if defined ERROR_INSTALL_USEREXIT
			ERROR_INSTALL_USEREXIT
#	else
				0x642
#	endif
		// User cancelled installation.

	, INSTALL_FAILURE =
#	if defined ERROR_INSTALL_FAILURE
			ERROR_INSTALL_FAILURE
#	else
				0x643
#	endif
		// Fatal error during installation.

	, INSTALL_SUSPEND =
#	if defined ERROR_INSTALL_SUSPEND
			ERROR_INSTALL_SUSPEND
#	else
				0x644
#	endif
		// Installation suspended, incomplete.

	, UNKNOWN_PRODUCT =
#	if defined ERROR_UNKNOWN_PRODUCT
			ERROR_UNKNOWN_PRODUCT
#	else
				0x645
#	endif
		// This action is only valid for products that are currently installed.

	, UNKNOWN_FEATURE =
#	if defined ERROR_UNKNOWN_FEATURE
			ERROR_UNKNOWN_FEATURE
#	else
				0x646
#	endif
		// Feature ID not registered.

	, UNKNOWN_COMPONENT =
#	if defined ERROR_UNKNOWN_COMPONENT
			ERROR_UNKNOWN_COMPONENT
#	else
				0x647
#	endif
		// Component ID not registered.

	, UNKNOWN_PROPERTY =
#	if defined ERROR_UNKNOWN_PROPERTY
			ERROR_UNKNOWN_PROPERTY
#	else
				0x648
#	endif
		// Unknown property.

	, INVALID_HANDLE_STATE =
#	if defined ERROR_INVALID_HANDLE_STATE
			ERROR_INVALID_HANDLE_STATE
#	else
				0x649
#	endif
		// Handle is in an invalid state.

	, BAD_CONFIGURATION =
#	if defined ERROR_BAD_CONFIGURATION
			ERROR_BAD_CONFIGURATION
#	else
				0x64A
#	endif
		// The configuration data for this product is corrupt. Contact your support personnel.

	, INDEX_ABSENT =
#	if defined ERROR_INDEX_ABSENT
			ERROR_INDEX_ABSENT
#	else
				0x64B
#	endif
		// Component qualifier not present.

	, INSTALL_SOURCE_ABSENT =
#	if defined ERROR_INSTALL_SOURCE_ABSENT
			ERROR_INSTALL_SOURCE_ABSENT
#	else
				0x64C
#	endif
		// The installation source for this product is not available. Verify that the source exists and that you can access it.

	, INSTALL_PACKAGE_VERSION =
#	if defined ERROR_INSTALL_PACKAGE_VERSION
			ERROR_INSTALL_PACKAGE_VERSION
#	else
				0x64D
#	endif
		// This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.

	, PRODUCT_UNINSTALLED =
#	if defined ERROR_PRODUCT_UNINSTALLED
			ERROR_PRODUCT_UNINSTALLED
#	else
				0x64E
#	endif
		// Product is uninstalled.

	, BAD_QUERY_SYNTAX =
#	if defined ERROR_BAD_QUERY_SYNTAX
			ERROR_BAD_QUERY_SYNTAX
#	else
				0x64F
#	endif
		// SQL query syntax invalid or unsupported.

	, INVALID_FIELD =
#	if defined ERROR_INVALID_FIELD
			ERROR_INVALID_FIELD
#	else
				0x650
#	endif
		// Record field does not exist.

	, DEVICE_REMOVED =
#	if defined ERROR_DEVICE_REMOVED
			ERROR_DEVICE_REMOVED
#	else
				0x651
#	endif
		// The device has been removed.

	, INSTALL_ALREADY_RUNNING =
#	if defined ERROR_INSTALL_ALREADY_RUNNING
			ERROR_INSTALL_ALREADY_RUNNING
#	else
				0x652
#	endif
		// Another installation is already in progress. Complete that installation before proceeding with this install.

	, INSTALL_PACKAGE_OPEN_FAILED =
#	if defined ERROR_INSTALL_PACKAGE_OPEN_FAILED
			ERROR_INSTALL_PACKAGE_OPEN_FAILED
#	else
				0x653
#	endif
		// This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.

	, INSTALL_PACKAGE_INVALID =
#	if defined ERROR_INSTALL_PACKAGE_INVALID
			ERROR_INSTALL_PACKAGE_INVALID
#	else
				0x654
#	endif
		// This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.

	, INSTALL_UI_FAILURE =
#	if defined ERROR_INSTALL_UI_FAILURE
			ERROR_INSTALL_UI_FAILURE
#	else
				0x655
#	endif
		// There was an error starting the Windows Installer service user interface. Contact your support personnel.

	, INSTALL_LOG_FAILURE =
#	if defined ERROR_INSTALL_LOG_FAILURE
			ERROR_INSTALL_LOG_FAILURE
#	else
				0x656
#	endif
		// Error opening installation log file. Verify that the specified log file location exists and that you can write to it.

	, INSTALL_LANGUAGE_UNSUPPORTED =
#	if defined ERROR_INSTALL_LANGUAGE_UNSUPPORTED
			ERROR_INSTALL_LANGUAGE_UNSUPPORTED
#	else
				0x657
#	endif
		// The language of this installation package is not supported by your system.

	, INSTALL_TRANSFORM_FAILURE =
#	if defined ERROR_INSTALL_TRANSFORM_FAILURE
			ERROR_INSTALL_TRANSFORM_FAILURE
#	else
				0x658
#	endif
		// Error applying transforms. Verify that the specified transform paths are valid.

	, INSTALL_PACKAGE_REJECTED =
#	if defined ERROR_INSTALL_PACKAGE_REJECTED
			ERROR_INSTALL_PACKAGE_REJECTED
#	else
				0x659
#	endif
		// This installation is forbidden by system policy. Contact your system administrator.

	, FUNCTION_NOT_CALLED =
#	if defined ERROR_FUNCTION_NOT_CALLED
			ERROR_FUNCTION_NOT_CALLED
#	else
				0x65A
#	endif
		// Function could not be executed.

	, FUNCTION_FAILED =
#	if defined ERROR_FUNCTION_FAILED
			ERROR_FUNCTION_FAILED
#	else
				0x65B
#	endif
		// Function failed during execution.

	, INVALID_TABLE =
#	if defined ERROR_INVALID_TABLE
			ERROR_INVALID_TABLE
#	else
				0x65C
#	endif
		// Invalid or unknown table specified.

	, DATATYPE_MISMATCH =
#	if defined ERROR_DATATYPE_MISMATCH
			ERROR_DATATYPE_MISMATCH
#	else
				0x65D
#	endif
		// Data supplied is of wrong type.

	, UNSUPPORTED_TYPE =
#	if defined ERROR_UNSUPPORTED_TYPE
			ERROR_UNSUPPORTED_TYPE
#	else
				0x65E
#	endif
		// Data of this type is not supported.

	, CREATE_FAILED =
#	if defined ERROR_CREATE_FAILED
			ERROR_CREATE_FAILED
#	else
				0x65F
#	endif
		// The Windows Installer service failed to start. Contact your support personnel.

	, INSTALL_TEMP_UNWRITABLE =
#	if defined ERROR_INSTALL_TEMP_UNWRITABLE
			ERROR_INSTALL_TEMP_UNWRITABLE
#	else
				0x660
#	endif
		// The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.

	, INSTALL_PLATFORM_UNSUPPORTED =
#	if defined ERROR_INSTALL_PLATFORM_UNSUPPORTED
			ERROR_INSTALL_PLATFORM_UNSUPPORTED
#	else
				0x661
#	endif
		// This installation package is not supported by this processor type. Contact your product vendor.

	, INSTALL_NOTUSED =
#	if defined ERROR_INSTALL_NOTUSED
			ERROR_INSTALL_NOTUSED
#	else
				0x662
#	endif
		// Component not used on this computer.

	, PATCH_PACKAGE_OPEN_FAILED =
#	if defined ERROR_PATCH_PACKAGE_OPEN_FAILED
			ERROR_PATCH_PACKAGE_OPEN_FAILED
#	else
				0x663
#	endif
		// This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.

	, PATCH_PACKAGE_INVALID =
#	if defined ERROR_PATCH_PACKAGE_INVALID
			ERROR_PATCH_PACKAGE_INVALID
#	else
				0x664
#	endif
		// This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.

	, PATCH_PACKAGE_UNSUPPORTED =
#	if defined ERROR_PATCH_PACKAGE_UNSUPPORTED
			ERROR_PATCH_PACKAGE_UNSUPPORTED
#	else
				0x665
#	endif
		// This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.

	, PRODUCT_VERSION =
#	if defined ERROR_PRODUCT_VERSION
			ERROR_PRODUCT_VERSION
#	else
				0x666
#	endif
		// Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.

	, INVALID_COMMAND_LINE =
#	if defined ERROR_INVALID_COMMAND_LINE
			ERROR_INVALID_COMMAND_LINE
#	else
				0x667
#	endif
		// Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.

	, INSTALL_REMOTE_DISALLOWED =
#	if defined ERROR_INSTALL_REMOTE_DISALLOWED
			ERROR_INSTALL_REMOTE_DISALLOWED
#	else
				0x668
#	endif
		// Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.

	, SUCCESS_REBOOT_INITIATED =
#	if defined ERROR_SUCCESS_REBOOT_INITIATED
			ERROR_SUCCESS_REBOOT_INITIATED
#	else
				0x669
#	endif
		// The requested operation completed successfully. The system will be restarted so the changes can take effect.

	, PATCH_TARGET_NOT_FOUND =
#	if defined ERROR_PATCH_TARGET_NOT_FOUND
			ERROR_PATCH_TARGET_NOT_FOUND
#	else
				0x66A
#	endif
		// The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.

	, PATCH_PACKAGE_REJECTED =
#	if defined ERROR_PATCH_PACKAGE_REJECTED
			ERROR_PATCH_PACKAGE_REJECTED
#	else
				0x66B
#	endif
		// The update package is not permitted by software restriction policy.

	, INSTALL_TRANSFORM_REJECTED =
#	if defined ERROR_INSTALL_TRANSFORM_REJECTED
			ERROR_INSTALL_TRANSFORM_REJECTED
#	else
				0x66C
#	endif
		// One or more customizations are not permitted by software restriction policy.

	, INSTALL_REMOTE_PROHIBITED =
#	if defined ERROR_INSTALL_REMOTE_PROHIBITED
			ERROR_INSTALL_REMOTE_PROHIBITED
#	else
				0x66D
#	endif
		// The Windows Installer does not permit installation from a Remote Desktop Connection.

	, PATCH_REMOVAL_UNSUPPORTED =
#	if defined ERROR_PATCH_REMOVAL_UNSUPPORTED
			ERROR_PATCH_REMOVAL_UNSUPPORTED
#	else
				0x66E
#	endif
		// Uninstallation of the update package is not supported.

	, UNKNOWN_PATCH =
#	if defined ERROR_UNKNOWN_PATCH
			ERROR_UNKNOWN_PATCH
#	else
				0x66F
#	endif
		// The update is not applied to this product.

	, PATCH_NO_SEQUENCE =
#	if defined ERROR_PATCH_NO_SEQUENCE
			ERROR_PATCH_NO_SEQUENCE
#	else
				0x670
#	endif
		// No valid sequence could be found for the set of updates.

	, PATCH_REMOVAL_DISALLOWED =
#	if defined ERROR_PATCH_REMOVAL_DISALLOWED
			ERROR_PATCH_REMOVAL_DISALLOWED
#	else
				0x671
#	endif
		// Update removal was disallowed by policy.

	, INVALID_PATCH_XML =
#	if defined ERROR_INVALID_PATCH_XML
			ERROR_INVALID_PATCH_XML
#	else
				0x672
#	endif
		// The XML update data is invalid.

	, PATCH_MANAGED_ADVERTISED_PRODUCT =
#	if defined ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT
			ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT
#	else
				0x673
#	endif
		// Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.

	, INSTALL_SERVICE_SAFEBOOT =
#	if defined ERROR_INSTALL_SERVICE_SAFEBOOT
			ERROR_INSTALL_SERVICE_SAFEBOOT
#	else
				0x674
#	endif
		// The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.

	, FAIL_FAST_EXCEPTION =
#	if defined ERROR_FAIL_FAST_EXCEPTION
			ERROR_FAIL_FAST_EXCEPTION
#	else
				0x675
#	endif
		// A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.

	, INSTALL_REJECTED =
#	if defined ERROR_INSTALL_REJECTED
			ERROR_INSTALL_REJECTED
#	else
				0x676
#	endif
		// The app that you are trying to run is not supported on this version of Windows.


};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString3(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::NOT_ALL_ASSIGNED:
			RETURN_STATIC_STRING(
					"Not all privileges or groups referenced are assigned to the caller"
			);
		case SystemCode::SOME_NOT_MAPPED:
			RETURN_STATIC_STRING(
					"Some mapping between account names and security IDs was not done"
			);
		case SystemCode::NO_QUOTAS_FOR_ACCOUNT:
			RETURN_STATIC_STRING(
					"No system quota limits are specifically set for this account"
			);
		case SystemCode::LOCAL_USER_SESSION_KEY:
			RETURN_STATIC_STRING(
					"No encryption key is available. A well-known encryption key was returned"
			);
		case SystemCode::NULL_LM_PASSWORD:
			RETURN_STATIC_STRING(
					"The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string"
			);
		case SystemCode::UNKNOWN_REVISION:
			RETURN_STATIC_STRING(
					"The revision level is unknown"
			);
		case SystemCode::REVISION_MISMATCH:
			RETURN_STATIC_STRING(
					"Indicates two revision levels are incompatible"
			);
		case SystemCode::INVALID_OWNER:
			RETURN_STATIC_STRING(
					"This security ID may not be assigned as the owner of this object"
			);
		case SystemCode::INVALID_PRIMARY_GROUP:
			RETURN_STATIC_STRING(
					"This security ID may not be assigned as the primary group of an object"
			);
		case SystemCode::NO_IMPERSONATION_TOKEN:
			RETURN_STATIC_STRING(
					"An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client"
			);
		case SystemCode::CANT_DISABLE_MANDATORY:
			RETURN_STATIC_STRING(
					"The group may not be disabled"
			);
		case SystemCode::NO_LOGON_SERVERS:
			RETURN_STATIC_STRING(
					"There are currently no logon servers available to service the logon request"
			);
		case SystemCode::NO_SUCH_LOGON_SESSION:
			RETURN_STATIC_STRING(
					"A specified logon session does not exist. It may already have been terminated"
			);
		case SystemCode::NO_SUCH_PRIVILEGE:
			RETURN_STATIC_STRING(
					"A specified privilege does not exist"
			);
		case SystemCode::PRIVILEGE_NOT_HELD:
			RETURN_STATIC_STRING(
					"A required privilege is not held by the client"
			);
		case SystemCode::INVALID_ACCOUNT_NAME:
			RETURN_STATIC_STRING(
					"The name provided is not a properly formed account name"
			);
		case SystemCode::USER_EXISTS:
			RETURN_STATIC_STRING(
					"The specified account already exists"
			);
		case SystemCode::NO_SUCH_USER:
			RETURN_STATIC_STRING(
					"The specified account does not exist"
			);
		case SystemCode::GROUP_EXISTS:
			RETURN_STATIC_STRING(
					"The specified group already exists"
			);
		case SystemCode::NO_SUCH_GROUP:
			RETURN_STATIC_STRING(
					"The specified group does not exist"
			);
		case SystemCode::MEMBER_IN_GROUP:
			RETURN_STATIC_STRING(
					"Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member"
			);
		case SystemCode::MEMBER_NOT_IN_GROUP:
			RETURN_STATIC_STRING(
					"The specified user account is not a member of the specified group account"
			);
		case SystemCode::LAST_ADMIN:
			RETURN_STATIC_STRING(
					"This operation is disallowed as it could result in an administration account being disabled, deleted or unable to log on"
			);
		case SystemCode::WRONG_PASSWORD:
			RETURN_STATIC_STRING(
					"Unable to update the password. The value provided as the current password is incorrect"
			);
		case SystemCode::ILL_FORMED_PASSWORD:
			RETURN_STATIC_STRING(
					"Unable to update the password. The value provided for the new password contains values that are not allowed in passwords"
			);
		case SystemCode::PASSWORD_RESTRICTION:
			RETURN_STATIC_STRING(
					"Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain"
			);
		case SystemCode::LOGON_FAILURE:
			RETURN_STATIC_STRING(
					"The user name or password is incorrect"
			);
		case SystemCode::ACCOUNT_RESTRICTION:
			RETURN_STATIC_STRING(
					"Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced"
			);
		case SystemCode::INVALID_LOGON_HOURS:
			RETURN_STATIC_STRING(
					"Your account has time restrictions that keep you from signing in right now"
			);
		case SystemCode::INVALID_WORKSTATION:
			RETURN_STATIC_STRING(
					"This user isn't allowed to sign in to this computer"
			);
		case SystemCode::PASSWORD_EXPIRED:
			RETURN_STATIC_STRING(
					"The password for this account has expired"
			);
		case SystemCode::ACCOUNT_DISABLED:
			RETURN_STATIC_STRING(
					"This user can't sign in because this account is currently disabled"
			);
		case SystemCode::NONE_MAPPED:
			RETURN_STATIC_STRING(
					"No mapping between account names and security IDs was done"
			);
		case SystemCode::TOO_MANY_LUIDS_REQUESTED:
			RETURN_STATIC_STRING(
					"Too many local user identifiers (LUIDs) were requested at one time"
			);
		case SystemCode::LUIDS_EXHAUSTED:
			RETURN_STATIC_STRING(
					"No more local user identifiers (LUIDs) are available"
			);
		case SystemCode::INVALID_SUB_AUTHORITY:
			RETURN_STATIC_STRING(
					"The subauthority part of a security ID is invalid for this particular use"
			);
		case SystemCode::INVALID_ACL:
			RETURN_STATIC_STRING(
					"The access control list (ACL) structure is invalid"
			);
		case SystemCode::INVALID_SID:
			RETURN_STATIC_STRING(
					"The security ID structure is invalid"
			);
		case SystemCode::INVALID_SECURITY_DESCR:
			RETURN_STATIC_STRING(
					"The security descriptor structure is invalid"
			);
		case SystemCode::BAD_INHERITANCE_ACL:
			RETURN_STATIC_STRING(
					"The inherited access control list (ACL) or access control entry (ACE) could not be built"
			);
		case SystemCode::SERVER_DISABLED:
			RETURN_STATIC_STRING(
					"The server is currently disabled"
			);
		case SystemCode::SERVER_NOT_DISABLED:
			RETURN_STATIC_STRING(
					"The server is currently enabled"
			);
		case SystemCode::INVALID_ID_AUTHORITY:
			RETURN_STATIC_STRING(
					"The value provided was an invalid value for an identifier authority"
			);
		case SystemCode::ALLOTTED_SPACE_EXCEEDED:
			RETURN_STATIC_STRING(
					"No more memory is available for security information updates"
			);
		case SystemCode::INVALID_GROUP_ATTRIBUTES:
			RETURN_STATIC_STRING(
					"The specified attributes are invalid, or incompatible with the attributes for the group as a whole"
			);
		case SystemCode::BAD_IMPERSONATION_LEVEL:
			RETURN_STATIC_STRING(
					"Either a required impersonation level was not provided, or the provided impersonation level is invalid"
			);
		case SystemCode::CANT_OPEN_ANONYMOUS:
			RETURN_STATIC_STRING(
					"Cannot open an anonymous level security token"
			);
		case SystemCode::BAD_VALIDATION_CLASS:
			RETURN_STATIC_STRING(
					"The validation information class requested was invalid"
			);
		case SystemCode::BAD_TOKEN_TYPE:
			RETURN_STATIC_STRING(
					"The type of the token is inappropriate for its attempted use"
			);
		case SystemCode::NO_SECURITY_ON_OBJECT:
			RETURN_STATIC_STRING(
					"Unable to perform a security operation on an object that has no associated security"
			);
		case SystemCode::CANT_ACCESS_DOMAIN_INFO:
			RETURN_STATIC_STRING(
					"Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied"
			);
		case SystemCode::INVALID_SERVER_STATE:
			RETURN_STATIC_STRING(
					"The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation"
			);
		case SystemCode::INVALID_DOMAIN_STATE:
			RETURN_STATIC_STRING(
					"The domain was in the wrong state to perform the security operation"
			);
		case SystemCode::INVALID_DOMAIN_ROLE:
			RETURN_STATIC_STRING(
					"This operation is only allowed for the Primary Domain Controller of the domain"
			);
		case SystemCode::NO_SUCH_DOMAIN:
			RETURN_STATIC_STRING(
					"The specified domain either does not exist or could not be contacted"
			);
		case SystemCode::DOMAIN_EXISTS:
			RETURN_STATIC_STRING(
					"The specified domain already exists"
			);
		case SystemCode::DOMAIN_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"An attempt was made to exceed the limit on the number of domains per server"
			);
		case SystemCode::INTERNAL_DB_CORRUPTION:
			RETURN_STATIC_STRING(
					"Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk"
			);
		case SystemCode::INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"An internal error occurred"
			);
		case SystemCode::GENERIC_NOT_MAPPED:
			RETURN_STATIC_STRING(
					"Generic access types were contained in an access mask which should already be mapped to nongeneric types"
			);
		case SystemCode::BAD_DESCRIPTOR_FORMAT:
			RETURN_STATIC_STRING(
					"A security descriptor is not in the right format (absolute or self-relative)"
			);
		case SystemCode::NOT_LOGON_PROCESS:
			RETURN_STATIC_STRING(
					"The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process"
			);
		case SystemCode::LOGON_SESSION_EXISTS:
			RETURN_STATIC_STRING(
					"Cannot start a new logon session with an ID that is already in use"
			);
		case SystemCode::NO_SUCH_PACKAGE:
			RETURN_STATIC_STRING(
					"A specified authentication package is unknown"
			);
		case SystemCode::BAD_LOGON_SESSION_STATE:
			RETURN_STATIC_STRING(
					"The logon session is not in a state that is consistent with the requested operation"
			);
		case SystemCode::LOGON_SESSION_COLLISION:
			RETURN_STATIC_STRING(
					"The logon session ID is already in use"
			);
		case SystemCode::INVALID_LOGON_TYPE:
			RETURN_STATIC_STRING(
					"A logon request contained an invalid logon type value"
			);
		case SystemCode::CANNOT_IMPERSONATE:
			RETURN_STATIC_STRING(
					"Unable to impersonate using a named pipe until data has been read from that pipe"
			);
		case SystemCode::RXACT_INVALID_STATE:
			RETURN_STATIC_STRING(
					"The transaction state of a registry subtree is incompatible with the requested operation"
			);
		case SystemCode::RXACT_COMMIT_FAILURE:
			RETURN_STATIC_STRING(
					"An internal security database corruption has been encountered"
			);
		case SystemCode::SPECIAL_ACCOUNT:
			RETURN_STATIC_STRING(
					"Cannot perform this operation on built-in accounts"
			);
		case SystemCode::SPECIAL_GROUP:
			RETURN_STATIC_STRING(
					"Cannot perform this operation on this built-in special group"
			);
		case SystemCode::SPECIAL_USER:
			RETURN_STATIC_STRING(
					"Cannot perform this operation on this built-in special user"
			);
		case SystemCode::MEMBERS_PRIMARY_GROUP:
			RETURN_STATIC_STRING(
					"The user cannot be removed from a group because the group is currently the user's primary group"
			);
		case SystemCode::TOKEN_ALREADY_IN_USE:
			RETURN_STATIC_STRING(
					"The token is already in use as a primary token"
			);
		case SystemCode::NO_SUCH_ALIAS:
			RETURN_STATIC_STRING(
					"The specified local group does not exist"
			);
		case SystemCode::MEMBER_NOT_IN_ALIAS:
			RETURN_STATIC_STRING(
					"The specified account name is not a member of the group"
			);
		case SystemCode::MEMBER_IN_ALIAS:
			RETURN_STATIC_STRING(
					"The specified account name is already a member of the group"
			);
		case SystemCode::ALIAS_EXISTS:
			RETURN_STATIC_STRING(
					"The specified local group already exists"
			);
		case SystemCode::LOGON_NOT_GRANTED:
			RETURN_STATIC_STRING(
					"Logon failure: the user has not been granted the requested logon type at this computer"
			);
		case SystemCode::TOO_MANY_SECRETS:
			RETURN_STATIC_STRING(
					"The maximum number of secrets that may be stored in a single system has been exceeded"
			);
		case SystemCode::SECRET_TOO_LONG:
			RETURN_STATIC_STRING(
					"The length of a secret exceeds the maximum length allowed"
			);
		case SystemCode::INTERNAL_DB_ERROR:
			RETURN_STATIC_STRING(
					"The local security authority database contains an internal inconsistency"
			);
		case SystemCode::TOO_MANY_CONTEXT_IDS:
			RETURN_STATIC_STRING(
					"During a logon attempt, the user's security context accumulated too many security IDs"
			);
		case SystemCode::LOGON_TYPE_NOT_GRANTED:
			RETURN_STATIC_STRING(
					"Logon failure: the user has not been granted the requested logon type at this computer"
			);
		case SystemCode::NT_CROSS_ENCRYPTION_REQUIRED:
			RETURN_STATIC_STRING(
					"A cross-encrypted password is necessary to change a user password"
			);
		case SystemCode::NO_SUCH_MEMBER:
			RETURN_STATIC_STRING(
					"A member could not be added to or removed from the local group because the member does not exist"
			);
		case SystemCode::INVALID_MEMBER:
			RETURN_STATIC_STRING(
					"A new member could not be added to a local group because the member has the wrong account type"
			);
		case SystemCode::TOO_MANY_SIDS:
			RETURN_STATIC_STRING(
					"Too many security IDs have been specified"
			);
		case SystemCode::LM_CROSS_ENCRYPTION_REQUIRED:
			RETURN_STATIC_STRING(
					"A cross-encrypted password is necessary to change this user password"
			);
		case SystemCode::NO_INHERITANCE:
			RETURN_STATIC_STRING(
					"Indicates an ACL contains no inheritable components"
			);
		case SystemCode::FILE_CORRUPT:
			RETURN_STATIC_STRING(
					"The file or directory is corrupted and unreadable"
			);
		case SystemCode::DISK_CORRUPT:
			RETURN_STATIC_STRING(
					"The disk structure is corrupted and unreadable"
			);
		case SystemCode::NO_USER_SESSION_KEY:
			RETURN_STATIC_STRING(
					"There is no user session key for the specified logon session"
			);
		case SystemCode::LICENSE_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept"
			);
		case SystemCode::WRONG_TARGET_NAME:
			RETURN_STATIC_STRING(
					"The target account name is incorrect"
			);
		case SystemCode::MUTUAL_AUTH_FAILED:
			RETURN_STATIC_STRING(
					"Mutual Authentication failed. The server's password is out of date at the domain controller"
			);
		case SystemCode::TIME_SKEW:
			RETURN_STATIC_STRING(
					"There is a time and/or date difference between the client and server"
			);
		case SystemCode::CURRENT_DOMAIN_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"This operation cannot be performed on the current domain"
			);
		case SystemCode::INVALID_WINDOW_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid window handle"
			);
		case SystemCode::INVALID_MENU_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid menu handle"
			);
		case SystemCode::INVALID_CURSOR_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid cursor handle"
			);
		case SystemCode::INVALID_ACCEL_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid accelerator table handle"
			);
		case SystemCode::INVALID_HOOK_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid hook handle"
			);
		case SystemCode::INVALID_DWP_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid handle to a multiple-window position structure"
			);
		case SystemCode::TLW_WITH_WSCHILD:
			RETURN_STATIC_STRING(
					"Cannot create a top-level child window"
			);
		case SystemCode::CANNOT_FIND_WND_CLASS:
			RETURN_STATIC_STRING(
					"Cannot find window class"
			);
		case SystemCode::WINDOW_OF_OTHER_THREAD:
			RETURN_STATIC_STRING(
					"Invalid window; it belongs to other thread"
			);
		case SystemCode::HOTKEY_ALREADY_REGISTERED:
			RETURN_STATIC_STRING(
					"Hot key is already registered"
			);
		case SystemCode::CLASS_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"Class already exists"
			);
		case SystemCode::CLASS_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"Class does not exist"
			);
		case SystemCode::CLASS_HAS_WINDOWS:
			RETURN_STATIC_STRING(
					"Class still has open windows"
			);
		case SystemCode::INVALID_INDEX:
			RETURN_STATIC_STRING(
					"Invalid index"
			);
		case SystemCode::INVALID_ICON_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid icon handle"
			);
		case SystemCode::PRIVATE_DIALOG_INDEX:
			RETURN_STATIC_STRING(
					"Using private DIALOG window words"
			);
		case SystemCode::LISTBOX_ID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The list box identifier was not found"
			);
		case SystemCode::NO_WILDCARD_CHARACTERS:
			RETURN_STATIC_STRING(
					"No wildcards were found"
			);
		case SystemCode::CLIPBOARD_NOT_OPEN:
			RETURN_STATIC_STRING(
					"Thread does not have a clipboard open"
			);
		case SystemCode::HOTKEY_NOT_REGISTERED:
			RETURN_STATIC_STRING(
					"Hot key is not registered"
			);
		case SystemCode::WINDOW_NOT_DIALOG:
			RETURN_STATIC_STRING(
					"The window is not a valid dialog window"
			);
		case SystemCode::CONTROL_ID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Control ID not found"
			);
		case SystemCode::INVALID_COMBOBOX_MESSAGE:
			RETURN_STATIC_STRING(
					"Invalid message for a combo box because it does not have an edit control"
			);
		case SystemCode::WINDOW_NOT_COMBOBOX:
			RETURN_STATIC_STRING(
					"The window is not a combo box"
			);
		case SystemCode::INVALID_EDIT_HEIGHT:
			RETURN_STATIC_STRING(
					"Height must be less than 256"
			);
		case SystemCode::DC_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Invalid device context (DC) handle"
			);
		case SystemCode::INVALID_HOOK_FILTER:
			RETURN_STATIC_STRING(
					"Invalid hook procedure type"
			);
		case SystemCode::INVALID_FILTER_PROC:
			RETURN_STATIC_STRING(
					"Invalid hook procedure"
			);
		case SystemCode::HOOK_NEEDS_HMOD:
			RETURN_STATIC_STRING(
					"Cannot set nonlocal hook without a module handle"
			);
		case SystemCode::GLOBAL_ONLY_HOOK:
			RETURN_STATIC_STRING(
					"This hook procedure can only be set globally"
			);
		case SystemCode::JOURNAL_HOOK_SET:
			RETURN_STATIC_STRING(
					"The journal hook procedure is already installed"
			);
		case SystemCode::HOOK_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"The hook procedure is not installed"
			);
		case SystemCode::INVALID_LB_MESSAGE:
			RETURN_STATIC_STRING(
					"Invalid message for single-selection list box"
			);
		case SystemCode::SETCOUNT_ON_BAD_LB:
			RETURN_STATIC_STRING(
					"LB_SETCOUNT sent to non-lazy list box"
			);
		case SystemCode::LB_WITHOUT_TABSTOPS:
			RETURN_STATIC_STRING(
					"This list box does not support tab stops"
			);
		case SystemCode::DESTROY_OBJECT_OF_OTHER_THREAD:
			RETURN_STATIC_STRING(
					"Cannot destroy object created by another thread"
			);
		case SystemCode::CHILD_WINDOW_MENU:
			RETURN_STATIC_STRING(
					"Child windows cannot have menus"
			);
		case SystemCode::NO_SYSTEM_MENU:
			RETURN_STATIC_STRING(
					"The window does not have a system menu"
			);
		case SystemCode::INVALID_MSGBOX_STYLE:
			RETURN_STATIC_STRING(
					"Invalid message box style"
			);
		case SystemCode::INVALID_SPI_VALUE:
			RETURN_STATIC_STRING(
					"Invalid system-wide (SPI_*) parameter"
			);
		case SystemCode::SCREEN_ALREADY_LOCKED:
			RETURN_STATIC_STRING(
					"Screen already locked"
			);
		case SystemCode::HWNDS_HAVE_DIFF_PARENT:
			RETURN_STATIC_STRING(
					"All handles to windows in a multiple-window position structure must have the same parent"
			);
		case SystemCode::NOT_CHILD_WINDOW:
			RETURN_STATIC_STRING(
					"The window is not a child window"
			);
		case SystemCode::INVALID_GW_COMMAND:
			RETURN_STATIC_STRING(
					"Invalid GW_* command"
			);
		case SystemCode::INVALID_THREAD_ID:
			RETURN_STATIC_STRING(
					"Invalid thread identifier"
			);
		case SystemCode::NON_MDICHILD_WINDOW:
			RETURN_STATIC_STRING(
					"Cannot process a message from a window that is not a multiple document interface (MDI) window"
			);
		case SystemCode::POPUP_ALREADY_ACTIVE:
			RETURN_STATIC_STRING(
					"Popup menu already active"
			);
		case SystemCode::NO_SCROLLBARS:
			RETURN_STATIC_STRING(
					"The window does not have scroll bars"
			);
		case SystemCode::INVALID_SCROLLBAR_RANGE:
			RETURN_STATIC_STRING(
					"Scroll bar range cannot be greater than MAXLONG"
			);
		case SystemCode::INVALID_SHOWWIN_COMMAND:
			RETURN_STATIC_STRING(
					"Cannot show or remove the window in the way specified"
			);
		case SystemCode::NO_SYSTEM_RESOURCES:
			RETURN_STATIC_STRING(
					"Insufficient system resources exist to complete the requested service"
			);
		case SystemCode::NONPAGED_SYSTEM_RESOURCES:
			RETURN_STATIC_STRING(
					"Insufficient system resources exist to complete the requested service"
			);
		case SystemCode::PAGED_SYSTEM_RESOURCES:
			RETURN_STATIC_STRING(
					"Insufficient system resources exist to complete the requested service"
			);
		case SystemCode::WORKING_SET_QUOTA:
			RETURN_STATIC_STRING(
					"Insufficient quota to complete the requested service"
			);
		case SystemCode::PAGEFILE_QUOTA:
			RETURN_STATIC_STRING(
					"Insufficient quota to complete the requested service"
			);
		case SystemCode::COMMITMENT_LIMIT:
			RETURN_STATIC_STRING(
					"The paging file is too small for this operation to complete"
			);
		case SystemCode::MENU_ITEM_NOT_FOUND:
			RETURN_STATIC_STRING(
					"A menu item was not found"
			);
		case SystemCode::INVALID_KEYBOARD_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid keyboard layout handle"
			);
		case SystemCode::HOOK_TYPE_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"Hook type not allowed"
			);
		case SystemCode::REQUIRES_INTERACTIVE_WINDOWSTATION:
			RETURN_STATIC_STRING(
					"This operation requires an interactive window station"
			);
		case SystemCode::TIMEOUT:
			RETURN_STATIC_STRING(
					"This operation returned because the timeout period expired"
			);
		case SystemCode::INVALID_MONITOR_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid monitor handle"
			);
		case SystemCode::INCORRECT_SIZE:
			RETURN_STATIC_STRING(
					"Incorrect size argument"
			);
		case SystemCode::SYMLINK_CLASS_DISABLED:
			RETURN_STATIC_STRING(
					"The symbolic link cannot be followed because its type is disabled"
			);
		case SystemCode::SYMLINK_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"This application does not support the current operation on symbolic links"
			);
		case SystemCode::XML_PARSE_ERROR:
			RETURN_STATIC_STRING(
					"Windows was unable to parse the requested XML data"
			);
		case SystemCode::XMLDSIG_ERROR:
			RETURN_STATIC_STRING(
					"An error was encountered while processing an XML digital signature"
			);
		case SystemCode::RESTART_APPLICATION:
			RETURN_STATIC_STRING(
					"This application must be restarted"
			);
		case SystemCode::WRONG_COMPARTMENT:
			RETURN_STATIC_STRING(
					"The caller made the connection request in the wrong routing compartment"
			);
		case SystemCode::AUTHIP_FAILURE:
			RETURN_STATIC_STRING(
					"There was an AuthIP failure when attempting to connect to the remote host"
			);
		case SystemCode::NO_NVRAM_RESOURCES:
			RETURN_STATIC_STRING(
					"Insufficient NVRAM resources exist to complete the requested service. A reboot might be required"
			);
		case SystemCode::NOT_GUI_PROCESS:
			RETURN_STATIC_STRING(
					"Unable to finish the requested operation because the specified process is not a GUI process"
			);
		case SystemCode::EVENTLOG_FILE_CORRUPT:
			RETURN_STATIC_STRING(
					"The event log file is corrupted"
			);
		case SystemCode::EVENTLOG_CANT_START:
			RETURN_STATIC_STRING(
					"No event log file could be opened, so the event logging service did not start"
			);
		case SystemCode::LOG_FILE_FULL:
			RETURN_STATIC_STRING(
					"The event log file is full"
			);
		case SystemCode::EVENTLOG_FILE_CHANGED:
			RETURN_STATIC_STRING(
					"The event log file has changed between read operations"
			);
		case SystemCode::INVALID_TASK_NAME:
			RETURN_STATIC_STRING(
					"The specified task name is invalid"
			);
		case SystemCode::INVALID_TASK_INDEX:
			RETURN_STATIC_STRING(
					"The specified task index is invalid"
			);
		case SystemCode::THREAD_ALREADY_IN_TASK:
			RETURN_STATIC_STRING(
					"The specified thread is already joining a task"
			);
		case SystemCode::INSTALL_SERVICE_FAILURE:
			RETURN_STATIC_STRING(
					"The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance"
			);
		case SystemCode::INSTALL_USEREXIT:
			RETURN_STATIC_STRING(
					"User cancelled installation"
			);
		case SystemCode::INSTALL_FAILURE:
			RETURN_STATIC_STRING(
					"Fatal error during installation"
			);
		case SystemCode::INSTALL_SUSPEND:
			RETURN_STATIC_STRING(
					"Installation suspended, incomplete"
			);
		case SystemCode::UNKNOWN_PRODUCT:
			RETURN_STATIC_STRING(
					"This action is only valid for products that are currently installed"
			);
		case SystemCode::UNKNOWN_FEATURE:
			RETURN_STATIC_STRING(
					"Feature ID not registered"
			);
		case SystemCode::UNKNOWN_COMPONENT:
			RETURN_STATIC_STRING(
					"Component ID not registered"
			);
		case SystemCode::UNKNOWN_PROPERTY:
			RETURN_STATIC_STRING(
					"Unknown property"
			);
		case SystemCode::INVALID_HANDLE_STATE:
			RETURN_STATIC_STRING(
					"Handle is in an invalid state"
			);
		case SystemCode::BAD_CONFIGURATION:
			RETURN_STATIC_STRING(
					"The configuration data for this product is corrupt. Contact your support personnel"
			);
		case SystemCode::INDEX_ABSENT:
			RETURN_STATIC_STRING(
					"Component qualifier not present"
			);
		case SystemCode::INSTALL_SOURCE_ABSENT:
			RETURN_STATIC_STRING(
					"The installation source for this product is not available. Verify that the source exists and that you can access it"
			);
		case SystemCode::INSTALL_PACKAGE_VERSION:
			RETURN_STATIC_STRING(
					"This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service"
			);
		case SystemCode::PRODUCT_UNINSTALLED:
			RETURN_STATIC_STRING(
					"Product is uninstalled"
			);
		case SystemCode::BAD_QUERY_SYNTAX:
			RETURN_STATIC_STRING(
					"SQL query syntax invalid or unsupported"
			);
		case SystemCode::INVALID_FIELD:
			RETURN_STATIC_STRING(
					"Record field does not exist"
			);
		case SystemCode::DEVICE_REMOVED:
			RETURN_STATIC_STRING(
					"The device has been removed"
			);
		case SystemCode::INSTALL_ALREADY_RUNNING:
			RETURN_STATIC_STRING(
					"Another installation is already in progress. Complete that installation before proceeding with this install"
			);
		case SystemCode::INSTALL_PACKAGE_OPEN_FAILED:
			RETURN_STATIC_STRING(
					"This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package"
			);
		case SystemCode::INSTALL_PACKAGE_INVALID:
			RETURN_STATIC_STRING(
					"This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package"
			);
		case SystemCode::INSTALL_UI_FAILURE:
			RETURN_STATIC_STRING(
					"There was an error starting the Windows Installer service user interface. Contact your support personnel"
			);
		case SystemCode::INSTALL_LOG_FAILURE:
			RETURN_STATIC_STRING(
					"Error opening installation log file. Verify that the specified log file location exists and that you can write to it"
			);
		case SystemCode::INSTALL_LANGUAGE_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"The language of this installation package is not supported by your system"
			);
		case SystemCode::INSTALL_TRANSFORM_FAILURE:
			RETURN_STATIC_STRING(
					"Error applying transforms. Verify that the specified transform paths are valid"
			);
		case SystemCode::INSTALL_PACKAGE_REJECTED:
			RETURN_STATIC_STRING(
					"This installation is forbidden by system policy. Contact your system administrator"
			);
		case SystemCode::FUNCTION_NOT_CALLED:
			RETURN_STATIC_STRING(
					"Function could not be executed"
			);
		case SystemCode::FUNCTION_FAILED:
			RETURN_STATIC_STRING(
					"Function failed during execution"
			);
		case SystemCode::INVALID_TABLE:
			RETURN_STATIC_STRING(
					"Invalid or unknown table specified"
			);
		case SystemCode::DATATYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"Data supplied is of wrong type"
			);
		case SystemCode::UNSUPPORTED_TYPE:
			RETURN_STATIC_STRING(
					"Data of this type is not supported"
			);
		case SystemCode::CREATE_FAILED:
			RETURN_STATIC_STRING(
					"The Windows Installer service failed to start. Contact your support personnel"
			);
		case SystemCode::INSTALL_TEMP_UNWRITABLE:
			RETURN_STATIC_STRING(
					"The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder"
			);
		case SystemCode::INSTALL_PLATFORM_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"This installation package is not supported by this processor type. Contact your product vendor"
			);
		case SystemCode::INSTALL_NOTUSED:
			RETURN_STATIC_STRING(
					"Component not used on this computer"
			);
		case SystemCode::PATCH_PACKAGE_OPEN_FAILED:
			RETURN_STATIC_STRING(
					"This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package"
			);
		case SystemCode::PATCH_PACKAGE_INVALID:
			RETURN_STATIC_STRING(
					"This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package"
			);
		case SystemCode::PATCH_PACKAGE_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service"
			);
		case SystemCode::PRODUCT_VERSION:
			RETURN_STATIC_STRING(
					"Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel"
			);
		case SystemCode::INVALID_COMMAND_LINE:
			RETURN_STATIC_STRING(
					"Invalid command line argument. Consult the Windows Installer SDK for detailed command line help"
			);
		case SystemCode::INSTALL_REMOTE_DISALLOWED:
			RETURN_STATIC_STRING(
					"Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator"
			);
		case SystemCode::SUCCESS_REBOOT_INITIATED:
			RETURN_STATIC_STRING(
					"The requested operation completed successfully. The system will be restarted so the changes can take effect"
			);
		case SystemCode::PATCH_TARGET_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade"
			);
		case SystemCode::PATCH_PACKAGE_REJECTED:
			RETURN_STATIC_STRING(
					"The update package is not permitted by software restriction policy"
			);
		case SystemCode::INSTALL_TRANSFORM_REJECTED:
			RETURN_STATIC_STRING(
					"One or more customizations are not permitted by software restriction policy"
			);
		case SystemCode::INSTALL_REMOTE_PROHIBITED:
			RETURN_STATIC_STRING(
					"The Windows Installer does not permit installation from a Remote Desktop Connection"
			);
		case SystemCode::PATCH_REMOVAL_UNSUPPORTED:
			RETURN_STATIC_STRING(
					"Uninstallation of the update package is not supported"
			);
		case SystemCode::UNKNOWN_PATCH:
			RETURN_STATIC_STRING(
					"The update is not applied to this product"
			);
		case SystemCode::PATCH_NO_SEQUENCE:
			RETURN_STATIC_STRING(
					"No valid sequence could be found for the set of updates"
			);
		case SystemCode::PATCH_REMOVAL_DISALLOWED:
			RETURN_STATIC_STRING(
					"Update removal was disallowed by policy"
			);
		case SystemCode::INVALID_PATCH_XML:
			RETURN_STATIC_STRING(
					"The XML update data is invalid"
			);
		case SystemCode::PATCH_MANAGED_ADVERTISED_PRODUCT:
			RETURN_STATIC_STRING(
					"Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update"
			);
		case SystemCode::INSTALL_SERVICE_SAFEBOOT:
			RETURN_STATIC_STRING(
					"The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state"
			);
		case SystemCode::FAIL_FAST_EXCEPTION:
			RETURN_STATIC_STRING(
					"A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately"
			);
		case SystemCode::INSTALL_REJECTED:
			RETURN_STATIC_STRING(
					"The app that you are trying to run is not supported on this version of Windows"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
