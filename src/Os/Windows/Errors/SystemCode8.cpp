#include <FlameIDE/../../src/Os/Windows/SystemCode8.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--9000-11999-
enum class SystemCode: decltype(::GetLastError())
{
	DNS_RCODE_FORMAT_ERROR =
#	if defined DNS_ERROR_RCODE_FORMAT_ERROR
			DNS_ERROR_RCODE_FORMAT_ERROR
#	else
			0x2329
#	endif
		// DNS server unable to interpret format.

	, DNS_RCODE_SERVER_FAILURE =
#	if defined DNS_ERROR_RCODE_SERVER_FAILURE
			DNS_ERROR_RCODE_SERVER_FAILURE
#	else
			0x232A
#	endif
		// DNS server failure.

	, DNS_RCODE_NAME_ERROR =
#	if defined DNS_ERROR_RCODE_NAME_ERROR
			DNS_ERROR_RCODE_NAME_ERROR
#	else
			0x232B
#	endif
		// DNS name does not exist.

	, DNS_RCODE_NOT_IMPLEMENTED =
#	if defined DNS_ERROR_RCODE_NOT_IMPLEMENTED
			DNS_ERROR_RCODE_NOT_IMPLEMENTED
#	else
			0x232C
#	endif
		// DNS request not supported by name server.

	, DNS_RCODE_REFUSED =
#	if defined DNS_ERROR_RCODE_REFUSED
			DNS_ERROR_RCODE_REFUSED
#	else
			0x232D
#	endif
		// DNS operation refused.

	, DNS_RCODE_YXDOMAIN =
#	if defined DNS_ERROR_RCODE_YXDOMAIN
			DNS_ERROR_RCODE_YXDOMAIN
#	else
			0x232E
#	endif
		// DNS name that ought not exist, does exist.

	, DNS_RCODE_YXRRSET =
#	if defined DNS_ERROR_RCODE_YXRRSET
			DNS_ERROR_RCODE_YXRRSET
#	else
			0x232F
#	endif
		// DNS RR set that ought not exist, does exist.

	, DNS_RCODE_NXRRSET =
#	if defined DNS_ERROR_RCODE_NXRRSET
			DNS_ERROR_RCODE_NXRRSET
#	else
			0x2330
#	endif
		// DNS RR set that ought to exist, does not exist.

	, DNS_RCODE_NOTAUTH =
#	if defined DNS_ERROR_RCODE_NOTAUTH
			DNS_ERROR_RCODE_NOTAUTH
#	else
			0x2331
#	endif
		// DNS server not authoritative for zone.

	, DNS_RCODE_NOTZONE =
#	if defined DNS_ERROR_RCODE_NOTZONE
			DNS_ERROR_RCODE_NOTZONE
#	else
			0x2332
#	endif
		// DNS name in update or prereq is not in zone.

	, DNS_RCODE_BADSIG =
#	if defined DNS_ERROR_RCODE_BADSIG
			DNS_ERROR_RCODE_BADSIG
#	else
			0x2338
#	endif
		// DNS signature failed to verify.

	, DNS_RCODE_BADKEY =
#	if defined DNS_ERROR_RCODE_BADKEY
			DNS_ERROR_RCODE_BADKEY
#	else
			0x2339
#	endif
		// DNS bad key.

	, DNS_RCODE_BADTIME =
#	if defined DNS_ERROR_RCODE_BADTIME
			DNS_ERROR_RCODE_BADTIME
#	else
			0x233A
#	endif
		// DNS signature validity expired.

	, DNS_KEYMASTER_REQUIRED =
#	if defined DNS_ERROR_KEYMASTER_REQUIRED
			DNS_ERROR_KEYMASTER_REQUIRED
#	else
			0x238D
#	endif
		// Only the DNS server acting as the key master for the zone may perform this operation.

	, DNS_NOT_ALLOWED_ON_SIGNED_ZONE =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE
			DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE
#	else
			0x238E
#	endif
		// This operation is not allowed on a zone that is signed or has signing keys.

	, DNS_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1 =
#	if defined DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1
			DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1
#	else
			0x238F
#	endif
		// NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC. This value was also named DNS_ERROR_INVALID_NSEC3_PARAMETERS

	, DNS_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS =
#	if defined DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS
			DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS
#	else
			0x2390
#	endif
		// The zone does not have enough signing keys. There must be at least one key signing key (KSK) and at least one zone signing key (ZSK).

	, DNS_UNSUPPORTED_ALGORITHM =
#	if defined DNS_ERROR_UNSUPPORTED_ALGORITHM
			DNS_ERROR_UNSUPPORTED_ALGORITHM
#	else
			0x2391
#	endif
		// The specified algorithm is not supported.

	, DNS_INVALID_KEY_SIZE =
#	if defined DNS_ERROR_INVALID_KEY_SIZE
			DNS_ERROR_INVALID_KEY_SIZE
#	else
			0x2392
#	endif
		// The specified key size is not supported.

	, DNS_SIGNING_KEY_NOT_ACCESSIBLE =
#	if defined DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE
			DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE
#	else
			0x2393
#	endif
		// One or more of the signing keys for a zone are not accessible to the DNS server. Zone signing will not be operational until this error is resolved.

	, DNS_KSP_DOES_NOT_SUPPORT_PROTECTION =
#	if defined DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION
			DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION
#	else
			0x2394
#	endif
		// The specified key storage provider does not support DPAPI++ data protection. Zone signing will not be operational until this error is resolved.

	, DNS_UNEXPECTED_DATA_PROTECTION_ERROR =
#	if defined DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR
			DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR
#	else
			0x2395
#	endif
		// An unexpected DPAPI++ error was encountered. Zone signing will not be operational until this error is resolved.

	, DNS_UNEXPECTED_CNG_ERROR =
#	if defined DNS_ERROR_UNEXPECTED_CNG_ERROR
			DNS_ERROR_UNEXPECTED_CNG_ERROR
#	else
			0x2396
#	endif
		// An unexpected crypto error was encountered. Zone signing may not be operational until this error is resolved.

	, DNS_UNKNOWN_SIGNING_PARAMETER_VERSION =
#	if defined DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION
			DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION
#	else
			0x2397
#	endif
		// The DNS server encountered a signing key with an unknown version. Zone signing will not be operational until this error is resolved.

	, DNS_KSP_NOT_ACCESSIBLE =
#	if defined DNS_ERROR_KSP_NOT_ACCESSIBLE
			DNS_ERROR_KSP_NOT_ACCESSIBLE
#	else
			0x2398
#	endif
		// The specified key service provider cannot be opened by the DNS server.

	, DNS_TOO_MANY_SKDS =
#	if defined DNS_ERROR_TOO_MANY_SKDS
			DNS_ERROR_TOO_MANY_SKDS
#	else
			0x2399
#	endif
		// The DNS server cannot accept any more signing keys with the specified algorithm and KSK flag value for this zone.

	, DNS_INVALID_ROLLOVER_PERIOD =
#	if defined DNS_ERROR_INVALID_ROLLOVER_PERIOD
			DNS_ERROR_INVALID_ROLLOVER_PERIOD
#	else
			0x239A
#	endif
		// The specified rollover period is invalid.

	, DNS_INVALID_INITIAL_ROLLOVER_OFFSET =
#	if defined DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET
			DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET
#	else
			0x239B
#	endif
		// The specified initial rollover offset is invalid.

	, DNS_ROLLOVER_IN_PROGRESS =
#	if defined DNS_ERROR_ROLLOVER_IN_PROGRESS
			DNS_ERROR_ROLLOVER_IN_PROGRESS
#	else
			0x239C
#	endif
		// The specified signing key is already in process of rolling over keys.

	, DNS_STANDBY_KEY_NOT_PRESENT =
#	if defined DNS_ERROR_STANDBY_KEY_NOT_PRESENT
			DNS_ERROR_STANDBY_KEY_NOT_PRESENT
#	else
			0x239D
#	endif
		// The specified signing key does not have a standby key to revoke.

	, DNS_NOT_ALLOWED_ON_ZSK =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_ZSK
			DNS_ERROR_NOT_ALLOWED_ON_ZSK
#	else
			0x239E
#	endif
		// This operation is not allowed on a zone signing key (ZSK).

