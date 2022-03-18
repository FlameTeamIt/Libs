#include <FlameIDE/Crypto/Pkcs11/Types/Structs/PrfDataParam.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

PrfDataParam::PrfDataParam() noexcept
{}

PrfDataParam::PrfDataParam(const PrfDataParam &params) noexcept
{
	operator=(params);
}

PrfDataParam::PrfDataParam(const Parent &params) noexcept
{
	operator=(params);
}

PrfDataParam::PrfDataParam(
		const decltype(Parent::type) &type
		, const decltype(Parent::pValue) &value
		, const decltype(Parent::ulValueLen) &valueLength
) noexcept
{
	this->type = type;
	pValue = value;
	ulValueLen = valueLength;
}

PrfDataParam &PrfDataParam::operator=(const PrfDataParam &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

PrfDataParam &PrfDataParam::operator=(const Parent &params) noexcept
{
	type = params.type;
	pValue = params.pValue;
	ulValueLen = params.ulValueLen;

	return *this;
}

}}} // flame_ide::pkcs11::structs
