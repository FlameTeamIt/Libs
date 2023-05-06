#include <FlameIDE/../../src/Os/Windows/SystemCode7.hpp>

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

// https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--8200-8999-
enum class SystemCode: decltype(::GetLastError())
{
	DS_NOT_INSTALLED =
#	if defined ERROR_DS_NOT_INSTALLED
			ERROR_DS_NOT_INSTALLED
#	else
			0x2008
#	endif
		// An error occurred while installing the directory service. For more information, see the event log.

	, DS_MEMBERSHIP_EVALUATED_LOCALLY =
#	if defined ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY
			ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY
#	else
			0x2009
#	endif
		// The directory service evaluated group memberships locally.

	, DS_NO_ATTRIBUTE_OR_VALUE =
#	if defined ERROR_DS_NO_ATTRIBUTE_OR_VALUE
			ERROR_DS_NO_ATTRIBUTE_OR_VALUE
#	else
			0x200A
#	endif
		// The specified directory service attribute or value does not exist.

	, DS_INVALID_ATTRIBUTE_SYNTAX =
#	if defined ERROR_DS_INVALID_ATTRIBUTE_SYNTAX
			ERROR_DS_INVALID_ATTRIBUTE_SYNTAX
#	else
			0x200B
#	endif
		// The attribute syntax specified to the directory service is invalid.

	, DS_ATTRIBUTE_TYPE_UNDEFINED =
#	if defined ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED
			ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED
#	else
			0x200C
#	endif
		// The attribute type specified to the directory service is not defined.

	, DS_ATTRIBUTE_OR_VALUE_EXISTS =
#	if defined ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS
			ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS
#	else
			0x200D
#	endif
		// The specified directory service attribute or value already exists.

	, DS_BUSY =
#	if defined ERROR_DS_BUSY
			ERROR_DS_BUSY
#	else
			0x200E
#	endif
		// The directory service is busy.

	, DS_UNAVAILABLE =
#	if defined ERROR_DS_UNAVAILABLE
			ERROR_DS_UNAVAILABLE
#	else
			0x200F
#	endif
		// The directory service is unavailable.

	, DS_NO_RIDS_ALLOCATED =
#	if defined ERROR_DS_NO_RIDS_ALLOCATED
			ERROR_DS_NO_RIDS_ALLOCATED
#	else
			0x2010
#	endif
		// The directory service was unable to allocate a relative identifier.

	, DS_NO_MORE_RIDS =
#	if defined ERROR_DS_NO_MORE_RIDS
			ERROR_DS_NO_MORE_RIDS
#	else
			0x2011
#	endif
		// The directory service has exhausted the pool of relative identifiers.

	, DS_INCORRECT_ROLE_OWNER =
#	if defined ERROR_DS_INCORRECT_ROLE_OWNER
			ERROR_DS_INCORRECT_ROLE_OWNER
#	else
			0x2012
#	endif
		// The requested operation could not be performed because the directory service is not the master for that type of operation.

	, DS_RIDMGR_INIT_ERROR =
#	if defined ERROR_DS_RIDMGR_INIT_ERROR
			ERROR_DS_RIDMGR_INIT_ERROR
#	else
			0x2013
#	endif
		// The directory service was unable to initialize the subsystem that allocates relative identifiers.

	, DS_OBJ_CLASS_VIOLATION =
#	if defined ERROR_DS_OBJ_CLASS_VIOLATION
			ERROR_DS_OBJ_CLASS_VIOLATION
#	else
			0x2014
#	endif
		// The requested operation did not satisfy one or more constraints associated with the class of the object.

	, DS_CANT_ON_NON_LEAF =
#	if defined ERROR_DS_CANT_ON_NON_LEAF
			ERROR_DS_CANT_ON_NON_LEAF
#	else
			0x2015
#	endif
		// The directory service can perform the requested operation only on a leaf object.

	, DS_CANT_ON_RDN =
#	if defined ERROR_DS_CANT_ON_RDN
			ERROR_DS_CANT_ON_RDN
#	else
			0x2016
#	endif
		// The directory service cannot perform the requested operation on the RDN attribute of an object.

	, DS_CANT_MOD_OBJ_CLASS =
#	if defined ERROR_DS_CANT_MOD_OBJ_CLASS
			ERROR_DS_CANT_MOD_OBJ_CLASS
#	else
			0x2017
#	endif
		// The directory service detected an attempt to modify the object class of an object.

	, DS_CROSS_DOM_MOVE_ERROR =
#	if defined ERROR_DS_CROSS_DOM_MOVE_ERROR
			ERROR_DS_CROSS_DOM_MOVE_ERROR
#	else
			0x2018
#	endif
		// The requested cross-domain move operation could not be performed.

	, DS_GC_NOT_AVAILABLE =
#	if defined ERROR_DS_GC_NOT_AVAILABLE
			ERROR_DS_GC_NOT_AVAILABLE
#	else
			0x2019
#	endif
		// Unable to contact the global catalog server.

	, SHARED_POLICY =
#	if defined ERROR_SHARED_POLICY
			ERROR_SHARED_POLICY
#	else
			0x201A
#	endif
		// The policy object is shared and can only be modified at the root.

	, POLICY_OBJECT_NOT_FOUND =
#	if defined ERROR_POLICY_OBJECT_NOT_FOUND
			ERROR_POLICY_OBJECT_NOT_FOUND
#	else
			0x201B
#	endif
		// The policy object does not exist.

	, POLICY_ONLY_IN_DS =
#	if defined ERROR_POLICY_ONLY_IN_DS
			ERROR_POLICY_ONLY_IN_DS
#	else
			0x201C
#	endif
		// The requested policy information is only in the directory service.

	, PROMOTION_ACTIVE =
#	if defined ERROR_PROMOTION_ACTIVE
			ERROR_PROMOTION_ACTIVE
#	else
			0x201D
#	endif
		// A domain controller promotion is currently active.

	, NO_PROMOTION_ACTIVE =
#	if defined ERROR_NO_PROMOTION_ACTIVE
			ERROR_NO_PROMOTION_ACTIVE
#	else
			0x201E
#	endif
		// A domain controller promotion is not currently active.

	, DS_OPERATIONS_ERROR =
#	if defined ERROR_DS_OPERATIONS_ERROR
			ERROR_DS_OPERATIONS_ERROR
#	else
			0x2020
#	endif
		// An operations error occurred.

	, DS_PROTOCOL_ERROR =
#	if defined ERROR_DS_PROTOCOL_ERROR
			ERROR_DS_PROTOCOL_ERROR
#	else
			0x2021
#	endif
		// A protocol error occurred.

	, DS_TIMELIMIT_EXCEEDED =
#	if defined ERROR_DS_TIMELIMIT_EXCEEDED
			ERROR_DS_TIMELIMIT_EXCEEDED
#	else
			0x2022
#	endif
		// The time limit for this request was exceeded.

	, DS_SIZELIMIT_EXCEEDED =
#	if defined ERROR_DS_SIZELIMIT_EXCEEDED
			ERROR_DS_SIZELIMIT_EXCEEDED
#	else
			0x2023
#	endif
		// The size limit for this request was exceeded.

	, DS_ADMIN_LIMIT_EXCEEDED =
#	if defined ERROR_DS_ADMIN_LIMIT_EXCEEDED
			ERROR_DS_ADMIN_LIMIT_EXCEEDED
#	else
			0x2024
#	endif
		// The administrative limit for this request was exceeded.

	, DS_COMPARE_FALSE =
#	if defined ERROR_DS_COMPARE_FALSE
			ERROR_DS_COMPARE_FALSE
#	else
			0x2025
#	endif
		// The compare response was false.

	, DS_COMPARE_TRUE =
#	if defined ERROR_DS_COMPARE_TRUE
			ERROR_DS_COMPARE_TRUE
#	else
			0x2026
#	endif
		// The compare response was true.

	, DS_AUTH_METHOD_NOT_SUPPORTED =
#	if defined ERROR_DS_AUTH_METHOD_NOT_SUPPORTED
			ERROR_DS_AUTH_METHOD_NOT_SUPPORTED
#	else
			0x2027
#	endif
		// The requested authentication method is not supported by the server.

	, DS_STRONG_AUTH_REQUIRED =
#	if defined ERROR_DS_STRONG_AUTH_REQUIRED
			ERROR_DS_STRONG_AUTH_REQUIRED
#	else
			0x2028
#	endif
		// A more secure authentication method is required for this server.

	, DS_INAPPROPRIATE_AUTH =
#	if defined ERROR_DS_INAPPROPRIATE_AUTH
			ERROR_DS_INAPPROPRIATE_AUTH
#	else
			0x2029
#	endif
		// Inappropriate authentication.

	, DS_AUTH_UNKNOWN =
#	if defined ERROR_DS_AUTH_UNKNOWN
			ERROR_DS_AUTH_UNKNOWN
#	else
			0x202A
#	endif
		// The authentication mechanism is unknown.

	, DS_REFERRAL =
#	if defined ERROR_DS_REFERRAL
			ERROR_DS_REFERRAL
#	else
			0x202B
#	endif
		// A referral was returned from the server.

	, DS_UNAVAILABLE_CRIT_EXTENSION =
#	if defined ERROR_DS_UNAVAILABLE_CRIT_EXTENSION
			ERROR_DS_UNAVAILABLE_CRIT_EXTENSION
#	else
			0x202C
#	endif
		// The server does not support the requested critical extension.

	, DS_CONFIDENTIALITY_REQUIRED =
#	if defined ERROR_DS_CONFIDENTIALITY_REQUIRED
			ERROR_DS_CONFIDENTIALITY_REQUIRED
#	else
			0x202D
#	endif
		// This request requires a secure connection.

	, DS_INAPPROPRIATE_MATCHING =
#	if defined ERROR_DS_INAPPROPRIATE_MATCHING
			ERROR_DS_INAPPROPRIATE_MATCHING
#	else
			0x202E
#	endif
		// Inappropriate matching.

	, DS_CONSTRAINT_VIOLATION =
#	if defined ERROR_DS_CONSTRAINT_VIOLATION
			ERROR_DS_CONSTRAINT_VIOLATION
#	else
			0x202F
#	endif
		// A constraint violation occurred.

	, DS_NO_SUCH_OBJECT =
#	if defined ERROR_DS_NO_SUCH_OBJECT
			ERROR_DS_NO_SUCH_OBJECT
#	else
			0x2030
#	endif
		// There is no such object on the server.

	, DS_ALIAS_PROBLEM =
#	if defined ERROR_DS_ALIAS_PROBLEM
			ERROR_DS_ALIAS_PROBLEM
#	else
			0x2031
#	endif
		// There is an alias problem.

	, DS_INVALID_DN_SYNTAX =
#	if defined ERROR_DS_INVALID_DN_SYNTAX
			ERROR_DS_INVALID_DN_SYNTAX
#	else
			0x2032
#	endif
		// An invalid dn syntax has been specified.

	, DS_IS_LEAF =
#	if defined ERROR_DS_IS_LEAF
			ERROR_DS_IS_LEAF
#	else
			0x2033
#	endif
		// The object is a leaf object.

	, DS_ALIAS_DEREF_PROBLEM =
#	if defined ERROR_DS_ALIAS_DEREF_PROBLEM
			ERROR_DS_ALIAS_DEREF_PROBLEM
#	else
			0x2034
#	endif
		// There is an alias dereferencing problem.

	, DS_UNWILLING_TO_PERFORM =
#	if defined ERROR_DS_UNWILLING_TO_PERFORM
			ERROR_DS_UNWILLING_TO_PERFORM
#	else
			0x2035
#	endif
		// The server is unwilling to process the request.

	, DS_LOOP_DETECT =
#	if defined ERROR_DS_LOOP_DETECT
			ERROR_DS_LOOP_DETECT
#	else
			0x2036
#	endif
		// A loop has been detected.

	, DS_NAMING_VIOLATION =
#	if defined ERROR_DS_NAMING_VIOLATION
			ERROR_DS_NAMING_VIOLATION
#	else
			0x2037
#	endif
		// There is a naming violation.

	, DS_OBJECT_RESULTS_TOO_LARGE =
#	if defined ERROR_DS_OBJECT_RESULTS_TOO_LARGE
			ERROR_DS_OBJECT_RESULTS_TOO_LARGE
#	else
			0x2038
#	endif
		// The result set is too large.

	, DS_AFFECTS_MULTIPLE_DSAS =
#	if defined ERROR_DS_AFFECTS_MULTIPLE_DSAS
			ERROR_DS_AFFECTS_MULTIPLE_DSAS
#	else
			0x2039
#	endif
		// The operation affects multiple DSAs.

	, DS_SERVER_DOWN =
#	if defined ERROR_DS_SERVER_DOWN
			ERROR_DS_SERVER_DOWN
#	else
			0x203A
#	endif
		// The server is not operational.

	, DS_LOCAL_ERROR =
#	if defined ERROR_DS_LOCAL_ERROR
			ERROR_DS_LOCAL_ERROR
#	else
			0x203B
#	endif
		// A local error has occurred.

	, DS_ENCODING_ERROR =
#	if defined ERROR_DS_ENCODING_ERROR
			ERROR_DS_ENCODING_ERROR
#	else
			0x203C
#	endif
		// An encoding error has occurred.

	, DS_DECODING_ERROR =
#	if defined ERROR_DS_DECODING_ERROR
			ERROR_DS_DECODING_ERROR
#	else
			0x203D
#	endif
		// A decoding error has occurred.

	, DS_FILTER_UNKNOWN =
#	if defined ERROR_DS_FILTER_UNKNOWN
			ERROR_DS_FILTER_UNKNOWN
#	else
			0x203E
#	endif
		// The search filter cannot be recognized.

	, DS_PARAM_ERROR =
#	if defined ERROR_DS_PARAM_ERROR
			ERROR_DS_PARAM_ERROR
#	else
			0x203F
#	endif
		// One or more parameters are illegal.

	, DS_NOT_SUPPORTED =
#	if defined ERROR_DS_NOT_SUPPORTED
			ERROR_DS_NOT_SUPPORTED
#	else
			0x2040
#	endif
		// The specified method is not supported.

	, DS_NO_RESULTS_RETURNED =
#	if defined ERROR_DS_NO_RESULTS_RETURNED
			ERROR_DS_NO_RESULTS_RETURNED
#	else
			0x2041
#	endif
		// No results were returned.

	, DS_CONTROL_NOT_FOUND =
#	if defined ERROR_DS_CONTROL_NOT_FOUND
			ERROR_DS_CONTROL_NOT_FOUND
#	else
			0x2042
#	endif
		// The specified control is not supported by the server.

	, DS_CLIENT_LOOP =
#	if defined ERROR_DS_CLIENT_LOOP
			ERROR_DS_CLIENT_LOOP
#	else
			0x2043
#	endif
		// A referral loop was detected by the client.

	, DS_REFERRAL_LIMIT_EXCEEDED =
#	if defined ERROR_DS_REFERRAL_LIMIT_EXCEEDED
			ERROR_DS_REFERRAL_LIMIT_EXCEEDED
#	else
			0x2044
#	endif
		// The preset referral limit was exceeded.

	, DS_SORT_CONTROL_MISSING =
#	if defined ERROR_DS_SORT_CONTROL_MISSING
			ERROR_DS_SORT_CONTROL_MISSING
#	else
			0x2045
#	endif
		// The search requires a SORT control.

	, DS_OFFSET_RANGE_ERROR =
#	if defined ERROR_DS_OFFSET_RANGE_ERROR
			ERROR_DS_OFFSET_RANGE_ERROR
#	else
			0x2046
#	endif
		// The search results exceed the offset range specified.

	, DS_RIDMGR_DISABLED =
#	if defined ERROR_DS_RIDMGR_DISABLED
			ERROR_DS_RIDMGR_DISABLED
#	else
			0x2047
#	endif
		// The directory service detected the subsystem that allocates relative identifiers is disabled. This can occur as a protective mechanism when the system determines a significant portion of relative identifiers (RIDs) have been exhausted. Please see https://go.microsoft.com/fwlink/p/?linkid=228610 for recommended diagnostic steps and the procedure to re-enable account creation.

	, DS_ROOT_MUST_BE_NC =
#	if defined ERROR_DS_ROOT_MUST_BE_NC
			ERROR_DS_ROOT_MUST_BE_NC
#	else
			0x206D
#	endif
		// The root object must be the head of a naming context. The root object cannot have an instantiated parent.

	, DS_ADD_REPLICA_INHIBITED =
#	if defined ERROR_DS_ADD_REPLICA_INHIBITED
			ERROR_DS_ADD_REPLICA_INHIBITED
#	else
			0x206E
#	endif
		// The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.

	, DS_ATT_NOT_DEF_IN_SCHEMA =
#	if defined ERROR_DS_ATT_NOT_DEF_IN_SCHEMA
			ERROR_DS_ATT_NOT_DEF_IN_SCHEMA
#	else
			0x206F
#	endif
		// A reference to an attribute that is not defined in the schema occurred.

	, DS_MAX_OBJ_SIZE_EXCEEDED =
#	if defined ERROR_DS_MAX_OBJ_SIZE_EXCEEDED
			ERROR_DS_MAX_OBJ_SIZE_EXCEEDED
#	else
			0x2070
#	endif
		// The maximum size of an object has been exceeded.

	, DS_OBJ_STRING_NAME_EXISTS =
#	if defined ERROR_DS_OBJ_STRING_NAME_EXISTS
			ERROR_DS_OBJ_STRING_NAME_EXISTS
#	else
			0x2071
#	endif
		// An attempt was made to add an object to the directory with a name that is already in use.

	, DS_NO_RDN_DEFINED_IN_SCHEMA =
#	if defined ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA
			ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA
#	else
			0x2072
#	endif
		// An attempt was made to add an object of a class that does not have an RDN defined in the schema.

	, DS_RDN_DOESNT_MATCH_SCHEMA =
#	if defined ERROR_DS_RDN_DOESNT_MATCH_SCHEMA
			ERROR_DS_RDN_DOESNT_MATCH_SCHEMA
#	else
			0x2073
#	endif
		// An attempt was made to add an object using an RDN that is not the RDN defined in the schema.

	, DS_NO_REQUESTED_ATTS_FOUND =
#	if defined ERROR_DS_NO_REQUESTED_ATTS_FOUND
			ERROR_DS_NO_REQUESTED_ATTS_FOUND
#	else
			0x2074
#	endif
		// None of the requested attributes were found on the objects.

	, DS_USER_BUFFER_TO_SMALL =
#	if defined ERROR_DS_USER_BUFFER_TO_SMALL
			ERROR_DS_USER_BUFFER_TO_SMALL
#	else
			0x2075
#	endif
		// The user buffer is too small.

	, DS_ATT_IS_NOT_ON_OBJ =
#	if defined ERROR_DS_ATT_IS_NOT_ON_OBJ
			ERROR_DS_ATT_IS_NOT_ON_OBJ
#	else
			0x2076
#	endif
		// The attribute specified in the operation is not present on the object.

	, DS_ILLEGAL_MOD_OPERATION =
#	if defined ERROR_DS_ILLEGAL_MOD_OPERATION
			ERROR_DS_ILLEGAL_MOD_OPERATION
#	else
			0x2077
#	endif
		// Illegal modify operation. Some aspect of the modification is not permitted.

	, DS_OBJ_TOO_LARGE =
#	if defined ERROR_DS_OBJ_TOO_LARGE
			ERROR_DS_OBJ_TOO_LARGE
#	else
			0x2078
#	endif
		// The specified object is too large.

	, DS_BAD_INSTANCE_TYPE =
#	if defined ERROR_DS_BAD_INSTANCE_TYPE
			ERROR_DS_BAD_INSTANCE_TYPE
#	else
			0x2079
#	endif
		// The specified instance type is not valid.

	, DS_MASTERDSA_REQUIRED =
#	if defined ERROR_DS_MASTERDSA_REQUIRED
			ERROR_DS_MASTERDSA_REQUIRED
#	else
			0x207A
#	endif
		// The operation must be performed at a master DSA.

	, DS_OBJECT_CLASS_REQUIRED =
#	if defined ERROR_DS_OBJECT_CLASS_REQUIRED
			ERROR_DS_OBJECT_CLASS_REQUIRED
#	else
			0x207B
#	endif
		// The object class attribute must be specified.

	, DS_MISSING_REQUIRED_ATT =
#	if defined ERROR_DS_MISSING_REQUIRED_ATT
			ERROR_DS_MISSING_REQUIRED_ATT
#	else
			0x207C
#	endif
		// A required attribute is missing.

	, DS_ATT_NOT_DEF_FOR_CLASS =
#	if defined ERROR_DS_ATT_NOT_DEF_FOR_CLASS
			ERROR_DS_ATT_NOT_DEF_FOR_CLASS
#	else
			0x207D
#	endif
		// An attempt was made to modify an object to include an attribute that is not legal for its class.

	, DS_ATT_ALREADY_EXISTS =
#	if defined ERROR_DS_ATT_ALREADY_EXISTS
			ERROR_DS_ATT_ALREADY_EXISTS
#	else
			0x207E
#	endif
		// The specified attribute is already present on the object.

	, DS_CANT_ADD_ATT_VALUES =
#	if defined ERROR_DS_CANT_ADD_ATT_VALUES
			ERROR_DS_CANT_ADD_ATT_VALUES
#	else
			0x2080
#	endif
		// The specified attribute is not present, or has no values.

	, DS_SINGLE_VALUE_CONSTRAINT =
#	if defined ERROR_DS_SINGLE_VALUE_CONSTRAINT
			ERROR_DS_SINGLE_VALUE_CONSTRAINT
#	else
			0x2081
#	endif
		// Multiple values were specified for an attribute that can have only one value.

	, DS_RANGE_CONSTRAINT =
#	if defined ERROR_DS_RANGE_CONSTRAINT
			ERROR_DS_RANGE_CONSTRAINT
#	else
			0x2082
#	endif
		// A value for the attribute was not in the acceptable range of values.

	, DS_ATT_VAL_ALREADY_EXISTS =
#	if defined ERROR_DS_ATT_VAL_ALREADY_EXISTS
			ERROR_DS_ATT_VAL_ALREADY_EXISTS
#	else
			0x2083
#	endif
		// The specified value already exists.