	, DNS_NOT_ALLOWED_ON_ACTIVE_SKD =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD
			DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD
#	else
			0x239F
#	endif
		// This operation is not allowed on an active signing key.

	, DNS_ROLLOVER_ALREADY_QUEUED =
#	if defined DNS_ERROR_ROLLOVER_ALREADY_QUEUED
			DNS_ERROR_ROLLOVER_ALREADY_QUEUED
#	else
			0x23A0
#	endif
		// The specified signing key is already queued for rollover.

	, DNS_NOT_ALLOWED_ON_UNSIGNED_ZONE =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE
			DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE
#	else
			0x23A1
#	endif
		// This operation is not allowed on an unsigned zone.

	, DNS_BAD_KEYMASTER =
#	if defined DNS_ERROR_BAD_KEYMASTER
			DNS_ERROR_BAD_KEYMASTER
#	else
			0x23A2
#	endif
		// This operation could not be completed because the DNS server listed as the current key master for this zone is down or misconfigured. Resolve the problem on the current key master for this zone or use another DNS server to seize the key master role.

	, DNS_INVALID_SIGNATURE_VALIDITY_PERIOD =
#	if defined DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD
			DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD
#	else
			0x23A3
#	endif
		// The specified signature validity period is invalid.

	, DNS_INVALID_NSEC3_ITERATION_COUNT =
#	if defined DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT
			DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT
#	else
			0x23A4
#	endif
		// The specified NSEC3 iteration count is higher than allowed by the minimum key length used in the zone.

	, DNS_DNSSEC_IS_DISABLED =
#	if defined DNS_ERROR_DNSSEC_IS_DISABLED
			DNS_ERROR_DNSSEC_IS_DISABLED
#	else
			0x23A5
#	endif
		// This operation could not be completed because the DNS server has been configured with DNSSEC features disabled. Enable DNSSEC on the DNS server.

	, DNS_INVALID_XML =
#	if defined DNS_ERROR_INVALID_XML
			DNS_ERROR_INVALID_XML
#	else
			0x23A6
#	endif
		// This operation could not be completed because the XML stream received is empty or syntactically invalid.

	, DNS_NO_VALID_TRUST_ANCHORS =
#	if defined DNS_ERROR_NO_VALID_TRUST_ANCHORS
			DNS_ERROR_NO_VALID_TRUST_ANCHORS
#	else
			0x23A7
#	endif
		// This operation completed, but no trust anchors were added because all of the trust anchors received were either invalid, unsupported, expired, or would not become valid in less than 30 days.

	, DNS_ROLLOVER_NOT_POKEABLE =
#	if defined DNS_ERROR_ROLLOVER_NOT_POKEABLE
			DNS_ERROR_ROLLOVER_NOT_POKEABLE
#	else
			0x23A8
#	endif
		// The specified signing key is not waiting for parental DS update.

	, DNS_NSEC3_NAME_COLLISION =
#	if defined DNS_ERROR_NSEC3_NAME_COLLISION
			DNS_ERROR_NSEC3_NAME_COLLISION
#	else
			0x23A9
#	endif
		// Hash collision detected during NSEC3 signing. Specify a different user-provided salt, or use a randomly generated salt, and attempt to sign the zone again.

	, DNS_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1 =
#	if defined DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1
			DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1
#	else
			0x23AA
#	endif
		// NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC3.

	, INFO_DNS_NO_RECORDS =
#	if defined DNS_INFO_NO_RECORDS
			DNS_INFO_NO_RECORDS
#	else
			0x251D
#	endif
		// No records found for given DNS query.

	, DNS_BAD_PACKET =
#	if defined DNS_ERROR_BAD_PACKET
			DNS_ERROR_BAD_PACKET
#	else
			0x251E
#	endif
		// Bad DNS packet.

	, DNS_NO_PACKET =
#	if defined DNS_ERROR_NO_PACKET
			DNS_ERROR_NO_PACKET
#	else
			0x251F
#	endif
		// No DNS packet.

	, DNS_RCODE =
#	if defined DNS_ERROR_RCODE
			DNS_ERROR_RCODE
#	else
			0x2520
#	endif
		// DNS error, check rcode.

	, DNS_UNSECURE_PACKET =
#	if defined DNS_ERROR_UNSECURE_PACKET
			DNS_ERROR_UNSECURE_PACKET
#	else
			0x2521
#	endif
		// Unsecured DNS packet.

	, REQUEST_PENDING =
#	if defined DNS_REQUEST_PENDING
			DNS_REQUEST_PENDING
#	else
			0x2522
#	endif
		// DNS query request is pending.

	, DNS_INVALID_TYPE =
#	if defined DNS_ERROR_INVALID_TYPE
			DNS_ERROR_INVALID_TYPE
#	else
			0x254F
#	endif
		// Invalid DNS type.

	, DNS_INVALID_IP_ADDRESS =
#	if defined DNS_ERROR_INVALID_IP_ADDRESS
			DNS_ERROR_INVALID_IP_ADDRESS
#	else
			0x2550
#	endif
		// Invalid IP address.

	, DNS_INVALID_PROPERTY =
#	if defined DNS_ERROR_INVALID_PROPERTY
			DNS_ERROR_INVALID_PROPERTY
#	else
			0x2551
#	endif
		// Invalid property.

	, DNS_TRY_AGAIN_LATER =
#	if defined DNS_ERROR_TRY_AGAIN_LATER
			DNS_ERROR_TRY_AGAIN_LATER
#	else
			0x2552
#	endif
		// Try DNS operation again later.

	, DNS_NOT_UNIQUE =
#	if defined DNS_ERROR_NOT_UNIQUE
			DNS_ERROR_NOT_UNIQUE
#	else
			0x2553
#	endif
		// Record for given name and type is not unique.

	, DNS_NON_RFC_NAME =
#	if defined DNS_ERROR_NON_RFC_NAME
			DNS_ERROR_NON_RFC_NAME
#	else
			0x2554
#	endif
		// DNS name does not comply with RFC specifications.

	, STATUS_FQDN =
#	if defined DNS_STATUS_FQDN
			DNS_STATUS_FQDN
#	else
			0x2555
#	endif
		// DNS name is a fully-qualified DNS name.

	, STATUS_DOTTED_NAME =
#	if defined DNS_STATUS_DOTTED_NAME
			DNS_STATUS_DOTTED_NAME
#	else
			0x2556
#	endif
		// DNS name is dotted (multi-label).

	, STATUS_SINGLE_PART_NAME =
#	if defined DNS_STATUS_SINGLE_PART_NAME
			DNS_STATUS_SINGLE_PART_NAME
#	else
			0x2557
#	endif
		// DNS name is a single-part name.

	, DNS_INVALID_NAME_CHAR =
#	if defined DNS_ERROR_INVALID_NAME_CHAR
			DNS_ERROR_INVALID_NAME_CHAR
#	else
			0x2558
#	endif
		// DNS name contains an invalid character.

	, DNS_NUMERIC_NAME =
#	if defined DNS_ERROR_NUMERIC_NAME
			DNS_ERROR_NUMERIC_NAME
#	else
			0x2559
#	endif
		// DNS name is entirely numeric.

	, DNS_NOT_ALLOWED_ON_ROOT_SERVER =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER
			DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER
#	else
			0x255A
#	endif
		// The operation requested is not permitted on a DNS root server.

	, DNS_NOT_ALLOWED_UNDER_DELEGATION =
#	if defined DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION
			DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION
#	else
			0x255B
#	endif
		// The record could not be created because this part of the DNS namespace has been delegated to another server.

	, DNS_CANNOT_FIND_ROOT_HINTS =
#	if defined DNS_ERROR_CANNOT_FIND_ROOT_HINTS
			DNS_ERROR_CANNOT_FIND_ROOT_HINTS
#	else
			0x255C
#	endif
		// The DNS server could not find a set of root hints.

	, DNS_INCONSISTENT_ROOT_HINTS =
#	if defined DNS_ERROR_INCONSISTENT_ROOT_HINTS
			DNS_ERROR_INCONSISTENT_ROOT_HINTS
#	else
			0x255D
#	endif
		// The DNS server found root hints but they were not consistent across all adapters.

