#include <FlameIDE/../../src/Os/Windows/SystemCode9.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--12000-15999-
enum class SystemCode: decltype(::GetLastError())
{
	IPSEC_QM_POLICY_EXISTS =
#	if defined ERROR_IPSEC_QM_POLICY_EXISTS
			ERROR_IPSEC_QM_POLICY_EXISTS
#	else
				0x32C8
#	endif
		// The specified quick mode policy already exists.

	, IPSEC_QM_POLICY_NOT_FOUND =
#	if defined ERROR_IPSEC_QM_POLICY_NOT_FOUND
			ERROR_IPSEC_QM_POLICY_NOT_FOUND
#	else
			0x32C9
#	endif
		// The specified quick mode policy was not found.

	, IPSEC_QM_POLICY_IN_USE =
#	if defined ERROR_IPSEC_QM_POLICY_IN_USE
			ERROR_IPSEC_QM_POLICY_IN_USE
#	else
			0x32CA
#	endif
		// The specified quick mode policy is being used.

	, IPSEC_MM_POLICY_EXISTS =
#	if defined ERROR_IPSEC_MM_POLICY_EXISTS
			ERROR_IPSEC_MM_POLICY_EXISTS
#	else
			0x32CB
#	endif
		// The specified main mode policy already exists.

	, IPSEC_MM_POLICY_NOT_FOUND =
#	if defined ERROR_IPSEC_MM_POLICY_NOT_FOUND
			ERROR_IPSEC_MM_POLICY_NOT_FOUND
#	else
			0x32CC
#	endif
		// The specified main mode policy was not found.

	, IPSEC_MM_POLICY_IN_USE =
#	if defined ERROR_IPSEC_MM_POLICY_IN_USE
			ERROR_IPSEC_MM_POLICY_IN_USE
#	else
			0x32CD
#	endif
		// The specified main mode policy is being used.

	, IPSEC_MM_FILTER_EXISTS =
#	if defined ERROR_IPSEC_MM_FILTER_EXISTS
			ERROR_IPSEC_MM_FILTER_EXISTS
#	else
			0x32CE
#	endif
		// The specified main mode filter already exists.

	, IPSEC_MM_FILTER_NOT_FOUND =
#	if defined ERROR_IPSEC_MM_FILTER_NOT_FOUND
			ERROR_IPSEC_MM_FILTER_NOT_FOUND
#	else
			0x32CF
#	endif
		// The specified main mode filter was not found.

	, IPSEC_TRANSPORT_FILTER_EXISTS =
#	if defined ERROR_IPSEC_TRANSPORT_FILTER_EXISTS
			ERROR_IPSEC_TRANSPORT_FILTER_EXISTS
#	else
			0x32D0
#	endif
		// The specified transport mode filter already exists.

	, IPSEC_TRANSPORT_FILTER_NOT_FOUND =
#	if defined ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND
			ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND
#	else
			0x32D1
#	endif
		// The specified transport mode filter does not exist.

	, IPSEC_MM_AUTH_EXISTS =
#	if defined ERROR_IPSEC_MM_AUTH_EXISTS
			ERROR_IPSEC_MM_AUTH_EXISTS
#	else
			0x32D2
#	endif
		// The specified main mode authentication list exists.

	, IPSEC_MM_AUTH_NOT_FOUND =
#	if defined ERROR_IPSEC_MM_AUTH_NOT_FOUND
			ERROR_IPSEC_MM_AUTH_NOT_FOUND
#	else
			0x32D3
#	endif
		// The specified main mode authentication list was not found.

	, IPSEC_MM_AUTH_IN_USE =
#	if defined ERROR_IPSEC_MM_AUTH_IN_USE
			ERROR_IPSEC_MM_AUTH_IN_USE
#	else
			0x32D4
#	endif
		// The specified main mode authentication list is being used.

	, IPSEC_DEFAULT_MM_POLICY_NOT_FOUND =
#	if defined ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND
			ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND
#	else
			0x32D5
#	endif
		// The specified default main mode policy was not found.

	, IPSEC_DEFAULT_MM_AUTH_NOT_FOUND =
#	if defined ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND
			ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND
#	else
			0x32D6
#	endif
		// The specified default main mode authentication list was not found.

	, IPSEC_DEFAULT_QM_POLICY_NOT_FOUND =
#	if defined ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND
			ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND
#	else
			0x32D7
#	endif
		// The specified default quick mode policy was not found.

	, IPSEC_TUNNEL_FILTER_EXISTS =
#	if defined ERROR_IPSEC_TUNNEL_FILTER_EXISTS
			ERROR_IPSEC_TUNNEL_FILTER_EXISTS
#	else
			0x32D8
#	endif
		// The specified tunnel mode filter exists.

	, IPSEC_TUNNEL_FILTER_NOT_FOUND =
#	if defined ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND
			ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND
#	else
			0x32D9
#	endif
		// The specified tunnel mode filter was not found.

	, IPSEC_MM_FILTER_PENDING_DELETION =
#	if defined ERROR_IPSEC_MM_FILTER_PENDING_DELETION
			ERROR_IPSEC_MM_FILTER_PENDING_DELETION
#	else
			0x32DA
#	endif
		// The Main Mode filter is pending deletion.

	, IPSEC_TRANSPORT_FILTER_PENDING_DELETION =
#	if defined ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION
			ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION
#	else
			0x32DB
#	endif
		// The transport filter is pending deletion.

	, IPSEC_TUNNEL_FILTER_PENDING_DELETION =
#	if defined ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION
			ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION
#	else
			0x32DC
#	endif
		// The tunnel filter is pending deletion.

	, IPSEC_MM_POLICY_PENDING_DELETION =
#	if defined ERROR_IPSEC_MM_POLICY_PENDING_DELETION
			ERROR_IPSEC_MM_POLICY_PENDING_DELETION
#	else
			0x32DD
#	endif
		// The Main Mode policy is pending deletion.

	, IPSEC_MM_AUTH_PENDING_DELETION =
#	if defined ERROR_IPSEC_MM_AUTH_PENDING_DELETION
			ERROR_IPSEC_MM_AUTH_PENDING_DELETION
#	else
			0x32DE
#	endif
		// The Main Mode authentication bundle is pending deletion.

	, IPSEC_QM_POLICY_PENDING_DELETION =
#	if defined ERROR_IPSEC_QM_POLICY_PENDING_DELETION
			ERROR_IPSEC_QM_POLICY_PENDING_DELETION
#	else
			0x32DF
#	endif
		// The Quick Mode policy is pending deletion.

	, IPSEC_MM_POLICY_PRUNED =
#	if defined WARNING_IPSEC_MM_POLICY_PRUNED
			WARNING_IPSEC_MM_POLICY_PRUNED
#	else
			0x32E0
#	endif
		// The Main Mode policy was successfully added, but some of the requested offers are not supported.

	, IPSEC_QM_POLICY_PRUNED =
#	if defined WARNING_IPSEC_QM_POLICY_PRUNED
			WARNING_IPSEC_QM_POLICY_PRUNED
#	else
			0x32E1
#	endif
		// The Quick Mode policy was successfully added, but some of the requested offers are not supported.

	, IPSEC_IKE_NEG_STATUS_BEGIN =
#	if defined ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
			ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
#	else
			0x35E8
#	endif
		// ERROR_IPSEC_IKE_NEG_STATUS_BEGIN

	, IPSEC_IKE_AUTH_FAIL =
#	if defined ERROR_IPSEC_IKE_AUTH_FAIL
			ERROR_IPSEC_IKE_AUTH_FAIL
#	else
			0x35E9
#	endif
		// IKE authentication credentials are unacceptable.

	, IPSEC_IKE_ATTRIB_FAIL =
#	if defined ERROR_IPSEC_IKE_ATTRIB_FAIL
			ERROR_IPSEC_IKE_ATTRIB_FAIL
#	else
			0x35EA
#	endif
		// IKE security attributes are unacceptable.

	, IPSEC_IKE_NEGOTIATION_PENDING =
#	if defined ERROR_IPSEC_IKE_NEGOTIATION_PENDING
			ERROR_IPSEC_IKE_NEGOTIATION_PENDING
#	else
			0x35EB
#	endif
		// IKE Negotiation in progress.

	, IPSEC_IKE_GENERAL_PROCESSING_ERROR =
#	if defined ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR
			ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR
#	else
			0x35EC
#	endif
		// General processing error.

	, IPSEC_IKE_TIMED_OUT =
#	if defined ERROR_IPSEC_IKE_TIMED_OUT
			ERROR_IPSEC_IKE_TIMED_OUT
#	else
			0x35ED
#	endif
		// Negotiation timed out.

	, IPSEC_IKE_NO_CERT =
#	if defined ERROR_IPSEC_IKE_NO_CERT
			ERROR_IPSEC_IKE_NO_CERT
#	else
			0x35EE
#	endif
		// IKE failed to find valid machine certificate. Contact your Network Security Administrator about installing a valid certificate in the appropriate Certificate Store.

	, IPSEC_IKE_SA_DELETED =
#	if defined ERROR_IPSEC_IKE_SA_DELETED
			ERROR_IPSEC_IKE_SA_DELETED
#	else
			0x35EF
#	endif
		// IKE SA deleted by peer before establishment completed.

	, IPSEC_IKE_SA_REAPED =
#	if defined ERROR_IPSEC_IKE_SA_REAPED
			ERROR_IPSEC_IKE_SA_REAPED
#	else
			0x35F0
#	endif
		// IKE SA deleted before establishment completed.

	, IPSEC_IKE_MM_ACQUIRE_DROP =
#	if defined ERROR_IPSEC_IKE_MM_ACQUIRE_DROP
			ERROR_IPSEC_IKE_MM_ACQUIRE_DROP
#	else
			0x35F1
#	endif
		// Negotiation request sat in Queue too long.

	, IPSEC_IKE_QM_ACQUIRE_DROP =
#	if defined ERROR_IPSEC_IKE_QM_ACQUIRE_DROP
			ERROR_IPSEC_IKE_QM_ACQUIRE_DROP
#	else
			0x35F2
#	endif
		// Negotiation request sat in Queue too long.

	, IPSEC_IKE_QUEUE_DROP_MM =
#	if defined ERROR_IPSEC_IKE_QUEUE_DROP_MM
			ERROR_IPSEC_IKE_QUEUE_DROP_MM
#	else
			0x35F3
#	endif
		// Negotiation request sat in Queue too long.

	, IPSEC_IKE_QUEUE_DROP_NO_MM =
#	if defined ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM
			ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM
#	else
			0x35F4
#	endif
		// Negotiation request sat in Queue too long.

	, IPSEC_IKE_DROP_NO_RESPONSE =
#	if defined ERROR_IPSEC_IKE_DROP_NO_RESPONSE
			ERROR_IPSEC_IKE_DROP_NO_RESPONSE
#	else
			0x35F5
#	endif
		// No response from peer.

	, IPSEC_IKE_MM_DELAY_DROP =
#	if defined ERROR_IPSEC_IKE_MM_DELAY_DROP
			ERROR_IPSEC_IKE_MM_DELAY_DROP
#	else
			0x35F6
#	endif
		// Negotiation took too long.

	, IPSEC_IKE_QM_DELAY_DROP =
#	if defined ERROR_IPSEC_IKE_QM_DELAY_DROP
			ERROR_IPSEC_IKE_QM_DELAY_DROP
#	else
			0x35F7
#	endif
		// Negotiation took too long.

	, IPSEC_IKE_ERROR =
#	if defined ERROR_IPSEC_IKE_ERROR
			ERROR_IPSEC_IKE_ERROR
#	else
			0x35F8
#	endif
		// Unknown error occurred.

	, IPSEC_IKE_CRL_FAILED =
#	if defined ERROR_IPSEC_IKE_CRL_FAILED
			ERROR_IPSEC_IKE_CRL_FAILED
#	else
			0x35F9
#	endif
		// Certificate Revocation Check failed.

	, IPSEC_IKE_INVALID_KEY_USAGE =
#	if defined ERROR_IPSEC_IKE_INVALID_KEY_USAGE
			ERROR_IPSEC_IKE_INVALID_KEY_USAGE
#	else
			0x35FA
#	endif
		// Invalid certificate key usage.

	, IPSEC_IKE_INVALID_CERT_TYPE =
#	if defined ERROR_IPSEC_IKE_INVALID_CERT_TYPE
			ERROR_IPSEC_IKE_INVALID_CERT_TYPE
#	else
			0x35FB
#	endif
		// Invalid certificate type.

	, IPSEC_IKE_NO_PRIVATE_KEY =
#	if defined ERROR_IPSEC_IKE_NO_PRIVATE_KEY
			ERROR_IPSEC_IKE_NO_PRIVATE_KEY
#	else
			0x35FC
#	endif
		// IKE negotiation failed because the machine certificate used does not have a private key. IPsec certificates require a private key. Contact your Network Security administrator about replacing with a certificate that has a private key.

	, IPSEC_IKE_SIMULTANEOUS_REKEY =
#	if defined ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY
			ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY
#	else
			0x35FD
#	endif
		// Simultaneous rekeys were detected.

	, IPSEC_IKE_DH_FAIL =
#	if defined ERROR_IPSEC_IKE_DH_FAIL
			ERROR_IPSEC_IKE_DH_FAIL
#	else
			0x35FE
#	endif
		// Failure in Diffie-Hellman computation.

	, IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED =
#	if defined ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED
			ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED
#	else
			0x35FF
#	endif
		// Don't know how to process critical payload.

	, IPSEC_IKE_INVALID_HEADER =
#	if defined ERROR_IPSEC_IKE_INVALID_HEADER
			ERROR_IPSEC_IKE_INVALID_HEADER
#	else
			0x3600
#	endif
		// Invalid header.

	, IPSEC_IKE_NO_POLICY =
#	if defined ERROR_IPSEC_IKE_NO_POLICY
			ERROR_IPSEC_IKE_NO_POLICY
#	else
			0x3601
#	endif
		// No policy configured.

	, IPSEC_IKE_INVALID_SIGNATURE =
#	if defined ERROR_IPSEC_IKE_INVALID_SIGNATURE
			ERROR_IPSEC_IKE_INVALID_SIGNATURE
#	else
			0x3602
#	endif
		// Failed to verify signature.

	, IPSEC_IKE_KERBEROS_ERROR =
#	if defined ERROR_IPSEC_IKE_KERBEROS_ERROR
			ERROR_IPSEC_IKE_KERBEROS_ERROR
#	else
			0x3603
#	endif
		// Failed to authenticate using Kerberos.

	, IPSEC_IKE_NO_PUBLIC_KEY =
#	if defined ERROR_IPSEC_IKE_NO_PUBLIC_KEY
			ERROR_IPSEC_IKE_NO_PUBLIC_KEY
#	else
			0x3604
#	endif
		// Peer's certificate did not have a public key.

	, IPSEC_IKE_PROCESS_ERR =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR
			ERROR_IPSEC_IKE_PROCESS_ERR
#	else
			0x3605
#	endif
		// Error processing error payload.

	, IPSEC_IKE_PROCESS_ERR_SA =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_SA
			ERROR_IPSEC_IKE_PROCESS_ERR_SA
#	else
			0x3606
#	endif
		// Error processing SA payload.

	, IPSEC_IKE_PROCESS_ERR_PROP =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_PROP
			ERROR_IPSEC_IKE_PROCESS_ERR_PROP
#	else
			0x3607
#	endif
		// Error processing Proposal payload.

	, IPSEC_IKE_PROCESS_ERR_TRANS =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_TRANS
			ERROR_IPSEC_IKE_PROCESS_ERR_TRANS
#	else
			0x3608
#	endif
		// Error processing Transform payload.

	, IPSEC_IKE_PROCESS_ERR_KE =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_KE
			ERROR_IPSEC_IKE_PROCESS_ERR_KE
#	else
			0x3609
#	endif
		// Error processing KE payload.

	, IPSEC_IKE_PROCESS_ERR_ID =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_ID
			ERROR_IPSEC_IKE_PROCESS_ERR_ID
#	else
			0x360A
#	endif
		// Error processing ID payload.

	, IPSEC_IKE_PROCESS_ERR_CERT =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_CERT
			ERROR_IPSEC_IKE_PROCESS_ERR_CERT
#	else
			0x360B
#	endif
		// Error processing Cert payload.

	, IPSEC_IKE_PROCESS_ERR_CERT_REQ =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ
			ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ
#	else
			0x360C
#	endif
		// Error processing Certificate Request payload.

	, IPSEC_IKE_PROCESS_ERR_HASH =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_HASH
			ERROR_IPSEC_IKE_PROCESS_ERR_HASH
#	else
			0x360D
#	endif
		// Error processing Hash payload.

	, IPSEC_IKE_PROCESS_ERR_SIG =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_SIG
			ERROR_IPSEC_IKE_PROCESS_ERR_SIG
#	else
			0x360E
#	endif
		// Error processing Signature payload.

	, IPSEC_IKE_PROCESS_ERR_NONCE =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_NONCE
			ERROR_IPSEC_IKE_PROCESS_ERR_NONCE
#	else
			0x360F
#	endif
		// Error processing Nonce payload.

	, IPSEC_IKE_PROCESS_ERR_NOTIFY =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY
			ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY
#	else
			0x3610
#	endif
		// Error processing Notify payload.

	, IPSEC_IKE_PROCESS_ERR_DELETE =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_DELETE
			ERROR_IPSEC_IKE_PROCESS_ERR_DELETE
#	else
			0x3611
#	endif
		// Error processing Delete Payload.

	, IPSEC_IKE_PROCESS_ERR_VENDOR =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR
			ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR
#	else
			0x3612
#	endif
		// Error processing VendorId payload.

	, IPSEC_IKE_INVALID_PAYLOAD =
#	if defined ERROR_IPSEC_IKE_INVALID_PAYLOAD
			ERROR_IPSEC_IKE_INVALID_PAYLOAD
#	else
			0x3613
#	endif
		// Invalid payload received.

	, IPSEC_IKE_LOAD_SOFT_SA =
#	if defined ERROR_IPSEC_IKE_LOAD_SOFT_SA
			ERROR_IPSEC_IKE_LOAD_SOFT_SA
#	else
			0x3614
#	endif
		// Soft SA loaded.

	, IPSEC_IKE_SOFT_SA_TORN_DOWN =
#	if defined ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN
			ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN
#	else
			0x3615
#	endif
		// Soft SA torn down.

	, IPSEC_IKE_INVALID_COOKIE =
#	if defined ERROR_IPSEC_IKE_INVALID_COOKIE
			ERROR_IPSEC_IKE_INVALID_COOKIE
#	else
			0x3616
#	endif
		// Invalid cookie received.

	, IPSEC_IKE_NO_PEER_CERT =
#	if defined ERROR_IPSEC_IKE_NO_PEER_CERT
			ERROR_IPSEC_IKE_NO_PEER_CERT
#	else
			0x3617
#	endif
		// Peer failed to send valid machine certificate.

	, IPSEC_IKE_PEER_CRL_FAILED =
#	if defined ERROR_IPSEC_IKE_PEER_CRL_FAILED
			ERROR_IPSEC_IKE_PEER_CRL_FAILED
#	else
			0x3618
#	endif
		// Certification Revocation check of peer's certificate failed.

	, IPSEC_IKE_POLICY_CHANGE =
#	if defined ERROR_IPSEC_IKE_POLICY_CHANGE
			ERROR_IPSEC_IKE_POLICY_CHANGE
#	else
			0x3619
#	endif
		// New policy invalidated SAs formed with old policy.

	, IPSEC_IKE_NO_MM_POLICY =
#	if defined ERROR_IPSEC_IKE_NO_MM_POLICY
			ERROR_IPSEC_IKE_NO_MM_POLICY
#	else
			0x361A
#	endif
		// There is no available Main Mode IKE policy.

	, IPSEC_IKE_NOTCBPRIV =
#	if defined ERROR_IPSEC_IKE_NOTCBPRIV
			ERROR_IPSEC_IKE_NOTCBPRIV
#	else
			0x361B
#	endif
		// Failed to enabled TCB privilege.

	, IPSEC_IKE_SECLOADFAIL =
#	if defined ERROR_IPSEC_IKE_SECLOADFAIL
			ERROR_IPSEC_IKE_SECLOADFAIL
#	else
			0x361C
#	endif
		// Failed to load SECURITY.DLL.

	, IPSEC_IKE_FAILSSPINIT =
#	if defined ERROR_IPSEC_IKE_FAILSSPINIT
			ERROR_IPSEC_IKE_FAILSSPINIT
#	else
			0x361D
#	endif
		// Failed to obtain security function table dispatch address from SSPI.

	, IPSEC_IKE_FAILQUERYSSP =
#	if defined ERROR_IPSEC_IKE_FAILQUERYSSP
			ERROR_IPSEC_IKE_FAILQUERYSSP
#	else
			0x361E
#	endif
		// Failed to query Kerberos package to obtain max token size.

	, IPSEC_IKE_SRVACQFAIL =
#	if defined ERROR_IPSEC_IKE_SRVACQFAIL
			ERROR_IPSEC_IKE_SRVACQFAIL
#	else
			0x361F
#	endif
		// Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.

	, IPSEC_IKE_SRVQUERYCRED =
#	if defined ERROR_IPSEC_IKE_SRVQUERYCRED
			ERROR_IPSEC_IKE_SRVQUERYCRED
#	else
			0x3620
#	endif
		// Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).

