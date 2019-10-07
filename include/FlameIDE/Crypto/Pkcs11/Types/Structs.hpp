#ifndef FLAMEDE_CRYPRO_PKCS11_TYPES_STRUCTS_HPP
#define FLAMEDE_CRYPRO_PKCS11_TYPES_STRUCTS_HPP

#include "../cryptoki/pkcs11.h"

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

using Version = CK_VERSION;
using VersionPtr = CK_VERSION_PTR;

using Info = CK_INFO;
using InfoPtr = CK_INFO_PTR;

using SlotInfo = CK_SLOT_INFO;
using SlotInfoPtr = CK_SLOT_INFO_PTR;

using TokenInfo = CK_TOKEN_INFO;
using TokenInfoPtr = CK_TOKEN_INFO_PTR;

using SessionInfo = CK_SESSION_INFO;
using SessionInfoPtr = CK_SESSION_INFO_PTR;

using Attribute = CK_ATTRIBUTE;
using AttributePtr = CK_ATTRIBUTE_PTR;

using Date = CK_DATE;

using Mechanism = CK_MECHANISM;
using MechanismPtr = CK_MECHANISM_PTR;

using MechanismInfo = CK_MECHANISM_INFO;
using MechanismInfoPtr = CK_MECHANISM_INFO_PTR;

using FunctionList = CK_FUNCTION_LIST;
using FunctionListPtr = CK_FUNCTION_LIST_PTR;
using FunctionListPtrPtr = CK_FUNCTION_LIST_PTR_PTR;

using IntializeArgs = CK_C_INITIALIZE_ARGS;
using IntializeArgsPtr = CK_C_INITIALIZE_ARGS_PTR;

using RsaPkcsOaepParams = CK_RSA_PKCS_OAEP_PARAMS;
using RsaPkcsOaepParamsPtr = CK_RSA_PKCS_OAEP_PARAMS_PTR;

using RsaPkcsPssParams = CK_RSA_PKCS_PSS_PARAMS;
using RsaPkcsPssParamsPtr = CK_RSA_PKCS_PSS_PARAMS_PTR;

using Ecdh1DeriveParams = CK_ECDH1_DERIVE_PARAMS;
using Ecdh1DeriveParamsPtr = CK_ECDH1_DERIVE_PARAMS_PTR;

using Ecdh2DeriveParams = CK_ECDH2_DERIVE_PARAMS;
using Ecdh2DeriveParamsPtr = CK_ECDH2_DERIVE_PARAMS_PTR;

using EcmqvDeriveparams = CK_ECMQV_DERIVE_PARAMS;
using EcmqvDeriveparamsPtr = CK_ECMQV_DERIVE_PARAMS_PTR;

using X9Dh1DeriveParams = CK_X9_42_DH1_DERIVE_PARAMS;
using X9Dh1DeriveParamsPtr = CK_X9_42_DH1_DERIVE_PARAMS_PTR;

using X9Dh2DeriveParams = CK_X9_42_DH2_DERIVE_PARAMS;
using X9Dh2DeriveParamsPtr = CK_X9_42_DH2_DERIVE_PARAMS_PTR;

using X9MqvDeriveParams = CK_X9_42_MQV_DERIVE_PARAMS;
using X9MqvDeriveParamsPtr = CK_X9_42_MQV_DERIVE_PARAMS_PTR;

using KeaDeriveParams = CK_KEA_DERIVE_PARAMS;
using KeaDeriveParamsPtr = CK_KEA_DERIVE_PARAMS_PTR;

using Rc2CbcParams = CK_RC2_CBC_PARAMS;
using Rc2CbcParamsPtr = CK_RC2_CBC_PARAMS_PTR;

using Rc2MacGeneralParams = CK_RC2_MAC_GENERAL_PARAMS;
using Rc2MacGeneralParamsPtr = CK_RC2_MAC_GENERAL_PARAMS_PTR;

using Rc5Params = CK_RC5_PARAMS;
using Rc5ParamsPtr = CK_RC5_PARAMS_PTR;

using Rc5CbcParams = CK_RC5_CBC_PARAMS;
using Rc5CbcParamsPtr = CK_RC5_CBC_PARAMS_PTR;