	, DS_CANT_REM_MISSING_ATT =
#	if defined ERROR_DS_CANT_REM_MISSING_ATT
			ERROR_DS_CANT_REM_MISSING_ATT
#	else
			0x2084
#	endif
		// The attribute cannot be removed because it is not present on the object.

	, DS_CANT_REM_MISSING_ATT_VAL =
#	if defined ERROR_DS_CANT_REM_MISSING_ATT_VAL
			ERROR_DS_CANT_REM_MISSING_ATT_VAL
#	else
			0x2085
#	endif
		// The attribute value cannot be removed because it is not present on the object.

	, DS_ROOT_CANT_BE_SUBREF =
#	if defined ERROR_DS_ROOT_CANT_BE_SUBREF
			ERROR_DS_ROOT_CANT_BE_SUBREF
#	else
			0x2086
#	endif
		// The specified root object cannot be a subref.

	, DS_NO_CHAINING =
#	if defined ERROR_DS_NO_CHAINING
			ERROR_DS_NO_CHAINING
#	else
			0x2087
#	endif
		// Chaining is not permitted.

	, DS_NO_CHAINED_EVAL =
#	if defined ERROR_DS_NO_CHAINED_EVAL
			ERROR_DS_NO_CHAINED_EVAL
#	else
			0x2088
#	endif
		// Chained evaluation is not permitted.

	, DS_NO_PARENT_OBJECT =
#	if defined ERROR_DS_NO_PARENT_OBJECT
			ERROR_DS_NO_PARENT_OBJECT
#	else
			0x2089
#	endif
		// The operation could not be performed because the object's parent is either uninstantiated or deleted.

	, DS_PARENT_IS_AN_ALIAS =
#	if defined ERROR_DS_PARENT_IS_AN_ALIAS
			ERROR_DS_PARENT_IS_AN_ALIAS
#	else
			0x208A
#	endif
		// Having a parent that is an alias is not permitted. Aliases are leaf objects.

	, DS_CANT_MIX_MASTER_AND_REPS =
#	if defined ERROR_DS_CANT_MIX_MASTER_AND_REPS
			ERROR_DS_CANT_MIX_MASTER_AND_REPS
#	else
			0x208B
#	endif
		// The object and parent must be of the same type, either both masters or both replicas.

	, DS_CHILDREN_EXIST =
#	if defined ERROR_DS_CHILDREN_EXIST
			ERROR_DS_CHILDREN_EXIST
#	else
			0x208C
#	endif
		// The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.

	, DS_OBJ_NOT_FOUND =
#	if defined ERROR_DS_OBJ_NOT_FOUND
			ERROR_DS_OBJ_NOT_FOUND
#	else
			0x208D
#	endif
		// Directory object not found.

	, DS_ALIASED_OBJ_MISSING =
#	if defined ERROR_DS_ALIASED_OBJ_MISSING
			ERROR_DS_ALIASED_OBJ_MISSING
#	else
			0x208E
#	endif
		// The aliased object is missing.

	, DS_BAD_NAME_SYNTAX =
#	if defined ERROR_DS_BAD_NAME_SYNTAX
			ERROR_DS_BAD_NAME_SYNTAX
#	else
			0x208F
#	endif
		// The object name has bad syntax.

	, DS_ALIAS_POINTS_TO_ALIAS =
#	if defined ERROR_DS_ALIAS_POINTS_TO_ALIAS
			ERROR_DS_ALIAS_POINTS_TO_ALIAS
#	else
			0x2090
#	endif
		// It is not permitted for an alias to refer to another alias.

	, DS_CANT_DEREF_ALIAS =
#	if defined ERROR_DS_CANT_DEREF_ALIAS
			ERROR_DS_CANT_DEREF_ALIAS
#	else
			0x2091
#	endif
		// The alias cannot be dereferenced.

	, DS_OUT_OF_SCOPE =
#	if defined ERROR_DS_OUT_OF_SCOPE
			ERROR_DS_OUT_OF_SCOPE
#	else
			0x2092
#	endif
		// The operation is out of scope.

	, DS_OBJECT_BEING_REMOVED =
#	if defined ERROR_DS_OBJECT_BEING_REMOVED
			ERROR_DS_OBJECT_BEING_REMOVED
#	else
			0x2093
#	endif
		// The operation cannot continue because the object is in the process of being removed.

	, DS_CANT_DELETE_DSA_OBJ =
#	if defined ERROR_DS_CANT_DELETE_DSA_OBJ
			ERROR_DS_CANT_DELETE_DSA_OBJ
#	else
			0x2094
#	endif
		// The DSA object cannot be deleted.

	, DS_GENERIC_ERROR =
#	if defined ERROR_DS_GENERIC_ERROR
			ERROR_DS_GENERIC_ERROR
#	else
			0x2095
#	endif
		// A directory service error has occurred.

	, DS_DSA_MUST_BE_INT_MASTER =
#	if defined ERROR_DS_DSA_MUST_BE_INT_MASTER
			ERROR_DS_DSA_MUST_BE_INT_MASTER
#	else
			0x2096
#	endif
		// The operation can only be performed on an internal master DSA object.

	, DS_CLASS_NOT_DSA =
#	if defined ERROR_DS_CLASS_NOT_DSA
			ERROR_DS_CLASS_NOT_DSA
#	else
			0x2097
#	endif
		// The object must be of class DSA.

	, DS_INSUFF_ACCESS_RIGHTS =
#	if defined ERROR_DS_INSUFF_ACCESS_RIGHTS
			ERROR_DS_INSUFF_ACCESS_RIGHTS
#	else
			0x2098
#	endif
		// Insufficient access rights to perform the operation.

	, DS_ILLEGAL_SUPERIOR =
#	if defined ERROR_DS_ILLEGAL_SUPERIOR
			ERROR_DS_ILLEGAL_SUPERIOR
#	else
			0x2099
#	endif
		// The object cannot be added because the parent is not on the list of possible superiors.

	, DS_ATTRIBUTE_OWNED_BY_SAM =
#	if defined ERROR_DS_ATTRIBUTE_OWNED_BY_SAM
			ERROR_DS_ATTRIBUTE_OWNED_BY_SAM
#	else
			0x209A
#	endif
		// Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).

	, DS_NAME_TOO_MANY_PARTS =
#	if defined ERROR_DS_NAME_TOO_MANY_PARTS
			ERROR_DS_NAME_TOO_MANY_PARTS
#	else
			0x209B
#	endif
		// The name has too many parts.

	, DS_NAME_TOO_LONG =
#	if defined ERROR_DS_NAME_TOO_LONG
			ERROR_DS_NAME_TOO_LONG
#	else
			0x209C
#	endif
		// The name is too long.

	, DS_NAME_VALUE_TOO_LONG =
#	if defined ERROR_DS_NAME_VALUE_TOO_LONG
			ERROR_DS_NAME_VALUE_TOO_LONG
#	else
			0x209D
#	endif
		// The name value is too long.

	, DS_NAME_UNPARSEABLE =
#	if defined ERROR_DS_NAME_UNPARSEABLE
			ERROR_DS_NAME_UNPARSEABLE
#	else
			0x209E
#	endif
		// The directory service encountered an error parsing a name.

	, DS_NAME_TYPE_UNKNOWN =
#	if defined ERROR_DS_NAME_TYPE_UNKNOWN
			ERROR_DS_NAME_TYPE_UNKNOWN
#	else
			0x209F
#	endif
		// The directory service cannot get the attribute type for a name.

	, DS_NOT_AN_OBJECT =
#	if defined ERROR_DS_NOT_AN_OBJECT
			ERROR_DS_NOT_AN_OBJECT
#	else
			0x20A0
#	endif
		// The name does not identify an object; the name identifies a phantom.

	, DS_SEC_DESC_TOO_SHORT =
#	if defined ERROR_DS_SEC_DESC_TOO_SHORT
			ERROR_DS_SEC_DESC_TOO_SHORT
#	else
			0x20A1
#	endif
		// The security descriptor is too short.

	, DS_SEC_DESC_INVALID =
#	if defined ERROR_DS_SEC_DESC_INVALID
			ERROR_DS_SEC_DESC_INVALID
#	else
			0x20A2
#	endif
		// The security descriptor is invalid.

	, DS_NO_DELETED_NAME =
#	if defined ERROR_DS_NO_DELETED_NAME
			ERROR_DS_NO_DELETED_NAME
#	else
			0x20A3
#	endif
		// Failed to create name for deleted object.

	, DS_SUBREF_MUST_HAVE_PARENT =
#	if defined ERROR_DS_SUBREF_MUST_HAVE_PARENT
			ERROR_DS_SUBREF_MUST_HAVE_PARENT
#	else
			0x20A4
#	endif
		// The parent of a new subref must exist.

	, DS_NCNAME_MUST_BE_NC =
#	if defined ERROR_DS_NCNAME_MUST_BE_NC
			ERROR_DS_NCNAME_MUST_BE_NC
#	else
			0x20A5
#	endif
		// The object must be a naming context.

	, DS_CANT_ADD_SYSTEM_ONLY =
#	if defined ERROR_DS_CANT_ADD_SYSTEM_ONLY
			ERROR_DS_CANT_ADD_SYSTEM_ONLY
#	else
			0x20A6
#	endif
		// It is not permitted to add an attribute which is owned by the system.

	, DS_CLASS_MUST_BE_CONCRETE =
#	if defined ERROR_DS_CLASS_MUST_BE_CONCRETE
			ERROR_DS_CLASS_MUST_BE_CONCRETE
#	else
			0x20A7
#	endif
		// The class of the object must be structural; you cannot instantiate an abstract class.

	, DS_INVALID_DMD =
#	if defined ERROR_DS_INVALID_DMD
			ERROR_DS_INVALID_DMD
#	else
			0x20A8
#	endif
		// The schema object could not be found.

	, DS_OBJ_GUID_EXISTS =
#	if defined ERROR_DS_OBJ_GUID_EXISTS
			ERROR_DS_OBJ_GUID_EXISTS
#	else
			0x20A9
#	endif
		// A local object with this GUID (dead or alive) already exists.

	, DS_NOT_ON_BACKLINK =
#	if defined ERROR_DS_NOT_ON_BACKLINK
			ERROR_DS_NOT_ON_BACKLINK
#	else
			0x20AA
#	endif
		// The operation cannot be performed on a back link.

	, DS_NO_CROSSREF_FOR_NC =
#	if defined ERROR_DS_NO_CROSSREF_FOR_NC
			ERROR_DS_NO_CROSSREF_FOR_NC
#	else
			0x20AB
#	endif
		// The cross reference for the specified naming context could not be found.

	, DS_SHUTTING_DOWN =
#	if defined ERROR_DS_SHUTTING_DOWN
			ERROR_DS_SHUTTING_DOWN
#	else
			0x20AC
#	endif
		// The operation could not be performed because the directory service is shutting down.

	, DS_UNKNOWN_OPERATION =
#	if defined ERROR_DS_UNKNOWN_OPERATION
			ERROR_DS_UNKNOWN_OPERATION
#	else
			0x20AD
#	endif
		// The directory service request is invalid.

	, DS_INVALID_ROLE_OWNER =
#	if defined ERROR_DS_INVALID_ROLE_OWNER
			ERROR_DS_INVALID_ROLE_OWNER
#	else
			0x20AE
#	endif
		// The role owner attribute could not be read.

	, DS_COULDNT_CONTACT_FSMO =
#	if defined ERROR_DS_COULDNT_CONTACT_FSMO
			ERROR_DS_COULDNT_CONTACT_FSMO
#	else
			0x20AF
#	endif
		// The requested FSMO operation failed. The current FSMO holder could not be contacted.

	, DS_CROSS_NC_DN_RENAME =
#	if defined ERROR_DS_CROSS_NC_DN_RENAME
			ERROR_DS_CROSS_NC_DN_RENAME
#	else
			0x20B0
#	endif
		// Modification of a DN across a naming context is not permitted.

	, DS_CANT_MOD_SYSTEM_ONLY =
#	if defined ERROR_DS_CANT_MOD_SYSTEM_ONLY
			ERROR_DS_CANT_MOD_SYSTEM_ONLY
#	else
			0x20B1
#	endif
		// The attribute cannot be modified because it is owned by the system.

	, DS_REPLICATOR_ONLY =
#	if defined ERROR_DS_REPLICATOR_ONLY
			ERROR_DS_REPLICATOR_ONLY
#	else
			0x20B2
#	endif
		// Only the replicator can perform this function.

	, DS_OBJ_CLASS_NOT_DEFINED =
#	if defined ERROR_DS_OBJ_CLASS_NOT_DEFINED
			ERROR_DS_OBJ_CLASS_NOT_DEFINED
#	else
			0x20B3
#	endif
		// The specified class is not defined.

	, DS_OBJ_CLASS_NOT_SUBCLASS =
#	if defined ERROR_DS_OBJ_CLASS_NOT_SUBCLASS
			ERROR_DS_OBJ_CLASS_NOT_SUBCLASS
#	else
			0x20B4
#	endif
		// The specified class is not a subclass.

	, DS_NAME_REFERENCE_INVALID =
#	if defined ERROR_DS_NAME_REFERENCE_INVALID
			ERROR_DS_NAME_REFERENCE_INVALID
#	else
			0x20B5
#	endif
		// The name reference is invalid.

	, DS_CROSS_REF_EXISTS =
#	if defined ERROR_DS_CROSS_REF_EXISTS
			ERROR_DS_CROSS_REF_EXISTS
#	else
			0x20B6
#	endif
		// A cross reference already exists.

	, DS_CANT_DEL_MASTER_CROSSREF =
#	if defined ERROR_DS_CANT_DEL_MASTER_CROSSREF
			ERROR_DS_CANT_DEL_MASTER_CROSSREF
#	else
			0x20B7
#	endif
		// It is not permitted to delete a master cross reference.

	, DS_SUBTREE_NOTIFY_NOT_NC_HEAD =
#	if defined ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD
			ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD
#	else
			0x20B8
#	endif
		// Subtree notifications are only supported on NC heads.

	, DS_NOTIFY_FILTER_TOO_COMPLEX =
#	if defined ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX
			ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX
#	else
			0x20B9
#	endif
		// Notification filter is too complex.

	, DS_DUP_RDN =
#	if defined ERROR_DS_DUP_RDN
			ERROR_DS_DUP_RDN
#	else
			0x20BA
#	endif
		// Schema update failed: duplicate RDN.

	, DS_DUP_OID =
#	if defined ERROR_DS_DUP_OID
			ERROR_DS_DUP_OID
#	else
			0x20BB
#	endif
		// Schema update failed: duplicate OID.

	, DS_DUP_MAPI_ID =
#	if defined ERROR_DS_DUP_MAPI_ID
			ERROR_DS_DUP_MAPI_ID
#	else
			0x20BC
#	endif
		// Schema update failed: duplicate MAPI identifier.

	, DS_DUP_SCHEMA_ID_GUID =
#	if defined ERROR_DS_DUP_SCHEMA_ID_GUID
			ERROR_DS_DUP_SCHEMA_ID_GUID
#	else
			0x20BD
#	endif
		// Schema update failed: duplicate schema-id GUID.

	, DS_DUP_LDAP_DISPLAY_NAME =
#	if defined ERROR_DS_DUP_LDAP_DISPLAY_NAME
			ERROR_DS_DUP_LDAP_DISPLAY_NAME
#	else
			0x20BE
#	endif
		// Schema update failed: duplicate LDAP display name.

	, DS_SEMANTIC_ATT_TEST =
#	if defined ERROR_DS_SEMANTIC_ATT_TEST
			ERROR_DS_SEMANTIC_ATT_TEST
#	else
			0x20BF
#	endif
		// Schema update failed: range-lower less than range upper.

	, DS_SYNTAX_MISMATCH =
#	if defined ERROR_DS_SYNTAX_MISMATCH
			ERROR_DS_SYNTAX_MISMATCH
#	else
			0x20C0
#	endif
		// Schema update failed: syntax mismatch.

	, DS_EXISTS_IN_MUST_HAVE =
#	if defined ERROR_DS_EXISTS_IN_MUST_HAVE
			ERROR_DS_EXISTS_IN_MUST_HAVE
#	else
			0x20C1
#	endif
		// Schema deletion failed: attribute is used in must-contain.

	, DS_EXISTS_IN_MAY_HAVE =
#	if defined ERROR_DS_EXISTS_IN_MAY_HAVE
			ERROR_DS_EXISTS_IN_MAY_HAVE
#	else
			0x20C2
#	endif
		// Schema deletion failed: attribute is used in may-contain.

	, DS_NONEXISTENT_MAY_HAVE =
#	if defined ERROR_DS_NONEXISTENT_MAY_HAVE
			ERROR_DS_NONEXISTENT_MAY_HAVE
#	else
			0x20C3
#	endif
		// Schema update failed: attribute in may-contain does not exist.

	, DS_NONEXISTENT_MUST_HAVE =
#	if defined ERROR_DS_NONEXISTENT_MUST_HAVE
			ERROR_DS_NONEXISTENT_MUST_HAVE
#	else
			0x20C4
#	endif
		// Schema update failed: attribute in must-contain does not exist.

	, DS_AUX_CLS_TEST_FAIL =
#	if defined ERROR_DS_AUX_CLS_TEST_FAIL
			ERROR_DS_AUX_CLS_TEST_FAIL
#	else
			0x20C5
#	endif
		// Schema update failed: class in aux-class list does not exist or is not an auxiliary class.

	, DS_NONEXISTENT_POSS_SUP =
#	if defined ERROR_DS_NONEXISTENT_POSS_SUP
			ERROR_DS_NONEXISTENT_POSS_SUP
#	else
			0x20C6
#	endif
		// Schema update failed: class in poss-superiors does not exist.

	, DS_SUB_CLS_TEST_FAIL =
#	if defined ERROR_DS_SUB_CLS_TEST_FAIL
			ERROR_DS_SUB_CLS_TEST_FAIL
#	else
			0x20C7
#	endif
		// Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules.

	, DS_BAD_RDN_ATT_ID_SYNTAX =
#	if defined ERROR_DS_BAD_RDN_ATT_ID_SYNTAX
			ERROR_DS_BAD_RDN_ATT_ID_SYNTAX
#	else
			0x20C8
#	endif
		// Schema update failed: Rdn-Att-Id has wrong syntax.

	, DS_EXISTS_IN_AUX_CLS =
#	if defined ERROR_DS_EXISTS_IN_AUX_CLS
			ERROR_DS_EXISTS_IN_AUX_CLS
#	else
			0x20C9
#	endif
		// Schema deletion failed: class is used as auxiliary class.

	, DS_EXISTS_IN_SUB_CLS =
#	if defined ERROR_DS_EXISTS_IN_SUB_CLS
			ERROR_DS_EXISTS_IN_SUB_CLS
#	else
			0x20CA
#	endif
		// Schema deletion failed: class is used as sub class.

	, DS_EXISTS_IN_POSS_SUP =
#	if defined ERROR_DS_EXISTS_IN_POSS_SUP
			ERROR_DS_EXISTS_IN_POSS_SUP
#	else
			0x20CB
#	endif
		// Schema deletion failed: class is used as poss superior.

	, DS_RECALCSCHEMA_FAILED =
#	if defined ERROR_DS_RECALCSCHEMA_FAILED
			ERROR_DS_RECALCSCHEMA_FAILED
#	else
			0x20CC
#	endif
		// Schema update failed in recalculating validation cache.

	, DS_TREE_DELETE_NOT_FINISHED =
#	if defined ERROR_DS_TREE_DELETE_NOT_FINISHED
			ERROR_DS_TREE_DELETE_NOT_FINISHED
#	else
			0x20CD
#	endif
		// The tree deletion is not finished. The request must be made again to continue deleting the tree.

	, DS_CANT_DELETE =
#	if defined ERROR_DS_CANT_DELETE
			ERROR_DS_CANT_DELETE
#	else
			0x20CE
#	endif
		// The requested delete operation could not be performed.

	, DS_ATT_SCHEMA_REQ_ID =
#	if defined ERROR_DS_ATT_SCHEMA_REQ_ID
			ERROR_DS_ATT_SCHEMA_REQ_ID
#	else
			0x20CF
#	endif
		// Cannot read the governs class identifier for the schema record.

	, DS_BAD_ATT_SCHEMA_SYNTAX =
#	if defined ERROR_DS_BAD_ATT_SCHEMA_SYNTAX
			ERROR_DS_BAD_ATT_SCHEMA_SYNTAX
#	else
			0x20D0
#	endif
		// The attribute schema has bad syntax.

	, DS_CANT_CACHE_ATT =
#	if defined ERROR_DS_CANT_CACHE_ATT
			ERROR_DS_CANT_CACHE_ATT
#	else
			0x20D1
#	endif
		// The attribute could not be cached.

	, DS_CANT_CACHE_CLASS =
#	if defined ERROR_DS_CANT_CACHE_CLASS
			ERROR_DS_CANT_CACHE_CLASS
#	else
			0x20D2
#	endif
		// The class could not be cached.

	, DS_CANT_REMOVE_ATT_CACHE =
#	if defined ERROR_DS_CANT_REMOVE_ATT_CACHE
			ERROR_DS_CANT_REMOVE_ATT_CACHE
#	else
			0x20D3
#	endif
		// The attribute could not be removed from the cache.

	, DS_CANT_REMOVE_CLASS_CACHE =
#	if defined ERROR_DS_CANT_REMOVE_CLASS_CACHE
			ERROR_DS_CANT_REMOVE_CLASS_CACHE
#	else
			0x20D4
#	endif
		// The class could not be removed from the cache.

	, DS_CANT_RETRIEVE_DN =
#	if defined ERROR_DS_CANT_RETRIEVE_DN
			ERROR_DS_CANT_RETRIEVE_DN
#	else
			0x20D5
#	endif
		// The distinguished name attribute could not be read.

	, DS_MISSING_SUPREF =
#	if defined ERROR_DS_MISSING_SUPREF
			ERROR_DS_MISSING_SUPREF
#	else
			0x20D6
#	endif
		// No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.

