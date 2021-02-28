#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateDataAndBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ConcatenateDataAndBase::ConcatenateDataAndBase() noexcept = default;
ConcatenateDataAndBase::~ConcatenateDataAndBase() noexcept = default;

pkcs11::enums::Mechanism ConcatenateDataAndBase::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CONCATENATE_DATA_AND_BASE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

