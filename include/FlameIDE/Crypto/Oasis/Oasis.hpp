#ifndef FLAMEDE_CRYPTO_OASIS_HPP
#define FLAMEDE_CRYPTO_OASIS_HPP

#define CK_DISABLE_TRUE_FALSE
#define CK_PTR *

#define CK_DECLARE_FUNCTION(returnType, name) \
	returnType name
#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
	returnType (* name)
#define CK_CALLBACK_FUNCTION(returnType, name) \
	returnType (* name)

#include <FlameIDE/Crypto/Oasis/pkcs11.h>

#endif // FLAMEDE_CRYPTO_OASIS_HPP
