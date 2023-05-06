#include <FlameIDE/../../src/Os/Windows/SystemCode4.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--1700-3999-
enum class SystemCode: decltype(::GetLastError())
{
	S_INVALID_STRING_BINDING =
#	if defined RPC_S_INVALID_STRING_BINDING
			RPC_S_INVALID_STRING_BINDING
#	else
			0x6A4
#	endif
		// The string binding is invalid.

	, S_WRONG_KIND_OF_BINDING =
#	if defined RPC_S_WRONG_KIND_OF_BINDING
			RPC_S_WRONG_KIND_OF_BINDING
#	else
			0x6A5
#	endif
		// The binding handle is not the correct type.

	, S_INVALID_BINDING =
#	if defined RPC_S_INVALID_BINDING
			RPC_S_INVALID_BINDING
#	else
			0x6A6
#	endif
		// The binding handle is invalid.

	, S_PROTSEQ_NOT_SUPPORTED =
#	if defined RPC_S_PROTSEQ_NOT_SUPPORTED
			RPC_S_PROTSEQ_NOT_SUPPORTED
#	else
			0x6A7
#	endif
		// The RPC protocol sequence is not supported.

	, S_INVALID_RPC_PROTSEQ =
#	if defined RPC_S_INVALID_RPC_PROTSEQ
			RPC_S_INVALID_RPC_PROTSEQ
#	else
			0x6A8
#	endif
		// The RPC protocol sequence is invalid.

	, S_INVALID_STRING_UUID =
#	if defined RPC_S_INVALID_STRING_UUID
			RPC_S_INVALID_STRING_UUID
#	else
			0x6A9
#	endif
		// The string universal unique identifier (UUID) is invalid.

	, S_INVALID_ENDPOINT_FORMAT =
#	if defined RPC_S_INVALID_ENDPOINT_FORMAT
			RPC_S_INVALID_ENDPOINT_FORMAT
#	else
			0x6AA
#	endif
		// The endpoint format is invalid.

	, S_INVALID_NET_ADDR =
#	if defined RPC_S_INVALID_NET_ADDR
			RPC_S_INVALID_NET_ADDR
#	else
			0x6AB
#	endif
		// The network address is invalid.

	, S_NO_ENDPOINT_FOUND =
#	if defined RPC_S_NO_ENDPOINT_FOUND
			RPC_S_NO_ENDPOINT_FOUND
#	else
			0x6AC
#	endif
		// No endpoint was found.

	, S_INVALID_TIMEOUT =
#	if defined RPC_S_INVALID_TIMEOUT
			RPC_S_INVALID_TIMEOUT
#	else
			0x6AD
#	endif
		// The timeout value is invalid.

	, S_OBJECT_NOT_FOUND =
#	if defined RPC_S_OBJECT_NOT_FOUND
			RPC_S_OBJECT_NOT_FOUND
#	else
			0x6AE
#	endif
		// The object universal unique identifier (UUID) was not found.

	, S_ALREADY_REGISTERED =
#	if defined RPC_S_ALREADY_REGISTERED
			RPC_S_ALREADY_REGISTERED
#	else
			0x6AF
#	endif
		// The object universal unique identifier (UUID) has already been registered.

	, S_TYPE_ALREADY_REGISTERED =
#	if defined RPC_S_TYPE_ALREADY_REGISTERED
			RPC_S_TYPE_ALREADY_REGISTERED
#	else
			0x6B0
#	endif
		// The type universal unique identifier (UUID) has already been registered.

	, S_ALREADY_LISTENING =
#	if defined RPC_S_ALREADY_LISTENING
			RPC_S_ALREADY_LISTENING
#	else
			0x6B1
#	endif
		// The RPC server is already listening.

	, S_NO_PROTSEQS_REGISTERED =
#	if defined RPC_S_NO_PROTSEQS_REGISTERED
			RPC_S_NO_PROTSEQS_REGISTERED
#	else
			0x6B2
#	endif
		// No protocol sequences have been registered.

	, S_NOT_LISTENING =
#	if defined RPC_S_NOT_LISTENING
			RPC_S_NOT_LISTENING
#	else
			0x6B3
#	endif
		// The RPC server is not listening.

	, S_UNKNOWN_MGR_TYPE =
#	if defined RPC_S_UNKNOWN_MGR_TYPE
			RPC_S_UNKNOWN_MGR_TYPE
#	else
			0x6B4
#	endif
		// The manager type is unknown.

	, S_UNKNOWN_IF =
#	if defined RPC_S_UNKNOWN_IF
			RPC_S_UNKNOWN_IF
#	else
			0x6B5
#	endif
		// The interface is unknown.

	, S_NO_BINDINGS =
#	if defined RPC_S_NO_BINDINGS
			RPC_S_NO_BINDINGS
#	else
			0x6B6
#	endif
		// There are no bindings.

	, S_NO_PROTSEQS =
#	if defined RPC_S_NO_PROTSEQS
			RPC_S_NO_PROTSEQS
#	else
			0x6B7
#	endif
		// There are no protocol sequences.

	, S_CANT_CREATE_ENDPOINT =
#	if defined RPC_S_CANT_CREATE_ENDPOINT
			RPC_S_CANT_CREATE_ENDPOINT
#	else
			0x6B8
#	endif
		// The endpoint cannot be created.

	, S_OUT_OF_RESOURCES =
#	if defined RPC_S_OUT_OF_RESOURCES
			RPC_S_OUT_OF_RESOURCES
#	else
			0x6B9
#	endif
		// Not enough resources are available to complete this operation.

	, S_SERVER_UNAVAILABLE =
#	if defined RPC_S_SERVER_UNAVAILABLE
			RPC_S_SERVER_UNAVAILABLE
#	else
			0x6BA
#	endif
		// The RPC server is unavailable.

	, S_SERVER_TOO_BUSY =
#	if defined RPC_S_SERVER_TOO_BUSY
			RPC_S_SERVER_TOO_BUSY
#	else
			0x6BB
#	endif
		// The RPC server is too busy to complete this operation.

	, S_INVALID_NETWORK_OPTIONS =
#	if defined RPC_S_INVALID_NETWORK_OPTIONS
			RPC_S_INVALID_NETWORK_OPTIONS
#	else
			0x6BC
#	endif
		// The network options are invalid.

	, S_NO_CALL_ACTIVE =
#	if defined RPC_S_NO_CALL_ACTIVE
			RPC_S_NO_CALL_ACTIVE
#	else
			0x6BD
#	endif
		// There are no remote procedure calls active on this thread.

	, S_CALL_FAILED =
#	if defined RPC_S_CALL_FAILED
			RPC_S_CALL_FAILED
#	else
			0x6BE
#	endif
		// The remote procedure call failed.

	, S_CALL_FAILED_DNE =
#	if defined RPC_S_CALL_FAILED_DNE
			RPC_S_CALL_FAILED_DNE
#	else
			0x6BF
#	endif
		// The remote procedure call failed and did not execute.

	, S_PROTOCOL_ERROR =
#	if defined RPC_S_PROTOCOL_ERROR
			RPC_S_PROTOCOL_ERROR
#	else
			0x6C0
#	endif
		// A remote procedure call (RPC) protocol error occurred.

	, S_PROXY_ACCESS_DENIED =
#	if defined RPC_S_PROXY_ACCESS_DENIED
			RPC_S_PROXY_ACCESS_DENIED
#	else
			0x6C1
#	endif
		// Access to the HTTP proxy is denied.

	, S_UNSUPPORTED_TRANS_SYN =
#	if defined RPC_S_UNSUPPORTED_TRANS_SYN
			RPC_S_UNSUPPORTED_TRANS_SYN
#	else
			0x6C2
#	endif
		// The transfer syntax is not supported by the RPC server.

	, S_UNSUPPORTED_TYPE =
#	if defined RPC_S_UNSUPPORTED_TYPE
			RPC_S_UNSUPPORTED_TYPE
#	else
			0x6C4
#	endif
		// The universal unique identifier (UUID) type is not supported.

	, S_INVALID_TAG =
#	if defined RPC_S_INVALID_TAG
			RPC_S_INVALID_TAG
#	else
			0x6C5
#	endif
		// The tag is invalid.

	, S_INVALID_BOUND =
#	if defined RPC_S_INVALID_BOUND
			RPC_S_INVALID_BOUND
#	else
			0x6C6
#	endif
		// The array bounds are invalid.

	, S_NO_ENTRY_NAME =
#	if defined RPC_S_NO_ENTRY_NAME
			RPC_S_NO_ENTRY_NAME
#	else
			0x6C7
#	endif
		// The binding does not contain an entry name.

	, S_INVALID_NAME_SYNTAX =
#	if defined RPC_S_INVALID_NAME_SYNTAX
			RPC_S_INVALID_NAME_SYNTAX
#	else
			0x6C8
#	endif
		// The name syntax is invalid.

	, S_UNSUPPORTED_NAME_SYNTAX =
#	if defined RPC_S_UNSUPPORTED_NAME_SYNTAX
			RPC_S_UNSUPPORTED_NAME_SYNTAX
#	else
			0x6C9
#	endif
		// The name syntax is not supported.

	, S_UUID_NO_ADDRESS =
#	if defined RPC_S_UUID_NO_ADDRESS
			RPC_S_UUID_NO_ADDRESS
#	else
			0x6CB
#	endif
		// No network address is available to use to construct a universal unique identifier (UUID).

	, S_DUPLICATE_ENDPOINT =
#	if defined RPC_S_DUPLICATE_ENDPOINT
			RPC_S_DUPLICATE_ENDPOINT
#	else
			0x6CC
#	endif
		// The endpoint is a duplicate.

	, S_UNKNOWN_AUTHN_TYPE =
#	if defined RPC_S_UNKNOWN_AUTHN_TYPE
			RPC_S_UNKNOWN_AUTHN_TYPE
#	else
			0x6CD
#	endif
		// The authentication type is unknown.

	, S_MAX_CALLS_TOO_SMALL =
#	if defined RPC_S_MAX_CALLS_TOO_SMALL
			RPC_S_MAX_CALLS_TOO_SMALL
#	else
			0x6CE
#	endif
		// The maximum number of calls is too small.

	, S_STRING_TOO_LONG =
#	if defined RPC_S_STRING_TOO_LONG
			RPC_S_STRING_TOO_LONG
#	else
			0x6CF
#	endif
		// The string is too long.

	, S_PROTSEQ_NOT_FOUND =
#	if defined RPC_S_PROTSEQ_NOT_FOUND
			RPC_S_PROTSEQ_NOT_FOUND
#	else
			0x6D0
#	endif
		// The RPC protocol sequence was not found.

	, S_PROCNUM_OUT_OF_RANGE =
#	if defined RPC_S_PROCNUM_OUT_OF_RANGE
			RPC_S_PROCNUM_OUT_OF_RANGE
#	else
			0x6D1
#	endif
		// The procedure number is out of range.