	, DNS_DWORD_VALUE_TOO_SMALL =
#	if defined DNS_ERROR_DWORD_VALUE_TOO_SMALL
			DNS_ERROR_DWORD_VALUE_TOO_SMALL
#	else
			0x255E
#	endif
		// The specified value is too small for this parameter.

	, DNS_DWORD_VALUE_TOO_LARGE =
#	if defined DNS_ERROR_DWORD_VALUE_TOO_LARGE
			DNS_ERROR_DWORD_VALUE_TOO_LARGE
#	else
			0x255F
#	endif
		// The specified value is too large for this parameter.

	, DNS_BACKGROUND_LOADING =
#	if defined DNS_ERROR_BACKGROUND_LOADING
			DNS_ERROR_BACKGROUND_LOADING
#	else
			0x2560
#	endif
		// This operation is not allowed while the DNS server is loading zones in the background. Please try again later.

	, DNS_NOT_ALLOWED_ON_RODC =
#	if defined DNS_ERROR_NOT_ALLOWED_ON_RODC
			DNS_ERROR_NOT_ALLOWED_ON_RODC
#	else
			0x2561
#	endif
		// The operation requested is not permitted on against a DNS server running on a read-only DC.

	, DNS_NOT_ALLOWED_UNDER_DNAME =
#	if defined DNS_ERROR_NOT_ALLOWED_UNDER_DNAME
			DNS_ERROR_NOT_ALLOWED_UNDER_DNAME
#	else
			0x2562
#	endif
		// No data is allowed to exist underneath a DNAME record.

	, DNS_DELEGATION_REQUIRED =
#	if defined DNS_ERROR_DELEGATION_REQUIRED
			DNS_ERROR_DELEGATION_REQUIRED
#	else
			0x2563
#	endif
		// This operation requires credentials delegation.

	, DNS_INVALID_POLICY_TABLE =
#	if defined DNS_ERROR_INVALID_POLICY_TABLE
			DNS_ERROR_INVALID_POLICY_TABLE
#	else
			0x2564
#	endif
		// Name resolution policy table has been corrupted. DNS resolution will fail until it is fixed. Contact your network administrator.

	, DNS_ZONE_DOES_NOT_EXIST =
#	if defined DNS_ERROR_ZONE_DOES_NOT_EXIST
			DNS_ERROR_ZONE_DOES_NOT_EXIST
#	else
			0x2581
#	endif
		// DNS zone does not exist.

	, DNS_NO_ZONE_INFO =
#	if defined DNS_ERROR_NO_ZONE_INFO
			DNS_ERROR_NO_ZONE_INFO
#	else
			0x2582
#	endif
		// DNS zone information not available.

	, DNS_INVALID_ZONE_OPERATION =
#	if defined DNS_ERROR_INVALID_ZONE_OPERATION
			DNS_ERROR_INVALID_ZONE_OPERATION
#	else
			0x2583
#	endif
		// Invalid operation for DNS zone.

	, DNS_ZONE_CONFIGURATION_ERROR =
#	if defined DNS_ERROR_ZONE_CONFIGURATION_ERROR
			DNS_ERROR_ZONE_CONFIGURATION_ERROR
#	else
			0x2584
#	endif
		// Invalid DNS zone configuration.

	, DNS_ZONE_HAS_NO_SOA_RECORD =
#	if defined DNS_ERROR_ZONE_HAS_NO_SOA_RECORD
			DNS_ERROR_ZONE_HAS_NO_SOA_RECORD
#	else
			0x2585
#	endif
		// DNS zone has no start of authority (SOA) record.

	, DNS_ZONE_HAS_NO_NS_RECORDS =
#	if defined DNS_ERROR_ZONE_HAS_NO_NS_RECORDS
			DNS_ERROR_ZONE_HAS_NO_NS_RECORDS
#	else
			0x2586
#	endif
		// DNS zone has no Name Server (NS) record.

	, DNS_ZONE_LOCKED =
#	if defined DNS_ERROR_ZONE_LOCKED
			DNS_ERROR_ZONE_LOCKED
#	else
			0x2587
#	endif
		// DNS zone is locked.

	, DNS_ZONE_CREATION_FAILED =
#	if defined DNS_ERROR_ZONE_CREATION_FAILED
			DNS_ERROR_ZONE_CREATION_FAILED
#	else
			0x2588
#	endif
		// DNS zone creation failed.

	, DNS_ZONE_ALREADY_EXISTS =
#	if defined DNS_ERROR_ZONE_ALREADY_EXISTS
			DNS_ERROR_ZONE_ALREADY_EXISTS
#	else
			0x2589
#	endif
		// DNS zone already exists.

	, DNS_AUTOZONE_ALREADY_EXISTS =
#	if defined DNS_ERROR_AUTOZONE_ALREADY_EXISTS
			DNS_ERROR_AUTOZONE_ALREADY_EXISTS
#	else
			0x258A
#	endif
		// DNS automatic zone already exists.

	, DNS_INVALID_ZONE_TYPE =
#	if defined DNS_ERROR_INVALID_ZONE_TYPE
			DNS_ERROR_INVALID_ZONE_TYPE
#	else
			0x258B
#	endif
		// Invalid DNS zone type.

	, DNS_SECONDARY_REQUIRES_MASTER_IP =
#	if defined DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP
			DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP
#	else
			0x258C
#	endif
		// Secondary DNS zone requires master IP address.

	, DNS_ZONE_NOT_SECONDARY =
#	if defined DNS_ERROR_ZONE_NOT_SECONDARY
			DNS_ERROR_ZONE_NOT_SECONDARY
#	else
			0x258D
#	endif
		// DNS zone not secondary.

	, DNS_NEED_SECONDARY_ADDRESSES =
#	if defined DNS_ERROR_NEED_SECONDARY_ADDRESSES
			DNS_ERROR_NEED_SECONDARY_ADDRESSES
#	else
			0x258E
#	endif
		// Need secondary IP address.

	, DNS_WINS_INIT_FAILED =
#	if defined DNS_ERROR_WINS_INIT_FAILED
			DNS_ERROR_WINS_INIT_FAILED
#	else
			0x258F
#	endif
		// WINS initialization failed.

	, DNS_NEED_WINS_SERVERS =
#	if defined DNS_ERROR_NEED_WINS_SERVERS
			DNS_ERROR_NEED_WINS_SERVERS
#	else
			0x2590
#	endif
		// Need WINS servers.

	, DNS_NBSTAT_INIT_FAILED =
#	if defined DNS_ERROR_NBSTAT_INIT_FAILED
			DNS_ERROR_NBSTAT_INIT_FAILED
#	else
			0x2591
#	endif
		// NBTSTAT initialization call failed.

	, DNS_SOA_DELETE_INVALID =
#	if defined DNS_ERROR_SOA_DELETE_INVALID
			DNS_ERROR_SOA_DELETE_INVALID
#	else
			0x2592
#	endif
		// Invalid delete of start of authority (SOA).

	, DNS_FORWARDER_ALREADY_EXISTS =
#	if defined DNS_ERROR_FORWARDER_ALREADY_EXISTS
			DNS_ERROR_FORWARDER_ALREADY_EXISTS
#	else
			0x2593
#	endif
		// A conditional forwarding zone already exists for that name.

	, DNS_ZONE_REQUIRES_MASTER_IP =
#	if defined DNS_ERROR_ZONE_REQUIRES_MASTER_IP
			DNS_ERROR_ZONE_REQUIRES_MASTER_IP
#	else
			0x2594
#	endif
		// This zone must be configured with one or more master DNS server IP addresses.

	, DNS_ZONE_IS_SHUTDOWN =
#	if defined DNS_ERROR_ZONE_IS_SHUTDOWN
			DNS_ERROR_ZONE_IS_SHUTDOWN
#	else
			0x2595
#	endif
		// The operation cannot be performed because this zone is shut down.

	, DNS_ZONE_LOCKED_FOR_SIGNING =
#	if defined DNS_ERROR_ZONE_LOCKED_FOR_SIGNING
			DNS_ERROR_ZONE_LOCKED_FOR_SIGNING
#	else
			0x2596
#	endif
		// This operation cannot be performed because the zone is currently being signed. Please try again later.

