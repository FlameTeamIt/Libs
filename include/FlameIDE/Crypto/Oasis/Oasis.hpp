#ifndef FLAMEDE_CRYPTO_OASIS_HPP
#define FLAMEDE_CRYPTO_OASIS_HPP

#include <FlameIDE/Common/Macros/DetectCompiler.hpp>

#define CK_DISABLE_TRUE_FALSE
#define CK_PTR *

#define CK_DECLARE_FUNCTION(returnType, name) \
	returnType FLAMEIDE_EXPORT name
#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
	returnType (* name)
#define CK_CALLBACK_FUNCTION(returnType, name) \
	returnType (* name)

#if defined (FLAMEIDE_COMPILER)
#	pragma pack(push, 1)
#endif

#include <FlameIDE/Crypto/Oasis/pkcs11.h>

#if defined (FLAMEIDE_COMPILER)
#	pragma pack(pop)
#endif

#endif // FLAMEDE_CRYPTO_OASIS_HPP
