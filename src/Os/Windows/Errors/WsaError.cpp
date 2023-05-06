#include <FlameIDE/../../src/Os/Windows/WsaError.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2
enum class WsaCode: decltype(::WSAGetLastError())
{
	INVALID_HANDLE = WSA_INVALID_HANDLE
// Specified event object handle is invalid.
// An application attempts to use an event object, but the specified handle is not valid.


	, NOT_ENOUGH_MEMORY = WSA_NOT_ENOUGH_MEMORY
// Insufficient memory available.
// An application used a Windows Sockets function that directly maps to a Windows function. The Windows function is indicating a lack of required memory resources.

	, INVALID_PARAMETER = WSA_INVALID_PARAMETER
// One or more parameters are invalid.
// An application used a Windows Sockets function which directly maps to a Windows function. The Windows function is indicating a problem with one or more parameters.

	, OPERATION_ABORTED = WSA_OPERATION_ABORTED
// Overlapped operation aborted.
// An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl.

	, IO_INCOMPLETE = WSA_IO_INCOMPLETE
// Overlapped I/O event object not in signaled state.
// The application has tried to determine the status of an overlapped operation which is not yet completed. Applications that use WSAGetOverlappedResult (with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete.

	, IO_PENDING = WSA_IO_PENDING
// Overlapped operations will complete later.
// The application has initiated an overlapped operation that cannot be completed immediately. A completion indication will be given later when the operation has been completed.

	, INTRRUPTED_CALL = WSAEINTR
// Interrupted function call.
// A blocking operation was interrupted by a call to WSACancelBlockingCall.

	, BAD_HANDLE = WSAEBADF
// File handle is not valid.
// The file handle supplied is not valid.

	, PERMISSION_DENIED = WSAEACCES
// Permission denied.
// An attempt was made to access a socket in a way forbidden by its access permissions. An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST).
// Another possible reason for the WSAEACCES error is that when the bind function is called (on Windows NT 4.0 with SP4 and later), another application, service, or kernel mode driver is bound to the same address with exclusive access. Such exclusive access is a new feature of Windows NT 4.0 with SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option.

	, BAD_ADDRESS = WSAEFAULT
// Bad address.
// The system detected an invalid pointer address in attempting to use a pointer argument of a call. This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr).

	, INVALID_ARGUMENT = WSAEINVAL
// Invalid argument.
// Some invalid argument was supplied (for example, specifying an invalid level to the setsockopt function). In some instances, it also refers to the current state of the socket—for instance, calling accept on a socket that is not listening.

	, TOO_MANY_FILES = WSAEMFILE
// Too many open files.
// Too many open sockets. Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread.

	, WOULD_BLOCK = WSAEWOULDBLOCK
// Resource temporarily unavailable.
// This error is returned from operations on nonblocking sockets that cannot be completed immediately, for example recv when no data is queued to be read from the socket. It is a nonfatal error, and the operation should be retried later. It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, since some time must elapse for the connection to be established.

	, IN_PROGRESS = WSAEINPROGRESS
// Operation now in progress.
// A blocking operation is currently executing. Windows Sockets only allows a single blocking operation—per- task or thread—to be outstanding, and if any other function call is made (whether or not it references that or any other socket) the function fails with the WSAEINPROGRESS error.

	, ALREADY = WSAEALREADY
// Operation already in progress.
// An operation was attempted on a nonblocking socket with an operation already in progress—that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed.

	, IS_NOT_SOCKET = WSAENOTSOCK
// Socket operation on nonsocket.
// An operation was attempted on something that is not a socket. Either the socket handle parameter
// did not reference a valid socket, or for select, a member of an fd_set was not valid.

	, DESTINATION_REQUIRED = WSAEDESTADDRREQ
// Destination address required.
// A required address was omitted from an operation on a socket. For example, this error is returned if sendto is called with the remote address of ADDR_ANY.

	, MESSAGE_SIZE = WSAEMSGSIZE
// Message too long.
// A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.

