#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_VALUETYPES_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_VALUETYPES_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace value_types
{

/// @defgroup pkcs11_value_types PKCS#11 value types

/// @addtogroup pkcs11_value_types
/// @brief PKCS#11 value types
/// @{

using Byte = ::CK_BYTE;
using Char = ::CK_CHAR;
using Utf8Char = ::CK_UTF8CHAR;
using Bool = ::CK_BBOOL;
using Ulong = ::CK_ULONG;
using Long = ::CK_LONG;
using Flags = ::CK_FLAGS;

using ValuePtr = ::CK_VOID_PTR;
using BytePtr = ::CK_BYTE_PTR;
using CharPtr = ::CK_CHAR_PTR;
using Utf8CharPtr = ::CK_UTF8CHAR_PTR;
using UlongPtr = ::CK_ULONG_PTR;

using ValuePtrPtr = ::CK_VOID_PTR_PTR;

using Notification = ::CK_NOTIFICATION; // CKN_SURRENDER & CKN_OTP_CHANGED

using SlotId = ::CK_SLOT_ID;
using SlotIdPtr = ::CK_SLOT_ID_PTR;

using SlotInfoFlags = Flags;

using TokenInfoFlags = Flags; // CKF_RNG and etc.

using SessionHandle = ::CK_SESSION_HANDLE;
using SessionHandlePtr = ::CK_SESSION_HANDLE_PTR;

using User = ::CK_USER_TYPE; // CKU_*

using State = ::CK_STATE; // CKS_*

using SessionInfoFlags = Flags;

using ObjectHandle = ::CK_OBJECT_HANDLE;
using ObjectHandlePtr = ::CK_OBJECT_HANDLE_PTR;

using ObjectClass = ::CK_OBJECT_CLASS;
using ObjectClassPtr = ::CK_OBJECT_CLASS_PTR;

using HwFeature = ::CK_HW_FEATURE_TYPE; // CKH_*

using Key = ::CK_KEY_TYPE; // CKK_*

using Certificate = ::CK_CERTIFICATE_TYPE; // ::CK_CERTIFICATE_*, ::CK_SECURITY_*, CKC_*

using Attribute = ::CK_ATTRIBUTE_TYPE; // ::CK_OTP_*, CKA_*

using Mechanism = ::CK_MECHANISM_TYPE; // CKM_*
using MechanismPtr = ::CK_MECHANISM_TYPE_PTR;

using MechanismInfoFlags = ::CK_FLAGS; // CKF_*

using ReturnType = ::CK_RV; // CKR_*

using IntializeArgsFlags = ::CK_FLAGS; // CKF_*

using RsaPkcsMessageGenerationFunction = ::CK_RSA_PKCS_MGF_TYPE; // CKG_*

using RsaPkcsOaepSource = ::CK_RSA_PKCS_OAEP_SOURCE_TYPE;
using RsaPkcsOaepSourcePtr = ::CK_RSA_PKCS_OAEP_SOURCE_TYPE_PTR;

using EcKdf = ::CK_EC_KDF_TYPE; // CKD_*

using X9DhKdf = ::CK_X9_42_DH_KDF_TYPE;
using X9DhKdfPtr = ::CK_X9_42_DH_KDF_TYPE_PTR;

using Rc2Params = ::CK_RC2_PARAMS;
using Rc2ParamsPtr = ::CK_RC2_PARAMS_PTR;

using MacGeneralParams = ::CK_MAC_GENERAL_PARAMS;
using MacGeneralParamsPtr = ::CK_MAC_GENERAL_PARAMS_PTR;

using ExtractParams = ::CK_EXTRACT_PARAMS;
using ExtractParamsPtr = ::CK_EXTRACT_PARAMS_PTR;

// enum CKP_PKCS5_PBKD2_HMAC_*
using Pkcs5Pbkd2PseudoRandomFunction = ::CK_PKCS5_PBKD2_PSEUDO_RANDOM_FUNCTION_TYPE;
using Pkcs5Pbkd2PseudoRandomFunctionPtr = ::CK_PKCS5_PBKD2_PSEUDO_RANDOM_FUNCTION_TYPE_PTR;

// CKZ_SALT_SPECIFIED
using Pkcs5Pbkdf2SaltSource = ::CK_PKCS5_PBKDF2_SALT_SOURCE_TYPE;
using Pkcs5Pbkdf2SaltSourcePtr = ::CK_PKCS5_PBKDF2_SALT_SOURCE_TYPE_PTR;

// ::CK_OTP_*
using OtpParam = ::CK_OTP_PARAM_TYPE;

// CKF_* after ::CK_OTP_*
using OtpFlags = ::CK_FLAGS;

using JavaMidpSecurityDomain = ::CK_JAVA_MIDP_SECURITY_DOMAIN;

using CertificateCategory = ::CK_CERTIFICATE_CATEGORY;

/// @}

} // namespace value_types
} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_VALUETYPES_HPP
