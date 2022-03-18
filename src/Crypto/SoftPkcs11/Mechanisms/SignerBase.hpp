#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class SignerBase
{
public:
	using InitCallback = void (*)(void);
	using UpdateCallback = void (*)(void);
	using FinalCallback = void (*)(void);

	using RecoverCallback = void (*)(void);

public:
	SignerBase() noexcept;
	~SignerBase() noexcept;

	void init();
	void update();
	void final();

	void recover();

protected:
	InitCallback initCallback;
	UpdateCallback updateCallback;
	FinalCallback finalCallback;

	RecoverCallback recoverCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SIGNERBASE_HPP
