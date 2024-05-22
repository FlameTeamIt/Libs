#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTOR_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTOR_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class Encryptor
{
public:
	using InitCallback = void (*)(void);
	using UpdateCallback = void (*)(void);
	using FinalCallback = void (*)(void);

public:
	Encryptor() noexcept;
	~Encryptor() noexcept;

	void init();
	void update();
	void final();

protected:
	InitCallback initCallback;
	UpdateCallback updateCallback;
	FinalCallback finalCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ENCRYPTOR_HPP