	, IPSEC_IKE_GETSPIFAIL =
#	if defined ERROR_IPSEC_IKE_GETSPIFAIL
			ERROR_IPSEC_IKE_GETSPIFAIL
#	else
			0x3621
#	endif
		// Failed to obtain new SPI for the inbound SA from IPsec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.

	, IPSEC_IKE_INVALID_FILTER =
#	if defined ERROR_IPSEC_IKE_INVALID_FILTER
			ERROR_IPSEC_IKE_INVALID_FILTER
#	else
			0x3622
#	endif
		// Given filter is invalid.

	, IPSEC_IKE_OUT_OF_MEMORY =
#	if defined ERROR_IPSEC_IKE_OUT_OF_MEMORY
			ERROR_IPSEC_IKE_OUT_OF_MEMORY
#	else
			0x3623
#	endif
		// Memory allocation failed.

	, IPSEC_IKE_ADD_UPDATE_KEY_FAILED =
#	if defined ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED
			ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED
#	else
			0x3624
#	endif
		// Failed to add Security Association to IPsec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.

	, IPSEC_IKE_INVALID_POLICY =
#	if defined ERROR_IPSEC_IKE_INVALID_POLICY
			ERROR_IPSEC_IKE_INVALID_POLICY
#	else
			0x3625
#	endif
		// Invalid policy.

	, IPSEC_IKE_UNKNOWN_DOI =
#	if defined ERROR_IPSEC_IKE_UNKNOWN_DOI
			ERROR_IPSEC_IKE_UNKNOWN_DOI
#	else
			0x3626
#	endif
		// Invalid DOI.

	, IPSEC_IKE_INVALID_SITUATION =
#	if defined ERROR_IPSEC_IKE_INVALID_SITUATION
			ERROR_IPSEC_IKE_INVALID_SITUATION
#	else
			0x3627
#	endif
		// Invalid situation.

	, IPSEC_IKE_DH_FAILURE =
#	if defined ERROR_IPSEC_IKE_DH_FAILURE
			ERROR_IPSEC_IKE_DH_FAILURE
#	else
			0x3628
#	endif
		// Diffie-Hellman failure.

	, IPSEC_IKE_INVALID_GROUP =
#	if defined ERROR_IPSEC_IKE_INVALID_GROUP
			ERROR_IPSEC_IKE_INVALID_GROUP
#	else
			0x3629
#	endif
		// Invalid Diffie-Hellman group.

	, IPSEC_IKE_ENCRYPT =
#	if defined ERROR_IPSEC_IKE_ENCRYPT
			ERROR_IPSEC_IKE_ENCRYPT
#	else
			0x362A
#	endif
		// Error encrypting payload.

	, IPSEC_IKE_DECRYPT =
#	if defined ERROR_IPSEC_IKE_DECRYPT
			ERROR_IPSEC_IKE_DECRYPT
#	else
			0x362B
#	endif
		// Error decrypting payload.

	, IPSEC_IKE_POLICY_MATCH =
#	if defined ERROR_IPSEC_IKE_POLICY_MATCH
			ERROR_IPSEC_IKE_POLICY_MATCH
#	else
			0x362C
#	endif
		// Policy match error.

	, IPSEC_IKE_UNSUPPORTED_ID =
#	if defined ERROR_IPSEC_IKE_UNSUPPORTED_ID
			ERROR_IPSEC_IKE_UNSUPPORTED_ID
#	else
			0x362D
#	endif
		// Unsupported ID.

	, IPSEC_IKE_INVALID_HASH =
#	if defined ERROR_IPSEC_IKE_INVALID_HASH
			ERROR_IPSEC_IKE_INVALID_HASH
#	else
			0x362E
#	endif
		// Hash verification failed.

	, IPSEC_IKE_INVALID_HASH_ALG =
#	if defined ERROR_IPSEC_IKE_INVALID_HASH_ALG
			ERROR_IPSEC_IKE_INVALID_HASH_ALG
#	else
			0x362F
#	endif
		// Invalid hash algorithm.

	, IPSEC_IKE_INVALID_HASH_SIZE =
#	if defined ERROR_IPSEC_IKE_INVALID_HASH_SIZE
			ERROR_IPSEC_IKE_INVALID_HASH_SIZE
#	else
			0x3630
#	endif
		// Invalid hash size.

	, IPSEC_IKE_INVALID_ENCRYPT_ALG =
#	if defined ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG
			ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG
#	else
			0x3631
#	endif
		// Invalid encryption algorithm.

	, IPSEC_IKE_INVALID_AUTH_ALG =
#	if defined ERROR_IPSEC_IKE_INVALID_AUTH_ALG
			ERROR_IPSEC_IKE_INVALID_AUTH_ALG
#	else
			0x3632
#	endif
		// Invalid authentication algorithm.

	, IPSEC_IKE_INVALID_SIG =
#	if defined ERROR_IPSEC_IKE_INVALID_SIG
			ERROR_IPSEC_IKE_INVALID_SIG
#	else
			0x3633
#	endif
		// Invalid certificate signature.

	, IPSEC_IKE_LOAD_FAILED =
#	if defined ERROR_IPSEC_IKE_LOAD_FAILED
			ERROR_IPSEC_IKE_LOAD_FAILED
#	else
			0x3634
#	endif
		// Load failed.

	, IPSEC_IKE_RPC_DELETE =
#	if defined ERROR_IPSEC_IKE_RPC_DELETE
			ERROR_IPSEC_IKE_RPC_DELETE
#	else
			0x3635
#	endif
		// Deleted via RPC call.

	, IPSEC_IKE_BENIGN_REINIT =
#	if defined ERROR_IPSEC_IKE_BENIGN_REINIT
			ERROR_IPSEC_IKE_BENIGN_REINIT
#	else
			0x3636
#	endif
		// Temporary state created to perform reinitialization. This is not a real failure.

	, IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY =
#	if defined ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY
			ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY
#	else
			0x3637
#	endif
		// The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.

	, IPSEC_IKE_INVALID_MAJOR_VERSION =
#	if defined ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION
			ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION
#	else
			0x3638
#	endif
		// The recipient cannot handle version of IKE specified in the header.

	, IPSEC_IKE_INVALID_CERT_KEYLEN =
#	if defined ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN
			ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN
#	else
			0x3639
#	endif
		// Key length in certificate is too small for configured security requirements.

	, IPSEC_IKE_MM_LIMIT =
#	if defined ERROR_IPSEC_IKE_MM_LIMIT
			ERROR_IPSEC_IKE_MM_LIMIT
#	else
			0x363A
#	endif
		// Max number of established MM SAs to peer exceeded.

	, IPSEC_IKE_NEGOTIATION_DISABLED =
#	if defined ERROR_IPSEC_IKE_NEGOTIATION_DISABLED
			ERROR_IPSEC_IKE_NEGOTIATION_DISABLED
#	else
			0x363B
#	endif
		// IKE received a policy that disables negotiation.

	, IPSEC_IKE_QM_LIMIT =
#	if defined ERROR_IPSEC_IKE_QM_LIMIT
			ERROR_IPSEC_IKE_QM_LIMIT
#	else
			0x363C
#	endif
		// Reached maximum quick mode limit for the main mode. New main mode will be started.

	, IPSEC_IKE_MM_EXPIRED =
#	if defined ERROR_IPSEC_IKE_MM_EXPIRED
			ERROR_IPSEC_IKE_MM_EXPIRED
#	else
			0x363D
#	endif
		// Main mode SA lifetime expired or peer sent a main mode delete.

	, IPSEC_IKE_PEER_MM_ASSUMED_INVALID =
#	if defined ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID
			ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID
#	else
			0x363E
#	endif
		// Main mode SA assumed to be invalid because peer stopped responding.

	, IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH =
#	if defined ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH
			ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH
#	else
			0x363F
#	endif
		// Certificate doesn't chain to a trusted root in IPsec policy.

	, IPSEC_IKE_UNEXPECTED_MESSAGE_ID =
#	if defined ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID
			ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID
#	else
			0x3640
#	endif
		// Received unexpected message ID.

	, IPSEC_IKE_INVALID_AUTH_PAYLOAD =
#	if defined ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD
			ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD
#	else
			0x3641
#	endif
		// Received invalid authentication offers.

	, IPSEC_IKE_DOS_COOKIE_SENT =
#	if defined ERROR_IPSEC_IKE_DOS_COOKIE_SENT
			ERROR_IPSEC_IKE_DOS_COOKIE_SENT
#	else
			0x3642
#	endif
		// Sent DoS cookie notify to initiator.

	, IPSEC_IKE_SHUTTING_DOWN =
#	if defined ERROR_IPSEC_IKE_SHUTTING_DOWN
			ERROR_IPSEC_IKE_SHUTTING_DOWN
#	else
			0x3643
#	endif
		// IKE service is shutting down.

	, IPSEC_IKE_CGA_AUTH_FAILED =
#	if defined ERROR_IPSEC_IKE_CGA_AUTH_FAILED
			ERROR_IPSEC_IKE_CGA_AUTH_FAILED
#	else
			0x3644
#	endif
		// Could not verify binding between CGA address and certificate.

	, IPSEC_IKE_PROCESS_ERR_NATOA =
#	if defined ERROR_IPSEC_IKE_PROCESS_ERR_NATOA
			ERROR_IPSEC_IKE_PROCESS_ERR_NATOA
#	else
			0x3645
#	endif
		// Error processing NatOA payload.

	, IPSEC_IKE_INVALID_MM_FOR_QM =
#	if defined ERROR_IPSEC_IKE_INVALID_MM_FOR_QM
			ERROR_IPSEC_IKE_INVALID_MM_FOR_QM
#	else
			0x3646
#	endif
		// Parameters of the main mode are invalid for this quick mode.

	, IPSEC_IKE_QM_EXPIRED =
#	if defined ERROR_IPSEC_IKE_QM_EXPIRED
			ERROR_IPSEC_IKE_QM_EXPIRED
#	else
			0x3647
#	endif
		// Quick mode SA was expired by IPsec driver.

	, IPSEC_IKE_TOO_MANY_FILTERS =
#	if defined ERROR_IPSEC_IKE_TOO_MANY_FILTERS
			ERROR_IPSEC_IKE_TOO_MANY_FILTERS
#	else
			0x3648
#	endif
		// Too many dynamically added IKEEXT filters were detected.

	, IPSEC_IKE_NEG_STATUS_END =
#	if defined ERROR_IPSEC_IKE_NEG_STATUS_END
			ERROR_IPSEC_IKE_NEG_STATUS_END
#	else
			0x3649
#	endif
		// ERROR_IPSEC_IKE_NEG_STATUS_END

	, IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL =
#	if defined ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL
			ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL
#	else
			0x364A
#	endif
		// NAP reauth succeeded and must delete the dummy NAP IKEv2 tunnel.

	, IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE =
#	if defined ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE
			ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE
#	else
			0x364B
#	endif
		// Error in assigning inner IP address to initiator in tunnel mode.

	, IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING =
#	if defined ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING
			ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING
#	else
			0x364C
#	endif
		// Require configuration payload missing.

	, IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING =
#	if defined ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING
			ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING
#	else
			0x364D
#	endif
		// A negotiation running as the security principle who issued the connection is in progress.

	, IPSEC_IKE_COEXISTENCE_SUPPRESS =
#	if defined ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS
			ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS
#	else
			0x364E
#	endif
		// SA was deleted due to IKEv1/AuthIP co-existence suppress check.

	, IPSEC_IKE_RATELIMIT_DROP =
#	if defined ERROR_IPSEC_IKE_RATELIMIT_DROP
			ERROR_IPSEC_IKE_RATELIMIT_DROP
#	else
			0x364F
#	endif
		// Incoming SA request was dropped due to peer IP address rate limiting.

	, IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE =
#	if defined ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE
			ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE
#	else
			0x3650
#	endif
		// Peer does not support MOBIKE.

	, IPSEC_IKE_AUTHORIZATION_FAILURE =
#	if defined ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE
			ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE
#	else
			0x3651
#	endif
		// SA establishment is not authorized.

	, IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE =
#	if defined ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE
			ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE
#	else
			0x3652
#	endif
		// SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential.

	, IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY =
#	if defined ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY
			ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY
#	else
			0x3653
#	endif
		// SA establishment is not authorized. You may need to enter updated or different credentials such as a smartcard.

	, IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE =
#	if defined ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE
			ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE
#	else
			0x3654
#	endif
		// SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential. This might be related to certificate-to-account mapping failure for the SA.

	, IPSEC_IKE_NEG_STATUS_EXTENDED_END =
#	if defined ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END
			ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END
#	else
			0x3655
#	endif
		// ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END

	, IPSEC_BAD_SPI =
#	if defined ERROR_IPSEC_BAD_SPI
			ERROR_IPSEC_BAD_SPI
#	else
			0x3656
#	endif
		// The SPI in the packet does not match a valid IPsec SA.

	, IPSEC_SA_LIFETIME_EXPIRED =
#	if defined ERROR_IPSEC_SA_LIFETIME_EXPIRED
			ERROR_IPSEC_SA_LIFETIME_EXPIRED
#	else
			0x3657
#	endif
		// Packet was received on an IPsec SA whose lifetime has expired.

	, IPSEC_WRONG_SA =
#	if defined ERROR_IPSEC_WRONG_SA
			ERROR_IPSEC_WRONG_SA
#	else
			0x3658
#	endif
		// Packet was received on an IPsec SA that does not match the packet characteristics.

	, IPSEC_REPLAY_CHECK_FAILED =
#	if defined ERROR_IPSEC_REPLAY_CHECK_FAILED
			ERROR_IPSEC_REPLAY_CHECK_FAILED
#	else
			0x3659
#	endif
		// Packet sequence number replay check failed.

	, IPSEC_INVALID_PACKET =
#	if defined ERROR_IPSEC_INVALID_PACKET
			ERROR_IPSEC_INVALID_PACKET
#	else
			0x365A
#	endif
		// IPsec header and/or trailer in the packet is invalid.

	, IPSEC_INTEGRITY_CHECK_FAILED =
#	if defined ERROR_IPSEC_INTEGRITY_CHECK_FAILED
			ERROR_IPSEC_INTEGRITY_CHECK_FAILED
#	else
			0x365B
#	endif
		// IPsec integrity check failed.

	, IPSEC_CLEAR_TEXT_DROP =
#	if defined ERROR_IPSEC_CLEAR_TEXT_DROP
			ERROR_IPSEC_CLEAR_TEXT_DROP
#	else
			0x365C
#	endif
		// IPsec dropped a clear text packet.

	, IPSEC_AUTH_FIREWALL_DROP =
#	if defined ERROR_IPSEC_AUTH_FIREWALL_DROP
			ERROR_IPSEC_AUTH_FIREWALL_DROP
#	else
			0x365D
#	endif
		// IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop is benign.

	, IPSEC_THROTTLE_DROP =
#	if defined ERROR_IPSEC_THROTTLE_DROP
			ERROR_IPSEC_THROTTLE_DROP
#	else
			0x365E
#	endif
		// IPsec dropped a packet due to DoS throttling.

	, IPSEC_DOSP_BLOCK =
#	if defined ERROR_IPSEC_DOSP_BLOCK
			ERROR_IPSEC_DOSP_BLOCK
#	else
			0x3665
#	endif
		// IPsec DoS Protection matched an explicit block rule.

	, IPSEC_DOSP_RECEIVED_MULTICAST =
#	if defined ERROR_IPSEC_DOSP_RECEIVED_MULTICAST
			ERROR_IPSEC_DOSP_RECEIVED_MULTICAST
#	else
			0x3666
#	endif
		// IPsec DoS Protection received an IPsec specific multicast packet which is not allowed.

	, IPSEC_DOSP_INVALID_PACKET =
#	if defined ERROR_IPSEC_DOSP_INVALID_PACKET
			ERROR_IPSEC_DOSP_INVALID_PACKET
#	else
			0x3667
#	endif
		// IPsec DoS Protection received an incorrectly formatted packet.

	, IPSEC_DOSP_STATE_LOOKUP_FAILED =
#	if defined ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED
			ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED
#	else
			0x3668
#	endif
		// IPsec DoS Protection failed to look up state.

	, IPSEC_DOSP_MAX_ENTRIES =
#	if defined ERROR_IPSEC_DOSP_MAX_ENTRIES
			ERROR_IPSEC_DOSP_MAX_ENTRIES
#	else
			0x3669
#	endif
		// IPsec DoS Protection failed to create state because the maximum number of entries allowed by policy has been reached.

	, IPSEC_DOSP_KEYMOD_NOT_ALLOWED =
#	if defined ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED
			ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED
#	else
			0x366A
#	endif
		// IPsec DoS Protection received an IPsec negotiation packet for a keying module which is not allowed by policy.

	, IPSEC_DOSP_NOT_INSTALLED =
#	if defined ERROR_IPSEC_DOSP_NOT_INSTALLED
			ERROR_IPSEC_DOSP_NOT_INSTALLED
#	else
			0x366B
#	endif
		// IPsec DoS Protection has not been enabled.

	, IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES =
#	if defined ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES
			ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES
#	else
			0x366C
#	endif
		// IPsec DoS Protection failed to create a per internal IP rate limit queue because the maximum number of queues allowed by policy has been reached.

	, SXS_SECTION_NOT_FOUND =
#	if defined ERROR_SXS_SECTION_NOT_FOUND
			ERROR_SXS_SECTION_NOT_FOUND
#	else
			0x36B0
#	endif
		// The requested section was not present in the activation context.

	, SXS_CANT_GEN_ACTCTX =
#	if defined ERROR_SXS_CANT_GEN_ACTCTX
			ERROR_SXS_CANT_GEN_ACTCTX
#	else
			0x36B1
#	endif
		// The application has failed to start because its side-by-side configuration is incorrect. Please see the application event log or use the command-line sxstrace.exe tool for more detail.

	, SXS_INVALID_ACTCTXDATA_FORMAT =
#	if defined ERROR_SXS_INVALID_ACTCTXDATA_FORMAT
			ERROR_SXS_INVALID_ACTCTXDATA_FORMAT
#	else
			0x36B2
#	endif
		// The application binding data format is invalid.

	, SXS_ASSEMBLY_NOT_FOUND =
#	if defined ERROR_SXS_ASSEMBLY_NOT_FOUND
			ERROR_SXS_ASSEMBLY_NOT_FOUND
#	else
			0x36B3
#	endif
		// The referenced assembly is not installed on your system.

	, SXS_MANIFEST_FORMAT_ERROR =
#	if defined ERROR_SXS_MANIFEST_FORMAT_ERROR
			ERROR_SXS_MANIFEST_FORMAT_ERROR
#	else
			0x36B4
#	endif
		// The manifest file does not begin with the required tag and format information.

	, SXS_MANIFEST_PARSE_ERROR =
#	if defined ERROR_SXS_MANIFEST_PARSE_ERROR
			ERROR_SXS_MANIFEST_PARSE_ERROR
#	else
			0x36B5
#	endif
		// The manifest file contains one or more syntax errors.

	, SXS_ACTIVATION_CONTEXT_DISABLED =
#	if defined ERROR_SXS_ACTIVATION_CONTEXT_DISABLED
			ERROR_SXS_ACTIVATION_CONTEXT_DISABLED
#	else
			0x36B6
#	endif
		// The application attempted to activate a disabled activation context.

	, SXS_KEY_NOT_FOUND =
#	if defined ERROR_SXS_KEY_NOT_FOUND
			ERROR_SXS_KEY_NOT_FOUND
#	else
			0x36B7
#	endif
		// The requested lookup key was not found in any active activation context.

	, SXS_VERSION_CONFLICT =
#	if defined ERROR_SXS_VERSION_CONFLICT
			ERROR_SXS_VERSION_CONFLICT
#	else
			0x36B8
#	endif
		// A component version required by the application conflicts with another component version already active.

	, SXS_WRONG_SECTION_TYPE =
#	if defined ERROR_SXS_WRONG_SECTION_TYPE
			ERROR_SXS_WRONG_SECTION_TYPE
#	else
			0x36B9
#	endif
		// The type requested activation context section does not match the query API used.

	, SXS_THREAD_QUERIES_DISABLED =
#	if defined ERROR_SXS_THREAD_QUERIES_DISABLED
			ERROR_SXS_THREAD_QUERIES_DISABLED
#	else
			0x36BA
#	endif
		// Lack of system resources has required isolated activation to be disabled for the current thread of execution.

	, SXS_PROCESS_DEFAULT_ALREADY_SET =
#	if defined ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET
			ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET
#	else
			0x36BB
#	endif
		// An attempt to set the process default activation context failed because the process default activation context was already set.

	, SXS_UNKNOWN_ENCODING_GROUP =
#	if defined ERROR_SXS_UNKNOWN_ENCODING_GROUP
			ERROR_SXS_UNKNOWN_ENCODING_GROUP
#	else
			0x36BC
#	endif
		// The encoding group identifier specified is not recognized.

	, SXS_UNKNOWN_ENCODING =
#	if defined ERROR_SXS_UNKNOWN_ENCODING
			ERROR_SXS_UNKNOWN_ENCODING
#	else
			0x36BD
#	endif
		// The encoding requested is not recognized.