	, PROTOCOL_TYPE = 10041
// Protocol wrong type for socket.
// A protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.

	, INVALID_PROTOCOL_OPTION = WSAENOPROTOOPT
// Bad protocol option.
// An unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.

	, PROTOCOL_NOT_SUPPORTED = WSAEPROTONOSUPPORT
// Protocol not supported.
// The requested protocol has not been configured into the system, or no implementation for it
// exists. For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol.

	, SOCKET_NOT_SUPPORTED = WSAESOCKTNOSUPPORT
// Socket type not supported.
// The support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.

	, OPERATION_NOT_SUPPORTED = WSAEOPNOTSUPP
// Operation not supported.
// The attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.

	, PROTOCOL_FAMILY_NOT_SUPPORTED = WSAEPFNOSUPPORT
// Protocol family not supported.
// The protocol family has not been configured into the system or no implementation for it exists. This message has a slightly different meaning from WSAEAFNOSUPPORT. However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT.

	, ADDRESS_FAMILY_NOT_SUPPORTED = WSAEAFNOSUPPORT
// Address family not supported by protocol family.
// An address incompatible with the requested protocol was used. All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). This error is returned if an incorrect protocol is explicitly requested in the socket call, or if an address of the wrong family is used for a socket, for example, in sendto.

	, ADDRINUSE = WSAEADDRINUSE
// Address already in use.
// Typically, only one usage of each socket address (protocol/IP address/port) is permitted. This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing. For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). Client applications usually need not call bind at all—connect chooses an unused port automatically. When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf.

	, ADDRNOTAVAIL = WSAEADDRNOTAVAIL
// Cannot assign requested address.
// The requested address is not valid in its context. This normally results from an attempt to bind to an address that is not valid for the local computer. This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port is not valid for a remote computer (for example, address or port 0).

	, NETDOWN = WSAENETDOWN
// Network is down.
// A socket operation encountered a dead network. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself.

	, NETUNREACH = WSAENETUNREACH
// Network is unreachable.
// A socket operation was attempted to an unreachable network. This usually means the local software knows no route to reach the remote host.

	, NETRESET = WSAENETRESET
// Network dropped connection on reset.
// The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.

	, CONNABORTED = WSAECONNABORTED
// Software caused connection abort.
// An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.

	, CONNRESET = WSAECONNRESET
// Connection reset by peer.
// An existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.

	, NOBUFS = WSAENOBUFS
// No buffer space available.
// An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.

	, ISCONN = WSAEISCONN
// Socket is already connected.
// A connect request was made on an already-connected socket. Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence.

	, NOTCONN = WSAENOTCONN
// Socket is not connected.
// A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied. Any other type of operation might also return this error—for example, setsockopt setting SO_KEEPALIVE if the connection has been reset.

	, SHUTDOWN = WSAESHUTDOWN
// Cannot send after socket shutdown.
// A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued.

	, TOOMANYREFS = WSAETOOMANYREFS
// Too many references.
// Too many references to some kernel object.

	, TIMEDOUT = WSAETIMEDOUT
// Connection timed out.
// A connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond.

	, CONNREFUSED = WSAECONNREFUSED
// Connection refused.
// No connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host—that is, one with no server application running.

	, LOOP = WSAELOOP
// Cannot translate name.
// Cannot translate a name.

	, NAMETOOLONG = WSAENAMETOOLONG
// Name too long.
// A name component or a name was too long.

	, HOSTDOWN = WSAEHOSTDOWN
// Host is down.
// A socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. These conditions are more likely to be indicated by the error WSAETIMEDOUT.

	, HOSTUNREACH = WSAEHOSTUNREACH
// No route to host.
// A socket operation was attempted to an unreachable host. See WSAENETUNREACH.

	, NOTEMPTY = WSAENOTEMPTY
// Directory not empty.
// Cannot remove a directory that is not empty.