	, S_BINDING_HAS_NO_AUTH =
#	if defined RPC_S_BINDING_HAS_NO_AUTH
			RPC_S_BINDING_HAS_NO_AUTH
#	else
			0x6D2
#	endif
		// The binding does not contain any authentication information.

	, S_UNKNOWN_AUTHN_SERVICE =
#	if defined RPC_S_UNKNOWN_AUTHN_SERVICE
			RPC_S_UNKNOWN_AUTHN_SERVICE
#	else
			0x6D3
#	endif
		// The authentication service is unknown.

	, S_UNKNOWN_AUTHN_LEVEL =
#	if defined RPC_S_UNKNOWN_AUTHN_LEVEL
			RPC_S_UNKNOWN_AUTHN_LEVEL
#	else
			0x6D4
#	endif
		// The authentication level is unknown.

	, S_INVALID_AUTH_IDENTITY =
#	if defined RPC_S_INVALID_AUTH_IDENTITY
			RPC_S_INVALID_AUTH_IDENTITY
#	else
			0x6D5
#	endif
		// The security context is invalid.

	, S_UNKNOWN_AUTHZ_SERVICE =
#	if defined RPC_S_UNKNOWN_AUTHZ_SERVICE
			RPC_S_UNKNOWN_AUTHZ_SERVICE
#	else
			0x6D6
#	endif
		// The authorization service is unknown.

	, S_INVALID_ENTRY =
#	if defined EPT_S_INVALID_ENTRY
			EPT_S_INVALID_ENTRY
#	else
			0x6D7
#	endif
		// The entry is invalid.

	, S_CANT_PERFORM_OP =
#	if defined EPT_S_CANT_PERFORM_OP
			EPT_S_CANT_PERFORM_OP
#	else
			0x6D8
#	endif
		// The server endpoint cannot perform the operation.

	, S_NOT_REGISTERED =
#	if defined EPT_S_NOT_REGISTERED
			EPT_S_NOT_REGISTERED
#	else
			0x6D9
#	endif
		// There are no more endpoints available from the endpoint mapper.

	, S_NOTHING_TO_EXPORT =
#	if defined RPC_S_NOTHING_TO_EXPORT
			RPC_S_NOTHING_TO_EXPORT
#	else
			0x6DA
#	endif
		// No interfaces have been exported.

	, S_INCOMPLETE_NAME =
#	if defined RPC_S_INCOMPLETE_NAME
			RPC_S_INCOMPLETE_NAME
#	else
			0x6DB
#	endif
		// The entry name is incomplete.

	, S_INVALID_VERS_OPTION =
#	if defined RPC_S_INVALID_VERS_OPTION
			RPC_S_INVALID_VERS_OPTION
#	else
			0x6DC
#	endif
		// The version option is invalid.

	, S_NO_MORE_MEMBERS =
#	if defined RPC_S_NO_MORE_MEMBERS
			RPC_S_NO_MORE_MEMBERS
#	else
			0x6DD
#	endif
		// There are no more members.

	, S_NOT_ALL_OBJS_UNEXPORTED =
#	if defined RPC_S_NOT_ALL_OBJS_UNEXPORTED
			RPC_S_NOT_ALL_OBJS_UNEXPORTED
#	else
			0x6DE
#	endif
		// There is nothing to unexport.

	, S_INTERFACE_NOT_FOUND =
#	if defined RPC_S_INTERFACE_NOT_FOUND
			RPC_S_INTERFACE_NOT_FOUND
#	else
			0x6DF
#	endif
		// The interface was not found.

	, S_ENTRY_ALREADY_EXISTS =
#	if defined RPC_S_ENTRY_ALREADY_EXISTS
			RPC_S_ENTRY_ALREADY_EXISTS
#	else
			0x6E0
#	endif
		// The entry already exists.

	, S_ENTRY_NOT_FOUND =
#	if defined RPC_S_ENTRY_NOT_FOUND
			RPC_S_ENTRY_NOT_FOUND
#	else
			0x6E1
#	endif
		// The entry is not found.

	, S_NAME_SERVICE_UNAVAILABLE =
#	if defined RPC_S_NAME_SERVICE_UNAVAILABLE
			RPC_S_NAME_SERVICE_UNAVAILABLE
#	else
			0x6E2
#	endif
		// The name service is unavailable.

	, S_INVALID_NAF_ID =
#	if defined RPC_S_INVALID_NAF_ID
			RPC_S_INVALID_NAF_ID
#	else
			0x6E3
#	endif
		// The network address family is invalid.

	, S_CANNOT_SUPPORT =
#	if defined RPC_S_CANNOT_SUPPORT
			RPC_S_CANNOT_SUPPORT
#	else
			0x6E4
#	endif
		// The requested operation is not supported.

	, S_NO_CONTEXT_AVAILABLE =
#	if defined RPC_S_NO_CONTEXT_AVAILABLE
			RPC_S_NO_CONTEXT_AVAILABLE
#	else
			0x6E5
#	endif
		// No security context is available to allow impersonation.

	, S_INTERNAL_ERROR =
#	if defined RPC_S_INTERNAL_ERROR
			RPC_S_INTERNAL_ERROR
#	else
			0x6E6
#	endif
		// An internal error occurred in a remote procedure call (RPC).

	, S_ZERO_DIVIDE =
#	if defined RPC_S_ZERO_DIVIDE
			RPC_S_ZERO_DIVIDE
#	else
			0x6E7
#	endif
		// The RPC server attempted an integer division by zero.

	, S_ADDRESS_ERROR =
#	if defined RPC_S_ADDRESS_ERROR
			RPC_S_ADDRESS_ERROR
#	else
			0x6E8
#	endif
		// An addressing error occurred in the RPC server.

	, S_FP_DIV_ZERO =
#	if defined RPC_S_FP_DIV_ZERO
			RPC_S_FP_DIV_ZERO
#	else
			0x6E9
#	endif
		// A floating-point operation at the RPC server caused a division by zero.

	, S_FP_UNDERFLOW =
#	if defined RPC_S_FP_UNDERFLOW
			RPC_S_FP_UNDERFLOW
#	else
			0x6EA
#	endif
		// A floating-point underflow occurred at the RPC server.

	, S_FP_OVERFLOW =
#	if defined RPC_S_FP_OVERFLOW
			RPC_S_FP_OVERFLOW
#	else
			0x6EB
#	endif
		// A floating-point overflow occurred at the RPC server.

	, X_NO_MORE_ENTRIES =
#	if defined RPC_X_NO_MORE_ENTRIES
			RPC_X_NO_MORE_ENTRIES
#	else
			0x6EC
#	endif
		// The list of RPC servers available for the binding of auto handles has been exhausted.

	, X_SS_CHAR_TRANS_OPEN_FAIL =
#	if defined RPC_X_SS_CHAR_TRANS_OPEN_FAIL
			RPC_X_SS_CHAR_TRANS_OPEN_FAIL
#	else
			0x6ED
#	endif
		// Unable to open the character translation table file.

	, X_SS_CHAR_TRANS_SHORT_FILE =
#	if defined RPC_X_SS_CHAR_TRANS_SHORT_FILE
			RPC_X_SS_CHAR_TRANS_SHORT_FILE
#	else
			0x6EE
#	endif
		// The file containing the character translation table has fewer than 512 bytes.

	, X_SS_IN_NULL_CONTEXT =
#	if defined RPC_X_SS_IN_NULL_CONTEXT
			RPC_X_SS_IN_NULL_CONTEXT
#	else
			0x6EF
#	endif
		// A null context handle was passed from the client to the host during a remote procedure call.

	, X_SS_CONTEXT_DAMAGED =
#	if defined RPC_X_SS_CONTEXT_DAMAGED
			RPC_X_SS_CONTEXT_DAMAGED
#	else
			0x6F1
#	endif
		// The context handle changed during a remote procedure call.

	, X_SS_HANDLES_MISMATCH =
#	if defined RPC_X_SS_HANDLES_MISMATCH
			RPC_X_SS_HANDLES_MISMATCH
#	else
			0x6F2
#	endif
		// The binding handles passed to a remote procedure call do not match.

	, X_SS_CANNOT_GET_CALL_HANDLE =
#	if defined RPC_X_SS_CANNOT_GET_CALL_HANDLE
			RPC_X_SS_CANNOT_GET_CALL_HANDLE
#	else
			0x6F3
#	endif
		// The stub is unable to get the remote procedure call handle.

	, X_NULL_REF_POINTER =
#	if defined RPC_X_NULL_REF_POINTER
			RPC_X_NULL_REF_POINTER
#	else
			0x6F4
#	endif
		// A null reference pointer was passed to the stub.

	, X_ENUM_VALUE_OUT_OF_RANGE =
#	if defined RPC_X_ENUM_VALUE_OUT_OF_RANGE
			RPC_X_ENUM_VALUE_OUT_OF_RANGE
#	else
			0x6F5
#	endif
		// The enumeration value is out of range.

	, X_BYTE_COUNT_TOO_SMALL =
#	if defined RPC_X_BYTE_COUNT_TOO_SMALL
			RPC_X_BYTE_COUNT_TOO_SMALL
#	else
			0x6F6
#	endif
		// The byte count is too small.

	, X_BAD_STUB_DATA =
#	if defined RPC_X_BAD_STUB_DATA
			RPC_X_BAD_STUB_DATA
#	else
			0x6F7
#	endif
		// The stub received bad data.

	, INVALID_USER_BUFFER =
#	if defined ERROR_INVALID_USER_BUFFER
			ERROR_INVALID_USER_BUFFER
#	else
			0x6F8
#	endif
		// The supplied user buffer is not valid for the requested operation.

	, UNRECOGNIZED_MEDIA =
#	if defined ERROR_UNRECOGNIZED_MEDIA
			ERROR_UNRECOGNIZED_MEDIA
#	else
			0x6F9
#	endif
		// The disk media is not recognized. It may not be formatted.

	, NO_TRUST_LSA_SECRET =
#	if defined ERROR_NO_TRUST_LSA_SECRET
			ERROR_NO_TRUST_LSA_SECRET
#	else
			0x6FA
#	endif
		// The workstation does not have a trust secret.

	, NO_TRUST_SAM_ACCOUNT =
#	if defined ERROR_NO_TRUST_SAM_ACCOUNT
			ERROR_NO_TRUST_SAM_ACCOUNT
#	else
			0x6FB
#	endif
		// The security database on the server does not have a computer account for this workstation trust relationship.

	, TRUSTED_DOMAIN_FAILURE =
#	if defined ERROR_TRUSTED_DOMAIN_FAILURE
			ERROR_TRUSTED_DOMAIN_FAILURE
#	else
			0x6FC
#	endif
		// The trust relationship between the primary domain and the trusted domain failed.