	, SXS_INVALID_XML_NAMESPACE_URI =
#	if defined ERROR_SXS_INVALID_XML_NAMESPACE_URI
			ERROR_SXS_INVALID_XML_NAMESPACE_URI
#	else
			0x36BE
#	endif
		// The manifest contains a reference to an invalid URI.

	, SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED =
#	if defined ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED
			ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED
#	else
			0x36BF
#	endif
		// The application manifest contains a reference to a dependent assembly which is not installed.

	, SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED =
#	if defined ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED
			ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED
#	else
			0x36C0
#	endif
		// The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed.

	, SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE =
#	if defined ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE
			ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE
#	else
			0x36C1
#	endif
		// The manifest contains an attribute for the assembly identity which is not valid.

	, SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE =
#	if defined ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE
			ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE
#	else
			0x36C2
#	endif
		// The manifest is missing the required default namespace specification on the assembly element.

	, SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE =
#	if defined ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE
			ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE
#	else
			0x36C3
#	endif
		// The manifest has a default namespace specified on the assembly element but its value is not "urn:schemas-microsoft-com:asm.v1".

	, SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT =
#	if defined ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT
			ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT
#	else
			0x36C4
#	endif
		// The private manifest probed has crossed a path with an unsupported reparse point.

	, SXS_DUPLICATE_DLL_NAME =
#	if defined ERROR_SXS_DUPLICATE_DLL_NAME
			ERROR_SXS_DUPLICATE_DLL_NAME
#	else
			0x36C5
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have files by the same name.

	, SXS_DUPLICATE_WINDOWCLASS_NAME =
#	if defined ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME
			ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME
#	else
			0x36C6
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.

	, SXS_DUPLICATE_CLSID =
#	if defined ERROR_SXS_DUPLICATE_CLSID
			ERROR_SXS_DUPLICATE_CLSID
#	else
			0x36C7
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.

	, SXS_DUPLICATE_IID =
#	if defined ERROR_SXS_DUPLICATE_IID
			ERROR_SXS_DUPLICATE_IID
#	else
			0x36C8
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.

	, SXS_DUPLICATE_TLBID =
#	if defined ERROR_SXS_DUPLICATE_TLBID
			ERROR_SXS_DUPLICATE_TLBID
#	else
			0x36C9
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.

	, SXS_DUPLICATE_PROGID =
#	if defined ERROR_SXS_DUPLICATE_PROGID
			ERROR_SXS_DUPLICATE_PROGID
#	else
			0x36CA
#	endif
		// Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.

	, SXS_DUPLICATE_ASSEMBLY_NAME =
#	if defined ERROR_SXS_DUPLICATE_ASSEMBLY_NAME
			ERROR_SXS_DUPLICATE_ASSEMBLY_NAME
#	else
			0x36CB
#	endif
		// Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.

	, SXS_FILE_HASH_MISMATCH =
#	if defined ERROR_SXS_FILE_HASH_MISMATCH
			ERROR_SXS_FILE_HASH_MISMATCH
#	else
			0x36CC
#	endif
		// A component's file does not match the verification information present in the component manifest.

	, SXS_POLICY_PARSE_ERROR =
#	if defined ERROR_SXS_POLICY_PARSE_ERROR
			ERROR_SXS_POLICY_PARSE_ERROR
#	else
			0x36CD
#	endif
		// The policy manifest contains one or more syntax errors.

	, SXS_XML_E_MISSINGQUOTE =
#	if defined ERROR_SXS_XML_E_MISSINGQUOTE
			ERROR_SXS_XML_E_MISSINGQUOTE
#	else
			0x36CE
#	endif
		// Manifest Parse Error : A string literal was expected, but no opening quote character was found.

	, SXS_XML_E_COMMENTSYNTAX =
#	if defined ERROR_SXS_XML_E_COMMENTSYNTAX
			ERROR_SXS_XML_E_COMMENTSYNTAX
#	else
			0x36CF
#	endif
		// Manifest Parse Error : Incorrect syntax was used in a comment.

	, SXS_XML_E_BADSTARTNAMECHAR =
#	if defined ERROR_SXS_XML_E_BADSTARTNAMECHAR
			ERROR_SXS_XML_E_BADSTARTNAMECHAR
#	else
			0x36D0
#	endif
		// Manifest Parse Error : A name was started with an invalid character.

	, SXS_XML_E_BADNAMECHAR =
#	if defined ERROR_SXS_XML_E_BADNAMECHAR
			ERROR_SXS_XML_E_BADNAMECHAR
#	else
			0x36D1
#	endif
		// Manifest Parse Error : A name contained an invalid character.

	, SXS_XML_E_BADCHARINSTRING =
#	if defined ERROR_SXS_XML_E_BADCHARINSTRING
			ERROR_SXS_XML_E_BADCHARINSTRING
#	else
			0x36D2
#	endif
		// Manifest Parse Error : A string literal contained an invalid character.

	, SXS_XML_E_XMLDECLSYNTAX =
#	if defined ERROR_SXS_XML_E_XMLDECLSYNTAX
			ERROR_SXS_XML_E_XMLDECLSYNTAX
#	else
			0x36D3
#	endif
		// Manifest Parse Error : Invalid syntax for an xml declaration.

	, SXS_XML_E_BADCHARDATA =
#	if defined ERROR_SXS_XML_E_BADCHARDATA
			ERROR_SXS_XML_E_BADCHARDATA
#	else
			0x36D4
#	endif
		// Manifest Parse Error : An Invalid character was found in text content.

	, SXS_XML_E_MISSINGWHITESPACE =
#	if defined ERROR_SXS_XML_E_MISSINGWHITESPACE
			ERROR_SXS_XML_E_MISSINGWHITESPACE
#	else
			0x36D5
#	endif
		// Manifest Parse Error : Required white space was missing.

	, SXS_XML_E_EXPECTINGTAGEND =
#	if defined ERROR_SXS_XML_E_EXPECTINGTAGEND
			ERROR_SXS_XML_E_EXPECTINGTAGEND
#	else
			0x36D6
#	endif
		// Manifest Parse Error : The character '>' was expected.

	, SXS_XML_E_MISSINGSEMICOLON =
#	if defined ERROR_SXS_XML_E_MISSINGSEMICOLON
			ERROR_SXS_XML_E_MISSINGSEMICOLON
#	else
			0x36D7
#	endif
		// Manifest Parse Error : A semi colon character was expected.

	, SXS_XML_E_UNBALANCEDPAREN =
#	if defined ERROR_SXS_XML_E_UNBALANCEDPAREN
			ERROR_SXS_XML_E_UNBALANCEDPAREN
#	else
			0x36D8
#	endif
		// Manifest Parse Error : Unbalanced parentheses.

	, SXS_XML_E_INTERNALERROR =
#	if defined ERROR_SXS_XML_E_INTERNALERROR
			ERROR_SXS_XML_E_INTERNALERROR
#	else
			0x36D9
#	endif
		// Manifest Parse Error : Internal error.

	, SXS_XML_E_UNEXPECTED_WHITESPACE =
#	if defined ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE
			ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE
#	else
			0x36DA
#	endif
		// Manifest Parse Error : Whitespace is not allowed at this location.

	, SXS_XML_E_INCOMPLETE_ENCODING =
#	if defined ERROR_SXS_XML_E_INCOMPLETE_ENCODING
			ERROR_SXS_XML_E_INCOMPLETE_ENCODING
#	else
			0x36DB
#	endif
		// Manifest Parse Error : End of file reached in invalid state for current encoding.

	, SXS_XML_E_MISSING_PAREN =
#	if defined ERROR_SXS_XML_E_MISSING_PAREN
			ERROR_SXS_XML_E_MISSING_PAREN
#	else
			0x36DC
#	endif
		// Manifest Parse Error : Missing parenthesis.

	, SXS_XML_E_EXPECTINGCLOSEQUOTE =
#	if defined ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE
			ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE
#	else
			0x36DD
#	endif
		// Manifest Parse Error : A single or double closing quote character (\' or \") is missing.

	, SXS_XML_E_MULTIPLE_COLONS =
#	if defined ERROR_SXS_XML_E_MULTIPLE_COLONS
			ERROR_SXS_XML_E_MULTIPLE_COLONS
#	else
			0x36DE
#	endif
		// Manifest Parse Error : Multiple colons are not allowed in a name.

	, SXS_XML_E_INVALID_DECIMAL =
#	if defined ERROR_SXS_XML_E_INVALID_DECIMAL
			ERROR_SXS_XML_E_INVALID_DECIMAL
#	else
			0x36DF
#	endif
		// Manifest Parse Error : Invalid character for decimal digit.

	, SXS_XML_E_INVALID_HEXIDECIMAL =
#	if defined ERROR_SXS_XML_E_INVALID_HEXIDECIMAL
			ERROR_SXS_XML_E_INVALID_HEXIDECIMAL
#	else
			0x36E0
#	endif
		// Manifest Parse Error : Invalid character for hexadecimal digit.

	, SXS_XML_E_INVALID_UNICODE =
#	if defined ERROR_SXS_XML_E_INVALID_UNICODE
			ERROR_SXS_XML_E_INVALID_UNICODE
#	else
			0x36E1
#	endif
		// Manifest Parse Error : Invalid unicode character value for this platform.

	, SXS_XML_E_WHITESPACEORQUESTIONMARK =
#	if defined ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK
			ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK
#	else
			0x36E2
#	endif
		// Manifest Parse Error : Expecting whitespace or '?'.

	, SXS_XML_E_UNEXPECTEDENDTAG =
#	if defined ERROR_SXS_XML_E_UNEXPECTEDENDTAG
			ERROR_SXS_XML_E_UNEXPECTEDENDTAG
#	else
			0x36E3
#	endif
		// Manifest Parse Error : End tag was not expected at this location.

	, SXS_XML_E_UNCLOSEDTAG =
#	if defined ERROR_SXS_XML_E_UNCLOSEDTAG
			ERROR_SXS_XML_E_UNCLOSEDTAG
#	else
			0x36E4
#	endif
		// Manifest Parse Error : The following tags were not closed: %1.

	, SXS_XML_E_DUPLICATEATTRIBUTE =
#	if defined ERROR_SXS_XML_E_DUPLICATEATTRIBUTE
			ERROR_SXS_XML_E_DUPLICATEATTRIBUTE
#	else
			0x36E5
#	endif
		// Manifest Parse Error : Duplicate attribute.

	, SXS_XML_E_MULTIPLEROOTS =
#	if defined ERROR_SXS_XML_E_MULTIPLEROOTS
			ERROR_SXS_XML_E_MULTIPLEROOTS
#	else
			0x36E6
#	endif
		// Manifest Parse Error : Only one top level element is allowed in an XML document.

	, SXS_XML_E_INVALIDATROOTLEVEL =
#	if defined ERROR_SXS_XML_E_INVALIDATROOTLEVEL
			ERROR_SXS_XML_E_INVALIDATROOTLEVEL
#	else
			0x36E7
#	endif
		// Manifest Parse Error : Invalid at the top level of the document.

	, SXS_XML_E_BADXMLDECL =
#	if defined ERROR_SXS_XML_E_BADXMLDECL
			ERROR_SXS_XML_E_BADXMLDECL
#	else
			0x36E8
#	endif
		// Manifest Parse Error : Invalid xml declaration.

	, SXS_XML_E_MISSINGROOT =
#	if defined ERROR_SXS_XML_E_MISSINGROOT
			ERROR_SXS_XML_E_MISSINGROOT
#	else
			0x36E9
#	endif
		// Manifest Parse Error : XML document must have a top level element.

	, SXS_XML_E_UNEXPECTEDEOF =
#	if defined ERROR_SXS_XML_E_UNEXPECTEDEOF
			ERROR_SXS_XML_E_UNEXPECTEDEOF
#	else
			0x36EA
#	endif
		// Manifest Parse Error : Unexpected end of file.

	, SXS_XML_E_BADPEREFINSUBSET =
#	if defined ERROR_SXS_XML_E_BADPEREFINSUBSET
			ERROR_SXS_XML_E_BADPEREFINSUBSET
#	else
			0x36EB
#	endif
		// Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.

	, SXS_XML_E_UNCLOSEDSTARTTAG =
#	if defined ERROR_SXS_XML_E_UNCLOSEDSTARTTAG
			ERROR_SXS_XML_E_UNCLOSEDSTARTTAG
#	else
			0x36EC
#	endif
		// Manifest Parse Error : Element was not closed.

	, SXS_XML_E_UNCLOSEDENDTAG =
#	if defined ERROR_SXS_XML_E_UNCLOSEDENDTAG
			ERROR_SXS_XML_E_UNCLOSEDENDTAG
#	else
			0x36ED
#	endif
		// Manifest Parse Error : End element was missing the character '>'.

	, SXS_XML_E_UNCLOSEDSTRING =
#	if defined ERROR_SXS_XML_E_UNCLOSEDSTRING
			ERROR_SXS_XML_E_UNCLOSEDSTRING
#	else
			0x36EE
#	endif
		// Manifest Parse Error : A string literal was not closed.

	, SXS_XML_E_UNCLOSEDCOMMENT =
#	if defined ERROR_SXS_XML_E_UNCLOSEDCOMMENT
			ERROR_SXS_XML_E_UNCLOSEDCOMMENT
#	else
			0x36EF
#	endif
		// Manifest Parse Error : A comment was not closed.

	, SXS_XML_E_UNCLOSEDDECL =
#	if defined ERROR_SXS_XML_E_UNCLOSEDDECL
			ERROR_SXS_XML_E_UNCLOSEDDECL
#	else
			0x36F0
#	endif
		// Manifest Parse Error : A declaration was not closed.

	, SXS_XML_E_UNCLOSEDCDATA =
#	if defined ERROR_SXS_XML_E_UNCLOSEDCDATA
			ERROR_SXS_XML_E_UNCLOSEDCDATA
#	else
			0x36F1
#	endif
		// Manifest Parse Error : A CDATA section was not closed.

	, SXS_XML_E_RESERVEDNAMESPACE =
#	if defined ERROR_SXS_XML_E_RESERVEDNAMESPACE
			ERROR_SXS_XML_E_RESERVEDNAMESPACE
#	else
			0x36F2
#	endif
		// Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string "xml".

	, SXS_XML_E_INVALIDENCODING =
#	if defined ERROR_SXS_XML_E_INVALIDENCODING
			ERROR_SXS_XML_E_INVALIDENCODING
#	else
			0x36F3
#	endif
		// Manifest Parse Error : System does not support the specified encoding.

	, SXS_XML_E_INVALIDSWITCH =
#	if defined ERROR_SXS_XML_E_INVALIDSWITCH
			ERROR_SXS_XML_E_INVALIDSWITCH
#	else
			0x36F4
#	endif
		// Manifest Parse Error : Switch from current encoding to specified encoding not supported.

	, SXS_XML_E_BADXMLCASE =
#	if defined ERROR_SXS_XML_E_BADXMLCASE
			ERROR_SXS_XML_E_BADXMLCASE
#	else
			0x36F5
#	endif
		// Manifest Parse Error : The name 'xml' is reserved and must be lower case.

	, SXS_XML_E_INVALID_STANDALONE =
#	if defined ERROR_SXS_XML_E_INVALID_STANDALONE
			ERROR_SXS_XML_E_INVALID_STANDALONE
#	else
			0x36F6
#	endif
		// Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.

	, SXS_XML_E_UNEXPECTED_STANDALONE =
#	if defined ERROR_SXS_XML_E_UNEXPECTED_STANDALONE
			ERROR_SXS_XML_E_UNEXPECTED_STANDALONE
#	else
			0x36F7
#	endif
		// Manifest Parse Error : The standalone attribute cannot be used in external entities.

	, SXS_XML_E_INVALID_VERSION =
#	if defined ERROR_SXS_XML_E_INVALID_VERSION
			ERROR_SXS_XML_E_INVALID_VERSION
#	else
			0x36F8
#	endif
		// Manifest Parse Error : Invalid version number.

	, SXS_XML_E_MISSINGEQUALS =
#	if defined ERROR_SXS_XML_E_MISSINGEQUALS
			ERROR_SXS_XML_E_MISSINGEQUALS
#	else
			0x36F9
#	endif
		// Manifest Parse Error : Missing equals sign between attribute and attribute value.

	, SXS_PROTECTION_RECOVERY_FAILED =
#	if defined ERROR_SXS_PROTECTION_RECOVERY_FAILED
			ERROR_SXS_PROTECTION_RECOVERY_FAILED
#	else
			0x36FA
#	endif
		// Assembly Protection Error : Unable to recover the specified assembly.

	, SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT =
#	if defined ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT
			ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT
#	else
			0x36FB
#	endif
		// Assembly Protection Error : The public key for an assembly was too short to be allowed.

	, SXS_PROTECTION_CATALOG_NOT_VALID =
#	if defined ERROR_SXS_PROTECTION_CATALOG_NOT_VALID
			ERROR_SXS_PROTECTION_CATALOG_NOT_VALID
#	else
			0x36FC
#	endif
		// Assembly Protection Error : The catalog for an assembly is not valid, or does not match the assembly's manifest.

	, SXS_UNTRANSLATABLE_HRESULT =
#	if defined ERROR_SXS_UNTRANSLATABLE_HRESULT
			ERROR_SXS_UNTRANSLATABLE_HRESULT
#	else
			0x36FD
#	endif
		// An HRESULT could not be translated to a corresponding Win32 error code.

	, SXS_PROTECTION_CATALOG_FILE_MISSING =
#	if defined ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING
			ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING
#	else
			0x36FE
#	endif
		// Assembly Protection Error : The catalog for an assembly is missing.

	, SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE =
#	if defined ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE
			ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE
#	else
			0x36FF
#	endif
		// The supplied assembly identity is missing one or more attributes which must be present in this context.

	, SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME =
#	if defined ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME
			ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME
#	else
			0x3700
#	endif
		// The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.

	, SXS_ASSEMBLY_MISSING =
#	if defined ERROR_SXS_ASSEMBLY_MISSING
			ERROR_SXS_ASSEMBLY_MISSING
#	else
			0x3701
#	endif
		// The referenced assembly could not be found.

	, SXS_CORRUPT_ACTIVATION_STACK =
#	if defined ERROR_SXS_CORRUPT_ACTIVATION_STACK
			ERROR_SXS_CORRUPT_ACTIVATION_STACK
#	else
			0x3702
#	endif
		// The activation context activation stack for the running thread of execution is corrupt.

	, SXS_CORRUPTION =
#	if defined ERROR_SXS_CORRUPTION
			ERROR_SXS_CORRUPTION
#	else
			0x3703
#	endif
		// The application isolation metadata for this process or thread has become corrupt.

	, SXS_EARLY_DEACTIVATION =
#	if defined ERROR_SXS_EARLY_DEACTIVATION
			ERROR_SXS_EARLY_DEACTIVATION
#	else
			0x3704
#	endif
		// The activation context being deactivated is not the most recently activated one.

	, SXS_INVALID_DEACTIVATION =
#	if defined ERROR_SXS_INVALID_DEACTIVATION
			ERROR_SXS_INVALID_DEACTIVATION
#	else
			0x3705
#	endif
		// The activation context being deactivated is not active for the current thread of execution.

	, SXS_MULTIPLE_DEACTIVATION =
#	if defined ERROR_SXS_MULTIPLE_DEACTIVATION
			ERROR_SXS_MULTIPLE_DEACTIVATION
#	else
			0x3706
#	endif
		// The activation context being deactivated has already been deactivated.

	, SXS_PROCESS_TERMINATION_REQUESTED =
#	if defined ERROR_SXS_PROCESS_TERMINATION_REQUESTED
			ERROR_SXS_PROCESS_TERMINATION_REQUESTED
#	else
			0x3707
#	endif
		// A component used by the isolation facility has requested to terminate the process.

	, SXS_RELEASE_ACTIVATION_CONTEXT =
#	if defined ERROR_SXS_RELEASE_ACTIVATION_CONTEXT
			ERROR_SXS_RELEASE_ACTIVATION_CONTEXT
#	else
			0x3708
#	endif
		// A kernel mode component is releasing a reference on an activation context.

	, SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY =
#	if defined ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY
			ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY
#	else
			0x3709
#	endif
		// The activation context of system default assembly could not be generated.

	, SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE =
#	if defined ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE
			ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE
#	else
			0x370A
#	endif
		// The value of an attribute in an identity is not within the legal range.

	, SXS_INVALID_IDENTITY_ATTRIBUTE_NAME =
#	if defined ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME
			ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME
#	else
			0x370B
#	endif
		// The name of an attribute in an identity is not within the legal range.

	, SXS_IDENTITY_DUPLICATE_ATTRIBUTE =
#	if defined ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE
			ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE
#	else
			0x370C
#	endif
		// An identity contains two definitions for the same attribute.

	, SXS_IDENTITY_PARSE_ERROR =
#	if defined ERROR_SXS_IDENTITY_PARSE_ERROR
			ERROR_SXS_IDENTITY_PARSE_ERROR
#	else
			0x370D
#	endif
		// The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.

	, MALFORMED_SUBSTITUTION_STRING =
#	if defined ERROR_MALFORMED_SUBSTITUTION_STRING
			ERROR_MALFORMED_SUBSTITUTION_STRING
#	else
			0x370E
#	endif
		// A string containing localized substitutable content was malformed. Either a dollar sign ($) was followed by something other than a left parenthesis or another dollar sign or an substitution's right parenthesis was not found.

