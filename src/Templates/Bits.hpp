#ifndef TEMPLATES_BITS_HPP
#define TEMPLATES_BITS_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{namespace bits
{

template<typename IntegralType, size_t BIT>
struct UpperedBit: public NonCreational
{
	static constexpr IntegralType VALUE = IntegralType(1) << BIT;
};

#define BIT(type, number) \
	UpperedBit<type, number>::VALUE

struct Constants: public NonCreational
{
	static constexpr auto BIT8_0 = BIT(Types::uichar_t, 0);
	static constexpr auto BIT8_1 = BIT(Types::uichar_t, 1);
	static constexpr auto BIT8_2 = BIT(Types::uichar_t, 2);
	static constexpr auto BIT8_3 = BIT(Types::uichar_t, 3);
	static constexpr auto BIT8_4 = BIT(Types::uichar_t, 4);
	static constexpr auto BIT8_5 = BIT(Types::uichar_t, 5);
	static constexpr auto BIT8_6 = BIT(Types::uichar_t, 6);
	static constexpr auto BIT8_7 = BIT(Types::uichar_t, 7);

	static constexpr decltype(BIT8_0) BYTE_0F = BIT8_0 | BIT8_1 | BIT8_2 | BIT8_3;
	static constexpr decltype(BIT8_0) BYTE_FF = BYTE_0F | BIT8_4 | BIT8_5 | BIT8_6 | BIT8_7;

	static constexpr auto BIT16_0 = Types::ushort_t(BIT8_0);
	static constexpr auto BIT16_1 = Types::ushort_t(BIT8_1);
	static constexpr auto BIT16_2 = Types::ushort_t(BIT8_2);
	static constexpr auto BIT16_3 = Types::ushort_t(BIT8_3);
	static constexpr auto BIT16_4 = Types::ushort_t(BIT8_4);
	static constexpr auto BIT16_5 = Types::ushort_t(BIT8_5);
	static constexpr auto BIT16_6 = Types::ushort_t(BIT8_6);
	static constexpr auto BIT16_7 = Types::ushort_t(BIT8_7);
	static constexpr auto BIT16_8 = BIT(Types::ushort_t, 8);
	static constexpr auto BIT16_9 = BIT(Types::ushort_t, 9);
	static constexpr auto BIT16_10 = BIT(Types::ushort_t, 10);
	static constexpr auto BIT16_11 = BIT(Types::ushort_t, 11);
	static constexpr auto BIT16_12 = BIT(Types::ushort_t, 12);
	static constexpr auto BIT16_13 = BIT(Types::ushort_t, 13);
	static constexpr auto BIT16_14 = BIT(Types::ushort_t, 14);
	static constexpr auto BIT16_15 = BIT(Types::ushort_t, 15);

	static constexpr auto BIT32_0 = Types::uint_t(BIT16_0);
	static constexpr auto BIT32_1 = Types::uint_t(BIT16_1);
	static constexpr auto BIT32_2 = Types::uint_t(BIT16_2);
	static constexpr auto BIT32_3 = Types::uint_t(BIT16_3);
	static constexpr auto BIT32_4 = Types::uint_t(BIT16_4);
	static constexpr auto BIT32_5 = Types::uint_t(BIT16_5);
	static constexpr auto BIT32_6 = Types::uint_t(BIT16_6);
	static constexpr auto BIT32_7 = Types::uint_t(BIT16_7);
	static constexpr auto BIT32_8 = Types::uint_t(BIT16_8);
	static constexpr auto BIT32_9 = Types::uint_t(BIT16_9);
	static constexpr auto BIT32_10 = Types::uint_t(BIT16_10);
	static constexpr auto BIT32_11 = Types::uint_t(BIT16_11);
	static constexpr auto BIT32_12 = Types::uint_t(BIT16_12);
	static constexpr auto BIT32_13 = Types::uint_t(BIT16_13);
	static constexpr auto BIT32_14 = Types::uint_t(BIT16_14);
	static constexpr auto BIT32_15 = Types::uint_t(BIT16_15);
	static constexpr auto BIT32_16 = BIT(Types::uint_t, 16);
	static constexpr auto BIT32_17 = BIT(Types::uint_t, 17);
	static constexpr auto BIT32_18 = BIT(Types::uint_t, 18);
	static constexpr auto BIT32_19 = BIT(Types::uint_t, 19);
	static constexpr auto BIT32_20 = BIT(Types::uint_t, 20);
	static constexpr auto BIT32_21 = BIT(Types::uint_t, 21);
	static constexpr auto BIT32_22 = BIT(Types::uint_t, 22);
	static constexpr auto BIT32_23 = BIT(Types::uint_t, 23);
	static constexpr auto BIT32_24 = BIT(Types::uint_t, 24);
	static constexpr auto BIT32_25 = BIT(Types::uint_t, 25);
	static constexpr auto BIT32_26 = BIT(Types::uint_t, 26);
	static constexpr auto BIT32_27 = BIT(Types::uint_t, 27);
	static constexpr auto BIT32_28 = BIT(Types::uint_t, 28);
	static constexpr auto BIT32_29 = BIT(Types::uint_t, 29);
	static constexpr auto BIT32_30 = BIT(Types::uint_t, 30);
	static constexpr auto BIT32_31 = BIT(Types::uint_t, 31);

	static constexpr auto BIT64_0 = Types::ulong_t(BIT32_0);
	static constexpr auto BIT64_1 = Types::ulong_t(BIT32_1);
	static constexpr auto BIT64_2 = Types::ulong_t(BIT32_2);
	static constexpr auto BIT64_3 = Types::ulong_t(BIT32_3);
	static constexpr auto BIT64_4 = Types::ulong_t(BIT32_4);
	static constexpr auto BIT64_5 = Types::ulong_t(BIT32_5);
	static constexpr auto BIT64_6 = Types::ulong_t(BIT32_6);
	static constexpr auto BIT64_7 = Types::ulong_t(BIT32_7);
	static constexpr auto BIT64_8 = Types::ulong_t(BIT32_8);
	static constexpr auto BIT64_9 = Types::ulong_t(BIT32_9);
	static constexpr auto BIT64_10 = Types::ulong_t(BIT32_10);
	static constexpr auto BIT64_11 = Types::ulong_t(BIT32_11);
	static constexpr auto BIT64_12 = Types::ulong_t(BIT32_12);
	static constexpr auto BIT64_13 = Types::ulong_t(BIT32_13);
	static constexpr auto BIT64_14 = Types::ulong_t(BIT32_14);
	static constexpr auto BIT64_15 = Types::ulong_t(BIT32_15);
	static constexpr auto BIT64_16 = Types::ulong_t(BIT32_16);
	static constexpr auto BIT64_17 = Types::ulong_t(BIT32_17);
	static constexpr auto BIT64_18 = Types::ulong_t(BIT32_18);
	static constexpr auto BIT64_19 = Types::ulong_t(BIT32_19);
	static constexpr auto BIT64_20 = Types::ulong_t(BIT32_20);
	static constexpr auto BIT64_21 = Types::ulong_t(BIT32_21);
	static constexpr auto BIT64_22 = Types::ulong_t(BIT32_22);
	static constexpr auto BIT64_23 = Types::ulong_t(BIT32_23);
	static constexpr auto BIT64_24 = Types::ulong_t(BIT32_24);
	static constexpr auto BIT64_25 = Types::ulong_t(BIT32_25);
	static constexpr auto BIT64_26 = Types::ulong_t(BIT32_26);
	static constexpr auto BIT64_27 = Types::ulong_t(BIT32_27);
	static constexpr auto BIT64_28 = Types::ulong_t(BIT32_28);
	static constexpr auto BIT64_29 = Types::ulong_t(BIT32_29);
	static constexpr auto BIT64_30 = Types::ulong_t(BIT32_30);
	static constexpr auto BIT64_31 = Types::ulong_t(BIT32_31);
	static constexpr auto BIT64_32 = BIT(Types::ullong_t, 32);
	static constexpr auto BIT64_33 = BIT(Types::ullong_t, 33);
	static constexpr auto BIT64_34 = BIT(Types::ullong_t, 34);
	static constexpr auto BIT64_35 = BIT(Types::ullong_t, 35);
	static constexpr auto BIT64_36 = BIT(Types::ullong_t, 36);
	static constexpr auto BIT64_37 = BIT(Types::ullong_t, 37);
	static constexpr auto BIT64_38 = BIT(Types::ullong_t, 38);
	static constexpr auto BIT64_39 = BIT(Types::ullong_t, 39);
	static constexpr auto BIT64_40 = BIT(Types::ullong_t, 40);
	static constexpr auto BIT64_41 = BIT(Types::ullong_t, 41);
	static constexpr auto BIT64_42 = BIT(Types::ullong_t, 42);
	static constexpr auto BIT64_43 = BIT(Types::ullong_t, 43);
	static constexpr auto BIT64_44 = BIT(Types::ullong_t, 44);
	static constexpr auto BIT64_45 = BIT(Types::ullong_t, 45);
	static constexpr auto BIT64_46 = BIT(Types::ullong_t, 46);
	static constexpr auto BIT64_47 = BIT(Types::ullong_t, 47);
	static constexpr auto BIT64_48 = BIT(Types::ullong_t, 48);
	static constexpr auto BIT64_49 = BIT(Types::ullong_t, 49);
	static constexpr auto BIT64_50 = BIT(Types::ullong_t, 50);
	static constexpr auto BIT64_51 = BIT(Types::ullong_t, 51);
	static constexpr auto BIT64_52 = BIT(Types::ullong_t, 52);
	static constexpr auto BIT64_53 = BIT(Types::ullong_t, 53);
	static constexpr auto BIT64_54 = BIT(Types::ullong_t, 54);
	static constexpr auto BIT64_55 = BIT(Types::ullong_t, 55);
	static constexpr auto BIT64_56 = BIT(Types::ullong_t, 56);
	static constexpr auto BIT64_57 = BIT(Types::ullong_t, 57);
	static constexpr auto BIT64_58 = BIT(Types::ullong_t, 58);
	static constexpr auto BIT64_59 = BIT(Types::ullong_t, 59);
	static constexpr auto BIT64_60 = BIT(Types::ullong_t, 60);
	static constexpr auto BIT64_63 = BIT(Types::ullong_t, 61);
	static constexpr auto BIT64_62 = BIT(Types::ullong_t, 62);
	static constexpr auto BIT64_61 = BIT(Types::ullong_t, 63);
};

#undef BIT

template<Types::size_t TEMPLATE_COUNT_BITS>
struct MinimalType
{
	static constexpr auto COUNT_BITS = TEMPLATE_COUNT_BITS;

	using Type = typename ChooseType<
		TEMPLATE_COUNT_BITS <= sizeof(uint8_t) * 8
		, uint8_t
		, typename ChooseType<
			TEMPLATE_COUNT_BITS <= sizeof(uint16_t) * 8
			, uint16_t
			, typename ChooseType<
				TEMPLATE_COUNT_BITS <= sizeof(uint32_t) * 8
				, uint32_t
				, typename ChooseType<
					TEMPLATE_COUNT_BITS <= sizeof(uint64_t) * 8
					, uint64_t
					, void
				>::Type
			>::Type
		>::Type
	>::Type;
};

}}}

namespace flame_ide
{namespace templates
{namespace bits
{


}}}

#endif // TEMPLATES_BITS_HPP