	, PROCLIM = WSAEPROCLIM
// Too many processes.
// A Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously. WSAStartup may fail with this error if the limit has been reached.

	, USERS = WSAEUSERS
// User quota exceeded.
// Ran out of user quota.

	, DQUOT = WSAEDQUOT
// Disk quota exceeded.
// Ran out of disk quota.

	, STALE = WSAESTALE
// Stale file handle reference.
// The file handle reference is no longer available.

	, REMOTE = WSAEREMOTE
// Item is remote.
// The item is not available locally.

	, SYSNOTREADY = WSASYSNOTREADY
// Network subsystem is unavailable.
// This error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Users should check:
// * That the appropriate Windows Sockets DLL file is in the current path.
// * That they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded.
// * The Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly.

	, VERNOTSUPPORTED = WSAVERNOTSUPPORTED
// Winsock.dll version out of range.
// The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed.

	, OTINITIALISED = WSANOTINITIALISED
// Successful WSAStartup not yet performed.
// Either the application has not called WSAStartup or WSAStartup failed. The application may be accessing a socket that the current active task does not own (that is, trying to share a socket between tasks), or WSACleanup has been called too many times.

	, DISCON = WSAEDISCON
// Graceful shutdown in progress.
// Returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence.

	, NOMORE = WSAENOMORE
// No more results.
// No more results can be returned by the WSALookupServiceNext function.

	, HAS_BEEN_CANCELLED = WSAECANCELLED
// Call has been canceled.
// A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.

	, INVALIDPROCTABLE = WSAEINVALIDPROCTABLE
// Procedure call table is invalid.
// The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. This is usually caused by one or more of the function pointers being NULL.

	, INVALIDPROVIDER = WSAEINVALIDPROVIDER
// Service provider is invalid.
// The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found. This error is also returned if the service provider returned a version number other than 2.0.

	, PROVIDERFAILEDINIT = WSAEPROVIDERFAILEDINIT
// Service provider failed to initialize.
// The requested service provider could not be loaded or initialized. This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed.

	, SYSCALL_FAILURE = WSASYSCALLFAILURE
// System call failure.
// A system call that should never fail has failed. This is a generic error code, returned under various conditions.
// Returned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs.
// Returned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error.

	, SERVICE_NOT_FOUND = WSASERVICE_NOT_FOUND
// Service not found.
// No such service is known. The service cannot be found in the specified name space.

	, TYPE_NOT_FOUND = WSATYPE_NOT_FOUND
// Class type not found.
// The specified class was not found.

	, NO_MORE_RESULTS = WSA_E_NO_MORE
// No more results.
// No more results can be returned by the WSALookupServiceNext function.

	, CANCELLED_CALL = WSA_E_CANCELLED
// Call was canceled.
// A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.

	, REFUSED = WSAEREFUSED
// Database query was refused.
// A database query failed because it was actively refused.

	, OST_NOT_FOUND = WSAHOST_NOT_FOUND
// Host not found.
// No such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database.

	, RY_AGAIN = WSATRY_AGAIN
// Nonauthoritative host not found.
// This is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server. A retry at some time later may be successful.

	, O_RECOVERY = WSANO_RECOVERY
// This is a nonrecoverable error.
// This indicates that some sort of nonrecoverable error occurred during a database lookup. This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error.

	, O_DATA = WSANO_DATA
// Valid name, no data record of requested type.
// The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName) which uses the DNS (Domain Name Server). An MX record is returned but no A record—indicating the host itself exists, but is not directly reachable.

	, QOS_RECEIVERS = WSA_QOS_RECEIVERS
// QoS receivers.
// At least one QoS reserve has arrived.

	, QOS_SENDERS = WSA_QOS_SENDERS
// QoS senders.
// At least one QoS send path has arrived.

	, QOS_NO_SENDERS = WSA_QOS_NO_SENDERS
// No QoS senders.
// There are no QoS senders.