	, SXS_INCORRECT_PUBLIC_KEY_TOKEN =
#	if defined ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN
			ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN
#	else
			0x370F
#	endif
		// The public key token does not correspond to the public key specified.

	, UNMAPPED_SUBSTITUTION_STRING =
#	if defined ERROR_UNMAPPED_SUBSTITUTION_STRING
			ERROR_UNMAPPED_SUBSTITUTION_STRING
#	else
			0x3710
#	endif
		// A substitution string had no mapping.

	, SXS_ASSEMBLY_NOT_LOCKED =
#	if defined ERROR_SXS_ASSEMBLY_NOT_LOCKED
			ERROR_SXS_ASSEMBLY_NOT_LOCKED
#	else
			0x3711
#	endif
		// The component must be locked before making the request.

	, SXS_COMPONENT_STORE_CORRUPT =
#	if defined ERROR_SXS_COMPONENT_STORE_CORRUPT
			ERROR_SXS_COMPONENT_STORE_CORRUPT
#	else
			0x3712
#	endif
		// The component store has been corrupted.

	, ADVANCED_INSTALLER_FAILED =
#	if defined ERROR_ADVANCED_INSTALLER_FAILED
			ERROR_ADVANCED_INSTALLER_FAILED
#	else
			0x3713
#	endif
		// An advanced installer failed during setup or servicing.

	, XML_ENCODING_MISMATCH =
#	if defined ERROR_XML_ENCODING_MISMATCH
			ERROR_XML_ENCODING_MISMATCH
#	else
			0x3714
#	endif
		// The character encoding in the XML declaration did not match the encoding used in the document.

	, SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT =
#	if defined ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT
			ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT
#	else
			0x3715
#	endif
		// The identities of the manifests are identical but their contents are different.

	, SXS_IDENTITIES_DIFFERENT =
#	if defined ERROR_SXS_IDENTITIES_DIFFERENT
			ERROR_SXS_IDENTITIES_DIFFERENT
#	else
			0x3716
#	endif
		// The component identities are different.

	, SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT =
#	if defined ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT
			ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT
#	else
			0x3717
#	endif
		// The assembly is not a deployment.

	, SXS_FILE_NOT_PART_OF_ASSEMBLY =
#	if defined ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY
			ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY
#	else
			0x3718
#	endif
		// The file is not a part of the assembly.

	, SXS_MANIFEST_TOO_BIG =
#	if defined ERROR_SXS_MANIFEST_TOO_BIG
			ERROR_SXS_MANIFEST_TOO_BIG
#	else
			0x3719
#	endif
		// The size of the manifest exceeds the maximum allowed.

	, SXS_SETTING_NOT_REGISTERED =
#	if defined ERROR_SXS_SETTING_NOT_REGISTERED
			ERROR_SXS_SETTING_NOT_REGISTERED
#	else
			0x371A
#	endif
		// The setting is not registered.

	, SXS_TRANSACTION_CLOSURE_INCOMPLETE =
#	if defined ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE
			ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE
#	else
			0x371B
#	endif
		// One or more required members of the transaction are not present.

	, SMI_PRIMITIVE_INSTALLER_FAILED =
#	if defined ERROR_SMI_PRIMITIVE_INSTALLER_FAILED
			ERROR_SMI_PRIMITIVE_INSTALLER_FAILED
#	else
			0x371C
#	endif
		// The SMI primitive installer failed during setup or servicing.

	, GENERIC_COMMAND_FAILED =
#	if defined ERROR_GENERIC_COMMAND_FAILED
			ERROR_GENERIC_COMMAND_FAILED
#	else
			0x371D
#	endif
		// A generic command executable returned a result that indicates failure.

	, SXS_FILE_HASH_MISSING =
#	if defined ERROR_SXS_FILE_HASH_MISSING
			ERROR_SXS_FILE_HASH_MISSING
#	else
			0x371E
#	endif
		// A component is missing file verification information in its manifest.

	, EVT_INVALID_CHANNEL_PATH =
#	if defined ERROR_EVT_INVALID_CHANNEL_PATH
			ERROR_EVT_INVALID_CHANNEL_PATH
#	else
			0x3A98
#	endif
		// The specified channel path is invalid.

	, EVT_INVALID_QUERY =
#	if defined ERROR_EVT_INVALID_QUERY
			ERROR_EVT_INVALID_QUERY
#	else
			0x3A99
#	endif
		// The specified query is invalid.

	, EVT_PUBLISHER_METADATA_NOT_FOUND =
#	if defined ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND
			ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND
#	else
			0x3A9A
#	endif
		// The publisher metadata cannot be found in the resource.

	, EVT_EVENT_TEMPLATE_NOT_FOUND =
#	if defined ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND
			ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND
#	else
			0x3A9B
#	endif
		// The template for an event definition cannot be found in the resource (error = %1).

	, EVT_INVALID_PUBLISHER_NAME =
#	if defined ERROR_EVT_INVALID_PUBLISHER_NAME
			ERROR_EVT_INVALID_PUBLISHER_NAME
#	else
			0x3A9C
#	endif
		// The specified publisher name is invalid.

	, EVT_INVALID_EVENT_DATA =
#	if defined ERROR_EVT_INVALID_EVENT_DATA
			ERROR_EVT_INVALID_EVENT_DATA
#	else
			0x3A9D
#	endif
		// The event data raised by the publisher is not compatible with the event template definition in the publisher's manifest.

	, EVT_CHANNEL_NOT_FOUND =
#	if defined ERROR_EVT_CHANNEL_NOT_FOUND
			ERROR_EVT_CHANNEL_NOT_FOUND
#	else
			0x3A9F
#	endif
		// The specified channel could not be found. Check channel configuration.

	, EVT_MALFORMED_XML_TEXT =
#	if defined ERROR_EVT_MALFORMED_XML_TEXT
			ERROR_EVT_MALFORMED_XML_TEXT
#	else
			0x3AA0
#	endif
		// The specified xml text was not well-formed. See Extended Error for more details.

	, EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL =
#	if defined ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL
			ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL
#	else
			0x3AA1
#	endif
		// The caller is trying to subscribe to a direct channel which is not allowed. The events for a direct channel go directly to a logfile and cannot be subscribed to.

	, EVT_CONFIGURATION_ERROR =
#	if defined ERROR_EVT_CONFIGURATION_ERROR
			ERROR_EVT_CONFIGURATION_ERROR
#	else
			0x3AA2
#	endif
		// Configuration error.

	, EVT_QUERY_RESULT_STALE =
#	if defined ERROR_EVT_QUERY_RESULT_STALE
			ERROR_EVT_QUERY_RESULT_STALE
#	else
			0x3AA3
#	endif
		// The query result is stale / invalid. This may be due to the log being cleared or rolling over after the query result was created. Users should handle this code by releasing the query result object and reissuing the query.

	, EVT_QUERY_RESULT_INVALID_POSITION =
#	if defined ERROR_EVT_QUERY_RESULT_INVALID_POSITION
			ERROR_EVT_QUERY_RESULT_INVALID_POSITION
#	else
			0x3AA4
#	endif
		// Query result is currently at an invalid position.

	, EVT_NON_VALIDATING_MSXML =
#	if defined ERROR_EVT_NON_VALIDATING_MSXML
			ERROR_EVT_NON_VALIDATING_MSXML
#	else
			0x3AA5
#	endif
		// Registered MSXML doesn't support validation.

	, EVT_FILTER_ALREADYSCOPED =
#	if defined ERROR_EVT_FILTER_ALREADYSCOPED
			ERROR_EVT_FILTER_ALREADYSCOPED
#	else
			0x3AA6
#	endif
		// An expression can only be followed by a change of scope operation if it itself evaluates to a node set and is not already part of some other change of scope operation.

	, EVT_FILTER_NOTELTSET =
#	if defined ERROR_EVT_FILTER_NOTELTSET
			ERROR_EVT_FILTER_NOTELTSET
#	else
			0x3AA7
#	endif
		// Can't perform a step operation from a term that does not represent an element set.

	, EVT_FILTER_INVARG =
#	if defined ERROR_EVT_FILTER_INVARG
			ERROR_EVT_FILTER_INVARG
#	else
			0x3AA8
#	endif
		// Left hand side arguments to binary operators must be either attributes, nodes or variables and right hand side arguments must be constants.

	, EVT_FILTER_INVTEST =
#	if defined ERROR_EVT_FILTER_INVTEST
			ERROR_EVT_FILTER_INVTEST
#	else
			0x3AA9
#	endif
		// A step operation must involve either a node test or, in the case of a predicate, an algebraic expression against which to test each node in the node set identified by the preceeding node set can be evaluated.

	, EVT_FILTER_INVTYPE =
#	if defined ERROR_EVT_FILTER_INVTYPE
			ERROR_EVT_FILTER_INVTYPE
#	else
			0x3AAA
#	endif
		// This data type is currently unsupported.

	, EVT_FILTER_PARSEERR =
#	if defined ERROR_EVT_FILTER_PARSEERR
			ERROR_EVT_FILTER_PARSEERR
#	else
			0x3AAB
#	endif
		// A syntax error occurred at position %1!d!.

	, EVT_FILTER_UNSUPPORTEDOP =
#	if defined ERROR_EVT_FILTER_UNSUPPORTEDOP
			ERROR_EVT_FILTER_UNSUPPORTEDOP
#	else
			0x3AAC
#	endif
		// This operator is unsupported by this implementation of the filter.

	, EVT_FILTER_UNEXPECTEDTOKEN =
#	if defined ERROR_EVT_FILTER_UNEXPECTEDTOKEN
			ERROR_EVT_FILTER_UNEXPECTEDTOKEN
#	else
			0x3AAD
#	endif
		// The token encountered was unexpected.

	, EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL =
#	if defined ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL
			ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL
#	else
			0x3AAE
#	endif
		// The requested operation cannot be performed over an enabled direct channel. The channel must first be disabled before performing the requested operation.

	, EVT_INVALID_CHANNEL_PROPERTY_VALUE =
#	if defined ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE
			ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE
#	else
			0x3AAF
#	endif
		// Channel property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of channel.

	, EVT_INVALID_PUBLISHER_PROPERTY_VALUE =
#	if defined ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE
			ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE
#	else
			0x3AB0
#	endif
		// Publisher property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of publisher.

	, EVT_CHANNEL_CANNOT_ACTIVATE =
#	if defined ERROR_EVT_CHANNEL_CANNOT_ACTIVATE
			ERROR_EVT_CHANNEL_CANNOT_ACTIVATE
#	else
			0x3AB1
#	endif
		// The channel fails to activate.

	, EVT_FILTER_TOO_COMPLEX =
#	if defined ERROR_EVT_FILTER_TOO_COMPLEX
			ERROR_EVT_FILTER_TOO_COMPLEX
#	else
			0x3AB2
#	endif
		// The xpath expression exceeded supported complexity. Please symplify it or split it into two or more simple expressions.

	, EVT_MESSAGE_NOT_FOUND =
#	if defined ERROR_EVT_MESSAGE_NOT_FOUND
			ERROR_EVT_MESSAGE_NOT_FOUND
#	else
			0x3AB3
#	endif
		// the message resource is present but the message is not found in the string/message table.

	, EVT_MESSAGE_ID_NOT_FOUND =
#	if defined ERROR_EVT_MESSAGE_ID_NOT_FOUND
			ERROR_EVT_MESSAGE_ID_NOT_FOUND
#	else
			0x3AB4
#	endif
		// The message id for the desired message could not be found.

	, EVT_UNRESOLVED_VALUE_INSERT =
#	if defined ERROR_EVT_UNRESOLVED_VALUE_INSERT
			ERROR_EVT_UNRESOLVED_VALUE_INSERT
#	else
			0x3AB5
#	endif
		// The substitution string for insert index (%1) could not be found.

	, EVT_UNRESOLVED_PARAMETER_INSERT =
#	if defined ERROR_EVT_UNRESOLVED_PARAMETER_INSERT
			ERROR_EVT_UNRESOLVED_PARAMETER_INSERT
#	else
			0x3AB6
#	endif
		// The description string for parameter reference (%1) could not be found.

	, EVT_MAX_INSERTS_REACHED =
#	if defined ERROR_EVT_MAX_INSERTS_REACHED
			ERROR_EVT_MAX_INSERTS_REACHED
#	else
			0x3AB7
#	endif
		// The maximum number of replacements has been reached.

	, EVT_EVENT_DEFINITION_NOT_FOUND =
#	if defined ERROR_EVT_EVENT_DEFINITION_NOT_FOUND
			ERROR_EVT_EVENT_DEFINITION_NOT_FOUND
#	else
			0x3AB8
#	endif
		// The event definition could not be found for event id (%1).

	, EVT_MESSAGE_LOCALE_NOT_FOUND =
#	if defined ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND
			ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND
#	else
			0x3AB9
#	endif
		// The locale specific resource for the desired message is not present.

	, EVT_VERSION_TOO_OLD =
#	if defined ERROR_EVT_VERSION_TOO_OLD
			ERROR_EVT_VERSION_TOO_OLD
#	else
			0x3ABA
#	endif
		// The resource is too old to be compatible.

	, EVT_VERSION_TOO_NEW =
#	if defined ERROR_EVT_VERSION_TOO_NEW
			ERROR_EVT_VERSION_TOO_NEW
#	else
			0x3ABB
#	endif
		// The resource is too new to be compatible.

	, EVT_CANNOT_OPEN_CHANNEL_OF_QUERY =
#	if defined ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY
			ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY
#	else
			0x3ABC
#	endif
		// The channel at index %1!d! of the query can't be opened.

	, EVT_PUBLISHER_DISABLED =
#	if defined ERROR_EVT_PUBLISHER_DISABLED
			ERROR_EVT_PUBLISHER_DISABLED
#	else
			0x3ABD
#	endif
		// The publisher has been disabled and its resource is not available. This usually occurs when the publisher is in the process of being uninstalled or upgraded.

	, EVT_FILTER_OUT_OF_RANGE =
#	if defined ERROR_EVT_FILTER_OUT_OF_RANGE
			ERROR_EVT_FILTER_OUT_OF_RANGE
#	else
			0x3ABE
#	endif
		// Attempted to create a numeric type that is outside of its valid range.

	, EC_SUBSCRIPTION_CANNOT_ACTIVATE =
#	if defined ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE
			ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE
#	else
			0x3AE8
#	endif
		// The subscription fails to activate.

	, EC_LOG_DISABLED =
#	if defined ERROR_EC_LOG_DISABLED
			ERROR_EC_LOG_DISABLED
#	else
			0x3AE9
#	endif
		// The log of the subscription is in disabled state, and can not be used to forward events to. The log must first be enabled before the subscription can be activated.

	, EC_CIRCULAR_FORWARDING =
#	if defined ERROR_EC_CIRCULAR_FORWARDING
			ERROR_EC_CIRCULAR_FORWARDING
#	else
			0x3AEA
#	endif
		// When forwarding events from local machine to itself, the query of the subscription can't contain target log of the subscription.

	, EC_CREDSTORE_FULL =
#	if defined ERROR_EC_CREDSTORE_FULL
			ERROR_EC_CREDSTORE_FULL
#	else
			0x3AEB
#	endif
		// The credential store that is used to save credentials is full.

	, EC_CRED_NOT_FOUND =
#	if defined ERROR_EC_CRED_NOT_FOUND
			ERROR_EC_CRED_NOT_FOUND
#	else
			0x3AEC
#	endif
		// The credential used by this subscription can't be found in credential store.

	, EC_NO_ACTIVE_CHANNEL =
#	if defined ERROR_EC_NO_ACTIVE_CHANNEL
			ERROR_EC_NO_ACTIVE_CHANNEL
#	else
			0x3AED
#	endif
		// No active channel is found for the query.

	, MUI_FILE_NOT_FOUND =
#	if defined ERROR_MUI_FILE_NOT_FOUND
			ERROR_MUI_FILE_NOT_FOUND
#	else
			0x3AFC
#	endif
		// The resource loader failed to find MUI file.

	, MUI_INVALID_FILE =
#	if defined ERROR_MUI_INVALID_FILE
			ERROR_MUI_INVALID_FILE
#	else
			0x3AFD
#	endif
		// The resource loader failed to load MUI file because the file fail to pass validation.

	, MUI_INVALID_RC_CONFIG =
#	if defined ERROR_MUI_INVALID_RC_CONFIG
			ERROR_MUI_INVALID_RC_CONFIG
#	else
			0x3AFE
#	endif
		// The RC Manifest is corrupted with garbage data or unsupported version or missing required item.

	, MUI_INVALID_LOCALE_NAME =
#	if defined ERROR_MUI_INVALID_LOCALE_NAME
			ERROR_MUI_INVALID_LOCALE_NAME
#	else
			0x3AFF
#	endif
		// The RC Manifest has invalid culture name.

	, MUI_INVALID_ULTIMATEFALLBACK_NAME =
#	if defined ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME
			ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME
#	else
			0x3B00
#	endif
		// The RC Manifest has invalid ultimatefallback name.

	, MUI_FILE_NOT_LOADED =
#	if defined ERROR_MUI_FILE_NOT_LOADED
			ERROR_MUI_FILE_NOT_LOADED
#	else
			0x3B01
#	endif
		// The resource loader cache doesn't have loaded MUI entry.

	, RESOURCE_ENUM_USER_STOP =
#	if defined ERROR_RESOURCE_ENUM_USER_STOP
			ERROR_RESOURCE_ENUM_USER_STOP
#	else
			0x3B02
#	endif
		// User stopped resource enumeration.

	, MUI_INTLSETTINGS_UILANG_NOT_INSTALLED =
#	if defined ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED
			ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED
#	else
			0x3B03
#	endif
		// UI language installation failed.

	, MUI_INTLSETTINGS_INVALID_LOCALE_NAME =
#	if defined ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME
			ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME
#	else
			0x3B04
#	endif
		// Locale installation failed.

	, MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE =
#	if defined ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE
			ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE
#	else
			0x3B06
#	endif
		// A resource does not have default or neutral value.

	, MRM_INVALID_PRICONFIG =
#	if defined ERROR_MRM_INVALID_PRICONFIG
			ERROR_MRM_INVALID_PRICONFIG
#	else
			0x3B07
#	endif
		// Invalid PRI config file.

	, MRM_INVALID_FILE_TYPE =
#	if defined ERROR_MRM_INVALID_FILE_TYPE
			ERROR_MRM_INVALID_FILE_TYPE
#	else
			0x3B08
#	endif
		// Invalid file type.

	, MRM_UNKNOWN_QUALIFIER =
#	if defined ERROR_MRM_UNKNOWN_QUALIFIER
			ERROR_MRM_UNKNOWN_QUALIFIER
#	else
			0x3B09
#	endif
		// Unknown qualifier.

	, MRM_INVALID_QUALIFIER_VALUE =
#	if defined ERROR_MRM_INVALID_QUALIFIER_VALUE
			ERROR_MRM_INVALID_QUALIFIER_VALUE
#	else
			0x3B0A
#	endif
		// Invalid qualifier value.

	, MRM_NO_CANDIDATE =
#	if defined ERROR_MRM_NO_CANDIDATE
			ERROR_MRM_NO_CANDIDATE
#	else
			0x3B0B
#	endif
		// No Candidate found.

	, MRM_NO_MATCH_OR_DEFAULT_CANDIDATE =
#	if defined ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE
			ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE
#	else
			0x3B0C
#	endif
		// The ResourceMap or NamedResource has an item that does not have default or neutral resource..

	, MRM_RESOURCE_TYPE_MISMATCH =
#	if defined ERROR_MRM_RESOURCE_TYPE_MISMATCH
			ERROR_MRM_RESOURCE_TYPE_MISMATCH
#	else
			0x3B0D
#	endif
		// Invalid ResourceCandidate type.

	, MRM_DUPLICATE_MAP_NAME =
#	if defined ERROR_MRM_DUPLICATE_MAP_NAME
			ERROR_MRM_DUPLICATE_MAP_NAME
#	else
			0x3B0E
#	endif
		// Duplicate Resource Map.

	, MRM_DUPLICATE_ENTRY =
#	if defined ERROR_MRM_DUPLICATE_ENTRY
			ERROR_MRM_DUPLICATE_ENTRY
#	else
			0x3B0F
#	endif
		// Duplicate Entry.

	, MRM_INVALID_RESOURCE_IDENTIFIER =
#	if defined ERROR_MRM_INVALID_RESOURCE_IDENTIFIER
			ERROR_MRM_INVALID_RESOURCE_IDENTIFIER
#	else
			0x3B10
#	endif
		// Invalid Resource Identifier.

	, MRM_FILEPATH_TOO_LONG =
#	if defined ERROR_MRM_FILEPATH_TOO_LONG
			ERROR_MRM_FILEPATH_TOO_LONG
#	else
			0x3B11
#	endif
		// Filepath too long.

	, MRM_UNSUPPORTED_DIRECTORY_TYPE =
#	if defined ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE
			ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE
#	else
			0x3B12
#	endif
		// Unsupported directory type.

	, MRM_INVALID_PRI_FILE =
#	if defined ERROR_MRM_INVALID_PRI_FILE
			ERROR_MRM_INVALID_PRI_FILE
#	else
			0x3B16
#	endif
		// Invalid PRI File.