	, DNS_PRIMARY_REQUIRES_DATAFILE =
#	if defined DNS_ERROR_PRIMARY_REQUIRES_DATAFILE
			DNS_ERROR_PRIMARY_REQUIRES_DATAFILE
#	else
			0x25B3
#	endif
		// Primary DNS zone requires datafile.

	, DNS_INVALID_DATAFILE_NAME =
#	if defined DNS_ERROR_INVALID_DATAFILE_NAME
			DNS_ERROR_INVALID_DATAFILE_NAME
#	else
			0x25B4
#	endif
		// Invalid datafile name for DNS zone.

	, DNS_DATAFILE_OPEN_FAILURE =
#	if defined DNS_ERROR_DATAFILE_OPEN_FAILURE
			DNS_ERROR_DATAFILE_OPEN_FAILURE
#	else
			0x25B5
#	endif
		// Failed to open datafile for DNS zone.

	, DNS_FILE_WRITEBACK_FAILED =
#	if defined DNS_ERROR_FILE_WRITEBACK_FAILED
			DNS_ERROR_FILE_WRITEBACK_FAILED
#	else
			0x25B6
#	endif
		// Failed to write datafile for DNS zone.

	, DNS_DATAFILE_PARSING =
#	if defined DNS_ERROR_DATAFILE_PARSING
			DNS_ERROR_DATAFILE_PARSING
#	else
			0x25B7
#	endif
		// Failure while reading datafile for DNS zone.

	, DNS_RECORD_DOES_NOT_EXIST =
#	if defined DNS_ERROR_RECORD_DOES_NOT_EXIST
			DNS_ERROR_RECORD_DOES_NOT_EXIST
#	else
			0x25E5
#	endif
		// DNS record does not exist.

	, DNS_RECORD_FORMAT =
#	if defined DNS_ERROR_RECORD_FORMAT
			DNS_ERROR_RECORD_FORMAT
#	else
			0x25E6
#	endif
		// DNS record format error.

	, DNS_NODE_CREATION_FAILED =
#	if defined DNS_ERROR_NODE_CREATION_FAILED
			DNS_ERROR_NODE_CREATION_FAILED
#	else
			0x25E7
#	endif
		// Node creation failure in DNS.

	, DNS_UNKNOWN_RECORD_TYPE =
#	if defined DNS_ERROR_UNKNOWN_RECORD_TYPE
			DNS_ERROR_UNKNOWN_RECORD_TYPE
#	else
			0x25E8
#	endif
		// Unknown DNS record type.

	, DNS_RECORD_TIMED_OUT =
#	if defined DNS_ERROR_RECORD_TIMED_OUT
			DNS_ERROR_RECORD_TIMED_OUT
#	else
			0x25E9
#	endif
		// DNS record timed out.

	, DNS_NAME_NOT_IN_ZONE =
#	if defined DNS_ERROR_NAME_NOT_IN_ZONE
			DNS_ERROR_NAME_NOT_IN_ZONE
#	else
			0x25EA
#	endif
		// Name not in DNS zone.

	, DNS_CNAME_LOOP =
#	if defined DNS_ERROR_CNAME_LOOP
			DNS_ERROR_CNAME_LOOP
#	else
			0x25EB
#	endif
		// CNAME loop detected.

	, DNS_NODE_IS_CNAME =
#	if defined DNS_ERROR_NODE_IS_CNAME
			DNS_ERROR_NODE_IS_CNAME
#	else
			0x25EC
#	endif
		// Node is a CNAME DNS record.

	, DNS_CNAME_COLLISION =
#	if defined DNS_ERROR_CNAME_COLLISION
			DNS_ERROR_CNAME_COLLISION
#	else
			0x25ED
#	endif
		// A CNAME record already exists for given name.

	, DNS_RECORD_ONLY_AT_ZONE_ROOT =
#	if defined DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT
			DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT
#	else
			0x25EE
#	endif
		// Record only at DNS zone root.

	, DNS_RECORD_ALREADY_EXISTS =
#	if defined DNS_ERROR_RECORD_ALREADY_EXISTS
			DNS_ERROR_RECORD_ALREADY_EXISTS
#	else
			0x25EF
#	endif
		// DNS record already exists.

	, DNS_SECONDARY_DATA =
#	if defined DNS_ERROR_SECONDARY_DATA
			DNS_ERROR_SECONDARY_DATA
#	else
			0x25F0
#	endif
		// Secondary DNS zone data error.

	, DNS_NO_CREATE_CACHE_DATA =
#	if defined DNS_ERROR_NO_CREATE_CACHE_DATA
			DNS_ERROR_NO_CREATE_CACHE_DATA
#	else
			0x25F1
#	endif
		// Could not create DNS cache data.

	, DNS_NAME_DOES_NOT_EXIST =
#	if defined DNS_ERROR_NAME_DOES_NOT_EXIST
			DNS_ERROR_NAME_DOES_NOT_EXIST
#	else
			0x25F2
#	endif
		// DNS name does not exist.

	, WARNING_DNS_PTR_CREATE_FAILED =
#	if defined DNS_WARNING_PTR_CREATE_FAILED
			DNS_WARNING_PTR_CREATE_FAILED
#	else
			0x25F3
#	endif
		// Could not create pointer (PTR) record.

	, WARNING_DNS_DOMAIN_UNDELETED =
#	if defined DNS_WARNING_DOMAIN_UNDELETED
			DNS_WARNING_DOMAIN_UNDELETED
#	else
			0x25F4
#	endif
		// DNS domain was undeleted.

	, DNS_DS_UNAVAILABLE =
#	if defined DNS_ERROR_DS_UNAVAILABLE
			DNS_ERROR_DS_UNAVAILABLE
#	else
			0x25F5
#	endif
		// The directory service is unavailable.

	, DNS_DS_ZONE_ALREADY_EXISTS =
#	if defined DNS_ERROR_DS_ZONE_ALREADY_EXISTS
			DNS_ERROR_DS_ZONE_ALREADY_EXISTS
#	else
			0x25F6
#	endif
		// DNS zone already exists in the directory service.

	, DNS_NO_BOOTFILE_IF_DS_ZONE =
#	if defined DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE
			DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE
#	else
			0x25F7
#	endif
		// DNS server not creating or reading the boot file for the directory service integrated DNS zone.

	, DNS_NODE_IS_DNAME =
#	if defined DNS_ERROR_NODE_IS_DNAME
			DNS_ERROR_NODE_IS_DNAME
#	else
			0x25F8
#	endif
		// Node is a DNAME DNS record.

	, DNS_DNAME_COLLISION =
#	if defined DNS_ERROR_DNAME_COLLISION
			DNS_ERROR_DNAME_COLLISION
#	else
			0x25F9
#	endif
		// A DNAME record already exists for given name.

	, DNS_ALIAS_LOOP =
#	if defined DNS_ERROR_ALIAS_LOOP
			DNS_ERROR_ALIAS_LOOP
#	else
			0x25FA
#	endif
		// An alias loop has been detected with either CNAME or DNAME records.

	, INFO_DNS_AXFR_COMPLETE =
#	if defined DNS_INFO_AXFR_COMPLETE
			DNS_INFO_AXFR_COMPLETE
#	else
			0x2617
#	endif
		// DNS AXFR (zone transfer) complete.

	, DNS_AXFR =
#	if defined DNS_ERROR_AXFR
			DNS_ERROR_AXFR
#	else
			0x2618
#	endif
		// DNS zone transfer failed.

	, INFO_DNS_ADDED_LOCAL_WINS =
#	if defined DNS_INFO_ADDED_LOCAL_WINS
			DNS_INFO_ADDED_LOCAL_WINS
#	else
			0x2619
#	endif
		// Added local WINS server.

	, STATUS_DNS_CONTINUE_NEEDED =
#	if defined DNS_STATUS_CONTINUE_NEEDED
			DNS_STATUS_CONTINUE_NEEDED
#	else
			0x2649
#	endif
		// Secure update call needs to continue update request.

	, DNS_NO_TCPIP =
#	if defined DNS_ERROR_NO_TCPIP
			DNS_ERROR_NO_TCPIP
#	else
			0x267B
#	endif
		// TCP/IP network protocol not installed.

	, DNS_NO_DNS_SERVERS =
#	if defined DNS_ERROR_NO_DNS_SERVERS
			DNS_ERROR_NO_DNS_SERVERS
#	else
			0x267C
#	endif
		// No DNS servers configured for local system.

