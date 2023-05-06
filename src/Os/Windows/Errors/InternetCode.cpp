#include <FlameIDE/../../src/Os/Windows/InternetCode.hpp>

#include <wininet.h>

#define RETURN_STATIC_STRING(string) \
{ \
	static const char returnString[] = string; \
	return &returnString[0]; \
}

namespace flame_ide
{namespace os
{namespace error
{

// https://learn.microsoft.com/en-us/windows/win32/wininet/wininet-errors
enum class InternetCode: decltype(::GetLastError())
{

	FTP_DROPPED =
#	if defined ERROR_FTP_DROPPED
			ERROR_FTP_DROPPED
#	else
			12111
#	endif
		// The FTP operation was not completed because the session was aborted.

	, FTP_NO_PASSIVE_MODE =
#	if defined ERROR_FTP_NO_PASSIVE_MODE
			ERROR_FTP_NO_PASSIVE_MODE
#	else
			12112
#	endif
		// Passive mode is not available on the server.

	, FTP_TRANSFER_IN_PROGRESS =
#	if defined ERROR_FTP_TRANSFER_IN_PROGRESS
			ERROR_FTP_TRANSFER_IN_PROGRESS
#	else
			12110
#	endif
		// The requested operation cannot be made on the FTP session handle because an operation is already in progress.

	, GOPHER_ATTRIBUTE_NOT_FOUND =
#	if defined ERROR_GOPHER_ATTRIBUTE_NOT_FOUND
			ERROR_GOPHER_ATTRIBUTE_NOT_FOUND
#	else
			12137
#	endif
		// The requested attribute could not be located. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_DATA_ERROR =
#	if defined ERROR_GOPHER_DATA_ERROR
			ERROR_GOPHER_DATA_ERROR
#	else
			12132
#	endif
		// An error was detected while receiving data from the Gopher server. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_END_OF_DATA =
#	if defined ERROR_GOPHER_END_OF_DATA
			ERROR_GOPHER_END_OF_DATA
#	else
			12133
#	endif
		// The end of the data has been reached. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_INCORRECT_LOCATOR_TYPE =
#	if defined ERROR_GOPHER_INCORRECT_LOCATOR_TYPE
			ERROR_GOPHER_INCORRECT_LOCATOR_TYPE
#	else
			12135
#	endif
		// The type of the locator is not correct for this operation. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_INVALID_LOCATOR =
#	if defined ERROR_GOPHER_INVALID_LOCATOR
			ERROR_GOPHER_INVALID_LOCATOR
#	else
			12134
#	endif
		// The supplied locator is not valid. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_NOT_FILE =
#	if defined ERROR_GOPHER_NOT_FILE
			ERROR_GOPHER_NOT_FILE
#	else
			12131
#	endif
		// The request must be made for a file locator. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_NOT_GOPHER_PLUS =
#	if defined ERROR_GOPHER_NOT_GOPHER_PLUS
			ERROR_GOPHER_NOT_GOPHER_PLUS
#	else
			12136
#	endif
		// The requested operation can be made only against a Gopher+ server, or with a locator that specifies a Gopher+ operation. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_PROTOCOL_ERROR =
#	if defined ERROR_GOPHER_PROTOCOL_ERROR
			ERROR_GOPHER_PROTOCOL_ERROR
#	else
			12130
#	endif
		// An error was detected while parsing data returned from the Gopher server. Windows XP and Windows Server 2003 R2 and earlier only.

	, GOPHER_UNKNOWN_LOCATOR =
#	if defined ERROR_GOPHER_UNKNOWN_LOCATOR
			ERROR_GOPHER_UNKNOWN_LOCATOR
#	else
			12138
#	endif
		// The locator type is unknown. Windows XP and Windows Server 2003 R2 and earlier only.

	, HTTP_COOKIE_DECLINED =
#	if defined ERROR_HTTP_COOKIE_DECLINED
			ERROR_HTTP_COOKIE_DECLINED
#	else
			12162
#	endif
		// The HTTP cookie was declined by the server.

	, HTTP_COOKIE_NEEDS_CONFIRMATION =
#	if defined ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION
			ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION
#	else
			12161
#	endif
		// The HTTP cookie requires confirmation. Windows Vista and Windows Server 2008 and earlier only.

	, HTTP_DOWNLEVEL_SERVER =
#	if defined ERROR_HTTP_DOWNLEVEL_SERVER
			ERROR_HTTP_DOWNLEVEL_SERVER
#	else
			12151
#	endif
		// The server did not return any headers.

	, HTTP_HEADER_ALREADY_EXISTS =
#	if defined ERROR_HTTP_HEADER_ALREADY_EXISTS
			ERROR_HTTP_HEADER_ALREADY_EXISTS
#	else
			12155
#	endif
		// The header could not be added because it already exists.

	, HTTP_HEADER_NOT_FOUND =
#	if defined ERROR_HTTP_HEADER_NOT_FOUND
			ERROR_HTTP_HEADER_NOT_FOUND
#	else
			12150
#	endif
		// The requested header could not be located.

	, HTTP_INVALID_HEADER =
#	if defined ERROR_HTTP_INVALID_HEADER
			ERROR_HTTP_INVALID_HEADER
#	else
			12153
#	endif
		// The supplied header is invalid.

	, HTTP_INVALID_QUERY_REQUEST =
#	if defined ERROR_HTTP_INVALID_QUERY_REQUEST
			ERROR_HTTP_INVALID_QUERY_REQUEST
#	else
			12154
#	endif
		// The request made to HttpQueryInfo is invalid.

	, HTTP_INVALID_SERVER_RESPONSE =
#	if defined ERROR_HTTP_INVALID_SERVER_RESPONSE
			ERROR_HTTP_INVALID_SERVER_RESPONSE
#	else
			12152
#	endif
		// The server response could not be parsed.

	, HTTP_NOT_REDIRECTED =
#	if defined ERROR_HTTP_NOT_REDIRECTED
			ERROR_HTTP_NOT_REDIRECTED
#	else
			12160
#	endif
		// The HTTP request was not redirected.

	, HTTP_REDIRECT_FAILED =
#	if defined ERROR_HTTP_REDIRECT_FAILED
			ERROR_HTTP_REDIRECT_FAILED
#	else
			12156
#	endif
		// The redirection failed because either the scheme changed (for example, HTTP to FTP) or all attempts made to redirect failed (default is five attempts).

	, HTTP_REDIRECT_NEEDS_CONFIRMATION =
#	if defined ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION
			ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION
#	else
			12168
#	endif
		// The redirection requires user confirmation.

	, INTERNET_ASYNC_THREAD_FAILED =
#	if defined ERROR_INTERNET_ASYNC_THREAD_FAILED
			ERROR_INTERNET_ASYNC_THREAD_FAILED
#	else
			12047
#	endif
		// The application could not start an asynchronous thread.

	, INTERNET_BAD_AUTO_PROXY_SCRIPT =
#	if defined ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT
			ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT
#	else
			12166
#	endif
		// There was an error in the automatic proxy configuration script.

	, INTERNET_BAD_OPTION_LENGTH =
#	if defined ERROR_INTERNET_BAD_OPTION_LENGTH
			ERROR_INTERNET_BAD_OPTION_LENGTH
#	else
			12010
#	endif
		// The length of an option supplied to InternetQueryOption or InternetSetOption is incorrect for the type of option specified.

	, INTERNET_BAD_REGISTRY_PARAMETER =
#	if defined ERROR_INTERNET_BAD_REGISTRY_PARAMETER
			ERROR_INTERNET_BAD_REGISTRY_PARAMETER
#	else
			12022
#	endif
		// A required registry value was located but is an incorrect type or has an invalid value.

	, INTERNET_CANNOT_CONNECT =
#	if defined ERROR_INTERNET_CANNOT_CONNECT
			ERROR_INTERNET_CANNOT_CONNECT
#	else
			12029
#	endif
		// The attempt to connect to the server failed.

	, INTERNET_CHG_POST_IS_NON_SECURE =
#	if defined ERROR_INTERNET_CHG_POST_IS_NON_SECURE
			ERROR_INTERNET_CHG_POST_IS_NON_SECURE
#	else
			12042
#	endif
		// The application is posting and attempting to change multiple lines of text on a server that is not secure.

	, INTERNET_CLIENT_AUTH_CERT_NEEDED =
#	if defined ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED
			ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED
#	else
			12044
#	endif
		// The server is requesting client authentication.

	, INTERNET_CLIENT_AUTH_NOT_SETUP =
#	if defined ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP
			ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP
#	else
			12046
#	endif
		// Client authorization is not set up on this computer.

	, INTERNET_CONNECTION_ABORTED =
#	if defined ERROR_INTERNET_CONNECTION_ABORTED
			ERROR_INTERNET_CONNECTION_ABORTED
#	else
			12030
#	endif
		// The connection with the server has been terminated.

	, INTERNET_CONNECTION_RESET =
#	if defined ERROR_INTERNET_CONNECTION_RESET
			ERROR_INTERNET_CONNECTION_RESET
#	else
			12031
#	endif
		// The connection with the server has been reset.

	, INTERNET_DECODING_FAILED =
#	if defined ERROR_INTERNET_DECODING_FAILED
			ERROR_INTERNET_DECODING_FAILED
#	else
			12175
#	endif
		// WinINet failed to perform content decoding on the response. For more information, see the Content Encoding topic.

	, INTERNET_DIALOG_PENDING =
#	if defined ERROR_INTERNET_DIALOG_PENDING
			ERROR_INTERNET_DIALOG_PENDING
#	else
			12049
#	endif
		// Another thread has a password dialog box in progress.

	, INTERNET_DISCONNECTED =
#	if defined ERROR_INTERNET_DISCONNECTED
			ERROR_INTERNET_DISCONNECTED
#	else
			12163
#	endif
		// The Internet connection has been lost.

	, INTERNET_EXTENDED_ERROR =
#	if defined ERROR_INTERNET_EXTENDED_ERROR
			ERROR_INTERNET_EXTENDED_ERROR
#	else
			12003
#	endif
		// An extended error was returned from the server. This is typically a string or buffer containing a verbose error message. Call InternetGetLastResponseInfo to retrieve the error text.

	, INTERNET_FAILED_DUETOSECURITYCHECK =
#	if defined ERROR_INTERNET_FAILED_DUETOSECURITYCHECK
			ERROR_INTERNET_FAILED_DUETOSECURITYCHECK
#	else
			12171
#	endif
		// The function failed due to a security check.

	, INTERNET_FORCE_RETRY =
#	if defined ERROR_INTERNET_FORCE_RETRY
			ERROR_INTERNET_FORCE_RETRY
#	else
			12032
#	endif
		// The function needs to redo the request.

	, INTERNET_FORTEZZA_LOGIN_NEEDED =
#	if defined ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED
			ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED
#	else
			12054
#	endif
		// The requested resource requires Fortezza authentication.

	, INTERNET_HANDLE_EXISTS =
#	if defined ERROR_INTERNET_HANDLE_EXISTS
			ERROR_INTERNET_HANDLE_EXISTS
#	else
			12036
#	endif
		// The request failed because the handle already exists.

	, INTERNET_HTTP_TO_HTTPS_ON_REDIR =
#	if defined ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR
			ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR
#	else
			12039
#	endif
		// The application is moving from a non-SSL to an SSL connection because of a redirect.

	, INTERNET_HTTPS_HTTP_SUBMIT_REDIR =
#	if defined ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR
			ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR
#	else
			12052
#	endif
		// The data being submitted to an SSL connection is being redirected to a non-SSL connection.

	, INTERNET_HTTPS_TO_HTTP_ON_REDIR =
#	if defined ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR
			ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR
#	else
			12040
#	endif
		// The application is moving from an SSL to an non-SSL connection because of a redirect.

	, INTERNET_INCORRECT_FORMAT =
#	if defined ERROR_INTERNET_INCORRECT_FORMAT
			ERROR_INTERNET_INCORRECT_FORMAT
#	else
			12027
#	endif
		// The format of the request is invalid.

	, INTERNET_INCORRECT_HANDLE_STATE =
#	if defined ERROR_INTERNET_INCORRECT_HANDLE_STATE
			ERROR_INTERNET_INCORRECT_HANDLE_STATE
#	else
			12019
#	endif
		// The requested operation cannot be carried out because the handle supplied is not in the correct state.

	, INTERNET_INCORRECT_HANDLE_TYPE =
#	if defined ERROR_INTERNET_INCORRECT_HANDLE_TYPE
			ERROR_INTERNET_INCORRECT_HANDLE_TYPE
#	else
			12018
#	endif
		// The type of handle supplied is incorrect for this operation.

	, INTERNET_INCORRECT_PASSWORD =
#	if defined ERROR_INTERNET_INCORRECT_PASSWORD
			ERROR_INTERNET_INCORRECT_PASSWORD
#	else
			12014
#	endif
		// The request to connect and log on to an FTP server could not be completed because the supplied password is incorrect.

	, INTERNET_INCORRECT_USER_NAME =
#	if defined ERROR_INTERNET_INCORRECT_USER_NAME
			ERROR_INTERNET_INCORRECT_USER_NAME
#	else
			12013
#	endif
		// The request to connect and log on to an FTP server could not be completed because the supplied user name is incorrect.

	, INTERNET_INSERT_CDROM =
#	if defined ERROR_INTERNET_INSERT_CDROM
			ERROR_INTERNET_INSERT_CDROM
#	else
			12053
#	endif
		// The request requires a CD-ROM to be inserted in the CD-ROM drive to locate the resource requested. Windows Vista and Windows Server 2008 and earlier only.

	, INTERNET_INTERNAL_ERROR =
#	if defined ERROR_INTERNET_INTERNAL_ERROR
			ERROR_INTERNET_INTERNAL_ERROR
#	else
			12004
#	endif
		// An internal error has occurred.

	, INTERNET_INVALID_CA =
#	if defined ERROR_INTERNET_INVALID_CA
			ERROR_INTERNET_INVALID_CA
#	else
			12045
#	endif
		// The function is unfamiliar with the Certificate Authority that generated the server's certificate.

	, INTERNET_INVALID_OPERATION =
#	if defined ERROR_INTERNET_INVALID_OPERATION
			ERROR_INTERNET_INVALID_OPERATION
#	else
			12016
#	endif
		// The requested operation is invalid.

	, INTERNET_INVALID_OPTION =
#	if defined ERROR_INTERNET_INVALID_OPTION
			ERROR_INTERNET_INVALID_OPTION
#	else
			12009
#	endif
		// A request to InternetQueryOption or InternetSetOption specified an invalid option value.

	, INTERNET_INVALID_PROXY_REQUEST =
#	if defined ERROR_INTERNET_INVALID_PROXY_REQUEST
			ERROR_INTERNET_INVALID_PROXY_REQUEST
#	else
			12033
#	endif
		// The request to the proxy was invalid.

	, INTERNET_INVALID_URL =
#	if defined ERROR_INTERNET_INVALID_URL
			ERROR_INTERNET_INVALID_URL
#	else
			12005
#	endif
		// The URL is invalid.

	, INTERNET_ITEM_NOT_FOUND =
#	if defined ERROR_INTERNET_ITEM_NOT_FOUND
			ERROR_INTERNET_ITEM_NOT_FOUND
#	else
			12028
#	endif
		// The requested item could not be located.

	, INTERNET_LOGIN_FAILURE =
#	if defined ERROR_INTERNET_LOGIN_FAILURE
			ERROR_INTERNET_LOGIN_FAILURE
#	else
			12015
#	endif
		// The request to connect and log on to an FTP server failed.

	, INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY =
#	if defined ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY
			ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY
#	else
			12174
#	endif
		// The MS-Logoff digest header has been returned from the website. This header specifically instructs the digest package to purge credentials for the associated realm. This error will only be returned if INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY option has been set; otherwise, ERROR_INTERNET_LOGIN_FAILURE is returned.

	, INTERNET_MIXED_SECURITY =
#	if defined ERROR_INTERNET_MIXED_SECURITY
			ERROR_INTERNET_MIXED_SECURITY
#	else
			12041
#	endif
		// The content is not entirely secure. Some of the content being viewed may have come from unsecured servers.

	, INTERNET_NAME_NOT_RESOLVED =
#	if defined ERROR_INTERNET_NAME_NOT_RESOLVED
			ERROR_INTERNET_NAME_NOT_RESOLVED
#	else
			12007
#	endif
		// The server name could not be resolved.

	, INTERNET_NEED_MSN_SSPI_PKG =
#	if defined ERROR_INTERNET_NEED_MSN_SSPI_PKG
			ERROR_INTERNET_NEED_MSN_SSPI_PKG
#	else
			12173
#	endif
		// Not currently implemented.

	, INTERNET_NEED_UI =
#	if defined ERROR_INTERNET_NEED_UI
			ERROR_INTERNET_NEED_UI
#	else
			12034
#	endif
		// A user interface or other blocking operation has been requested. Windows Vista and Windows Server 2008 and earlier only.

	, INTERNET_NOT_SET_CALLBACK =
#	if defined ERROR_INTERNET_NO_CALLBACK
			ERROR_INTERNET_NO_CALLBACK
#	else
			12025
#	endif
		// An asynchronous request could not be made because a callback function has not been set.

	, INTERNET_NO_CONTEXT =
#	if defined ERROR_INTERNET_NO_CONTEXT
			ERROR_INTERNET_NO_CONTEXT
#	else
			12024
#	endif
		// An asynchronous request could not be made because a zero context value was supplied.

	, INTERNET_NO_DIRECT_ACCESS =
#	if defined ERROR_INTERNET_NO_DIRECT_ACCESS
			ERROR_INTERNET_NO_DIRECT_ACCESS
#	else
			12023
#	endif
		// Direct network access cannot be made at this time.

	, INTERNET_NOT_INITIALIZED =
#	if defined ERROR_INTERNET_NOT_INITIALIZED
			ERROR_INTERNET_NOT_INITIALIZED
#	else
			12172
#	endif
		// Initialization of the WinINet API has not occurred. Indicates that a higher-level function, such as InternetOpen, has not been called yet.

	, INTERNET_NOT_PROXY_REQUEST =
#	if defined ERROR_INTERNET_NOT_PROXY_REQUEST
			ERROR_INTERNET_NOT_PROXY_REQUEST
#	else
			12020
#	endif
		// The request cannot be made via a proxy.

	, INTERNET_OPERATION_CANCELLED =
#	if defined ERROR_INTERNET_OPERATION_CANCELLED
			ERROR_INTERNET_OPERATION_CANCELLED
#	else
			12017
#	endif
		// The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.

	, INTERNET_OPTION_NOT_SETTABLE =
#	if defined ERROR_INTERNET_OPTION_NOT_SETTABLE
			ERROR_INTERNET_OPTION_NOT_SETTABLE
#	else
			12011
#	endif
		// The requested option cannot be set, only queried.

	, INTERNET_OUT_OF_HANDLES =
#	if defined ERROR_INTERNET_OUT_OF_HANDLES
			ERROR_INTERNET_OUT_OF_HANDLES
#	else
			12001
#	endif
		// No more handles could be generated at this time.

	, INTERNET_POST_IS_NON_SECURE =
#	if defined ERROR_INTERNET_POST_IS_NON_SECURE
			ERROR_INTERNET_POST_IS_NON_SECURE
#	else
			12043
#	endif
		// The application is posting data to a server that is not secure.

	, INTERNET_PROTOCOL_NOT_FOUND =
#	if defined ERROR_INTERNET_PROTOCOL_NOT_FOUND
			ERROR_INTERNET_PROTOCOL_NOT_FOUND
#	else
			12008
#	endif
		// The requested protocol could not be located.

	, INTERNET_PROXY_SERVER_UNREACHABLE =
#	if defined ERROR_INTERNET_PROXY_SERVER_UNREACHABLE
			ERROR_INTERNET_PROXY_SERVER_UNREACHABLE
#	else
			12165
#	endif
		// The designated proxy server cannot be reached.

	, INTERNET_REDIRECT_SCHEME_CHANGE =
#	if defined ERROR_INTERNET_REDIRECT_SCHEME_CHANGE
			ERROR_INTERNET_REDIRECT_SCHEME_CHANGE
#	else
			12048
#	endif
		// The function could not handle the redirection, because the scheme changed (for example, HTTP to FTP).

	, INTERNET_REGISTRY_VALUE_NOT_FOUND =
#	if defined ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND
			ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND
#	else
			12021
#	endif
		// A required registry value could not be located.

	, INTERNET_REQUEST_PENDING =
#	if defined ERROR_INTERNET_REQUEST_PENDING
			ERROR_INTERNET_REQUEST_PENDING
#	else
			12026
#	endif
		// The required operation could not be completed because one or more requests are pending.

	, INTERNET_RETRY_DIALOG =
#	if defined ERROR_INTERNET_RETRY_DIALOG
			ERROR_INTERNET_RETRY_DIALOG
#	else
			12050
#	endif
		// The dialog box should be retried.

	, INTERNET_SEC_CERT_CN_INVALID =
#	if defined ERROR_INTERNET_SEC_CERT_CN_INVALID
			ERROR_INTERNET_SEC_CERT_CN_INVALID
#	else
			12038
#	endif
		// SSL certificate common name (host name field) is incorrect for example, if you entered www.server.com and the common name on the certificate says www.different.com.

	, INTERNET_SEC_CERT_DATE_INVALID =
#	if defined ERROR_INTERNET_SEC_CERT_DATE_INVALID
			ERROR_INTERNET_SEC_CERT_DATE_INVALID
#	else
			12037
#	endif
		// SSL certificate date that was received from the server is bad. The certificate is expired.

	, INTERNET_SEC_CERT_ERRORS =
#	if defined ERROR_INTERNET_SEC_CERT_ERRORS
			ERROR_INTERNET_SEC_CERT_ERRORS
#	else
			12055
#	endif
		// The SSL certificate contains errors.

	, INTERNET_SEC_CERT_NO_REV =
#	if defined ERROR_INTERNET_SEC_CERT_NO_REV
			ERROR_INTERNET_SEC_CERT_NO_REV
#	else
			12056
#	endif
		// The SSL certificate was not revoked.

	, INTERNET_SEC_CERT_REV_FAILED =
#	if defined ERROR_INTERNET_SEC_CERT_REV_FAILED
			ERROR_INTERNET_SEC_CERT_REV_FAILED
#	else
			12057
#	endif
		// Revocation of the SSL certificate failed.

	, INTERNET_SEC_CERT_REVOKED =
#	if defined ERROR_INTERNET_SEC_CERT_REVOKED
			ERROR_INTERNET_SEC_CERT_REVOKED
#	else
			12170
#	endif
		// The SSL certificate was revoked.

	, INTERNET_SEC_INVALID_CERT =
#	if defined ERROR_INTERNET_SEC_INVALID_CERT
			ERROR_INTERNET_SEC_INVALID_CERT
#	else
			12169
#	endif
		// The SSL certificate is invalid.

	, INTERNET_SECURITY_CHANNEL_ERROR =
#	if defined ERROR_INTERNET_SECURITY_CHANNEL_ERROR
			ERROR_INTERNET_SECURITY_CHANNEL_ERROR
#	else
			12157
#	endif
		// The application experienced an internal error loading the SSL libraries.

	, INTERNET_SERVER_UNREACHABLE =
#	if defined ERROR_INTERNET_SERVER_UNREACHABLE
			ERROR_INTERNET_SERVER_UNREACHABLE
#	else
			12164
#	endif
		// The website or server indicated is unreachable.

	, INTERNET_SHUTDOWN =
#	if defined ERROR_INTERNET_SHUTDOWN
			ERROR_INTERNET_SHUTDOWN
#	else
			12012
#	endif
		// WinINet support is being shut down or unloaded.

	, INTERNET_TCPIP_NOT_INSTALLED =
#	if defined ERROR_INTERNET_TCPIP_NOT_INSTALLED
			ERROR_INTERNET_TCPIP_NOT_INSTALLED
#	else
			12159
#	endif
		// The required protocol stack is not loaded and the application cannot start WinSock.

	, INTERNET_TIMEOUT =
#	if defined ERROR_INTERNET_TIMEOUT
			ERROR_INTERNET_TIMEOUT
#	else
			12002
#	endif
		// The request has timed out.

	, INTERNET_UNABLE_TO_CACHE_FILE =
#	if defined ERROR_INTERNET_UNABLE_TO_CACHE_FILE
			ERROR_INTERNET_UNABLE_TO_CACHE_FILE
#	else
			12158
#	endif
		// The function was unable to cache the file.

	, INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT =
#	if defined ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT
			ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT
#	else
			12167
#	endif
		// The automatic proxy configuration script could not be downloaded. The INTERNET_FLAG_MUST_CACHE_REQUEST flag was set.

	, INTERNET_UNRECOGNIZED_SCHEME =
#	if defined ERROR_INTERNET_UNRECOGNIZED_SCHEME
			ERROR_INTERNET_UNRECOGNIZED_SCHEME
#	else
			12006
#	endif
		// The URL scheme could not be recognized, or is not supported.

	, INVALID_HANDLE =
#	if defined ERROR_INVALID_HANDLE
			ERROR_INVALID_HANDLE
#	else
			6
#	endif
		// The handle that was passed to the API has been either invalidated or closed. Declared in Winerror.h

	, MORE_DATA =
#	if defined ERROR_MORE_DATA
			ERROR_MORE_DATA
#	else
			234
#	endif
		// More data is available. Declared in Winerror.h

	, NO_MORE_FILES =
#	if defined ERROR_NO_MORE_FILES
			ERROR_NO_MORE_FILES
#	else
			18
#	endif
		// No more files have been found. Declared in Winerror.h

	, NO_MORE_ITEMS =
#	if defined ERROR_NO_MORE_ITEMS
			ERROR_NO_MORE_ITEMS
#	else
			259
#	endif
		// No more items have been found. Declared in Winerror.h
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *internetCodeToString(os::Status status) noexcept
{
	const auto code = static_cast<InternetCode>(status);
	switch (code)
	{
		case InternetCode::FTP_DROPPED:
			RETURN_STATIC_STRING(
					"The FTP operation was not completed because the session was aborted"
			);
		case InternetCode::FTP_NO_PASSIVE_MODE:
			RETURN_STATIC_STRING(
					"Passive mode is not available on the server"
			);
		case InternetCode::FTP_TRANSFER_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The requested operation cannot be made on the FTP session handle because an"
					" operation is already in progress"
			);
		case InternetCode::GOPHER_ATTRIBUTE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested attribute could not be located. Windows XP and Windows Server"
					" 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_DATA_ERROR:
			RETURN_STATIC_STRING(
					"An error was detected while receiving data from the Gopher server. Windows XP"
					" and Windows Server 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_END_OF_DATA:
			RETURN_STATIC_STRING(
					"The end of the data has been reached. Windows XP and Windows Server 2003 R2"
					" and earlier only"
			);
		case InternetCode::GOPHER_INCORRECT_LOCATOR_TYPE:
			RETURN_STATIC_STRING(
					"The type of the locator is not correct for this operation. Windows XP and"
					" Windows Server 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_INVALID_LOCATOR:
			RETURN_STATIC_STRING(
					"The supplied locator is not valid. Windows XP and Windows Server 2003 R2 and"
					" earlier only"
			);
		case InternetCode::GOPHER_NOT_FILE:
			RETURN_STATIC_STRING(
					"The request must be made for a file locator. Windows XP and Windows Server"
					" 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_NOT_GOPHER_PLUS:
			RETURN_STATIC_STRING(
					"The requested operation can be made only against a Gopher+ server, or with a"
					" locator that specifies a Gopher+ operation. Windows XP and Windows Server"
					" 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_PROTOCOL_ERROR:
			RETURN_STATIC_STRING(
					"An error was detected while parsing data returned from the Gopher server."
					" Windows XP and Windows Server 2003 R2 and earlier only"
			);
		case InternetCode::GOPHER_UNKNOWN_LOCATOR:
			RETURN_STATIC_STRING(
					"The locator type is unknown. Windows XP and Windows Server 2003 R2 and earlier"
					" only"
			);
		case InternetCode::HTTP_COOKIE_DECLINED:
			RETURN_STATIC_STRING(
					"The HTTP cookie was declined by the server"
			);
		case InternetCode::HTTP_COOKIE_NEEDS_CONFIRMATION:
			RETURN_STATIC_STRING(
					"The HTTP cookie requires confirmation. Windows Vista and Windows Server 2008"
					" and earlier only"
			);
		case InternetCode::HTTP_DOWNLEVEL_SERVER:
			RETURN_STATIC_STRING(
					"The server did not return any headers"
			);
		case InternetCode::HTTP_HEADER_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The header could not be added because it already exists"
			);
		case InternetCode::HTTP_HEADER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested header could not be located"
			);
		case InternetCode::HTTP_INVALID_HEADER:
			RETURN_STATIC_STRING(
					"The supplied header is invalid"
			);
		case InternetCode::HTTP_INVALID_QUERY_REQUEST:
			RETURN_STATIC_STRING(
					"The request made to HttpQueryInfo is invalid"
			);
		case InternetCode::HTTP_INVALID_SERVER_RESPONSE:
			RETURN_STATIC_STRING(
					"The server response could not be parsed"
			);
		case InternetCode::HTTP_NOT_REDIRECTED:
			RETURN_STATIC_STRING(
					"The HTTP request was not redirected"
			);
		case InternetCode::HTTP_REDIRECT_FAILED:
			RETURN_STATIC_STRING(
					"The redirection failed because either the scheme changed (for example, HTTP to"
					" FTP) or all attempts made to redirect failed (default is five attempts)"
			);
		case InternetCode::HTTP_REDIRECT_NEEDS_CONFIRMATION:
			RETURN_STATIC_STRING(
					"The redirection requires user confirmation"
			);
		case InternetCode::INTERNET_ASYNC_THREAD_FAILED:
			RETURN_STATIC_STRING(
					"The application could not start an asynchronous thread"
			);
		case InternetCode::INTERNET_BAD_AUTO_PROXY_SCRIPT:
			RETURN_STATIC_STRING(
					"There was an error in the automatic proxy configuration script"
			);
		case InternetCode::INTERNET_BAD_OPTION_LENGTH:
			RETURN_STATIC_STRING(
					"The length of an option supplied to InternetQueryOption or InternetSetOption"
					" is incorrect for the type of option specified"
			);
		case InternetCode::INTERNET_BAD_REGISTRY_PARAMETER:
			RETURN_STATIC_STRING(
					"A required registry value was located but is an incorrect type or has an"
					" invalid value"
			);
		case InternetCode::INTERNET_CANNOT_CONNECT:
			RETURN_STATIC_STRING(
					"The attempt to connect to the server failed"
			);
		case InternetCode::INTERNET_CHG_POST_IS_NON_SECURE:
			RETURN_STATIC_STRING(
					"The application is posting and attempting to change multiple lines of text on"
					" a server that is not secure"
			);
		case InternetCode::INTERNET_CLIENT_AUTH_CERT_NEEDED:
			RETURN_STATIC_STRING(
					"The server is requesting client authentication"
			);
		case InternetCode::INTERNET_CLIENT_AUTH_NOT_SETUP:
			RETURN_STATIC_STRING(
					"Client authorization is not set up on this computer"
			);
		case InternetCode::INTERNET_CONNECTION_ABORTED:
			RETURN_STATIC_STRING(
					"The connection with the server has been terminated"
			);
		case InternetCode::INTERNET_CONNECTION_RESET:
			RETURN_STATIC_STRING(
					"The connection with the server has been reset"
			);
		case InternetCode::INTERNET_DECODING_FAILED:
			RETURN_STATIC_STRING(
					"WinINet failed to perform content decoding on the response. For more"
					" information, see the Content Encoding topic"
			);
		case InternetCode::INTERNET_DIALOG_PENDING:
			RETURN_STATIC_STRING(
					"Another thread has a password dialog box in progress"
			);
		case InternetCode::INTERNET_DISCONNECTED:
			RETURN_STATIC_STRING(
					"The Internet connection has been lost"
			);
		case InternetCode::INTERNET_EXTENDED_ERROR:
			RETURN_STATIC_STRING(
					"An extended error was returned from the server. This is typically a string or"
					" buffer containing a verbose error message. Call InternetGetLastResponseInfo"
					" to retrieve the error text"
			);
		case InternetCode::INTERNET_FAILED_DUETOSECURITYCHECK:
			RETURN_STATIC_STRING(
					"The function failed due to a security check"
			);
		case InternetCode::INTERNET_FORCE_RETRY:
			RETURN_STATIC_STRING(
					"The function needs to redo the request"
			);
		case InternetCode::INTERNET_FORTEZZA_LOGIN_NEEDED:
			RETURN_STATIC_STRING(
					"The requested resource requires Fortezza authentication"
			);
		case InternetCode::INTERNET_HANDLE_EXISTS:
			RETURN_STATIC_STRING(
					"The request failed because the handle already exists"
			);
		case InternetCode::INTERNET_HTTP_TO_HTTPS_ON_REDIR:
			RETURN_STATIC_STRING(
					"The application is moving from a non-SSL to an SSL connection because of a"
					" redirect"
			);
		case InternetCode::INTERNET_HTTPS_HTTP_SUBMIT_REDIR:
			RETURN_STATIC_STRING(
					"The data being submitted to an SSL connection is being redirected to a non-SSL"
					" connection"
			);
		case InternetCode::INTERNET_HTTPS_TO_HTTP_ON_REDIR:
			RETURN_STATIC_STRING(
					"The application is moving from an SSL to an non-SSL connection because of a"
					" redirect"
			);
		case InternetCode::INTERNET_INCORRECT_FORMAT:
			RETURN_STATIC_STRING(
					"The format of the request is invalid"
			);
		case InternetCode::INTERNET_INCORRECT_HANDLE_STATE:
			RETURN_STATIC_STRING(
					"The requested operation cannot be carried out because the handle supplied is"
					" not in the correct state"
			);
		case InternetCode::INTERNET_INCORRECT_HANDLE_TYPE:
			RETURN_STATIC_STRING(
					"The type of handle supplied is incorrect for this operation"
			);
		case InternetCode::INTERNET_INCORRECT_PASSWORD:
			RETURN_STATIC_STRING(
					"The request to connect and log on to an FTP server could not be completed"
					" because the supplied password is incorrect"
			);
		case InternetCode::INTERNET_INCORRECT_USER_NAME:
			RETURN_STATIC_STRING(
					"The request to connect and log on to an FTP server could not be completed"
					" because the supplied user name is incorrect"
			);
		case InternetCode::INTERNET_INSERT_CDROM:
			RETURN_STATIC_STRING(
					"The request requires a CD-ROM to be inserted in the CD-ROM drive to locate the"
					" resource requested. Windows Vista and Windows Server 2008 and earlier only"
			);
		case InternetCode::INTERNET_INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"An internal error has occurred"
			);
		case InternetCode::INTERNET_INVALID_CA:
			RETURN_STATIC_STRING(
					"The function is unfamiliar with the Certificate Authority that generated the"
					" server's certificate"
			);
		case InternetCode::INTERNET_INVALID_OPERATION:
			RETURN_STATIC_STRING(
					"The requested operation is invalid"
			);
		case InternetCode::INTERNET_INVALID_OPTION:
			RETURN_STATIC_STRING(
					"A request to InternetQueryOption or InternetSetOption specified an invalid"
					" option value"
			);
		case InternetCode::INTERNET_INVALID_PROXY_REQUEST:
			RETURN_STATIC_STRING(
					"The request to the proxy was invalid"
			);
		case InternetCode::INTERNET_INVALID_URL:
			RETURN_STATIC_STRING(
					"The URL is invalid"
			);
		case InternetCode::INTERNET_ITEM_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested item could not be located"
			);
		case InternetCode::INTERNET_LOGIN_FAILURE:
			RETURN_STATIC_STRING(
					"The request to connect and log on to an FTP server failed"
			);
		case InternetCode::INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY:
			RETURN_STATIC_STRING(
					"The MS-Logoff digest header has been returned from the website. This header"
					" specifically instructs the digest package to purge credentials for the"
					" associated realm. This error will only be returned if"
					" INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY option has been set;"
					" otherwise, ERROR_INTERNET_LOGIN_FAILURE is returned"
			);
		case InternetCode::INTERNET_MIXED_SECURITY:
			RETURN_STATIC_STRING(
					"The content is not entirely secure. Some of the content being viewed may have"
					" come from unsecured servers"
			);
		case InternetCode::INTERNET_NAME_NOT_RESOLVED:
			RETURN_STATIC_STRING(
					"The server name could not be resolved"
			);
		case InternetCode::INTERNET_NEED_MSN_SSPI_PKG:
			RETURN_STATIC_STRING(
					"Not currently implemented"
			);
		case InternetCode::INTERNET_NEED_UI:
			RETURN_STATIC_STRING(
					"A user interface or other blocking operation has been requested. Windows Vista"
					" and Windows Server 2008 and earlier only"
			);
		case InternetCode::INTERNET_NOT_SET_CALLBACK:
			RETURN_STATIC_STRING(
					"An asynchronous request could not be made because a callback function has not"
					" been set"
			);
		case InternetCode::INTERNET_NO_CONTEXT:
			RETURN_STATIC_STRING(
					"An asynchronous request could not be made because a zero context value was"
					" supplied"
			);
		case InternetCode::INTERNET_NO_DIRECT_ACCESS:
			RETURN_STATIC_STRING(
					"Direct network access cannot be made at this time"
			);
		case InternetCode::INTERNET_NOT_INITIALIZED:
			RETURN_STATIC_STRING(
					"Initialization of the WinINet API has not occurred. Indicates that a"
					" higher-level function, such as InternetOpen, has not been called yet"
			);
		case InternetCode::INTERNET_NOT_PROXY_REQUEST:
			RETURN_STATIC_STRING(
					"The request cannot be made via a proxy"
			);
		case InternetCode::INTERNET_OPERATION_CANCELLED:
			RETURN_STATIC_STRING(
					"The operation was canceled, usually because the handle on which the request"
					" was operating was closed before the operation completed"
			);
		case InternetCode::INTERNET_OPTION_NOT_SETTABLE:
			RETURN_STATIC_STRING(
					"The requested option cannot be set, only queried"
			);
		case InternetCode::INTERNET_OUT_OF_HANDLES:
			RETURN_STATIC_STRING(
					"No more handles could be generated at this time"
			);
		case InternetCode::INTERNET_POST_IS_NON_SECURE:
			RETURN_STATIC_STRING(
					"The application is posting data to a server that is not secure"
			);
		case InternetCode::INTERNET_PROTOCOL_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested protocol could not be located"
			);
		case InternetCode::INTERNET_PROXY_SERVER_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The designated proxy server cannot be reached"
			);
		case InternetCode::INTERNET_REDIRECT_SCHEME_CHANGE:
			RETURN_STATIC_STRING(
					"The function could not handle the redirection, because the scheme changed (for"
					" example, HTTP to FTP)"
			);
		case InternetCode::INTERNET_REGISTRY_VALUE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"A required registry value could not be located"
			);
		case InternetCode::INTERNET_REQUEST_PENDING:
			RETURN_STATIC_STRING(
					"The required operation could not be completed because one or more requests are"
					" pending"
			);
		case InternetCode::INTERNET_RETRY_DIALOG:
			RETURN_STATIC_STRING(
					"The dialog box should be retried"
			);
		case InternetCode::INTERNET_SEC_CERT_CN_INVALID:
			RETURN_STATIC_STRING(
					"SSL certificate common name (host name field) is incorrect for example, if you"
					" entered www.server.com and the common name on the certificate says"
					" www.different.com"
			);
		case InternetCode::INTERNET_SEC_CERT_DATE_INVALID:
			RETURN_STATIC_STRING(
					"SSL certificate date that was received from the server is bad. The certificate"
					" is expired"
			);
		case InternetCode::INTERNET_SEC_CERT_ERRORS:
			RETURN_STATIC_STRING(
					"The SSL certificate contains errors"
			);
		case InternetCode::INTERNET_SEC_CERT_NO_REV:
			RETURN_STATIC_STRING(
					"The SSL certificate was not revoked"
			);
		case InternetCode::INTERNET_SEC_CERT_REV_FAILED:
			RETURN_STATIC_STRING(
					"Revocation of the SSL certificate failed"
			);
		case InternetCode::INTERNET_SEC_CERT_REVOKED:
			RETURN_STATIC_STRING(
					"The SSL certificate was revoked"
			);
		case InternetCode::INTERNET_SEC_INVALID_CERT:
			RETURN_STATIC_STRING(
					"The SSL certificate is invalid"
			);
		case InternetCode::INTERNET_SECURITY_CHANNEL_ERROR:
			RETURN_STATIC_STRING(
					"The application experienced an internal error loading the SSL libraries"
			);
		case InternetCode::INTERNET_SERVER_UNREACHABLE:
			RETURN_STATIC_STRING(
					"The website or server indicated is unreachable"
			);
		case InternetCode::INTERNET_SHUTDOWN:
			RETURN_STATIC_STRING(
					"WinINet support is being shut down or unloaded"
			);
		case InternetCode::INTERNET_TCPIP_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"The required protocol stack is not loaded and the application cannot start"
					" WinSock"
			);
		case InternetCode::INTERNET_TIMEOUT:
			RETURN_STATIC_STRING(
					"The request has timed out"
			);
		case InternetCode::INTERNET_UNABLE_TO_CACHE_FILE:
			RETURN_STATIC_STRING(
					"The function was unable to cache the file"
			);
		case InternetCode::INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT:
			RETURN_STATIC_STRING(
					"The automatic proxy configuration script could not be downloaded. The"
					" INTERNET_FLAG_MUST_CACHE_REQUEST flag was set"
			);
		case InternetCode::INTERNET_UNRECOGNIZED_SCHEME:
			RETURN_STATIC_STRING(
					"The URL scheme could not be recognized, or is not supported"
			);
		case InternetCode::INVALID_HANDLE:
			RETURN_STATIC_STRING(
					"The handle that was passed to the API has been either invalidated or closed."
					" Declared in Winerror.h"
			);
		case InternetCode::MORE_DATA:
			RETURN_STATIC_STRING(
					"More data is available. Declared in Winerror.h"
			);
		case InternetCode::NO_MORE_FILES:
			RETURN_STATIC_STRING(
					"No more files have been found. Declared in Winerror.h"
			);
		case InternetCode::NO_MORE_ITEMS:
			RETURN_STATIC_STRING(
					"No more items have been found. Declared in Winerror.h"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