	, DS_CANT_RETRIEVE_INSTANCE =
#	if defined ERROR_DS_CANT_RETRIEVE_INSTANCE
			ERROR_DS_CANT_RETRIEVE_INSTANCE
#	else
			0x20D7
#	endif
		// The instance type attribute could not be retrieved.

	, DS_CODE_INCONSISTENCY =
#	if defined ERROR_DS_CODE_INCONSISTENCY
			ERROR_DS_CODE_INCONSISTENCY
#	else
			0x20D8
#	endif
		// An internal error has occurred.

	, DS_DATABASE_ERROR =
#	if defined ERROR_DS_DATABASE_ERROR
			ERROR_DS_DATABASE_ERROR
#	else
			0x20D9
#	endif
		// A database error has occurred.

	, DS_GOVERNSID_MISSING =
#	if defined ERROR_DS_GOVERNSID_MISSING
			ERROR_DS_GOVERNSID_MISSING
#	else
			0x20DA
#	endif
		// The attribute GOVERNSID is missing.

	, DS_MISSING_EXPECTED_ATT =
#	if defined ERROR_DS_MISSING_EXPECTED_ATT
			ERROR_DS_MISSING_EXPECTED_ATT
#	else
			0x20DB
#	endif
		// An expected attribute is missing.

	, DS_NCNAME_MISSING_CR_REF =
#	if defined ERROR_DS_NCNAME_MISSING_CR_REF
			ERROR_DS_NCNAME_MISSING_CR_REF
#	else
			0x20DC
#	endif
		// The specified naming context is missing a cross reference.

	, DS_SECURITY_CHECKING_ERROR =
#	if defined ERROR_DS_SECURITY_CHECKING_ERROR
			ERROR_DS_SECURITY_CHECKING_ERROR
#	else
			0x20DD
#	endif
		// A security checking error has occurred.

	, DS_SCHEMA_NOT_LOADED =
#	if defined ERROR_DS_SCHEMA_NOT_LOADED
			ERROR_DS_SCHEMA_NOT_LOADED
#	else
			0x20DE
#	endif
		// The schema is not loaded.

	, DS_SCHEMA_ALLOC_FAILED =
#	if defined ERROR_DS_SCHEMA_ALLOC_FAILED
			ERROR_DS_SCHEMA_ALLOC_FAILED
#	else
			0x20DF
#	endif
		// Schema allocation failed. Please check if the machine is running low on memory.

	, DS_ATT_SCHEMA_REQ_SYNTAX =
#	if defined ERROR_DS_ATT_SCHEMA_REQ_SYNTAX
			ERROR_DS_ATT_SCHEMA_REQ_SYNTAX
#	else
			0x20E0
#	endif
		// Failed to obtain the required syntax for the attribute schema.

	, DS_GCVERIFY_ERROR =
#	if defined ERROR_DS_GCVERIFY_ERROR
			ERROR_DS_GCVERIFY_ERROR
#	else
			0x20E1
#	endif
		// The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.

	, DS_DRA_SCHEMA_MISMATCH =
#	if defined ERROR_DS_DRA_SCHEMA_MISMATCH
			ERROR_DS_DRA_SCHEMA_MISMATCH
#	else
			0x20E2
#	endif
		// The replication operation failed because of a schema mismatch between the servers involved.

	, DS_CANT_FIND_DSA_OBJ =
#	if defined ERROR_DS_CANT_FIND_DSA_OBJ
			ERROR_DS_CANT_FIND_DSA_OBJ
#	else
			0x20E3
#	endif
		// The DSA object could not be found.

	, DS_CANT_FIND_EXPECTED_NC =
#	if defined ERROR_DS_CANT_FIND_EXPECTED_NC
			ERROR_DS_CANT_FIND_EXPECTED_NC
#	else
			0x20E4
#	endif
		// The naming context could not be found.

	, DS_CANT_FIND_NC_IN_CACHE =
#	if defined ERROR_DS_CANT_FIND_NC_IN_CACHE
			ERROR_DS_CANT_FIND_NC_IN_CACHE
#	else
			0x20E5
#	endif
		// The naming context could not be found in the cache.

	, DS_CANT_RETRIEVE_CHILD =
#	if defined ERROR_DS_CANT_RETRIEVE_CHILD
			ERROR_DS_CANT_RETRIEVE_CHILD
#	else
			0x20E6
#	endif
		// The child object could not be retrieved.

	, DS_SECURITY_ILLEGAL_MODIFY =
#	if defined ERROR_DS_SECURITY_ILLEGAL_MODIFY
			ERROR_DS_SECURITY_ILLEGAL_MODIFY
#	else
			0x20E7
#	endif
		// The modification was not permitted for security reasons.

	, DS_CANT_REPLACE_HIDDEN_REC =
#	if defined ERROR_DS_CANT_REPLACE_HIDDEN_REC
			ERROR_DS_CANT_REPLACE_HIDDEN_REC
#	else
			0x20E8
#	endif
		// The operation cannot replace the hidden record.

	, DS_BAD_HIERARCHY_FILE =
#	if defined ERROR_DS_BAD_HIERARCHY_FILE
			ERROR_DS_BAD_HIERARCHY_FILE
#	else
			0x20E9
#	endif
		// The hierarchy file is invalid.

	, DS_BUILD_HIERARCHY_TABLE_FAILED =
#	if defined ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED
			ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED
#	else
			0x20EA
#	endif
		// The attempt to build the hierarchy table failed.

	, DS_CONFIG_PARAM_MISSING =
#	if defined ERROR_DS_CONFIG_PARAM_MISSING
			ERROR_DS_CONFIG_PARAM_MISSING
#	else
			0x20EB
#	endif
		// The directory configuration parameter is missing from the registry.

	, DS_COUNTING_AB_INDICES_FAILED =
#	if defined ERROR_DS_COUNTING_AB_INDICES_FAILED
			ERROR_DS_COUNTING_AB_INDICES_FAILED
#	else
			0x20EC
#	endif
		// The attempt to count the address book indices failed.

	, DS_HIERARCHY_TABLE_MALLOC_FAILED =
#	if defined ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED
			ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED
#	else
			0x20ED
#	endif
		// The allocation of the hierarchy table failed.

	, DS_INTERNAL_FAILURE =
#	if defined ERROR_DS_INTERNAL_FAILURE
			ERROR_DS_INTERNAL_FAILURE
#	else
			0x20EE
#	endif
		// The directory service encountered an internal failure.

	, DS_UNKNOWN_ERROR =
#	if defined ERROR_DS_UNKNOWN_ERROR
			ERROR_DS_UNKNOWN_ERROR
#	else
			0x20EF
#	endif
		// The directory service encountered an unknown failure.

	, DS_ROOT_REQUIRES_CLASS_TOP =
#	if defined ERROR_DS_ROOT_REQUIRES_CLASS_TOP
			ERROR_DS_ROOT_REQUIRES_CLASS_TOP
#	else
			0x20F0
#	endif
		// A root object requires a class of 'top'.

	, DS_REFUSING_FSMO_ROLES =
#	if defined ERROR_DS_REFUSING_FSMO_ROLES
			ERROR_DS_REFUSING_FSMO_ROLES
#	else
			0x20F1
#	endif
		// This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.

	, DS_MISSING_FSMO_SETTINGS =
#	if defined ERROR_DS_MISSING_FSMO_SETTINGS
			ERROR_DS_MISSING_FSMO_SETTINGS
#	else
			0x20F2
#	endif
		// The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.

	, DS_UNABLE_TO_SURRENDER_ROLES =
#	if defined ERROR_DS_UNABLE_TO_SURRENDER_ROLES
			ERROR_DS_UNABLE_TO_SURRENDER_ROLES
#	else
			0x20F3
#	endif
		// The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.

	, DS_DRA_GENERIC =
#	if defined ERROR_DS_DRA_GENERIC
			ERROR_DS_DRA_GENERIC
#	else
			0x20F4
#	endif
		// The replication operation failed.

	, DS_DRA_INVALID_PARAMETER =
#	if defined ERROR_DS_DRA_INVALID_PARAMETER
			ERROR_DS_DRA_INVALID_PARAMETER
#	else
			0x20F5
#	endif
		// An invalid parameter was specified for this replication operation.

	, DS_DRA_BUSY =
#	if defined ERROR_DS_DRA_BUSY
			ERROR_DS_DRA_BUSY
#	else
			0x20F6
#	endif
		// The directory service is too busy to complete the replication operation at this time.

	, DS_DRA_BAD_DN =
#	if defined ERROR_DS_DRA_BAD_DN
			ERROR_DS_DRA_BAD_DN
#	else
			0x20F7
#	endif
		// The distinguished name specified for this replication operation is invalid.

	, DS_DRA_BAD_NC =
#	if defined ERROR_DS_DRA_BAD_NC
			ERROR_DS_DRA_BAD_NC
#	else
			0x20F8
#	endif
		// The naming context specified for this replication operation is invalid.

	, DS_DRA_DN_EXISTS =
#	if defined ERROR_DS_DRA_DN_EXISTS
			ERROR_DS_DRA_DN_EXISTS
#	else
			0x20F9
#	endif
		// The distinguished name specified for this replication operation already exists.

	, DS_DRA_INTERNAL_ERROR =
#	if defined ERROR_DS_DRA_INTERNAL_ERROR
			ERROR_DS_DRA_INTERNAL_ERROR
#	else
			0x20FA
#	endif
		// The replication system encountered an internal error.

	, DS_DRA_INCONSISTENT_DIT =
#	if defined ERROR_DS_DRA_INCONSISTENT_DIT
			ERROR_DS_DRA_INCONSISTENT_DIT
#	else
			0x20FB
#	endif
		// The replication operation encountered a database inconsistency.

	, DS_DRA_CONNECTION_FAILED =
#	if defined ERROR_DS_DRA_CONNECTION_FAILED
			ERROR_DS_DRA_CONNECTION_FAILED
#	else
			0x20FC
#	endif
		// The server specified for this replication operation could not be contacted.

	, DS_DRA_BAD_INSTANCE_TYPE =
#	if defined ERROR_DS_DRA_BAD_INSTANCE_TYPE
			ERROR_DS_DRA_BAD_INSTANCE_TYPE
#	else
			0x20FD
#	endif
		// The replication operation encountered an object with an invalid instance type.

	, DS_DRA_OUT_OF_MEM =
#	if defined ERROR_DS_DRA_OUT_OF_MEM
			ERROR_DS_DRA_OUT_OF_MEM
#	else
			0x20FE
#	endif
		// The replication operation failed to allocate memory.

	, DS_DRA_MAIL_PROBLEM =
#	if defined ERROR_DS_DRA_MAIL_PROBLEM
			ERROR_DS_DRA_MAIL_PROBLEM
#	else
			0x20FF
#	endif
		// The replication operation encountered an error with the mail system.

	, DS_DRA_REF_ALREADY_EXISTS =
#	if defined ERROR_DS_DRA_REF_ALREADY_EXISTS
			ERROR_DS_DRA_REF_ALREADY_EXISTS
#	else
			0x2100
#	endif
		// The replication reference information for the target server already exists.

	, DS_DRA_REF_NOT_FOUND =
#	if defined ERROR_DS_DRA_REF_NOT_FOUND
			ERROR_DS_DRA_REF_NOT_FOUND
#	else
			0x2101
#	endif
		// The replication reference information for the target server does not exist.

	, DS_DRA_OBJ_IS_REP_SOURCE =
#	if defined ERROR_DS_DRA_OBJ_IS_REP_SOURCE
			ERROR_DS_DRA_OBJ_IS_REP_SOURCE
#	else
			0x2102
#	endif
		// The naming context cannot be removed because it is replicated to another server.

	, DS_DRA_DB_ERROR =
#	if defined ERROR_DS_DRA_DB_ERROR
			ERROR_DS_DRA_DB_ERROR
#	else
			0x2103
#	endif
		// The replication operation encountered a database error.

	, DS_DRA_NO_REPLICA =
#	if defined ERROR_DS_DRA_NO_REPLICA
			ERROR_DS_DRA_NO_REPLICA
#	else
			0x2104
#	endif
		// The naming context is in the process of being removed or is not replicated from the specified server.

	, DS_DRA_ACCESS_DENIED =
#	if defined ERROR_DS_DRA_ACCESS_DENIED
			ERROR_DS_DRA_ACCESS_DENIED
#	else
			0x2105
#	endif
		// Replication access was denied.

	, DS_DRA_NOT_SUPPORTED =
#	if defined ERROR_DS_DRA_NOT_SUPPORTED
			ERROR_DS_DRA_NOT_SUPPORTED
#	else
			0x2106
#	endif
		// The requested operation is not supported by this version of the directory service.

	, DS_DRA_RPC_CANCELLED =
#	if defined ERROR_DS_DRA_RPC_CANCELLED
			ERROR_DS_DRA_RPC_CANCELLED
#	else
			0x2107
#	endif
		// The replication remote procedure call was cancelled.

	, DS_DRA_SOURCE_DISABLED =
#	if defined ERROR_DS_DRA_SOURCE_DISABLED
			ERROR_DS_DRA_SOURCE_DISABLED
#	else
			0x2108
#	endif
		// The source server is currently rejecting replication requests.

	, DS_DRA_SINK_DISABLED =
#	if defined ERROR_DS_DRA_SINK_DISABLED
			ERROR_DS_DRA_SINK_DISABLED
#	else
			0x2109
#	endif
		// The destination server is currently rejecting replication requests.

	, DS_DRA_NAME_COLLISION =
#	if defined ERROR_DS_DRA_NAME_COLLISION
			ERROR_DS_DRA_NAME_COLLISION
#	else
			0x210A
#	endif
		// The replication operation failed due to a collision of object names.

	, DS_DRA_SOURCE_REINSTALLED =
#	if defined ERROR_DS_DRA_SOURCE_REINSTALLED
			ERROR_DS_DRA_SOURCE_REINSTALLED
#	else
			0x210B
#	endif
		// The replication source has been reinstalled.

	, DS_DRA_MISSING_PARENT =
#	if defined ERROR_DS_DRA_MISSING_PARENT
			ERROR_DS_DRA_MISSING_PARENT
#	else
			0x210C
#	endif
		// The replication operation failed because a required parent object is missing.

	, DS_DRA_PREEMPTED =
#	if defined ERROR_DS_DRA_PREEMPTED
			ERROR_DS_DRA_PREEMPTED
#	else
			0x210D
#	endif
		// The replication operation was preempted.

	, DS_DRA_ABANDON_SYNC =
#	if defined ERROR_DS_DRA_ABANDON_SYNC
			ERROR_DS_DRA_ABANDON_SYNC
#	else
			0x210E
#	endif
		// The replication synchronization attempt was abandoned because of a lack of updates.

	, DS_DRA_SHUTDOWN =
#	if defined ERROR_DS_DRA_SHUTDOWN
			ERROR_DS_DRA_SHUTDOWN
#	else
			0x210F
#	endif
		// The replication operation was terminated because the system is shutting down.

	, DS_DRA_INCOMPATIBLE_PARTIAL_SET =
#	if defined ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET
			ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET
#	else
			0x2110
#	endif
		// Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of source partial attribute set.

	, DS_DRA_SOURCE_IS_PARTIAL_REPLICA =
#	if defined ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA
			ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA
#	else
			0x2111
#	endif
		// The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.

	, DS_DRA_EXTN_CONNECTION_FAILED =
#	if defined ERROR_DS_DRA_EXTN_CONNECTION_FAILED
			ERROR_DS_DRA_EXTN_CONNECTION_FAILED
#	else
			0x2112
#	endif
		// The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.

	, DS_INSTALL_SCHEMA_MISMATCH =
#	if defined ERROR_DS_INSTALL_SCHEMA_MISMATCH
			ERROR_DS_INSTALL_SCHEMA_MISMATCH
#	else
			0x2113
#	endif
		// The version of the directory service schema of the source forest is not compatible with the version of directory service on this computer.

	, DS_DUP_LINK_ID =
#	if defined ERROR_DS_DUP_LINK_ID
			ERROR_DS_DUP_LINK_ID
#	else
			0x2114
#	endif
		// Schema update failed: An attribute with the same link identifier already exists.

	, DS_NAME_ERROR_RESOLVING =
#	if defined ERROR_DS_NAME_ERROR_RESOLVING
			ERROR_DS_NAME_ERROR_RESOLVING
#	else
			0x2115
#	endif
		// Name translation: Generic processing error.

	, DS_NAME_ERROR_NOT_FOUND =
#	if defined ERROR_DS_NAME_ERROR_NOT_FOUND
			ERROR_DS_NAME_ERROR_NOT_FOUND
#	else
			0x2116
#	endif
		// Name translation: Could not find the name or insufficient right to see name.

	, DS_NAME_ERROR_NOT_UNIQUE =
#	if defined ERROR_DS_NAME_ERROR_NOT_UNIQUE
			ERROR_DS_NAME_ERROR_NOT_UNIQUE
#	else
			0x2117
#	endif
		// Name translation: Input name mapped to more than one output name.

	, DS_NAME_ERROR_NO_MAPPING =
#	if defined ERROR_DS_NAME_ERROR_NO_MAPPING
			ERROR_DS_NAME_ERROR_NO_MAPPING
#	else
			0x2118
#	endif
		// Name translation: Input name found, but not the associated output format.

	, DS_NAME_ERROR_DOMAIN_ONLY =
#	if defined ERROR_DS_NAME_ERROR_DOMAIN_ONLY
			ERROR_DS_NAME_ERROR_DOMAIN_ONLY
#	else
			0x2119
#	endif
		// Name translation: Unable to resolve completely, only the domain was found.

	, DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING =
#	if defined ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING
			ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING
#	else
			0x211A
#	endif
		// Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.

	, DS_CONSTRUCTED_ATT_MOD =
#	if defined ERROR_DS_CONSTRUCTED_ATT_MOD
			ERROR_DS_CONSTRUCTED_ATT_MOD
#	else
			0x211B
#	endif
		// Modification of a constructed attribute is not allowed.

	, DS_WRONG_OM_OBJ_CLASS =
#	if defined ERROR_DS_WRONG_OM_OBJ_CLASS
			ERROR_DS_WRONG_OM_OBJ_CLASS
#	else
			0x211C
#	endif
		// The OM-Object-Class specified is incorrect for an attribute with the specified syntax.

	, DS_DRA_REPL_PENDING =
#	if defined ERROR_DS_DRA_REPL_PENDING
			ERROR_DS_DRA_REPL_PENDING
#	else
			0x211D
#	endif
		// The replication request has been posted; waiting for reply.

	, DS_DS_REQUIRED =
#	if defined ERROR_DS_DS_REQUIRED
			ERROR_DS_DS_REQUIRED
#	else
			0x211E
#	endif
		// The requested operation requires a directory service, and none was available.

	, DS_INVALID_LDAP_DISPLAY_NAME =
#	if defined ERROR_DS_INVALID_LDAP_DISPLAY_NAME
			ERROR_DS_INVALID_LDAP_DISPLAY_NAME
#	else
			0x211F
#	endif
		// The LDAP display name of the class or attribute contains non-ASCII characters.

	, DS_NON_BASE_SEARCH =
#	if defined ERROR_DS_NON_BASE_SEARCH
			ERROR_DS_NON_BASE_SEARCH
#	else
			0x2120
#	endif
		// The requested search operation is only supported for base searches.

	, DS_CANT_RETRIEVE_ATTS =
#	if defined ERROR_DS_CANT_RETRIEVE_ATTS
			ERROR_DS_CANT_RETRIEVE_ATTS
#	else
			0x2121
#	endif
		// The search failed to retrieve attributes from the database.

	, DS_BACKLINK_WITHOUT_LINK =
#	if defined ERROR_DS_BACKLINK_WITHOUT_LINK
			ERROR_DS_BACKLINK_WITHOUT_LINK
#	else
			0x2122
#	endif
		// The schema update operation tried to add a backward link attribute that has no corresponding forward link.

	, DS_EPOCH_MISMATCH =
#	if defined ERROR_DS_EPOCH_MISMATCH
			ERROR_DS_EPOCH_MISMATCH
#	else
			0x2123
#	endif
		// Source and destination of a cross-domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.

	, DS_SRC_NAME_MISMATCH =
#	if defined ERROR_DS_SRC_NAME_MISMATCH
			ERROR_DS_SRC_NAME_MISMATCH
#	else
			0x2124
#	endif
		// Source and destination of a cross-domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.

	, DS_SRC_AND_DST_NC_IDENTICAL =
#	if defined ERROR_DS_SRC_AND_DST_NC_IDENTICAL
			ERROR_DS_SRC_AND_DST_NC_IDENTICAL
#	else
			0x2125
#	endif
		// Source and destination for the cross-domain move operation are identical. Caller should use local move operation instead of cross-domain move operation.

	, DS_DST_NC_MISMATCH =
#	if defined ERROR_DS_DST_NC_MISMATCH
			ERROR_DS_DST_NC_MISMATCH
#	else
			0x2126
#	endif
		// Source and destination for a cross-domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.

	, DS_NOT_AUTHORITIVE_FOR_DST_NC =
#	if defined ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC
			ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC
#	else
			0x2127
#	endif
		// Destination of a cross-domain move is not authoritative for the destination naming context.

	, DS_SRC_GUID_MISMATCH =
#	if defined ERROR_DS_SRC_GUID_MISMATCH
			ERROR_DS_SRC_GUID_MISMATCH
#	else
			0x2128
#	endif
		// Source and destination of a cross-domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.

	, DS_CANT_MOVE_DELETED_OBJECT =
#	if defined ERROR_DS_CANT_MOVE_DELETED_OBJECT
			ERROR_DS_CANT_MOVE_DELETED_OBJECT
#	else
			0x2129
#	endif
		// Object being moved across-domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.

	, DS_PDC_OPERATION_IN_PROGRESS =
#	if defined ERROR_DS_PDC_OPERATION_IN_PROGRESS
			ERROR_DS_PDC_OPERATION_IN_PROGRESS
#	else
			0x212A
#	endif
		// Another operation which requires exclusive access to the PDC FSMO is already in progress.

