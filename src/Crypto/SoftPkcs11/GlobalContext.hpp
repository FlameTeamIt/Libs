#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mutex.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

struct GlobalContext
{
public:
	struct ExternalCallbacks
	{
		flame_ide::pkcs11::callbacks::CreateMutex create   = nullptr;
		flame_ide::pkcs11::callbacks::DestroyMutex destroy = nullptr;
		flame_ide::pkcs11::callbacks::LockMutex lock       = nullptr;
		flame_ide::pkcs11::callbacks::UnlockMutex unlock   = nullptr;

		flame_ide::pkcs11::callbacks::Notify notify = nullptr;
	};

	struct GeneralPurposeCallbacks
	{
		flame_ide::pkcs11::callbacks::Initialize initialize
				= functions::general_purpose::initialize;
		flame_ide::pkcs11::callbacks::Finalize finalize
				= functions::general_purpose::finalize;
		flame_ide::pkcs11::callbacks::GetInfo getInfo
				= functions::general_purpose::getInfo;
		flame_ide::pkcs11::callbacks::GetFunctionList getFunctionList
				= functions::general_purpose::getFunctionList;
	};

	struct ManagementCallbacks
	{
		flame_ide::pkcs11::callbacks::GetSlotList getSlotList
				= functions::management::getSlotList;
		flame_ide::pkcs11::callbacks::GetSlotInfo getSlotInfo
				= functions::management::getSlotInfo;
		flame_ide::pkcs11::callbacks::GetTokenInfo getTokenInfo
				= functions::management::getTokenInfo;
		flame_ide::pkcs11::callbacks::GetMechanismList getMechanismList
				= functions::management::getMechanismList;
		flame_ide::pkcs11::callbacks::GetMechanismInfo getMechanismInfo
				= functions::management::getMechanismInfo;
		flame_ide::pkcs11::callbacks::InitToken initToken
				= functions::management::initToken;
		flame_ide::pkcs11::callbacks::InitPin initPin
				= functions::management::initPin;
		flame_ide::pkcs11::callbacks::SetPin setPin
				= functions::management::setPin;
	};

	struct SessionCallbacks
	{
		flame_ide::pkcs11::callbacks::OpenSession open
				= functions::session::open;
		flame_ide::pkcs11::callbacks::CloseSession close
				= functions::session::close;
		flame_ide::pkcs11::callbacks::CloseAllSessions closeAll
				= functions::session::closeAll;
		flame_ide::pkcs11::callbacks::GetSessionInfo getInfo
				= functions::session::getInfo;

		flame_ide::pkcs11::callbacks::GetOperationState	getOperationState
				= functions::session::getOperationState;
		flame_ide::pkcs11::callbacks::SetOperationState setOperationState
				= functions::session::setOperationState;

		flame_ide::pkcs11::callbacks::Login login   = functions::session::login;
		flame_ide::pkcs11::callbacks::Logout logout = functions::session::logout;
	};

	struct ObjectCallbacks
	{
		flame_ide::pkcs11::callbacks::CreateObject create
				= functions::object::create;
		flame_ide::pkcs11::callbacks::CopyObject copy
				= functions::object::copy;
		flame_ide::pkcs11::callbacks::DestroyObject destroy
				= functions::object::destroy;
		flame_ide::pkcs11::callbacks::GetObjectSize getSize
				= functions::object::getSize;

		flame_ide::pkcs11::callbacks::GetAttributeValue getAttributeValue
				= functions::object::getAttributeValue;
		flame_ide::pkcs11::callbacks::SetAttributeValue setAttributeValue
				= functions::object::setAttributeValue;

		flame_ide::pkcs11::callbacks::FindObjectsInit findInit
				= functions::object::findInit;
		flame_ide::pkcs11::callbacks::FindObjects find
				= functions::object::find;
		flame_ide::pkcs11::callbacks::FindObjectsFinal findFinal
				= functions::object::findFinal;
	};

	struct EncryptCallbacks
	{
		flame_ide::pkcs11::callbacks::EncryptInit init     = functions::encrypt::init;
		flame_ide::pkcs11::callbacks::EncryptUpdate update = functions::encrypt::update;
		flame_ide::pkcs11::callbacks::EncryptFinal final   = functions::encrypt::final;
		flame_ide::pkcs11::callbacks::Encrypt full         = functions::encrypt::full;
	};

	struct DecryptCallbacks
	{
		flame_ide::pkcs11::callbacks::DecryptInit init     = functions::decrypt::init;
		flame_ide::pkcs11::callbacks::DecryptUpdate update = functions::decrypt::update;
		flame_ide::pkcs11::callbacks::DecryptFinal final   = functions::decrypt::final;
		flame_ide::pkcs11::callbacks::Decrypt full         = functions::decrypt::full;
	};

