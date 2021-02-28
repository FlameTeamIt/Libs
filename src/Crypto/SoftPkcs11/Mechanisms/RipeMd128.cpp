#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd128::RipeMd128() noexcept = default;
RipeMd128::~RipeMd128() noexcept = default;

pkcs11::enums::Mechanism RipeMd128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