	, QOS_NO_RECEIVERS = WSA_QOS_NO_RECEIVERS
// QoS no receivers.
// There are no QoS receivers.

	, QOS_REQUEST_CONFIRMED = WSA_QOS_REQUEST_CONFIRMED
// QoS request confirmed.
// The QoS reserve request has been confirmed.

	, QOS_ADMISSION_FAILURE = WSA_QOS_ADMISSION_FAILURE
// QoS admission error.
// A QoS error occurred due to lack of resources.

	, QOS_POLICY_FAILURE = WSA_QOS_POLICY_FAILURE
// QoS policy failure.
// The QoS request was rejected because the policy system couldn't allocate the requested resource within the existing policy.

	, QOS_BAD_STYLE = WSA_QOS_BAD_STYLE
// QoS bad style.
// An unknown or conflicting QoS style was encountered.

	, QOS_BAD_OBJECT = WSA_QOS_BAD_OBJECT
// QoS bad object.
// A problem was encountered with some part of the filterspec or the provider-specific buffer in general.

	, QOS_TRAFFIC_CTRL_ERROR = WSA_QOS_TRAFFIC_CTRL_ERROR
// QoS traffic control error.
// An error with the underlying traffic control (TC) API as the generic QoS request was converted for local enforcement by the TC API. This could be due to an out of memory error or to an internal QoS provider error.

	, QOS_GENERIC_ERROR = WSA_QOS_GENERIC_ERROR
// QoS generic error.
// A general QoS error.

	, QOS_ESERVICETYPE = WSA_QOS_ESERVICETYPE
// QoS service type error.
// An invalid or unrecognized service type was found in the QoS flowspec.

	, QOS_EFLOWSPEC = WSA_QOS_EFLOWSPEC
// QoS flowspec error.
// An invalid or inconsistent flowspec was found in the QOS structure.

	, QOS_EPROVSPECBUF = WSA_QOS_EPROVSPECBUF
// Invalid QoS provider buffer.
// An invalid QoS provider-specific buffer.

	, QOS_EFILTERSTYLE = WSA_QOS_EFILTERSTYLE
// Invalid QoS filter style.
// An invalid QoS filter style was used.

	, QOS_EFILTERTYPE = WSA_QOS_EFILTERTYPE
// Invalid QoS filter type.
// An invalid QoS filter type was used.

	, QOS_EFILTERCOUNT = WSA_QOS_EFILTERCOUNT
// Incorrect QoS filter count.
// An incorrect number of QoS FILTERSPECs were specified in the FLOWDESCRIPTOR.

	, QOS_EOBJLENGTH = WSA_QOS_EOBJLENGTH
// Invalid QoS object length.
// An object with an invalid ObjectLength field was specified in the QoS provider-specific buffer.

	, QOS_EFLOWCOUNT = WSA_QOS_EFLOWCOUNT
// Incorrect QoS flow count.
// An incorrect number of flow descriptors was specified in the QoS structure.

	, QOS_EUNKOWNPSOBJ = WSA_QOS_EUNKOWNPSOBJ
// Unrecognized QoS object.
// An unrecognized object was found in the QoS provider-specific buffer.

	, QOS_EPOLICYOBJ = WSA_QOS_EPOLICYOBJ
// Invalid QoS policy object.
// An invalid policy object was found in the QoS provider-specific buffer.

	, QOS_EFLOWDESC = WSA_QOS_EFLOWDESC
// Invalid QoS flow descriptor.
// An invalid QoS flow descriptor was found in the flow descriptor list.

	, QOS_EPSFLOWSPEC = WSA_QOS_EPSFLOWSPEC
// Invalid QoS provider-specific flowspec.
// An invalid or inconsistent flowspec was found in the QoS provider-specific buffer.

	, QOS_EPSFILTERSPEC = WSA_QOS_EPSFILTERSPEC
// Invalid QoS provider-specific filterspec.
// An invalid FILTERSPEC was found in the QoS provider-specific buffer.