	, DNS_DP_DOES_NOT_EXIST =
#	if defined DNS_ERROR_DP_DOES_NOT_EXIST
			DNS_ERROR_DP_DOES_NOT_EXIST
#	else
			0x26AD
#	endif
		// The specified directory partition does not exist.

	, DNS_DP_ALREADY_EXISTS =
#	if defined DNS_ERROR_DP_ALREADY_EXISTS
			DNS_ERROR_DP_ALREADY_EXISTS
#	else
			0x26AE
#	endif
		// The specified directory partition already exists.

	, DNS_DP_NOT_ENLISTED =
#	if defined DNS_ERROR_DP_NOT_ENLISTED
			DNS_ERROR_DP_NOT_ENLISTED
#	else
			0x26AF
#	endif
		// This DNS server is not enlisted in the specified directory partition.

	, DNS_DP_ALREADY_ENLISTED =
#	if defined DNS_ERROR_DP_ALREADY_ENLISTED
			DNS_ERROR_DP_ALREADY_ENLISTED
#	else
			0x26B0
#	endif
		// This DNS server is already enlisted in the specified directory partition.

	, DNS_DP_NOT_AVAILABLE =
#	if defined DNS_ERROR_DP_NOT_AVAILABLE
			DNS_ERROR_DP_NOT_AVAILABLE
#	else
			0x26B1
#	endif
		// The directory partition is not available at this time. Please wait a few minutes and try again.

	, DNS_DP_FSMO_ERROR =
#	if defined DNS_ERROR_DP_FSMO_ERROR
			DNS_ERROR_DP_FSMO_ERROR
#	else
			0x26B2
#	endif
		// The operation failed because the domain naming master FSMO role could not be reached. The domain controller holding the domain naming master FSMO role is down or unable to service the request or is not running Windows Server 2003 or later.

	/*
	WSAEINTR

		10004 (0x2714)

		A blocking operation was interrupted by a call to WSACancelBlockingCall.

	WSAEBADF

		10009 (0x2719)

		The file handle supplied is not valid.

	WSAEACCES

		10013 (0x271D)

		An attempt was made to access a socket in a way forbidden by its access permissions.

	WSAEFAULT

		10014 (0x271E)

		The system detected an invalid pointer address in attempting to use a pointer argument in a call.

	WSAEINVAL

		10022 (0x2726)

		An invalid argument was supplied.

	WSAEMFILE

		10024 (0x2728)

		Too many open sockets.

	WSAEWOULDBLOCK

		10035 (0x2733)

		A non-blocking socket operation could not be completed immediately.

	WSAEINPROGRESS

		10036 (0x2734)

		A blocking operation is currently executing.

	WSAEALREADY

		10037 (0x2735)

		An operation was attempted on a non-blocking socket that already had an operation in progress.

	WSAENOTSOCK

		10038 (0x2736)

		An operation was attempted on something that is not a socket.

	WSAEDESTADDRREQ

		10039 (0x2737)

		A required address was omitted from an operation on a socket.

	WSAEMSGSIZE

		10040 (0x2738)

		A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.

	WSAEPROTOTYPE

		10041 (0x2739)

		A protocol was specified in the socket function call that does not support the semantics of the socket type requested.

	WSAENOPROTOOPT

		10042 (0x273A)

		An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.

	WSAEPROTONOSUPPORT

		10043 (0x273B)

		The requested protocol has not been configured into the system, or no implementation for it exists.

	WSAESOCKTNOSUPPORT

		10044 (0x273C)

		The support for the specified socket type does not exist in this address family.

	WSAEOPNOTSUPP

		10045 (0x273D)

		The attempted operation is not supported for the type of object referenced.

	WSAEPFNOSUPPORT

		10046 (0x273E)

		The protocol family has not been configured into the system or no implementation for it exists.

	WSAEAFNOSUPPORT

		10047 (0x273F)

		An address incompatible with the requested protocol was used.

	WSAEADDRINUSE

		10048 (0x2740)

		Only one usage of each socket address (protocol/network address/port) is normally permitted.

	WSAEADDRNOTAVAIL

		10049 (0x2741)

		The requested address is not valid in its context.

	WSAENETDOWN

		10050 (0x2742)

		A socket operation encountered a dead network.

	WSAENETUNREACH

		10051 (0x2743)

		A socket operation was attempted to an unreachable network.

	WSAENETRESET

		10052 (0x2744)

		The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.

	WSAECONNABORTED

		10053 (0x2745)

		An established connection was aborted by the software in your host machine.

	WSAECONNRESET

		10054 (0x2746)

		An existing connection was forcibly closed by the remote host.

	WSAENOBUFS

		10055 (0x2747)

		An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.

	WSAEISCONN

		10056 (0x2748)

		A connect request was made on an already connected socket.

	WSAENOTCONN

		10057 (0x2749)

		A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.

	WSAESHUTDOWN

		10058 (0x274A)

		A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.

	WSAETOOMANYREFS

		10059 (0x274B)

		Too many references to some kernel object.

	WSAETIMEDOUT

		10060 (0x274C)

		A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.

	WSAECONNREFUSED

		10061 (0x274D)

		No connection could be made because the target machine actively refused it.

	WSAELOOP

		10062 (0x274E)

		Cannot translate name.

	WSAENAMETOOLONG

		10063 (0x274F)

		Name component or name was too long.

	WSAEHOSTDOWN

		10064 (0x2750)

		A socket operation failed because the destination host was down.

	WSAEHOSTUNREACH

		10065 (0x2751)

		A socket operation was attempted to an unreachable host.

	WSAENOTEMPTY

		10066 (0x2752)

		Cannot remove a directory that is not empty.

	WSAEPROCLIM

		10067 (0x2753)

		A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.

	WSAEUSERS

		10068 (0x2754)

		Ran out of quota.

	WSAEDQUOT

		10069 (0x2755)

		Ran out of disk quota.

	WSAESTALE

		10070 (0x2756)

		File handle reference is no longer available.

	WSAEREMOTE

		10071 (0x2757)

		Item is not available locally.

	WSASYSNOTREADY

		10091 (0x276B)

		WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.

	WSAVERNOTSUPPORTED

		10092 (0x276C)

		The Windows Sockets version requested is not supported.

	WSANOTINITIALISED

		10093 (0x276D)

		Either the application has not called WSAStartup, or WSAStartup failed.

	WSAEDISCON

		10101 (0x2775)

		Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.

	WSAENOMORE

		10102 (0x2776)

		No more results can be returned by WSALookupServiceNext.

	WSAECANCELLED

		10103 (0x2777)

		A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.

	WSAEINVALIDPROCTABLE

		10104 (0x2778)

		The procedure call table is invalid.

	WSAEINVALIDPROVIDER

		10105 (0x2779)

		The requested service provider is invalid.

	WSAEPROVIDERFAILEDINIT

		10106 (0x277A)

		The requested service provider could not be loaded or initialized.

	WSASYSCALLFAILURE

		10107 (0x277B)

		A system call has failed.

	WSASERVICE_NOT_FOUND

		10108 (0x277C)

		No such service is known. The service cannot be found in the specified name space.

	WSATYPE_NOT_FOUND

		10109 (0x277D)

		The specified class was not found.

	WSA_E_NO_MORE

		10110 (0x277E)

		No more results can be returned by WSALookupServiceNext.

	WSA_E_CANCELLED

		10111 (0x277F)

		A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.

	WSAEREFUSED

		10112 (0x2780)

		A database query failed because it was actively refused.

	WSAHOST_NOT_FOUND

		11001 (0x2AF9)

		No such host is known.

	WSATRY_AGAIN

		11002 (0x2AFA)

		This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.

	WSANO_RECOVERY

		11003 (0x2AFB)

		A non-recoverable error occurred during a database lookup.

	WSANO_DATA

		11004 (0x2AFC)

		The requested name is valid, but no data of the requested type was found.

	WSA_QOS_RECEIVERS

		11005 (0x2AFD)

		At least one reserve has arrived.

	WSA_QOS_SENDERS

		11006 (0x2AFE)

		At least one path has arrived.

	WSA_QOS_NO_SENDERS

		11007 (0x2AFF)

		There are no senders.

	WSA_QOS_NO_RECEIVERS

		11008 (0x2B00)

		There are no receivers.

	WSA_QOS_REQUEST_CONFIRMED

		11009 (0x2B01)

		Reserve has been confirmed.

	WSA_QOS_ADMISSION_FAILURE

		11010 (0x2B02)

		Error due to lack of resources.

	WSA_QOS_POLICY_FAILURE

		11011 (0x2B03)

		Rejected for administrative reasons - bad credentials.

	WSA_QOS_BAD_STYLE

		11012 (0x2B04)

		Unknown or conflicting style.

	WSA_QOS_BAD_OBJECT

		11013 (0x2B05)

		Problem with some part of the filterspec or providerspecific buffer in general.

	WSA_QOS_TRAFFIC_CTRL_ERROR

		11014 (0x2B06)

		Problem with some part of the flowspec.

	WSA_QOS_GENERIC_ERROR

		11015 (0x2B07)

		General QOS error.

	WSA_QOS_ESERVICETYPE

		11016 (0x2B08)

		An invalid or unrecognized service type was found in the flowspec.

	WSA_QOS_EFLOWSPEC

		11017 (0x2B09)

		An invalid or inconsistent flowspec was found in the QOS structure.

	WSA_QOS_EPROVSPECBUF

		11018 (0x2B0A)

		Invalid QOS provider-specific buffer.

	WSA_QOS_EFILTERSTYLE

		11019 (0x2B0B)

		An invalid QOS filter style was used.

	WSA_QOS_EFILTERTYPE

		11020 (0x2B0C)

		An invalid QOS filter type was used.

	WSA_QOS_EFILTERCOUNT

		11021 (0x2B0D)

		An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.

	WSA_QOS_EOBJLENGTH

		11022 (0x2B0E)

		An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.

	WSA_QOS_EFLOWCOUNT

		11023 (0x2B0F)

		An incorrect number of flow descriptors was specified in the QOS structure.

	WSA_QOS_EUNKOWNPSOBJ

		11024 (0x2B10)

		An unrecognized object was found in the QOS provider-specific buffer.

	WSA_QOS_EPOLICYOBJ

		11025 (0x2B11)

		An invalid policy object was found in the QOS provider-specific buffer.

	WSA_QOS_EFLOWDESC

		11026 (0x2B12)

		An invalid QOS flow descriptor was found in the flow descriptor list.

	WSA_QOS_EPSFLOWSPEC

		11027 (0x2B13)

		An invalid or inconsistent flowspec was found in the QOS provider specific buffer.

	WSA_QOS_EPSFILTERSPEC

		11028 (0x2B14)

		An invalid FILTERSPEC was found in the QOS provider-specific buffer.

	WSA_QOS_ESDMODEOBJ

		11029 (0x2B15)

		An invalid shape discard mode object was found in the QOS provider specific buffer.

	WSA_QOS_ESHAPERATEOBJ

		11030 (0x2B16)

		An invalid shaping rate object was found in the QOS provider-specific buffer.

	WSA_QOS_RESERVED_PETYPE

		11031 (0x2B17)

		A reserved policy element was found in the QOS provider-specific buffer.

	WSA_SECURE_HOST_NOT_FOUND

		11032 (0x2B18)

		No such host is known securely.

	WSA_IPSEC_NAME_POLICY_ERROR

		11033 (0x2B19)

		Name based IPSEC policy could not be added.
	*/
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString8(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)