	, MRM_NAMED_RESOURCE_NOT_FOUND =
#	if defined ERROR_MRM_NAMED_RESOURCE_NOT_FOUND
			ERROR_MRM_NAMED_RESOURCE_NOT_FOUND
#	else
			0x3B17
#	endif
		// NamedResource Not Found.

	, MRM_MAP_NOT_FOUND =
#	if defined ERROR_MRM_MAP_NOT_FOUND
			ERROR_MRM_MAP_NOT_FOUND
#	else
			0x3B1F
#	endif
		// ResourceMap Not Found.

	, MRM_UNSUPPORTED_PROFILE_TYPE =
#	if defined ERROR_MRM_UNSUPPORTED_PROFILE_TYPE
			ERROR_MRM_UNSUPPORTED_PROFILE_TYPE
#	else
			0x3B20
#	endif
		// Unsupported MRT profile type.

	, MRM_INVALID_QUALIFIER_OPERATOR =
#	if defined ERROR_MRM_INVALID_QUALIFIER_OPERATOR
			ERROR_MRM_INVALID_QUALIFIER_OPERATOR
#	else
			0x3B21
#	endif
		// Invalid qualifier operator.

	, MRM_INDETERMINATE_QUALIFIER_VALUE =
#	if defined ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE
			ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE
#	else
			0x3B22
#	endif
		// Unable to determine qualifier value or qualifier value has not been set.

	, MRM_AUTOMERGE_ENABLED =
#	if defined ERROR_MRM_AUTOMERGE_ENABLED
			ERROR_MRM_AUTOMERGE_ENABLED
#	else
			0x3B23
#	endif
		// Automerge is enabled in the PRI file.

	, MRM_TOO_MANY_RESOURCES =
#	if defined ERROR_MRM_TOO_MANY_RESOURCES
			ERROR_MRM_TOO_MANY_RESOURCES
#	else
			0x3B24
#	endif
		// Too many resources defined for package.

	, MCA_INVALID_CAPABILITIES_STRING =
#	if defined ERROR_MCA_INVALID_CAPABILITIES_STRING
			ERROR_MCA_INVALID_CAPABILITIES_STRING
#	else
			0x3B60
#	endif
		// The monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification.

	, MCA_INVALID_VCP_VERSION =
#	if defined ERROR_MCA_INVALID_VCP_VERSION
			ERROR_MCA_INVALID_VCP_VERSION
#	else
			0x3B61
#	endif
		// The monitor's VCP Version (0xDF) VCP code returned an invalid version value.

	, MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION =
#	if defined ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION
			ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION
#	else
			0x3B62
#	endif
		// The monitor does not comply with the MCCS specification it claims to support.

	, MCA_MCCS_VERSION_MISMATCH =
#	if defined ERROR_MCA_MCCS_VERSION_MISMATCH
			ERROR_MCA_MCCS_VERSION_MISMATCH
#	else
			0x3B63
#	endif
		// The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.

	, MCA_UNSUPPORTED_MCCS_VERSION =
#	if defined ERROR_MCA_UNSUPPORTED_MCCS_VERSION
			ERROR_MCA_UNSUPPORTED_MCCS_VERSION
#	else
			0x3B64
#	endif
		// The Monitor Configuration API only works with monitors that support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.

	, MCA_INTERNAL_ERROR =
#	if defined ERROR_MCA_INTERNAL_ERROR
			ERROR_MCA_INTERNAL_ERROR
#	else
			0x3B65
#	endif
		// An internal Monitor Configuration API error occurred.

	, MCA_INVALID_TECHNOLOGY_TYPE_RETURNED =
#	if defined ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED
			ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED
#	else
			0x3B66
#	endif
		// The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

	, MCA_UNSUPPORTED_COLOR_TEMPERATURE =
#	if defined ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE
			ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE
#	else
			0x3B67
#	endif
		// The caller of SetMonitorColorTemperature specified a color temperature that the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

	, AMBIGUOUS_SYSTEM_DEVICE =
#	if defined ERROR_AMBIGUOUS_SYSTEM_DEVICE
			ERROR_AMBIGUOUS_SYSTEM_DEVICE
#	else
			0x3B92
#	endif
		// The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.

	, SYSTEM_DEVICE_NOT_FOUND =
#	if defined ERROR_SYSTEM_DEVICE_NOT_FOUND
			ERROR_SYSTEM_DEVICE_NOT_FOUND
#	else
			0x3BC3
#	endif
		// The requested system device cannot be found.

	, HASH_NOT_SUPPORTED =
#	if defined ERROR_HASH_NOT_SUPPORTED
			ERROR_HASH_NOT_SUPPORTED
#	else
			0x3BC4
#	endif
		// Hash generation for the specified hash version and hash type is not enabled on the server.

	, HASH_NOT_PRESENT =
#	if defined ERROR_HASH_NOT_PRESENT
			ERROR_HASH_NOT_PRESENT
#	else
			0x3BC5
#	endif
		// The hash requested from the server is not available or no longer valid.

	, SECONDARY_IC_PROVIDER_NOT_REGISTERED =
#	if defined ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED
			ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED
#	else
			0x3BD9
#	endif
		// The secondary interrupt controller instance that manages the specified interrupt is not registered.

	, GPIO_CLIENT_INFORMATION_INVALID =
#	if defined ERROR_GPIO_CLIENT_INFORMATION_INVALID
			ERROR_GPIO_CLIENT_INFORMATION_INVALID
#	else
			0x3BDA
#	endif
		// The information supplied by the GPIO client driver is invalid.

	, GPIO_VERSION_NOT_SUPPORTED =
#	if defined ERROR_GPIO_VERSION_NOT_SUPPORTED
			ERROR_GPIO_VERSION_NOT_SUPPORTED
#	else
			0x3BDB
#	endif
		// The version specified by the GPIO client driver is not supported.

	, GPIO_INVALID_REGISTRATION_PACKET =
#	if defined ERROR_GPIO_INVALID_REGISTRATION_PACKET
			ERROR_GPIO_INVALID_REGISTRATION_PACKET
#	else
			0x3BDC
#	endif
		// The registration packet supplied by the GPIO client driver is not valid.

	, GPIO_OPERATION_DENIED =
#	if defined ERROR_GPIO_OPERATION_DENIED
			ERROR_GPIO_OPERATION_DENIED
#	else
			0x3BDD
#	endif
		// The requested operation is not supported for the specified handle.

	, GPIO_INCOMPATIBLE_CONNECT_MODE =
#	if defined ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE
			ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE
#	else
			0x3BDE
#	endif
		// The requested connect mode conflicts with an existing mode on one or more of the specified pins.

	, GPIO_INTERRUPT_ALREADY_UNMASKED =
#	if defined ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED
			ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED
#	else
			0x3BDF
#	endif
		// The interrupt requested to be unmasked is not masked.

	, CANNOT_SWITCH_RUNLEVEL =
#	if defined ERROR_CANNOT_SWITCH_RUNLEVEL
			ERROR_CANNOT_SWITCH_RUNLEVEL
#	else
			0x3C28
#	endif
		// The requested run level switch cannot be completed successfully.

	, INVALID_RUNLEVEL_SETTING =
#	if defined ERROR_INVALID_RUNLEVEL_SETTING
			ERROR_INVALID_RUNLEVEL_SETTING
#	else
			0x3C29
#	endif
		// The service has an invalid run level setting. The run level for a service must not be higher than the run level of its dependent services.

	, RUNLEVEL_SWITCH_TIMEOUT =
#	if defined ERROR_RUNLEVEL_SWITCH_TIMEOUT
			ERROR_RUNLEVEL_SWITCH_TIMEOUT
#	else
			0x3C2A
#	endif
		// The requested run level switch cannot be completed successfully since one or more services will not stop or restart within the specified timeout.

	, RUNLEVEL_SWITCH_AGENT_TIMEOUT =
#	if defined ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT
			ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT
#	else
			0x3C2B
#	endif
		// A run level switch agent did not respond within the specified timeout.

	, RUNLEVEL_SWITCH_IN_PROGRESS =
#	if defined ERROR_RUNLEVEL_SWITCH_IN_PROGRESS
			ERROR_RUNLEVEL_SWITCH_IN_PROGRESS
#	else
			0x3C2C
#	endif
		// A run level switch is currently in progress.

	, SERVICES_FAILED_AUTOSTART =
#	if defined ERROR_SERVICES_FAILED_AUTOSTART
			ERROR_SERVICES_FAILED_AUTOSTART
#	else
			0x3C2D
#	endif
		// One or more services failed to start during the service startup phase of a run level switch.

	, COM_TASK_STOP_PENDING =
#	if defined ERROR_COM_TASK_STOP_PENDING
			ERROR_COM_TASK_STOP_PENDING
#	else
			0x3C8D
#	endif
		// The task stop request cannot be completed immediately since task needs more time to shutdown.

	, INSTALL_OPEN_PACKAGE_FAILED =
#	if defined ERROR_INSTALL_OPEN_PACKAGE_FAILED
			ERROR_INSTALL_OPEN_PACKAGE_FAILED
#	else
			0x3CF0
#	endif
		// Package could not be opened.

	, INSTALL_PACKAGE_NOT_FOUND =
#	if defined ERROR_INSTALL_PACKAGE_NOT_FOUND
			ERROR_INSTALL_PACKAGE_NOT_FOUND
#	else
			0x3CF1
#	endif
		// Package was not found.

	, INSTALL_INVALID_PACKAGE =
#	if defined ERROR_INSTALL_INVALID_PACKAGE
			ERROR_INSTALL_INVALID_PACKAGE
#	else
			0x3CF2
#	endif
		// Package data is invalid.

	, INSTALL_RESOLVE_DEPENDENCY_FAILED =
#	if defined ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED
			ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED
#	else
			0x3CF3
#	endif
		// Package failed updates, dependency or conflict validation.

	, INSTALL_OUT_OF_DISK_SPACE =
#	if defined ERROR_INSTALL_OUT_OF_DISK_SPACE
			ERROR_INSTALL_OUT_OF_DISK_SPACE
#	else
			0x3CF4
#	endif
		// There is not enough disk space on your computer. Please free up some space and try again.

	, INSTALL_NETWORK_FAILURE =
#	if defined ERROR_INSTALL_NETWORK_FAILURE
			ERROR_INSTALL_NETWORK_FAILURE
#	else
			0x3CF5
#	endif
		// There was a problem downloading your product.

	, INSTALL_REGISTRATION_FAILURE =
#	if defined ERROR_INSTALL_REGISTRATION_FAILURE
			ERROR_INSTALL_REGISTRATION_FAILURE
#	else
			0x3CF6
#	endif
		// Package could not be registered.

	, INSTALL_DEREGISTRATION_FAILURE =
#	if defined ERROR_INSTALL_DEREGISTRATION_FAILURE
			ERROR_INSTALL_DEREGISTRATION_FAILURE
#	else
			0x3CF7
#	endif
		// Package could not be unregistered.

	, INSTALL_CANCEL =
#	if defined ERROR_INSTALL_CANCEL
			ERROR_INSTALL_CANCEL
#	else
			0x3CF8
#	endif
		// User cancelled the install request.

	, INSTALL_FAILED =
#	if defined ERROR_INSTALL_FAILED
			ERROR_INSTALL_FAILED
#	else
			0x3CF9
#	endif
		// Install failed. Please contact your software vendor.

	, REMOVE_FAILED =
#	if defined ERROR_REMOVE_FAILED
			ERROR_REMOVE_FAILED
#	else
			0x3CFA
#	endif
		// Removal failed. Please contact your software vendor.

	, PACKAGE_ALREADY_EXISTS =
#	if defined ERROR_PACKAGE_ALREADY_EXISTS
			ERROR_PACKAGE_ALREADY_EXISTS
#	else
			0x3CFB
#	endif
		// The provided package is already installed, and reinstallation of the package was blocked. Check the AppXDeployment-Server event log for details.

	, NEEDS_REMEDIATION =
#	if defined ERROR_NEEDS_REMEDIATION
			ERROR_NEEDS_REMEDIATION
#	else
			0x3CFC
#	endif
		// The application cannot be started. Try reinstalling the application to fix the problem.

	, INSTALL_PREREQUISITE_FAILED =
#	if defined ERROR_INSTALL_PREREQUISITE_FAILED
			ERROR_INSTALL_PREREQUISITE_FAILED
#	else
			0x3CFD
#	endif
		// A Prerequisite for an install could not be satisfied.

	, PACKAGE_REPOSITORY_CORRUPTED =
#	if defined ERROR_PACKAGE_REPOSITORY_CORRUPTED
			ERROR_PACKAGE_REPOSITORY_CORRUPTED
#	else
			0x3CFE
#	endif
		// The package repository is corrupted.

	, INSTALL_POLICY_FAILURE =
#	if defined ERROR_INSTALL_POLICY_FAILURE
			ERROR_INSTALL_POLICY_FAILURE
#	else
			0x3CFF
#	endif
		// To install this application you need either a Windows developer license or a sideloading-enabled system.

	, PACKAGE_UPDATING =
#	if defined ERROR_PACKAGE_UPDATING
			ERROR_PACKAGE_UPDATING
#	else
			0x3D00
#	endif
		// The application cannot be started because it is currently updating.

	, DEPLOYMENT_BLOCKED_BY_POLICY =
#	if defined ERROR_DEPLOYMENT_BLOCKED_BY_POLICY
			ERROR_DEPLOYMENT_BLOCKED_BY_POLICY
#	else
			0x3D01
#	endif
		// The package deployment operation is blocked by policy. Please contact your system administrator.

	, PACKAGES_IN_USE =
#	if defined ERROR_PACKAGES_IN_USE
			ERROR_PACKAGES_IN_USE
#	else
			0x3D02
#	endif
		// The package could not be installed because resources it modifies are currently in use.

	, RECOVERY_FILE_CORRUPT =
#	if defined ERROR_RECOVERY_FILE_CORRUPT
			ERROR_RECOVERY_FILE_CORRUPT
#	else
			0x3D03
#	endif
		// The package could not be recovered because necessary data for recovery have been corrupted.

	, INVALID_STAGED_SIGNATURE =
#	if defined ERROR_INVALID_STAGED_SIGNATURE
			ERROR_INVALID_STAGED_SIGNATURE
#	else
			0x3D04
#	endif
		// The signature is invalid. To register in developer mode, AppxSignature.p7x and AppxBlockMap.xml must be valid or should not be present.

	, DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED =
#	if defined ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED
			ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED
#	else
			0x3D05
#	endif
		// An error occurred while deleting the package's previously existing application data.

	, INSTALL_PACKAGE_DOWNGRADE =
#	if defined ERROR_INSTALL_PACKAGE_DOWNGRADE
			ERROR_INSTALL_PACKAGE_DOWNGRADE
#	else
			0x3D06
#	endif
		// The package could not be installed because a higher version of this package is already installed.

	, SYSTEM_NEEDS_REMEDIATION =
#	if defined ERROR_SYSTEM_NEEDS_REMEDIATION
			ERROR_SYSTEM_NEEDS_REMEDIATION
#	else
			0x3D07
#	endif
		// An error in a system binary was detected. Try refreshing the PC to fix the problem.

	, APPX_INTEGRITY_FAILURE_CLR_NGEN =
#	if defined ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN
			ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN
#	else
			0x3D08
#	endif
		// A corrupted CLR NGEN binary was detected on the system.

	, RESILIENCY_FILE_CORRUPT =
#	if defined ERROR_RESILIENCY_FILE_CORRUPT
			ERROR_RESILIENCY_FILE_CORRUPT
#	else
			0x3D09
#	endif
		// The operation could not be resumed because necessary data for recovery have been corrupted.

	, INSTALL_FIREWALL_SERVICE_NOT_RUNNING =
#	if defined ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING
			ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING
#	else
			0x3D0A
#	endif
		// The package could not be installed because the Windows Firewall service is not running. Enable the Windows Firewall service and try again.

	, APPMODEL_NO_PACKAGE =
#	if defined APPMODEL_ERROR_NO_PACKAGE
			APPMODEL_ERROR_NO_PACKAGE
#	else
			0x3D54
#	endif
		// The process has no package identity.

	, APPMODEL_PACKAGE_RUNTIME_CORRUPT =
#	if defined APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT
			APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT
#	else
			0x3D55
#	endif
		// The package runtime information is corrupted.

	, APPMODEL_PACKAGE_IDENTITY_CORRUPT =
#	if defined APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT
			APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT
#	else
			0x3D56
#	endif
		// The package identity is corrupted.

	, APPMODEL_NO_APPLICATION =
#	if defined APPMODEL_ERROR_NO_APPLICATION
			APPMODEL_ERROR_NO_APPLICATION
#	else
			0x3D57
#	endif
		// The process has no application identity.

	, STATE_LOAD_STORE_FAILED =
#	if defined ERROR_STATE_LOAD_STORE_FAILED
			ERROR_STATE_LOAD_STORE_FAILED
#	else
			0x3DB8
#	endif
		// Loading the state store failed.

	, STATE_GET_VERSION_FAILED =
#	if defined ERROR_STATE_GET_VERSION_FAILED
			ERROR_STATE_GET_VERSION_FAILED
#	else
			0x3DB9
#	endif
		// Retrieving the state version for the application failed.

	, STATE_SET_VERSION_FAILED =
#	if defined ERROR_STATE_SET_VERSION_FAILED
			ERROR_STATE_SET_VERSION_FAILED
#	else
			0x3DBA
#	endif
		// Setting the state version for the application failed.

	, STATE_STRUCTURED_RESET_FAILED =
#	if defined ERROR_STATE_STRUCTURED_RESET_FAILED
			ERROR_STATE_STRUCTURED_RESET_FAILED
#	else
			0x3DBB
#	endif
		// Resetting the structured state of the application failed.

	, STATE_OPEN_CONTAINER_FAILED =
#	if defined ERROR_STATE_OPEN_CONTAINER_FAILED
			ERROR_STATE_OPEN_CONTAINER_FAILED
#	else
			0x3DBC
#	endif
		// State Manager failed to open the container.

	, STATE_CREATE_CONTAINER_FAILED =
#	if defined ERROR_STATE_CREATE_CONTAINER_FAILED
			ERROR_STATE_CREATE_CONTAINER_FAILED
#	else
			0x3DBD
#	endif
		// State Manager failed to create the container.

	, STATE_DELETE_CONTAINER_FAILED =
#	if defined ERROR_STATE_DELETE_CONTAINER_FAILED
			ERROR_STATE_DELETE_CONTAINER_FAILED
#	else
			0x3DBE
#	endif
		// State Manager failed to delete the container.

	, STATE_READ_SETTING_FAILED =
#	if defined ERROR_STATE_READ_SETTING_FAILED
			ERROR_STATE_READ_SETTING_FAILED
#	else
			0x3DBF
#	endif
		// State Manager failed to read the setting.

	, STATE_WRITE_SETTING_FAILED =
#	if defined ERROR_STATE_WRITE_SETTING_FAILED
			ERROR_STATE_WRITE_SETTING_FAILED
#	else
			0x3DC0
#	endif
		// State Manager failed to write the setting.

	, STATE_DELETE_SETTING_FAILED =
#	if defined ERROR_STATE_DELETE_SETTING_FAILED
			ERROR_STATE_DELETE_SETTING_FAILED
#	else
			0x3DC1
#	endif
		// State Manager failed to delete the setting.

	, STATE_QUERY_SETTING_FAILED =
#	if defined ERROR_STATE_QUERY_SETTING_FAILED
			ERROR_STATE_QUERY_SETTING_FAILED
#	else
			0x3DC2
#	endif
		// State Manager failed to query the setting.

	, STATE_READ_COMPOSITE_SETTING_FAILED =
#	if defined ERROR_STATE_READ_COMPOSITE_SETTING_FAILED
			ERROR_STATE_READ_COMPOSITE_SETTING_FAILED
#	else
			0x3DC3
#	endif
		// State Manager failed to read the composite setting.

	, STATE_WRITE_COMPOSITE_SETTING_FAILED =
#	if defined ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED
			ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED
#	else
			0x3DC4
#	endif
		// State Manager failed to write the composite setting.

	, STATE_ENUMERATE_CONTAINER_FAILED =
#	if defined ERROR_STATE_ENUMERATE_CONTAINER_FAILED
			ERROR_STATE_ENUMERATE_CONTAINER_FAILED
#	else
			0x3DC5
#	endif
		// State Manager failed to enumerate the containers.

	, STATE_ENUMERATE_SETTINGS_FAILED =
#	if defined ERROR_STATE_ENUMERATE_SETTINGS_FAILED
			ERROR_STATE_ENUMERATE_SETTINGS_FAILED
#	else
			0x3DC6
#	endif
		// State Manager failed to enumerate the settings.

	, STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED =
#	if defined ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED
			ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED
#	else
			0x3DC7
#	endif
		// The size of the state manager composite setting value has exceeded the limit.

	, STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED =
#	if defined ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED
			ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED
#	else
			0x3DC8
#	endif
		// The size of the state manager setting value has exceeded the limit.

	, STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED =
#	if defined ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED
			ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED
#	else
			0x3DC9
#	endif
		// The length of the state manager setting name has exceeded the limit.

	, STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED =
#	if defined ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED
			ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED
#	else
			0x3DCA
#	endif
		// The length of the state manager container name has exceeded the limit.

	, API_UNAVAILABLE =
#	if defined ERROR_API_UNAVAILABLE
			ERROR_API_UNAVAILABLE
#	else
			0x3DE1
#	endif
		// This API cannot be used in the context of the caller's application type.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString9(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)
	{
		case SystemCode::IPSEC_QM_POLICY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified quick mode policy already exists"
			);
		case SystemCode::IPSEC_QM_POLICY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified quick mode policy was not found"
			);
		case SystemCode::IPSEC_QM_POLICY_IN_USE:
			RETURN_STATIC_STRING(
					"The specified quick mode policy is being used"
			);
		case SystemCode::IPSEC_MM_POLICY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified main mode policy already exists"
			);
		case SystemCode::IPSEC_MM_POLICY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified main mode policy was not found"
			);
		case SystemCode::IPSEC_MM_POLICY_IN_USE:
			RETURN_STATIC_STRING(
					"The specified main mode policy is being used"
			);
		case SystemCode::IPSEC_MM_FILTER_EXISTS:
			RETURN_STATIC_STRING(
					"The specified main mode filter already exists"
			);
		case SystemCode::IPSEC_MM_FILTER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified main mode filter was not found"
			);
		case SystemCode::IPSEC_TRANSPORT_FILTER_EXISTS:
			RETURN_STATIC_STRING(
					"The specified transport mode filter already exists"
			);
		case SystemCode::IPSEC_TRANSPORT_FILTER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified transport mode filter does not exist"
			);
		case SystemCode::IPSEC_MM_AUTH_EXISTS:
			RETURN_STATIC_STRING(
					"The specified main mode authentication list exists"
			);
		case SystemCode::IPSEC_MM_AUTH_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified main mode authentication list was not found"
			);
		case SystemCode::IPSEC_MM_AUTH_IN_USE:
			RETURN_STATIC_STRING(
					"The specified main mode authentication list is being used"
			);
		case SystemCode::IPSEC_DEFAULT_MM_POLICY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified default main mode policy was not found"
			);
		case SystemCode::IPSEC_DEFAULT_MM_AUTH_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified default main mode authentication list was not found"
			);
		case SystemCode::IPSEC_DEFAULT_QM_POLICY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified default quick mode policy was not found"
			);
		case SystemCode::IPSEC_TUNNEL_FILTER_EXISTS:
			RETURN_STATIC_STRING(
					"The specified tunnel mode filter exists"
			);
		case SystemCode::IPSEC_TUNNEL_FILTER_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified tunnel mode filter was not found"
			);
		case SystemCode::IPSEC_MM_FILTER_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The Main Mode filter is pending deletion"
			);
		case SystemCode::IPSEC_TRANSPORT_FILTER_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The transport filter is pending deletion"
			);
		case SystemCode::IPSEC_TUNNEL_FILTER_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The tunnel filter is pending deletion"
			);
		case SystemCode::IPSEC_MM_POLICY_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The Main Mode policy is pending deletion"
			);
		case SystemCode::IPSEC_MM_AUTH_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The Main Mode authentication bundle is pending deletion"
			);
		case SystemCode::IPSEC_QM_POLICY_PENDING_DELETION:
			RETURN_STATIC_STRING(
					"The Quick Mode policy is pending deletion"
			);
		case SystemCode::IPSEC_MM_POLICY_PRUNED:
			RETURN_STATIC_STRING(
					"The Main Mode policy was successfully added, but some of the requested offers"
					" are not supported"
			);
		case SystemCode::IPSEC_QM_POLICY_PRUNED:
			RETURN_STATIC_STRING(
					"The Quick Mode policy was successfully added, but some of the requested offers"
					" are not supported"
			);
		case SystemCode::IPSEC_IKE_NEG_STATUS_BEGIN:
			RETURN_STATIC_STRING(
					"ERROR_IPSEC_IKE_NEG_STATUS_BEGI"
			);
		case SystemCode::IPSEC_IKE_AUTH_FAIL:
			RETURN_STATIC_STRING(
					"IKE authentication credentials are unacceptable"
			);
		case SystemCode::IPSEC_IKE_ATTRIB_FAIL:
			RETURN_STATIC_STRING(
					"IKE security attributes are unacceptable"
			);
		case SystemCode::IPSEC_IKE_NEGOTIATION_PENDING:
			RETURN_STATIC_STRING(
					"IKE Negotiation in progress"
			);
		case SystemCode::IPSEC_IKE_GENERAL_PROCESSING_ERROR:
			RETURN_STATIC_STRING(
					"General processing error"
			);
		case SystemCode::IPSEC_IKE_TIMED_OUT:
			RETURN_STATIC_STRING(
					"Negotiation timed out"
			);
		case SystemCode::IPSEC_IKE_NO_CERT:
			RETURN_STATIC_STRING(
					"IKE failed to find valid machine certificate. Contact your Network Security"
					" Administrator about installing a valid certificate in the appropriate"
					" Certificate Store"
			);
		case SystemCode::IPSEC_IKE_SA_DELETED:
			RETURN_STATIC_STRING(
					"IKE SA deleted by peer before establishment completed"
			);
		case SystemCode::IPSEC_IKE_SA_REAPED:
			RETURN_STATIC_STRING(
					"IKE SA deleted before establishment completed"
			);
		case SystemCode::IPSEC_IKE_MM_ACQUIRE_DROP:
			RETURN_STATIC_STRING(
					"Negotiation request sat in Queue too long"
			);
		case SystemCode::IPSEC_IKE_QM_ACQUIRE_DROP:
			RETURN_STATIC_STRING(
					"Negotiation request sat in Queue too long"
			);
		case SystemCode::IPSEC_IKE_QUEUE_DROP_MM:
			RETURN_STATIC_STRING(
					"Negotiation request sat in Queue too long"
			);
		case SystemCode::IPSEC_IKE_QUEUE_DROP_NO_MM:
			RETURN_STATIC_STRING(
					"Negotiation request sat in Queue too long"
			);
		case SystemCode::IPSEC_IKE_DROP_NO_RESPONSE:
			RETURN_STATIC_STRING(
					"No response from peer"
			);
		case SystemCode::IPSEC_IKE_MM_DELAY_DROP:
			RETURN_STATIC_STRING(
					"Negotiation took too long"
			);
		case SystemCode::IPSEC_IKE_QM_DELAY_DROP:
			RETURN_STATIC_STRING(
					"Negotiation took too long"
			);
		case SystemCode::IPSEC_IKE_ERROR:
			RETURN_STATIC_STRING(
					"Unknown error occurred"
			);
		case SystemCode::IPSEC_IKE_CRL_FAILED:
			RETURN_STATIC_STRING(
					"Certificate Revocation Check failed"
			);
		case SystemCode::IPSEC_IKE_INVALID_KEY_USAGE:
			RETURN_STATIC_STRING(
					"Invalid certificate key usage"
			);
		case SystemCode::IPSEC_IKE_INVALID_CERT_TYPE:
			RETURN_STATIC_STRING(
					"Invalid certificate type"
			);
		case SystemCode::IPSEC_IKE_NO_PRIVATE_KEY:
			RETURN_STATIC_STRING(
					"IKE negotiation failed because the machine certificate used does not have a"
					" private key. IPsec certificates require a private key. Contact your Network"
					" Security administrator about replacing with a certificate that has a private"
					" key"
			);
		case SystemCode::IPSEC_IKE_SIMULTANEOUS_REKEY:
			RETURN_STATIC_STRING(
					"Simultaneous rekeys were detected"
			);
		case SystemCode::IPSEC_IKE_DH_FAIL:
			RETURN_STATIC_STRING(
					"Failure in Diffie-Hellman computation"
			);
		case SystemCode::IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED:
			RETURN_STATIC_STRING(
					"Don't know how to process critical payload"
			);
		case SystemCode::IPSEC_IKE_INVALID_HEADER:
			RETURN_STATIC_STRING(
					"Invalid header"
			);
		case SystemCode::IPSEC_IKE_NO_POLICY:
			RETURN_STATIC_STRING(
					"No policy configured"
			);
		case SystemCode::IPSEC_IKE_INVALID_SIGNATURE:
			RETURN_STATIC_STRING(
					"Failed to verify signature"
			);
		case SystemCode::IPSEC_IKE_KERBEROS_ERROR:
			RETURN_STATIC_STRING(
					"Failed to authenticate using Kerberos"
			);
		case SystemCode::IPSEC_IKE_NO_PUBLIC_KEY:
			RETURN_STATIC_STRING(
					"Peer's certificate did not have a public key"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR:
			RETURN_STATIC_STRING(
					"Error processing error payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_SA:
			RETURN_STATIC_STRING(
					"Error processing SA payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_PROP:
			RETURN_STATIC_STRING(
					"Error processing Proposal payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_TRANS:
			RETURN_STATIC_STRING(
					"Error processing Transform payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_KE:
			RETURN_STATIC_STRING(
					"Error processing KE payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_ID:
			RETURN_STATIC_STRING(
					"Error processing ID payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_CERT:
			RETURN_STATIC_STRING(
					"Error processing Cert payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_CERT_REQ:
			RETURN_STATIC_STRING(
					"Error processing Certificate Request payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_HASH:
			RETURN_STATIC_STRING(
					"Error processing Hash payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_SIG:
			RETURN_STATIC_STRING(
					"Error processing Signature payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_NONCE:
			RETURN_STATIC_STRING(
					"Error processing Nonce payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_NOTIFY:
			RETURN_STATIC_STRING(
					"Error processing Notify payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_DELETE:
			RETURN_STATIC_STRING(
					"Error processing Delete Payload"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_VENDOR:
			RETURN_STATIC_STRING(
					"Error processing VendorId payload"
			);
		case SystemCode::IPSEC_IKE_INVALID_PAYLOAD:
			RETURN_STATIC_STRING(
					"Invalid payload received"
			);
		case SystemCode::IPSEC_IKE_LOAD_SOFT_SA:
			RETURN_STATIC_STRING(
					"Soft SA loaded"
			);
		case SystemCode::IPSEC_IKE_SOFT_SA_TORN_DOWN:
			RETURN_STATIC_STRING(
					"Soft SA torn down"
			);
		case SystemCode::IPSEC_IKE_INVALID_COOKIE:
			RETURN_STATIC_STRING(
					"Invalid cookie received"
			);
		case SystemCode::IPSEC_IKE_NO_PEER_CERT:
			RETURN_STATIC_STRING(
					"Peer failed to send valid machine certificate"
			);
		case SystemCode::IPSEC_IKE_PEER_CRL_FAILED:
			RETURN_STATIC_STRING(
					"Certification Revocation check of peer's certificate failed"
			);
		case SystemCode::IPSEC_IKE_POLICY_CHANGE:
			RETURN_STATIC_STRING(
					"New policy invalidated SAs formed with old policy"
			);
		case SystemCode::IPSEC_IKE_NO_MM_POLICY:
			RETURN_STATIC_STRING(
					"There is no available Main Mode IKE policy"
			);
		case SystemCode::IPSEC_IKE_NOTCBPRIV:
			RETURN_STATIC_STRING(
					"Failed to enabled TCB privilege"
			);
		case SystemCode::IPSEC_IKE_SECLOADFAIL:
			RETURN_STATIC_STRING(
					"Failed to load SECURITY.DLL"
			);
		case SystemCode::IPSEC_IKE_FAILSSPINIT:
			RETURN_STATIC_STRING(
					"Failed to obtain security function table dispatch address from SSPI"
			);
		case SystemCode::IPSEC_IKE_FAILQUERYSSP:
			RETURN_STATIC_STRING(
					"Failed to query Kerberos package to obtain max token size"
			);
		case SystemCode::IPSEC_IKE_SRVACQFAIL:
			RETURN_STATIC_STRING(
					"Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE"
					" service. Kerberos authentication will not function. The most likely reason"
					" for this is lack of domain membership. This is normal if your computer is a"
					" member of a workgroup"
			);
		case SystemCode::IPSEC_IKE_SRVQUERYCRED:
			RETURN_STATIC_STRING(
					"Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service"
					" (QueryCredentialsAttributes)"
			);
		case SystemCode::IPSEC_IKE_GETSPIFAIL:
			RETURN_STATIC_STRING(
					"Failed to obtain new SPI for the inbound SA from IPsec driver. The most common"
					" cause for this is that the driver does not have the correct filter. Check"
					" your policy to verify the filters"
			);
		case SystemCode::IPSEC_IKE_INVALID_FILTER:
			RETURN_STATIC_STRING(
					"Given filter is invalid"
			);
		case SystemCode::IPSEC_IKE_OUT_OF_MEMORY:
			RETURN_STATIC_STRING(
					"Memory allocation failed"
			);
		case SystemCode::IPSEC_IKE_ADD_UPDATE_KEY_FAILED:
			RETURN_STATIC_STRING(
					"Failed to add Security Association to IPsec Driver. The most common cause for"
					" this is if the IKE negotiation took too long to complete. If the problem"
					" persists, reduce the load on the faulting machine"
			);
		case SystemCode::IPSEC_IKE_INVALID_POLICY:
			RETURN_STATIC_STRING(
					"Invalid policy"
			);
		case SystemCode::IPSEC_IKE_UNKNOWN_DOI:
			RETURN_STATIC_STRING(
					"Invalid DOI"
			);
		case SystemCode::IPSEC_IKE_INVALID_SITUATION:
			RETURN_STATIC_STRING(
					"Invalid situation"
			);
		case SystemCode::IPSEC_IKE_DH_FAILURE:
			RETURN_STATIC_STRING(
					"Diffie-Hellman failure"
			);
		case SystemCode::IPSEC_IKE_INVALID_GROUP:
			RETURN_STATIC_STRING(
					"Invalid Diffie-Hellman group"
			);
		case SystemCode::IPSEC_IKE_ENCRYPT:
			RETURN_STATIC_STRING(
					"Error encrypting payload"
			);
		case SystemCode::IPSEC_IKE_DECRYPT:
			RETURN_STATIC_STRING(
					"Error decrypting payload"
			);
		case SystemCode::IPSEC_IKE_POLICY_MATCH:
			RETURN_STATIC_STRING(
					"Policy match error"
			);
		case SystemCode::IPSEC_IKE_UNSUPPORTED_ID:
			RETURN_STATIC_STRING(
					"Unsupported ID"
			);
		case SystemCode::IPSEC_IKE_INVALID_HASH:
			RETURN_STATIC_STRING(
					"Hash verification failed"
			);
		case SystemCode::IPSEC_IKE_INVALID_HASH_ALG:
			RETURN_STATIC_STRING(
					"Invalid hash algorithm"
			);
		case SystemCode::IPSEC_IKE_INVALID_HASH_SIZE:
			RETURN_STATIC_STRING(
					"Invalid hash size"
			);
		case SystemCode::IPSEC_IKE_INVALID_ENCRYPT_ALG:
			RETURN_STATIC_STRING(
					"Invalid encryption algorithm"
			);
		case SystemCode::IPSEC_IKE_INVALID_AUTH_ALG:
			RETURN_STATIC_STRING(
					"Invalid authentication algorithm"
			);
		case SystemCode::IPSEC_IKE_INVALID_SIG:
			RETURN_STATIC_STRING(
					"Invalid certificate signature"
			);
		case SystemCode::IPSEC_IKE_LOAD_FAILED:
			RETURN_STATIC_STRING(
					"Load failed"
			);
		case SystemCode::IPSEC_IKE_RPC_DELETE:
			RETURN_STATIC_STRING(
					"Deleted via RPC call"
			);
		case SystemCode::IPSEC_IKE_BENIGN_REINIT:
			RETURN_STATIC_STRING(
					"Temporary state created to perform reinitialization. This is not a real"
					" failure"
			);
		case SystemCode::IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY:
			RETURN_STATIC_STRING(
					"The lifetime value received in the Responder Lifetime Notify is below the"
					" Windows 2000 configured minimum value. Please fix the policy on the peer"
					" machine"
			);
		case SystemCode::IPSEC_IKE_INVALID_MAJOR_VERSION:
			RETURN_STATIC_STRING(
					"The recipient cannot handle version of IKE specified in the header"
			);
		case SystemCode::IPSEC_IKE_INVALID_CERT_KEYLEN:
			RETURN_STATIC_STRING(
					"Key length in certificate is too small for configured security requirements"
			);
		case SystemCode::IPSEC_IKE_MM_LIMIT:
			RETURN_STATIC_STRING(
					"Max number of established MM SAs to peer exceeded"
			);
		case SystemCode::IPSEC_IKE_NEGOTIATION_DISABLED:
			RETURN_STATIC_STRING(
					"IKE received a policy that disables negotiation"
			);
		case SystemCode::IPSEC_IKE_QM_LIMIT:
			RETURN_STATIC_STRING(
					"Reached maximum quick mode limit for the main mode. New main mode will be"
					" started"
			);
		case SystemCode::IPSEC_IKE_MM_EXPIRED:
			RETURN_STATIC_STRING(
					"Main mode SA lifetime expired or peer sent a main mode delete"
			);
		case SystemCode::IPSEC_IKE_PEER_MM_ASSUMED_INVALID:
			RETURN_STATIC_STRING(
					"Main mode SA assumed to be invalid because peer stopped responding"
			);
		case SystemCode::IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH:
			RETURN_STATIC_STRING(
					"Certificate doesn't chain to a trusted root in IPsec policy"
			);
		case SystemCode::IPSEC_IKE_UNEXPECTED_MESSAGE_ID:
			RETURN_STATIC_STRING(
					"Received unexpected message ID"
			);
		case SystemCode::IPSEC_IKE_INVALID_AUTH_PAYLOAD:
			RETURN_STATIC_STRING(
					"Received invalid authentication offers"
			);
		case SystemCode::IPSEC_IKE_DOS_COOKIE_SENT:
			RETURN_STATIC_STRING(
					"Sent DoS cookie notify to initiator"
			);
		case SystemCode::IPSEC_IKE_SHUTTING_DOWN:
			RETURN_STATIC_STRING(
					"IKE service is shutting down"
			);
		case SystemCode::IPSEC_IKE_CGA_AUTH_FAILED:
			RETURN_STATIC_STRING(
					"Could not verify binding between CGA address and certificate"
			);
		case SystemCode::IPSEC_IKE_PROCESS_ERR_NATOA:
			RETURN_STATIC_STRING(
					"Error processing NatOA payload"
			);
		case SystemCode::IPSEC_IKE_INVALID_MM_FOR_QM:
			RETURN_STATIC_STRING(
					"Parameters of the main mode are invalid for this quick mode"
			);
		case SystemCode::IPSEC_IKE_QM_EXPIRED:
			RETURN_STATIC_STRING(
					"Quick mode SA was expired by IPsec driver"
			);
		case SystemCode::IPSEC_IKE_TOO_MANY_FILTERS:
			RETURN_STATIC_STRING(
					"Too many dynamically added IKEEXT filters were detected"
			);
		case SystemCode::IPSEC_IKE_NEG_STATUS_END:
			RETURN_STATIC_STRING(
					"ERROR_IPSEC_IKE_NEG_STATUS_EN"
			);
		case SystemCode::IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL:
			RETURN_STATIC_STRING(
					"NAP reauth succeeded and must delete the dummy NAP IKEv2 tunnel"
			);
		case SystemCode::IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE:
			RETURN_STATIC_STRING(
					"Error in assigning inner IP address to initiator in tunnel mode"
			);
		case SystemCode::IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING:
			RETURN_STATIC_STRING(
					"Require configuration payload missing"
			);
		case SystemCode::IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING:
			RETURN_STATIC_STRING(
					"A negotiation running as the security principle who issued the connection is"
					" in progress"
			);
		case SystemCode::IPSEC_IKE_COEXISTENCE_SUPPRESS:
			RETURN_STATIC_STRING(
					"SA was deleted due to IKEv1/AuthIP co-existence suppress check"
			);
		case SystemCode::IPSEC_IKE_RATELIMIT_DROP:
			RETURN_STATIC_STRING(
					"Incoming SA request was dropped due to peer IP address rate limiting"
			);
		case SystemCode::IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE:
			RETURN_STATIC_STRING(
					"Peer does not support MOBIKE"
			);
		case SystemCode::IPSEC_IKE_AUTHORIZATION_FAILURE:
			RETURN_STATIC_STRING(
					"SA establishment is not authorized"
			);
		case SystemCode::IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE:
			RETURN_STATIC_STRING(
					"SA establishment is not authorized because there is not a sufficiently strong"
					" PKINIT-based credential"
			);
		case SystemCode::IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY:
			RETURN_STATIC_STRING(
					"SA establishment is not authorized. You may need to enter updated or different"
					" credentials such as a smartcard"
			);
		case SystemCode::IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE:
			RETURN_STATIC_STRING(
					"SA establishment is not authorized because there is not a sufficiently strong"
					" PKINIT-based credential. This might be related to certificate-to-account"
					" mapping failure for the SA"
			);
		case SystemCode::IPSEC_IKE_NEG_STATUS_EXTENDED_END:
			RETURN_STATIC_STRING(
					"ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_EN"
			);
		case SystemCode::IPSEC_BAD_SPI:
			RETURN_STATIC_STRING(
					"The SPI in the packet does not match a valid IPsec SA"
			);
		case SystemCode::IPSEC_SA_LIFETIME_EXPIRED:
			RETURN_STATIC_STRING(
					"Packet was received on an IPsec SA whose lifetime has expired"
			);
		case SystemCode::IPSEC_WRONG_SA:
			RETURN_STATIC_STRING(
					"Packet was received on an IPsec SA that does not match the packet"
					" characteristics"
			);
		case SystemCode::IPSEC_REPLAY_CHECK_FAILED:
			RETURN_STATIC_STRING(
					"Packet sequence number replay check failed"
			);
		case SystemCode::IPSEC_INVALID_PACKET:
			RETURN_STATIC_STRING(
					"IPsec header and/or trailer in the packet is invalid"
			);
		case SystemCode::IPSEC_INTEGRITY_CHECK_FAILED:
			RETURN_STATIC_STRING(
					"IPsec integrity check failed"
			);
		case SystemCode::IPSEC_CLEAR_TEXT_DROP:
			RETURN_STATIC_STRING(
					"IPsec dropped a clear text packet"
			);
		case SystemCode::IPSEC_AUTH_FIREWALL_DROP:
			RETURN_STATIC_STRING(
					"IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop"
					" is benign"
			);
		case SystemCode::IPSEC_THROTTLE_DROP:
			RETURN_STATIC_STRING(
					"IPsec dropped a packet due to DoS throttling"
			);
		case SystemCode::IPSEC_DOSP_BLOCK:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection matched an explicit block rule"
			);
		case SystemCode::IPSEC_DOSP_RECEIVED_MULTICAST:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection received an IPsec specific multicast packet which is not"
					" allowed"
			);
		case SystemCode::IPSEC_DOSP_INVALID_PACKET:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection received an incorrectly formatted packet"
			);
		case SystemCode::IPSEC_DOSP_STATE_LOOKUP_FAILED:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection failed to look up state"
			);
		case SystemCode::IPSEC_DOSP_MAX_ENTRIES:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection failed to create state because the maximum number of"
					" entries allowed by policy has been reached"
			);
		case SystemCode::IPSEC_DOSP_KEYMOD_NOT_ALLOWED:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection received an IPsec negotiation packet for a keying module"
					" which is not allowed by policy"
			);
		case SystemCode::IPSEC_DOSP_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection has not been enabled"
			);
		case SystemCode::IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES:
			RETURN_STATIC_STRING(
					"IPsec DoS Protection failed to create a per internal IP rate limit queue"
					" because the maximum number of queues allowed by policy has been reached"
			);
		case SystemCode::SXS_SECTION_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested section was not present in the activation context"
			);
		case SystemCode::SXS_CANT_GEN_ACTCTX:
			RETURN_STATIC_STRING(
					"The application has failed to start because its side-by-side configuration is"
					" incorrect. Please see the application event log or use the command-line"
					" sxstrace.exe tool for more detail"
			);
		case SystemCode::SXS_INVALID_ACTCTXDATA_FORMAT:
			RETURN_STATIC_STRING(
					"The application binding data format is invalid"
			);
		case SystemCode::SXS_ASSEMBLY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The referenced assembly is not installed on your system"
			);
		case SystemCode::SXS_MANIFEST_FORMAT_ERROR:
			RETURN_STATIC_STRING(
					"The manifest file does not begin with the required tag and format information"
			);
		case SystemCode::SXS_MANIFEST_PARSE_ERROR:
			RETURN_STATIC_STRING(
					"The manifest file contains one or more syntax errors"
			);
		case SystemCode::SXS_ACTIVATION_CONTEXT_DISABLED:
			RETURN_STATIC_STRING(
					"The application attempted to activate a disabled activation context"
			);
		case SystemCode::SXS_KEY_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested lookup key was not found in any active activation context"
			);
		case SystemCode::SXS_VERSION_CONFLICT:
			RETURN_STATIC_STRING(
					"A component version required by the application conflicts with another"
					" component version already active"
			);
		case SystemCode::SXS_WRONG_SECTION_TYPE:
			RETURN_STATIC_STRING(
					"The type requested activation context section does not match the query API"
					" used"
			);
		case SystemCode::SXS_THREAD_QUERIES_DISABLED:
			RETURN_STATIC_STRING(
					"Lack of system resources has required isolated activation to be disabled for"
					" the current thread of execution"
			);
		case SystemCode::SXS_PROCESS_DEFAULT_ALREADY_SET:
			RETURN_STATIC_STRING(
					"An attempt to set the process default activation context failed because the"
					" process default activation context was already set"
			);
		case SystemCode::SXS_UNKNOWN_ENCODING_GROUP:
			RETURN_STATIC_STRING(
					"The encoding group identifier specified is not recognized"
			);
		case SystemCode::SXS_UNKNOWN_ENCODING:
			RETURN_STATIC_STRING(
					"The encoding requested is not recognized"
			);
		case SystemCode::SXS_INVALID_XML_NAMESPACE_URI:
			RETURN_STATIC_STRING(
					"The manifest contains a reference to an invalid URI"
			);
		case SystemCode::SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"The application manifest contains a reference to a dependent assembly which is"
					" not installed"
			);
		case SystemCode::SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"The manifest for an assembly used by the application has a reference to a"
					" dependent assembly which is not installed"
			);
		case SystemCode::SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE:
			RETURN_STATIC_STRING(
					"The manifest contains an attribute for the assembly identity which is not"
					" valid"
			);
		case SystemCode::SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE:
			RETURN_STATIC_STRING(
					"The manifest is missing the required default namespace specification on the"
					" assembly element"
			);
		case SystemCode::SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE:
			RETURN_STATIC_STRING(
					"The manifest has a default namespace specified on the assembly element but its"
					" value is not \"urn:schemas-microsoft-com:asm.v1\""
			);
		case SystemCode::SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT:
			RETURN_STATIC_STRING(
					"The private manifest probed has crossed a path with an unsupported reparse"
					" point"
			);
		case SystemCode::SXS_DUPLICATE_DLL_NAME:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have files by the same name"
			);
		case SystemCode::SXS_DUPLICATE_WINDOWCLASS_NAME:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have window classes with the same name"
			);
		case SystemCode::SXS_DUPLICATE_CLSID:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have the same COM server CLSIDs"
			);
		case SystemCode::SXS_DUPLICATE_IID:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have proxies for the same COM interface IIDs"
			);
		case SystemCode::SXS_DUPLICATE_TLBID:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have the same COM type library TLBIDs"
			);
		case SystemCode::SXS_DUPLICATE_PROGID:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest have the same COM ProgIDs"
			);
		case SystemCode::SXS_DUPLICATE_ASSEMBLY_NAME:
			RETURN_STATIC_STRING(
					"Two or more components referenced directly or indirectly by the application"
					" manifest are different versions of the same component which is not permitted"
			);
		case SystemCode::SXS_FILE_HASH_MISMATCH:
			RETURN_STATIC_STRING(
					"A component's file does not match the verification information present in the"
					" component manifest"
			);
		case SystemCode::SXS_POLICY_PARSE_ERROR:
			RETURN_STATIC_STRING(
					"The policy manifest contains one or more syntax errors"
			);
		case SystemCode::SXS_XML_E_MISSINGQUOTE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A string literal was expected, but no opening quote"
					" character was found"
			);
		case SystemCode::SXS_XML_E_COMMENTSYNTAX:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Incorrect syntax was used in a comment"
			);
		case SystemCode::SXS_XML_E_BADSTARTNAMECHAR:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A name was started with an invalid character"
			);
		case SystemCode::SXS_XML_E_BADNAMECHAR:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A name contained an invalid character"
			);
		case SystemCode::SXS_XML_E_BADCHARINSTRING:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A string literal contained an invalid character"
			);
		case SystemCode::SXS_XML_E_XMLDECLSYNTAX:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid syntax for an xml declaration"
			);
		case SystemCode::SXS_XML_E_BADCHARDATA:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : An Invalid character was found in text content"
			);
		case SystemCode::SXS_XML_E_MISSINGWHITESPACE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Required white space was missing"
			);
		case SystemCode::SXS_XML_E_EXPECTINGTAGEND:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The character '>' was expected"
			);
		case SystemCode::SXS_XML_E_MISSINGSEMICOLON:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A semi colon character was expected"
			);
		case SystemCode::SXS_XML_E_UNBALANCEDPAREN:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Unbalanced parentheses"
			);
		case SystemCode::SXS_XML_E_INTERNALERROR:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Internal error"
			);
		case SystemCode::SXS_XML_E_UNEXPECTED_WHITESPACE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Whitespace is not allowed at this location"
			);
		case SystemCode::SXS_XML_E_INCOMPLETE_ENCODING:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : End of file reached in invalid state for current encoding"
			);
		case SystemCode::SXS_XML_E_MISSING_PAREN:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Missing parenthesis"
			);
		case SystemCode::SXS_XML_E_EXPECTINGCLOSEQUOTE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A single or double closing quote character (\' or \")"
					" is missing"
			);
		case SystemCode::SXS_XML_E_MULTIPLE_COLONS:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Multiple colons are not allowed in a name"
			);
		case SystemCode::SXS_XML_E_INVALID_DECIMAL:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid character for decimal digit"
			);
		case SystemCode::SXS_XML_E_INVALID_HEXIDECIMAL:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid character for hexadecimal digit"
			);
		case SystemCode::SXS_XML_E_INVALID_UNICODE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid unicode character value for this platform"
			);
		case SystemCode::SXS_XML_E_WHITESPACEORQUESTIONMARK:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Expecting whitespace or '?'"
			);
		case SystemCode::SXS_XML_E_UNEXPECTEDENDTAG:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : End tag was not expected at this location"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDTAG:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The following tags were not closed: %1"
			);
		case SystemCode::SXS_XML_E_DUPLICATEATTRIBUTE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Duplicate attribute"
			);
		case SystemCode::SXS_XML_E_MULTIPLEROOTS:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Only one top level element is allowed in an XML"
					" document"
			);
		case SystemCode::SXS_XML_E_INVALIDATROOTLEVEL:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid at the top level of the document"
			);
		case SystemCode::SXS_XML_E_BADXMLDECL:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid xml declaration"
			);
		case SystemCode::SXS_XML_E_MISSINGROOT:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : XML document must have a top level element"
			);
		case SystemCode::SXS_XML_E_UNEXPECTEDEOF:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Unexpected end of file"
			);
		case SystemCode::SXS_XML_E_BADPEREFINSUBSET:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Parameter entities cannot be used inside markup"
					" declarations in an internal subset"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDSTARTTAG:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Element was not closed"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDENDTAG:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : End element was missing the character '>'"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDSTRING:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A string literal was not closed"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDCOMMENT:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A comment was not closed"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDDECL:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A declaration was not closed"
			);
		case SystemCode::SXS_XML_E_UNCLOSEDCDATA:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : A CDATA section was not closed"
			);
		case SystemCode::SXS_XML_E_RESERVEDNAMESPACE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The namespace prefix is not allowed to start with the"
					" reserved string \"xml\""
			);
		case SystemCode::SXS_XML_E_INVALIDENCODING:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : System does not support the specified encoding"
			);
		case SystemCode::SXS_XML_E_INVALIDSWITCH:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Switch from current encoding to specified encoding not"
					" supported"
			);
		case SystemCode::SXS_XML_E_BADXMLCASE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The name 'xml' is reserved and must be lower case"
			);
		case SystemCode::SXS_XML_E_INVALID_STANDALONE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The standalone attribute must have the value 'yes' or"
					" 'no'"
			);
		case SystemCode::SXS_XML_E_UNEXPECTED_STANDALONE:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : The standalone attribute cannot be used in external"
					" entities"
			);
		case SystemCode::SXS_XML_E_INVALID_VERSION:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Invalid version number"
			);
		case SystemCode::SXS_XML_E_MISSINGEQUALS:
			RETURN_STATIC_STRING(
					"Manifest Parse Error : Missing equals sign between attribute and attribute"
					" value"
			);
		case SystemCode::SXS_PROTECTION_RECOVERY_FAILED:
			RETURN_STATIC_STRING(
					"Assembly Protection Error : Unable to recover the specified assembly"
			);
		case SystemCode::SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT:
			RETURN_STATIC_STRING(
					"Assembly Protection Error : The public key for an assembly was too short to be"
					" allowed"
			);
		case SystemCode::SXS_PROTECTION_CATALOG_NOT_VALID:
			RETURN_STATIC_STRING(
					"Assembly Protection Error : The catalog for an assembly is not valid, or does"
					" not match the assembly's manifest"
			);
		case SystemCode::SXS_UNTRANSLATABLE_HRESULT:
			RETURN_STATIC_STRING(
					"An HRESULT could not be translated to a corresponding Win32 error code"
			);
		case SystemCode::SXS_PROTECTION_CATALOG_FILE_MISSING:
			RETURN_STATIC_STRING(
					"Assembly Protection Error : The catalog for an assembly is missing"
			);
		case SystemCode::SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE:
			RETURN_STATIC_STRING(
					"The supplied assembly identity is missing one or more attributes which must be"
					" present in this context"
			);
		case SystemCode::SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME:
			RETURN_STATIC_STRING(
					"The supplied assembly identity has one or more attribute names that contain"
					" characters not permitted in XML names"
			);
		case SystemCode::SXS_ASSEMBLY_MISSING:
			RETURN_STATIC_STRING(
					"The referenced assembly could not be found"
			);
		case SystemCode::SXS_CORRUPT_ACTIVATION_STACK:
			RETURN_STATIC_STRING(
					"The activation context activation stack for the running thread of execution is"
					" corrupt"
			);
		case SystemCode::SXS_CORRUPTION:
			RETURN_STATIC_STRING(
					"The application isolation metadata for this process or thread has become"
					" corrupt"
			);
		case SystemCode::SXS_EARLY_DEACTIVATION:
			RETURN_STATIC_STRING(
					"The activation context being deactivated is not the most recently activated"
					" one"
			);
		case SystemCode::SXS_INVALID_DEACTIVATION:
			RETURN_STATIC_STRING(
					"The activation context being deactivated is not active for the current thread"
					" of execution"
			);
		case SystemCode::SXS_MULTIPLE_DEACTIVATION:
			RETURN_STATIC_STRING(
					"The activation context being deactivated has already been deactivated"
			);
		case SystemCode::SXS_PROCESS_TERMINATION_REQUESTED:
			RETURN_STATIC_STRING(
					"A component used by the isolation facility has requested to terminate the"
					" process"
			);
		case SystemCode::SXS_RELEASE_ACTIVATION_CONTEXT:
			RETURN_STATIC_STRING(
					"A kernel mode component is releasing a reference on an activation context"
			);
		case SystemCode::SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY:
			RETURN_STATIC_STRING(
					"The activation context of system default assembly could not be generated"
			);
		case SystemCode::SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE:
			RETURN_STATIC_STRING(
					"The value of an attribute in an identity is not within the legal range"
			);
		case SystemCode::SXS_INVALID_IDENTITY_ATTRIBUTE_NAME:
			RETURN_STATIC_STRING(
					"The name of an attribute in an identity is not within the legal range"
			);
		case SystemCode::SXS_IDENTITY_DUPLICATE_ATTRIBUTE:
			RETURN_STATIC_STRING(
					"An identity contains two definitions for the same attribute"
			);
		case SystemCode::SXS_IDENTITY_PARSE_ERROR:
			RETURN_STATIC_STRING(
					"The identity string is malformed. This may be due to a trailing comma, more"
					" than two unnamed attributes, missing attribute name or missing attribute"
					" value"
			);
		case SystemCode::MALFORMED_SUBSTITUTION_STRING:
			RETURN_STATIC_STRING(
					"A string containing localized substitutable content was malformed. Either a"
					" dollar sign ($) was followed by something other than a left parenthesis or"
					" another dollar sign or an substitution's right parenthesis was not found"
			);
		case SystemCode::SXS_INCORRECT_PUBLIC_KEY_TOKEN:
			RETURN_STATIC_STRING(
					"The public key token does not correspond to the public key specified"
			);
		case SystemCode::UNMAPPED_SUBSTITUTION_STRING:
			RETURN_STATIC_STRING(
					"A substitution string had no mapping"
			);
		case SystemCode::SXS_ASSEMBLY_NOT_LOCKED:
			RETURN_STATIC_STRING(
					"The component must be locked before making the request"
			);
		case SystemCode::SXS_COMPONENT_STORE_CORRUPT:
			RETURN_STATIC_STRING(
					"The component store has been corrupted"
			);
		case SystemCode::ADVANCED_INSTALLER_FAILED:
			RETURN_STATIC_STRING(
					"An advanced installer failed during setup or servicing"
			);
		case SystemCode::XML_ENCODING_MISMATCH:
			RETURN_STATIC_STRING(
					"The character encoding in the XML declaration did not match the encoding used"
					" in the document"
			);
		case SystemCode::SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT:
			RETURN_STATIC_STRING(
					"The identities of the manifests are identical but their contents are different"
			);
		case SystemCode::SXS_IDENTITIES_DIFFERENT:
			RETURN_STATIC_STRING(
					"The component identities are different"
			);
		case SystemCode::SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT:
			RETURN_STATIC_STRING(
					"The assembly is not a deployment"
			);
		case SystemCode::SXS_FILE_NOT_PART_OF_ASSEMBLY:
			RETURN_STATIC_STRING(
					"The file is not a part of the assembly"
			);
		case SystemCode::SXS_MANIFEST_TOO_BIG:
			RETURN_STATIC_STRING(
					"The size of the manifest exceeds the maximum allowed"
			);
		case SystemCode::SXS_SETTING_NOT_REGISTERED:
			RETURN_STATIC_STRING(
					"The setting is not registered"
			);
		case SystemCode::SXS_TRANSACTION_CLOSURE_INCOMPLETE:
			RETURN_STATIC_STRING(
					"One or more required members of the transaction are not present"
			);
		case SystemCode::SMI_PRIMITIVE_INSTALLER_FAILED:
			RETURN_STATIC_STRING(
					"The SMI primitive installer failed during setup or servicing"
			);
		case SystemCode::GENERIC_COMMAND_FAILED:
			RETURN_STATIC_STRING(
					"A generic command executable returned a result that indicates failure"
			);
		case SystemCode::SXS_FILE_HASH_MISSING:
			RETURN_STATIC_STRING(
					"A component is missing file verification information in its manifest"
			);
		case SystemCode::EVT_INVALID_CHANNEL_PATH:
			RETURN_STATIC_STRING(
					"The specified channel path is invalid"
			);
		case SystemCode::EVT_INVALID_QUERY:
			RETURN_STATIC_STRING(
					"The specified query is invalid"
			);
		case SystemCode::EVT_PUBLISHER_METADATA_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The publisher metadata cannot be found in the resource"
			);
		case SystemCode::EVT_EVENT_TEMPLATE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The template for an event definition cannot be found in the resource"
					" (error = %1)"
			);
		case SystemCode::EVT_INVALID_PUBLISHER_NAME:
			RETURN_STATIC_STRING(
					"The specified publisher name is invalid"
			);
		case SystemCode::EVT_INVALID_EVENT_DATA:
			RETURN_STATIC_STRING(
					"The event data raised by the publisher is not compatible with the event"
					" template definition in the publisher's manifest"
			);
		case SystemCode::EVT_CHANNEL_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified channel could not be found. Check channel configuration"
			);
		case SystemCode::EVT_MALFORMED_XML_TEXT:
			RETURN_STATIC_STRING(
					"The specified xml text was not well-formed. See Extended Error for more"
					" details"
			);
		case SystemCode::EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL:
			RETURN_STATIC_STRING(
					"The caller is trying to subscribe to a direct channel which is not allowed."
					" The events for a direct channel go directly to a logfile and cannot be"
					" subscribed to"
			);
		case SystemCode::EVT_CONFIGURATION_ERROR:
			RETURN_STATIC_STRING(
					"Configuration error"
			);
		case SystemCode::EVT_QUERY_RESULT_STALE:
			RETURN_STATIC_STRING(
					"The query result is stale / invalid. This may be due to the log being cleared"
					" or rolling over after the query result was created. Users should handle this"
					" code by releasing the query result object and reissuing the query"
			);
		case SystemCode::EVT_QUERY_RESULT_INVALID_POSITION:
			RETURN_STATIC_STRING(
					"Query result is currently at an invalid position"
			);
		case SystemCode::EVT_NON_VALIDATING_MSXML:
			RETURN_STATIC_STRING(
					"Registered MSXML doesn't support validation"
			);
		case SystemCode::EVT_FILTER_ALREADYSCOPED:
			RETURN_STATIC_STRING(
					"An expression can only be followed by a change of scope operation if it itself"
					" evaluates to a node set and is not already part of some other change of scope"
					" operation"
			);
		case SystemCode::EVT_FILTER_NOTELTSET:
			RETURN_STATIC_STRING(
					"Can't perform a step operation from a term that does not represent an element"
					" set"
			);
		case SystemCode::EVT_FILTER_INVARG:
			RETURN_STATIC_STRING(
					"Left hand side arguments to binary operators must be either attributes, nodes"
					" or variables and right hand side arguments must be constants"
			);
		case SystemCode::EVT_FILTER_INVTEST:
			RETURN_STATIC_STRING(
					"A step operation must involve either a node test or, in the case of a"
					" predicate, an algebraic expression against which to test each node in the"
					" node set identified by the preceeding node set can be evaluated"
			);
		case SystemCode::EVT_FILTER_INVTYPE:
			RETURN_STATIC_STRING(
					"This data type is currently unsupported"
			);
		case SystemCode::EVT_FILTER_PARSEERR:
			RETURN_STATIC_STRING(
					"A syntax error occurred at position %1!d!"
			);
		case SystemCode::EVT_FILTER_UNSUPPORTEDOP:
			RETURN_STATIC_STRING(
					"This operator is unsupported by this implementation of the filter"
			);
		case SystemCode::EVT_FILTER_UNEXPECTEDTOKEN:
			RETURN_STATIC_STRING(
					"The token encountered was unexpected"
			);
		case SystemCode::EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL:
			RETURN_STATIC_STRING(
					"The requested operation cannot be performed over an enabled direct channel."
					" The channel must first be disabled before performing the requested operation"
			);
		case SystemCode::EVT_INVALID_CHANNEL_PROPERTY_VALUE:
			RETURN_STATIC_STRING(
					"Channel property %1!s! contains invalid value. The value has invalid type, is"
					" outside of valid range, can't be updated or is not supported by this type of"
					" channel"
			);
		case SystemCode::EVT_INVALID_PUBLISHER_PROPERTY_VALUE:
			RETURN_STATIC_STRING(
					"Publisher property %1!s! contains invalid value. The value has invalid type,"
					" is outside of valid range, can't be updated or is not supported by this type"
					" of publisher"
			);
		case SystemCode::EVT_CHANNEL_CANNOT_ACTIVATE:
			RETURN_STATIC_STRING(
					"The channel fails to activate"
			);
		case SystemCode::EVT_FILTER_TOO_COMPLEX:
			RETURN_STATIC_STRING(
					"The xpath expression exceeded supported complexity. Please symplify it or"
					" split it into two or more simple expressions"
			);
		case SystemCode::EVT_MESSAGE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"the message resource is present but the message is not found in the"
					" string/message table"
			);
		case SystemCode::EVT_MESSAGE_ID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The message id for the desired message could not be found"
			);
		case SystemCode::EVT_UNRESOLVED_VALUE_INSERT:
			RETURN_STATIC_STRING(
					"The substitution string for insert index (%1) could not be found"
			);
		case SystemCode::EVT_UNRESOLVED_PARAMETER_INSERT:
			RETURN_STATIC_STRING(
					"The description string for parameter reference (%1) could not be found"
			);
		case SystemCode::EVT_MAX_INSERTS_REACHED:
			RETURN_STATIC_STRING(
					"The maximum number of replacements has been reached"
			);
		case SystemCode::EVT_EVENT_DEFINITION_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The event definition could not be found for event id (%1)"
			);
		case SystemCode::EVT_MESSAGE_LOCALE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The locale specific resource for the desired message is not present"
			);
		case SystemCode::EVT_VERSION_TOO_OLD:
			RETURN_STATIC_STRING(
					"The resource is too old to be compatible"
			);
		case SystemCode::EVT_VERSION_TOO_NEW:
			RETURN_STATIC_STRING(
					"The resource is too new to be compatible"
			);
		case SystemCode::EVT_CANNOT_OPEN_CHANNEL_OF_QUERY:
			RETURN_STATIC_STRING(
					"The channel at index %1!d! of the query can't be opened"
			);
		case SystemCode::EVT_PUBLISHER_DISABLED:
			RETURN_STATIC_STRING(
					"The publisher has been disabled and its resource is not available. This"
					" usually occurs when the publisher is in the process of being uninstalled or"
					" upgraded"
			);
		case SystemCode::EVT_FILTER_OUT_OF_RANGE:
			RETURN_STATIC_STRING(
					"Attempted to create a numeric type that is outside of its valid range"
			);
		case SystemCode::EC_SUBSCRIPTION_CANNOT_ACTIVATE:
			RETURN_STATIC_STRING(
					"The subscription fails to activate"
			);
		case SystemCode::EC_LOG_DISABLED:
			RETURN_STATIC_STRING(
					"The log of the subscription is in disabled state, and can not be used to"
					" forward events to. The log must first be enabled before the subscription can"
					" be activated"
			);
		case SystemCode::EC_CIRCULAR_FORWARDING:
			RETURN_STATIC_STRING(
					"When forwarding events from local machine to itself, the query of the"
					" subscription can't contain target log of the subscription"
			);
		case SystemCode::EC_CREDSTORE_FULL:
			RETURN_STATIC_STRING(
					"The credential store that is used to save credentials is full"
			);
		case SystemCode::EC_CRED_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The credential used by this subscription can't be found in credential store"
			);
		case SystemCode::EC_NO_ACTIVE_CHANNEL:
			RETURN_STATIC_STRING(
					"No active channel is found for the query"
			);
		case SystemCode::MUI_FILE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The resource loader failed to find MUI file"
			);
		case SystemCode::MUI_INVALID_FILE:
			RETURN_STATIC_STRING(
					"The resource loader failed to load MUI file because the file fail to pass"
					" validation"
			);
		case SystemCode::MUI_INVALID_RC_CONFIG:
			RETURN_STATIC_STRING(
					"The RC Manifest is corrupted with garbage data or unsupported version or"
					" missing required item"
			);
		case SystemCode::MUI_INVALID_LOCALE_NAME:
			RETURN_STATIC_STRING(
					"The RC Manifest has invalid culture name"
			);
		case SystemCode::MUI_INVALID_ULTIMATEFALLBACK_NAME:
			RETURN_STATIC_STRING(
					"The RC Manifest has invalid ultimatefallback name"
			);
		case SystemCode::MUI_FILE_NOT_LOADED:
			RETURN_STATIC_STRING(
					"The resource loader cache doesn't have loaded MUI entry"
			);
		case SystemCode::RESOURCE_ENUM_USER_STOP:
			RETURN_STATIC_STRING(
					"User stopped resource enumeration"
			);
		case SystemCode::MUI_INTLSETTINGS_UILANG_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"UI language installation failed"
			);
		case SystemCode::MUI_INTLSETTINGS_INVALID_LOCALE_NAME:
			RETURN_STATIC_STRING(
					"Locale installation failed"
			);
		case SystemCode::MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE:
			RETURN_STATIC_STRING(
					"A resource does not have default or neutral value"
			);
		case SystemCode::MRM_INVALID_PRICONFIG:
			RETURN_STATIC_STRING(
					"Invalid PRI config file"
			);
		case SystemCode::MRM_INVALID_FILE_TYPE:
			RETURN_STATIC_STRING(
					"Invalid file type"
			);
		case SystemCode::MRM_UNKNOWN_QUALIFIER:
			RETURN_STATIC_STRING(
					"Unknown qualifier"
			);
		case SystemCode::MRM_INVALID_QUALIFIER_VALUE:
			RETURN_STATIC_STRING(
					"Invalid qualifier value"
			);
		case SystemCode::MRM_NO_CANDIDATE:
			RETURN_STATIC_STRING(
					"No Candidate found"
			);
		case SystemCode::MRM_NO_MATCH_OR_DEFAULT_CANDIDATE:
			RETURN_STATIC_STRING(
					"The ResourceMap or NamedResource has an item that does not have default or"
					" neutral resource"
			);
		case SystemCode::MRM_RESOURCE_TYPE_MISMATCH:
			RETURN_STATIC_STRING(
					"Invalid ResourceCandidate type"
			);
		case SystemCode::MRM_DUPLICATE_MAP_NAME:
			RETURN_STATIC_STRING(
					"Duplicate Resource Map"
			);
		case SystemCode::MRM_DUPLICATE_ENTRY:
			RETURN_STATIC_STRING(
					"Duplicate Entry"
			);
		case SystemCode::MRM_INVALID_RESOURCE_IDENTIFIER:
			RETURN_STATIC_STRING(
					"Invalid Resource Identifier"
			);
		case SystemCode::MRM_FILEPATH_TOO_LONG:
			RETURN_STATIC_STRING(
					"Filepath too long"
			);
		case SystemCode::MRM_UNSUPPORTED_DIRECTORY_TYPE:
			RETURN_STATIC_STRING(
					"Unsupported directory type"
			);
		case SystemCode::MRM_INVALID_PRI_FILE:
			RETURN_STATIC_STRING(
					"Invalid PRI File"
			);
		case SystemCode::MRM_NAMED_RESOURCE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"NamedResource Not Found"
			);
		case SystemCode::MRM_MAP_NOT_FOUND:
			RETURN_STATIC_STRING(
					"ResourceMap Not Found"
			);
		case SystemCode::MRM_UNSUPPORTED_PROFILE_TYPE:
			RETURN_STATIC_STRING(
					"Unsupported MRT profile type"
			);
		case SystemCode::MRM_INVALID_QUALIFIER_OPERATOR:
			RETURN_STATIC_STRING(
					"Invalid qualifier operator"
			);
		case SystemCode::MRM_INDETERMINATE_QUALIFIER_VALUE:
			RETURN_STATIC_STRING(
					"Unable to determine qualifier value or qualifier value has not been set"
			);
		case SystemCode::MRM_AUTOMERGE_ENABLED:
			RETURN_STATIC_STRING(
					"Automerge is enabled in the PRI file"
			);
		case SystemCode::MRM_TOO_MANY_RESOURCES:
			RETURN_STATIC_STRING(
					"Too many resources defined for package"
			);
		case SystemCode::MCA_INVALID_CAPABILITIES_STRING:
			RETURN_STATIC_STRING(
					"The monitor returned a DDC/CI capabilities string that did not comply with the"
					" ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification"
			);
		case SystemCode::MCA_INVALID_VCP_VERSION:
			RETURN_STATIC_STRING(
					"The monitor's VCP Version (0xDF) VCP code returned an invalid version value"
			);
		case SystemCode::MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION:
			RETURN_STATIC_STRING(
					"The monitor does not comply with the MCCS specification it claims to support"
			);
		case SystemCode::MCA_MCCS_VERSION_MISMATCH:
			RETURN_STATIC_STRING(
					"The MCCS version in a monitor's mccs_ver capability does not match the MCCS"
					" version the monitor reports when the VCP Version (0xDF) VCP code is used"
			);
		case SystemCode::MCA_UNSUPPORTED_MCCS_VERSION:
			RETURN_STATIC_STRING(
					"The Monitor Configuration API only works with monitors that support the MCCS"
					" 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1"
					" specification"
			);
		case SystemCode::MCA_INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"An internal Monitor Configuration API error occurred"
			);
		case SystemCode::MCA_INVALID_TECHNOLOGY_TYPE_RETURNED:
			RETURN_STATIC_STRING(
					"The monitor returned an invalid monitor technology type. CRT, Plasma and LCD"
					" (TFT) are examples of monitor technology types. This error implies that the"
					" monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification"
			);
		case SystemCode::MCA_UNSUPPORTED_COLOR_TEMPERATURE:
			RETURN_STATIC_STRING(
					"The caller of SetMonitorColorTemperature specified a color temperature that"
					" the current monitor did not support. This error implies that the monitor"
					" violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification"
			);
		case SystemCode::AMBIGUOUS_SYSTEM_DEVICE:
			RETURN_STATIC_STRING(
					"The requested system device cannot be identified due to multiple"
					" indistinguishable devices potentially matching the identification criteria"
			);
		case SystemCode::SYSTEM_DEVICE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The requested system device cannot be found"
			);
		case SystemCode::HASH_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"Hash generation for the specified hash version and hash type is not enabled on"
					" the server"
			);
		case SystemCode::HASH_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"The hash requested from the server is not available or no longer valid"
			);
		case SystemCode::SECONDARY_IC_PROVIDER_NOT_REGISTERED:
			RETURN_STATIC_STRING(
					"The secondary interrupt controller instance that manages the specified"
					" interrupt is not registered"
			);
		case SystemCode::GPIO_CLIENT_INFORMATION_INVALID:
			RETURN_STATIC_STRING(
					"The information supplied by the GPIO client driver is invalid"
			);
		case SystemCode::GPIO_VERSION_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The version specified by the GPIO client driver is not supported"
			);
		case SystemCode::GPIO_INVALID_REGISTRATION_PACKET:
			RETURN_STATIC_STRING(
					"The registration packet supplied by the GPIO client driver is not valid"
			);
		case SystemCode::GPIO_OPERATION_DENIED:
			RETURN_STATIC_STRING(
					"The requested operation is not supported for the specified handle"
			);
		case SystemCode::GPIO_INCOMPATIBLE_CONNECT_MODE:
			RETURN_STATIC_STRING(
					"The requested connect mode conflicts with an existing mode on one or more of"
					" the specified pins"
			);
		case SystemCode::GPIO_INTERRUPT_ALREADY_UNMASKED:
			RETURN_STATIC_STRING(
					"The interrupt requested to be unmasked is not masked"
			);
		case SystemCode::CANNOT_SWITCH_RUNLEVEL:
			RETURN_STATIC_STRING(
					"The requested run level switch cannot be completed successfully"
			);
		case SystemCode::INVALID_RUNLEVEL_SETTING:
			RETURN_STATIC_STRING(
					"The service has an invalid run level setting. The run level for a service must"
					" not be higher than the run level of its dependent services"
			);
		case SystemCode::RUNLEVEL_SWITCH_TIMEOUT:
			RETURN_STATIC_STRING(
					"The requested run level switch cannot be completed successfully since one or"
					" more services will not stop or restart within the specified timeout"
			);
		case SystemCode::RUNLEVEL_SWITCH_AGENT_TIMEOUT:
			RETURN_STATIC_STRING(
					"A run level switch agent did not respond within the specified timeout"
			);
		case SystemCode::RUNLEVEL_SWITCH_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"A run level switch is currently in progress"
			);
		case SystemCode::SERVICES_FAILED_AUTOSTART:
			RETURN_STATIC_STRING(
					"One or more services failed to start during the service startup phase of a run"
					" level switch"
			);
		case SystemCode::COM_TASK_STOP_PENDING:
			RETURN_STATIC_STRING(
					"The task stop request cannot be completed immediately since task needs more"
					" time to shutdown"
			);
		case SystemCode::INSTALL_OPEN_PACKAGE_FAILED:
			RETURN_STATIC_STRING(
					"Package could not be opened"
			);
		case SystemCode::INSTALL_PACKAGE_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Package was not found"
			);
		case SystemCode::INSTALL_INVALID_PACKAGE:
			RETURN_STATIC_STRING(
					"Package data is invalid"
			);
		case SystemCode::INSTALL_RESOLVE_DEPENDENCY_FAILED:
			RETURN_STATIC_STRING(
					"Package failed updates, dependency or conflict validation"
			);
		case SystemCode::INSTALL_OUT_OF_DISK_SPACE:
			RETURN_STATIC_STRING(
					"There is not enough disk space on your computer. Please free up some space and"
					" try again"
			);
		case SystemCode::INSTALL_NETWORK_FAILURE:
			RETURN_STATIC_STRING(
					"There was a problem downloading your product"
			);
		case SystemCode::INSTALL_REGISTRATION_FAILURE:
			RETURN_STATIC_STRING(
					"Package could not be registered"
			);
		case SystemCode::INSTALL_DEREGISTRATION_FAILURE:
			RETURN_STATIC_STRING(
					"Package could not be unregistered"
			);
		case SystemCode::INSTALL_CANCEL:
			RETURN_STATIC_STRING(
					"User cancelled the install request"
			);
		case SystemCode::INSTALL_FAILED:
			RETURN_STATIC_STRING(
					"Install failed. Please contact your software vendor"
			);
		case SystemCode::REMOVE_FAILED:
			RETURN_STATIC_STRING(
					"Removal failed. Please contact your software vendor"
			);
		case SystemCode::PACKAGE_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The provided package is already installed, and reinstallation of the package"
					" was blocked. Check the AppXDeployment-Server event log for details"
			);
		case SystemCode::NEEDS_REMEDIATION:
			RETURN_STATIC_STRING(
					"The application cannot be started. Try reinstalling the application to fix the"
					" problem"
			);
		case SystemCode::INSTALL_PREREQUISITE_FAILED:
			RETURN_STATIC_STRING(
					"A Prerequisite for an install could not be satisfied"
			);
		case SystemCode::PACKAGE_REPOSITORY_CORRUPTED:
			RETURN_STATIC_STRING(
					"The package repository is corrupted"
			);
		case SystemCode::INSTALL_POLICY_FAILURE:
			RETURN_STATIC_STRING(
					"To install this application you need either a Windows developer license or a"
					" sideloading-enabled system"
			);
		case SystemCode::PACKAGE_UPDATING:
			RETURN_STATIC_STRING(
					"The application cannot be started because it is currently updating"
			);
		case SystemCode::DEPLOYMENT_BLOCKED_BY_POLICY:
			RETURN_STATIC_STRING(
					"The package deployment operation is blocked by policy. Please contact your"
					" system administrator"
			);
		case SystemCode::PACKAGES_IN_USE:
			RETURN_STATIC_STRING(
					"The package could not be installed because resources it modifies are currently"
					" in use"
			);
		case SystemCode::RECOVERY_FILE_CORRUPT:
			RETURN_STATIC_STRING(
					"The package could not be recovered because necessary data for recovery have"
					" been corrupted"
			);
		case SystemCode::INVALID_STAGED_SIGNATURE:
			RETURN_STATIC_STRING(
					"The signature is invalid. To register in developer mode, AppxSignature.p7x and"
					" AppxBlockMap.xml must be valid or should not be present"
			);
		case SystemCode::DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED:
			RETURN_STATIC_STRING(
					"An error occurred while deleting the package's previously existing application"
					" data"
			);
		case SystemCode::INSTALL_PACKAGE_DOWNGRADE:
			RETURN_STATIC_STRING(
					"The package could not be installed because a higher version of this package is"
					" already installed"
			);
		case SystemCode::SYSTEM_NEEDS_REMEDIATION:
			RETURN_STATIC_STRING(
					"An error in a system binary was detected. Try refreshing the PC to fix the"
					" problem"
			);
		case SystemCode::APPX_INTEGRITY_FAILURE_CLR_NGEN:
			RETURN_STATIC_STRING(
					"A corrupted CLR NGEN binary was detected on the system"
			);
		case SystemCode::RESILIENCY_FILE_CORRUPT:
			RETURN_STATIC_STRING(
					"The operation could not be resumed because necessary data for recovery have"
					" been corrupted"
			);
		case SystemCode::INSTALL_FIREWALL_SERVICE_NOT_RUNNING:
			RETURN_STATIC_STRING(
					"The package could not be installed because the Windows Firewall service is not"
					" running. Enable the Windows Firewall service and try again"
			);
		case SystemCode::APPMODEL_NO_PACKAGE:
			RETURN_STATIC_STRING(
					"The process has no package identity"
			);
		case SystemCode::APPMODEL_PACKAGE_RUNTIME_CORRUPT:
			RETURN_STATIC_STRING(
					"The package runtime information is corrupted"
			);
		case SystemCode::APPMODEL_PACKAGE_IDENTITY_CORRUPT:
			RETURN_STATIC_STRING(
					"The package identity is corrupted"
			);
		case SystemCode::APPMODEL_NO_APPLICATION:
			RETURN_STATIC_STRING(
					"The process has no application identity"
			);
		case SystemCode::STATE_LOAD_STORE_FAILED:
			RETURN_STATIC_STRING(
					"Loading the state store failed"
			);
		case SystemCode::STATE_GET_VERSION_FAILED:
			RETURN_STATIC_STRING(
					"Retrieving the state version for the application failed"
			);
		case SystemCode::STATE_SET_VERSION_FAILED:
			RETURN_STATIC_STRING(
					"Setting the state version for the application failed"
			);
		case SystemCode::STATE_STRUCTURED_RESET_FAILED:
			RETURN_STATIC_STRING(
					"Resetting the structured state of the application failed"
			);
		case SystemCode::STATE_OPEN_CONTAINER_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to open the container"
			);
		case SystemCode::STATE_CREATE_CONTAINER_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to create the container"
			);
		case SystemCode::STATE_DELETE_CONTAINER_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to delete the container"
			);
		case SystemCode::STATE_READ_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to read the setting"
			);
		case SystemCode::STATE_WRITE_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to write the setting"
			);
		case SystemCode::STATE_DELETE_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to delete the setting"
			);
		case SystemCode::STATE_QUERY_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to query the setting"
			);
		case SystemCode::STATE_READ_COMPOSITE_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to read the composite setting"
			);
		case SystemCode::STATE_WRITE_COMPOSITE_SETTING_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to write the composite setting"
			);
		case SystemCode::STATE_ENUMERATE_CONTAINER_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to enumerate the containers"
			);
		case SystemCode::STATE_ENUMERATE_SETTINGS_FAILED:
			RETURN_STATIC_STRING(
					"State Manager failed to enumerate the settings"
			);
		case SystemCode::STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The size of the state manager composite setting value has exceeded the limit"
			);
		case SystemCode::STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The size of the state manager setting value has exceeded the limit"
			);
		case SystemCode::STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The length of the state manager setting name has exceeded the limit"
			);
		case SystemCode::STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The length of the state manager container name has exceeded the limit"
			);
		case SystemCode::API_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"This API cannot be used in the context of the caller's application type"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