	, QOS_ESDMODEOBJ = WSA_QOS_ESDMODEOBJ
// Invalid QoS shape discard mode object.
// An invalid shape discard mode object was found in the QoS provider-specific buffer.

	, QOS_ESHAPERATEOBJ = WSA_QOS_ESHAPERATEOBJ
// Invalid QoS shaping rate object.
// An invalid shaping rate object was found in the QoS provider-specific buffer.

	, QOS_RESERVED_PETYPE = WSA_QOS_RESERVED_PETYPE
// Reserved policy QoS element type.
// A reserved policy element was found in the QoS provider-specific buffer.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *wsaCodeToString(os::Status status) noexcept
{
	const auto errorCode = static_cast<WsaCode>(status);
	switch (errorCode) {
		case WsaCode::INVALID_HANDLE:
			RETURN_STATIC_STRING("Specified event object handle is invalid");
		case WsaCode::NOT_ENOUGH_MEMORY:
			RETURN_STATIC_STRING("Insufficient memory available");
		case WsaCode::INVALID_PARAMETER:
			RETURN_STATIC_STRING("One or more parameters are invalid");
		case WsaCode::OPERATION_ABORTED:
			RETURN_STATIC_STRING("Overlapped operation aborted");
		case WsaCode::IO_INCOMPLETE:
			RETURN_STATIC_STRING("Overlapped I/O event object not in signaled state");
		case WsaCode::IO_PENDING:
			RETURN_STATIC_STRING("Overlapped operations will complete later");
		case WsaCode::INTRRUPTED_CALL:
			RETURN_STATIC_STRING("Interrupted function call");
		case WsaCode::BAD_HANDLE:
			RETURN_STATIC_STRING("File handle is not valid");
		case WsaCode::PERMISSION_DENIED:
			RETURN_STATIC_STRING("Permission denied");
		case WsaCode::BAD_ADDRESS:
			RETURN_STATIC_STRING("Bad address");
		case WsaCode::INVALID_ARGUMENT:
			RETURN_STATIC_STRING("Invalid argument");
		case WsaCode::TOO_MANY_FILES:
			RETURN_STATIC_STRING("Too many open files");
		case WsaCode::WOULD_BLOCK:
			RETURN_STATIC_STRING("Resource temporarily unavailable");
		case WsaCode::IN_PROGRESS:
			RETURN_STATIC_STRING("Operation now in progress");
		case WsaCode::ALREADY:
			RETURN_STATIC_STRING("Operation already in progress");
		case WsaCode::IS_NOT_SOCKET:
			RETURN_STATIC_STRING("Socket operation on nonsocket");
		case WsaCode::DESTINATION_REQUIRED:
			RETURN_STATIC_STRING("Destination address required");
		case WsaCode::MESSAGE_SIZE:
			RETURN_STATIC_STRING("Message too long");
		case WsaCode::PROTOCOL_TYPE:
			RETURN_STATIC_STRING("Protocol wrong type for socket");
		case WsaCode::INVALID_PROTOCOL_OPTION:
			RETURN_STATIC_STRING("Bad protocol option");
		case WsaCode::PROTOCOL_NOT_SUPPORTED:
			RETURN_STATIC_STRING("Protocol not supported");
		case WsaCode::SOCKET_NOT_SUPPORTED:
			RETURN_STATIC_STRING("Socket type not supported");
		case WsaCode::OPERATION_NOT_SUPPORTED:
			RETURN_STATIC_STRING("Operation not supported");
		case WsaCode::PROTOCOL_FAMILY_NOT_SUPPORTED:
			RETURN_STATIC_STRING("Protocol family not supported");
		case WsaCode::ADDRESS_FAMILY_NOT_SUPPORTED:
			RETURN_STATIC_STRING("Address family not supported by protocol family");
		case WsaCode::ADDRINUSE:
			RETURN_STATIC_STRING("Address already in use");
		case WsaCode::ADDRNOTAVAIL:
			RETURN_STATIC_STRING("Cannot assign requested address");
		case WsaCode::NETDOWN:
			RETURN_STATIC_STRING("Network is down");
		case WsaCode::NETUNREACH:
			RETURN_STATIC_STRING("Network is unreachable");
		case WsaCode::NETRESET:
			RETURN_STATIC_STRING("Network dropped connection on reset");
		case WsaCode::CONNABORTED:
			RETURN_STATIC_STRING("Software caused connection abort");
		case WsaCode::CONNRESET:
			RETURN_STATIC_STRING("Connection reset by peer");
		case WsaCode::NOBUFS:
			RETURN_STATIC_STRING("No buffer space available");
		case WsaCode::ISCONN:
			RETURN_STATIC_STRING("Socket is already connected");
		case WsaCode::NOTCONN:
			RETURN_STATIC_STRING("Socket is not connected");
		case WsaCode::SHUTDOWN:
			RETURN_STATIC_STRING("Cannot send after socket shutdown");
		case WsaCode::TOOMANYREFS:
			RETURN_STATIC_STRING("Too many references to some kernel object");
		case WsaCode::TIMEDOUT:
			RETURN_STATIC_STRING("Connection timed out");
		case WsaCode::CONNREFUSED:
			RETURN_STATIC_STRING("Connection refused");
		case WsaCode::LOOP:
			RETURN_STATIC_STRING("Cannot translate name");
		case WsaCode::NAMETOOLONG:
			RETURN_STATIC_STRING("Name too long");
		case WsaCode::HOSTDOWN:
			RETURN_STATIC_STRING("Host is down");
		case WsaCode::HOSTUNREACH:
			RETURN_STATIC_STRING("No route to host");
		case WsaCode::NOTEMPTY:
			RETURN_STATIC_STRING("Directory not empty");
		case WsaCode::PROCLIM:
			RETURN_STATIC_STRING("Too many processes");
		case WsaCode::USERS:
			RETURN_STATIC_STRING("User quota exceeded");
		case WsaCode::DQUOT:
			RETURN_STATIC_STRING("Disk quota exceeded");
		case WsaCode::STALE:
			RETURN_STATIC_STRING("Stale file handle reference");
		case WsaCode::REMOTE:
			RETURN_STATIC_STRING("Item is remote");
		case WsaCode::SYSNOTREADY:
			RETURN_STATIC_STRING("Network subsystem is unavailable");
		case WsaCode::VERNOTSUPPORTED:
			RETURN_STATIC_STRING("Winsock.dll version out of range");
		case WsaCode::OTINITIALISED:
			RETURN_STATIC_STRING("Successful WSAStartup not yet performed");
		case WsaCode::DISCON:
			RETURN_STATIC_STRING("Graceful shutdown in progress");
		case WsaCode::NOMORE:
			RETURN_STATIC_STRING("No more results");
		case WsaCode::HAS_BEEN_CANCELLED:
			RETURN_STATIC_STRING("Call has been canceled");
		case WsaCode::INVALIDPROCTABLE:
			RETURN_STATIC_STRING("Procedure call table is invalid");
		case WsaCode::INVALIDPROVIDER:
			RETURN_STATIC_STRING("Service provider is invalid");
		case WsaCode::PROVIDERFAILEDINIT:
			RETURN_STATIC_STRING("Service provider failed to initialize");
		case WsaCode::SYSCALL_FAILURE:
			RETURN_STATIC_STRING("System call failure");
		case WsaCode::SERVICE_NOT_FOUND:
			RETURN_STATIC_STRING("Service not found");
		case WsaCode::TYPE_NOT_FOUND:
			RETURN_STATIC_STRING("Class type not found");
		case WsaCode::NO_MORE_RESULTS:
			RETURN_STATIC_STRING("No more results");
		case WsaCode::CANCELLED_CALL:
			RETURN_STATIC_STRING("Call was canceled");
		case WsaCode::REFUSED:
			RETURN_STATIC_STRING("Database query was refused");
		case WsaCode::OST_NOT_FOUND:
			RETURN_STATIC_STRING("Host not found");
		case WsaCode::RY_AGAIN:
			RETURN_STATIC_STRING("Nonauthoritative host not found");
		case WsaCode::O_RECOVERY:
			RETURN_STATIC_STRING("This is a nonrecoverable error");
		case WsaCode::O_DATA:
			RETURN_STATIC_STRING("Valid name, no data record of requested type");
		case WsaCode::QOS_RECEIVERS:
			RETURN_STATIC_STRING("QoS receivers");
		case WsaCode::QOS_SENDERS:
			RETURN_STATIC_STRING("QoS senders");
		case WsaCode::QOS_NO_SENDERS:
			RETURN_STATIC_STRING("No QoS senders");
		case WsaCode::QOS_NO_RECEIVERS:
			RETURN_STATIC_STRING("QoS no receivers");
		case WsaCode::QOS_REQUEST_CONFIRMED:
			RETURN_STATIC_STRING("QoS request confirmed");
		case WsaCode::QOS_ADMISSION_FAILURE:
			RETURN_STATIC_STRING("QoS admission error");
		case WsaCode::QOS_POLICY_FAILURE:
			RETURN_STATIC_STRING("QoS policy failure");
		case WsaCode::QOS_BAD_STYLE:
			RETURN_STATIC_STRING("QoS bad style");
		case WsaCode::QOS_BAD_OBJECT:
			RETURN_STATIC_STRING("QoS bad object");
		case WsaCode::QOS_TRAFFIC_CTRL_ERROR:
			RETURN_STATIC_STRING("QoS traffic control error");
		case WsaCode::QOS_GENERIC_ERROR:
			RETURN_STATIC_STRING("QoS generic error");
		case WsaCode::QOS_ESERVICETYPE:
			RETURN_STATIC_STRING("QoS service type error");
		case WsaCode::QOS_EFLOWSPEC:
			RETURN_STATIC_STRING("QoS flowspec error");
		case WsaCode::QOS_EPROVSPECBUF:
			RETURN_STATIC_STRING("Invalid QoS provider buffer");
		case WsaCode::QOS_EFILTERSTYLE:
			RETURN_STATIC_STRING("Invalid QoS filter style");
		case WsaCode::QOS_EFILTERTYPE:
			RETURN_STATIC_STRING("Invalid QoS filter type");
		case WsaCode::QOS_EFILTERCOUNT:
			RETURN_STATIC_STRING("Incorrect QoS filter count");
		case WsaCode::QOS_EOBJLENGTH:
			RETURN_STATIC_STRING("Invalid QoS object length");
		case WsaCode::QOS_EFLOWCOUNT:
			RETURN_STATIC_STRING("Incorrect QoS flow count");
		case WsaCode::QOS_EUNKOWNPSOBJ:
			RETURN_STATIC_STRING("Unrecognized QoS object");
		case WsaCode::QOS_EPOLICYOBJ:
			RETURN_STATIC_STRING("Invalid QoS policy object");
		case WsaCode::QOS_EFLOWDESC:
			RETURN_STATIC_STRING("Invalid QoS flow descriptor");
		case WsaCode::QOS_EPSFLOWSPEC:
			RETURN_STATIC_STRING("Invalid QoS provider-specific flowspec");
		case WsaCode::QOS_EPSFILTERSPEC:
			RETURN_STATIC_STRING("Invalid QoS provider-specific filterspec");
		case WsaCode::QOS_ESDMODEOBJ:
			RETURN_STATIC_STRING("Invalid QoS shape discard mode object");
		case WsaCode::QOS_ESHAPERATEOBJ:
			RETURN_STATIC_STRING("Invalid QoS shaping rate object");
		case WsaCode::QOS_RESERVED_PETYPE:
			RETURN_STATIC_STRING("Reserved policy QoS element type");
	}
	return nullptr;
}

}}} // flame_ide::os::error
