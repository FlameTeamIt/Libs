#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismList.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa9796.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaXdot509.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsOaep.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaX9dot31KeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaX9dot31.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaX9dot31.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Dsa.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha1.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha224.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha256.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha384.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha512.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanHybridDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42MqvDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224RsaPkcs.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224RsaPkcsPss.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512t.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tHmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tHmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tKeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2MacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2CbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc4KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc4.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des2KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3MacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Cmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesOfb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesOfb8.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCfb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCfb8.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512HmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SecurIdKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SecurId.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/HotpKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Hotp.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Acti.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ActiKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3MacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3CbcPad.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128KeyGenerator.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Ecb.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Cbc.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Mac.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5MacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128MacGeneral.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5CbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128CbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5MacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5CbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/GenericSecretKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateBaseAndKey.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateBaseAndData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateDataAndBase.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/XorBaseAndData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ExtractKeyFromKey.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3PreMasterKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3MasterKeyDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3KeyAndMacDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3MasterKeyDeriveDiffieHellman.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsPreMasterKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMasterKeyDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsKeyAndMacDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMasterKeyDeriveDiffieHellman.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsPrf.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3Md5Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3Sha1Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224KeyDerivation.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd2DesCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5DesCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5CastCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast3Cbc.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast5Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast128Cbc.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Cast5Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Cast128Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc4dot128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc4dot40.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Des3EdeCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Des2EdeCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc2dot128Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc2dot40Cbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Pkcs5Pbkd2.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbaSha1WithSha1Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsPreMasterKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsMasterKeyDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsMasterKeyDeriveDiffieHellmanEcc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsPrf.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsServerKeyAndMacDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsClientKeyAndMacDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls10MacServer.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls10MacClient.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12Kdf.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12MasterKeyDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12KeyAndMacDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12MasterKeyDeriveDiffieHellman.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12KeySafeDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsKdf.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeyWrapLynks.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeyWrapSetOaep.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CmsSignature.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaEcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCtr.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaEcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedEcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackEcb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCbc64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackOfb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb32.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb16.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb8.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackPrivateWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackRelayx.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaKeyDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/FortezzaTimestamp.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonEcb128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonEcb96.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonCbc128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonCounter.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonShuffle.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonWrap.hpp>
//#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveKeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsa.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha1.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha224.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha256.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha384.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha512.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellman1Derive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellman1CofactorDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveMqvDerive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellmanAesKeyWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaAesKeyWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperEcb128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperCbc128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperCounter.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperShuffle.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Fasthash.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesEcb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesMacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCtr.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesGcm.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCcm.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCts.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCmacGeneral.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesXcbcMac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesXcbcMac96.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesGmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishKeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishCbc.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishCbcPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesEcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3EcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesEcbEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbcEncryptData.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410KeyPairGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410WithGostr3411.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410KeyWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410Derive.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3411.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3411Hmac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147KeyGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147Ecb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147Mac.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147KeyWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaParameterGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsParameterGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanParameterGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaProbablisticParameterGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaShaweTaylorParameterGenerator.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesOfb.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb64.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb8.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb128.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb1.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyWrap.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyWrapPad.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsTpm11.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsOaepTpm11.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct MechanismList::List
{
	RsaPkcsKeyPairGenerator rsaPkcsKeyPairGenerator;
	RsaPkcs rsaPkcs;
	Rsa9796 rsa9796;
	RsaXdot509 rsaXdot509;
	Md2RsaPkcs md2RsaPkcs;
	Md5RsaPkcs md5RsaPkcs;
	Sha1RsaPkcs sha1RsaPkcs;
	RipeMd128RsaPkcs ripeMd128RsaPkcs;
	RipeMd160RsaPkcs ripeMd160RsaPkcs;
	RsaPkcsOaep rsaPkcsOaep;
	RsaX9dot31KeyPairGenerator rsaX9dot31KeyPairGenerator;
	RsaX9dot31 rsaX9dot31;
	Sha1RsaX9dot31 sha1RsaX9dot31;
	RsaPkcsPss rsaPkcsPss;
	Sha1RsaPkcsPss sha1RsaPkcsPss;
	DsaKeyPairGenerator dsaKeyPairGenerator;
	Dsa dsa;
	DsaSha1 dsaSha1;
	DsaSha224 dsaSha224;
	DsaSha256 dsaSha256;
	DsaSha384 dsaSha384;
	DsaSha512 dsaSha512;
	DiffieHellmanPkcsKeyPairGenerator diffieHellmanPkcsKeyPairGenerator;
	DiffieHellmanPkcsDerive diffieHellmanPkcsDerive;
	X9dot42DiffieHellmanKeyPairGenerator x9dot42DiffieHellmanKeyPairGenerator;
	X9dot42DiffieHellmanDerive x9dot42DiffieHellmanDerive;
	X9dot42DiffieHellmanHybridDerive x9dot42DiffieHellmanHybridDerive;
	X9dot42MqvDerive x9dot42MqvDerive;
	Sha256RsaPkcs sha256RsaPkcs;
	Sha384RsaPkcs sha384RsaPkcs;
	Sha512RsaPkcs sha512RsaPkcs;
	Sha256RsaPkcsPss sha256RsaPkcsPss;
	Sha384RsaPkcsPss sha384RsaPkcsPss;
	Sha512RsaPkcsPss sha512RsaPkcsPss;
	Sha224RsaPkcs sha224RsaPkcs;
	Sha224RsaPkcsPss sha224RsaPkcsPss;
	Sha512dot224 sha512dot224;
	Sha512dot224Hmac sha512dot224Hmac;
	Sha512dot224HmacGeneral sha512dot224HmacGeneral;
	Sha512dot224KeyDerivation sha512dot224KeyDerivation;
	Sha512dot256 sha512dot256;
	Sha512dot256Hmac sha512dot256Hmac;
	Sha512dot256HmacGeneral sha512dot256HmacGeneral;
	Sha512dot256KeyDerivation sha512dot256KeyDerivation;
	Sha512t sha512t;
	Sha512tHmac sha512tHmac;
	Sha512tHmacGeneral sha512tHmacGeneral;
	Sha512tKeyDerivation sha512tKeyDerivation;
	Rc2KeyGenerator rc2KeyGenerator;
	Rc2Ecb rc2Ecb;
	Rc2Cbc rc2Cbc;
	Rc2Mac rc2Mac;
	Rc2MacGeneral rc2MacGeneral;
	Rc2CbcPad rc2CbcPad;
	Rc4KeyGenerator rc4KeyGenerator;
	Rc4 rc4;
	DesKeyGenerator desKeyGenerator;
	DesEcb desEcb;
	DesCbc desCbc;
	DesMac desMac;
	DesMacGeneral desMacGeneral;
	DesCbcPad desCbcPad;
	Des2KeyGenerator des2KeyGenerator;
	Des3KeyGenerator des3KeyGenerator;
	Des3Ecb des3Ecb;
	Des3Cbc des3Cbc;
	Des3Mac des3Mac;
	Des3MacGeneral des3MacGeneral;
	Des3CbcPad des3CbcPad;
	Des3CmacGeneral des3CmacGeneral;
	Des3Cmac des3Cmac;
	CdmfKeyGenerator cdmfKeyGenerator;
	CdmfEcb cdmfEcb;
	CdmfCbc cdmfCbc;
	CdmfMac cdmfMac;
	CdmfMacGeneral cdmfMacGeneral;
	CdmfCbcPad cdmfCbcPad;
	DesOfb64 desOfb64;
	DesOfb8 desOfb8;
	DesCfb64 desCfb64;
	DesCfb8 desCfb8;
	Md2 md2;
	Md2Hmac md2Hmac;
	Md2HmacGeneral md2HmacGeneral;
	Md5 md5;
	Md5Hmac md5Hmac;
	Md5HmacGeneral md5HmacGeneral;
	Sha1 sha1;
	Sha1Hmac sha1Hmac;
	Sha1HmacGeneral sha1HmacGeneral;
	RipeMd128 ripeMd128;
	RipeMd128Hmac ripeMd128Hmac;
	RipeMd128HmacGeneral ripeMd128HmacGeneral;
	RipeMd160 ripeMd160;
	RipeMd160Hmac ripeMd160Hmac;
	RipeMd160HmacGeneral ripeMd160HmacGeneral;
	Sha256 sha256;
	Sha256Hmac sha256Hmac;
	Sha256HmacGeneral sha256HmacGeneral;
	Sha224 sha224;
	Sha224Hmac sha224Hmac;
	Sha224HmacGeneral sha224HmacGeneral;
	Sha384 sha384;
	Sha384Hmac sha384Hmac;
	Sha384HmacGeneral sha384HmacGeneral;
	Sha512 sha512;
	Sha512Hmac sha512Hmac;
	Sha512HmacGeneral sha512HmacGeneral;
	SecurIdKeyGenerator securIdKeyGenerator;
	SecurId securId;
	HotpKeyGenerator hotpKeyGenerator;
	Hotp hotp;
	Acti acti;
	ActiKeyGenerator actiKeyGenerator;
	CastKeyGenerator castKeyGenerator;
	CastEcb castEcb;
	CastCbc castCbc;
	CastMac castMac;
	CastMacGeneral castMacGeneral;
	CastCbcPad castCbcPad;
	Cast3KeyGenerator cast3KeyGenerator;
	Cast3Ecb cast3Ecb;
	Cast3Cbc cast3Cbc;
	Cast3Mac cast3Mac;
	Cast3MacGeneral cast3MacGeneral;
	Cast3CbcPad cast3CbcPad;
//	Cast5KeyGenerator cast5KeyGenerator;
	Cast128KeyGenerator cast128KeyGenerator;
//	Cast5Ecb cast5Ecb;
	Cast128Ecb cast128Ecb;
//	Cast5Cbc cast5Cbc;
	Cast128Cbc cast128Cbc;
//	Cast5Mac cast5Mac;
	Cast128Mac cast128Mac;
//	Cast5MacGeneral cast5MacGeneral;
	Cast128MacGeneral cast128MacGeneral;
//	Cast5CbcPad cast5CbcPad;
	Cast128CbcPad cast128CbcPad;
	Rc5KeyGenerator rc5KeyGenerator;
	Rc5Ecb rc5Ecb;
	Rc5Cbc rc5Cbc;
	Rc5Mac rc5Mac;
	Rc5MacGeneral rc5MacGeneral;
	Rc5CbcPad rc5CbcPad;
	IdeaKeyGenerator ideaKeyGenerator;
	IdeaEcb ideaEcb;
	IdeaCbc ideaCbc;
	IdeaMac ideaMac;
	IdeaMacGeneral ideaMacGeneral;
	IdeaCbcPad ideaCbcPad;
	GenericSecretKeyGenerator genericSecretKeyGenerator;
	ConcatenateBaseAndKey concatenateBaseAndKey;
	ConcatenateBaseAndData concatenateBaseAndData;
	ConcatenateDataAndBase concatenateDataAndBase;
	XorBaseAndData xorBaseAndData;
	ExtractKeyFromKey extractKeyFromKey;
	Ssl3PreMasterKeyGenerator ssl3PreMasterKeyGenerator;
	Ssl3MasterKeyDerive ssl3MasterKeyDerive;
	Ssl3KeyAndMacDerive ssl3KeyAndMacDerive;
	Ssl3MasterKeyDeriveDiffieHellman ssl3MasterKeyDeriveDiffieHellman;
	TlsPreMasterKeyGenerator tlsPreMasterKeyGenerator;
	TlsMasterKeyDerive tlsMasterKeyDerive;
	TlsKeyAndMacDerive tlsKeyAndMacDerive;
	TlsMasterKeyDeriveDiffieHellman tlsMasterKeyDeriveDiffieHellman;
	TlsPrf tlsPrf;
	Ssl3Md5Mac ssl3Md5Mac;
	Ssl3Sha1Mac ssl3Sha1Mac;
	Md5KeyDerivation md5KeyDerivation;
	Md2KeyDerivation md2KeyDerivation;
	Sha1KeyDerivation sha1KeyDerivation;
	Sha256KeyDerivation sha256KeyDerivation;
	Sha384KeyDerivation sha384KeyDerivation;
	Sha512KeyDerivation sha512KeyDerivation;
	Sha224KeyDerivation sha224KeyDerivation;
	PbeMd2DesCbc pbeMd2DesCbc;
	PbeMd5DesCbc pbeMd5DesCbc;
	PbeMd5CastCbc pbeMd5CastCbc;
	PbeMd5Cast3Cbc pbeMd5Cast3Cbc;
//	PbeMd5Cast5Cbc pbeMd5Cast5Cbc;
	PbeMd5Cast128Cbc pbeMd5Cast128Cbc;
//	PbeSha1Cast5Cbc pbeSha1Cast5Cbc;
	PbeSha1Cast128Cbc pbeSha1Cast128Cbc;
	PbeSha1Rc4dot128 pbeSha1Rc4dot128;
	PbeSha1Rc4dot40 pbeSha1Rc4dot40;
	PbeSha1Des3EdeCbc pbeSha1Des3EdeCbc;
	PbeSha1Des2EdeCbc pbeSha1Des2EdeCbc;
	PbeSha1Rc2dot128Cbc pbeSha1Rc2dot128Cbc;
	PbeSha1Rc2dot40Cbc pbeSha1Rc2dot40Cbc;
	Pkcs5Pbkd2 pkcs5Pbkd2;
	PbaSha1WithSha1Hmac pbaSha1WithSha1Hmac;
	WtlsPreMasterKeyGenerator wtlsPreMasterKeyGenerator;
	WtlsMasterKeyDerive wtlsMasterKeyDerive;
	WtlsMasterKeyDeriveDiffieHellmanEcc wtlsMasterKeyDeriveDiffieHellmanEcc;
	WtlsPrf wtlsPrf;
	WtlsServerKeyAndMacDerive wtlsServerKeyAndMacDerive;
	WtlsClientKeyAndMacDerive wtlsClientKeyAndMacDerive;
	Tls10MacServer tls10MacServer;
	Tls10MacClient tls10MacClient;
	Tls12Mac tls12Mac;
	Tls12Kdf tls12Kdf;
	Tls12MasterKeyDerive tls12MasterKeyDerive;
	Tls12KeyAndMacDerive tls12KeyAndMacDerive;
	Tls12MasterKeyDeriveDiffieHellman tls12MasterKeyDeriveDiffieHellman;
	Tls12KeySafeDerive tls12KeySafeDerive;
	TlsMac tlsMac;
	TlsKdf tlsKdf;
	KeyWrapLynks keyWrapLynks;
	KeyWrapSetOaep keyWrapSetOaep;
	CmsSignature cmsSignature;
	KipDerive kipDerive;
	KipWrap kipWrap;
	KipMac kipMac;
	CamelliaKeyGenerator camelliaKeyGenerator;
	CamelliaEcb camelliaEcb;
	CamelliaCbc camelliaCbc;
	CamelliaMac camelliaMac;
	CamelliaMacGeneral camelliaMacGeneral;
	CamelliaCbcPad camelliaCbcPad;
	CamelliaEcbEncryptData camelliaEcbEncryptData;
	CamelliaCbcEncryptData camelliaCbcEncryptData;
	CamelliaCtr camelliaCtr;
	AriaKeyGenerator ariaKeyGenerator;
	AriaEcb ariaEcb;
	AriaCbc ariaCbc;
	AriaMac ariaMac;
	AriaMacGeneral ariaMacGeneral;
	AriaCbcPad ariaCbcPad;
	AriaEcbEncryptData ariaEcbEncryptData;
	AriaCbcEncryptData ariaCbcEncryptData;
	SeedKeyGenerator seedKeyGenerator;
	SeedEcb seedEcb;
	SeedCbc seedCbc;
	SeedMac seedMac;
	SeedMacGeneral seedMacGeneral;
	SeedCbcPad seedCbcPad;
	SeedEcbEncryptData seedEcbEncryptData;
	SeedCbcEncryptData seedCbcEncryptData;
	SkipjackKeyGenerator skipjackKeyGenerator;
	SkipjackEcb64 skipjackEcb64;
	SkipjackCbc64 skipjackCbc64;
	SkipjackOfb64 skipjackOfb64;
	SkipjackCfb64 skipjackCfb64;
	SkipjackCfb32 skipjackCfb32;
	SkipjackCfb16 skipjackCfb16;
	SkipjackCfb8 skipjackCfb8;
	SkipjackWrap skipjackWrap;
	SkipjackPrivateWrap skipjackPrivateWrap;
	SkipjackRelayx skipjackRelayx;
	KeaKeyPairGenerator keaKeyPairGenerator;
	KeaKeyDerive keaKeyDerive;
	KeaDerive keaDerive;
	FortezzaTimestamp fortezzaTimestamp;
	BatonKeyGenerator batonKeyGenerator;
	BatonEcb128 batonEcb128;
	BatonEcb96 batonEcb96;
	BatonCbc128 batonCbc128;
	BatonCounter batonCounter;
	BatonShuffle batonShuffle;
	BatonWrap batonWrap;
//	ElipticCurveDsaKeyPairGenerator elipticCurveDsaKeyPairGenerator;
	ElipticCurveKeyPairGenerator elipticCurveKeyPairGenerator;
	ElipticCurveDsa elipticCurveDsa;
	ElipticCurveDsaSha1 elipticCurveDsaSha1;
	ElipticCurveDsaSha224 elipticCurveDsaSha224;
	ElipticCurveDsaSha256 elipticCurveDsaSha256;
	ElipticCurveDsaSha384 elipticCurveDsaSha384;
	ElipticCurveDsaSha512 elipticCurveDsaSha512;
	ElipticCurveDiffieHellman1Derive elipticCurveDiffieHellman1Derive;
	ElipticCurveDiffieHellman1CofactorDerive elipticCurveDiffieHellman1CofactorDerive;
	ElipticCurveMqvDerive elipticCurveMqvDerive;
	ElipticCurveDiffieHellmanAesKeyWrap elipticCurveDiffieHellmanAesKeyWrap;
	RsaAesKeyWrap rsaAesKeyWrap;
	JuniperKeyGenerator juniperKeyGenerator;
	JuniperEcb128 juniperEcb128;
	JuniperCbc128 juniperCbc128;
	JuniperCounter juniperCounter;
	JuniperShuffle juniperShuffle;
	JuniperWrap juniperWrap;
	Fasthash fasthash;
	AesKeyGenerator aesKeyGenerator;
	AesEcb aesEcb;
	AesCbc aesCbc;
	AesMac aesMac;
	AesMacGeneral aesMacGeneral;
	AesCbcPad aesCbcPad;
	AesCtr aesCtr;
	AesGcm aesGcm;
	AesCcm aesCcm;
	AesCts aesCts;
	AesCmac aesCmac;
	AesCmacGeneral aesCmacGeneral;
	AesXcbcMac aesXcbcMac;
	AesXcbcMac96 aesXcbcMac96;
	AesGmac aesGmac;
	BlowfishKeyGenerator blowfishKeyGenerator;
	BlowfishCbc blowfishCbc;
	TwofishKeyGenerator twofishKeyGenerator;
	TwofishCbc twofishCbc;
	BlowfishCbcPad blowfishCbcPad;
	TwofishCbcPad twofishCbcPad;
	DesEcbEncryptData desEcbEncryptData;
	DesCbcEncryptData desCbcEncryptData;
	Des3EcbEncryptData des3EcbEncryptData;
	Des3CbcEncryptData des3CbcEncryptData;
	AesEcbEncryptData aesEcbEncryptData;
	AesCbcEncryptData aesCbcEncryptData;
	Gostr3410KeyPairGenerator gostr3410KeyPairGenerator;
	Gostr3410 gostr3410;
	Gostr3410WithGostr3411 gostr3410WithGostr3411;
	Gostr3410KeyWrap gostr3410KeyWrap;
	Gostr3410Derive gostr3410Derive;
	Gostr3411 gostr3411;
	Gostr3411Hmac gostr3411Hmac;
	Gost28147KeyGenerator gost28147KeyGenerator;
	Gost28147Ecb gost28147Ecb;
	Gost28147 gost28147;
	Gost28147Mac gost28147Mac;
	Gost28147KeyWrap gost28147KeyWrap;
	DsaParameterGenerator dsaParameterGenerator;
	DiffieHellmanPkcsParameterGenerator diffieHellmanPkcsParameterGenerator;
	X9dot42DiffieHellmanParameterGenerator x9dot42DiffieHellmanParameterGenerator;
	DsaProbablisticParameterGenerator dsaProbablisticParameterGenerator;
	DsaShaweTaylorParameterGenerator dsaShaweTaylorParameterGenerator;
	AesOfb aesOfb;
	AesCfb64 aesCfb64;
	AesCfb8 aesCfb8;
	AesCfb128 aesCfb128;
	AesCfb1 aesCfb1;
	AesKeyWrap aesKeyWrap;
	AesKeyWrapPad aesKeyWrapPad;
	RsaPkcsTpm11 rsaPkcsTpm11;
	RsaPkcsOaepTpm11 rsaPkcsOaepTpm11;

	MechanismBase *operator()(pkcs11::enums::Mechanism type)
	{
		switch (type)
		{
			case pkcs11::enums::Mechanism::RSA_PKCS_KEY_PAIR_GEN:
				return &rsaPkcsKeyPairGenerator;

			case pkcs11::enums::Mechanism::RSA_PKCS:
				return &rsaPkcs;

			case pkcs11::enums::Mechanism::RSA_9796:
				return &rsa9796;

			case pkcs11::enums::Mechanism::RSA_X_509:
				return &rsaXdot509;

			case pkcs11::enums::Mechanism::MD2_RSA_PKCS:
				return &md2RsaPkcs;

			case pkcs11::enums::Mechanism::MD5_RSA_PKCS:
				return &md5RsaPkcs;

			case pkcs11::enums::Mechanism::SHA1_RSA_PKCS:
				return &sha1RsaPkcs;

			case pkcs11::enums::Mechanism::RIPEMD128_RSA_PKCS:
				return &ripeMd128RsaPkcs;

			case pkcs11::enums::Mechanism::RIPEMD160_RSA_PKCS:
				return &ripeMd160RsaPkcs;

			case pkcs11::enums::Mechanism::RSA_PKCS_OAEP:
				return &rsaPkcsOaep;

			case pkcs11::enums::Mechanism::RSA_X9_31_KEY_PAIR_GEN:
				return &rsaX9dot31KeyPairGenerator;

			case pkcs11::enums::Mechanism::RSA_X9_31:
				return &rsaX9dot31;

			case pkcs11::enums::Mechanism::SHA1_RSA_X9_31:
				return &sha1RsaX9dot31;

			case pkcs11::enums::Mechanism::RSA_PKCS_PSS:
				return &rsaPkcsPss;

			case pkcs11::enums::Mechanism::SHA1_RSA_PKCS_PSS:
				return &sha1RsaPkcsPss;

			case pkcs11::enums::Mechanism::DSA_KEY_PAIR_GEN:
				return &dsaKeyPairGenerator;

			case pkcs11::enums::Mechanism::DSA:
				return &dsa;

			case pkcs11::enums::Mechanism::DSA_SHA1:
				return &dsaSha1;

			case pkcs11::enums::Mechanism::DSA_SHA224:
				return &dsaSha224;

			case pkcs11::enums::Mechanism::DSA_SHA256:
				return &dsaSha256;

			case pkcs11::enums::Mechanism::DSA_SHA384:
				return &dsaSha384;

			case pkcs11::enums::Mechanism::DSA_SHA512:
				return &dsaSha512;

			case pkcs11::enums::Mechanism::DH_PKCS_KEY_PAIR_GEN:
				return &diffieHellmanPkcsKeyPairGenerator;

			case pkcs11::enums::Mechanism::DH_PKCS_DERIVE:
				return &diffieHellmanPkcsDerive;

			case pkcs11::enums::Mechanism::X9_42_DH_KEY_PAIR_GEN:
				return &x9dot42DiffieHellmanKeyPairGenerator;

			case pkcs11::enums::Mechanism::X9_42_DH_DERIVE:
				return &x9dot42DiffieHellmanDerive;

			case pkcs11::enums::Mechanism::X9_42_DH_HYBRID_DERIVE:
				return &x9dot42DiffieHellmanHybridDerive;

			case pkcs11::enums::Mechanism::X9_42_MQV_DERIVE:
				return &x9dot42MqvDerive;

			case pkcs11::enums::Mechanism::SHA256_RSA_PKCS:
				return &sha256RsaPkcs;

			case pkcs11::enums::Mechanism::SHA384_RSA_PKCS:
				return &sha384RsaPkcs;

			case pkcs11::enums::Mechanism::SHA512_RSA_PKCS:
				return &sha512RsaPkcs;

			case pkcs11::enums::Mechanism::SHA256_RSA_PKCS_PSS:
				return &sha256RsaPkcsPss;

			case pkcs11::enums::Mechanism::SHA384_RSA_PKCS_PSS:
				return &sha384RsaPkcsPss;

			case pkcs11::enums::Mechanism::SHA512_RSA_PKCS_PSS:
				return &sha512RsaPkcsPss;

			case pkcs11::enums::Mechanism::SHA224_RSA_PKCS:
				return &sha224RsaPkcs;

			case pkcs11::enums::Mechanism::SHA224_RSA_PKCS_PSS:
				return &sha224RsaPkcsPss;

			case pkcs11::enums::Mechanism::SHA512_224:
				return &sha512dot224;

			case pkcs11::enums::Mechanism::SHA512_224_HMAC:
				return &sha512dot224Hmac;

			case pkcs11::enums::Mechanism::SHA512_224_HMAC_GENERAL:
				return &sha512dot224HmacGeneral;

			case pkcs11::enums::Mechanism::SHA512_224_KEY_DERIVATION:
				return &sha512dot224KeyDerivation;

			case pkcs11::enums::Mechanism::SHA512_256:
				return &sha512dot256;

			case pkcs11::enums::Mechanism::SHA512_256_HMAC:
				return &sha512dot256Hmac;

			case pkcs11::enums::Mechanism::SHA512_256_HMAC_GENERAL:
				return &sha512dot256HmacGeneral;

			case pkcs11::enums::Mechanism::SHA512_256_KEY_DERIVATION:
				return &sha512dot256KeyDerivation;

			case pkcs11::enums::Mechanism::SHA512_T:
				return &sha512t;

			case pkcs11::enums::Mechanism::SHA512_T_HMAC:
				return &sha512tHmac;

			case pkcs11::enums::Mechanism::SHA512_T_HMAC_GENERAL:
				return &sha512tHmacGeneral;

			case pkcs11::enums::Mechanism::SHA512_T_KEY_DERIVATION:
				return &sha512tKeyDerivation;

			case pkcs11::enums::Mechanism::RC2_KEY_GEN:
				return &rc2KeyGenerator;

			case pkcs11::enums::Mechanism::RC2_ECB:
				return &rc2Ecb;

			case pkcs11::enums::Mechanism::RC2_CBC:
				return &rc2Cbc;

			case pkcs11::enums::Mechanism::RC2_MAC:
				return &rc2Mac;

			case pkcs11::enums::Mechanism::RC2_MAC_GENERAL:
				return &rc2MacGeneral;

			case pkcs11::enums::Mechanism::RC2_CBC_PAD:
				return &rc2CbcPad;

			case pkcs11::enums::Mechanism::RC4_KEY_GEN:
				return &rc4KeyGenerator;

			case pkcs11::enums::Mechanism::RC4:
				return &rc4;

			case pkcs11::enums::Mechanism::DES_KEY_GEN:
				return &desKeyGenerator;

			case pkcs11::enums::Mechanism::DES_ECB:
				return &desEcb;

			case pkcs11::enums::Mechanism::DES_CBC:
				return &desCbc;

			case pkcs11::enums::Mechanism::DES_MAC:
				return &desMac;

			case pkcs11::enums::Mechanism::DES_MAC_GENERAL:
				return &desMacGeneral;

			case pkcs11::enums::Mechanism::DES_CBC_PAD:
				return &desCbcPad;

			case pkcs11::enums::Mechanism::DES2_KEY_GEN:
				return &des2KeyGenerator;

			case pkcs11::enums::Mechanism::DES3_KEY_GEN:
				return &des3KeyGenerator;

			case pkcs11::enums::Mechanism::DES3_ECB:
				return &des3Ecb;

			case pkcs11::enums::Mechanism::DES3_CBC:
				return &des3Cbc;

			case pkcs11::enums::Mechanism::DES3_MAC:
				return &des3Mac;

			case pkcs11::enums::Mechanism::DES3_MAC_GENERAL:
				return &des3MacGeneral;

			case pkcs11::enums::Mechanism::DES3_CBC_PAD:
				return &des3CbcPad;

			case pkcs11::enums::Mechanism::DES3_CMAC_GENERAL:
				return &des3CmacGeneral;

			case pkcs11::enums::Mechanism::DES3_CMAC:
				return &des3Cmac;

			case pkcs11::enums::Mechanism::CDMF_KEY_GEN:
				return &cdmfKeyGenerator;

			case pkcs11::enums::Mechanism::CDMF_ECB:
				return &cdmfEcb;

			case pkcs11::enums::Mechanism::CDMF_CBC:
				return &cdmfCbc;

			case pkcs11::enums::Mechanism::CDMF_MAC:
				return &cdmfMac;

			case pkcs11::enums::Mechanism::CDMF_MAC_GENERAL:
				return &cdmfMacGeneral;

			case pkcs11::enums::Mechanism::CDMF_CBC_PAD:
				return &cdmfCbcPad;

			case pkcs11::enums::Mechanism::DES_OFB64:
				return &desOfb64;

			case pkcs11::enums::Mechanism::DES_OFB8:
				return &desOfb8;

			case pkcs11::enums::Mechanism::DES_CFB64:
				return &desCfb64;

			case pkcs11::enums::Mechanism::DES_CFB8:
				return &desCfb8;

			case pkcs11::enums::Mechanism::MD2:
				return &md2;

			case pkcs11::enums::Mechanism::MD2_HMAC:
				return &md2Hmac;

			case pkcs11::enums::Mechanism::MD2_HMAC_GENERAL:
				return &md2HmacGeneral;

			case pkcs11::enums::Mechanism::MD5:
				return &md5;

			case pkcs11::enums::Mechanism::MD5_HMAC:
				return &md5Hmac;

			case pkcs11::enums::Mechanism::MD5_HMAC_GENERAL:
				return &md5HmacGeneral;

			case pkcs11::enums::Mechanism::SHA_1:
				return &sha1;

			case pkcs11::enums::Mechanism::SHA_1_HMAC:
				return &sha1Hmac;

			case pkcs11::enums::Mechanism::SHA_1_HMAC_GENERAL:
				return &sha1HmacGeneral;

			case pkcs11::enums::Mechanism::RIPEMD128:
				return &ripeMd128;

			case pkcs11::enums::Mechanism::RIPEMD128_HMAC:
				return &ripeMd128Hmac;

			case pkcs11::enums::Mechanism::RIPEMD128_HMAC_GENERAL:
				return &ripeMd128HmacGeneral;

			case pkcs11::enums::Mechanism::RIPEMD160:
				return &ripeMd160;

			case pkcs11::enums::Mechanism::RIPEMD160_HMAC:
				return &ripeMd160Hmac;

			case pkcs11::enums::Mechanism::RIPEMD160_HMAC_GENERAL:
				return &ripeMd160HmacGeneral;

			case pkcs11::enums::Mechanism::SHA256:
				return &sha256;

			case pkcs11::enums::Mechanism::SHA256_HMAC:
				return &sha256Hmac;

			case pkcs11::enums::Mechanism::SHA256_HMAC_GENERAL:
				return &sha256HmacGeneral;

			case pkcs11::enums::Mechanism::SHA224:
				return &sha224;

			case pkcs11::enums::Mechanism::SHA224_HMAC:
				return &sha224Hmac;

			case pkcs11::enums::Mechanism::SHA224_HMAC_GENERAL:
				return &sha224HmacGeneral;

			case pkcs11::enums::Mechanism::SHA384:
				return &sha384;

			case pkcs11::enums::Mechanism::SHA384_HMAC:
				return &sha384Hmac;

			case pkcs11::enums::Mechanism::SHA384_HMAC_GENERAL:
				return &sha384HmacGeneral;

			case pkcs11::enums::Mechanism::SHA512:
				return &sha512;

			case pkcs11::enums::Mechanism::SHA512_HMAC:
				return &sha512Hmac;

			case pkcs11::enums::Mechanism::SHA512_HMAC_GENERAL:
				return &sha512HmacGeneral;

			case pkcs11::enums::Mechanism::SECURID_KEY_GEN:
				return &securIdKeyGenerator;

			case pkcs11::enums::Mechanism::SECURID:
				return &securId;

			case pkcs11::enums::Mechanism::HOTP_KEY_GEN:
				return &hotpKeyGenerator;

			case pkcs11::enums::Mechanism::HOTP:
				return &hotp;

			case pkcs11::enums::Mechanism::ACTI:
				return &acti;

			case pkcs11::enums::Mechanism::ACTI_KEY_GEN:
				return &actiKeyGenerator;

			case pkcs11::enums::Mechanism::CAST_KEY_GEN:
				return &castKeyGenerator;

			case pkcs11::enums::Mechanism::CAST_ECB:
				return &castEcb;

			case pkcs11::enums::Mechanism::CAST_CBC:
				return &castCbc;

			case pkcs11::enums::Mechanism::CAST_MAC:
				return &castMac;

			case pkcs11::enums::Mechanism::CAST_MAC_GENERAL:
				return &castMacGeneral;

			case pkcs11::enums::Mechanism::CAST_CBC_PAD:
				return &castCbcPad;

			case pkcs11::enums::Mechanism::CAST3_KEY_GEN:
				return &cast3KeyGenerator;

			case pkcs11::enums::Mechanism::CAST3_ECB:
				return &cast3Ecb;

			case pkcs11::enums::Mechanism::CAST3_CBC:
				return &cast3Cbc;

			case pkcs11::enums::Mechanism::CAST3_MAC:
				return &cast3Mac;

			case pkcs11::enums::Mechanism::CAST3_MAC_GENERAL:
				return &cast3MacGeneral;

			case pkcs11::enums::Mechanism::CAST3_CBC_PAD:
				return &cast3CbcPad;

//			case pkcs11::enums::Mechanism::CAST5_KEY_GEN:
			case pkcs11::enums::Mechanism::CAST128_KEY_GEN:
//				return &cast5KeyGenerator;
				return &cast128KeyGenerator;


//			case pkcs11::enums::Mechanism::CAST5_ECB:
			case pkcs11::enums::Mechanism::CAST128_ECB:
//				return &cast5Ecb;
				return &cast128Ecb;

//			case pkcs11::enums::Mechanism::CAST5_CBC:
			case pkcs11::enums::Mechanism::CAST128_CBC:
//				return &cast5Cbc;
				return &cast128Cbc;

//			case pkcs11::enums::Mechanism::CAST5_MAC:
			case pkcs11::enums::Mechanism::CAST128_MAC:
//				return &cast5Mac;
				return &cast128Mac;

//			case pkcs11::enums::Mechanism::CAST5_MAC_GENERAL:
			case pkcs11::enums::Mechanism::CAST128_MAC_GENERAL:
//				return &cast5MacGeneral;
				return &cast128MacGeneral;

//			case pkcs11::enums::Mechanism::CAST5_CBC_PAD:
			case pkcs11::enums::Mechanism::CAST128_CBC_PAD:
//				return &cast5CbcPad;
				return &cast128CbcPad;

			case pkcs11::enums::Mechanism::RC5_KEY_GEN:
				return &rc5KeyGenerator;

			case pkcs11::enums::Mechanism::RC5_ECB:
				return &rc5Ecb;

			case pkcs11::enums::Mechanism::RC5_CBC:
				return &rc5Cbc;

			case pkcs11::enums::Mechanism::RC5_MAC:
				return &rc5Mac;

			case pkcs11::enums::Mechanism::RC5_MAC_GENERAL:
				return &rc5MacGeneral;

			case pkcs11::enums::Mechanism::RC5_CBC_PAD:
				return &rc5CbcPad;

			case pkcs11::enums::Mechanism::IDEA_KEY_GEN:
				return &ideaKeyGenerator;

			case pkcs11::enums::Mechanism::IDEA_ECB:
				return &ideaEcb;

			case pkcs11::enums::Mechanism::IDEA_CBC:
				return &ideaCbc;

			case pkcs11::enums::Mechanism::IDEA_MAC:
				return &ideaMac;

			case pkcs11::enums::Mechanism::IDEA_MAC_GENERAL:
				return &ideaMacGeneral;

			case pkcs11::enums::Mechanism::IDEA_CBC_PAD:
				return &ideaCbcPad;

			case pkcs11::enums::Mechanism::GENERIC_SECRET_KEY_GEN:
				return &genericSecretKeyGenerator;

			case pkcs11::enums::Mechanism::CONCATENATE_BASE_AND_KEY:
				return &concatenateBaseAndKey;

			case pkcs11::enums::Mechanism::CONCATENATE_BASE_AND_DATA:
				return &concatenateBaseAndData;

			case pkcs11::enums::Mechanism::CONCATENATE_DATA_AND_BASE:
				return &concatenateDataAndBase;

			case pkcs11::enums::Mechanism::XOR_BASE_AND_DATA:
				return &xorBaseAndData;

			case pkcs11::enums::Mechanism::EXTRACT_KEY_FROM_KEY:
				return &extractKeyFromKey;

			case pkcs11::enums::Mechanism::SSL3_PRE_MASTER_KEY_GEN:
				return &ssl3PreMasterKeyGenerator;

			case pkcs11::enums::Mechanism::SSL3_MASTER_KEY_DERIVE:
				return &ssl3MasterKeyDerive;

			case pkcs11::enums::Mechanism::SSL3_KEY_AND_MAC_DERIVE:
				return &ssl3KeyAndMacDerive;

			case pkcs11::enums::Mechanism::SSL3_MASTER_KEY_DERIVE_DH:
				return &ssl3MasterKeyDeriveDiffieHellman;

			case pkcs11::enums::Mechanism::TLS_PRE_MASTER_KEY_GEN:
				return &tlsPreMasterKeyGenerator;

			case pkcs11::enums::Mechanism::TLS_MASTER_KEY_DERIVE:
				return &tlsMasterKeyDerive;

			case pkcs11::enums::Mechanism::TLS_KEY_AND_MAC_DERIVE:
				return &tlsKeyAndMacDerive;

			case pkcs11::enums::Mechanism::TLS_MASTER_KEY_DERIVE_DH:
				return &tlsMasterKeyDeriveDiffieHellman;

			case pkcs11::enums::Mechanism::TLS_PRF:
				return &tlsPrf;

			case pkcs11::enums::Mechanism::SSL3_MD5_MAC:
				return &ssl3Md5Mac;

			case pkcs11::enums::Mechanism::SSL3_SHA1_MAC:
				return &ssl3Sha1Mac;

			case pkcs11::enums::Mechanism::MD5_KEY_DERIVATION:
				return &md5KeyDerivation;

			case pkcs11::enums::Mechanism::MD2_KEY_DERIVATION:
				return &md2KeyDerivation;

			case pkcs11::enums::Mechanism::SHA1_KEY_DERIVATION:
				return &sha1KeyDerivation;

			case pkcs11::enums::Mechanism::SHA256_KEY_DERIVATION:
				return &sha256KeyDerivation;

			case pkcs11::enums::Mechanism::SHA384_KEY_DERIVATION:
				return &sha384KeyDerivation;

			case pkcs11::enums::Mechanism::SHA512_KEY_DERIVATION:
				return &sha512KeyDerivation;

			case pkcs11::enums::Mechanism::SHA224_KEY_DERIVATION:
				return &sha224KeyDerivation;

			case pkcs11::enums::Mechanism::PBE_MD2_DES_CBC:
				return &pbeMd2DesCbc;

			case pkcs11::enums::Mechanism::PBE_MD5_DES_CBC:
				return &pbeMd5DesCbc;

			case pkcs11::enums::Mechanism::PBE_MD5_CAST_CBC:
				return &pbeMd5CastCbc;

			case pkcs11::enums::Mechanism::PBE_MD5_CAST3_CBC:
				return &pbeMd5Cast3Cbc;

//			case pkcs11::enums::Mechanism::PBE_MD5_CAST5_CBC:
			case pkcs11::enums::Mechanism::PBE_MD5_CAST128_CBC:
//				return &pbeMd5Cast5Cbc;
				return &pbeMd5Cast128Cbc;

//			case pkcs11::enums::Mechanism::PBE_SHA1_CAST5_CBC:
			case pkcs11::enums::Mechanism::PBE_SHA1_CAST128_CBC:
//				return &pbeSha1Cast5Cbc;
				return &pbeSha1Cast128Cbc;

			case pkcs11::enums::Mechanism::PBE_SHA1_RC4_128:
				return &pbeSha1Rc4dot128;

			case pkcs11::enums::Mechanism::PBE_SHA1_RC4_40:
				return &pbeSha1Rc4dot40;

			case pkcs11::enums::Mechanism::PBE_SHA1_DES3_EDE_CBC:
				return &pbeSha1Des3EdeCbc;

			case pkcs11::enums::Mechanism::PBE_SHA1_DES2_EDE_CBC:
				return &pbeSha1Des2EdeCbc;

			case pkcs11::enums::Mechanism::PBE_SHA1_RC2_128_CBC:
				return &pbeSha1Rc2dot128Cbc;

			case pkcs11::enums::Mechanism::PBE_SHA1_RC2_40_CBC:
				return &pbeSha1Rc2dot40Cbc;

			case pkcs11::enums::Mechanism::PKCS5_PBKD2:
				return &pkcs5Pbkd2;

			case pkcs11::enums::Mechanism::PBA_SHA1_WITH_SHA1_HMAC:
				return &pbaSha1WithSha1Hmac;

			case pkcs11::enums::Mechanism::WTLS_PRE_MASTER_KEY_GEN:
				return &wtlsPreMasterKeyGenerator;

			case pkcs11::enums::Mechanism::WTLS_MASTER_KEY_DERIVE:
				return &wtlsMasterKeyDerive;

			case pkcs11::enums::Mechanism::WTLS_MASTER_KEY_DERIVE_DH_ECC:
				return &wtlsMasterKeyDeriveDiffieHellmanEcc;

			case pkcs11::enums::Mechanism::WTLS_PRF:
				return &wtlsPrf;

			case pkcs11::enums::Mechanism::WTLS_SERVER_KEY_AND_MAC_DERIVE:
				return &wtlsServerKeyAndMacDerive;

			case pkcs11::enums::Mechanism::WTLS_CLIENT_KEY_AND_MAC_DERIVE:
				return &wtlsClientKeyAndMacDerive;

			case pkcs11::enums::Mechanism::TLS10_MAC_SERVER:
				return &tls10MacServer;

			case pkcs11::enums::Mechanism::TLS10_MAC_CLIENT:
				return &tls10MacClient;

			case pkcs11::enums::Mechanism::TLS12_MAC:
				return &tls12Mac;

			case pkcs11::enums::Mechanism::TLS12_KDF:
				return &tls12Kdf;

			case pkcs11::enums::Mechanism::TLS12_MASTER_KEY_DERIVE:
				return &tls12MasterKeyDerive;

			case pkcs11::enums::Mechanism::TLS12_KEY_AND_MAC_DERIVE:
				return &tls12KeyAndMacDerive;

			case pkcs11::enums::Mechanism::TLS12_MASTER_KEY_DERIVE_DH:
				return &tls12MasterKeyDeriveDiffieHellman;

			case pkcs11::enums::Mechanism::TLS12_KEY_SAFE_DERIVE:
				return &tls12KeySafeDerive;

			case pkcs11::enums::Mechanism::TLS_MAC:
				return &tlsMac;

			case pkcs11::enums::Mechanism::TLS_KDF:
				return &tlsKdf;

			case pkcs11::enums::Mechanism::KEY_WRAP_LYNKS:
				return &keyWrapLynks;

			case pkcs11::enums::Mechanism::KEY_WRAP_SET_OAEP:
				return &keyWrapSetOaep;

			case pkcs11::enums::Mechanism::CMS_SIG:
				return &cmsSignature;

			case pkcs11::enums::Mechanism::KIP_DERIVE:
				return &kipDerive;

			case pkcs11::enums::Mechanism::KIP_WRAP:
				return &kipWrap;

			case pkcs11::enums::Mechanism::KIP_MAC:
				return &kipMac;

			case pkcs11::enums::Mechanism::CAMELLIA_KEY_GEN:
				return &camelliaKeyGenerator;

			case pkcs11::enums::Mechanism::CAMELLIA_ECB:
				return &camelliaEcb;

			case pkcs11::enums::Mechanism::CAMELLIA_CBC:
				return &camelliaCbc;

			case pkcs11::enums::Mechanism::CAMELLIA_MAC:
				return &camelliaMac;

			case pkcs11::enums::Mechanism::CAMELLIA_MAC_GENERAL:
				return &camelliaMacGeneral;

			case pkcs11::enums::Mechanism::CAMELLIA_CBC_PAD:
				return &camelliaCbcPad;

			case pkcs11::enums::Mechanism::CAMELLIA_ECB_ENCRYPT_DATA:
				return &camelliaEcbEncryptData;

			case pkcs11::enums::Mechanism::CAMELLIA_CBC_ENCRYPT_DATA:
				return &camelliaCbcEncryptData;

			case pkcs11::enums::Mechanism::CAMELLIA_CTR:
				return &camelliaCtr;

			case pkcs11::enums::Mechanism::ARIA_KEY_GEN:
				return &ariaKeyGenerator;

			case pkcs11::enums::Mechanism::ARIA_ECB:
				return &ariaEcb;

			case pkcs11::enums::Mechanism::ARIA_CBC:
				return &ariaCbc;

			case pkcs11::enums::Mechanism::ARIA_MAC:
				return &ariaMac;

			case pkcs11::enums::Mechanism::ARIA_MAC_GENERAL:
				return &ariaMacGeneral;

			case pkcs11::enums::Mechanism::ARIA_CBC_PAD:
				return &ariaCbcPad;

			case pkcs11::enums::Mechanism::ARIA_ECB_ENCRYPT_DATA:
				return &ariaEcbEncryptData;

			case pkcs11::enums::Mechanism::ARIA_CBC_ENCRYPT_DATA:
				return &ariaCbcEncryptData;

			case pkcs11::enums::Mechanism::SEED_KEY_GEN:
				return &seedKeyGenerator;

			case pkcs11::enums::Mechanism::SEED_ECB:
				return &seedEcb;

			case pkcs11::enums::Mechanism::SEED_CBC:
				return &seedCbc;

			case pkcs11::enums::Mechanism::SEED_MAC:
				return &seedMac;

			case pkcs11::enums::Mechanism::SEED_MAC_GENERAL:
				return &seedMacGeneral;

			case pkcs11::enums::Mechanism::SEED_CBC_PAD:
				return &seedCbcPad;

			case pkcs11::enums::Mechanism::SEED_ECB_ENCRYPT_DATA:
				return &seedEcbEncryptData;

			case pkcs11::enums::Mechanism::SEED_CBC_ENCRYPT_DATA:
				return &seedCbcEncryptData;

			case pkcs11::enums::Mechanism::SKIPJACK_KEY_GEN:
				return &skipjackKeyGenerator;

			case pkcs11::enums::Mechanism::SKIPJACK_ECB64:
				return &skipjackEcb64;

			case pkcs11::enums::Mechanism::SKIPJACK_CBC64:
				return &skipjackCbc64;

			case pkcs11::enums::Mechanism::SKIPJACK_OFB64:
				return &skipjackOfb64;

			case pkcs11::enums::Mechanism::SKIPJACK_CFB64:
				return &skipjackCfb64;

			case pkcs11::enums::Mechanism::SKIPJACK_CFB32:
				return &skipjackCfb32;

			case pkcs11::enums::Mechanism::SKIPJACK_CFB16:
				return &skipjackCfb16;

			case pkcs11::enums::Mechanism::SKIPJACK_CFB8:
				return &skipjackCfb8;

			case pkcs11::enums::Mechanism::SKIPJACK_WRAP:
				return &skipjackWrap;

			case pkcs11::enums::Mechanism::SKIPJACK_PRIVATE_WRAP:
				return &skipjackPrivateWrap;

			case pkcs11::enums::Mechanism::SKIPJACK_RELAYX:
				return &skipjackRelayx;

			case pkcs11::enums::Mechanism::KEA_KEY_PAIR_GEN:
				return &keaKeyPairGenerator;

			case pkcs11::enums::Mechanism::KEA_KEY_DERIVE:
				return &keaKeyDerive;

			case pkcs11::enums::Mechanism::KEA_DERIVE:
				return &keaDerive;

			case pkcs11::enums::Mechanism::FORTEZZA_TIMESTAMP:
				return &fortezzaTimestamp;

			case pkcs11::enums::Mechanism::BATON_KEY_GEN:
				return &batonKeyGenerator;

			case pkcs11::enums::Mechanism::BATON_ECB128:
				return &batonEcb128;

			case pkcs11::enums::Mechanism::BATON_ECB96:
				return &batonEcb96;

			case pkcs11::enums::Mechanism::BATON_CBC128:
				return &batonCbc128;

			case pkcs11::enums::Mechanism::BATON_COUNTER:
				return &batonCounter;

			case pkcs11::enums::Mechanism::BATON_SHUFFLE:
				return &batonShuffle;

			case pkcs11::enums::Mechanism::BATON_WRAP:
				return &batonWrap;

			case pkcs11::enums::Mechanism::EC_KEY_PAIR_GEN:
//			case pkcs11::enums::Mechanism::ECDSA_KEY_PAIR_GEN:
				return &elipticCurveKeyPairGenerator;
//				return &elipticCurveDsaKeyPairGenerator;

			case pkcs11::enums::Mechanism::ECDSA:
				return &elipticCurveDsa;

			case pkcs11::enums::Mechanism::ECDSA_SHA1:
				return &elipticCurveDsaSha1;

			case pkcs11::enums::Mechanism::ECDSA_SHA224:
				return &elipticCurveDsaSha224;

			case pkcs11::enums::Mechanism::ECDSA_SHA256:
				return &elipticCurveDsaSha256;

			case pkcs11::enums::Mechanism::ECDSA_SHA384:
				return &elipticCurveDsaSha384;

			case pkcs11::enums::Mechanism::ECDSA_SHA512:
				return &elipticCurveDsaSha512;

			case pkcs11::enums::Mechanism::ECDH1_DERIVE:
				return &elipticCurveDiffieHellman1Derive;

			case pkcs11::enums::Mechanism::ECDH1_COFACTOR_DERIVE:
				return &elipticCurveDiffieHellman1CofactorDerive;

			case pkcs11::enums::Mechanism::ECMQV_DERIVE:
				return &elipticCurveMqvDerive;

			case pkcs11::enums::Mechanism::ECDH_AES_KEY_WRAP:
				return &elipticCurveDiffieHellmanAesKeyWrap;

			case pkcs11::enums::Mechanism::RSA_AES_KEY_WRAP:
				return &rsaAesKeyWrap;

			case pkcs11::enums::Mechanism::JUNIPER_KEY_GEN:
				return &juniperKeyGenerator;

			case pkcs11::enums::Mechanism::JUNIPER_ECB128:
				return &juniperEcb128;

			case pkcs11::enums::Mechanism::JUNIPER_CBC128:
				return &juniperCbc128;

			case pkcs11::enums::Mechanism::JUNIPER_COUNTER:
				return &juniperCounter;

			case pkcs11::enums::Mechanism::JUNIPER_SHUFFLE:
				return &juniperShuffle;

			case pkcs11::enums::Mechanism::JUNIPER_WRAP:
				return &juniperWrap;

			case pkcs11::enums::Mechanism::FASTHASH:
				return &fasthash;

			case pkcs11::enums::Mechanism::AES_KEY_GEN:
				return &aesKeyGenerator;

			case pkcs11::enums::Mechanism::AES_ECB:
				return &aesEcb;

			case pkcs11::enums::Mechanism::AES_CBC:
				return &aesCbc;

			case pkcs11::enums::Mechanism::AES_MAC:
				return &aesMac;

			case pkcs11::enums::Mechanism::AES_MAC_GENERAL:
				return &aesMacGeneral;

			case pkcs11::enums::Mechanism::AES_CBC_PAD:
				return &aesCbcPad;

			case pkcs11::enums::Mechanism::AES_CTR:
				return &aesCtr;

			case pkcs11::enums::Mechanism::AES_GCM:
				return &aesGcm;

			case pkcs11::enums::Mechanism::AES_CCM:
				return &aesCcm;

			case pkcs11::enums::Mechanism::AES_CTS:
				return &aesCts;

			case pkcs11::enums::Mechanism::AES_CMAC:
				return &aesCmac;

			case pkcs11::enums::Mechanism::AES_CMAC_GENERAL:
				return &aesCmacGeneral;

			case pkcs11::enums::Mechanism::AES_XCBC_MAC:
				return &aesXcbcMac;

			case pkcs11::enums::Mechanism::AES_XCBC_MAC_96:
				return &aesXcbcMac96;

			case pkcs11::enums::Mechanism::AES_GMAC:
				return &aesGmac;

			case pkcs11::enums::Mechanism::BLOWFISH_KEY_GEN:
				return &blowfishKeyGenerator;

			case pkcs11::enums::Mechanism::BLOWFISH_CBC:
				return &blowfishCbc;

			case pkcs11::enums::Mechanism::TWOFISH_KEY_GEN:
				return &twofishKeyGenerator;

			case pkcs11::enums::Mechanism::TWOFISH_CBC:
				return &twofishCbc;

			case pkcs11::enums::Mechanism::BLOWFISH_CBC_PAD:
				return &blowfishCbcPad;

			case pkcs11::enums::Mechanism::TWOFISH_CBC_PAD:
				return &twofishCbcPad;

			case pkcs11::enums::Mechanism::DES_ECB_ENCRYPT_DATA:
				return &desEcbEncryptData;

			case pkcs11::enums::Mechanism::DES_CBC_ENCRYPT_DATA:
				return &desCbcEncryptData;

			case pkcs11::enums::Mechanism::DES3_ECB_ENCRYPT_DATA:
				return &des3EcbEncryptData;

			case pkcs11::enums::Mechanism::DES3_CBC_ENCRYPT_DATA:
				return &des3CbcEncryptData;

			case pkcs11::enums::Mechanism::AES_ECB_ENCRYPT_DATA:
				return &aesEcbEncryptData;

			case pkcs11::enums::Mechanism::AES_CBC_ENCRYPT_DATA:
				return &aesCbcEncryptData;

			case pkcs11::enums::Mechanism::GOSTR3410_KEY_PAIR_GEN:
				return &gostr3410KeyPairGenerator;

			case pkcs11::enums::Mechanism::GOSTR3410:
				return &gostr3410;

			case pkcs11::enums::Mechanism::GOSTR3410_WITH_GOSTR3411:
				return &gostr3410WithGostr3411;

			case pkcs11::enums::Mechanism::GOSTR3410_KEY_WRAP:
				return &gostr3410KeyWrap;

			case pkcs11::enums::Mechanism::GOSTR3410_DERIVE:
				return &gostr3410Derive;

			case pkcs11::enums::Mechanism::GOSTR3411:
				return &gostr3411;

			case pkcs11::enums::Mechanism::GOSTR3411_HMAC:
				return &gostr3411Hmac;

			case pkcs11::enums::Mechanism::GOST28147_KEY_GEN:
				return &gost28147KeyGenerator;

			case pkcs11::enums::Mechanism::GOST28147_ECB:
				return &gost28147Ecb;

			case pkcs11::enums::Mechanism::GOST28147:
				return &gost28147;

			case pkcs11::enums::Mechanism::GOST28147_MAC:
				return &gost28147Mac;

			case pkcs11::enums::Mechanism::GOST28147_KEY_WRAP:
				return &gost28147KeyWrap;

			case pkcs11::enums::Mechanism::DSA_PARAMETER_GEN:
				return &dsaParameterGenerator;

			case pkcs11::enums::Mechanism::DH_PKCS_PARAMETER_GEN:
				return &diffieHellmanPkcsParameterGenerator;

			case pkcs11::enums::Mechanism::X9_42_DH_PARAMETER_GEN:
				return &x9dot42DiffieHellmanParameterGenerator;

			case pkcs11::enums::Mechanism::DSA_PROBABLISTIC_PARAMETER_GEN:
				return &dsaProbablisticParameterGenerator;

			case pkcs11::enums::Mechanism::DSA_SHAWE_TAYLOR_PARAMETER_GEN:
				return &dsaShaweTaylorParameterGenerator;

			case pkcs11::enums::Mechanism::AES_OFB:
				return &aesOfb;

			case pkcs11::enums::Mechanism::AES_CFB64:
				return &aesCfb64;

			case pkcs11::enums::Mechanism::AES_CFB8:
				return &aesCfb8;

			case pkcs11::enums::Mechanism::AES_CFB128:
				return &aesCfb128;

			case pkcs11::enums::Mechanism::AES_CFB1:
				return &aesCfb1;

			case pkcs11::enums::Mechanism::AES_KEY_WRAP:
				return &aesKeyWrap;

			case pkcs11::enums::Mechanism::AES_KEY_WRAP_PAD:
				return &aesKeyWrapPad;

			case pkcs11::enums::Mechanism::RSA_PKCS_TPM_1_1:
				return &rsaPkcsTpm11;

			case pkcs11::enums::Mechanism::RSA_PKCS_OAEP_TPM_1_1:
				return &rsaPkcsOaepTpm11;

			default:
				return nullptr;
		}
	}
};

MechanismList::MechanismList() noexcept :
		list{ static_cast<decltype(list)>(
				allocator.allocate(sizeof(List))
		) }
{}

MechanismList::~MechanismList() noexcept
{
	allocator.deallocate(list);
}

MechanismBase &MechanismList::get(pkcs11::enums::Mechanism mechanismType) noexcept
{
	if (list)
	{
		MechanismBase *mechanism = makeReferenceWrapper(list).get()(mechanismType);
		if (mechanism)
		{
			return *mechanism;
		}
	}
	return vendorDefined;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

