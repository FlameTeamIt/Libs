#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DECRYPTORBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DECRYPTORBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class DecryptorBase
{
public:
	DecryptorBase() noexcept;
	virtual ~DecryptorBase() noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DECRYPTORBASE_HPP
