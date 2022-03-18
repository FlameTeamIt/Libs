#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_CALLBACKS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_CALLBACKS_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

pkcs11::structs::FunctionList createFunctionList() noexcept;

pkcs11::structs::FunctionList3 createFunctionList3() noexcept;

struct ExternalCallbacks
{
	flame_ide::pkcs11::callbacks::CreateMutex create   = nullptr;
	flame_ide::pkcs11::callbacks::DestroyMutex destroy = nullptr;
	flame_ide::pkcs11::callbacks::LockMutex lock       = nullptr;
	flame_ide::pkcs11::callbacks::UnlockMutex unlock   = nullptr;

	flame_ide::pkcs11::callbacks::Notify notify = nullptr; // TODO: by sessions
};

struct GeneralPurposeCallbacks
{
	const flame_ide::pkcs11::callbacks::Initialize initialize
			= functions::general_purpose::initialize;
	const flame_ide::pkcs11::callbacks::Finalize finalize
			= functions::general_purpose::finalize;
	const flame_ide::pkcs11::callbacks::GetInfo getInfo
			= functions::general_purpose::getInfo;
	const flame_ide::pkcs11::callbacks::GetFunctionList getFunctionList
			= functions::general_purpose::getFunctionList;

	// v3.0

	const flame_ide::pkcs11::callbacks::GetInterfaceList getInterfaceList
			= functions::general_purpose::getIterfaceList;
	const flame_ide::pkcs11::callbacks::GetInterface getInterface
			= functions::general_purpose::getIterface;
};

struct ManagementCallbacks
{
	const flame_ide::pkcs11::callbacks::GetSlotList getSlotList
			= functions::management::getSlotList;
	const flame_ide::pkcs11::callbacks::GetSlotInfo getSlotInfo
			= functions::management::getSlotInfo;
	const flame_ide::pkcs11::callbacks::GetTokenInfo getTokenInfo
			= functions::management::getTokenInfo;
	const flame_ide::pkcs11::callbacks::GetMechanismList getMechanismList
			= functions::management::getMechanismList;
	const flame_ide::pkcs11::callbacks::GetMechanismInfo getMechanismInfo
			= functions::management::getMechanismInfo;
	const flame_ide::pkcs11::callbacks::InitToken initToken
			= functions::management::initToken;
	const flame_ide::pkcs11::callbacks::InitPin initPin
			= functions::management::initPin;
	const flame_ide::pkcs11::callbacks::SetPin setPin
			= functions::management::setPin;
};

struct SessionCallbacks
{
	const flame_ide::pkcs11::callbacks::OpenSession open
			= functions::session::open;
	const flame_ide::pkcs11::callbacks::CloseSession close
			= functions::session::close;
	const flame_ide::pkcs11::callbacks::CloseAllSessions closeAll
			= functions::session::closeAll;
	const flame_ide::pkcs11::callbacks::GetSessionInfo getInfo
			= functions::session::getInfo;

	const flame_ide::pkcs11::callbacks::GetOperationState	getOperationState
			= functions::session::getOperationState;
	const flame_ide::pkcs11::callbacks::SetOperationState setOperationState
			= functions::session::setOperationState;

	const flame_ide::pkcs11::callbacks::Login login
			= functions::session::login;
	const flame_ide::pkcs11::callbacks::Logout logout
			= functions::session::logout;

	// v3.0

	const flame_ide::pkcs11::callbacks::LoginUser loginUser
			= functions::session::loginUser;

	const flame_ide::pkcs11::callbacks::SessionCancel sessionCancel
			= functions::session::sessionCancel;
};

struct ObjectCallbacks
{
	const flame_ide::pkcs11::callbacks::CreateObject create
			= functions::object::create;
	const flame_ide::pkcs11::callbacks::CopyObject copy
			= functions::object::copy;
	const flame_ide::pkcs11::callbacks::DestroyObject destroy
			= functions::object::destroy;
	const flame_ide::pkcs11::callbacks::GetObjectSize getSize
			= functions::object::getSize;

	const flame_ide::pkcs11::callbacks::GetAttributeValue getAttributeValue
			= functions::object::getAttributeValue;
	const flame_ide::pkcs11::callbacks::SetAttributeValue setAttributeValue
			= functions::object::setAttributeValue;