	, TRUSTED_RELATIONSHIP_FAILURE =
#	if defined ERROR_TRUSTED_RELATIONSHIP_FAILURE
			ERROR_TRUSTED_RELATIONSHIP_FAILURE
#	else
			0x6FD
#	endif
		// The trust relationship between this workstation and the primary domain failed.

	, TRUST_FAILURE =
#	if defined ERROR_TRUST_FAILURE
			ERROR_TRUST_FAILURE
#	else
			0x6FE
#	endif
		// The network logon failed.

	, S_CALL_IN_PROGRESS =
#	if defined RPC_S_CALL_IN_PROGRESS
			RPC_S_CALL_IN_PROGRESS
#	else
			0x6FF
#	endif
		// A remote procedure call is already in progress for this thread.

	, NETLOGON_NOT_STARTED =
#	if defined ERROR_NETLOGON_NOT_STARTED
			ERROR_NETLOGON_NOT_STARTED
#	else
			0x700
#	endif
		// An attempt was made to logon, but the network logon service was not started.

	, ACCOUNT_EXPIRED =
#	if defined ERROR_ACCOUNT_EXPIRED
			ERROR_ACCOUNT_EXPIRED
#	else
			0x701
#	endif
		// The user's account has expired.

	, REDIRECTOR_HAS_OPEN_HANDLES =
#	if defined ERROR_REDIRECTOR_HAS_OPEN_HANDLES
			ERROR_REDIRECTOR_HAS_OPEN_HANDLES
#	else
			0x702
#	endif
		// The redirector is in use and cannot be unloaded.

	, PRINTER_DRIVER_ALREADY_INSTALLED =
#	if defined ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
			ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
#	else
			0x703
#	endif
		// The specified printer driver is already installed.

	, UNKNOWN_PORT =
#	if defined ERROR_UNKNOWN_PORT
			ERROR_UNKNOWN_PORT
#	else
			0x704
#	endif
		// The specified port is unknown.

	, UNKNOWN_PRINTER_DRIVER =
#	if defined ERROR_UNKNOWN_PRINTER_DRIVER
			ERROR_UNKNOWN_PRINTER_DRIVER
#	else
			0x705
#	endif
		// The printer driver is unknown.

	, UNKNOWN_PRINTPROCESSOR =
#	if defined ERROR_UNKNOWN_PRINTPROCESSOR
			ERROR_UNKNOWN_PRINTPROCESSOR
#	else
			0x706
#	endif
		// The print processor is unknown.

	, INVALID_SEPARATOR_FILE =
#	if defined ERROR_INVALID_SEPARATOR_FILE
			ERROR_INVALID_SEPARATOR_FILE
#	else
			0x707
#	endif
		// The specified separator file is invalid.

	, INVALID_PRIORITY =
#	if defined ERROR_INVALID_PRIORITY
			ERROR_INVALID_PRIORITY
#	else
			0x708
#	endif
		// The specified priority is invalid.

	, INVALID_PRINTER_NAME =
#	if defined ERROR_INVALID_PRINTER_NAME
			ERROR_INVALID_PRINTER_NAME
#	else
			0x709
#	endif
		// The printer name is invalid.

	, PRINTER_ALREADY_EXISTS =
#	if defined ERROR_PRINTER_ALREADY_EXISTS
			ERROR_PRINTER_ALREADY_EXISTS
#	else
			0x70A
#	endif
		// The printer already exists.

	, INVALID_PRINTER_COMMAND =
#	if defined ERROR_INVALID_PRINTER_COMMAND
			ERROR_INVALID_PRINTER_COMMAND
#	else
			0x70B
#	endif
		// The printer command is invalid.

	, INVALID_DATATYPE =
#	if defined ERROR_INVALID_DATATYPE
			ERROR_INVALID_DATATYPE
#	else
			0x70C
#	endif
		// The specified datatype is invalid.

	, INVALID_ENVIRONMENT =
#	if defined ERROR_INVALID_ENVIRONMENT
			ERROR_INVALID_ENVIRONMENT
#	else
			0x70D
#	endif
		// The environment specified is invalid.

	, S_NO_MORE_BINDINGS =
#	if defined RPC_S_NO_MORE_BINDINGS
			RPC_S_NO_MORE_BINDINGS
#	else
			0x70E
#	endif
		// There are no more bindings.

	, NOLOGON_INTERDOMAIN_TRUST_ACCOUNT =
#	if defined ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
			ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
#	else
			0x70F
#	endif
		// The account used is an interdomain trust account. Use your global user account or local user account to access this server.

	, NOLOGON_WORKSTATION_TRUST_ACCOUNT =
#	if defined ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT
			ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT
#	else
			0x710
#	endif
		// The account used is a computer account. Use your global user account or local user account to access this server.

	, NOLOGON_SERVER_TRUST_ACCOUNT =
#	if defined ERROR_NOLOGON_SERVER_TRUST_ACCOUNT
			ERROR_NOLOGON_SERVER_TRUST_ACCOUNT
#	else
			0x711
#	endif
		// The account used is a server trust account. Use your global user account or local user account to access this server.

	, DOMAIN_TRUST_INCONSISTENT =
#	if defined ERROR_DOMAIN_TRUST_INCONSISTENT
			ERROR_DOMAIN_TRUST_INCONSISTENT
#	else
			0x712
#	endif
		// The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.

	, SERVER_HAS_OPEN_HANDLES =
#	if defined ERROR_SERVER_HAS_OPEN_HANDLES
			ERROR_SERVER_HAS_OPEN_HANDLES
#	else
			0x713
#	endif
		// The server is in use and cannot be unloaded.

	, RESOURCE_DATA_NOT_FOUND =
#	if defined ERROR_RESOURCE_DATA_NOT_FOUND
			ERROR_RESOURCE_DATA_NOT_FOUND
#	else
			0x714
#	endif
		// The specified image file did not contain a resource section.

	, RESOURCE_TYPE_NOT_FOUND =
#	if defined ERROR_RESOURCE_TYPE_NOT_FOUND
			ERROR_RESOURCE_TYPE_NOT_FOUND
#	else
			0x715
#	endif
		// The specified resource type cannot be found in the image file.

	, RESOURCE_NAME_NOT_FOUND =
#	if defined ERROR_RESOURCE_NAME_NOT_FOUND
			ERROR_RESOURCE_NAME_NOT_FOUND
#	else
			0x716
#	endif
		// The specified resource name cannot be found in the image file.

	, RESOURCE_LANG_NOT_FOUND =
#	if defined ERROR_RESOURCE_LANG_NOT_FOUND
			ERROR_RESOURCE_LANG_NOT_FOUND
#	else
			0x717
#	endif
		// The specified resource language ID cannot be found in the image file.

	, NOT_ENOUGH_QUOTA =
#	if defined ERROR_NOT_ENOUGH_QUOTA
			ERROR_NOT_ENOUGH_QUOTA
#	else
			0x718
#	endif
		// Not enough quota is available to process this command.

	, S_NO_INTERFACES =
#	if defined RPC_S_NO_INTERFACES
			RPC_S_NO_INTERFACES
#	else
			0x719
#	endif
		// No interfaces have been registered.

	, S_CALL_CANCELLED =
#	if defined RPC_S_CALL_CANCELLED
			RPC_S_CALL_CANCELLED
#	else
			0x71A
#	endif
		// The remote procedure call was cancelled.

	, S_BINDING_INCOMPLETE =
#	if defined RPC_S_BINDING_INCOMPLETE
			RPC_S_BINDING_INCOMPLETE
#	else
			0x71B
#	endif
		// The binding handle does not contain all required information.

	, S_COMM_FAILURE =
#	if defined RPC_S_COMM_FAILURE
			RPC_S_COMM_FAILURE
#	else
			0x71C
#	endif
		// A communications failure occurred during a remote procedure call.

	, S_UNSUPPORTED_AUTHN_LEVEL =
#	if defined RPC_S_UNSUPPORTED_AUTHN_LEVEL
			RPC_S_UNSUPPORTED_AUTHN_LEVEL
#	else
			0x71D
#	endif
		// The requested authentication level is not supported.

	, S_NO_PRINC_NAME =
#	if defined RPC_S_NO_PRINC_NAME
			RPC_S_NO_PRINC_NAME
#	else
			0x71E
#	endif
		// No principal name registered.

	, S_NOT_RPC_ERROR =
#	if defined RPC_S_NOT_RPC_ERROR
			RPC_S_NOT_RPC_ERROR
#	else
			0x71F
#	endif
		// The error specified is not a valid Windows RPC error code.

	, S_UUID_LOCAL_ONLY =
#	if defined RPC_S_UUID_LOCAL_ONLY
			RPC_S_UUID_LOCAL_ONLY
#	else
			0x720
#	endif
		// A UUID that is valid only on this computer has been allocated.

	, S_SEC_PKG_ERROR =
#	if defined RPC_S_SEC_PKG_ERROR
			RPC_S_SEC_PKG_ERROR
#	else
			0x721
#	endif
		// A security package specific error occurred.

	, S_NOT_CANCELLED =
#	if defined RPC_S_NOT_CANCELLED
			RPC_S_NOT_CANCELLED
#	else
			0x722
#	endif
		// Thread is not canceled.

	, X_INVALID_ES_ACTION =
#	if defined RPC_X_INVALID_ES_ACTION
			RPC_X_INVALID_ES_ACTION
#	else
			0x723
#	endif
		// Invalid operation on the encoding/decoding handle.

	, X_WRONG_ES_VERSION =
#	if defined RPC_X_WRONG_ES_VERSION
			RPC_X_WRONG_ES_VERSION
#	else
			0x724
#	endif
		// Incompatible version of the serializing package.

	, X_WRONG_STUB_VERSION =
#	if defined RPC_X_WRONG_STUB_VERSION
			RPC_X_WRONG_STUB_VERSION
#	else
			0x725
#	endif
		// Incompatible version of the RPC stub.

	, X_INVALID_PIPE_OBJECT =
#	if defined RPC_X_INVALID_PIPE_OBJECT
			RPC_X_INVALID_PIPE_OBJECT
#	else
			0x726
#	endif
		// The RPC pipe object is invalid or corrupted.

	, X_WRONG_PIPE_ORDER =
#	if defined RPC_X_WRONG_PIPE_ORDER
			RPC_X_WRONG_PIPE_ORDER
#	else
			0x727
#	endif
		// An invalid operation was attempted on an RPC pipe object.

	, X_WRONG_PIPE_VERSION =
#	if defined RPC_X_WRONG_PIPE_VERSION
			RPC_X_WRONG_PIPE_VERSION
#	else
			0x728
#	endif
		// Unsupported RPC pipe version.

	, S_COOKIE_AUTH_FAILED =
#	if defined RPC_S_COOKIE_AUTH_FAILED
			RPC_S_COOKIE_AUTH_FAILED
#	else
			0x729
#	endif
		// HTTP proxy server rejected the connection because the cookie authentication failed.