	, DS_CROSS_DOMAIN_CLEANUP_REQD =
#	if defined ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD
			ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD
#	else
			0x212B
#	endif
		// A cross-domain move operation failed such that two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.

	, DS_ILLEGAL_XDOM_MOVE_OPERATION =
#	if defined ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION
			ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION
#	else
			0x212C
#	endif
		// This object may not be moved across domain boundaries either because cross-domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.

	, DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS =
#	if defined ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS
			ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS
#	else
			0x212D
#	endif
		// Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.

	, DS_NC_MUST_HAVE_NC_PARENT =
#	if defined ERROR_DS_NC_MUST_HAVE_NC_PARENT
			ERROR_DS_NC_MUST_HAVE_NC_PARENT
#	else
			0x212E
#	endif
		// A naming context head must be the immediate child of another naming context head, not of an interior node.

	, DS_CR_IMPOSSIBLE_TO_VALIDATE =
#	if defined ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE
			ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE
#	else
			0x212F
#	endif
		// The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters.)

	, DS_DST_DOMAIN_NOT_NATIVE =
#	if defined ERROR_DS_DST_DOMAIN_NOT_NATIVE
			ERROR_DS_DST_DOMAIN_NOT_NATIVE
#	else
			0x2130
#	endif
		// Destination domain must be in native mode.

	, DS_MISSING_INFRASTRUCTURE_CONTAINER =
#	if defined ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER
			ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER
#	else
			0x2131
#	endif
		// The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.

	, DS_CANT_MOVE_ACCOUNT_GROUP =
#	if defined ERROR_DS_CANT_MOVE_ACCOUNT_GROUP
			ERROR_DS_CANT_MOVE_ACCOUNT_GROUP
#	else
			0x2132
#	endif
		// Cross-domain move of non-empty account groups is not allowed.

	, DS_CANT_MOVE_RESOURCE_GROUP =
#	if defined ERROR_DS_CANT_MOVE_RESOURCE_GROUP
			ERROR_DS_CANT_MOVE_RESOURCE_GROUP
#	else
			0x2133
#	endif
		// Cross-domain move of non-empty resource groups is not allowed.

	, DS_INVALID_SEARCH_FLAG =
#	if defined ERROR_DS_INVALID_SEARCH_FLAG
			ERROR_DS_INVALID_SEARCH_FLAG
#	else
			0x2134
#	endif
		// The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.

	, DS_NO_TREE_DELETE_ABOVE_NC =
#	if defined ERROR_DS_NO_TREE_DELETE_ABOVE_NC
			ERROR_DS_NO_TREE_DELETE_ABOVE_NC
#	else
			0x2135
#	endif
		// Tree deletions starting at an object which has an NC head as a descendant are not allowed.

	, DS_COULDNT_LOCK_TREE_FOR_DELETE =
#	if defined ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE
			ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE
#	else
			0x2136
#	endif
		// The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.

	, DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE =
#	if defined ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE
			ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE
#	else
			0x2137
#	endif
		// The directory service failed to identify the list of objects to delete while attempting a tree deletion.

	, DS_SAM_INIT_FAILURE =
#	if defined ERROR_DS_SAM_INIT_FAILURE
			ERROR_DS_SAM_INIT_FAILURE
#	else
			0x2138
#	endif
		// Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.

	, DS_SENSITIVE_GROUP_VIOLATION =
#	if defined ERROR_DS_SENSITIVE_GROUP_VIOLATION
			ERROR_DS_SENSITIVE_GROUP_VIOLATION
#	else
			0x2139
#	endif
		// Only an administrator can modify the membership list of an administrative group.

	, DS_CANT_MOD_PRIMARYGROUPID =
#	if defined ERROR_DS_CANT_MOD_PRIMARYGROUPID
			ERROR_DS_CANT_MOD_PRIMARYGROUPID
#	else
			0x213A
#	endif
		// Cannot change the primary group ID of a domain controller account.

	, DS_ILLEGAL_BASE_SCHEMA_MOD =
#	if defined ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD
			ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD
#	else
			0x213B
#	endif
		// An attempt is made to modify the base schema.

	, DS_NONSAFE_SCHEMA_CHANGE =
#	if defined ERROR_DS_NONSAFE_SCHEMA_CHANGE
			ERROR_DS_NONSAFE_SCHEMA_CHANGE
#	else
			0x213C
#	endif
		// Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.

	, DS_SCHEMA_UPDATE_DISALLOWED =
#	if defined ERROR_DS_SCHEMA_UPDATE_DISALLOWED
			ERROR_DS_SCHEMA_UPDATE_DISALLOWED
#	else
			0x213D
#	endif
		// Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.

	, DS_CANT_CREATE_UNDER_SCHEMA =
#	if defined ERROR_DS_CANT_CREATE_UNDER_SCHEMA
			ERROR_DS_CANT_CREATE_UNDER_SCHEMA
#	else
			0x213E
#	endif
		// An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.

	, DS_INSTALL_NO_SRC_SCH_VERSION =
#	if defined ERROR_DS_INSTALL_NO_SRC_SCH_VERSION
			ERROR_DS_INSTALL_NO_SRC_SCH_VERSION
#	else
			0x213F
#	endif
		// The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.

	, DS_INSTALL_NO_SCH_VERSION_IN_INIFILE =
#	if defined ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE
			ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE
#	else
			0x2140
#	endif
		// The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.

	, DS_INVALID_GROUP_TYPE =
#	if defined ERROR_DS_INVALID_GROUP_TYPE
			ERROR_DS_INVALID_GROUP_TYPE
#	else
			0x2141
#	endif
		// The specified group type is invalid.

	, DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN =
#	if defined ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN
			ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN
#	else
			0x2142
#	endif
		// You cannot nest global groups in a mixed domain if the group is security-enabled.

	, DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN =
#	if defined ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN
			ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN
#	else
			0x2143
#	endif
		// You cannot nest local groups in a mixed domain if the group is security-enabled.

	, DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER =
#	if defined ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER
			ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER
#	else
			0x2144
#	endif
		// A global group cannot have a local group as a member.

	, DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER =
#	if defined ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER
			ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER
#	else
			0x2145
#	endif
		// A global group cannot have a universal group as a member.

	, DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER =
#	if defined ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER
			ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER
#	else
			0x2146
#	endif
		// A universal group cannot have a local group as a member.

	, DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER =
#	if defined ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER
			ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER
#	else
			0x2147
#	endif
		// A global group cannot have a cross-domain member.

	, DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER =
#	if defined ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER
			ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER
#	else
			0x2148
#	endif
		// A local group cannot have another cross domain local group as a member.

	, DS_HAVE_PRIMARY_MEMBERS =
#	if defined ERROR_DS_HAVE_PRIMARY_MEMBERS
			ERROR_DS_HAVE_PRIMARY_MEMBERS
#	else
			0x2149
#	endif
		// A group with primary members cannot change to a security-disabled group.

	, DS_STRING_SD_CONVERSION_FAILED =
#	if defined ERROR_DS_STRING_SD_CONVERSION_FAILED
			ERROR_DS_STRING_SD_CONVERSION_FAILED
#	else
			0x214A
#	endif
		// The schema cache load failed to convert the string default SD on a class-schema object.

	, DS_NAMING_MASTER_GC =
#	if defined ERROR_DS_NAMING_MASTER_GC
			ERROR_DS_NAMING_MASTER_GC
#	else
			0x214B
#	endif
		// Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers.)

	, DS_DNS_LOOKUP_FAILURE =
#	if defined ERROR_DS_DNS_LOOKUP_FAILURE
			ERROR_DS_DNS_LOOKUP_FAILURE
#	else
			0x214C
#	endif
		// The DSA operation is unable to proceed because of a DNS lookup failure.

	, DS_COULDNT_UPDATE_SPNS =
#	if defined ERROR_DS_COULDNT_UPDATE_SPNS
			ERROR_DS_COULDNT_UPDATE_SPNS
#	else
			0x214D
#	endif
		// While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.

	, DS_CANT_RETRIEVE_SD =
#	if defined ERROR_DS_CANT_RETRIEVE_SD
			ERROR_DS_CANT_RETRIEVE_SD
#	else
			0x214E
#	endif
		// The Security Descriptor attribute could not be read.

	, DS_KEY_NOT_UNIQUE =
#	if defined ERROR_DS_KEY_NOT_UNIQUE
			ERROR_DS_KEY_NOT_UNIQUE
#	else
			0x214F
#	endif
		// The object requested was not found, but an object with that key was found.

	, DS_WRONG_LINKED_ATT_SYNTAX =
#	if defined ERROR_DS_WRONG_LINKED_ATT_SYNTAX
			ERROR_DS_WRONG_LINKED_ATT_SYNTAX
#	else
			0x2150
#	endif
		// The syntax of the linked attribute being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1.

	, DS_SAM_NEED_BOOTKEY_PASSWORD =
#	if defined ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD
			ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD
#	else
			0x2151
#	endif
		// Security Account Manager needs to get the boot password.

	, DS_SAM_NEED_BOOTKEY_FLOPPY =
#	if defined ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY
			ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY
#	else
			0x2152
#	endif
		// Security Account Manager needs to get the boot key from floppy disk.

	, DS_CANT_START =
#	if defined ERROR_DS_CANT_START
			ERROR_DS_CANT_START
#	else
			0x2153
#	endif
		// Directory Service cannot start.

	, DS_INIT_FAILURE =
#	if defined ERROR_DS_INIT_FAILURE
			ERROR_DS_INIT_FAILURE
#	else
			0x2154
#	endif
		// Directory Services could not start.

	, DS_NO_PKT_PRIVACY_ON_CONNECTION =
#	if defined ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION
			ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION
#	else
			0x2155
#	endif
		// The connection between client and server requires packet privacy or better.

	, DS_SOURCE_DOMAIN_IN_FOREST =
#	if defined ERROR_DS_SOURCE_DOMAIN_IN_FOREST
			ERROR_DS_SOURCE_DOMAIN_IN_FOREST
#	else
			0x2156
#	endif
		// The source domain may not be in the same forest as destination.

	, DS_DESTINATION_DOMAIN_NOT_IN_FOREST =
#	if defined ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST
			ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST
#	else
			0x2157
#	endif
		// The destination domain must be in the forest.

	, DS_DESTINATION_AUDITING_NOT_ENABLED =
#	if defined ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED
			ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED
#	else
			0x2158
#	endif
		// The operation requires that destination domain auditing be enabled.

	, DS_CANT_FIND_DC_FOR_SRC_DOMAIN =
#	if defined ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN
			ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN
#	else
			0x2159
#	endif
		// The operation couldn't locate a DC for the source domain.

	, DS_SRC_OBJ_NOT_GROUP_OR_USER =
#	if defined ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER
			ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER
#	else
			0x215A
#	endif
		// The source object must be a group or user.

	, DS_SRC_SID_EXISTS_IN_FOREST =
#	if defined ERROR_DS_SRC_SID_EXISTS_IN_FOREST
			ERROR_DS_SRC_SID_EXISTS_IN_FOREST
#	else
			0x215B
#	endif
		// The source object's SID already exists in destination forest.

	, DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH =
#	if defined ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH
			ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH
#	else
			0x215C
#	endif
		// The source and destination object must be of the same type.

	, SAM_INIT_FAILURE =
#	if defined ERROR_SAM_INIT_FAILURE
			ERROR_SAM_INIT_FAILURE
#	else
			0x215D
#	endif
		// Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.

	, DS_DRA_SCHEMA_INFO_SHIP =
#	if defined ERROR_DS_DRA_SCHEMA_INFO_SHIP
			ERROR_DS_DRA_SCHEMA_INFO_SHIP
#	else
			0x215E
#	endif
		// Schema information could not be included in the replication request.

	, DS_DRA_SCHEMA_CONFLICT =
#	if defined ERROR_DS_DRA_SCHEMA_CONFLICT
			ERROR_DS_DRA_SCHEMA_CONFLICT
#	else
			0x215F
#	endif
		// The replication operation could not be completed due to a schema incompatibility.

	, DS_DRA_EARLIER_SCHEMA_CONFLICT =
#	if defined ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT
			ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT
#	else
			0x2160
#	endif
		// The replication operation could not be completed due to a previous schema incompatibility.

	, DS_DRA_OBJ_NC_MISMATCH =
#	if defined ERROR_DS_DRA_OBJ_NC_MISMATCH
			ERROR_DS_DRA_OBJ_NC_MISMATCH
#	else
			0x2161
#	endif
		// The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.

	, DS_NC_STILL_HAS_DSAS =
#	if defined ERROR_DS_NC_STILL_HAS_DSAS
			ERROR_DS_NC_STILL_HAS_DSAS
#	else
			0x2162
#	endif
		// The requested domain could not be deleted because there exist domain controllers that still host this domain.

	, DS_GC_REQUIRED =
#	if defined ERROR_DS_GC_REQUIRED
			ERROR_DS_GC_REQUIRED
#	else
			0x2163
#	endif
		// The requested operation can be performed only on a global catalog server.

	, DS_LOCAL_MEMBER_OF_LOCAL_ONLY =
#	if defined ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY
			ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY
#	else
			0x2164
#	endif
		// A local group can only be a member of other local groups in the same domain.

	, DS_NO_FPO_IN_UNIVERSAL_GROUPS =
#	if defined ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS
			ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS
#	else
			0x2165
#	endif
		// Foreign security principals cannot be members of universal groups.

	, DS_CANT_ADD_TO_GC =
#	if defined ERROR_DS_CANT_ADD_TO_GC
			ERROR_DS_CANT_ADD_TO_GC
#	else
			0x2166
#	endif
		// The attribute is not allowed to be replicated to the GC because of security reasons.

	, DS_NO_CHECKPOINT_WITH_PDC =
#	if defined ERROR_DS_NO_CHECKPOINT_WITH_PDC
			ERROR_DS_NO_CHECKPOINT_WITH_PDC
#	else
			0x2167
#	endif
		// The checkpoint with the PDC could not be taken because there too many modifications being processed currently.

	, DS_SOURCE_AUDITING_NOT_ENABLED =
#	if defined ERROR_DS_SOURCE_AUDITING_NOT_ENABLED
			ERROR_DS_SOURCE_AUDITING_NOT_ENABLED
#	else
			0x2168
#	endif
		// The operation requires that source domain auditing be enabled.

	, DS_CANT_CREATE_IN_NONDOMAIN_NC =
#	if defined ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC
			ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC
#	else
			0x2169
#	endif
		// Security principal objects can only be created inside domain naming contexts.

	, DS_INVALID_NAME_FOR_SPN =
#	if defined ERROR_DS_INVALID_NAME_FOR_SPN
			ERROR_DS_INVALID_NAME_FOR_SPN
#	else
			0x216A
#	endif
		// A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.

	, DS_FILTER_USES_CONTRUCTED_ATTRS =
#	if defined ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS
			ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS
#	else
			0x216B
#	endif
		// A Filter was passed that uses constructed attributes.

	, DS_UNICODEPWD_NOT_IN_QUOTES =
#	if defined ERROR_DS_UNICODEPWD_NOT_IN_QUOTES
			ERROR_DS_UNICODEPWD_NOT_IN_QUOTES
#	else
			0x216C
#	endif
		// The unicodePwd attribute value must be enclosed in double quotes.

	, DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED =
#	if defined ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED
			ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED
#	else
			0x216D
#	endif
		// Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.

	, DS_MUST_BE_RUN_ON_DST_DC =
#	if defined ERROR_DS_MUST_BE_RUN_ON_DST_DC
			ERROR_DS_MUST_BE_RUN_ON_DST_DC
#	else
			0x216E
#	endif
		// For security reasons, the operation must be run on the destination DC.

	, DS_SRC_DC_MUST_BE_SP4_OR_GREATER =
#	if defined ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER
			ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER
#	else
			0x216F
#	endif
		// For security reasons, the source DC must be NT4SP4 or greater.

	, DS_CANT_TREE_DELETE_CRITICAL_OBJ =
#	if defined ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ
			ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ
#	else
			0x2170
#	endif
		// Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.

	, DS_INIT_FAILURE_CONSOLE =
#	if defined ERROR_DS_INIT_FAILURE_CONSOLE
			ERROR_DS_INIT_FAILURE_CONSOLE
#	else
			0x2171
#	endif
		// Directory Services could not start because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.

	, DS_SAM_INIT_FAILURE_CONSOLE =
#	if defined ERROR_DS_SAM_INIT_FAILURE_CONSOLE
			ERROR_DS_SAM_INIT_FAILURE_CONSOLE
#	else
			0x2172
#	endif
		// Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.

	, DS_FOREST_VERSION_TOO_HIGH =
#	if defined ERROR_DS_FOREST_VERSION_TOO_HIGH
			ERROR_DS_FOREST_VERSION_TOO_HIGH
#	else
			0x2173
#	endif
		// The version of the operating system is incompatible with the current AD DS forest functional level or AD LDS Configuration Set functional level. You must upgrade to a new version of the operating system before this server can become an AD DS Domain Controller or add an AD LDS Instance in this AD DS Forest or AD LDS Configuration Set.

	, DS_DOMAIN_VERSION_TOO_HIGH =
#	if defined ERROR_DS_DOMAIN_VERSION_TOO_HIGH
			ERROR_DS_DOMAIN_VERSION_TOO_HIGH
#	else
			0x2174
#	endif
		// The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.

	, DS_FOREST_VERSION_TOO_LOW =
#	if defined ERROR_DS_FOREST_VERSION_TOO_LOW
			ERROR_DS_FOREST_VERSION_TOO_LOW
#	else
			0x2175
#	endif
		// The version of the operating system installed on this server no longer supports the current AD DS Forest functional level or AD LDS Configuration Set functional level. You must raise the AD DS Forest functional level or AD LDS Configuration Set functional level before this server can become an AD DS Domain Controller or an AD LDS Instance in this Forest or Configuration Set.

	, DS_DOMAIN_VERSION_TOO_LOW =
#	if defined ERROR_DS_DOMAIN_VERSION_TOO_LOW
			ERROR_DS_DOMAIN_VERSION_TOO_LOW
#	else
			0x2176
#	endif
		// The version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.

	, DS_INCOMPATIBLE_VERSION =
#	if defined ERROR_DS_INCOMPATIBLE_VERSION
			ERROR_DS_INCOMPATIBLE_VERSION
#	else
			0x2177
#	endif
		// The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.

	, DS_LOW_DSA_VERSION =
#	if defined ERROR_DS_LOW_DSA_VERSION
			ERROR_DS_LOW_DSA_VERSION
#	else
			0x2178
#	endif
		// The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.

	, DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN =
#	if defined ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN
			ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN
#	else
			0x2179
#	endif
		// The forest functional level cannot be raised to the requested value since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode, for you to raise the forest functional level.

	, DS_NOT_SUPPORTED_SORT_ORDER =
#	if defined ERROR_DS_NOT_SUPPORTED_SORT_ORDER
			ERROR_DS_NOT_SUPPORTED_SORT_ORDER
#	else
			0x217A
#	endif
		// The sort order requested is not supported.

	, DS_NAME_NOT_UNIQUE =
#	if defined ERROR_DS_NAME_NOT_UNIQUE
			ERROR_DS_NAME_NOT_UNIQUE
#	else
			0x217B
#	endif
		// The requested name already exists as a unique identifier.

	, DS_MACHINE_ACCOUNT_CREATED_PRENT4 =
#	if defined ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4
			ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4
#	else
			0x217C
#	endif
		// The machine account was created pre-NT4. The account needs to be recreated.

	, DS_OUT_OF_VERSION_STORE =
#	if defined ERROR_DS_OUT_OF_VERSION_STORE
			ERROR_DS_OUT_OF_VERSION_STORE
#	else
			0x217D
#	endif
		// The database is out of version store.

	, DS_INCOMPATIBLE_CONTROLS_USED =
#	if defined ERROR_DS_INCOMPATIBLE_CONTROLS_USED
			ERROR_DS_INCOMPATIBLE_CONTROLS_USED
#	else
			0x217E
#	endif
		// Unable to continue operation because multiple conflicting controls were used.

	, DS_NO_REF_DOMAIN =
#	if defined ERROR_DS_NO_REF_DOMAIN
			ERROR_DS_NO_REF_DOMAIN
#	else
			0x217F
#	endif
		// Unable to find a valid security descriptor reference domain for this partition.

	, DS_RESERVED_LINK_ID =
#	if defined ERROR_DS_RESERVED_LINK_ID
			ERROR_DS_RESERVED_LINK_ID
#	else
			0x2180
#	endif
		// Schema update failed: The link identifier is reserved.

	, DS_LINK_ID_NOT_AVAILABLE =
#	if defined ERROR_DS_LINK_ID_NOT_AVAILABLE
			ERROR_DS_LINK_ID_NOT_AVAILABLE
#	else
			0x2181
#	endif
		// Schema update failed: There are no link identifiers available.

	, DS_AG_CANT_HAVE_UNIVERSAL_MEMBER =
#	if defined ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER
			ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER
#	else
			0x2182
#	endif
		// An account group cannot have a universal group as a member.

	, DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE =
#	if defined ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE
			ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE
#	else
			0x2183
#	endif
		// Rename or move operations on naming context heads or read-only objects are not allowed.

	, DS_NO_OBJECT_MOVE_IN_SCHEMA_NC =
#	if defined ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC
			ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC
#	else
			0x2184
#	endif
		// Move operations on objects in the schema naming context are not allowed.

	, DS_MODIFYDN_DISALLOWED_BY_FLAG =
#	if defined ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG
			ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG
#	else
			0x2185
#	endif
		// A system flag has been set on the object and does not allow the object to be moved or renamed.

	, DS_MODIFYDN_WRONG_GRANDPARENT =
#	if defined ERROR_DS_MODIFYDN_WRONG_GRANDPARENT
			ERROR_DS_MODIFYDN_WRONG_GRANDPARENT
#	else
			0x2186
#	endif
		// This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.

	, DS_NAME_ERROR_TRUST_REFERRAL =
#	if defined ERROR_DS_NAME_ERROR_TRUST_REFERRAL
			ERROR_DS_NAME_ERROR_TRUST_REFERRAL
#	else
			0x2187
#	endif
		// Unable to resolve completely, a referral to another forest is generated.