	const flame_ide::pkcs11::callbacks::FindObjectsInit findInit
			= functions::object::findInit;
	const flame_ide::pkcs11::callbacks::FindObjects find
			= functions::object::find;
	const flame_ide::pkcs11::callbacks::FindObjectsFinal findFinal
			= functions::object::findFinal;
};

struct EncryptCallbacks
{
	const flame_ide::pkcs11::callbacks::EncryptInit init
			= functions::encrypt::init;
	const flame_ide::pkcs11::callbacks::EncryptUpdate update
			= functions::encrypt::update;
	const flame_ide::pkcs11::callbacks::EncryptFinal final
			= functions::encrypt::final;
	const flame_ide::pkcs11::callbacks::Encrypt full
			= functions::encrypt::full;
};

struct DecryptCallbacks
{
	const flame_ide::pkcs11::callbacks::DecryptInit init
			= functions::decrypt::init;
	const flame_ide::pkcs11::callbacks::DecryptUpdate update
			= functions::decrypt::update;
	const flame_ide::pkcs11::callbacks::DecryptFinal final
			= functions::decrypt::final;
	const flame_ide::pkcs11::callbacks::Decrypt full
			= functions::decrypt::full;
};

struct DigestCallbacks
{
	const flame_ide::pkcs11::callbacks::DigestInit init
			= functions::digest::init;
	const flame_ide::pkcs11::callbacks::DigestUpdate update
			= functions::digest::update;
	const flame_ide::pkcs11::callbacks::DigestFinal final
			= functions::digest::final;
	const flame_ide::pkcs11::callbacks::Digest full
			= functions::digest::full;

	const flame_ide::pkcs11::callbacks::DigestKey key
			= functions::digest::key;
};

struct SignCallbacks
{
	const flame_ide::pkcs11::callbacks::SignInit init
			= functions::sign::init;
	const flame_ide::pkcs11::callbacks::SignUpdate update
			= functions::sign::update;
	const flame_ide::pkcs11::callbacks::SignFinal final
			= functions::sign::final;
	const flame_ide::pkcs11::callbacks::Sign full
			= functions::sign::full;

	const flame_ide::pkcs11::callbacks::SignRecoverInit recoverInit
			= functions::sign::recover::init;
	const flame_ide::pkcs11::callbacks::SignRecover recoverFull
			= functions::sign::recover::full;
};

struct VerifyCallbacks
{
	const flame_ide::pkcs11::callbacks::VerifyInit init
			= functions::verify::init;
	const flame_ide::pkcs11::callbacks::VerifyUpdate update
			= functions::verify::update;
	const flame_ide::pkcs11::callbacks::VerifyFinal final
			= functions::verify::final;
	const flame_ide::pkcs11::callbacks::Verify full
			= functions::verify::full;

	const flame_ide::pkcs11::callbacks::VerifyRecoverInit recoverInit
			= functions::verify::recover::init;
	const flame_ide::pkcs11::callbacks::VerifyRecover recoverFull
			= functions::verify::recover::full;
};

struct DualOperationCallbacks
{
	const flame_ide::pkcs11::callbacks::DigestEncryptUpdate digestEncryptUpdate
			= functions::dual_operations::digestEncryptUpdate;
	const flame_ide::pkcs11::callbacks::DecryptDigestUpdate decryptDigestUpdate
			= functions::dual_operations::decryptDigestUpdate;
	const flame_ide::pkcs11::callbacks::SignEncryptUpdate signEncryptUpdate
			= functions::dual_operations::signEncryptUpdate;
	const flame_ide::pkcs11::callbacks::DecryptVerifyUpdate decryptVerifyUpdate
			= functions::dual_operations::decryptVerifyUpdate;
};

struct KeyCallbacks
{
	const flame_ide::pkcs11::callbacks::GenerateKey generateKey
			= functions::key::generateKey;
	const flame_ide::pkcs11::callbacks::GenerateKeyPair generateKeyPair
			= functions::key::generateKeyPair;
	const flame_ide::pkcs11::callbacks::WrapKey wrapKey
			= functions::key::wrapKey;
	const flame_ide::pkcs11::callbacks::UnwrapKey unwrapKey
			= functions::key::unwrapKey;
	const flame_ide::pkcs11::callbacks::DeriveKey deriveKey
			= functions::key::deriveKey;
};