	, S_GROUP_MEMBER_NOT_FOUND =
#	if defined RPC_S_GROUP_MEMBER_NOT_FOUND
			RPC_S_GROUP_MEMBER_NOT_FOUND
#	else
			0x76A
#	endif
		// The group member was not found.

	, S_CANT_CREATE =
#	if defined EPT_S_CANT_CREATE
			EPT_S_CANT_CREATE
#	else
			0x76B
#	endif
		// The endpoint mapper database entry could not be created.

	, S_INVALID_OBJECT =
#	if defined RPC_S_INVALID_OBJECT
			RPC_S_INVALID_OBJECT
#	else
			0x76C
#	endif
		// The object universal unique identifier (UUID) is the nil UUID.

	, INVALID_TIME =
#	if defined ERROR_INVALID_TIME
			ERROR_INVALID_TIME
#	else
			0x76D
#	endif
		// The specified time is invalid.

	, INVALID_FORM_NAME =
#	if defined ERROR_INVALID_FORM_NAME
			ERROR_INVALID_FORM_NAME
#	else
			0x76E
#	endif
		// The specified form name is invalid.

	, INVALID_FORM_SIZE =
#	if defined ERROR_INVALID_FORM_SIZE
			ERROR_INVALID_FORM_SIZE
#	else
			0x76F
#	endif
		// The specified form size is invalid.

	, ALREADY_WAITING =
#	if defined ERROR_ALREADY_WAITING
			ERROR_ALREADY_WAITING
#	else
			0x770
#	endif
		// The specified printer handle is already being waited on.

	, PRINTER_DELETED =
#	if defined ERROR_PRINTER_DELETED
			ERROR_PRINTER_DELETED
#	else
			0x771
#	endif
		// The specified printer has been deleted.

	, INVALID_PRINTER_STATE =
#	if defined ERROR_INVALID_PRINTER_STATE
			ERROR_INVALID_PRINTER_STATE
#	else
			0x772
#	endif
		// The state of the printer is invalid.

	, PASSWORD_MUST_CHANGE =
#	if defined ERROR_PASSWORD_MUST_CHANGE
			ERROR_PASSWORD_MUST_CHANGE
#	else
			0x773
#	endif
		// The user's password must be changed before signing in.

	, DOMAIN_CONTROLLER_NOT_FOUND =
#	if defined ERROR_DOMAIN_CONTROLLER_NOT_FOUND
			ERROR_DOMAIN_CONTROLLER_NOT_FOUND
#	else
			0x774
#	endif
		// Could not find the domain controller for this domain.

	, ACCOUNT_LOCKED_OUT =
#	if defined ERROR_ACCOUNT_LOCKED_OUT
			ERROR_ACCOUNT_LOCKED_OUT
#	else
			0x775
#	endif
		// The referenced account is currently locked out and may not be logged on to.

	, INVALID_OXID =
#	if defined OR_INVALID_OXID
			OR_INVALID_OXID
#	else
			0x776
#	endif
		// The object exporter specified was not found.

	, INVALID_OID =
#	if defined OR_INVALID_OID
			OR_INVALID_OID
#	else
			0x777
#	endif
		// The object specified was not found.

	, INVALID_SET =
#	if defined OR_INVALID_SET
			OR_INVALID_SET
#	else
			0x778
#	endif
		// The object resolver set specified was not found.

	, S_SEND_INCOMPLETE =
#	if defined RPC_S_SEND_INCOMPLETE
			RPC_S_SEND_INCOMPLETE
#	else
			0x779
#	endif
		// Some data remains to be sent in the request buffer.

	, S_INVALID_ASYNC_HANDLE =
#	if defined RPC_S_INVALID_ASYNC_HANDLE
			RPC_S_INVALID_ASYNC_HANDLE
#	else
			0x77A
#	endif
		// Invalid asynchronous remote procedure call handle.

	, S_INVALID_ASYNC_CALL =
#	if defined RPC_S_INVALID_ASYNC_CALL
			RPC_S_INVALID_ASYNC_CALL
#	else
			0x77B
#	endif
		// Invalid asynchronous RPC call handle for this operation.

	, X_PIPE_CLOSED =
#	if defined RPC_X_PIPE_CLOSED
			RPC_X_PIPE_CLOSED
#	else
			0x77C
#	endif
		// The RPC pipe object has already been closed.

	, X_PIPE_DISCIPLINE_ERROR =
#	if defined RPC_X_PIPE_DISCIPLINE_ERROR
			RPC_X_PIPE_DISCIPLINE_ERROR
#	else
			0x77D
#	endif
		// The RPC call completed before all pipes were processed.

	, X_PIPE_EMPTY =
#	if defined RPC_X_PIPE_EMPTY
			RPC_X_PIPE_EMPTY
#	else
			0x77E
#	endif
		// No more data is available from the RPC pipe.

	, NO_SITENAME =
#	if defined ERROR_NO_SITENAME
			ERROR_NO_SITENAME
#	else
			0x77F
#	endif
		// No site name is available for this machine.

	, CANT_ACCESS_FILE =
#	if defined ERROR_CANT_ACCESS_FILE
			ERROR_CANT_ACCESS_FILE
#	else
			0x780
#	endif
		// The file cannot be accessed by the system.

	, CANT_RESOLVE_FILENAME =
#	if defined ERROR_CANT_RESOLVE_FILENAME
			ERROR_CANT_RESOLVE_FILENAME
#	else
			0x781
#	endif
		// The name of the file cannot be resolved by the system.

	, S_ENTRY_TYPE_MISMATCH =
#	if defined RPC_S_ENTRY_TYPE_MISMATCH
			RPC_S_ENTRY_TYPE_MISMATCH
#	else
			0x782
#	endif
		// The entry is not of the expected type.

	, S_NOT_ALL_OBJS_EXPORTED =
#	if defined RPC_S_NOT_ALL_OBJS_EXPORTED
			RPC_S_NOT_ALL_OBJS_EXPORTED
#	else
			0x783
#	endif
		// Not all object UUIDs could be exported to the specified entry.

	, S_INTERFACE_NOT_EXPORTED =
#	if defined RPC_S_INTERFACE_NOT_EXPORTED
			RPC_S_INTERFACE_NOT_EXPORTED
#	else
			0x784
#	endif
		// Interface could not be exported to the specified entry.

	, S_PROFILE_NOT_ADDED =
#	if defined RPC_S_PROFILE_NOT_ADDED
			RPC_S_PROFILE_NOT_ADDED
#	else
			0x785
#	endif
		// The specified profile entry could not be added.

	, S_PRF_ELT_NOT_ADDED =
#	if defined RPC_S_PRF_ELT_NOT_ADDED
			RPC_S_PRF_ELT_NOT_ADDED
#	else
			0x786
#	endif
		// The specified profile element could not be added.

	, S_PRF_ELT_NOT_REMOVED =
#	if defined RPC_S_PRF_ELT_NOT_REMOVED
			RPC_S_PRF_ELT_NOT_REMOVED
#	else
			0x787
#	endif
		// The specified profile element could not be removed.

	, S_GRP_ELT_NOT_ADDED =
#	if defined RPC_S_GRP_ELT_NOT_ADDED
			RPC_S_GRP_ELT_NOT_ADDED
#	else
			0x788
#	endif
		// The group element could not be added.

	, S_GRP_ELT_NOT_REMOVED =
#	if defined RPC_S_GRP_ELT_NOT_REMOVED
			RPC_S_GRP_ELT_NOT_REMOVED
#	else
			0x789
#	endif
		// The group element could not be removed.

	, KM_DRIVER_BLOCKED =
#	if defined ERROR_KM_DRIVER_BLOCKED
			ERROR_KM_DRIVER_BLOCKED
#	else
			0x78A
#	endif
		// The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.

	, CONTEXT_EXPIRED =
#	if defined ERROR_CONTEXT_EXPIRED
			ERROR_CONTEXT_EXPIRED
#	else
			0x78B
#	endif
		// The context has expired and can no longer be used.

	, PER_USER_TRUST_QUOTA_EXCEEDED =
#	if defined ERROR_PER_USER_TRUST_QUOTA_EXCEEDED
			ERROR_PER_USER_TRUST_QUOTA_EXCEEDED
#	else
			0x78C
#	endif
		// The current user's delegated trust creation quota has been exceeded.

	, ALL_USER_TRUST_QUOTA_EXCEEDED =
#	if defined ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED
			ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED
#	else
			0x78D
#	endif
		// The total delegated trust creation quota has been exceeded.

	, USER_DELETE_TRUST_QUOTA_EXCEEDED =
#	if defined ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED
			ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED
#	else
			0x78E
#	endif
		// The current user's delegated trust deletion quota has been exceeded.

	, AUTHENTICATION_FIREWALL_FAILED =
#	if defined ERROR_AUTHENTICATION_FIREWALL_FAILED
			ERROR_AUTHENTICATION_FIREWALL_FAILED
#	else
			0x78F
#	endif
		// The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.

	, REMOTE_PRINT_CONNECTIONS_BLOCKED =
#	if defined ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED
			ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED
#	else
			0x790
#	endif
		// Remote connections to the Print Spooler are blocked by a policy set on your machine.

	, NTLM_BLOCKED =
#	if defined ERROR_NTLM_BLOCKED
			ERROR_NTLM_BLOCKED
#	else
			0x791
#	endif
		// Authentication failed because NTLM authentication has been disabled.

	, PASSWORD_CHANGE_REQUIRED =
#	if defined ERROR_PASSWORD_CHANGE_REQUIRED
			ERROR_PASSWORD_CHANGE_REQUIRED
#	else
			0x792
#	endif
		// Logon Failure: EAS policy requires that the user change their password before this operation can be performed.

	, INVALID_PIXEL_FORMAT =
#	if defined ERROR_INVALID_PIXEL_FORMAT
			ERROR_INVALID_PIXEL_FORMAT
#	else
			0x7D0
#	endif
		// The pixel format is invalid.

	, BAD_DRIVER =
#	if defined ERROR_BAD_DRIVER
			ERROR_BAD_DRIVER
#	else
			0x7D1
#	endif
		// The specified driver is invalid.

	, INVALID_WINDOW_STYLE =
#	if defined ERROR_INVALID_WINDOW_STYLE
			ERROR_INVALID_WINDOW_STYLE
#	else
			0x7D2
#	endif
		// The window style or class attribute is invalid for this operation.

	, METAFILE_NOT_SUPPORTED =
#	if defined ERROR_METAFILE_NOT_SUPPORTED
			ERROR_METAFILE_NOT_SUPPORTED
#	else
			0x7D3
#	endif
		// The requested metafile operation is not supported.

	, TRANSFORM_NOT_SUPPORTED =
#	if defined ERROR_TRANSFORM_NOT_SUPPORTED
			ERROR_TRANSFORM_NOT_SUPPORTED
#	else
			0x7D4
#	endif
		// The requested transformation operation is not supported.

