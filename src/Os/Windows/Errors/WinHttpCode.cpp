#include <FlameIDE/../../src/Os/Windows/WinHttpCode.hpp>

#include <FlameIDE/Os/Types.hpp>

#include <winerror.h>

#define RETURN_STATIC_STRING(string) \
{ \
	static const char returnString[] = string; \
	return &returnString[0]; \
}

namespace flame_ide
{namespace os
{namespace error
{

// https://learn.microsoft.com/en-us/windows/win32/winhttp/error-messages
enum class WinHttpCode: decltype(::GetLastError())
{

	WINHTTP_AUTO_PROXY_SERVICE_ERROR =
#	if defined ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR
			ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR
#	else
			12178
#	endif
		// Returned by WinHttpGetProxyForUrl when a proxy for the specified URL cannot be located.

	, WINHTTP_AUTODETECTION_FAILED =
#	if defined ERROR_WINHTTP_AUTODETECTION_FAILED
			ERROR_WINHTTP_AUTODETECTION_FAILED
#	else
			12180
#	endif
		// Returned by WinHttpDetectAutoProxyConfigUrl if WinHTTP was unable to discover the URL of the Proxy Auto-Configuration (PAC) file.

	, WINHTTP_BAD_AUTO_PROXY_SCRIPT =
#	if defined ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT
			ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT
#	else
			12166
#	endif
		// An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file.

	, WINHTTP_CANNOT_CALL_AFTER_OPEN =
#	if defined ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN
			ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN
#	else
			12103
#	endif
		// Returned by the HttpRequest object if a specified option cannot be requested after the Open method has been called.

	, WINHTTP_CANNOT_CALL_AFTER_SEND =
#	if defined ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND
			ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND
#	else
			12102
#	endif
		// Returned by the HttpRequest object if a requested operation cannot be performed after calling the Send method.

	, WINHTTP_CANNOT_CALL_BEFORE_OPEN =
#	if defined ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN
			ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN
#	else
			12100
#	endif
		// Returned by the HttpRequest object if a requested operation cannot be performed before calling the Open method.

	, WINHTTP_CANNOT_CALL_BEFORE_SEND =
#	if defined ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND
			ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND
#	else
			12101
#	endif
		// Returned by the HttpRequest object if a requested operation cannot be performed before calling the Send method.

	, WINHTTP_CANNOT_CONNECT =
#	if defined ERROR_WINHTTP_CANNOT_CONNECT
			ERROR_WINHTTP_CANNOT_CONNECT
#	else
			12029
#	endif
		// Returned if connection to the server failed.

//	, WINHTTP_CLIENT_AUTH_CERT_NEEDED =
//#	if defined ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
//			ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
//#	else
//			?
//#	endif
		// The server requires SSL client Authentication. The application retrieves the list of certificate issuers by calling WinHttpQueryOption with the WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST option. For more information, see the WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST option. If the server requests the client certificate, but does not require it, the application can alternately call WinHttpSetOption with the WINHTTP_OPTION_CLIENT_CERT_CONTEXT option. In this case, the application specifies the WINHTTP_NO_CLIENT_CERT_CONTEXT macro in the lpBuffer parameter of WinHttpSetOption. For more information, see the WINHTTP_OPTION_CLIENT_CERT_CONTEXT option. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

//	, WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY =
//#	if defined ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY
//			ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY
//#	else
//			?
//#	endif
		// The application does not have the required privileges to access the private key associated with the client certificate. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

//	, WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY =
//#	if defined ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY
//			ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY
//#	else
//			?
//#	endif
		// The context for the SSL client certificate does not have a private key associated with it. The client certificate may have been imported to the computer without the private key. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

	, WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW =
#	if defined ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW
			ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW
#	else
			12183
#	endif
		// Returned by WinHttpReceiveResponse when an overflow condition is encountered in the course of parsing chunked encoding.

	, WINHTTP_CLIENT_AUTH_CERT_NEEDED =
#	if defined ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
			ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
#	else
			12044
#	endif
		// Returned by WinHttpReceiveResponse when the server requests client authentication. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

	, WINHTTP_CONNECTION_ERROR =
#	if defined ERROR_WINHTTP_CONNECTION_ERROR
			ERROR_WINHTTP_CONNECTION_ERROR
#	else
			12030
#	endif
		// The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it.

	, WINHTTP_HEADER_ALREADY_EXISTS =
#	if defined ERROR_WINHTTP_HEADER_ALREADY_EXISTS
			ERROR_WINHTTP_HEADER_ALREADY_EXISTS
#	else
			12155
#	endif
		// Obsolete; no longer used.

	, WINHTTP_HEADER_COUNT_EXCEEDED =
#	if defined ERROR_WINHTTP_HEADER_COUNT_EXCEEDED
			ERROR_WINHTTP_HEADER_COUNT_EXCEEDED
#	else
			12181
#	endif
		// Returned by WinHttpReceiveResponse when a larger number of headers were present in a response than WinHTTP could receive.

	, WINHTTP_HEADER_NOT_FOUND =
#	if defined ERROR_WINHTTP_HEADER_NOT_FOUND
			ERROR_WINHTTP_HEADER_NOT_FOUND
#	else
			12150
#	endif
		// The requested header cannot be located.

	, WINHTTP_HEADER_SIZE_OVERFLOW =
#	if defined ERROR_WINHTTP_HEADER_SIZE_OVERFLOW
			ERROR_WINHTTP_HEADER_SIZE_OVERFLOW
#	else
			12182
#	endif
		// Returned by WinHttpReceiveResponse when the size of headers received exceeds the limit for the request handle.

	, WINHTTP_INCORRECT_HANDLE_STATE =
#	if defined ERROR_WINHTTP_INCORRECT_HANDLE_STATE
			ERROR_WINHTTP_INCORRECT_HANDLE_STATE
#	else
			12019
#	endif
		// The requested operation cannot be carried out because the handle supplied is not in the correct state.

	, WINHTTP_INCORRECT_HANDLE_TYPE =
#	if defined ERROR_WINHTTP_INCORRECT_HANDLE_TYPE
			ERROR_WINHTTP_INCORRECT_HANDLE_TYPE
#	else
			12018
#	endif
		// The type of handle supplied is incorrect for this operation.

	, WINHTTP_INTERNAL_ERROR =
#	if defined ERROR_WINHTTP_INTERNAL_ERROR
			ERROR_WINHTTP_INTERNAL_ERROR
#	else
			12004
#	endif
		// An internal error has occurred.

	, WINHTTP_INVALID_OPTION =
#	if defined ERROR_WINHTTP_INVALID_OPTION
			ERROR_WINHTTP_INVALID_OPTION
#	else
			12009
#	endif
		// A request to WinHttpQueryOption or WinHttpSetOption specified an invalid option value.

	, WINHTTP_INVALID_QUERY_REQUEST =
#	if defined ERROR_WINHTTP_INVALID_QUERY_REQUEST
			ERROR_WINHTTP_INVALID_QUERY_REQUEST
#	else
			12154
#	endif
		// Obsolete; no longer used.

	, WINHTTP_INVALID_SERVER_RESPONSE =
#	if defined ERROR_WINHTTP_INVALID_SERVER_RESPONSE
			ERROR_WINHTTP_INVALID_SERVER_RESPONSE
#	else
			12152
#	endif
		// The server response cannot be parsed.

	, WINHTTP_INVALID_URL =
#	if defined ERROR_WINHTTP_INVALID_URL
			ERROR_WINHTTP_INVALID_URL
#	else
			12005
#	endif
		// The URL is not valid.

	, WINHTTP_LOGIN_FAILURE =
#	if defined ERROR_WINHTTP_LOGIN_FAILURE
			ERROR_WINHTTP_LOGIN_FAILURE
#	else
			12015
#	endif
		// The login attempt failed. When this error is encountered, the request handle should be closed with WinHttpCloseHandle. A new request handle must be created before retrying the function that originally produced this error.

	, WINHTTP_NAME_NOT_RESOLVED =
#	if defined ERROR_WINHTTP_NAME_NOT_RESOLVED
			ERROR_WINHTTP_NAME_NOT_RESOLVED
#	else
			12007
#	endif
		// The server name cannot be resolved.

	, WINHTTP_NOT_INITIALIZED =
#	if defined ERROR_WINHTTP_NOT_INITIALIZED
			ERROR_WINHTTP_NOT_INITIALIZED
#	else
			12172
#	endif
		// Obsolete; no longer used.

	, WINHTTP_OPERATION_CANCELLED =
#	if defined ERROR_WINHTTP_OPERATION_CANCELLED
			ERROR_WINHTTP_OPERATION_CANCELLED
#	else
			12017
#	endif
		// The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.

	, WINHTTP_OPTION_NOT_SETTABLE =
#	if defined ERROR_WINHTTP_OPTION_NOT_SETTABLE
			ERROR_WINHTTP_OPTION_NOT_SETTABLE
#	else
			12011
#	endif
		// The requested option cannot be set, only queried.

	, WINHTTP_OUT_OF_HANDLES =
#	if defined ERROR_WINHTTP_OUT_OF_HANDLES
			ERROR_WINHTTP_OUT_OF_HANDLES
#	else
			12001
#	endif
		// Obsolete; no longer used.

	, WINHTTP_REDIRECT_FAILED =
#	if defined ERROR_WINHTTP_REDIRECT_FAILED
			ERROR_WINHTTP_REDIRECT_FAILED
#	else
			12156
#	endif
		// The redirection failed because either the scheme changed or all attempts made to redirect failed (default is five attempts).

	, WINHTTP_RESEND_REQUEST =
#	if defined ERROR_WINHTTP_RESEND_REQUEST
			ERROR_WINHTTP_RESEND_REQUEST
#	else
			12032
#	endif
		// The WinHTTP function failed. The desired function can be retried on the same request handle.

	, WINHTTP_RESPONSE_DRAIN_OVERFLOW =
#	if defined ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW
			ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW
#	else
			12184
#	endif
		// Returned when an incoming response exceeds an internal WinHTTP size limit.

	, WINHTTP_SCRIPT_EXECUTION_ERROR =
#	if defined ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR
			ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR
#	else
			12177
#	endif
		// An error was encountered while executing a script.

	, WINHTTP_SECURE_CERT_CN_INVALID =
#	if defined ERROR_WINHTTP_SECURE_CERT_CN_INVALID
			ERROR_WINHTTP_SECURE_CERT_CN_INVALID
#	else
			12038
#	endif
		// Returned when a certificate CN name does not match the passed value (equivalent to a CERT_E_CN_NO_MATCH error).

	, WINHTTP_SECURE_CERT_DATE_INVALID =
#	if defined ERROR_WINHTTP_SECURE_CERT_DATE_INVALID
			ERROR_WINHTTP_SECURE_CERT_DATE_INVALID
#	else
			12037
#	endif
		// Indicates that a required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file, or that the validity periods of the certification chain do not nest correctly (equivalent to a CERT_E_EXPIRED or a CERT_E_VALIDITYPERIODNESTING error).

	, WINHTTP_SECURE_CERT_REV_FAILED =
#	if defined ERROR_WINHTTP_SECURE_CERT_REV_FAILED
			ERROR_WINHTTP_SECURE_CERT_REV_FAILED
#	else
			12057
#	endif
		// Indicates that revocation cannot be checked because the revocation server was offline (equivalent to CRYPT_E_REVOCATION_OFFLINE).

	, WINHTTP_SECURE_CERT_REVOKED =
#	if defined ERROR_WINHTTP_SECURE_CERT_REVOKED
			ERROR_WINHTTP_SECURE_CERT_REVOKED
#	else
			12170
#	endif
		// Indicates that a certificate has been revoked (equivalent to CRYPT_E_REVOKED).

	, WINHTTP_SECURE_CERT_WRONG_USAGE =
#	if defined ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE
			ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE
#	else
			12179
#	endif
		// Indicates that a certificate is not valid for the requested usage (equivalent to CERT_E_WRONG_USAGE).

	, WINHTTP_SECURE_CHANNEL_ERROR =
#	if defined ERROR_WINHTTP_SECURE_CHANNEL_ERROR
			ERROR_WINHTTP_SECURE_CHANNEL_ERROR
#	else
			12157
#	endif
		// Indicates that an error occurred having to do with a secure channel (equivalent to error codes that begin with "SEC_E_" and "SEC_I_" listed in the "winerror.h" header file).

	, WINHTTP_SECURE_FAILURE =
#	if defined ERROR_WINHTTP_SECURE_FAILURE
			ERROR_WINHTTP_SECURE_FAILURE
#	else
			12175
#	endif
		// One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, check for a WINHTTP_CALLBACK_STATUS_SECURE_FAILURE notification in a status callback function. For more information, see WINHTTP_STATUS_CALLBACK.

	, WINHTTP_SECURE_INVALID_CA =
#	if defined ERROR_WINHTTP_SECURE_INVALID_CA
			ERROR_WINHTTP_SECURE_INVALID_CA
#	else
			12045
#	endif
		// Indicates that a certificate chain was processed, but terminated in a root certificate that is not trusted by the trust provider (equivalent to CERT_E_UNTRUSTEDROOT).

	, WINHTTP_SECURE_INVALID_CERT =
#	if defined ERROR_WINHTTP_SECURE_INVALID_CERT
			ERROR_WINHTTP_SECURE_INVALID_CERT
#	else
			12169
#	endif
		// Indicates that a certificate is invalid (equivalent to errors such as CERT_E_ROLE, CERT_E_PATHLENCONST, CERT_E_CRITICAL, CERT_E_PURPOSE, CERT_E_ISSUERCHAINING, CERT_E_MALFORMED and CERT_E_CHAINING).

	, WINHTTP_SHUTDOWN =
#	if defined ERROR_WINHTTP_SHUTDOWN
			ERROR_WINHTTP_SHUTDOWN
#	else
			12012
#	endif
		// The WinHTTP function support is being shut down or unloaded.

	, WINHTTP_TIMEOUT =
#	if defined ERROR_WINHTTP_TIMEOUT
			ERROR_WINHTTP_TIMEOUT
#	else
			12002
#	endif
		// The request has timed out. This error can be returned as a result of TCP/IP time-out behavior, regardless of time-out values set in Windows HTTP Services.

	, WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT =
#	if defined ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT
			ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT
#	else
			12167
#	endif
		// The PAC file cannot be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response.

	, WINHTTP_UNHANDLED_SCRIPT_TYPE =
#	if defined ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE
			ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE
#	else
			12176
#	endif
		// The script type is not supported.

	, WINHTTP_UNRECOGNIZED_SCHEME =
#	if defined ERROR_WINHTTP_UNRECOGNIZED_SCHEME
			ERROR_WINHTTP_UNRECOGNIZED_SCHEME
#	else
			12006
#	endif
		// The URL specified a scheme other than "http:" or "https:".

	, NOT_ENOUGH_MEMORY =
#	if defined ERROR_NOT_ENOUGH_MEMORY
			ERROR_NOT_ENOUGH_MEMORY
#	else
			8
#	endif
		// Not enough memory was available to complete the requested operation. Header: Declared in Winerror.h

	, INSUFFICIENT_BUFFER =
#	if defined ERROR_INSUFFICIENT_BUFFER
			ERROR_INSUFFICIENT_BUFFER
#	else
			122
#	endif
		// The size, in bytes, of the buffer supplied to a function was insufficient to contain the returned data. For more information, see the specific function. Header: Declared in Winerror.h

	, INVALID_HANDLE =
#	if defined ERROR_INVALID_HANDLE
			ERROR_INVALID_HANDLE
#	else
			6
#	endif
		// The handle passed to the application programming interface (API) has been either invalidated or closed. Header: Declared in Winerror.h

	, NO_MORE_FILES =
#	if defined ERROR_NO_MORE_FILES
			ERROR_NO_MORE_FILES
#	else
			18
#	endif
		// No more files have been found. Header: Declared in Winerror.h

	, NO_MORE_ITEMS =
#	if defined ERROR_NO_MORE_ITEMS
			ERROR_NO_MORE_ITEMS
#	else
			259
#	endif
		// No more items have been found. Header: Declared in Winerror.h

	, NOT_SUPPORTED =
#	if defined ERROR_NOT_SUPPORTED
			ERROR_NOT_SUPPORTED
#	else
			50
#	endif
		// The required protocol stack is not loaded and the application cannot start WinSock. Header: Declared in Winerror.h
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *winHttpCodeToString(os::Status status) noexcept
{
	const auto code = static_cast<WinHttpCode>(status);
	switch (code)
	{
		case WinHttpCode::WINHTTP_AUTO_PROXY_SERVICE_ERROR:
			RETURN_STATIC_STRING(
					"Returned by WinHttpGetProxyForUrl when a proxy for the specified URL cannot be located"
			);
		case WinHttpCode::WINHTTP_AUTODETECTION_FAILED:
			RETURN_STATIC_STRING(
					"Returned by WinHttpDetectAutoProxyConfigUrl if WinHTTP was unable to discover the URL of the Proxy Auto-Configuration (PAC) file"
			);
		case WinHttpCode::WINHTTP_BAD_AUTO_PROXY_SCRIPT:
			RETURN_STATIC_STRING(
					"An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file"
			);
		case WinHttpCode::WINHTTP_CANNOT_CALL_AFTER_OPEN:
			RETURN_STATIC_STRING(
					"Returned by the HttpRequest object if a specified option cannot be requested after the Open method has been called"
			);
		case WinHttpCode::WINHTTP_CANNOT_CALL_AFTER_SEND:
			RETURN_STATIC_STRING(
					"Returned by the HttpRequest object if a requested operation cannot be performed after calling the Send method"
			);
		case WinHttpCode::WINHTTP_CANNOT_CALL_BEFORE_OPEN:
			RETURN_STATIC_STRING(
					"Returned by the HttpRequest object if a requested operation cannot be performed before calling the Open method"
			);
		case WinHttpCode::WINHTTP_CANNOT_CALL_BEFORE_SEND:
			RETURN_STATIC_STRING(
					"Returned by the HttpRequest object if a requested operation cannot be performed before calling the Send method"
			);
		case WinHttpCode::WINHTTP_CANNOT_CONNECT:
			RETURN_STATIC_STRING(
					"Returned if connection to the server failed"
			);

	//	, WINHTTP_CLIENT_AUTH_CERT_NEEDED =
	//#	if defined ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
	//			ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED
	//#	else
	//			?
	//#	endif
			// The server requires SSL client Authentication. The application retrieves the list of certificate issuers by calling WinHttpQueryOption with the WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST option. For more information, see the WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST option. If the server requests the client certificate, but does not require it, the application can alternately call WinHttpSetOption with the WINHTTP_OPTION_CLIENT_CERT_CONTEXT option. In this case, the application specifies the WINHTTP_NO_CLIENT_CERT_CONTEXT macro in the lpBuffer parameter of WinHttpSetOption. For more information, see the WINHTTP_OPTION_CLIENT_CERT_CONTEXT option. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

	//	, WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY =
	//#	if defined ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY
	//			ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY
	//#	else
	//			?
	//#	endif
			// The application does not have the required privileges to access the private key associated with the client certificate. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

	//	, WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY =
	//#	if defined ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY
	//			ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY
	//#	else
	//			?
	//#	endif
			// The context for the SSL client certificate does not have a private key associated with it. The client certificate may have been imported to the computer without the private key. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported.

		case WinHttpCode::WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW:
			RETURN_STATIC_STRING(
					"Returned by WinHttpReceiveResponse when an overflow condition is encountered in the course of parsing chunked encoding"
			);
		case WinHttpCode::WINHTTP_CLIENT_AUTH_CERT_NEEDED:
			RETURN_STATIC_STRING(
					"Returned by WinHttpReceiveResponse when the server requests client authentication. Windows Server 2003 with SP1 and Windows XP with SP2: This error is not supported"
			);
		case WinHttpCode::WINHTTP_CONNECTION_ERROR:
			RETURN_STATIC_STRING(
					"The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it"
			);
		case WinHttpCode::WINHTTP_HEADER_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"Obsolete; no longer used"
			);
		case WinHttpCode::WINHTTP_HEADER_COUNT_EXCEEDED:
			RETURN_STATIC_STRING(
					"Returned by WinHttpReceiveResponse when a larger number of headers were present in a response than WinHTTP could receive"
			);
		case WinHttpCode::WINHTTP_HEADER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested header cannot be located"
			);
		case WinHttpCode::WINHTTP_HEADER_SIZE_OVERFLOW:
			RETURN_STATIC_STRING(
					"Returned by WinHttpReceiveResponse when the size of headers received exceeds the limit for the request handle"
			);
		case WinHttpCode::WINHTTP_INCORRECT_HANDLE_STATE:
			RETURN_STATIC_STRING(
					"The requested operation cannot be carried out because the handle supplied is not in the correct state"
			);
		case WinHttpCode::WINHTTP_INCORRECT_HANDLE_TYPE:
			RETURN_STATIC_STRING(
					"The type of handle supplied is incorrect for this operation"
			);
		case WinHttpCode::WINHTTP_INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"An internal error has occurred"
			);
		case WinHttpCode::WINHTTP_INVALID_OPTION:
			RETURN_STATIC_STRING(
					"A request to WinHttpQueryOption or WinHttpSetOption specified an invalid option value"
			);
		case WinHttpCode::WINHTTP_INVALID_QUERY_REQUEST:
			RETURN_STATIC_STRING(
					"Obsolete; no longer used"
			);
		case WinHttpCode::WINHTTP_INVALID_SERVER_RESPONSE:
			RETURN_STATIC_STRING(
					"The server response cannot be parsed"
			);
		case WinHttpCode::WINHTTP_INVALID_URL:
			RETURN_STATIC_STRING(
					"The URL is not valid"
			);
		case WinHttpCode::WINHTTP_LOGIN_FAILURE:
			RETURN_STATIC_STRING(
					"The login attempt failed. When this error is encountered, the request handle should be closed with WinHttpCloseHandle. A new request handle must be created before retrying the function that originally produced this error"
			);
		case WinHttpCode::WINHTTP_NAME_NOT_RESOLVED:
			RETURN_STATIC_STRING(
					"The server name cannot be resolved"
			);
		case WinHttpCode::WINHTTP_NOT_INITIALIZED:
			RETURN_STATIC_STRING(
					"Obsolete; no longer used"
			);
		case WinHttpCode::WINHTTP_OPERATION_CANCELLED:
			RETURN_STATIC_STRING(
					"The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed"
			);
		case WinHttpCode::WINHTTP_OPTION_NOT_SETTABLE:
			RETURN_STATIC_STRING(
					"The requested option cannot be set, only queried"
			);
		case WinHttpCode::WINHTTP_OUT_OF_HANDLES:
			RETURN_STATIC_STRING(
					"Obsolete; no longer used"
			);
		case WinHttpCode::WINHTTP_REDIRECT_FAILED:
			RETURN_STATIC_STRING(
					"The redirection failed because either the scheme changed or all attempts made to redirect failed (default is five attempts)"
			);
		case WinHttpCode::WINHTTP_RESEND_REQUEST:
			RETURN_STATIC_STRING(
					"The WinHTTP function failed. The desired function can be retried on the same request handle"
			);
		case WinHttpCode::WINHTTP_RESPONSE_DRAIN_OVERFLOW:
			RETURN_STATIC_STRING(
					"Returned when an incoming response exceeds an internal WinHTTP size limit"
			);
		case WinHttpCode::WINHTTP_SCRIPT_EXECUTION_ERROR:
			RETURN_STATIC_STRING(
					"An error was encountered while executing a script"
			);
		case WinHttpCode::WINHTTP_SECURE_CERT_CN_INVALID:
			RETURN_STATIC_STRING(
					"Returned when a certificate CN name does not match the passed value (equivalent to a CERT_E_CN_NO_MATCH error)"
			);
		case WinHttpCode::WINHTTP_SECURE_CERT_DATE_INVALID:
			RETURN_STATIC_STRING(
					"Indicates that a required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file, or that the validity periods of the certification chain do not nest correctly (equivalent to a CERT_E_EXPIRED or a CERT_E_VALIDITYPERIODNESTING error)"
			);
		case WinHttpCode::WINHTTP_SECURE_CERT_REV_FAILED:
			RETURN_STATIC_STRING(
					"Indicates that revocation cannot be checked because the revocation server was offline (equivalent to CRYPT_E_REVOCATION_OFFLINE)"
			);
		case WinHttpCode::WINHTTP_SECURE_CERT_REVOKED:
			RETURN_STATIC_STRING(
					"Indicates that a certificate has been revoked (equivalent to CRYPT_E_REVOKED)"
			);
		case WinHttpCode::WINHTTP_SECURE_CERT_WRONG_USAGE:
			RETURN_STATIC_STRING(
					"Indicates that a certificate is not valid for the requested usage (equivalent to CERT_E_WRONG_USAGE)"
			);
		case WinHttpCode::WINHTTP_SECURE_CHANNEL_ERROR:
			RETURN_STATIC_STRING(
					"Indicates that an error occurred having to do with a secure channel (equivalent to error codes that begin with \"SEC_E_\" and \"SEC_I_\" listed in the \"winerror.h\" header file)"
			);
		case WinHttpCode::WINHTTP_SECURE_FAILURE:
			RETURN_STATIC_STRING(
					"One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, check for a WINHTTP_CALLBACK_STATUS_SECURE_FAILURE notification in a status callback function. For more information, see WINHTTP_STATUS_CALLBACK"
			);
		case WinHttpCode::WINHTTP_SECURE_INVALID_CA:
			RETURN_STATIC_STRING(
					"Indicates that a certificate chain was processed, but terminated in a root certificate that is not trusted by the trust provider (equivalent to CERT_E_UNTRUSTEDROOT)"
			);
		case WinHttpCode::WINHTTP_SECURE_INVALID_CERT:
			RETURN_STATIC_STRING(
					"Indicates that a certificate is invalid (equivalent to errors such as CERT_E_ROLE, CERT_E_PATHLENCONST, CERT_E_CRITICAL, CERT_E_PURPOSE, CERT_E_ISSUERCHAINING, CERT_E_MALFORMED and CERT_E_CHAINING)"
			);
		case WinHttpCode::WINHTTP_SHUTDOWN:
			RETURN_STATIC_STRING(
					"The WinHTTP function support is being shut down or unloaded"
			);
		case WinHttpCode::WINHTTP_TIMEOUT:
			RETURN_STATIC_STRING(
					"The request has timed out. This error can be returned as a result of TCP/IP time-out behavior, regardless of time-out values set in Windows HTTP Services"
			);
		case WinHttpCode::WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT:
			RETURN_STATIC_STRING(
					"The PAC file cannot be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response"
			);
		case WinHttpCode::WINHTTP_UNHANDLED_SCRIPT_TYPE:
			RETURN_STATIC_STRING(
					"The script type is not supported"
			);
		case WinHttpCode::WINHTTP_UNRECOGNIZED_SCHEME:
			RETURN_STATIC_STRING(
					"The URL specified a scheme other than \"http:\" or \"https:\""
			);
		case WinHttpCode::NOT_ENOUGH_MEMORY:
			RETURN_STATIC_STRING(
					"Not enough memory was available to complete the requested operation. Header: Declared in Winerror."
			);
		case WinHttpCode::INSUFFICIENT_BUFFER:
			RETURN_STATIC_STRING(
					"The size, in bytes, of the buffer supplied to a function was insufficient to contain the returned data. For more information, see the specific function. Header: Declared in Winerror."
			);
		case WinHttpCode::INVALID_HANDLE:
			RETURN_STATIC_STRING(
					"The handle passed to the application programming interface (API) has been either invalidated or closed. Header: Declared in Winerror."
			);
		case WinHttpCode::NO_MORE_FILES:
			RETURN_STATIC_STRING(
					"No more files have been found. Header: Declared in Winerror."
			);
		case WinHttpCode::NO_MORE_ITEMS:
			RETURN_STATIC_STRING(
					"No more items have been found. Header: Declared in Winerror."
			);
		case WinHttpCode::NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The required protocol stack is not loaded and the application cannot start WinSock. Header: Declared in Winerror."
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
