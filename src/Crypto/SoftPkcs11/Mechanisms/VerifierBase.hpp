#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIERBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIERBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class VerifierBase
{
public:
	VerifierBase() noexcept;
	virtual ~VerifierBase() noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIERBASE_HPP
