#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Rc5Params.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Rc5Params::Rc5Params() noexcept
{}

Rc5Params::Rc5Params(const Rc5Params &params) noexcept
{
	operator=(params);
}

Rc5Params::Rc5Params(const Parent &params) noexcept
{
	operator=(params);
}

Rc5Params::Rc5Params(
		const decltype(Parent::ulWordsize) &wordSize
		, const decltype(Parent::ulRounds) &rounds
) noexcept
{
	ulWordsize = wordSize;
	ulRounds = rounds;
}

Rc5Params &Rc5Params::operator=(const Rc5Params &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Rc5Params &Rc5Params::operator=(const Parent &params) noexcept
{
	ulWordsize = params.ulWordsize;
	ulRounds = params.ulRounds;

	return *this;
}

}}} // flame_ide::pkcs11::structs