	, NOT_SUPPORTED_ON_STANDARD_SERVER =
#	if defined ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER
			ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER
#	else
			0x2188
#	endif
		// The requested action is not supported on standard server.

	, DS_CANT_ACCESS_REMOTE_PART_OF_AD =
#	if defined ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD
			ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD
#	else
			0x2189
#	endif
		// Could not access a partition of the directory service located on a remote server. Make sure at least one server is running for the partition in question.

	, DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 =
#	if defined ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2
			ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2
#	else
			0x218A
#	endif
		// The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.

	, DS_THREAD_LIMIT_EXCEEDED =
#	if defined ERROR_DS_THREAD_LIMIT_EXCEEDED
			ERROR_DS_THREAD_LIMIT_EXCEEDED
#	else
			0x218B
#	endif
		// The thread limit for this request was exceeded.

	, DS_NOT_CLOSEST =
#	if defined ERROR_DS_NOT_CLOSEST
			ERROR_DS_NOT_CLOSEST
#	else
			0x218C
#	endif
		// The Global catalog server is not in the closest site.

	, DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF =
#	if defined ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF
			ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF
#	else
			0x218D
#	endif
		// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.

	, DS_SINGLE_USER_MODE_FAILED =
#	if defined ERROR_DS_SINGLE_USER_MODE_FAILED
			ERROR_DS_SINGLE_USER_MODE_FAILED
#	else
			0x218E
#	endif
		// The Directory Service failed to enter single user mode.

	, DS_NTDSCRIPT_SYNTAX_ERROR =
#	if defined ERROR_DS_NTDSCRIPT_SYNTAX_ERROR
			ERROR_DS_NTDSCRIPT_SYNTAX_ERROR
#	else
			0x218F
#	endif
		// The Directory Service cannot parse the script because of a syntax error.

	, DS_NTDSCRIPT_PROCESS_ERROR =
#	if defined ERROR_DS_NTDSCRIPT_PROCESS_ERROR
			ERROR_DS_NTDSCRIPT_PROCESS_ERROR
#	else
			0x2190
#	endif
		// The Directory Service cannot process the script because of an error.

	, DS_DIFFERENT_REPL_EPOCHS =
#	if defined ERROR_DS_DIFFERENT_REPL_EPOCHS
			ERROR_DS_DIFFERENT_REPL_EPOCHS
#	else
			0x2191
#	endif
		// The directory service cannot perform the requested operation because the servers involved are of different replication epochs (which is usually related to a domain rename that is in progress).

	, DS_DRS_EXTENSIONS_CHANGED =
#	if defined ERROR_DS_DRS_EXTENSIONS_CHANGED
			ERROR_DS_DRS_EXTENSIONS_CHANGED
#	else
			0x2192
#	endif
		// The directory service binding must be renegotiated due to a change in the server extensions information.

	, DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR =
#	if defined ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR
			ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR
#	else
			0x2193
#	endif
		// Operation not allowed on a disabled cross ref.

	, DS_NO_MSDS_INTID =
#	if defined ERROR_DS_NO_MSDS_INTID
			ERROR_DS_NO_MSDS_INTID
#	else
			0x2194
#	endif
		// Schema update failed: No values for msDS-IntId are available.

	, DS_DUP_MSDS_INTID =
#	if defined ERROR_DS_DUP_MSDS_INTID
			ERROR_DS_DUP_MSDS_INTID
#	else
			0x2195
#	endif
		// Schema update failed: Duplicate msDS-INtId. Retry the operation.

	, DS_EXISTS_IN_RDNATTID =
#	if defined ERROR_DS_EXISTS_IN_RDNATTID
			ERROR_DS_EXISTS_IN_RDNATTID
#	else
			0x2196
#	endif
		// Schema deletion failed: attribute is used in rDNAttID.

	, DS_AUTHORIZATION_FAILED =
#	if defined ERROR_DS_AUTHORIZATION_FAILED
			ERROR_DS_AUTHORIZATION_FAILED
#	else
			0x2197
#	endif
		// The directory service failed to authorize the request.

	, DS_INVALID_SCRIPT =
#	if defined ERROR_DS_INVALID_SCRIPT
			ERROR_DS_INVALID_SCRIPT
#	else
			0x2198
#	endif
		// The Directory Service cannot process the script because it is invalid.

	, DS_REMOTE_CROSSREF_OP_FAILED =
#	if defined ERROR_DS_REMOTE_CROSSREF_OP_FAILED
			ERROR_DS_REMOTE_CROSSREF_OP_FAILED
#	else
			0x2199
#	endif
		// The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.

	, DS_CROSS_REF_BUSY =
#	if defined ERROR_DS_CROSS_REF_BUSY
			ERROR_DS_CROSS_REF_BUSY
#	else
			0x219A
#	endif
		// A cross reference is in use locally with the same name.

	, DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN =
#	if defined ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN
			ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN
#	else
			0x219B
#	endif
		// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.

	, DS_CANT_DEMOTE_WITH_WRITEABLE_NC =
#	if defined ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC
			ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC
#	else
			0x219C
#	endif
		// Writeable NCs prevent this DC from demoting.

	, DS_DUPLICATE_ID_FOUND =
#	if defined ERROR_DS_DUPLICATE_ID_FOUND
			ERROR_DS_DUPLICATE_ID_FOUND
#	else
			0x219D
#	endif
		// The requested object has a non-unique identifier and cannot be retrieved.

	, DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT =
#	if defined ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT
			ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT
#	else
			0x219E
#	endif
		// Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.

	, DS_GROUP_CONVERSION_ERROR =
#	if defined ERROR_DS_GROUP_CONVERSION_ERROR
			ERROR_DS_GROUP_CONVERSION_ERROR
#	else
			0x219F
#	endif
		// The group cannot be converted due to attribute restrictions on the requested group type.

	, DS_CANT_MOVE_APP_BASIC_GROUP =
#	if defined ERROR_DS_CANT_MOVE_APP_BASIC_GROUP
			ERROR_DS_CANT_MOVE_APP_BASIC_GROUP
#	else
			0x21A0
#	endif
		// Cross-domain move of non-empty basic application groups is not allowed.

	, DS_CANT_MOVE_APP_QUERY_GROUP =
#	if defined ERROR_DS_CANT_MOVE_APP_QUERY_GROUP
			ERROR_DS_CANT_MOVE_APP_QUERY_GROUP
#	else
			0x21A1
#	endif
		// Cross-domain move of non-empty query based application groups is not allowed.

	, DS_ROLE_NOT_VERIFIED =
#	if defined ERROR_DS_ROLE_NOT_VERIFIED
			ERROR_DS_ROLE_NOT_VERIFIED
#	else
			0x21A2
#	endif
		// The FSMO role ownership could not be verified because its directory partition has not replicated successfully with at least one replication partner.

	, DS_WKO_CONTAINER_CANNOT_BE_SPECIAL =
#	if defined ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL
			ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL
#	else
			0x21A3
#	endif
		// The target container for a redirection of a well known object container cannot already be a special container.

	, DS_DOMAIN_RENAME_IN_PROGRESS =
#	if defined ERROR_DS_DOMAIN_RENAME_IN_PROGRESS
			ERROR_DS_DOMAIN_RENAME_IN_PROGRESS
#	else
			0x21A4
#	endif
		// The Directory Service cannot perform the requested operation because a domain rename operation is in progress.

	, DS_EXISTING_AD_CHILD_NC =
#	if defined ERROR_DS_EXISTING_AD_CHILD_NC
			ERROR_DS_EXISTING_AD_CHILD_NC
#	else
			0x21A5
#	endif
		// The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method.

	, DS_REPL_LIFETIME_EXCEEDED =
#	if defined ERROR_DS_REPL_LIFETIME_EXCEEDED
			ERROR_DS_REPL_LIFETIME_EXCEEDED
#	else
			0x21A6
#	endif
		// The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.

	, DS_DISALLOWED_IN_SYSTEM_CONTAINER =
#	if defined ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER
			ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER
#	else
			0x21A7
#	endif
		// The requested operation is not allowed on an object under the system container.

	, DS_LDAP_SEND_QUEUE_FULL =
#	if defined ERROR_DS_LDAP_SEND_QUEUE_FULL
			ERROR_DS_LDAP_SEND_QUEUE_FULL
#	else
			0x21A8
#	endif
		// The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.

	, DS_DRA_OUT_SCHEDULE_WINDOW =
#	if defined ERROR_DS_DRA_OUT_SCHEDULE_WINDOW
			ERROR_DS_DRA_OUT_SCHEDULE_WINDOW
#	else
			0x21A9
#	endif
		// The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.

	, DS_POLICY_NOT_KNOWN =
#	if defined ERROR_DS_POLICY_NOT_KNOWN
			ERROR_DS_POLICY_NOT_KNOWN
#	else
			0x21AA
#	endif
		// At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies.

	, NO_SITE_SETTINGS_OBJECT =
#	if defined ERROR_NO_SITE_SETTINGS_OBJECT
			ERROR_NO_SITE_SETTINGS_OBJECT
#	else
			0x21AB
#	endif
		// The site settings object for the specified site does not exist.

	, NO_SECRETS =
#	if defined ERROR_NO_SECRETS
			ERROR_NO_SECRETS
#	else
			0x21AC
#	endif
		// The local account store does not contain secret material for the specified account.

	, NO_WRITABLE_DC_FOUND =
#	if defined ERROR_NO_WRITABLE_DC_FOUND
			ERROR_NO_WRITABLE_DC_FOUND
#	else
			0x21AD
#	endif
		// Could not find a writable domain controller in the domain.

	, DS_NO_SERVER_OBJECT =
#	if defined ERROR_DS_NO_SERVER_OBJECT
			ERROR_DS_NO_SERVER_OBJECT
#	else
			0x21AE
#	endif
		// The server object for the domain controller does not exist.

	, DS_NO_NTDSA_OBJECT =
#	if defined ERROR_DS_NO_NTDSA_OBJECT
			ERROR_DS_NO_NTDSA_OBJECT
#	else
			0x21AF
#	endif
		// The NTDS Settings object for the domain controller does not exist.

	, DS_NON_ASQ_SEARCH =
#	if defined ERROR_DS_NON_ASQ_SEARCH
			ERROR_DS_NON_ASQ_SEARCH
#	else
			0x21B0
#	endif
		// The requested search operation is not supported for ASQ searches.

	, DS_AUDIT_FAILURE =
#	if defined ERROR_DS_AUDIT_FAILURE
			ERROR_DS_AUDIT_FAILURE
#	else
			0x21B1
#	endif
		// A required audit event could not be generated for the operation.

	, DS_INVALID_SEARCH_FLAG_SUBTREE =
#	if defined ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE
			ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE
#	else
			0x21B2
#	endif
		// The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes.

	, DS_INVALID_SEARCH_FLAG_TUPLE =
#	if defined ERROR_DS_INVALID_SEARCH_FLAG_TUPLE
			ERROR_DS_INVALID_SEARCH_FLAG_TUPLE
#	else
			0x21B3
#	endif
		// The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings.

	, DS_HIERARCHY_TABLE_TOO_DEEP =
#	if defined ERROR_DS_HIERARCHY_TABLE_TOO_DEEP
			ERROR_DS_HIERARCHY_TABLE_TOO_DEEP
#	else
			0x21B4
#	endif
		// The address books are nested too deeply. Failed to build the hierarchy table.

	, DS_DRA_CORRUPT_UTD_VECTOR =
#	if defined ERROR_DS_DRA_CORRUPT_UTD_VECTOR
			ERROR_DS_DRA_CORRUPT_UTD_VECTOR
#	else
			0x21B5
#	endif
		// The specified up-to-date-ness vector is corrupt.

	, DS_DRA_SECRETS_DENIED =
#	if defined ERROR_DS_DRA_SECRETS_DENIED
			ERROR_DS_DRA_SECRETS_DENIED
#	else
			0x21B6
#	endif
		// The request to replicate secrets is denied.

	, DS_RESERVED_MAPI_ID =
#	if defined ERROR_DS_RESERVED_MAPI_ID
			ERROR_DS_RESERVED_MAPI_ID
#	else
			0x21B7
#	endif
		// Schema update failed: The MAPI identifier is reserved.

	, DS_MAPI_ID_NOT_AVAILABLE =
#	if defined ERROR_DS_MAPI_ID_NOT_AVAILABLE
			ERROR_DS_MAPI_ID_NOT_AVAILABLE
#	else
			0x21B8
#	endif
		// Schema update failed: There are no MAPI identifiers available.

	, DS_DRA_MISSING_KRBTGT_SECRET =
#	if defined ERROR_DS_DRA_MISSING_KRBTGT_SECRET
			ERROR_DS_DRA_MISSING_KRBTGT_SECRET
#	else
			0x21B9
#	endif
		// The replication operation failed because the required attributes of the local krbtgt object are missing.

	, DS_DOMAIN_NAME_EXISTS_IN_FOREST =
#	if defined ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST
			ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST
#	else
			0x21BA
#	endif
		// The domain name of the trusted domain already exists in the forest.

	, DS_FLAT_NAME_EXISTS_IN_FOREST =
#	if defined ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST
			ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST
#	else
			0x21BB
#	endif
		// The flat name of the trusted domain already exists in the forest.

	, INVALID_USER_PRINCIPAL_NAME =
#	if defined ERROR_INVALID_USER_PRINCIPAL_NAME
			ERROR_INVALID_USER_PRINCIPAL_NAME
#	else
			0x21BC
#	endif
		// The User Principal Name (UPN) is invalid.

	, DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS =
#	if defined ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS
			ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS
#	else
			0x21BD
#	endif
		// OID mapped groups cannot have members.

	, DS_OID_NOT_FOUND =
#	if defined ERROR_DS_OID_NOT_FOUND
			ERROR_DS_OID_NOT_FOUND
#	else
			0x21BE
#	endif
		// The specified OID cannot be found.

	, DS_DRA_RECYCLED_TARGET =
#	if defined ERROR_DS_DRA_RECYCLED_TARGET
			ERROR_DS_DRA_RECYCLED_TARGET
#	else
			0x21BF
#	endif
		// The replication operation failed because the target object referred by a link value is recycled.

	, DS_DISALLOWED_NC_REDIRECT =
#	if defined ERROR_DS_DISALLOWED_NC_REDIRECT
			ERROR_DS_DISALLOWED_NC_REDIRECT
#	else
			0x21C0
#	endif
		// The redirect operation failed because the target object is in a NC different from the domain NC of the current domain controller.

	, DS_HIGH_ADLDS_FFL =
#	if defined ERROR_DS_HIGH_ADLDS_FFL
			ERROR_DS_HIGH_ADLDS_FFL
#	else
			0x21C1
#	endif
		// The functional level of the AD LDS configuration set cannot be lowered to the requested value.

	, DS_HIGH_DSA_VERSION =
#	if defined ERROR_DS_HIGH_DSA_VERSION
			ERROR_DS_HIGH_DSA_VERSION
#	else
			0x21C2
#	endif
		// The functional level of the domain (or forest) cannot be lowered to the requested value.

	, DS_LOW_ADLDS_FFL =
#	if defined ERROR_DS_LOW_ADLDS_FFL
			ERROR_DS_LOW_ADLDS_FFL
#	else
			0x21C3
#	endif
		// The functional level of the AD LDS configuration set cannot be raised to the requested value, because there exist one or more ADLDS instances that are at a lower incompatible functional level.

	, DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION =
#	if defined ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION
			ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION
#	else
			0x21C4
#	endif
		// The domain join cannot be completed because the SID of the domain you attempted to join was identical to the SID of this machine. This is a symptom of an improperly cloned operating system install. You should run sysprep on this machine in order to generate a new machine SID. Please see https://go.microsoft.com/fwlink/p/?linkid=168895 for more information.

	, DS_UNDELETE_SAM_VALIDATION_FAILED =
#	if defined ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED
			ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED
#	else
			0x21C5
#	endif
		// The undelete operation failed because the Sam Account Name or Additional Sam Account Name of the object being undeleted conflicts with an existing live object.

	, INCORRECT_ACCOUNT_TYPE =
#	if defined ERROR_INCORRECT_ACCOUNT_TYPE
			ERROR_INCORRECT_ACCOUNT_TYPE
#	else
			0x21C6
#	endif
		// The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site.
};

}}} // flame_ide::os::error

