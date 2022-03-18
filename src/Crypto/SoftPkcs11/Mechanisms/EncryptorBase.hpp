#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class EncryptorBase
{
public:
	using InitCallback = void (*)(void);
	using UpdateCallback = void (*)(void);
	using FinalCallback = void (*)(void);

public:
	EncryptorBase() noexcept;
	~EncryptorBase() noexcept;

	void init();
	void update();
	void final();

protected:
	InitCallback initCallback;
	UpdateCallback updateCallback;
	FinalCallback finalCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTORBASE_HPP
