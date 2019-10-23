#include <FlameIDE/Crypto/Pkcs11/Date.hpp>

namespace flame_ide
{
namespace pkcs11
{

namespace // anonymous
{

enum class CompareResult
{
	LESS = -1
	, EQUAL
	, MORE
};

template<typename T, Types::size_t INDEX, Types::size_t SIZE>
struct DoSomeByIndex
{
	static void copy(T (& dest)[SIZE], const T (& src)[SIZE])
	{
		dest[INDEX] = src[INDEX];
		DoSomeByIndex<T, INDEX + 1, SIZE>::copy(dest, src);
	}

	static CompareResult compare(const T (& array1)[SIZE], const T (& array2)[SIZE])
	{
		if (array1[INDEX] == array2[INDEX])
		{
			return DoSomeByIndex<T, INDEX + 1, SIZE>::compare(array1, array2);
		}
		else if (array1[INDEX] > array2[INDEX])
		{
			return CompareResult::MORE;
		}
		else
		{
			return CompareResult::LESS;
		}
	}
};

template<typename T, Types::size_t SIZE>
struct DoSomeByIndex<T, SIZE, SIZE>
{
	static void copy(T (&)[SIZE], const T (&)[SIZE])
	{}

	static CompareResult compare(const T (&)[SIZE], const T (&)[SIZE])
	{
		return CompareResult::EQUAL;
	}
};


template<typename T, Types::size_t SIZE>
void copy(T (& dest)[SIZE], const T (& src)[SIZE])
{
	DoSomeByIndex<T, Types::size_t{ 0 }, SIZE>::copy(dest, src);
}

template<typename T, Types::size_t SIZE>
CompareResult compare(const T (& arr1)[SIZE], const T (& arr2)[SIZE])
{
	return DoSomeByIndex<T, Types::size_t{ 0 }, SIZE>::compare(arr1, arr2);
}

} // namespace anonymous

Date::Date() noexcept : Parent{}
{
	constexpr YearType initYear = {'1', '9', '0', '0'};
	constexpr MonthType initMonth = {'0', '1'};
	constexpr DayType initDay = {'0', '1'};

	copy(year, initYear);
	copy(month, initMonth);
	copy(day, initDay);
}

Date::Date(const Parent &cryptokiDate) noexcept : Parent{}
{
	copy(year, cryptokiDate.year);
	copy(month, cryptokiDate.month);
	copy(day, cryptokiDate.day);
}

Date::Date(const YearType &initYear, const MonthType &initMonth
		, const DayType &initDay) noexcept : Parent{}
{
	copy(year, initYear);
	copy(month, initMonth);
	copy(day, initDay);
}

bool Date::operator==(const Date &date) noexcept
{
	return (CompareResult::EQUAL == compare(year, date.year)
			&& CompareResult::EQUAL == compare(month, date.month)
			&& CompareResult::EQUAL == compare(day, date.day));
}

bool Date::operator<(const Date &date) noexcept
{
	return (CompareResult::LESS == compare(year, date.year))
			|| (
					CompareResult::EQUAL == compare(year, date.year)
					&& CompareResult::LESS == compare(month, date.month)
			)
			|| (
					CompareResult::EQUAL == compare(year, date.year)
					&& CompareResult::EQUAL == compare(month, date.month)
					&& CompareResult::LESS == compare(day, date.day)
			);
}

bool Date::operator>(const Date &date) noexcept
{
	return (CompareResult::MORE == compare(year, date.year))
			|| (
					CompareResult::EQUAL == compare(year, date.year)
					&& CompareResult::MORE == compare(month, date.month)
			)
			|| (
					CompareResult::EQUAL == compare(year, date.year)
					&& CompareResult::EQUAL == compare(month, date.month)
					&& CompareResult::MORE == compare(day, date.day)
			);
}

bool Date::operator>=(const Date &date) noexcept
{
	return operator==(date) || operator>(date);
}

bool Date::operator<=(const Date &date) noexcept
{
	return operator==(date) || operator<(date);
}

} // namespace pkcs11
} // namespace flame_ide
