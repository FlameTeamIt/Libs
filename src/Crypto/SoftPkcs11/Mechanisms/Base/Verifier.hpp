#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIER_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIER_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class Verifier
{
public:
	using InitCallback = void (*)(void);
	using UpdateCallback = void (*)(void);
	using FinalCallback = void (*)(void);

	using RecoverCallback = void (*)(void);

public:
	Verifier() noexcept;
	~Verifier() noexcept;

	void init(void);
	void update(void);
	void final(void);

	void recover (void);

protected:
	InitCallback initCallback;
	UpdateCallback updateCallback;
	FinalCallback finalCallback;

	RecoverCallback recoverCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_VERIFIER_HPP