	, CLIPPING_NOT_SUPPORTED =
#	if defined ERROR_CLIPPING_NOT_SUPPORTED
			ERROR_CLIPPING_NOT_SUPPORTED
#	else
			0x7D5
#	endif
		// The requested clipping operation is not supported.

	, INVALID_CMM =
#	if defined ERROR_INVALID_CMM
			ERROR_INVALID_CMM
#	else
			0x7DA
#	endif
		// The specified color management module is invalid.

	, INVALID_PROFILE =
#	if defined ERROR_INVALID_PROFILE
			ERROR_INVALID_PROFILE
#	else
			0x7DB
#	endif
		// The specified color profile is invalid.

	, TAG_NOT_FOUND =
#	if defined ERROR_TAG_NOT_FOUND
			ERROR_TAG_NOT_FOUND
#	else
			0x7DC
#	endif
		// The specified tag was not found.

	, TAG_NOT_PRESENT =
#	if defined ERROR_TAG_NOT_PRESENT
			ERROR_TAG_NOT_PRESENT
#	else
			0x7DD
#	endif
		// A required tag is not present.

	, DUPLICATE_TAG =
#	if defined ERROR_DUPLICATE_TAG
			ERROR_DUPLICATE_TAG
#	else
			0x7DE
#	endif
		// The specified tag is already present.

	, PROFILE_NOT_ASSOCIATED_WITH_DEVICE =
#	if defined ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE
			ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE
#	else
			0x7DF
#	endif
		// The specified color profile is not associated with the specified device.

	, PROFILE_NOT_FOUND =
#	if defined ERROR_PROFILE_NOT_FOUND
			ERROR_PROFILE_NOT_FOUND
#	else
			0x7E0
#	endif
		// The specified color profile was not found.

	, INVALID_COLORSPACE =
#	if defined ERROR_INVALID_COLORSPACE
			ERROR_INVALID_COLORSPACE
#	else
			0x7E1
#	endif
		// The specified color space is invalid.

	, ICM_NOT_ENABLED =
#	if defined ERROR_ICM_NOT_ENABLED
			ERROR_ICM_NOT_ENABLED
#	else
			0x7E2
#	endif
		// Image Color Management is not enabled.

	, DELETING_ICM_XFORM =
#	if defined ERROR_DELETING_ICM_XFORM
			ERROR_DELETING_ICM_XFORM
#	else
			0x7E3
#	endif
		// There was an error while deleting the color transform.

	, INVALID_TRANSFORM =
#	if defined ERROR_INVALID_TRANSFORM
			ERROR_INVALID_TRANSFORM
#	else
			0x7E4
#	endif
		// The specified color transform is invalid.

	, COLORSPACE_MISMATCH =
#	if defined ERROR_COLORSPACE_MISMATCH
			ERROR_COLORSPACE_MISMATCH
#	else
			0x7E5
#	endif
		// The specified transform does not match the bitmap's color space.

	, INVALID_COLORINDEX =
#	if defined ERROR_INVALID_COLORINDEX
			ERROR_INVALID_COLORINDEX
#	else
			0x7E6
#	endif
		// The specified named color index is not present in the profile.

	, PROFILE_DOES_NOT_MATCH_DEVICE =
#	if defined ERROR_PROFILE_DOES_NOT_MATCH_DEVICE
			ERROR_PROFILE_DOES_NOT_MATCH_DEVICE
#	else
			0x7E7
#	endif
		// The specified profile is intended for a device of a different type than the specified device.

	, CONNECTED_OTHER_PASSWORD =
#	if defined ERROR_CONNECTED_OTHER_PASSWORD
			ERROR_CONNECTED_OTHER_PASSWORD
#	else
			0x83C
#	endif
		// The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.

	, CONNECTED_OTHER_PASSWORD_DEFAULT =
#	if defined ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
			ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
#	else
			0x83D
#	endif
		// The network connection was made successfully using default credentials.

	, BAD_USERNAME =
#	if defined ERROR_BAD_USERNAME
			ERROR_BAD_USERNAME
#	else
			0x89A
#	endif
		// The specified username is invalid.

	, NOT_CONNECTED =
#	if defined ERROR_NOT_CONNECTED
			ERROR_NOT_CONNECTED
#	else
			0x8CA
#	endif
		// This network connection does not exist.

	, OPEN_FILES =
#	if defined ERROR_OPEN_FILES
			ERROR_OPEN_FILES
#	else
			0x961
#	endif
		// This network connection has files open or requests pending.

	, ACTIVE_CONNECTIONS =
#	if defined ERROR_ACTIVE_CONNECTIONS
			ERROR_ACTIVE_CONNECTIONS
#	else
			0x962
#	endif
		// Active connections still exist.

	, DEVICE_IN_USE =
#	if defined ERROR_DEVICE_IN_USE
			ERROR_DEVICE_IN_USE
#	else
			0x964
#	endif
		// The device is in use by an active process and cannot be disconnected.

	, UNKNOWN_PRINT_MONITOR =
#	if defined ERROR_UNKNOWN_PRINT_MONITOR
			ERROR_UNKNOWN_PRINT_MONITOR
#	else
			0xBB8
#	endif
		// The specified print monitor is unknown.

	, PRINTER_DRIVER_IN_USE =
#	if defined ERROR_PRINTER_DRIVER_IN_USE
			ERROR_PRINTER_DRIVER_IN_USE
#	else
			0xBB9
#	endif
		// The specified printer driver is currently in use.

	, SPOOL_FILE_NOT_FOUND =
#	if defined ERROR_SPOOL_FILE_NOT_FOUND
			ERROR_SPOOL_FILE_NOT_FOUND
#	else
			0xBBA
#	endif
		// The spool file was not found.

	, SPL_NO_STARTDOC =
#	if defined ERROR_SPL_NO_STARTDOC
			ERROR_SPL_NO_STARTDOC
#	else
			0xBBB
#	endif
		// A StartDocPrinter call was not issued.

	, SPL_NO_ADDJOB =
#	if defined ERROR_SPL_NO_ADDJOB
			ERROR_SPL_NO_ADDJOB
#	else
			0xBBC
#	endif
		// An AddJob call was not issued.

	, PRINT_PROCESSOR_ALREADY_INSTALLED =
#	if defined ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED
			ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED
#	else
			0xBBD
#	endif
		// The specified print processor has already been installed.

	, PRINT_MONITOR_ALREADY_INSTALLED =
#	if defined ERROR_PRINT_MONITOR_ALREADY_INSTALLED
			ERROR_PRINT_MONITOR_ALREADY_INSTALLED
#	else
			0xBBE
#	endif
		// The specified print monitor has already been installed.

	, INVALID_PRINT_MONITOR =
#	if defined ERROR_INVALID_PRINT_MONITOR
			ERROR_INVALID_PRINT_MONITOR
#	else
			0xBBF
#	endif
		// The specified print monitor does not have the required functions.

	, PRINT_MONITOR_IN_USE =
#	if defined ERROR_PRINT_MONITOR_IN_USE
			ERROR_PRINT_MONITOR_IN_USE
#	else
			0xBC0
#	endif
		// The specified print monitor is currently in use.

	, PRINTER_HAS_JOBS_QUEUED =
#	if defined ERROR_PRINTER_HAS_JOBS_QUEUED
			ERROR_PRINTER_HAS_JOBS_QUEUED
#	else
			0xBC1
#	endif
		// The requested operation is not allowed when there are jobs queued to the printer.

	, SUCCESS_REBOOT_REQUIRED =
#	if defined ERROR_SUCCESS_REBOOT_REQUIRED
			ERROR_SUCCESS_REBOOT_REQUIRED
#	else
			0xBC2
#	endif
		// The requested operation is successful. Changes will not be effective until the system is rebooted.

	, SUCCESS_RESTART_REQUIRED =
#	if defined ERROR_SUCCESS_RESTART_REQUIRED
			ERROR_SUCCESS_RESTART_REQUIRED
#	else
			0xBC3
#	endif
		// The requested operation is successful. Changes will not be effective until the service is restarted.

	, PRINTER_NOT_FOUND =
#	if defined ERROR_PRINTER_NOT_FOUND
			ERROR_PRINTER_NOT_FOUND
#	else
			0xBC4
#	endif
		// No printers were found.

	, PRINTER_DRIVER_WARNED =
#	if defined ERROR_PRINTER_DRIVER_WARNED
			ERROR_PRINTER_DRIVER_WARNED
#	else
			0xBC5
#	endif
		// The printer driver is known to be unreliable.

	, PRINTER_DRIVER_BLOCKED =
#	if defined ERROR_PRINTER_DRIVER_BLOCKED
			ERROR_PRINTER_DRIVER_BLOCKED
#	else
			0xBC6
#	endif
		// The printer driver is known to harm the system.

	, PRINTER_DRIVER_PACKAGE_IN_USE =
#	if defined ERROR_PRINTER_DRIVER_PACKAGE_IN_USE
			ERROR_PRINTER_DRIVER_PACKAGE_IN_USE
#	else
			0xBC7
#	endif
		// The specified printer driver package is currently in use.

	, CORE_DRIVER_PACKAGE_NOT_FOUND =
#	if defined ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND
			ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND
#	else
			0xBC8
#	endif
		// Unable to find a core driver package that is required by the printer driver package.

	, FAIL_REBOOT_REQUIRED =
#	if defined ERROR_FAIL_REBOOT_REQUIRED
			ERROR_FAIL_REBOOT_REQUIRED
#	else
			0xBC9
#	endif
		// The requested operation failed. A system reboot is required to roll back changes made.

	, FAIL_REBOOT_INITIATED =
#	if defined ERROR_FAIL_REBOOT_INITIATED
			ERROR_FAIL_REBOOT_INITIATED
#	else
			0xBCA
#	endif
		// The requested operation failed. A system reboot has been initiated to roll back changes made.

	, PRINTER_DRIVER_DOWNLOAD_NEEDED =
#	if defined ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED
			ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED
#	else
			0xBCB
#	endif
		// The specified printer driver was not found on the system and needs to be downloaded.

	, PRINT_JOB_RESTART_REQUIRED =
#	if defined ERROR_PRINT_JOB_RESTART_REQUIRED
			ERROR_PRINT_JOB_RESTART_REQUIRED
#	else
			0xBCC
#	endif
		// The requested print job has failed to print. A print system update requires the job to be resubmitted.

	, INVALID_PRINTER_DRIVER_MANIFEST =
#	if defined ERROR_INVALID_PRINTER_DRIVER_MANIFEST
			ERROR_INVALID_PRINTER_DRIVER_MANIFEST
#	else
			0xBCD
#	endif
		// The printer driver does not contain a valid manifest, or contains too many manifests.

	, PRINTER_NOT_SHAREABLE =
#	if defined ERROR_PRINTER_NOT_SHAREABLE
			ERROR_PRINTER_NOT_SHAREABLE
#	else
			0xBCE
#	endif
		// The specified printer cannot be shared.

	, REQUEST_PAUSED =
#	if defined ERROR_REQUEST_PAUSED
			ERROR_REQUEST_PAUSED
#	else
			0xBEA
#	endif
		// The operation was paused.

	, IO_REISSUE_AS_CACHED =
#	if defined ERROR_IO_REISSUE_AS_CACHED
			ERROR_IO_REISSUE_AS_CACHED
#	else
			0xF6E
#	endif
		// Reissue the given operation as a cached IO operation.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString4(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::S_INVALID_STRING_BINDING:
			RETURN_STATIC_STRING(
					"The string binding is invalid"
			);
		case SystemCode::S_WRONG_KIND_OF_BINDING:
			RETURN_STATIC_STRING(
					"The binding handle is not the correct type"
			);
		case SystemCode::S_INVALID_BINDING:
			RETURN_STATIC_STRING(
					"The binding handle is invalid"
			);
		case SystemCode::S_PROTSEQ_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The RPC protocol sequence is not supported"
			);
		case SystemCode::S_INVALID_RPC_PROTSEQ:
			RETURN_STATIC_STRING(
					"The RPC protocol sequence is invalid"
			);
		case SystemCode::S_INVALID_STRING_UUID:
			RETURN_STATIC_STRING(
					"The string universal unique identifier (UUID) is invalid"
			);
		case SystemCode::S_INVALID_ENDPOINT_FORMAT:
			RETURN_STATIC_STRING(
					"The endpoint format is invalid"
			);
		case SystemCode::S_INVALID_NET_ADDR:
			RETURN_STATIC_STRING(
					"The network address is invalid"
			);
		case SystemCode::S_NO_ENDPOINT_FOUND:
			RETURN_STATIC_STRING(
					"No endpoint was found"
			);
		case SystemCode::S_INVALID_TIMEOUT:
			RETURN_STATIC_STRING(
					"The timeout value is invalid"
			);
		case SystemCode::S_OBJECT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The object universal unique identifier (UUID) was not found"
			);
		case SystemCode::S_ALREADY_REGISTERED:
			RETURN_STATIC_STRING(
					"The object universal unique identifier (UUID) has already been registered"
			);
		case SystemCode::S_TYPE_ALREADY_REGISTERED:
			RETURN_STATIC_STRING(
					"The type universal unique identifier (UUID) has already been registered"
			);
		case SystemCode::S_ALREADY_LISTENING:
			RETURN_STATIC_STRING(
					"The RPC server is already listening"
			);
		case SystemCode::S_NO_PROTSEQS_REGISTERED:
			RETURN_STATIC_STRING(
					"No protocol sequences have been registered"
			);
		case SystemCode::S_NOT_LISTENING:
			RETURN_STATIC_STRING(
					"The RPC server is not listening"
			);
		case SystemCode::S_UNKNOWN_MGR_TYPE:
			RETURN_STATIC_STRING(
					"The manager type is unknown"
			);
		case SystemCode::S_UNKNOWN_IF:
			RETURN_STATIC_STRING(
					"The interface is unknown"
			);
		case SystemCode::S_NO_BINDINGS:
			RETURN_STATIC_STRING(
					"There are no bindings"
			);
		case SystemCode::S_NO_PROTSEQS:
			RETURN_STATIC_STRING(
					"There are no protocol sequences"
			);
		case SystemCode::S_CANT_CREATE_ENDPOINT:
			RETURN_STATIC_STRING(
					"The endpoint cannot be created"
			);
		case SystemCode::S_OUT_OF_RESOURCES:
			RETURN_STATIC_STRING(
					"Not enough resources are available to complete this operation"
			);
		case SystemCode::S_SERVER_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"The RPC server is unavailable"
			);
		case SystemCode::S_SERVER_TOO_BUSY:
			RETURN_STATIC_STRING(
					"The RPC server is too busy to complete this operation"
			);
		case SystemCode::S_INVALID_NETWORK_OPTIONS:
			RETURN_STATIC_STRING(
					"The network options are invalid"
			);
		case SystemCode::S_NO_CALL_ACTIVE:
			RETURN_STATIC_STRING(
					"There are no remote procedure calls active on this thread"
			);
		case SystemCode::S_CALL_FAILED:
			RETURN_STATIC_STRING(
					"The remote procedure call failed"
			);
		case SystemCode::S_CALL_FAILED_DNE:
			RETURN_STATIC_STRING(
					"The remote procedure call failed and did not execute"
			);
		case SystemCode::S_PROTOCOL_ERROR:
			RETURN_STATIC_STRING(
					"A remote procedure call (RPC) protocol error occurred"
			);
		case SystemCode::S_PROXY_ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"Access to the HTTP proxy is denied"
			);
		case SystemCode::S_UNSUPPORTED_TRANS_SYN:
			RETURN_STATIC_STRING(
					"The transfer syntax is not supported by the RPC server"
			);
		case SystemCode::S_UNSUPPORTED_TYPE:
			RETURN_STATIC_STRING(
					"The universal unique identifier (UUID) type is not supported"
			);
		case SystemCode::S_INVALID_TAG:
			RETURN_STATIC_STRING(
					"The tag is invalid"
			);
		case SystemCode::S_INVALID_BOUND:
			RETURN_STATIC_STRING(
					"The array bounds are invalid"
			);
		case SystemCode::S_NO_ENTRY_NAME:
			RETURN_STATIC_STRING(
					"The binding does not contain an entry name"
			);
		case SystemCode::S_INVALID_NAME_SYNTAX:
			RETURN_STATIC_STRING(
					"The name syntax is invalid"
			);
		case SystemCode::S_UNSUPPORTED_NAME_SYNTAX:
			RETURN_STATIC_STRING(
					"The name syntax is not supported"
			);
		case SystemCode::S_UUID_NO_ADDRESS:
			RETURN_STATIC_STRING(
					"No network address is available to use to construct a universal unique identifier (UUID)"
			);
		case SystemCode::S_DUPLICATE_ENDPOINT:
			RETURN_STATIC_STRING(
					"The endpoint is a duplicate"
			);
		case SystemCode::S_UNKNOWN_AUTHN_TYPE:
			RETURN_STATIC_STRING(
					"The authentication type is unknown"
			);
		case SystemCode::S_MAX_CALLS_TOO_SMALL:
			RETURN_STATIC_STRING(
					"The maximum number of calls is too small"
			);
		case SystemCode::S_STRING_TOO_LONG:
			RETURN_STATIC_STRING(
					"The string is too long"
			);
		case SystemCode::S_PROTSEQ_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The RPC protocol sequence was not found"
			);
		case SystemCode::S_PROCNUM_OUT_OF_RANGE:
			RETURN_STATIC_STRING(
					"The procedure number is out of range"
			);
		case SystemCode::S_BINDING_HAS_NO_AUTH:
			RETURN_STATIC_STRING(
					"The binding does not contain any authentication information"
			);
		case SystemCode::S_UNKNOWN_AUTHN_SERVICE:
			RETURN_STATIC_STRING(
					"The authentication service is unknown"
			);
		case SystemCode::S_UNKNOWN_AUTHN_LEVEL:
			RETURN_STATIC_STRING(
					"The authentication level is unknown"
			);
		case SystemCode::S_INVALID_AUTH_IDENTITY:
			RETURN_STATIC_STRING(
					"The security context is invalid"
			);
		case SystemCode::S_UNKNOWN_AUTHZ_SERVICE:
			RETURN_STATIC_STRING(
					"The authorization service is unknown"
			);
		case SystemCode::S_INVALID_ENTRY:
			RETURN_STATIC_STRING(
					"The entry is invalid"
			);
		case SystemCode::S_CANT_PERFORM_OP:
			RETURN_STATIC_STRING(
					"The server endpoint cannot perform the operation"
			);
		case SystemCode::S_NOT_REGISTERED:
			RETURN_STATIC_STRING(
					"There are no more endpoints available from the endpoint mapper"
			);
		case SystemCode::S_NOTHING_TO_EXPORT:
			RETURN_STATIC_STRING(
					"No interfaces have been exported"
			);
		case SystemCode::S_INCOMPLETE_NAME:
			RETURN_STATIC_STRING(
					"The entry name is incomplete"
			);
		case SystemCode::S_INVALID_VERS_OPTION:
			RETURN_STATIC_STRING(
					"The version option is invalid"
			);
		case SystemCode::S_NO_MORE_MEMBERS:
			RETURN_STATIC_STRING(
					"There are no more members"
			);
		case SystemCode::S_NOT_ALL_OBJS_UNEXPORTED:
			RETURN_STATIC_STRING(
					"There is nothing to unexport"
			);
		case SystemCode::S_INTERFACE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The interface was not found"
			);
		case SystemCode::S_ENTRY_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The entry already exists"
			);
		case SystemCode::S_ENTRY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The entry is not found"
			);
		case SystemCode::S_NAME_SERVICE_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"The name service is unavailable"
			);
		case SystemCode::S_INVALID_NAF_ID:
			RETURN_STATIC_STRING(
					"The network address family is invalid"
			);
		case SystemCode::S_CANNOT_SUPPORT:
			RETURN_STATIC_STRING(
					"The requested operation is not supported"
			);
		case SystemCode::S_NO_CONTEXT_AVAILABLE:
			RETURN_STATIC_STRING(
					"No security context is available to allow impersonation"
			);
		case SystemCode::S_INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"An internal error occurred in a remote procedure call (RPC)"
			);
		case SystemCode::S_ZERO_DIVIDE:
			RETURN_STATIC_STRING(
					"The RPC server attempted an integer division by zero"
			);
		case SystemCode::S_ADDRESS_ERROR:
			RETURN_STATIC_STRING(
					"An addressing error occurred in the RPC server"
			);
		case SystemCode::S_FP_DIV_ZERO:
			RETURN_STATIC_STRING(
					"A floating-point operation at the RPC server caused a division by zero"
			);
		case SystemCode::S_FP_UNDERFLOW:
			RETURN_STATIC_STRING(
					"A floating-point underflow occurred at the RPC server"
			);
		case SystemCode::S_FP_OVERFLOW:
			RETURN_STATIC_STRING(
					"A floating-point overflow occurred at the RPC server"
			);
		case SystemCode::X_NO_MORE_ENTRIES:
			RETURN_STATIC_STRING(
					"The list of RPC servers available for the binding of auto handles has been exhausted"
			);
		case SystemCode::X_SS_CHAR_TRANS_OPEN_FAIL:
			RETURN_STATIC_STRING(
					"Unable to open the character translation table file"
			);
		case SystemCode::X_SS_CHAR_TRANS_SHORT_FILE:
			RETURN_STATIC_STRING(
					"The file containing the character translation table has fewer than 512 bytes"
			);
		case SystemCode::X_SS_IN_NULL_CONTEXT:
			RETURN_STATIC_STRING(
					"A null context handle was passed from the client to the host during a remote procedure call"
			);
		case SystemCode::X_SS_CONTEXT_DAMAGED:
			RETURN_STATIC_STRING(
					"The context handle changed during a remote procedure call"
			);
		case SystemCode::X_SS_HANDLES_MISMATCH:
			RETURN_STATIC_STRING(
					"The binding handles passed to a remote procedure call do not match"
			);
		case SystemCode::X_SS_CANNOT_GET_CALL_HANDLE:
			RETURN_STATIC_STRING(
					"The stub is unable to get the remote procedure call handle"
			);
		case SystemCode::X_NULL_REF_POINTER:
			RETURN_STATIC_STRING(
					"A null reference pointer was passed to the stub"
			);
		case SystemCode::X_ENUM_VALUE_OUT_OF_RANGE:
			RETURN_STATIC_STRING(
					"The enumeration value is out of range"
			);
		case SystemCode::X_BYTE_COUNT_TOO_SMALL:
			RETURN_STATIC_STRING(
					"The byte count is too small"
			);
		case SystemCode::X_BAD_STUB_DATA:
			RETURN_STATIC_STRING(
					"The stub received bad data"
			);
		case SystemCode::INVALID_USER_BUFFER:
			RETURN_STATIC_STRING(
					"The supplied user buffer is not valid for the requested operation"
			);
		case SystemCode::UNRECOGNIZED_MEDIA:
			RETURN_STATIC_STRING(
					"The disk media is not recognized. It may not be formatted"
			);
		case SystemCode::NO_TRUST_LSA_SECRET:
			RETURN_STATIC_STRING(
					"The workstation does not have a trust secret"
			);
		case SystemCode::NO_TRUST_SAM_ACCOUNT:
			RETURN_STATIC_STRING(
					"The security database on the server does not have a computer account for this workstation trust relationship"
			);
		case SystemCode::TRUSTED_DOMAIN_FAILURE:
			RETURN_STATIC_STRING(
					"The trust relationship between the primary domain and the trusted domain failed"
			);
		case SystemCode::TRUSTED_RELATIONSHIP_FAILURE:
			RETURN_STATIC_STRING(
					"The trust relationship between this workstation and the primary domain failed"
			);
		case SystemCode::TRUST_FAILURE:
			RETURN_STATIC_STRING(
					"The network logon failed"
			);
		case SystemCode::S_CALL_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A remote procedure call is already in progress for this thread"
			);
		case SystemCode::NETLOGON_NOT_STARTED:
			RETURN_STATIC_STRING(
					"An attempt was made to logon, but the network logon service was not started"
			);
		case SystemCode::ACCOUNT_EXPIRED:
			RETURN_STATIC_STRING(
					"The user's account has expired"
			);
		case SystemCode::REDIRECTOR_HAS_OPEN_HANDLES:
			RETURN_STATIC_STRING(
					"The redirector is in use and cannot be unloaded"
			);
		case SystemCode::PRINTER_DRIVER_ALREADY_INSTALLED:
			RETURN_STATIC_STRING(
					"The specified printer driver is already installed"
			);
		case SystemCode::UNKNOWN_PORT:
			RETURN_STATIC_STRING(
					"The specified port is unknown"
			);
		case SystemCode::UNKNOWN_PRINTER_DRIVER:
			RETURN_STATIC_STRING(
					"The printer driver is unknown"
			);
		case SystemCode::UNKNOWN_PRINTPROCESSOR:
			RETURN_STATIC_STRING(
					"The print processor is unknown"
			);
		case SystemCode::INVALID_SEPARATOR_FILE:
			RETURN_STATIC_STRING(
					"The specified separator file is invalid"
			);
		case SystemCode::INVALID_PRIORITY:
			RETURN_STATIC_STRING(
					"The specified priority is invalid"
			);
		case SystemCode::INVALID_PRINTER_NAME:
			RETURN_STATIC_STRING(
					"The printer name is invalid"
			);
		case SystemCode::PRINTER_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The printer already exists"
			);
		case SystemCode::INVALID_PRINTER_COMMAND:
			RETURN_STATIC_STRING(
					"The printer command is invalid"
			);
		case SystemCode::INVALID_DATATYPE:
			RETURN_STATIC_STRING(
					"The specified datatype is invalid"
			);
		case SystemCode::INVALID_ENVIRONMENT:
			RETURN_STATIC_STRING(
					"The environment specified is invalid"
			);
		case SystemCode::S_NO_MORE_BINDINGS:
			RETURN_STATIC_STRING(
					"There are no more bindings"
			);
		case SystemCode::NOLOGON_INTERDOMAIN_TRUST_ACCOUNT:
			RETURN_STATIC_STRING(
					"The account used is an interdomain trust account. Use your global user account or local user account to access this server"
			);
		case SystemCode::NOLOGON_WORKSTATION_TRUST_ACCOUNT:
			RETURN_STATIC_STRING(
					"The account used is a computer account. Use your global user account or local user account to access this server"
			);
		case SystemCode::NOLOGON_SERVER_TRUST_ACCOUNT:
			RETURN_STATIC_STRING(
					"The account used is a server trust account. Use your global user account or local user account to access this server"
			);
		case SystemCode::DOMAIN_TRUST_INCONSISTENT:
			RETURN_STATIC_STRING(
					"The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain"
			);
		case SystemCode::SERVER_HAS_OPEN_HANDLES:
			RETURN_STATIC_STRING(
					"The server is in use and cannot be unloaded"
			);
		case SystemCode::RESOURCE_DATA_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified image file did not contain a resource section"
			);
		case SystemCode::RESOURCE_TYPE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified resource type cannot be found in the image file"
			);
		case SystemCode::RESOURCE_NAME_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified resource name cannot be found in the image file"
			);
		case SystemCode::RESOURCE_LANG_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified resource language ID cannot be found in the image file"
			);
		case SystemCode::NOT_ENOUGH_QUOTA:
			RETURN_STATIC_STRING(
					"Not enough quota is available to process this command"
			);
		case SystemCode::S_NO_INTERFACES:
			RETURN_STATIC_STRING(
					"No interfaces have been registered"
			);
		case SystemCode::S_CALL_CANCELLED:
			RETURN_STATIC_STRING(
					"The remote procedure call was cancelled"
			);
		case SystemCode::S_BINDING_INCOMPLETE:
			RETURN_STATIC_STRING(
					"The binding handle does not contain all required information"
			);
		case SystemCode::S_COMM_FAILURE:
			RETURN_STATIC_STRING(
					"A communications failure occurred during a remote procedure call"
			);
		case SystemCode::S_UNSUPPORTED_AUTHN_LEVEL:
			RETURN_STATIC_STRING(
					"The requested authentication level is not supported"
			);
		case SystemCode::S_NO_PRINC_NAME:
			RETURN_STATIC_STRING(
					"No principal name registered"
			);
		case SystemCode::S_NOT_RPC_ERROR:
			RETURN_STATIC_STRING(
					"The error specified is not a valid Windows RPC error code"
			);
		case SystemCode::S_UUID_LOCAL_ONLY:
			RETURN_STATIC_STRING(
					"A UUID that is valid only on this computer has been allocated"
			);
		case SystemCode::S_SEC_PKG_ERROR:
			RETURN_STATIC_STRING(
					"A security package specific error occurred"
			);
		case SystemCode::S_NOT_CANCELLED:
			RETURN_STATIC_STRING(
					"Thread is not canceled"
			);
		case SystemCode::X_INVALID_ES_ACTION:
			RETURN_STATIC_STRING(
					"Invalid operation on the encoding/decoding handle"
			);
		case SystemCode::X_WRONG_ES_VERSION:
			RETURN_STATIC_STRING(
					"Incompatible version of the serializing package"
			);
		case SystemCode::X_WRONG_STUB_VERSION:
			RETURN_STATIC_STRING(
					"Incompatible version of the RPC stub"
			);
		case SystemCode::X_INVALID_PIPE_OBJECT:
			RETURN_STATIC_STRING(
					"The RPC pipe object is invalid or corrupted"
			);
		case SystemCode::X_WRONG_PIPE_ORDER:
			RETURN_STATIC_STRING(
					"An invalid operation was attempted on an RPC pipe object"
			);
		case SystemCode::X_WRONG_PIPE_VERSION:
			RETURN_STATIC_STRING(
					"Unsupported RPC pipe version"
			);
		case SystemCode::S_COOKIE_AUTH_FAILED:
			RETURN_STATIC_STRING(
					"HTTP proxy server rejected the connection because the cookie authentication failed"
			);
		case SystemCode::S_GROUP_MEMBER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The group member was not found"
			);
		case SystemCode::S_CANT_CREATE:
			RETURN_STATIC_STRING(
					"The endpoint mapper database entry could not be created"
			);
		case SystemCode::S_INVALID_OBJECT:
			RETURN_STATIC_STRING(
					"The object universal unique identifier (UUID) is the nil UUID"
			);
		case SystemCode::INVALID_TIME:
			RETURN_STATIC_STRING(
					"The specified time is invalid"
			);
		case SystemCode::INVALID_FORM_NAME:
			RETURN_STATIC_STRING(
					"The specified form name is invalid"
			);
		case SystemCode::INVALID_FORM_SIZE:
			RETURN_STATIC_STRING(
					"The specified form size is invalid"
			);
		case SystemCode::ALREADY_WAITING:
			RETURN_STATIC_STRING(
					"The specified printer handle is already being waited on"
			);
		case SystemCode::PRINTER_DELETED:
			RETURN_STATIC_STRING(
					"The specified printer has been deleted"
			);
		case SystemCode::INVALID_PRINTER_STATE:
			RETURN_STATIC_STRING(
					"The state of the printer is invalid"
			);
		case SystemCode::PASSWORD_MUST_CHANGE:
			RETURN_STATIC_STRING(
					"The user's password must be changed before signing in"
			);
		case SystemCode::DOMAIN_CONTROLLER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Could not find the domain controller for this domain"
			);
		case SystemCode::ACCOUNT_LOCKED_OUT:
			RETURN_STATIC_STRING(
					"The referenced account is currently locked out and may not be logged on to"
			);
		case SystemCode::INVALID_OXID:
			RETURN_STATIC_STRING(
					"The object exporter specified was not found"
			);
		case SystemCode::INVALID_OID:
			RETURN_STATIC_STRING(
					"The object specified was not found"
			);
		case SystemCode::INVALID_SET:
			RETURN_STATIC_STRING(
					"The object resolver set specified was not found"
			);
		case SystemCode::S_SEND_INCOMPLETE:
			RETURN_STATIC_STRING(
					"Some data remains to be sent in the request buffer"
			);
		case SystemCode::S_INVALID_ASYNC_HANDLE:
			RETURN_STATIC_STRING(
					"Invalid asynchronous remote procedure call handle"
			);
		case SystemCode::S_INVALID_ASYNC_CALL:
			RETURN_STATIC_STRING(
					"Invalid asynchronous RPC call handle for this operation"
			);
		case SystemCode::X_PIPE_CLOSED:
			RETURN_STATIC_STRING(
					"The RPC pipe object has already been closed"
			);
		case SystemCode::X_PIPE_DISCIPLINE_ERROR:
			RETURN_STATIC_STRING(
					"The RPC call completed before all pipes were processed"
			);
		case SystemCode::X_PIPE_EMPTY:
			RETURN_STATIC_STRING(
					"No more data is available from the RPC pipe"
			);
		case SystemCode::NO_SITENAME:
			RETURN_STATIC_STRING(
					"No site name is available for this machine"
			);
		case SystemCode::CANT_ACCESS_FILE:
			RETURN_STATIC_STRING(
					"The file cannot be accessed by the system"
			);
		case SystemCode::CANT_RESOLVE_FILENAME:
			RETURN_STATIC_STRING(
					"The name of the file cannot be resolved by the system"
			);
		case SystemCode::S_ENTRY_TYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"The entry is not of the expected type"
			);
		case SystemCode::S_NOT_ALL_OBJS_EXPORTED:
			RETURN_STATIC_STRING(
					"Not all object UUIDs could be exported to the specified entry"
			);
		case SystemCode::S_INTERFACE_NOT_EXPORTED:
			RETURN_STATIC_STRING(
					"Interface could not be exported to the specified entry"
			);
		case SystemCode::S_PROFILE_NOT_ADDED:
			RETURN_STATIC_STRING(
					"The specified profile entry could not be added"
			);
		case SystemCode::S_PRF_ELT_NOT_ADDED:
			RETURN_STATIC_STRING(
					"The specified profile element could not be added"
			);
		case SystemCode::S_PRF_ELT_NOT_REMOVED:
			RETURN_STATIC_STRING(
					"The specified profile element could not be removed"
			);
		case SystemCode::S_GRP_ELT_NOT_ADDED:
			RETURN_STATIC_STRING(
					"The group element could not be added"
			);
		case SystemCode::S_GRP_ELT_NOT_REMOVED:
			RETURN_STATIC_STRING(
					"The group element could not be removed"
			);
		case SystemCode::KM_DRIVER_BLOCKED:
			RETURN_STATIC_STRING(
					"The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers"
			);
		case SystemCode::CONTEXT_EXPIRED:
			RETURN_STATIC_STRING(
					"The context has expired and can no longer be used"
			);
		case SystemCode::PER_USER_TRUST_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"The current user's delegated trust creation quota has been exceeded"
			);
		case SystemCode::ALL_USER_TRUST_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"The total delegated trust creation quota has been exceeded"
			);
		case SystemCode::USER_DELETE_TRUST_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"The current user's delegated trust deletion quota has been exceeded"
			);
		case SystemCode::AUTHENTICATION_FIREWALL_FAILED:
			RETURN_STATIC_STRING(
					"The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer"
			);
		case SystemCode::REMOTE_PRINT_CONNECTIONS_BLOCKED:
			RETURN_STATIC_STRING(
					"Remote connections to the Print Spooler are blocked by a policy set on your machine"
			);
		case SystemCode::NTLM_BLOCKED:
			RETURN_STATIC_STRING(
					"Authentication failed because NTLM authentication has been disabled"
			);
		case SystemCode::PASSWORD_CHANGE_REQUIRED:
			RETURN_STATIC_STRING(
					"Logon Failure: EAS policy requires that the user change their password before this operation can be performed"
			);
		case SystemCode::INVALID_PIXEL_FORMAT:
			RETURN_STATIC_STRING(
					"The pixel format is invalid"
			);
		case SystemCode::BAD_DRIVER:
			RETURN_STATIC_STRING(
					"The specified driver is invalid"
			);
		case SystemCode::INVALID_WINDOW_STYLE:
			RETURN_STATIC_STRING(
					"The window style or class attribute is invalid for this operation"
			);
		case SystemCode::METAFILE_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The requested metafile operation is not supported"
			);
		case SystemCode::TRANSFORM_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The requested transformation operation is not supported"
			);
		case SystemCode::CLIPPING_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The requested clipping operation is not supported"
			);
		case SystemCode::INVALID_CMM:
			RETURN_STATIC_STRING(
					"The specified color management module is invalid"
			);
		case SystemCode::INVALID_PROFILE:
			RETURN_STATIC_STRING(
					"The specified color profile is invalid"
			);
		case SystemCode::TAG_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified tag was not found"
			);
		case SystemCode::TAG_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"A required tag is not present"
			);
		case SystemCode::DUPLICATE_TAG:
			RETURN_STATIC_STRING(
					"The specified tag is already present"
			);
		case SystemCode::PROFILE_NOT_ASSOCIATED_WITH_DEVICE:
			RETURN_STATIC_STRING(
					"The specified color profile is not associated with the specified device"
			);
		case SystemCode::PROFILE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified color profile was not found"
			);
		case SystemCode::INVALID_COLORSPACE:
			RETURN_STATIC_STRING(
					"The specified color space is invalid"
			);
		case SystemCode::ICM_NOT_ENABLED:
			RETURN_STATIC_STRING(
					"Image Color Management is not enabled"
			);
		case SystemCode::DELETING_ICM_XFORM:
			RETURN_STATIC_STRING(
					"There was an error while deleting the color transform"
			);
		case SystemCode::INVALID_TRANSFORM:
			RETURN_STATIC_STRING(
					"The specified color transform is invalid"
			);
		case SystemCode::COLORSPACE_MISMATCH:
			RETURN_STATIC_STRING(
					"The specified transform does not match the bitmap's color space"
			);
		case SystemCode::INVALID_COLORINDEX:
			RETURN_STATIC_STRING(
					"The specified named color index is not present in the profile"
			);
		case SystemCode::PROFILE_DOES_NOT_MATCH_DEVICE:
			RETURN_STATIC_STRING(
					"The specified profile is intended for a device of a different type than the specified device"
			);
		case SystemCode::CONNECTED_OTHER_PASSWORD:
			RETURN_STATIC_STRING(
					"The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified"
			);
		case SystemCode::CONNECTED_OTHER_PASSWORD_DEFAULT:
			RETURN_STATIC_STRING(
					"The network connection was made successfully using default credentials"
			);
		case SystemCode::BAD_USERNAME:
			RETURN_STATIC_STRING(
					"The specified username is invalid"
			);
		case SystemCode::NOT_CONNECTED:
			RETURN_STATIC_STRING(
					"This network connection does not exist"
			);
		case SystemCode::OPEN_FILES:
			RETURN_STATIC_STRING(
					"This network connection has files open or requests pending"
			);
		case SystemCode::ACTIVE_CONNECTIONS:
			RETURN_STATIC_STRING(
					"Active connections still exist"
			);
		case SystemCode::DEVICE_IN_USE:
			RETURN_STATIC_STRING(
					"The device is in use by an active process and cannot be disconnected"
			);
		case SystemCode::UNKNOWN_PRINT_MONITOR:
			RETURN_STATIC_STRING(
					"The specified print monitor is unknown"
			);
		case SystemCode::PRINTER_DRIVER_IN_USE:
			RETURN_STATIC_STRING(
					"The specified printer driver is currently in use"
			);
		case SystemCode::SPOOL_FILE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The spool file was not found"
			);
		case SystemCode::SPL_NO_STARTDOC:
			RETURN_STATIC_STRING(
					"A StartDocPrinter call was not issued"
			);
		case SystemCode::SPL_NO_ADDJOB:
			RETURN_STATIC_STRING(
					"An AddJob call was not issued"
			);
		case SystemCode::PRINT_PROCESSOR_ALREADY_INSTALLED:
			RETURN_STATIC_STRING(
					"The specified print processor has already been installed"
			);
		case SystemCode::PRINT_MONITOR_ALREADY_INSTALLED:
			RETURN_STATIC_STRING(
					"The specified print monitor has already been installed"
			);
		case SystemCode::INVALID_PRINT_MONITOR:
			RETURN_STATIC_STRING(
					"The specified print monitor does not have the required functions"
			);
		case SystemCode::PRINT_MONITOR_IN_USE:
			RETURN_STATIC_STRING(
					"The specified print monitor is currently in use"
			);
		case SystemCode::PRINTER_HAS_JOBS_QUEUED:
			RETURN_STATIC_STRING(
					"The requested operation is not allowed when there are jobs queued to the printer"
			);
		case SystemCode::SUCCESS_REBOOT_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation is successful. Changes will not be effective until the system is rebooted"
			);
		case SystemCode::SUCCESS_RESTART_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation is successful. Changes will not be effective until the service is restarted"
			);
		case SystemCode::PRINTER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"No printers were found"
			);
		case SystemCode::PRINTER_DRIVER_WARNED:
			RETURN_STATIC_STRING(
					"The printer driver is known to be unreliable"
			);
		case SystemCode::PRINTER_DRIVER_BLOCKED:
			RETURN_STATIC_STRING(
					"The printer driver is known to harm the system"
			);
		case SystemCode::PRINTER_DRIVER_PACKAGE_IN_USE:
			RETURN_STATIC_STRING(
					"The specified printer driver package is currently in use"
			);
		case SystemCode::CORE_DRIVER_PACKAGE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Unable to find a core driver package that is required by the printer driver package"
			);
		case SystemCode::FAIL_REBOOT_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation failed. A system reboot is required to roll back changes made"
			);
		case SystemCode::FAIL_REBOOT_INITIATED:
			RETURN_STATIC_STRING(
					"The requested operation failed. A system reboot has been initiated to roll back changes made"
			);
		case SystemCode::PRINTER_DRIVER_DOWNLOAD_NEEDED:
			RETURN_STATIC_STRING(
					"The specified printer driver was not found on the system and needs to be downloaded"
			);
		case SystemCode::PRINT_JOB_RESTART_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested print job has failed to print. A print system update requires the job to be resubmitted"
			);
		case SystemCode::INVALID_PRINTER_DRIVER_MANIFEST:
			RETURN_STATIC_STRING(
					"The printer driver does not contain a valid manifest, or contains too many manifests"
			);
		case SystemCode::PRINTER_NOT_SHAREABLE:
			RETURN_STATIC_STRING(
					"The specified printer cannot be shared"
			);
		case SystemCode::REQUEST_PAUSED:
			RETURN_STATIC_STRING(
					"The operation was paused"
			);
		case SystemCode::IO_REISSUE_AS_CACHED:
			RETURN_STATIC_STRING(
					"Reissue the given operation as a cached IO operation"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