using Rc5MacGeneralParams = CK_RC5_MAC_GENERAL_PARAMS;
using Rc5MacGeneralParamsPtr = CK_RC5_MAC_GENERAL_PARAMS_PTR;

using DesCbcEncryptDataParams = CK_DES_CBC_ENCRYPT_DATA_PARAMS;
using DesCbcEncryptDataParamsPtr = CK_DES_CBC_ENCRYPT_DATA_PARAMS_PTR;

using AesCbcEncryptDataParams = CK_AES_CBC_ENCRYPT_DATA_PARAMS;
using AesCbcEncryptDataParamsPtr = CK_AES_CBC_ENCRYPT_DATA_PARAMS_PTR;

using SkipjackPrivateWrapParams = CK_SKIPJACK_PRIVATE_WRAP_PARAMS;
using SkipjackPrivateWrapParamsPtr = CK_SKIPJACK_PRIVATE_WRAP_PARAMS_PTR;

using SkipjackRelayxParams = CK_SKIPJACK_RELAYX_PARAMS;
using SkipjackRelayxParamsPtr = CK_SKIPJACK_RELAYX_PARAMS_PTR;

using PbeParams = CK_PBE_PARAMS;
using PbeParamsPtr = CK_PBE_PARAMS_PTR;

using KeyWrapSetOaepParams = CK_KEY_WRAP_SET_OAEP_PARAMS;
using KeyWrapSetOaepParamsPtr = CK_KEY_WRAP_SET_OAEP_PARAMS_PTR;



using Ssl3RandomData = CK_SSL3_RANDOM_DATA;

using Ssl3MasterKeyDeriveParams = CK_SSL3_MASTER_KEY_DERIVE_PARAMS;
using Ssl3MasterKeyDeriveParamsPtr = CK_SSL3_MASTER_KEY_DERIVE_PARAMS_PTR;

using Ssl3KeyMatOut = CK_SSL3_KEY_MAT_OUT;
using Ssl3KeyMatOutPtr = CK_SSL3_KEY_MAT_OUT_PTR;

using Ssl3KeyMatParams = CK_SSL3_KEY_MAT_PARAMS;
using Ssl3KeyMatParamsPtr = CK_SSL3_KEY_MAT_PARAMS_PTR;

using TlsPrfParams = CK_TLS_PRF_PARAMS;
using TlsPrfParamsPtr = CK_TLS_PRF_PARAMS_PTR;

using WtlsRandomData = CK_WTLS_RANDOM_DATA;
using WtlsRandomDataPtr = CK_WTLS_RANDOM_DATA_PTR;

using WtlsMasterKeyDeriveParams = CK_WTLS_MASTER_KEY_DERIVE_PARAMS;
using WtlsMasterKeyDeriveParamsPtr = CK_WTLS_MASTER_KEY_DERIVE_PARAMS_PTR;

using WtlsPrfParams = CK_WTLS_PRF_PARAMS;
using WtlsPrfParamsPtr = CK_WTLS_PRF_PARAMS_PTR;

using WtlsKeyMatOut = CK_WTLS_KEY_MAT_OUT;
using WtlsKeyMatOutPtr = CK_WTLS_KEY_MAT_OUT_PTR;

using WtlsKeyMatParams = CK_WTLS_KEY_MAT_PARAMS;
using WtlsKeyMatParamsPtr = CK_WTLS_KEY_MAT_PARAMS_PTR;

using CmsSigParams = CK_CMS_SIG_PARAMS;
using CmsSigParamsPtr = CK_CMS_SIG_PARAMS_PTR;

using KeyDerivationStringData = CK_KEY_DERIVATION_STRING_DATA;
using KeyDerivationStringDataPtr = CK_KEY_DERIVATION_STRING_DATA_PTR;

using Pkcs5Pbkd2Params = CK_PKCS5_PBKD2_PARAMS;
using Pkcs5Pbkd2ParamsPtr = CK_PKCS5_PBKD2_PARAMS_PTR;

using Pkcs5Pbkd2Params2 = CK_PKCS5_PBKD2_PARAMS2;
using Pkcs5Pbkd2Params2Ptr = CK_PKCS5_PBKD2_PARAMS2_PTR;

