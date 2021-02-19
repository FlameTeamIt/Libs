#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_PARALLELMANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_PARALLELMANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace parallel_management
{

///
/// \brief getFunctionStatus
/// \param session
/// \return
///
pkcs11::value_types::ReturnType getFunctionStatus(
		pkcs11::value_types::SessionHandle session
);

///
/// \brief cancelFunction
/// \param session
/// \return
///
pkcs11::value_types::ReturnType cancelFunction(
		pkcs11::value_types::SessionHandle session
);

///
/// \brief waitForSlotEvent
/// \param flags
/// \param slotId
/// \return
///
pkcs11::value_types::ReturnType waitForSlotEvent(
		pkcs11::value_types::Flags flags
		, pkcs11::value_types::SlotIdPtr slotId
		, pkcs11::value_types::ValuePtr /* reserved */
);

}}}} // flame_ide::soft_pkcs11::functions::parallel_management

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_PARALLELMANAGEMENTFUNCTIONS_HPP
