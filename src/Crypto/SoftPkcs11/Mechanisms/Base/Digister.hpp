#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DIGISTER_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DIGISTER_HPP

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class Digister
{
public:
	using InitCallback = void (*)(void);
	using UpdateCallback = void (*)(void);
	using FinalCallback = void (*)(void);

	using KeyCallback = void (*)(void);

public:
	Digister() noexcept;
	~Digister() noexcept;

	void init();
	void update();
	void final();

protected:
	InitCallback initCallback;
	UpdateCallback updateCallback;
	FinalCallback finalCallback;

	KeyCallback keyCallback;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_DIGISTER_HPP