	struct DigestCallbacks
	{
		flame_ide::pkcs11::callbacks::DigestInit init     = functions::digest::init;
		flame_ide::pkcs11::callbacks::DigestUpdate update = functions::digest::update;
		flame_ide::pkcs11::callbacks::DigestFinal final   = functions::digest::final;
		flame_ide::pkcs11::callbacks::Digest full         = functions::digest::full;

		flame_ide::pkcs11::callbacks::DigestKey key       = functions::digest::key;
	};

	struct SignCallbacks
	{
		flame_ide::pkcs11::callbacks::SignInit init     = functions::sign::init;
		flame_ide::pkcs11::callbacks::SignUpdate update = functions::sign::update;
		flame_ide::pkcs11::callbacks::SignFinal final   = functions::sign::final;
		flame_ide::pkcs11::callbacks::Sign full         = functions::sign::full;

		flame_ide::pkcs11::callbacks::SignRecoverInit recoverInit
				= functions::sign::recover::init;
		flame_ide::pkcs11::callbacks::SignRecover recoverFull
				= functions::sign::recover::full;
	};

	struct VerifyCallbacks
	{
		flame_ide::pkcs11::callbacks::VerifyInit init     = functions::verify::init;
		flame_ide::pkcs11::callbacks::VerifyUpdate update = functions::verify::update;
		flame_ide::pkcs11::callbacks::VerifyFinal final   = functions::verify::final;
		flame_ide::pkcs11::callbacks::Verify full         = functions::verify::full;

		flame_ide::pkcs11::callbacks::VerifyRecoverInit recoverInit
				= functions::verify::recover::init;
		flame_ide::pkcs11::callbacks::VerifyRecover recoverFull
				= functions::verify::recover::full;
	};

	struct DualOperationCallbacks
	{
		flame_ide::pkcs11::callbacks::DigestEncryptUpdate digestEncryptUpdate
				= functions::dual_operations::digestEncryptUpdate;
		flame_ide::pkcs11::callbacks::DecryptDigestUpdate decryptDigestUpdate
				= functions::dual_operations::decryptDigestUpdate;
		flame_ide::pkcs11::callbacks::SignEncryptUpdate signEncryptUpdate
				= functions::dual_operations::signEncryptUpdate;
		flame_ide::pkcs11::callbacks::DecryptVerifyUpdate decryptVerifyUpdate
				= functions::dual_operations::decryptVerifyUpdate;
	};

	struct KeyCallbacks
	{
		flame_ide::pkcs11::callbacks::GenerateKey generateKey
				= functions::key::generateKey;
		flame_ide::pkcs11::callbacks::GenerateKeyPair generateKeyPair
				= functions::key::generateKeyPair;
		flame_ide::pkcs11::callbacks::WrapKey wrapKey
				= functions::key::wrapKey;
		flame_ide::pkcs11::callbacks::UnwrapKey unwrapKey
				= functions::key::unwrapKey;
		flame_ide::pkcs11::callbacks::DeriveKey deriveKey
				= functions::key::deriveKey;
	};

	struct ParallelManagementCallbacks
	{
		flame_ide::pkcs11::callbacks::GetFunctionStatus getFunctionStatus
				= functions::parallel_management::getFunctionStatus;
		flame_ide::pkcs11::callbacks::CancelFunction cancelfunciton
				= functions::parallel_management::cancelFunction;
		flame_ide::pkcs11::callbacks::WaitForSlotEvent waitForSlotEvent
				= functions::parallel_management::waitForSlotEvent;
	};

	struct OtherCallbacks
	{
		flame_ide::pkcs11::callbacks::SeedRandom seedRandom
				= functions::other::seedRandom;
		flame_ide::pkcs11::callbacks::GenerateRandom generateRandom
				= functions::other::generateRandom;
	};

public:
	static GlobalContext &get() noexcept;

public:
	Mutex createMutex() noexcept;

public:
	ExternalCallbacks externalCallbacks;
	GeneralPurposeCallbacks generalPurposeCallbacks;
	ManagementCallbacks managementCallbacks;
	SessionCallbacks sessionCallbacks;
	ObjectCallbacks objectCallbacks;
	EncryptCallbacks encryptCallbacks;
	DecryptCallbacks decryptCallbacks;
	DigestCallbacks digestCallbacks;
	SignCallbacks signCallbacks;
	VerifyCallbacks verifyCallbacks;
	DualOperationCallbacks dualOperationCallbacks;
	KeyCallbacks keyCallbacks;
	ParallelManagementCallbacks parallelManagementCallbacks;
	OtherCallbacks otherCallbacks;

	flame_ide::pkcs11::enums::InitializeArgsFlags initFlags;
};

}}

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