using OtpParam = CK_OTP_PARAM;
using OtpParamPtr = CK_OTP_PARAM_PTR;

using OtpParams = CK_OTP_PARAMS;
using OtpParamsPtr = CK_OTP_PARAMS_PTR;

using OtpSignatureInfo = CK_OTP_SIGNATURE_INFO;
using OtpSignatureInfoPtr = CK_OTP_SIGNATURE_INFO_PTR;



using KipParams = CK_KIP_PARAMS;
using KipParamsPtr = CK_KIP_PARAMS_PTR;

using AesCtrParams = CK_AES_CTR_PARAMS;
using AesCtrParamsPtr = CK_AES_CTR_PARAMS_PTR;

using GcmParams = CK_GCM_PARAMS;
using GcmParamsPtr = CK_GCM_PARAMS_PTR;

using CcmParams = CK_CCM_PARAMS;
using CcmParamsPtr = CK_CCM_PARAMS_PTR;

using AesGcmParams = CK_AES_GCM_PARAMS;
using AesGcmParamsPtr = CK_AES_GCM_PARAMS_PTR;

using AesCcmParams = CK_AES_CCM_PARAMS;
using AesCcmParamsPtr = CK_AES_CCM_PARAMS_PTR;

using CamelliaCtrParams = CK_CAMELLIA_CTR_PARAMS;
using CamelliaCtrParamsPtr = CK_CAMELLIA_CTR_PARAMS_PTR;

using CamelliaCbcEncryptDataParams = CK_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS;
using CamelliaCbcEncryptDataParamsPtr = CK_CAMELLIA_CBC_ENCRYPT_DATA_PARAMS_PTR;

using AriaCbcEncryptDataParams = CK_ARIA_CBC_ENCRYPT_DATA_PARAMS;
using AriaCbcEncryptDataParamsPtr = CK_ARIA_CBC_ENCRYPT_DATA_PARAMS_PTR;

using DsaParameterGenParam = CK_DSA_PARAMETER_GEN_PARAM;
using DsaParameterGenParamPtr = CK_DSA_PARAMETER_GEN_PARAM_PTR;

using EcdhAesKeyWrapParams = CK_ECDH_AES_KEY_WRAP_PARAMS;
using EcdhAesKeyWrapParamsPtr = CK_ECDH_AES_KEY_WRAP_PARAMS_PTR;

using RsaAesKeyWrapParams = CK_RSA_AES_KEY_WRAP_PARAMS;
using RsaAesKeyWrapParamsPtr = CK_RSA_AES_KEY_WRAP_PARAMS_PTR;

using Tls12MasterKeyDeriveParams = CK_TLS12_MASTER_KEY_DERIVE_PARAMS;
using Tls12MasterKeyDeriveParamsPtr = CK_TLS12_MASTER_KEY_DERIVE_PARAMS_PTR;

using Tls12KeyMatParams = CK_TLS12_KEY_MAT_PARAMS;
using Tls12KeyMatParamsPtr = CK_TLS12_KEY_MAT_PARAMS_PTR;

using TlsKdfParams = CK_TLS_KDF_PARAMS;
using TlsKdfParamsPtr = CK_TLS_KDF_PARAMS_PTR;

using TlsMacParams = CK_TLS_MAC_PARAMS;
using TlsMacParamsPtr = CK_TLS_MAC_PARAMS_PTR;

using Gostr3410DeriveParams = CK_GOSTR3410_DERIVE_PARAMS;
using Gostr3410DeriveParamsPtr = CK_GOSTR3410_DERIVE_PARAMS_PTR;

using Gostr3410_KeyWrapParams = CK_GOSTR3410_KEY_WRAP_PARAMS;
using Gostr3410_KeyWrapParamsPtr = CK_GOSTR3410_KEY_WRAP_PARAMS_PTR;

using SeedCbcEncryptDataParams = CK_SEED_CBC_ENCRYPT_DATA_PARAMS;
using SeedCbcEncryptDataParamsPtr = CK_SEED_CBC_ENCRYPT_DATA_PARAMS_PTR;

} // namespace structs
} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEDE_CRYPRO_PKCS11_TYPES_STRUCTS_HPP