namespace flame_ide
{namespace os
{namespace error
{

const char *systemCodeToString7(os::Status status) noexcept
{
	const auto code = static_cast<SystemCode>(status);
	switch (code)

	{
		case SystemCode::DS_NOT_INSTALLED:
			RETURN_STATIC_STRING(
					"An error occurred while installing the directory service. For more"
					" information, see the event log"
			);
		case SystemCode::DS_MEMBERSHIP_EVALUATED_LOCALLY:
			RETURN_STATIC_STRING(
					"The directory service evaluated group memberships locally"
			);
		case SystemCode::DS_NO_ATTRIBUTE_OR_VALUE:
			RETURN_STATIC_STRING(
					"The specified directory service attribute or value does not exist"
			);
		case SystemCode::DS_INVALID_ATTRIBUTE_SYNTAX:
			RETURN_STATIC_STRING(
					"The attribute syntax specified to the directory service is invalid"
			);
		case SystemCode::DS_ATTRIBUTE_TYPE_UNDEFINED:
			RETURN_STATIC_STRING(
					"The attribute type specified to the directory service is not defined"
			);
		case SystemCode::DS_ATTRIBUTE_OR_VALUE_EXISTS:
			RETURN_STATIC_STRING(
					"The specified directory service attribute or value already exists"
			);
		case SystemCode::DS_BUSY:
			RETURN_STATIC_STRING(
					"The directory service is busy"
			);
		case SystemCode::DS_UNAVAILABLE:
			RETURN_STATIC_STRING(
					"The directory service is unavailable"
			);
		case SystemCode::DS_NO_RIDS_ALLOCATED:
			RETURN_STATIC_STRING(
					"The directory service was unable to allocate a relative identifier"
			);
		case SystemCode::DS_NO_MORE_RIDS:
			RETURN_STATIC_STRING(
					"The directory service has exhausted the pool of relative identifiers"
			);
		case SystemCode::DS_INCORRECT_ROLE_OWNER:
			RETURN_STATIC_STRING(
					"The requested operation could not be performed because the directory service"
					" is not the master for that type of operation"
			);
		case SystemCode::DS_RIDMGR_INIT_ERROR:
			RETURN_STATIC_STRING(
					"The directory service was unable to initialize the subsystem that allocates"
					" relative identifiers"
			);
		case SystemCode::DS_OBJ_CLASS_VIOLATION:
			RETURN_STATIC_STRING(
					"The requested operation did not satisfy one or more constraints associated"
					" with the class of the object"
			);
		case SystemCode::DS_CANT_ON_NON_LEAF:
			RETURN_STATIC_STRING(
					"The directory service can perform the requested operation only on a leaf"
					" object"
			);
		case SystemCode::DS_CANT_ON_RDN:
			RETURN_STATIC_STRING(
					"The directory service cannot perform the requested operation on the RDN"
					" attribute of an object"
			);
		case SystemCode::DS_CANT_MOD_OBJ_CLASS:
			RETURN_STATIC_STRING(
					"The directory service detected an attempt to modify the object class of an"
					" object"
			);
		case SystemCode::DS_CROSS_DOM_MOVE_ERROR:
			RETURN_STATIC_STRING(
					"The requested cross-domain move operation could not be performed"
			);
		case SystemCode::DS_GC_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"Unable to contact the global catalog server"
			);
		case SystemCode::SHARED_POLICY:
			RETURN_STATIC_STRING(
					"The policy object is shared and can only be modified at the root"
			);
		case SystemCode::POLICY_OBJECT_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The policy object does not exist"
			);
		case SystemCode::POLICY_ONLY_IN_DS:
			RETURN_STATIC_STRING(
					"The requested policy information is only in the directory service"
			);
		case SystemCode::PROMOTION_ACTIVE:
			RETURN_STATIC_STRING(
					"A domain controller promotion is currently active"
			);
		case SystemCode::NO_PROMOTION_ACTIVE:
			RETURN_STATIC_STRING(
					"A domain controller promotion is not currently active"
			);
		case SystemCode::DS_OPERATIONS_ERROR:
			RETURN_STATIC_STRING(
					"An operations error occurred"
			);
		case SystemCode::DS_PROTOCOL_ERROR:
			RETURN_STATIC_STRING(
					"A protocol error occurred"
			);
		case SystemCode::DS_TIMELIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The time limit for this request was exceeded"
			);
		case SystemCode::DS_SIZELIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The size limit for this request was exceeded"
			);
		case SystemCode::DS_ADMIN_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The administrative limit for this request was exceeded"
			);
		case SystemCode::DS_COMPARE_FALSE:
			RETURN_STATIC_STRING(
					"The compare response was false"
			);
		case SystemCode::DS_COMPARE_TRUE:
			RETURN_STATIC_STRING(
					"The compare response was true"
			);
		case SystemCode::DS_AUTH_METHOD_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The requested authentication method is not supported by the server"
			);
		case SystemCode::DS_STRONG_AUTH_REQUIRED:
			RETURN_STATIC_STRING(
					"A more secure authentication method is required for this server"
			);
		case SystemCode::DS_INAPPROPRIATE_AUTH:
			RETURN_STATIC_STRING(
					"Inappropriate authentication"
			);
		case SystemCode::DS_AUTH_UNKNOWN:
			RETURN_STATIC_STRING(
					"The authentication mechanism is unknown"
			);
		case SystemCode::DS_REFERRAL:
			RETURN_STATIC_STRING(
					"A referral was returned from the server"
			);
		case SystemCode::DS_UNAVAILABLE_CRIT_EXTENSION:
			RETURN_STATIC_STRING(
					"The server does not support the requested critical extension"
			);
		case SystemCode::DS_CONFIDENTIALITY_REQUIRED:
			RETURN_STATIC_STRING(
					"This request requires a secure connection"
			);
		case SystemCode::DS_INAPPROPRIATE_MATCHING:
			RETURN_STATIC_STRING(
					"Inappropriate matching"
			);
		case SystemCode::DS_CONSTRAINT_VIOLATION:
			RETURN_STATIC_STRING(
					"A constraint violation occurred"
			);
		case SystemCode::DS_NO_SUCH_OBJECT:
			RETURN_STATIC_STRING(
					"There is no such object on the server"
			);
		case SystemCode::DS_ALIAS_PROBLEM:
			RETURN_STATIC_STRING(
					"There is an alias problem"
			);
		case SystemCode::DS_INVALID_DN_SYNTAX:
			RETURN_STATIC_STRING(
					"An invalid dn syntax has been specified"
			);
		case SystemCode::DS_IS_LEAF:
			RETURN_STATIC_STRING(
					"The object is a leaf object"
			);
		case SystemCode::DS_ALIAS_DEREF_PROBLEM:
			RETURN_STATIC_STRING(
					"There is an alias dereferencing problem"
			);
		case SystemCode::DS_UNWILLING_TO_PERFORM:
			RETURN_STATIC_STRING(
					"The server is unwilling to process the request"
			);
		case SystemCode::DS_LOOP_DETECT:
			RETURN_STATIC_STRING(
					"A loop has been detected"
			);
		case SystemCode::DS_NAMING_VIOLATION:
			RETURN_STATIC_STRING(
					"There is a naming violation"
			);
		case SystemCode::DS_OBJECT_RESULTS_TOO_LARGE:
			RETURN_STATIC_STRING(
					"The result set is too large"
			);
		case SystemCode::DS_AFFECTS_MULTIPLE_DSAS:
			RETURN_STATIC_STRING(
					"The operation affects multiple DSAs"
			);
		case SystemCode::DS_SERVER_DOWN:
			RETURN_STATIC_STRING(
					"The server is not operational"
			);
		case SystemCode::DS_LOCAL_ERROR:
			RETURN_STATIC_STRING(
					"A local error has occurred"
			);
		case SystemCode::DS_ENCODING_ERROR:
			RETURN_STATIC_STRING(
					"An encoding error has occurred"
			);
		case SystemCode::DS_DECODING_ERROR:
			RETURN_STATIC_STRING(
					"A decoding error has occurred"
			);
		case SystemCode::DS_FILTER_UNKNOWN:
			RETURN_STATIC_STRING(
					"The search filter cannot be recognized"
			);
		case SystemCode::DS_PARAM_ERROR:
			RETURN_STATIC_STRING(
					"One or more parameters are illegal"
			);
		case SystemCode::DS_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The specified method is not supported"
			);
		case SystemCode::DS_NO_RESULTS_RETURNED:
			RETURN_STATIC_STRING(
					"No results were returned"
			);
		case SystemCode::DS_CONTROL_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified control is not supported by the server"
			);
		case SystemCode::DS_CLIENT_LOOP:
			RETURN_STATIC_STRING(
					"A referral loop was detected by the client"
			);
		case SystemCode::DS_REFERRAL_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The preset referral limit was exceeded"
			);
		case SystemCode::DS_SORT_CONTROL_MISSING:
			RETURN_STATIC_STRING(
					"The search requires a SORT control"
			);
		case SystemCode::DS_OFFSET_RANGE_ERROR:
			RETURN_STATIC_STRING(
					"The search results exceed the offset range specified"
			);
		case SystemCode::DS_RIDMGR_DISABLED:
			RETURN_STATIC_STRING(
					"The directory service detected the subsystem that allocates relative"
					" identifiers is disabled. This can occur as a protective mechanism when the"
					" system determines a significant portion of relative identifiers (RIDs) have"
					" been exhausted. Please see https://go.microsoft.com/fwlink/p/?linkid=228610"
					" for recommended diagnostic steps and the procedure to re-enable account"
					" creation"
			);
		case SystemCode::DS_ROOT_MUST_BE_NC:
			RETURN_STATIC_STRING(
					"The root object must be the head of a naming context. The root object cannot"
					" have an instantiated parent"
			);
		case SystemCode::DS_ADD_REPLICA_INHIBITED:
			RETURN_STATIC_STRING(
					"The add replica operation cannot be performed. The naming context must be"
					" writeable in order to create the replica"
			);
		case SystemCode::DS_ATT_NOT_DEF_IN_SCHEMA:
			RETURN_STATIC_STRING(
					"A reference to an attribute that is not defined in the schema occurred"
			);
		case SystemCode::DS_MAX_OBJ_SIZE_EXCEEDED:
			RETURN_STATIC_STRING(
					"The maximum size of an object has been exceeded"
			);
		case SystemCode::DS_OBJ_STRING_NAME_EXISTS:
			RETURN_STATIC_STRING(
					"An attempt was made to add an object to the directory with a name that is"
					" already in use"
			);
		case SystemCode::DS_NO_RDN_DEFINED_IN_SCHEMA:
			RETURN_STATIC_STRING(
					"An attempt was made to add an object of a class that does not have an RDN"
					" defined in the schema"
			);
		case SystemCode::DS_RDN_DOESNT_MATCH_SCHEMA:
			RETURN_STATIC_STRING(
					"An attempt was made to add an object using an RDN that is not the RDN defined"
					" in the schema"
			);
		case SystemCode::DS_NO_REQUESTED_ATTS_FOUND:
			RETURN_STATIC_STRING(
					"None of the requested attributes were found on the objects"
			);
		case SystemCode::DS_USER_BUFFER_TO_SMALL:
			RETURN_STATIC_STRING(
					"The user buffer is too small"
			);
		case SystemCode::DS_ATT_IS_NOT_ON_OBJ:
			RETURN_STATIC_STRING(
					"The attribute specified in the operation is not present on the object"
			);
		case SystemCode::DS_ILLEGAL_MOD_OPERATION:
			RETURN_STATIC_STRING(
					"Illegal modify operation. Some aspect of the modification is not permitted"
			);
		case SystemCode::DS_OBJ_TOO_LARGE:
			RETURN_STATIC_STRING(
					"The specified object is too large"
			);
		case SystemCode::DS_BAD_INSTANCE_TYPE:
			RETURN_STATIC_STRING(
					"The specified instance type is not valid"
			);
		case SystemCode::DS_MASTERDSA_REQUIRED:
			RETURN_STATIC_STRING(
					"The operation must be performed at a master DSA"
			);
		case SystemCode::DS_OBJECT_CLASS_REQUIRED:
			RETURN_STATIC_STRING(
					"The object class attribute must be specified"
			);
		case SystemCode::DS_MISSING_REQUIRED_ATT:
			RETURN_STATIC_STRING(
					"A required attribute is missing"
			);
		case SystemCode::DS_ATT_NOT_DEF_FOR_CLASS:
			RETURN_STATIC_STRING(
					"An attempt was made to modify an object to include an attribute that is not"
					" legal for its class"
			);
		case SystemCode::DS_ATT_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified attribute is already present on the object"
			);
		case SystemCode::DS_CANT_ADD_ATT_VALUES:
			RETURN_STATIC_STRING(
					"The specified attribute is not present, or has no values"
			);
		case SystemCode::DS_SINGLE_VALUE_CONSTRAINT:
			RETURN_STATIC_STRING(
					"Multiple values were specified for an attribute that can have only one value"
			);
		case SystemCode::DS_RANGE_CONSTRAINT:
			RETURN_STATIC_STRING(
					"A value for the attribute was not in the acceptable range of values"
			);
		case SystemCode::DS_ATT_VAL_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The specified value already exists"
			);
		case SystemCode::DS_CANT_REM_MISSING_ATT:
			RETURN_STATIC_STRING(
					"The attribute cannot be removed because it is not present on the object"
			);
		case SystemCode::DS_CANT_REM_MISSING_ATT_VAL:
			RETURN_STATIC_STRING(
					"The attribute value cannot be removed because it is not present on the object"
			);
		case SystemCode::DS_ROOT_CANT_BE_SUBREF:
			RETURN_STATIC_STRING(
					"The specified root object cannot be a subref"
			);
		case SystemCode::DS_NO_CHAINING:
			RETURN_STATIC_STRING(
					"Chaining is not permitted"
			);
		case SystemCode::DS_NO_CHAINED_EVAL:
			RETURN_STATIC_STRING(
					"Chained evaluation is not permitted"
			);
		case SystemCode::DS_NO_PARENT_OBJECT:
			RETURN_STATIC_STRING(
					"The operation could not be performed because the object's parent is either"
					" uninstantiated or deleted"
			);
		case SystemCode::DS_PARENT_IS_AN_ALIAS:
			RETURN_STATIC_STRING(
					"Having a parent that is an alias is not permitted. Aliases are leaf objects"
			);
		case SystemCode::DS_CANT_MIX_MASTER_AND_REPS:
			RETURN_STATIC_STRING(
					"The object and parent must be of the same type, either both masters or both"
					" replicas"
			);
		case SystemCode::DS_CHILDREN_EXIST:
			RETURN_STATIC_STRING(
					"The operation cannot be performed because child objects exist. This operation"
					" can only be performed on a leaf object"
			);
		case SystemCode::DS_OBJ_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Directory object not found"
			);
		case SystemCode::DS_ALIASED_OBJ_MISSING:
			RETURN_STATIC_STRING(
					"The aliased object is missing"
			);
		case SystemCode::DS_BAD_NAME_SYNTAX:
			RETURN_STATIC_STRING(
					"The object name has bad syntax"
			);
		case SystemCode::DS_ALIAS_POINTS_TO_ALIAS:
			RETURN_STATIC_STRING(
					"It is not permitted for an alias to refer to another alias"
			);
		case SystemCode::DS_CANT_DEREF_ALIAS:
			RETURN_STATIC_STRING(
					"The alias cannot be dereferenced"
			);
		case SystemCode::DS_OUT_OF_SCOPE:
			RETURN_STATIC_STRING(
					"The operation is out of scope"
			);
		case SystemCode::DS_OBJECT_BEING_REMOVED:
			RETURN_STATIC_STRING(
					"The operation cannot continue because the object is in the process of being"
					" removed"
			);
		case SystemCode::DS_CANT_DELETE_DSA_OBJ:
			RETURN_STATIC_STRING(
					"The DSA object cannot be deleted"
			);
		case SystemCode::DS_GENERIC_ERROR:
			RETURN_STATIC_STRING(
					"A directory service error has occurred"
			);
		case SystemCode::DS_DSA_MUST_BE_INT_MASTER:
			RETURN_STATIC_STRING(
					"The operation can only be performed on an internal master DSA object"
			);
		case SystemCode::DS_CLASS_NOT_DSA:
			RETURN_STATIC_STRING(
					"The object must be of class DSA"
			);
		case SystemCode::DS_INSUFF_ACCESS_RIGHTS:
			RETURN_STATIC_STRING(
					"Insufficient access rights to perform the operation"
			);
		case SystemCode::DS_ILLEGAL_SUPERIOR:
			RETURN_STATIC_STRING(
					"The object cannot be added because the parent is not on the list of possible"
					" superiors"
			);
		case SystemCode::DS_ATTRIBUTE_OWNED_BY_SAM:
			RETURN_STATIC_STRING(
					"Access to the attribute is not permitted because the attribute is owned by the"
					" Security Accounts Manager (SAM)"
			);
		case SystemCode::DS_NAME_TOO_MANY_PARTS:
			RETURN_STATIC_STRING(
					"The name has too many parts"
			);
		case SystemCode::DS_NAME_TOO_LONG:
			RETURN_STATIC_STRING(
					"The name is too long"
			);
		case SystemCode::DS_NAME_VALUE_TOO_LONG:
			RETURN_STATIC_STRING(
					"The name value is too long"
			);
		case SystemCode::DS_NAME_UNPARSEABLE:
			RETURN_STATIC_STRING(
					"The directory service encountered an error parsing a name"
			);
		case SystemCode::DS_NAME_TYPE_UNKNOWN:
			RETURN_STATIC_STRING(
					"The directory service cannot get the attribute type for a name"
			);
		case SystemCode::DS_NOT_AN_OBJECT:
			RETURN_STATIC_STRING(
					"The name does not identify an object; the name identifies a phantom"
			);
		case SystemCode::DS_SEC_DESC_TOO_SHORT:
			RETURN_STATIC_STRING(
					"The security descriptor is too short"
			);
		case SystemCode::DS_SEC_DESC_INVALID:
			RETURN_STATIC_STRING(
					"The security descriptor is invalid"
			);
		case SystemCode::DS_NO_DELETED_NAME:
			RETURN_STATIC_STRING(
					"Failed to create name for deleted object"
			);
		case SystemCode::DS_SUBREF_MUST_HAVE_PARENT:
			RETURN_STATIC_STRING(
					"The parent of a new subref must exist"
			);
		case SystemCode::DS_NCNAME_MUST_BE_NC:
			RETURN_STATIC_STRING(
					"The object must be a naming context"
			);
		case SystemCode::DS_CANT_ADD_SYSTEM_ONLY:
			RETURN_STATIC_STRING(
					"It is not permitted to add an attribute which is owned by the system"
			);
		case SystemCode::DS_CLASS_MUST_BE_CONCRETE:
			RETURN_STATIC_STRING(
					"The class of the object must be structural; you cannot instantiate an abstract"
					" class"
			);
		case SystemCode::DS_INVALID_DMD:
			RETURN_STATIC_STRING(
					"The schema object could not be found"
			);
		case SystemCode::DS_OBJ_GUID_EXISTS:
			RETURN_STATIC_STRING(
					"A local object with this GUID (dead or alive) already exists"
			);
		case SystemCode::DS_NOT_ON_BACKLINK:
			RETURN_STATIC_STRING(
					"The operation cannot be performed on a back link"
			);
		case SystemCode::DS_NO_CROSSREF_FOR_NC:
			RETURN_STATIC_STRING(
					"The cross reference for the specified naming context could not be found"
			);
		case SystemCode::DS_SHUTTING_DOWN:
			RETURN_STATIC_STRING(
					"The operation could not be performed because the directory service is shutting"
					" down"
			);
		case SystemCode::DS_UNKNOWN_OPERATION:
			RETURN_STATIC_STRING(
					"The directory service request is invalid"
			);
		case SystemCode::DS_INVALID_ROLE_OWNER:
			RETURN_STATIC_STRING(
					"The role owner attribute could not be read"
			);
		case SystemCode::DS_COULDNT_CONTACT_FSMO:
			RETURN_STATIC_STRING(
					"The requested FSMO operation failed. The current FSMO holder could not be"
					" contacted"
			);
		case SystemCode::DS_CROSS_NC_DN_RENAME:
			RETURN_STATIC_STRING(
					"Modification of a DN across a naming context is not permitted"
			);
		case SystemCode::DS_CANT_MOD_SYSTEM_ONLY:
			RETURN_STATIC_STRING(
					"The attribute cannot be modified because it is owned by the system"
			);
		case SystemCode::DS_REPLICATOR_ONLY:
			RETURN_STATIC_STRING(
					"Only the replicator can perform this function"
			);
		case SystemCode::DS_OBJ_CLASS_NOT_DEFINED:
			RETURN_STATIC_STRING(
					"The specified class is not defined"
			);
		case SystemCode::DS_OBJ_CLASS_NOT_SUBCLASS:
			RETURN_STATIC_STRING(
					"The specified class is not a subclass"
			);
		case SystemCode::DS_NAME_REFERENCE_INVALID:
			RETURN_STATIC_STRING(
					"The name reference is invalid"
			);
		case SystemCode::DS_CROSS_REF_EXISTS:
			RETURN_STATIC_STRING(
					"A cross reference already exists"
			);
		case SystemCode::DS_CANT_DEL_MASTER_CROSSREF:
			RETURN_STATIC_STRING(
					"It is not permitted to delete a master cross reference"
			);
		case SystemCode::DS_SUBTREE_NOTIFY_NOT_NC_HEAD:
			RETURN_STATIC_STRING(
					"Subtree notifications are only supported on NC heads"
			);
		case SystemCode::DS_NOTIFY_FILTER_TOO_COMPLEX:
			RETURN_STATIC_STRING(
					"Notification filter is too complex"
			);
		case SystemCode::DS_DUP_RDN:
			RETURN_STATIC_STRING(
					"Schema update failed: duplicate RDN"
			);
		case SystemCode::DS_DUP_OID:
			RETURN_STATIC_STRING(
					"Schema update failed: duplicate OID"
			);
		case SystemCode::DS_DUP_MAPI_ID:
			RETURN_STATIC_STRING(
					"Schema update failed: duplicate MAPI identifier"
			);
		case SystemCode::DS_DUP_SCHEMA_ID_GUID:
			RETURN_STATIC_STRING(
					"Schema update failed: duplicate schema-id GUID"
			);
		case SystemCode::DS_DUP_LDAP_DISPLAY_NAME:
			RETURN_STATIC_STRING(
					"Schema update failed: duplicate LDAP display name"
			);
		case SystemCode::DS_SEMANTIC_ATT_TEST:
			RETURN_STATIC_STRING(
					"Schema update failed: range-lower less than range upper"
			);
		case SystemCode::DS_SYNTAX_MISMATCH:
			RETURN_STATIC_STRING(
					"Schema update failed: syntax mismatch"
			);
		case SystemCode::DS_EXISTS_IN_MUST_HAVE:
			RETURN_STATIC_STRING(
					"Schema deletion failed: attribute is used in must-contain"
			);
		case SystemCode::DS_EXISTS_IN_MAY_HAVE:
			RETURN_STATIC_STRING(
					"Schema deletion failed: attribute is used in may-contain"
			);
		case SystemCode::DS_NONEXISTENT_MAY_HAVE:
			RETURN_STATIC_STRING(
					"Schema update failed: attribute in may-contain does not exist"
			);
		case SystemCode::DS_NONEXISTENT_MUST_HAVE:
			RETURN_STATIC_STRING(
					"Schema update failed: attribute in must-contain does not exist"
			);
		case SystemCode::DS_AUX_CLS_TEST_FAIL:
			RETURN_STATIC_STRING(
					"Schema update failed: class in aux-class list does not exist or is not an"
					" auxiliary class"
			);
		case SystemCode::DS_NONEXISTENT_POSS_SUP:
			RETURN_STATIC_STRING(
					"Schema update failed: class in poss-superiors does not exist"
			);
		case SystemCode::DS_SUB_CLS_TEST_FAIL:
			RETURN_STATIC_STRING(
					"Schema update failed: class in subclassof list does not exist or does not"
					" satisfy hierarchy rules"
			);
		case SystemCode::DS_BAD_RDN_ATT_ID_SYNTAX:
			RETURN_STATIC_STRING(
					"Schema update failed: Rdn-Att-Id has wrong syntax"
			);
		case SystemCode::DS_EXISTS_IN_AUX_CLS:
			RETURN_STATIC_STRING(
					"Schema deletion failed: class is used as auxiliary class"
			);
		case SystemCode::DS_EXISTS_IN_SUB_CLS:
			RETURN_STATIC_STRING(
					"Schema deletion failed: class is used as sub class"
			);
		case SystemCode::DS_EXISTS_IN_POSS_SUP:
			RETURN_STATIC_STRING(
					"Schema deletion failed: class is used as poss superior"
			);
		case SystemCode::DS_RECALCSCHEMA_FAILED:
			RETURN_STATIC_STRING(
					"Schema update failed in recalculating validation cache"
			);
		case SystemCode::DS_TREE_DELETE_NOT_FINISHED:
			RETURN_STATIC_STRING(
					"The tree deletion is not finished. The request must be made again to continue"
					" deleting the tree"
			);
		case SystemCode::DS_CANT_DELETE:
			RETURN_STATIC_STRING(
					"The requested delete operation could not be performed"
			);
		case SystemCode::DS_ATT_SCHEMA_REQ_ID:
			RETURN_STATIC_STRING(
					"Cannot read the governs class identifier for the schema record"
			);
		case SystemCode::DS_BAD_ATT_SCHEMA_SYNTAX:
			RETURN_STATIC_STRING(
					"The attribute schema has bad syntax"
			);
		case SystemCode::DS_CANT_CACHE_ATT:
			RETURN_STATIC_STRING(
					"The attribute could not be cached"
			);
		case SystemCode::DS_CANT_CACHE_CLASS:
			RETURN_STATIC_STRING(
					"The class could not be cached"
			);
		case SystemCode::DS_CANT_REMOVE_ATT_CACHE:
			RETURN_STATIC_STRING(
					"The attribute could not be removed from the cache"
			);
		case SystemCode::DS_CANT_REMOVE_CLASS_CACHE:
			RETURN_STATIC_STRING(
					"The class could not be removed from the cache"
			);
		case SystemCode::DS_CANT_RETRIEVE_DN:
			RETURN_STATIC_STRING(
					"The distinguished name attribute could not be read"
			);
		case SystemCode::DS_MISSING_SUPREF:
			RETURN_STATIC_STRING(
					"No superior reference has been configured for the directory service. The"
					" directory service is therefore unable to issue referrals to objects outside"
					" this forest"
			);
		case SystemCode::DS_CANT_RETRIEVE_INSTANCE:
			RETURN_STATIC_STRING(
					"The instance type attribute could not be retrieved"
			);
		case SystemCode::DS_CODE_INCONSISTENCY:
			RETURN_STATIC_STRING(
					"An internal error has occurred"
			);
		case SystemCode::DS_DATABASE_ERROR:
			RETURN_STATIC_STRING(
					"A database error has occurred"
			);
		case SystemCode::DS_GOVERNSID_MISSING:
			RETURN_STATIC_STRING(
					"The attribute GOVERNSID is missing"
			);
		case SystemCode::DS_MISSING_EXPECTED_ATT:
			RETURN_STATIC_STRING(
					"An expected attribute is missing"
			);
		case SystemCode::DS_NCNAME_MISSING_CR_REF:
			RETURN_STATIC_STRING(
					"The specified naming context is missing a cross reference"
			);
		case SystemCode::DS_SECURITY_CHECKING_ERROR:
			RETURN_STATIC_STRING(
					"A security checking error has occurred"
			);
		case SystemCode::DS_SCHEMA_NOT_LOADED:
			RETURN_STATIC_STRING(
					"The schema is not loaded"
			);
		case SystemCode::DS_SCHEMA_ALLOC_FAILED:
			RETURN_STATIC_STRING(
					"Schema allocation failed. Please check if the machine is running low on memory"
			);
		case SystemCode::DS_ATT_SCHEMA_REQ_SYNTAX:
			RETURN_STATIC_STRING(
					"Failed to obtain the required syntax for the attribute schema"
			);
		case SystemCode::DS_GCVERIFY_ERROR:
			RETURN_STATIC_STRING(
					"The global catalog verification failed. The global catalog is not available or"
					" does not support the operation. Some part of the directory is currently not"
					" available"
			);
		case SystemCode::DS_DRA_SCHEMA_MISMATCH:
			RETURN_STATIC_STRING(
					"The replication operation failed because of a schema mismatch between the"
					" servers involved"
			);
		case SystemCode::DS_CANT_FIND_DSA_OBJ:
			RETURN_STATIC_STRING(
					"The DSA object could not be found"
			);
		case SystemCode::DS_CANT_FIND_EXPECTED_NC:
			RETURN_STATIC_STRING(
					"The naming context could not be found"
			);
		case SystemCode::DS_CANT_FIND_NC_IN_CACHE:
			RETURN_STATIC_STRING(
					"The naming context could not be found in the cache"
			);
		case SystemCode::DS_CANT_RETRIEVE_CHILD:
			RETURN_STATIC_STRING(
					"The child object could not be retrieved"
			);
		case SystemCode::DS_SECURITY_ILLEGAL_MODIFY:
			RETURN_STATIC_STRING(
					"The modification was not permitted for security reasons"
			);
		case SystemCode::DS_CANT_REPLACE_HIDDEN_REC:
			RETURN_STATIC_STRING(
					"The operation cannot replace the hidden record"
			);
		case SystemCode::DS_BAD_HIERARCHY_FILE:
			RETURN_STATIC_STRING(
					"The hierarchy file is invalid"
			);
		case SystemCode::DS_BUILD_HIERARCHY_TABLE_FAILED:
			RETURN_STATIC_STRING(
					"The attempt to build the hierarchy table failed"
			);
		case SystemCode::DS_CONFIG_PARAM_MISSING:
			RETURN_STATIC_STRING(
					"The directory configuration parameter is missing from the registry"
			);
		case SystemCode::DS_COUNTING_AB_INDICES_FAILED:
			RETURN_STATIC_STRING(
					"The attempt to count the address book indices failed"
			);
		case SystemCode::DS_HIERARCHY_TABLE_MALLOC_FAILED:
			RETURN_STATIC_STRING(
					"The allocation of the hierarchy table failed"
			);
		case SystemCode::DS_INTERNAL_FAILURE:
			RETURN_STATIC_STRING(
					"The directory service encountered an internal failure"
			);
		case SystemCode::DS_UNKNOWN_ERROR:
			RETURN_STATIC_STRING(
					"The directory service encountered an unknown failure"
			);
		case SystemCode::DS_ROOT_REQUIRES_CLASS_TOP:
			RETURN_STATIC_STRING(
					"A root object requires a class of 'top'"
			);
		case SystemCode::DS_REFUSING_FSMO_ROLES:
			RETURN_STATIC_STRING(
					"This directory server is shutting down, and cannot take ownership of new"
					" floating single-master operation roles"
			);
		case SystemCode::DS_MISSING_FSMO_SETTINGS:
			RETURN_STATIC_STRING(
					"The directory service is missing mandatory configuration information, and is"
					" unable to determine the ownership of floating single-master operation roles"
			);
		case SystemCode::DS_UNABLE_TO_SURRENDER_ROLES:
			RETURN_STATIC_STRING(
					"The directory service was unable to transfer ownership of one or more floating"
					" single-master operation roles to other servers"
			);
		case SystemCode::DS_DRA_GENERIC:
			RETURN_STATIC_STRING(
					"The replication operation failed"
			);
		case SystemCode::DS_DRA_INVALID_PARAMETER:
			RETURN_STATIC_STRING(
					"An invalid parameter was specified for this replication operation"
			);
		case SystemCode::DS_DRA_BUSY:
			RETURN_STATIC_STRING(
					"The directory service is too busy to complete the replication operation at"
					" this time"
			);
		case SystemCode::DS_DRA_BAD_DN:
			RETURN_STATIC_STRING(
					"The distinguished name specified for this replication operation is invalid"
			);
		case SystemCode::DS_DRA_BAD_NC:
			RETURN_STATIC_STRING(
					"The naming context specified for this replication operation is invalid"
			);
		case SystemCode::DS_DRA_DN_EXISTS:
			RETURN_STATIC_STRING(
					"The distinguished name specified for this replication operation already exists"
			);
		case SystemCode::DS_DRA_INTERNAL_ERROR:
			RETURN_STATIC_STRING(
					"The replication system encountered an internal error"
			);
		case SystemCode::DS_DRA_INCONSISTENT_DIT:
			RETURN_STATIC_STRING(
					"The replication operation encountered a database inconsistency"
			);
		case SystemCode::DS_DRA_CONNECTION_FAILED:
			RETURN_STATIC_STRING(
					"The server specified for this replication operation could not be contacted"
			);
		case SystemCode::DS_DRA_BAD_INSTANCE_TYPE:
			RETURN_STATIC_STRING(
					"The replication operation encountered an object with an invalid instance type"
			);
		case SystemCode::DS_DRA_OUT_OF_MEM:
			RETURN_STATIC_STRING(
					"The replication operation failed to allocate memory"
			);
		case SystemCode::DS_DRA_MAIL_PROBLEM:
			RETURN_STATIC_STRING(
					"The replication operation encountered an error with the mail system"
			);
		case SystemCode::DS_DRA_REF_ALREADY_EXISTS:
			RETURN_STATIC_STRING(
					"The replication reference information for the target server already exists"
			);
		case SystemCode::DS_DRA_REF_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The replication reference information for the target server does not exist"
			);
		case SystemCode::DS_DRA_OBJ_IS_REP_SOURCE:
			RETURN_STATIC_STRING(
					"The naming context cannot be removed because it is replicated to another"
					" server"
			);
		case SystemCode::DS_DRA_DB_ERROR:
			RETURN_STATIC_STRING(
					"The replication operation encountered a database error"
			);
		case SystemCode::DS_DRA_NO_REPLICA:
			RETURN_STATIC_STRING(
					"The naming context is in the process of being removed or is not replicated"
					" from the specified server"
			);
		case SystemCode::DS_DRA_ACCESS_DENIED:
			RETURN_STATIC_STRING(
					"Replication access was denied"
			);
		case SystemCode::DS_DRA_NOT_SUPPORTED:
			RETURN_STATIC_STRING(
					"The requested operation is not supported by this version of the directory"
					" service"
			);
		case SystemCode::DS_DRA_RPC_CANCELLED:
			RETURN_STATIC_STRING(
					"The replication remote procedure call was cancelled"
			);
		case SystemCode::DS_DRA_SOURCE_DISABLED:
			RETURN_STATIC_STRING(
					"The source server is currently rejecting replication requests"
			);
		case SystemCode::DS_DRA_SINK_DISABLED:
			RETURN_STATIC_STRING(
					"The destination server is currently rejecting replication requests"
			);
		case SystemCode::DS_DRA_NAME_COLLISION:
			RETURN_STATIC_STRING(
					"The replication operation failed due to a collision of object names"
			);
		case SystemCode::DS_DRA_SOURCE_REINSTALLED:
			RETURN_STATIC_STRING(
					"The replication source has been reinstalled"
			);
		case SystemCode::DS_DRA_MISSING_PARENT:
			RETURN_STATIC_STRING(
					"The replication operation failed because a required parent object is missing"
			);
		case SystemCode::DS_DRA_PREEMPTED:
			RETURN_STATIC_STRING(
					"The replication operation was preempted"
			);
		case SystemCode::DS_DRA_ABANDON_SYNC:
			RETURN_STATIC_STRING(
					"The replication synchronization attempt was abandoned because of a lack of"
					" updates"
			);
		case SystemCode::DS_DRA_SHUTDOWN:
			RETURN_STATIC_STRING(
					"The replication operation was terminated because the system is shutting down"
			);
		case SystemCode::DS_DRA_INCOMPATIBLE_PARTIAL_SET:
			RETURN_STATIC_STRING(
					"Synchronization attempt failed because the destination DC is currently"
					" waiting to synchronize new partial attributes from source. This condition is"
					" normal if a recent schema change modified the partial attribute set. The"
					" destination partial attribute set is not a subset of source partial attribute"
					" set"
			);
		case SystemCode::DS_DRA_SOURCE_IS_PARTIAL_REPLICA:
			RETURN_STATIC_STRING(
					"The replication synchronization attempt failed because a master replica"
					" attempted to sync from a partial replica"
			);
		case SystemCode::DS_DRA_EXTN_CONNECTION_FAILED:
			RETURN_STATIC_STRING(
					"The server specified for this replication operation was contacted, but that"
					" server was unable to contact an additional server needed to complete the"
					" operation"
			);
		case SystemCode::DS_INSTALL_SCHEMA_MISMATCH:
			RETURN_STATIC_STRING(
					"The version of the directory service schema of the source forest is not"
					" compatible with the version of directory service on this computer"
			);
		case SystemCode::DS_DUP_LINK_ID:
			RETURN_STATIC_STRING(
					"Schema update failed: An attribute with the same link identifier already"
					" exists"
			);
		case SystemCode::DS_NAME_ERROR_RESOLVING:
			RETURN_STATIC_STRING(
					"Name translation: Generic processing error"
			);
		case SystemCode::DS_NAME_ERROR_NOT_FOUND:
			RETURN_STATIC_STRING(
					"Name translation: Could not find the name or insufficient right to see name"
			);
		case SystemCode::DS_NAME_ERROR_NOT_UNIQUE:
			RETURN_STATIC_STRING(
					"Name translation: Input name mapped to more than one output name"
			);
		case SystemCode::DS_NAME_ERROR_NO_MAPPING:
			RETURN_STATIC_STRING(
					"Name translation: Input name found, but not the associated output format"
			);
		case SystemCode::DS_NAME_ERROR_DOMAIN_ONLY:
			RETURN_STATIC_STRING(
					"Name translation: Unable to resolve completely, only the domain was found"
			);
		case SystemCode::DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING:
			RETURN_STATIC_STRING(
					"Name translation: Unable to perform purely syntactical mapping at the client"
					" without going out to the wire"
			);
		case SystemCode::DS_CONSTRUCTED_ATT_MOD:
			RETURN_STATIC_STRING(
					"Modification of a constructed attribute is not allowed"
			);
		case SystemCode::DS_WRONG_OM_OBJ_CLASS:
			RETURN_STATIC_STRING(
					"The OM-Object-Class specified is incorrect for an attribute with the"
					" specified syntax"
			);
		case SystemCode::DS_DRA_REPL_PENDING:
			RETURN_STATIC_STRING(
					"The replication request has been posted; waiting for reply"
			);
		case SystemCode::DS_DS_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation requires a directory service, and none was available"
			);
		case SystemCode::DS_INVALID_LDAP_DISPLAY_NAME:
			RETURN_STATIC_STRING(
					"The LDAP display name of the class or attribute contains non-ASCII characters"
			);
		case SystemCode::DS_NON_BASE_SEARCH:
			RETURN_STATIC_STRING(
					"The requested search operation is only supported for base searches"
			);
		case SystemCode::DS_CANT_RETRIEVE_ATTS:
			RETURN_STATIC_STRING(
					"The search failed to retrieve attributes from the database"
			);
		case SystemCode::DS_BACKLINK_WITHOUT_LINK:
			RETURN_STATIC_STRING(
					"The schema update operation tried to add a backward link attribute that has no"
					" corresponding forward link"
			);
		case SystemCode::DS_EPOCH_MISMATCH:
			RETURN_STATIC_STRING(
					"Source and destination of a cross-domain move do not agree on the object's"
					" epoch number. Either source or destination does not have the latest version"
					" of the object"
			);
		case SystemCode::DS_SRC_NAME_MISMATCH:
			RETURN_STATIC_STRING(
					"Source and destination of a cross-domain move do not agree on the object's"
					" current name. Either source or destination does not have the latest version"
					" of the object"
			);
		case SystemCode::DS_SRC_AND_DST_NC_IDENTICAL:
			RETURN_STATIC_STRING(
					"Source and destination for the cross-domain move operation are identical."
					" Caller should use local move operation instead of cross-domain move operation"
			);
		case SystemCode::DS_DST_NC_MISMATCH:
			RETURN_STATIC_STRING(
					"Source and destination for a cross-domain move are not in agreement on the"
					" naming contexts in the forest. Either source or destination does not have the"
					" latest version of the Partitions container"
			);
		case SystemCode::DS_NOT_AUTHORITIVE_FOR_DST_NC:
			RETURN_STATIC_STRING(
					"Destination of a cross-domain move is not authoritative for the destination"
					" naming context"
			);
		case SystemCode::DS_SRC_GUID_MISMATCH:
			RETURN_STATIC_STRING(
					"Source and destination of a cross-domain move do not agree on the identity of"
					" the source object. Either source or destination does not have the latest"
					" version of the source object"
			);
		case SystemCode::DS_CANT_MOVE_DELETED_OBJECT:
			RETURN_STATIC_STRING(
					"Object being moved across-domains is already known to be deleted by the"
					" destination server. The source server does not have the latest version of the"
					" source object"
			);
		case SystemCode::DS_PDC_OPERATION_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"Another operation which requires exclusive access to the PDC FSMO is already"
					" in progress"
			);
		case SystemCode::DS_CROSS_DOMAIN_CLEANUP_REQD:
			RETURN_STATIC_STRING(
					"A cross-domain move operation failed such that two versions of the moved"
					" object exist - one each in the source and destination domains. The"
					" destination object needs to be removed to restore the system to a consistent"
					" state"
			);
		case SystemCode::DS_ILLEGAL_XDOM_MOVE_OPERATION:
			RETURN_STATIC_STRING(
					"This object may not be moved across domain boundaries either because"
					" cross-domain moves for this class are disallowed, or the object has some"
					" special characteristics, e.g.: trust account or restricted RID, which prevent"
					" its move"
			);
		case SystemCode::DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS:
			RETURN_STATIC_STRING(
					"Can't move objects with memberships across domain boundaries as once moved,"
					" this would violate the membership conditions of the account group. Remove the"
					" object from any account group memberships and retry"
			);
		case SystemCode::DS_NC_MUST_HAVE_NC_PARENT:
			RETURN_STATIC_STRING(
					"A naming context head must be the immediate child of another naming context"
					" head, not of an interior node"
			);
		case SystemCode::DS_CR_IMPOSSIBLE_TO_VALIDATE:
			RETURN_STATIC_STRING(
					"The directory cannot validate the proposed naming context name because it does"
					" not hold a replica of the naming context above the proposed naming context."
					" Please ensure that the domain naming master role is held by a server that is"
					" configured as a global catalog server, and that the server is up to date with"
					" its replication partners. (Applies only to Windows 2000 Domain Naming"
					" masters)"
			);
		case SystemCode::DS_DST_DOMAIN_NOT_NATIVE:
			RETURN_STATIC_STRING(
					"Destination domain must be in native mode"
			);
		case SystemCode::DS_MISSING_INFRASTRUCTURE_CONTAINER:
			RETURN_STATIC_STRING(
					"The operation cannot be performed because the server does not have an"
					" infrastructure container in the domain of interest"
			);
		case SystemCode::DS_CANT_MOVE_ACCOUNT_GROUP:
			RETURN_STATIC_STRING(
					"Cross-domain move of non-empty account groups is not allowed"
			);
		case SystemCode::DS_CANT_MOVE_RESOURCE_GROUP:
			RETURN_STATIC_STRING(
					"Cross-domain move of non-empty resource groups is not allowed"
			);
		case SystemCode::DS_INVALID_SEARCH_FLAG:
			RETURN_STATIC_STRING(
					"The search flags for the attribute are invalid. The ANR bit is valid only on"
					" attributes of Unicode or Teletex strings"
			);
		case SystemCode::DS_NO_TREE_DELETE_ABOVE_NC:
			RETURN_STATIC_STRING(
					"Tree deletions starting at an object which has an NC head as a descendant are"
					" not allowed"
			);
		case SystemCode::DS_COULDNT_LOCK_TREE_FOR_DELETE:
			RETURN_STATIC_STRING(
					"The directory service failed to lock a tree in preparation for a tree deletion"
					" because the tree was in use"
			);
		case SystemCode::DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE:
			RETURN_STATIC_STRING(
					"The directory service failed to identify the list of objects to delete while"
					" attempting a tree deletion"
			);
		case SystemCode::DS_SAM_INIT_FAILURE:
			RETURN_STATIC_STRING(
					"Security Accounts Manager initialization failed because of the following"
					" error: %1. Error Status: 0x%2. Please shutdown this system and reboot into"
					" Directory Services Restore Mode, check the event log for more detailed"
					" information"
			);
		case SystemCode::DS_SENSITIVE_GROUP_VIOLATION:
			RETURN_STATIC_STRING(
					"Only an administrator can modify the membership list of an administrative"
					" group"
			);
		case SystemCode::DS_CANT_MOD_PRIMARYGROUPID:
			RETURN_STATIC_STRING(
					"Cannot change the primary group ID of a domain controller account"
			);
		case SystemCode::DS_ILLEGAL_BASE_SCHEMA_MOD:
			RETURN_STATIC_STRING(
					"An attempt is made to modify the base schema"
			);
		case SystemCode::DS_NONSAFE_SCHEMA_CHANGE:
			RETURN_STATIC_STRING(
					"Adding a new mandatory attribute to an existing class, deleting a mandatory"
					" attribute from an existing class, or adding an optional attribute to the"
					" special class Top that is not a backlink attribute (directly or through"
					" inheritance, for example, by adding or deleting an auxiliary class) is not"
					" allowed"
			);
		case SystemCode::DS_SCHEMA_UPDATE_DISALLOWED:
			RETURN_STATIC_STRING(
					"Schema update is not allowed on this DC because the DC is not the schema FSMO"
					" Role Owner"
			);
		case SystemCode::DS_CANT_CREATE_UNDER_SCHEMA:
			RETURN_STATIC_STRING(
					"An object of this class cannot be created under the schema container. You can"
					" only create attribute-schema and class-schema objects under the schema"
					" container"
			);
		case SystemCode::DS_INSTALL_NO_SRC_SCH_VERSION:
			RETURN_STATIC_STRING(
					"The replica/child install failed to get the objectVersion attribute on the"
					" schema container on the source DC. Either the attribute is missing on the"
					" schema container or the credentials supplied do not have permission to read"
					" it"
			);
		case SystemCode::DS_INSTALL_NO_SCH_VERSION_IN_INIFILE:
			RETURN_STATIC_STRING(
					"The replica/child install failed to read the objectVersion attribute in the"
					" SCHEMA section of the file schema.ini in the system32 directory"
			);
		case SystemCode::DS_INVALID_GROUP_TYPE:
			RETURN_STATIC_STRING(
					"The specified group type is invalid"
			);
		case SystemCode::DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN:
			RETURN_STATIC_STRING(
					"You cannot nest global groups in a mixed domain if the group is"
					" security-enabled"
			);
		case SystemCode::DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN:
			RETURN_STATIC_STRING(
					"You cannot nest local groups in a mixed domain if the group is"
					" security-enabled"
			);
		case SystemCode::DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER:
			RETURN_STATIC_STRING(
					"A global group cannot have a local group as a member"
			);
		case SystemCode::DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER:
			RETURN_STATIC_STRING(
					"A global group cannot have a universal group as a member"
			);
		case SystemCode::DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER:
			RETURN_STATIC_STRING(
					"A universal group cannot have a local group as a member"
			);
		case SystemCode::DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER:
			RETURN_STATIC_STRING(
					"A global group cannot have a cross-domain member"
			);
		case SystemCode::DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER:
			RETURN_STATIC_STRING(
					"A local group cannot have another cross domain local group as a member"
			);
		case SystemCode::DS_HAVE_PRIMARY_MEMBERS:
			RETURN_STATIC_STRING(
					"A group with primary members cannot change to a security-disabled group"
			);
		case SystemCode::DS_STRING_SD_CONVERSION_FAILED:
			RETURN_STATIC_STRING(
					"The schema cache load failed to convert the string default SD on a"
					" class-schema object"
			);
		case SystemCode::DS_NAMING_MASTER_GC:
			RETURN_STATIC_STRING(
					"Only DSAs configured to be Global Catalog servers should be allowed to hold"
					" the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers)"
			);
		case SystemCode::DS_DNS_LOOKUP_FAILURE:
			RETURN_STATIC_STRING(
					"The DSA operation is unable to proceed because of a DNS lookup failure"
			);
		case SystemCode::DS_COULDNT_UPDATE_SPNS:
			RETURN_STATIC_STRING(
					"While processing a change to the DNS Host Name for an object, the Service"
					" Principal Name values could not be kept in sync"
			);
		case SystemCode::DS_CANT_RETRIEVE_SD:
			RETURN_STATIC_STRING(
					"The Security Descriptor attribute could not be read"
			);
		case SystemCode::DS_KEY_NOT_UNIQUE:
			RETURN_STATIC_STRING(
					"The object requested was not found, but an object with that key was found"
			);
		case SystemCode::DS_WRONG_LINKED_ATT_SYNTAX:
			RETURN_STATIC_STRING(
					"The syntax of the linked attribute being added is incorrect. Forward links can"
					" only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have"
					" syntax 2.5.5.1"
			);
		case SystemCode::DS_SAM_NEED_BOOTKEY_PASSWORD:
			RETURN_STATIC_STRING(
					"Security Account Manager needs to get the boot password"
			);
		case SystemCode::DS_SAM_NEED_BOOTKEY_FLOPPY:
			RETURN_STATIC_STRING(
					"Security Account Manager needs to get the boot key from floppy disk"
			);
		case SystemCode::DS_CANT_START:
			RETURN_STATIC_STRING(
					"Directory Service cannot start"
			);
		case SystemCode::DS_INIT_FAILURE:
			RETURN_STATIC_STRING(
					"Directory Services could not start"
			);
		case SystemCode::DS_NO_PKT_PRIVACY_ON_CONNECTION:
			RETURN_STATIC_STRING(
					"The connection between client and server requires packet privacy or better"
			);
		case SystemCode::DS_SOURCE_DOMAIN_IN_FOREST:
			RETURN_STATIC_STRING(
					"The source domain may not be in the same forest as destination"
			);
		case SystemCode::DS_DESTINATION_DOMAIN_NOT_IN_FOREST:
			RETURN_STATIC_STRING(
					"The destination domain must be in the forest"
			);
		case SystemCode::DS_DESTINATION_AUDITING_NOT_ENABLED:
			RETURN_STATIC_STRING(
					"The operation requires that destination domain auditing be enabled"
			);
		case SystemCode::DS_CANT_FIND_DC_FOR_SRC_DOMAIN:
			RETURN_STATIC_STRING(
					"The operation couldn't locate a DC for the source domain"
			);
		case SystemCode::DS_SRC_OBJ_NOT_GROUP_OR_USER:
			RETURN_STATIC_STRING(
					"The source object must be a group or user"
			);
		case SystemCode::DS_SRC_SID_EXISTS_IN_FOREST:
			RETURN_STATIC_STRING(
					"The source object's SID already exists in destination forest"
			);
		case SystemCode::DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH:
			RETURN_STATIC_STRING(
					"The source and destination object must be of the same type"
			);
		case SystemCode::SAM_INIT_FAILURE:
			RETURN_STATIC_STRING(
					"Security Accounts Manager initialization failed because of the following"
					" error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot"
					" into Safe Mode. Check the event log for detailed information"
			);
		case SystemCode::DS_DRA_SCHEMA_INFO_SHIP:
			RETURN_STATIC_STRING(
					"Schema information could not be included in the replication request"
			);
		case SystemCode::DS_DRA_SCHEMA_CONFLICT:
			RETURN_STATIC_STRING(
					"The replication operation could not be completed due to a schema"
					" incompatibility"
			);
		case SystemCode::DS_DRA_EARLIER_SCHEMA_CONFLICT:
			RETURN_STATIC_STRING(
					"The replication operation could not be completed due to a previous schema"
					" incompatibility"
			);
		case SystemCode::DS_DRA_OBJ_NC_MISMATCH:
			RETURN_STATIC_STRING(
					"The replication update could not be applied because either the source or the"
					" destination has not yet received information regarding a recent cross-domain"
					" move operation"
			);
		case SystemCode::DS_NC_STILL_HAS_DSAS:
			RETURN_STATIC_STRING(
					"The requested domain could not be deleted because there exist domain"
					" controllers that still host this domain"
			);
		case SystemCode::DS_GC_REQUIRED:
			RETURN_STATIC_STRING(
					"The requested operation can be performed only on a global catalog server"
			);
		case SystemCode::DS_LOCAL_MEMBER_OF_LOCAL_ONLY:
			RETURN_STATIC_STRING(
					"A local group can only be a member of other local groups in the same domain"
			);
		case SystemCode::DS_NO_FPO_IN_UNIVERSAL_GROUPS:
			RETURN_STATIC_STRING(
					"Foreign security principals cannot be members of universal groups"
			);
		case SystemCode::DS_CANT_ADD_TO_GC:
			RETURN_STATIC_STRING(
					"The attribute is not allowed to be replicated to the GC because of security reasons"
			);
		case SystemCode::DS_NO_CHECKPOINT_WITH_PDC:
			RETURN_STATIC_STRING(
					"The checkpoint with the PDC could not be taken because there too many"
					" modifications being processed currently"
			);
		case SystemCode::DS_SOURCE_AUDITING_NOT_ENABLED:
			RETURN_STATIC_STRING(
					"The operation requires that source domain auditing be enabled"
			);
		case SystemCode::DS_CANT_CREATE_IN_NONDOMAIN_NC:
			RETURN_STATIC_STRING(
					"Security principal objects can only be created inside domain naming contexts"
			);
		case SystemCode::DS_INVALID_NAME_FOR_SPN:
			RETURN_STATIC_STRING(
					"A Service Principal Name (SPN) could not be constructed because the provided"
					" hostname is not in the necessary format"
			);
		case SystemCode::DS_FILTER_USES_CONTRUCTED_ATTRS:
			RETURN_STATIC_STRING(
					"A Filter was passed that uses constructed attributes"
			);
		case SystemCode::DS_UNICODEPWD_NOT_IN_QUOTES:
			RETURN_STATIC_STRING(
					"The unicodePwd attribute value must be enclosed in double quotes"
			);
		case SystemCode::DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED:
			RETURN_STATIC_STRING(
					"Your computer could not be joined to the domain. You have exceeded the maximum"
					" number of computer accounts you are allowed to create in this domain. Contact"
					" your system administrator to have this limit reset or increased"
			);
		case SystemCode::DS_MUST_BE_RUN_ON_DST_DC:
			RETURN_STATIC_STRING(
					"For security reasons, the operation must be run on the destination DC"
			);
		case SystemCode::DS_SRC_DC_MUST_BE_SP4_OR_GREATER:
			RETURN_STATIC_STRING(
					"For security reasons, the source DC must be NT4SP4 or greater"
			);
		case SystemCode::DS_CANT_TREE_DELETE_CRITICAL_OBJ:
			RETURN_STATIC_STRING(
					"Critical Directory Service System objects cannot be deleted during tree delete"
					" operations. The tree delete may have been partially performed"
			);
		case SystemCode::DS_INIT_FAILURE_CONSOLE:
			RETURN_STATIC_STRING(
					"Directory Services could not start because of the following error: %1. Error"
					" Status: 0x%2. Please click OK to shutdown the system. You can use the"
					" recovery console to diagnose the system further"
			);
		case SystemCode::DS_SAM_INIT_FAILURE_CONSOLE:
			RETURN_STATIC_STRING(
					"Security Accounts Manager initialization failed because of the following"
					" error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You"
					" can use the recovery console to diagnose the system further"
			);
		case SystemCode::DS_FOREST_VERSION_TOO_HIGH:
			RETURN_STATIC_STRING(
					"The version of the operating system is incompatible with the current AD DS"
					" forest functional level or AD LDS Configuration Set functional level. You"
					" must upgrade to a new version of the operating system before this server can"
					" become an AD DS Domain Controller or add an AD LDS Instance in this AD DS"
					" Forest or AD LDS Configuration Set"
			);
		case SystemCode::DS_DOMAIN_VERSION_TOO_HIGH:
			RETURN_STATIC_STRING(
					"The version of the operating system installed is incompatible with the current"
					" domain functional level. You must upgrade to a new version of the operating"
					" system before this server can become a domain controller in this domain"
			);
		case SystemCode::DS_FOREST_VERSION_TOO_LOW:
			RETURN_STATIC_STRING(
					"The version of the operating system installed on this server no longer"
					" supports the current AD DS Forest functional level or AD LDS Configuration"
					" Set functional level. You must raise the AD DS Forest functional level or AD"
					" LDS Configuration Set functional level before this server can become an AD DS"
					" Domain Controller or an AD LDS Instance in this Forest or Configuration Set"
			);
		case SystemCode::DS_DOMAIN_VERSION_TOO_LOW:
			RETURN_STATIC_STRING(
					"The version of the operating system installed on this server no longer"
					" supports the current domain functional level. You must raise the domain"
					" functional level before this server can become a domain controller in this"
					" domain"
			);
		case SystemCode::DS_INCOMPATIBLE_VERSION:
			RETURN_STATIC_STRING(
					"The version of the operating system installed on this server is incompatible"
					" with the functional level of the domain or forest"
			);
		case SystemCode::DS_LOW_DSA_VERSION:
			RETURN_STATIC_STRING(
					"The functional level of the domain (or forest) cannot be raised to the"
					" requested value, because there exist one or more domain controllers in the"
					" domain (or forest) that are at a lower incompatible functional level"
			);
		case SystemCode::DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN:
			RETURN_STATIC_STRING(
					"The forest functional level cannot be raised to the requested value since one"
					" or more domains are still in mixed domain mode. All domains in the forest"
					" must be in native mode, for you to raise the forest functional level"
			);
		case SystemCode::DS_NOT_SUPPORTED_SORT_ORDER:
			RETURN_STATIC_STRING(
					"The sort order requested is not supported"
			);
		case SystemCode::DS_NAME_NOT_UNIQUE:
			RETURN_STATIC_STRING(
					"The requested name already exists as a unique identifier"
			);
		case SystemCode::DS_MACHINE_ACCOUNT_CREATED_PRENT4:
			RETURN_STATIC_STRING(
					"The machine account was created pre-NT4. The account needs to be recreated"
			);
		case SystemCode::DS_OUT_OF_VERSION_STORE:
			RETURN_STATIC_STRING(
					"The database is out of version store"
			);
		case SystemCode::DS_INCOMPATIBLE_CONTROLS_USED:
			RETURN_STATIC_STRING(
					"Unable to continue operation because multiple conflicting controls were used"
			);
		case SystemCode::DS_NO_REF_DOMAIN:
			RETURN_STATIC_STRING(
					"Unable to find a valid security descriptor reference domain for this partition"
			);
		case SystemCode::DS_RESERVED_LINK_ID:
			RETURN_STATIC_STRING(
					"Schema update failed: The link identifier is reserved"
			);
		case SystemCode::DS_LINK_ID_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"Schema update failed: There are no link identifiers available"
			);
		case SystemCode::DS_AG_CANT_HAVE_UNIVERSAL_MEMBER:
			RETURN_STATIC_STRING(
					"An account group cannot have a universal group as a member"
			);
		case SystemCode::DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE:
			RETURN_STATIC_STRING(
					"Rename or move operations on naming context heads or read-only objects are not"
					" allowed"
			);
		case SystemCode::DS_NO_OBJECT_MOVE_IN_SCHEMA_NC:
			RETURN_STATIC_STRING(
					"Move operations on objects in the schema naming context are not allowed"
			);
		case SystemCode::DS_MODIFYDN_DISALLOWED_BY_FLAG:
			RETURN_STATIC_STRING(
					"A system flag has been set on the object and does not allow the object to be"
					" moved or renamed"
			);
		case SystemCode::DS_MODIFYDN_WRONG_GRANDPARENT:
			RETURN_STATIC_STRING(
					"This object is not allowed to change its grandparent container. Moves are not"
					" forbidden on this object, but are restricted to sibling containers"
			);
		case SystemCode::DS_NAME_ERROR_TRUST_REFERRAL:
			RETURN_STATIC_STRING(
					"Unable to resolve completely, a referral to another forest is generated"
			);
		case SystemCode::NOT_SUPPORTED_ON_STANDARD_SERVER:
			RETURN_STATIC_STRING(
					"The requested action is not supported on standard server"
			);
		case SystemCode::DS_CANT_ACCESS_REMOTE_PART_OF_AD:
			RETURN_STATIC_STRING(
					"Could not access a partition of the directory service located on a remote"
					" server. Make sure at least one server is running for the partition in"
					" question"
			);
		case SystemCode::DS_CR_IMPOSSIBLE_TO_VALIDATE_V2:
			RETURN_STATIC_STRING(
					"The directory cannot validate the proposed naming context (or partition) name"
					" because it does not hold a replica nor can it contact a replica of the naming"
					" context above the proposed naming context. Please ensure that the parent"
					" naming context is properly registered in DNS, and at least one replica of"
					" this naming context is reachable by the Domain Naming master"
			);
		case SystemCode::DS_THREAD_LIMIT_EXCEEDED:
			RETURN_STATIC_STRING(
					"The thread limit for this request was exceeded"
			);
		case SystemCode::DS_NOT_CLOSEST:
			RETURN_STATIC_STRING(
					"The Global catalog server is not in the closest site"
			);
		case SystemCode::DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF:
			RETURN_STATIC_STRING(
					"The DS cannot derive a service principal name (SPN) with which to mutually"
					" authenticate the target server because the corresponding server object in the"
					" local DS database has no serverReference attribute"
			);
		case SystemCode::DS_SINGLE_USER_MODE_FAILED:
			RETURN_STATIC_STRING(
					"The Directory Service failed to enter single user mode"
			);
		case SystemCode::DS_NTDSCRIPT_SYNTAX_ERROR:
			RETURN_STATIC_STRING(
					"The Directory Service cannot parse the script because of a syntax error"
			);
		case SystemCode::DS_NTDSCRIPT_PROCESS_ERROR:
			RETURN_STATIC_STRING(
					"The Directory Service cannot process the script because of an error"
			);
		case SystemCode::DS_DIFFERENT_REPL_EPOCHS:
			RETURN_STATIC_STRING(
					"The directory service cannot perform the requested operation because the"
					" servers involved are of different replication epochs (which is usually"
					" related to a domain rename that is in progress)"
			);
		case SystemCode::DS_DRS_EXTENSIONS_CHANGED:
			RETURN_STATIC_STRING(
					"The directory service binding must be renegotiated due to a change in the"
					" server extensions information"
			);
		case SystemCode::DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR:
			RETURN_STATIC_STRING(
					"Operation not allowed on a disabled cross ref"
			);
		case SystemCode::DS_NO_MSDS_INTID:
			RETURN_STATIC_STRING(
					"Schema update failed: No values for msDS-IntId are available"
			);
		case SystemCode::DS_DUP_MSDS_INTID:
			RETURN_STATIC_STRING(
					"Schema update failed: Duplicate msDS-INtId. Retry the operation"
			);
		case SystemCode::DS_EXISTS_IN_RDNATTID:
			RETURN_STATIC_STRING(
					"Schema deletion failed: attribute is used in rDNAttID"
			);
		case SystemCode::DS_AUTHORIZATION_FAILED:
			RETURN_STATIC_STRING(
					"The directory service failed to authorize the request"
			);
		case SystemCode::DS_INVALID_SCRIPT:
			RETURN_STATIC_STRING(
					"The Directory Service cannot process the script because it is invalid"
			);
		case SystemCode::DS_REMOTE_CROSSREF_OP_FAILED:
			RETURN_STATIC_STRING(
					"The remote create cross reference operation failed on the Domain Naming Master"
					" FSMO. The operation's error is in the extended data"
			);
		case SystemCode::DS_CROSS_REF_BUSY:
			RETURN_STATIC_STRING(
					"A cross reference is in use locally with the same name"
			);
		case SystemCode::DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN:
			RETURN_STATIC_STRING(
					"The DS cannot derive a service principal name (SPN) with which to mutually"
					" authenticate the target server because the server's domain has been deleted"
					" from the forest"
			);
		case SystemCode::DS_CANT_DEMOTE_WITH_WRITEABLE_NC:
			RETURN_STATIC_STRING(
					"Writeable NCs prevent this DC from demoting"
			);
		case SystemCode::DS_DUPLICATE_ID_FOUND:
			RETURN_STATIC_STRING(
					"The requested object has a non-unique identifier and cannot be retrieved"
			);
		case SystemCode::DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT:
			RETURN_STATIC_STRING(
					"Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected"
			);
		case SystemCode::DS_GROUP_CONVERSION_ERROR:
			RETURN_STATIC_STRING(
					"The group cannot be converted due to attribute restrictions on the requested group type"
			);
		case SystemCode::DS_CANT_MOVE_APP_BASIC_GROUP:
			RETURN_STATIC_STRING(
					"Cross-domain move of non-empty basic application groups is not allowed"
			);
		case SystemCode::DS_CANT_MOVE_APP_QUERY_GROUP:
			RETURN_STATIC_STRING(
					"Cross-domain move of non-empty query based application groups is not allowed"
			);
		case SystemCode::DS_ROLE_NOT_VERIFIED:
			RETURN_STATIC_STRING(
					"The FSMO role ownership could not be verified because its directory partition has not replicated successfully with at least one replication partner"
			);
		case SystemCode::DS_WKO_CONTAINER_CANNOT_BE_SPECIAL:
			RETURN_STATIC_STRING(
					"The target container for a redirection of a well known object container cannot already be a special container"
			);
		case SystemCode::DS_DOMAIN_RENAME_IN_PROGRESS:
			RETURN_STATIC_STRING(
					"The Directory Service cannot perform the requested operation because a domain rename operation is in progress"
			);
		case SystemCode::DS_EXISTING_AD_CHILD_NC:
			RETURN_STATIC_STRING(
					"The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method"
			);
		case SystemCode::DS_REPL_LIFETIME_EXCEEDED:
			RETURN_STATIC_STRING(
					"The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime"
			);
		case SystemCode::DS_DISALLOWED_IN_SYSTEM_CONTAINER:
			RETURN_STATIC_STRING(
					"The requested operation is not allowed on an object under the system container"
			);
		case SystemCode::DS_LDAP_SEND_QUEUE_FULL:
			RETURN_STATIC_STRING(
					"The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected"
			);
		case SystemCode::DS_DRA_OUT_SCHEDULE_WINDOW:
			RETURN_STATIC_STRING(
					"The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency"
			);
		case SystemCode::DS_POLICY_NOT_KNOWN:
			RETURN_STATIC_STRING(
					"At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies"
			);
		case SystemCode::NO_SITE_SETTINGS_OBJECT:
			RETURN_STATIC_STRING(
					"The site settings object for the specified site does not exist"
			);
		case SystemCode::NO_SECRETS:
			RETURN_STATIC_STRING(
					"The local account store does not contain secret material for the specified account"
			);
		case SystemCode::NO_WRITABLE_DC_FOUND:
			RETURN_STATIC_STRING(
					"Could not find a writable domain controller in the domain"
			);
		case SystemCode::DS_NO_SERVER_OBJECT:
			RETURN_STATIC_STRING(
					"The server object for the domain controller does not exist"
			);
		case SystemCode::DS_NO_NTDSA_OBJECT:
			RETURN_STATIC_STRING(
					"The NTDS Settings object for the domain controller does not exist"
			);
		case SystemCode::DS_NON_ASQ_SEARCH:
			RETURN_STATIC_STRING(
					"The requested search operation is not supported for ASQ searches"
			);
		case SystemCode::DS_AUDIT_FAILURE:
			RETURN_STATIC_STRING(
					"A required audit event could not be generated for the operation"
			);
		case SystemCode::DS_INVALID_SEARCH_FLAG_SUBTREE:
			RETURN_STATIC_STRING(
					"The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes"
			);
		case SystemCode::DS_INVALID_SEARCH_FLAG_TUPLE:
			RETURN_STATIC_STRING(
					"The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings"
			);
		case SystemCode::DS_HIERARCHY_TABLE_TOO_DEEP:
			RETURN_STATIC_STRING(
					"The address books are nested too deeply. Failed to build the hierarchy table"
			);
		case SystemCode::DS_DRA_CORRUPT_UTD_VECTOR:
			RETURN_STATIC_STRING(
					"The specified up-to-date-ness vector is corrupt"
			);
		case SystemCode::DS_DRA_SECRETS_DENIED:
			RETURN_STATIC_STRING(
					"The request to replicate secrets is denied"
			);
		case SystemCode::DS_RESERVED_MAPI_ID:
			RETURN_STATIC_STRING(
					"Schema update failed: The MAPI identifier is reserved"
			);
		case SystemCode::DS_MAPI_ID_NOT_AVAILABLE:
			RETURN_STATIC_STRING(
					"Schema update failed: There are no MAPI identifiers available"
			);
		case SystemCode::DS_DRA_MISSING_KRBTGT_SECRET:
			RETURN_STATIC_STRING(
					"The replication operation failed because the required attributes of the local krbtgt object are missing"
			);
		case SystemCode::DS_DOMAIN_NAME_EXISTS_IN_FOREST:
			RETURN_STATIC_STRING(
					"The domain name of the trusted domain already exists in the forest"
			);
		case SystemCode::DS_FLAT_NAME_EXISTS_IN_FOREST:
			RETURN_STATIC_STRING(
					"The flat name of the trusted domain already exists in the forest"
			);
		case SystemCode::INVALID_USER_PRINCIPAL_NAME:
			RETURN_STATIC_STRING(
					"The User Principal Name (UPN) is invalid"
			);
		case SystemCode::DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS:
			RETURN_STATIC_STRING(
					"OID mapped groups cannot have members"
			);
		case SystemCode::DS_OID_NOT_FOUND:
			RETURN_STATIC_STRING(
					"The specified OID cannot be found"
			);
		case SystemCode::DS_DRA_RECYCLED_TARGET:
			RETURN_STATIC_STRING(
					"The replication operation failed because the target object referred by a link value is recycled"
			);
		case SystemCode::DS_DISALLOWED_NC_REDIRECT:
			RETURN_STATIC_STRING(
					"The redirect operation failed because the target object is in a NC different from the domain NC of the current domain controller"
			);
		case SystemCode::DS_HIGH_ADLDS_FFL:
			RETURN_STATIC_STRING(
					"The functional level of the AD LDS configuration set cannot be lowered to the requested value"
			);
		case SystemCode::DS_HIGH_DSA_VERSION:
			RETURN_STATIC_STRING(
					"The functional level of the domain (or forest) cannot be lowered to the requested value"
			);
		case SystemCode::DS_LOW_ADLDS_FFL:
			RETURN_STATIC_STRING(
					"The functional level of the AD LDS configuration set cannot be raised to the requested value, because there exist one or more ADLDS instances that are at a lower incompatible functional level"
			);
		case SystemCode::DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION:
			RETURN_STATIC_STRING(
					"The domain join cannot be completed because the SID of the domain you attempted to join was identical to the SID of this machine. This is a symptom of an improperly cloned operating system install. You should run sysprep on this machine in order to generate a new machine SID. Please see https://go.microsoft.com/fwlink/p/?linkid=168895 for more information"
			);
		case SystemCode::DS_UNDELETE_SAM_VALIDATION_FAILED:
			RETURN_STATIC_STRING(
					"The undelete operation failed because the Sam Account Name or Additional Sam Account Name of the object being undeleted conflicts with an existing live object"
			);
		case SystemCode::INCORRECT_ACCOUNT_TYPE:
			RETURN_STATIC_STRING(
					"The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site"
			);
	};
	return nullptr;
}

}}} // flame_ide::os::error