struct ParallelManagementCallbacks
{
	const flame_ide::pkcs11::callbacks::GetFunctionStatus getFunctionStatus
			= functions::parallel_management::getFunctionStatus;
	const flame_ide::pkcs11::callbacks::CancelFunction cancelfunciton
			= functions::parallel_management::cancelFunction;
	const flame_ide::pkcs11::callbacks::WaitForSlotEvent waitForSlotEvent
			= functions::parallel_management::waitForSlotEvent;
};

struct RandomGenerationCallbacks
{
	const flame_ide::pkcs11::callbacks::SeedRandom seedRandom
			= functions::random_generation::seedRandom;
	const flame_ide::pkcs11::callbacks::GenerateRandom generateRandom
			= functions::random_generation::generateRandom;
};

// v3.0
struct MessageEncriptionFunctions
{
	const flame_ide::pkcs11::callbacks::MessageEncryptInit encryptMessageInit
			= flame_ide::soft_pkcs11::functions::message::encryptInit;
	const flame_ide::pkcs11::callbacks::EncryptMessage encryptMessage
			= flame_ide::soft_pkcs11::functions::message::encrypt;
	const flame_ide::pkcs11::callbacks::EncryptMessageBegin encryptMessageBegin
			= flame_ide::soft_pkcs11::functions::message::encryptBegin;
	const flame_ide::pkcs11::callbacks::EncryptMessageNext encryptMessageNext
			= flame_ide::soft_pkcs11::functions::message::encryptNext;
	const flame_ide::pkcs11::callbacks::EncryptMessageFinal encryptMessageFinal
			= flame_ide::soft_pkcs11::functions::message::encryptFinal;
};

// v3.0
struct MessageDecriptionFunctions
{
	const flame_ide::pkcs11::callbacks::MessageDecryptInit decryptMessageInit
			= flame_ide::soft_pkcs11::functions::message::decryptInit;
	const flame_ide::pkcs11::callbacks::DecryptMessage decryptMessage
			= flame_ide::soft_pkcs11::functions::message::decrypt;
	const flame_ide::pkcs11::callbacks::DecryptMessageBegin decryptMessageBegin
			= flame_ide::soft_pkcs11::functions::message::decryptBegin;
	const flame_ide::pkcs11::callbacks::DecryptMessageNext decryptMessageNext
			= flame_ide::soft_pkcs11::functions::message::decryptNext;
	const flame_ide::pkcs11::callbacks::MessageDecryptFinal decryptMessageFinal
			= flame_ide::soft_pkcs11::functions::message::decryptFinal;
};

// v3.0
struct MessageSignFunctions
{
	const flame_ide::pkcs11::callbacks::MessageSignInit signMessageInit
			= flame_ide::soft_pkcs11::functions::message::signInit;
	const flame_ide::pkcs11::callbacks::SignMessage signMessage
			= flame_ide::soft_pkcs11::functions::message::sign;
	const flame_ide::pkcs11::callbacks::SignMessageBegin signMessageBegin
			= flame_ide::soft_pkcs11::functions::message::signBegin;
	const flame_ide::pkcs11::callbacks::SignMessageNext signMessageNext
			= flame_ide::soft_pkcs11::functions::message::signNext;
	const flame_ide::pkcs11::callbacks::MessageSignFinal signMessageFinal
			= flame_ide::soft_pkcs11::functions::message::signFinal;
};

// v3.0
struct MessageVerifyFunctions
{
	const flame_ide::pkcs11::callbacks::MessageVerifyInit verifyMessageInit
			= flame_ide::soft_pkcs11::functions::message::verifyInit;
	const flame_ide::pkcs11::callbacks::VerifyMessage verifyMessage
			= flame_ide::soft_pkcs11::functions::message::verify;
	const flame_ide::pkcs11::callbacks::VerifyMessageBegin verifyMessageBegin
			= flame_ide::soft_pkcs11::functions::message::verifyBegin;
	const flame_ide::pkcs11::callbacks::VerifyMessageNext verifyMessageNext
			= flame_ide::soft_pkcs11::functions::message::verifyNext;
	const flame_ide::pkcs11::callbacks::MessageVerifyFinal verifyMessageFinal
			= flame_ide::soft_pkcs11::functions::message::verifyFinal;
};

}} // flame_ide::soft_pkcs11

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_CALLBACKS_HPP