	{
		case SystemCode::DNS_RCODE_FORMAT_ERROR:
			RETURN_STATIC_STRING(
					"DNS server unable to interpret format"
			);
		case SystemCode::DNS_RCODE_SERVER_FAILURE:
			RETURN_STATIC_STRING(
					"DNS server failure"
			);
		case SystemCode::DNS_RCODE_NAME_ERROR:
			RETURN_STATIC_STRING(
					"DNS name does not exist"
			);
		case SystemCode::DNS_RCODE_NOT_IMPLEMENTED:
			RETURN_STATIC_STRING(
					"DNS request not supported by name server"
			);
		case SystemCode::DNS_RCODE_REFUSED:
			RETURN_STATIC_STRING(
					"DNS operation refused"
			);
		case SystemCode::DNS_RCODE_YXDOMAIN:
			RETURN_STATIC_STRING(
					"DNS name that ought not exist, does exist"
			);
		case SystemCode::DNS_RCODE_YXRRSET:
			RETURN_STATIC_STRING(
					"DNS RR set that ought not exist, does exist"
			);
		case SystemCode::DNS_RCODE_NXRRSET:
			RETURN_STATIC_STRING(
					"DNS RR set that ought to exist, does not exist"
			);
		case SystemCode::DNS_RCODE_NOTAUTH:
			RETURN_STATIC_STRING(
					"DNS server not authoritative for zone"
			);
		case SystemCode::DNS_RCODE_NOTZONE:
			RETURN_STATIC_STRING(
					"DNS name in update or prereq is not in zone"
			);
		case SystemCode::DNS_RCODE_BADSIG:
			RETURN_STATIC_STRING(
					"DNS signature failed to verify"
			);
		case SystemCode::DNS_RCODE_BADKEY:
			RETURN_STATIC_STRING(
					"DNS bad key"
			);
		case SystemCode::DNS_RCODE_BADTIME:
			RETURN_STATIC_STRING(
					"DNS signature validity expired"
			);
		case SystemCode::DNS_KEYMASTER_REQUIRED:
			RETURN_STATIC_STRING(
					"Only the DNS server acting as the key master for the zone may perform this"
					" operation"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_SIGNED_ZONE:
			RETURN_STATIC_STRING(
					"This operation is not allowed on a zone that is signed or has signing keys"
			);
		case SystemCode::DNS_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1:
			RETURN_STATIC_STRING(
					"NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different"
					" algorithm or use NSEC. This value was also named"
					" DNS_ERROR_INVALID_NSEC3_PARAMETER"
			);
		case SystemCode::DNS_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS:
			RETURN_STATIC_STRING(
					"The zone does not have enough signing keys. There must be at least one key"
					" signing key (KSK) and at least one zone signing key (ZSK)"
			);
		case SystemCode::DNS_UNSUPPORTED_ALGORITHM:
			RETURN_STATIC_STRING(
					"The specified algorithm is not supported"
			);
		case SystemCode::DNS_INVALID_KEY_SIZE:
			RETURN_STATIC_STRING(
					"The specified key size is not supported"
			);
		case SystemCode::DNS_SIGNING_KEY_NOT_ACCESSIBLE:
			RETURN_STATIC_STRING(
					"One or more of the signing keys for a zone are not accessible to the DNS"
					" server. Zone signing will not be operational until this error is resolved"
			);
		case SystemCode::DNS_KSP_DOES_NOT_SUPPORT_PROTECTION:
			RETURN_STATIC_STRING(
					"The specified key storage provider does not support DPAPI++ data protection."
					" Zone signing will not be operational until this error is resolved"
			);
		case SystemCode::DNS_UNEXPECTED_DATA_PROTECTION_ERROR:
			RETURN_STATIC_STRING(
					"An unexpected DPAPI++ error was encountered. Zone signing will not be"
					" operational until this error is resolved"
			);
		case SystemCode::DNS_UNEXPECTED_CNG_ERROR:
			RETURN_STATIC_STRING(
					"An unexpected crypto error was encountered. Zone signing may not be"
					" operational until this error is resolved"
			);
		case SystemCode::DNS_UNKNOWN_SIGNING_PARAMETER_VERSION:
			RETURN_STATIC_STRING(
					"The DNS server encountered a signing key with an unknown version. Zone signing"
					" will not be operational until this error is resolved"
			);
		case SystemCode::DNS_KSP_NOT_ACCESSIBLE:
			RETURN_STATIC_STRING(
					"The specified key service provider cannot be opened by the DNS server"
			);
		case SystemCode::DNS_TOO_MANY_SKDS:
			RETURN_STATIC_STRING(
					"The DNS server cannot accept any more signing keys with the specified"
					" algorithm and KSK flag value for this zone"
			);
		case SystemCode::DNS_INVALID_ROLLOVER_PERIOD:
			RETURN_STATIC_STRING(
					"The specified rollover period is invalid"
			);
		case SystemCode::DNS_INVALID_INITIAL_ROLLOVER_OFFSET:
			RETURN_STATIC_STRING(
					"The specified initial rollover offset is invalid"
			);
		case SystemCode::DNS_ROLLOVER_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The specified signing key is already in process of rolling over keys"
			);
		case SystemCode::DNS_STANDBY_KEY_NOT_PRESENT:
			RETURN_STATIC_STRING(
					"The specified signing key does not have a standby key to revoke"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_ZSK:
			RETURN_STATIC_STRING(
					"This operation is not allowed on a zone signing key (ZSK)"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_ACTIVE_SKD:
			RETURN_STATIC_STRING(
					"This operation is not allowed on an active signing key"
			);
		case SystemCode::DNS_ROLLOVER_ALREADY_QUEUED:
			RETURN_STATIC_STRING(
					"The specified signing key is already queued for rollover"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_UNSIGNED_ZONE:
			RETURN_STATIC_STRING(
					"This operation is not allowed on an unsigned zone"
			);
		case SystemCode::DNS_BAD_KEYMASTER:
			RETURN_STATIC_STRING(
					"This operation could not be completed because the DNS server listed as the"
					" current key master for this zone is down or misconfigured. Resolve the"
					" problem on the current key master for this zone or use another DNS server to"
					" seize the key master role"
			);
		case SystemCode::DNS_INVALID_SIGNATURE_VALIDITY_PERIOD:
			RETURN_STATIC_STRING(
					"The specified signature validity period is invalid"
			);
		case SystemCode::DNS_INVALID_NSEC3_ITERATION_COUNT:
			RETURN_STATIC_STRING(
					"The specified NSEC3 iteration count is higher than allowed by the minimum key"
					" length used in the zone"
			);
		case SystemCode::DNS_DNSSEC_IS_DISABLED:
			RETURN_STATIC_STRING(
					"This operation could not be completed because the DNS server has been"
					" configured with DNSSEC features disabled. Enable DNSSEC on the DNS server"
			);
		case SystemCode::DNS_INVALID_XML:
			RETURN_STATIC_STRING(
					"This operation could not be completed because the XML stream received is empty"
					" or syntactically invalid"
			);
		case SystemCode::DNS_NO_VALID_TRUST_ANCHORS:
			RETURN_STATIC_STRING(
					"This operation completed, but no trust anchors were added because all of the"
					" trust anchors received were either invalid, unsupported, expired, or would"
					" not become valid in less than 30 days"
			);
		case SystemCode::DNS_ROLLOVER_NOT_POKEABLE:
			RETURN_STATIC_STRING(
					"The specified signing key is not waiting for parental DS update"
			);
		case SystemCode::DNS_NSEC3_NAME_COLLISION:
			RETURN_STATIC_STRING(
					"Hash collision detected during NSEC3 signing. Specify a different"
					" user-provided salt, or use a randomly generated salt, and attempt to sign the"
					" zone again"
			);
		case SystemCode::DNS_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1:
			RETURN_STATIC_STRING(
					"NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different"
					" algorithm or use NSEC3"
			);
		case SystemCode::INFO_DNS_NO_RECORDS:
			RETURN_STATIC_STRING(
					"No records found for given DNS query"
			);
		case SystemCode::DNS_BAD_PACKET:
			RETURN_STATIC_STRING(
					"Bad DNS packet"
			);
		case SystemCode::DNS_NO_PACKET:
			RETURN_STATIC_STRING(
					"No DNS packet"
			);
		case SystemCode::DNS_RCODE:
			RETURN_STATIC_STRING(
					"DNS error, check rcode"
			);
		case SystemCode::DNS_UNSECURE_PACKET:
			RETURN_STATIC_STRING(
					"Unsecured DNS packet"
			);
		case SystemCode::REQUEST_PENDING:
			RETURN_STATIC_STRING(
					"DNS query request is pending"
			);
		case SystemCode::DNS_INVALID_TYPE:
			RETURN_STATIC_STRING(
					"Invalid DNS type"
			);
		case SystemCode::DNS_INVALID_IP_ADDRESS:
			RETURN_STATIC_STRING(
					"Invalid IP address"
			);
		case SystemCode::DNS_INVALID_PROPERTY:
			RETURN_STATIC_STRING(
					"Invalid property"
			);
		case SystemCode::DNS_TRY_AGAIN_LATER:
			RETURN_STATIC_STRING(
					"Try DNS operation again later"
			);
		case SystemCode::DNS_NOT_UNIQUE:
			RETURN_STATIC_STRING(
					"Record for given name and type is not unique"
			);
		case SystemCode::DNS_NON_RFC_NAME:
			RETURN_STATIC_STRING(
					"DNS name does not comply with RFC specifications"
			);
		case SystemCode::STATUS_FQDN:
			RETURN_STATIC_STRING(
					"DNS name is a fully-qualified DNS name"
			);
		case SystemCode::STATUS_DOTTED_NAME:
			RETURN_STATIC_STRING(
					"DNS name is dotted (multi-label)"
			);
		case SystemCode::STATUS_SINGLE_PART_NAME:
			RETURN_STATIC_STRING(
					"DNS name is a single-part name"
			);
		case SystemCode::DNS_INVALID_NAME_CHAR:
			RETURN_STATIC_STRING(
					"DNS name contains an invalid character"
			);
		case SystemCode::DNS_NUMERIC_NAME:
			RETURN_STATIC_STRING(
					"DNS name is entirely numeric"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_ROOT_SERVER:
			RETURN_STATIC_STRING(
					"The operation requested is not permitted on a DNS root server"
			);
		case SystemCode::DNS_NOT_ALLOWED_UNDER_DELEGATION:
			RETURN_STATIC_STRING(
					"The record could not be created because this part of the DNS namespace has"
					" been delegated to another server"
			);
		case SystemCode::DNS_CANNOT_FIND_ROOT_HINTS:
			RETURN_STATIC_STRING(
					"The DNS server could not find a set of root hints"
			);
		case SystemCode::DNS_INCONSISTENT_ROOT_HINTS:
			RETURN_STATIC_STRING(
					"The DNS server found root hints but they were not consistent across all"
					" adapters"
			);
		case SystemCode::DNS_DWORD_VALUE_TOO_SMALL:
			RETURN_STATIC_STRING(
					"The specified value is too small for this parameter"
			);
		case SystemCode::DNS_DWORD_VALUE_TOO_LARGE:
			RETURN_STATIC_STRING(
					"The specified value is too large for this parameter"
			);
		case SystemCode::DNS_BACKGROUND_LOADING:
			RETURN_STATIC_STRING(
					"This operation is not allowed while the DNS server is loading zones in the"
					" background. Please try again later"
			);
		case SystemCode::DNS_NOT_ALLOWED_ON_RODC:
			RETURN_STATIC_STRING(
					"The operation requested is not permitted on against a DNS server running on a"
					" read-only DC"
			);
		case SystemCode::DNS_NOT_ALLOWED_UNDER_DNAME:
			RETURN_STATIC_STRING(
					"No data is allowed to exist underneath a DNAME record"
			);
		case SystemCode::DNS_DELEGATION_REQUIRED:
			RETURN_STATIC_STRING(
					"This operation requires credentials delegation"
			);
		case SystemCode::DNS_INVALID_POLICY_TABLE:
			RETURN_STATIC_STRING(
					"Name resolution policy table has been corrupted. DNS resolution will fail"
					" until it is fixed. Contact your network administrator"
			);
		case SystemCode::DNS_ZONE_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"DNS zone does not exist"
			);
		case SystemCode::DNS_NO_ZONE_INFO:
			RETURN_STATIC_STRING(
					"DNS zone information not available"
			);
		case SystemCode::DNS_INVALID_ZONE_OPERATION:
			RETURN_STATIC_STRING(
					"Invalid operation for DNS zone"
			);
		case SystemCode::DNS_ZONE_CONFIGURATION_ERROR:
			RETURN_STATIC_STRING(
					"Invalid DNS zone configuration"
			);
		case SystemCode::DNS_ZONE_HAS_NO_SOA_RECORD:
			RETURN_STATIC_STRING(
					"DNS zone has no start of authority (SOA) record"
			);
		case SystemCode::DNS_ZONE_HAS_NO_NS_RECORDS:
			RETURN_STATIC_STRING(
					"DNS zone has no Name Server (NS) record"
			);
		case SystemCode::DNS_ZONE_LOCKED:
			RETURN_STATIC_STRING(
					"DNS zone is locked"
			);
		case SystemCode::DNS_ZONE_CREATION_FAILED:
			RETURN_STATIC_STRING(
					"DNS zone creation failed"
			);
		case SystemCode::DNS_ZONE_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"DNS zone already exists"
			);
		case SystemCode::DNS_AUTOZONE_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"DNS automatic zone already exists"
			);
		case SystemCode::DNS_INVALID_ZONE_TYPE:
			RETURN_STATIC_STRING(
					"Invalid DNS zone type"
			);
		case SystemCode::DNS_SECONDARY_REQUIRES_MASTER_IP:
			RETURN_STATIC_STRING(
					"Secondary DNS zone requires master IP address"
			);
		case SystemCode::DNS_ZONE_NOT_SECONDARY:
			RETURN_STATIC_STRING(
					"DNS zone not secondary"
			);
		case SystemCode::DNS_NEED_SECONDARY_ADDRESSES:
			RETURN_STATIC_STRING(
					"Need secondary IP address"
			);
		case SystemCode::DNS_WINS_INIT_FAILED:
			RETURN_STATIC_STRING(
					"WINS initialization failed"
			);
		case SystemCode::DNS_NEED_WINS_SERVERS:
			RETURN_STATIC_STRING(
					"Need WINS servers"
			);
		case SystemCode::DNS_NBSTAT_INIT_FAILED:
			RETURN_STATIC_STRING(
					"NBTSTAT initialization call failed"
			);
		case SystemCode::DNS_SOA_DELETE_INVALID:
			RETURN_STATIC_STRING(
					"Invalid delete of start of authority (SOA)"
			);
		case SystemCode::DNS_FORWARDER_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"A conditional forwarding zone already exists for that name"
			);
		case SystemCode::DNS_ZONE_REQUIRES_MASTER_IP:
			RETURN_STATIC_STRING(
					"This zone must be configured with one or more master DNS server IP addresses"
			);
		case SystemCode::DNS_ZONE_IS_SHUTDOWN:
			RETURN_STATIC_STRING(
					"The operation cannot be performed because this zone is shut down"
			);
		case SystemCode::DNS_ZONE_LOCKED_FOR_SIGNING:
			RETURN_STATIC_STRING(
					"This operation cannot be performed because the zone is currently being signed."
					" Please try again later"
			);
		case SystemCode::DNS_PRIMARY_REQUIRES_DATAFILE:
			RETURN_STATIC_STRING(
					"Primary DNS zone requires datafile"
			);
		case SystemCode::DNS_INVALID_DATAFILE_NAME:
			RETURN_STATIC_STRING(
					"Invalid datafile name for DNS zone"
			);
		case SystemCode::DNS_DATAFILE_OPEN_FAILURE:
			RETURN_STATIC_STRING(
					"Failed to open datafile for DNS zone"
			);
		case SystemCode::DNS_FILE_WRITEBACK_FAILED:
			RETURN_STATIC_STRING(
					"Failed to write datafile for DNS zone"
			);
		case SystemCode::DNS_DATAFILE_PARSING:
			RETURN_STATIC_STRING(
					"Failure while reading datafile for DNS zone"
			);
		case SystemCode::DNS_RECORD_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"DNS record does not exist"
			);
		case SystemCode::DNS_RECORD_FORMAT:
			RETURN_STATIC_STRING(
					"DNS record format error"
			);
		case SystemCode::DNS_NODE_CREATION_FAILED:
			RETURN_STATIC_STRING(
					"Node creation failure in DNS"
			);
		case SystemCode::DNS_UNKNOWN_RECORD_TYPE:
			RETURN_STATIC_STRING(
					"Unknown DNS record type"
			);
		case SystemCode::DNS_RECORD_TIMED_OUT:
			RETURN_STATIC_STRING(
					"DNS record timed out"
			);
		case SystemCode::DNS_NAME_NOT_IN_ZONE:
			RETURN_STATIC_STRING(
					"Name not in DNS zone"
			);
		case SystemCode::DNS_CNAME_LOOP:
			RETURN_STATIC_STRING(
					"CNAME loop detected"
			);
		case SystemCode::DNS_NODE_IS_CNAME:
			RETURN_STATIC_STRING(
					"Node is a CNAME DNS record"
			);
		case SystemCode::DNS_CNAME_COLLISION:
			RETURN_STATIC_STRING(
					"A CNAME record already exists for given name"
			);
		case SystemCode::DNS_RECORD_ONLY_AT_ZONE_ROOT:
			RETURN_STATIC_STRING(
					"Record only at DNS zone root"
			);
		case SystemCode::DNS_RECORD_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"DNS record already exists"
			);
		case SystemCode::DNS_SECONDARY_DATA:
			RETURN_STATIC_STRING(
					"Secondary DNS zone data error"
			);
		case SystemCode::DNS_NO_CREATE_CACHE_DATA:
			RETURN_STATIC_STRING(
					"Could not create DNS cache data"
			);
		case SystemCode::DNS_NAME_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"DNS name does not exist"
			);
		case SystemCode::WARNING_DNS_PTR_CREATE_FAILED:
			RETURN_STATIC_STRING(
					"Could not create pointer (PTR) record"
			);
		case SystemCode::WARNING_DNS_DOMAIN_UNDELETED:
			RETURN_STATIC_STRING(
					"DNS domain was undeleted"
			);
		case SystemCode::DNS_DS_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"The directory service is unavailable"
			);
		case SystemCode::DNS_DS_ZONE_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"DNS zone already exists in the directory service"
			);
		case SystemCode::DNS_NO_BOOTFILE_IF_DS_ZONE:
			RETURN_STATIC_STRING(
					"DNS server not creating or reading the boot file for the directory service"
					" integrated DNS zone"
			);
		case SystemCode::DNS_NODE_IS_DNAME:
			RETURN_STATIC_STRING(
					"Node is a DNAME DNS record"
			);
		case SystemCode::DNS_DNAME_COLLISION:
			RETURN_STATIC_STRING(
					"A DNAME record already exists for given name"
			);
		case SystemCode::DNS_ALIAS_LOOP:
			RETURN_STATIC_STRING(
					"An alias loop has been detected with either CNAME or DNAME records"
			);
		case SystemCode::INFO_DNS_AXFR_COMPLETE:
			RETURN_STATIC_STRING(
					"DNS AXFR (zone transfer) complete"
			);
		case SystemCode::DNS_AXFR:
			RETURN_STATIC_STRING(
					"DNS zone transfer failed"
			);
		case SystemCode::INFO_DNS_ADDED_LOCAL_WINS:
			RETURN_STATIC_STRING(
					"Added local WINS server"
			);
		case SystemCode::STATUS_DNS_CONTINUE_NEEDED:
			RETURN_STATIC_STRING(
					"Secure update call needs to continue update request"
			);
		case SystemCode::DNS_NO_TCPIP:
			RETURN_STATIC_STRING(
					"TCP/IP network protocol not installed"
			);
		case SystemCode::DNS_NO_DNS_SERVERS:
			RETURN_STATIC_STRING(
					"No DNS servers configured for local system"
			);
		case SystemCode::DNS_DP_DOES_NOT_EXIST:
			RETURN_STATIC_STRING(
					"The specified directory partition does not exist"
			);
		case SystemCode::DNS_DP_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified directory partition already exists"
			);
		case SystemCode::DNS_DP_NOT_ENLISTED:
			RETURN_STATIC_STRING(
					"This DNS server is not enlisted in the specified directory partition"
			);
		case SystemCode::DNS_DP_ALREADY_ENLISTED:
			RETURN_STATIC_STRING(
					"This DNS server is already enlisted in the specified directory partition"
			);
		case SystemCode::DNS_DP_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"The directory partition is not available at this time. Please wait a few"
					" minutes and try again"
			);
		case SystemCode::DNS_DP_FSMO_ERROR:
			RETURN_STATIC_STRING(
					"The operation failed because the domain naming master FSMO role could not be"
					" reached. The domain controller holding the domain naming master FSMO role is"
					" down or unable to service the request or is not running Windows Server 2003"
					" or later"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
