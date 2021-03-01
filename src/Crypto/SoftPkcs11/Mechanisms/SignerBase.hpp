#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class SignerBase
{
public:
	SignerBase() noexcept;
	virtual ~SignerBase() noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP
