#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Version.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Info.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SlotInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TokenInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SessionInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Attribute.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Date.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Mechanism.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/MechanismInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList3.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Interface.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/InitializeArgs.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaPkcsOaepParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaPkcsPssParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcDh1DeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcDh2DeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcMqvDeriveParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/X9dot42DiffieHellman1DeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/X9dot42DiffieHellman2DeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/X9dot42MqvDeriveParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeaDeriveParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc2CbcParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc2MacGeneralParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5Params.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5CbcParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5MacGeneralParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DesCbcEncryptDataParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AesCbcEncryptDataParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SkipjackPrivateWrapParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SkipjackRelayxParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/PbeParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeyWrapSetOaepParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3RandomData.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3MasterKeyDeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3KeyMatOut.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Ssl3KeyMatParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsPrfParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsRandomData.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsMasterKeyDeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsPrfParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsKeyMatOut.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/WtlsKeyMatParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CmsSigParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeyDerivationStringData.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Pkcs5Pbkd2Params.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Pkcs5Pbkd2Params2.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpParam.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/OtpSignatureInfo.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KipParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AesCtrParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/GcmParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/GcmMessageParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CcmParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CcmMessageParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CamelliaCtrParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CamelliaCbcEncryptDataParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AriaCbcEncryptDataParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DsaParameterGenParam.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EcdhAesKeyWrapParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/RsaAesKeyWrapParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Tls12MasterKeyDeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Tls12KeyMatParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsKdfParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsMacParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Gostr3410DeriveParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Gostr3410KeyWrapParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SeedCbcEncryptDataParams.hpp>

// v3.0

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/PrfDataParam.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108CounterFormat.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108DkmLengthFormat.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DerivedKey.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108KdfParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108FeedbackKdfParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/EdDsaParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ChaCha20Params.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20Params.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20ChaCha20Poly1305Params.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20ChaCha20Poly1305MessageParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedTripleDiffieHellmanInitiateParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedTripleDiffieHellmanRespondParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DoubleRatchetInitializeParams.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/DoubleRatchetRespondParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ExtendedEdDsaParams.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/HkdfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

//using AesGcmParams = ::CK_AES_GCM_PARAMS; // Deprecated
//using AesGcmParamsPtr = ::CK_AES_GCM_PARAMS_PTR; // Deprecated
using AesGcmParams = GcmParams;
using AesGcmParamsPtr = GcmParamsPtr;

//using AesCcmParams = ::CK_AES_CCM_PARAMS; // Deprecated
//using AesCcmParamsPtr = ::CK_AES_CCM_PARAMS_PTR; // Deprecated
using AesCcmParams = CcmParams;
using AesCcmParamsPtr = CcmParamsPtr;

} // namespace structs
} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_HPP
