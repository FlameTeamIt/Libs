#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISM_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISM_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Templates/Expected.hpp>
#include <FlameIDE/Templates/Variant.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Base/Encryptor.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Base/Decryptor.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Base/Signer.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Base/Verifier.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class Mechanism
{
public:
	using ExpectedEncryptor = templates::Expected<
		Encryptor *, pkcs11::enums::ReturnType
	>;
	using ExpectedDecryptor = templates::Expected<
		Decryptor *, pkcs11::enums::ReturnType
	>;
	using ExpectedSigner = templates::Expected<
		Signer *, pkcs11::enums::ReturnType
	>;
	using ExpectedVerifier = templates::Expected<
		Verifier *, pkcs11::enums::ReturnType
	>;

	using Parameter = templates::Variant<
		pkcs11::structs::RsaPkcsOaepParams
		, pkcs11::structs::RsaPkcsPssParams
		, pkcs11::structs::ElipticCurveDiffieHellman1DeriveParams
		, pkcs11::structs::ElipticCurveDiffieHellman2DeriveParams
		, pkcs11::structs::EcMqvDeriveParams
		, pkcs11::structs::X9dot42DiffieHellman1DeriveParams
		, pkcs11::structs::X9dot42DiffieHellman2DeriveParams
		, pkcs11::structs::X9dot42MqvDeriveParams
		, pkcs11::structs::KeaDeriveParams
		, pkcs11::structs::Rc2CbcParams
		, pkcs11::structs::Rc2MacGeneralParams
		, pkcs11::structs::Rc5Params
		, pkcs11::structs::Rc5CbcParams
		, pkcs11::structs::Rc5MacGeneralParams
		, pkcs11::structs::DesCbcEncryptDataParams
		, pkcs11::structs::AesCbcEncryptDataParams
		, pkcs11::structs::SkipjackPrivateWrapParams
		, pkcs11::structs::SkipjackRelayxParams
		, pkcs11::structs::PbeParams
		, pkcs11::structs::KeyWrapSetOaepParams
		, pkcs11::structs::Ssl3MasterKeyDeriveParams
		, pkcs11::structs::Ssl3KeyMatParams
		, pkcs11::structs::TlsPrfParams
		, pkcs11::structs::WtlsMasterKeyDeriveParams
		, pkcs11::structs::WtlsPrfParams
		, pkcs11::structs::WtlsKeyMatParams
		, pkcs11::structs::CmsSigParams
		, pkcs11::structs::Pkcs5Pbkd2Params
		, pkcs11::structs::Pkcs5Pbkd2Params2
		, pkcs11::structs::OtpParam
		, pkcs11::structs::OtpParams
		, pkcs11::structs::KipParams
		, pkcs11::structs::AesCtrParams
		, pkcs11::structs::GcmParams
		, pkcs11::structs::CcmParams
		, pkcs11::structs::CamelliaCtrParams
		, pkcs11::structs::CamelliaCbcEncryptDataParams
		, pkcs11::structs::AriaCbcEncryptDataParams
		, pkcs11::structs::DsaParameterGenParam
		, pkcs11::structs::EcdhAesKeyWrapParams
		, pkcs11::structs::RsaAesKeyWrapParams
		, pkcs11::structs::Tls12MasterKeyDeriveParams
		, pkcs11::structs::Tls12KeyMatParams
		, pkcs11::structs::TlsKdfParams
		, pkcs11::structs::TlsMacParams
		, pkcs11::structs::Gostr3410DeriveParams
		, pkcs11::structs::Gostr3410KeyWrapParams
		, pkcs11::structs::SeedCbcEncryptDataParams

		// v3.0
		, pkcs11::structs::PrfDataParam
		, pkcs11::structs::NistSp800Hyphen108CounterFormat
		, pkcs11::structs::NistSp800Hyphen108DkmLengthFormat
		, pkcs11::structs::DerivedKey
		, pkcs11::structs::NistSp800Hyphen108KdfParams
		, pkcs11::structs::NistSp800Hyphen108FeedbackKdfParams
		, pkcs11::structs::EdDsaParams
		, pkcs11::structs::ChaCha20Params
		, pkcs11::structs::Salsa20Params
		, pkcs11::structs::Salsa20ChaCha20Poly1305Params
		, pkcs11::structs::Salsa20ChaCha20Poly1305MessageParams
		, pkcs11::structs::ExtendedTripleDiffieHellmanInitiateParams
		, pkcs11::structs::ExtendedTripleDiffieHellmanRespondParams
		, pkcs11::structs::DoubleRatchetInitializeParams
		, pkcs11::structs::DoubleRatchetRespondParams
		, pkcs11::structs::ExtendedEdDsaParams
		, pkcs11::structs::HkdfParams
	>;

	using GetTypeCallback = pkcs11::enums::Mechanism (*) (const Mechanism *);
	using GetInfoCallback = pkcs11::structs::MechanismInfo (*) (const Mechanism *);

	using GetEncryptorCallback = ExpectedEncryptor (*) (Mechanism *);
	using GetDecryptorCallback = ExpectedDecryptor (*) (Mechanism *);
	using GetSignerCallback = ExpectedSigner (*) (Mechanism *);
	using GetVerifierCallback = ExpectedVerifier (*) (Mechanism *);
	using ProcessParameterCallback = pkcs11::enums::ReturnType (*)(
			Mechanism *, const Parameter &
	);

public:
	Mechanism() noexcept;

	~Mechanism() noexcept;

	pkcs11::enums::Mechanism getType() const noexcept;

	pkcs11::structs::MechanismInfo getInfo() const noexcept;

	ExpectedEncryptor getEncryptor() noexcept;

	ExpectedDecryptor getDecryptor() noexcept;

	ExpectedSigner getSigner() noexcept;

	ExpectedVerifier getVerifier() noexcept;

	pkcs11::enums::ReturnType processParameter(
			const Parameter &paramter
	) noexcept;

protected:
	Mechanism(
			GetTypeCallback getTypeCallback
			, GetInfoCallback getInfoCallback
			, GetEncryptorCallback getEncryptorCallback
			, GetDecryptorCallback getDecryptorCallback
			, GetSignerCallback getSignerCallback
			, GetVerifierCallback getVerifierCallback
			, ProcessParameterCallback processParameterCallback
	) noexcept;

protected:
	GetTypeCallback getTypeCallback;
	GetInfoCallback getInfoCallback;

	GetEncryptorCallback getEncryptorCallback;
	GetDecryptorCallback getDecryptorCallback;
	GetSignerCallback getSignerCallback;
	GetVerifierCallback getVerifierCallback;
	ProcessParameterCallback processParameterCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISM_HPP
