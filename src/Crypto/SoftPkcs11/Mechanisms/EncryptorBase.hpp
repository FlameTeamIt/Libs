#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class EncryptorBase
{
public:
	EncryptorBase() noexcept;
	virtual ~EncryptorBase() noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP
