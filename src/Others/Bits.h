#ifndef BITS_H
#define BITS_H

#include <Others/PrimitiveTypes.h>

namespace flame_ide
{namespace bits
{

using namespace flame_ide::types;

	const primitive::uchar_t BIT8_0 =   1U;
	const primitive::uchar_t BIT8_1 =   2U;
	const primitive::uchar_t BIT8_2 =   4U;
	const primitive::uchar_t BIT8_3 =   8U;
	const primitive::uchar_t BIT8_4 =  16U;
	const primitive::uchar_t BIT8_5 =  32U;
	const primitive::uchar_t BIT8_6 =  64U;
	const primitive::uchar_t BIT8_7 = 128U;

	const primitive::ushort_t BIT16_0  =     1U;
	const primitive::ushort_t BIT16_1  =     2U;
	const primitive::ushort_t BIT16_2  =     4U;
	const primitive::ushort_t BIT16_3  =     8U;
	const primitive::ushort_t BIT16_4  =    16U;
	const primitive::ushort_t BIT16_5  =    32U;
	const primitive::ushort_t BIT16_6  =    64U;
	const primitive::ushort_t BIT16_7  =   128U;
	const primitive::ushort_t BIT16_8  =   256U;
	const primitive::ushort_t BIT16_9  =   512U;
	const primitive::ushort_t BIT16_10 =  1024U;
	const primitive::ushort_t BIT16_11 =  2048U;
	const primitive::ushort_t BIT16_12 =  4096U;
	const primitive::ushort_t BIT16_13 =  8192U;
	const primitive::ushort_t BIT16_14 = 16384U;
	const primitive::ushort_t BIT16_15 = 32768U;

	const primitive::uint_t BIT32_0  =          1U;
	const primitive::uint_t BIT32_1  =          2U;
	const primitive::uint_t BIT32_2  =          4U;
	const primitive::uint_t BIT32_3  =          8U;
	const primitive::uint_t BIT32_4  =         16U;
	const primitive::uint_t BIT32_5  =         32U;
	const primitive::uint_t BIT32_6  =         64U;
	const primitive::uint_t BIT32_7  =        128U;
	const primitive::uint_t BIT32_8  =        256U;
	const primitive::uint_t BIT32_9  =        512U;
	const primitive::uint_t BIT32_10 =       1024U;
	const primitive::uint_t BIT32_11 =       2048U;
	const primitive::uint_t BIT32_12 =       4096U;
	const primitive::uint_t BIT32_13 =       8192U;
	const primitive::uint_t BIT32_14 =      16384U;
	const primitive::uint_t BIT32_15 =      32768U;
	const primitive::uint_t BIT32_16 =      65536U;
	const primitive::uint_t BIT32_17 =     131072U;
	const primitive::uint_t BIT32_18 =     262144U;
	const primitive::uint_t BIT32_19 =     524288U;
	const primitive::uint_t BIT32_20 =    1048576U;
	const primitive::uint_t BIT32_21 =    2097152U;
	const primitive::uint_t BIT32_22 =    4194304U;
	const primitive::uint_t BIT32_23 =    8388608U;
	const primitive::uint_t BIT32_24 =   16777216U;
	const primitive::uint_t BIT32_25 =   33554432U;
	const primitive::uint_t BIT32_26 =   67108864U;
	const primitive::uint_t BIT32_27 =  134217728U;
	const primitive::uint_t BIT32_28 =  268435456U;
	const primitive::uint_t BIT32_29 =  536870912U;
	const primitive::uint_t BIT32_30 = 1073741824U;
	const primitive::uint_t BIT32_31 = 2147483648U;

	const primitive::ullong_t BIT64_0  =                   1UL;
	const primitive::ullong_t BIT64_1  =                   2UL;
	const primitive::ullong_t BIT64_2  =                   4UL;
	const primitive::ullong_t BIT64_3  =                   8UL;
	const primitive::ullong_t BIT64_4  =                  16UL;
	const primitive::ullong_t BIT64_5  =                  32UL;
	const primitive::ullong_t BIT64_6  =                  64UL;
	const primitive::ullong_t BIT64_7  =                 128UL;
	const primitive::ullong_t BIT64_8  =                 256UL;
	const primitive::ullong_t BIT64_9  =                 512UL;
	const primitive::ullong_t BIT64_10 =                1024UL;
	const primitive::ullong_t BIT64_11 =                2048UL;
	const primitive::ullong_t BIT64_12 =                4096UL;
	const primitive::ullong_t BIT64_13 =                8192UL;
	const primitive::ullong_t BIT64_14 =               16384UL;
	const primitive::ullong_t BIT64_15 =               32768UL;
	const primitive::ullong_t BIT64_16 =               65536UL;
	const primitive::ullong_t BIT64_17 =              131072UL;
	const primitive::ullong_t BIT64_18 =              262144UL;
	const primitive::ullong_t BIT64_19 =              524288UL;
	const primitive::ullong_t BIT64_20 =             1048576UL;
	const primitive::ullong_t BIT64_21 =             2097152UL;
	const primitive::ullong_t BIT64_22 =             4194304UL;
	const primitive::ullong_t BIT64_23 =             8388608UL;
	const primitive::ullong_t BIT64_24 =            16777216UL;
	const primitive::ullong_t BIT64_25 =            33554432UL;
	const primitive::ullong_t BIT64_26 =            67108864UL;
	const primitive::ullong_t BIT64_27 =           134217728UL;
	const primitive::ullong_t BIT64_28 =           268435456UL;
	const primitive::ullong_t BIT64_29 =           536870912UL;
	const primitive::ullong_t BIT64_30 =          1073741824UL;
	const primitive::ullong_t BIT64_31 =          2147483648UL;
	const primitive::ullong_t BIT64_32 =          4294967296UL;
	const primitive::ullong_t BIT64_33 =          8589934592UL;
	const primitive::ullong_t BIT64_34 =         17179869184UL;
	const primitive::ullong_t BIT64_35 =         34359738368UL;
	const primitive::ullong_t BIT64_36 =         68719476736UL;
	const primitive::ullong_t BIT64_37 =        137438953472UL;
	const primitive::ullong_t BIT64_38 =        274877906944UL;
	const primitive::ullong_t BIT64_39 =        549755813888UL;
	const primitive::ullong_t BIT64_40 =       1099511627776UL;
	const primitive::ullong_t BIT64_41 =       2199023255552UL;
	const primitive::ullong_t BIT64_42 =       4398046511104UL;
	const primitive::ullong_t BIT64_43 =       8796093022208UL;
	const primitive::ullong_t BIT64_44 =      17592186044416UL;
	const primitive::ullong_t BIT64_45 =      35184372088832UL;
	const primitive::ullong_t BIT64_46 =      70368744177664UL;
	const primitive::ullong_t BIT64_47 =     140737488355328UL;
	const primitive::ullong_t BIT64_48 =     281474976710656UL;
	const primitive::ullong_t BIT64_49 =     562949953421312UL;
	const primitive::ullong_t BIT64_50 =    1125899906842624UL;
	const primitive::ullong_t BIT64_51 =    2251799813685248UL;
	const primitive::ullong_t BIT64_52 =    4503599627370496UL;
	const primitive::ullong_t BIT64_53 =    9007199254740992UL;
	const primitive::ullong_t BIT64_54 =   18014398509481984UL;
	const primitive::ullong_t BIT64_55 =   36028797018963968UL;
	const primitive::ullong_t BIT64_56 =   72057594037927936UL;
	const primitive::ullong_t BIT64_57 =  144115188075855872UL;
	const primitive::ullong_t BIT64_58 =  288230376151711744UL;
	const primitive::ullong_t BIT64_59 =  576460752303423488UL;
	const primitive::ullong_t BIT64_60 = 1152921504606846976UL;
	const primitive::ullong_t BIT64_61 = 2305843009213693952UL;
	const primitive::ullong_t BIT64_62 = 4611686018427387904UL;
	const primitive::ullong_t BIT64_63 = 9223372036854775808UL;
	
}}

#endif // BITS_H
