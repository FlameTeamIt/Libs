#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ActiKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ActiKeyGenerator::ActiKeyGenerator() noexcept = default;
ActiKeyGenerator::~ActiKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism ActiKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ACTI_KEY_GEN;
}

pkcs11::structs::MechanismInfo ActiKeyGenerator::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::GENERATE
			& pkcs11::enums::MechanismFlags::GENERATE_KEY_PAIR
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

