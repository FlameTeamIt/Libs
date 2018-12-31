﻿#ifndef FLAMEIDE_COMMON_MACROSES_HPP
#define FLAMEIDE_COMMON_MACROSES_HPP

#ifdef _WIN32
#	define ORDER_LITTLE_ENDIAN 0
#	define ORDER_BIG_ENDIAN    1
#	define ORDER_PDP_ENDIAN    2
#	define CURRENT_BYTE_ORDER  ORDER_LITTLE_ENDIAN
#else
#	define ORDER_LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#	define ORDER_BIG_ENDIAN    __ORDER_BIG_ENDIAN__
#	define ORDER_PDP_ENDIAN    __ORDER_PDP_ENDIAN__
#	define CURRENT_BYTE_ORDER  __BYTE_ORDER__
#endif

#endif // FLAMEIDE_COMMON_MACROSES_HPP