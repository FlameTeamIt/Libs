#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CONCATENATE_DATA_AND_BASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CONCATENATE_DATA_AND_BASE_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct ConcatenateDataAndBase: public MechanismBase
{
	ConcatenateDataAndBase() noexcept;

	virtual ~ConcatenateDataAndBase() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CONCATENATE_DATA_AND_BASE_HPP
