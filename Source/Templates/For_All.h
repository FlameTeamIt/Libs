#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

namespace flame_ide

{namespace templates
{

//typedef unsigned long size_t;

template<typename Tt1, typename Tt2>
struct Types
{
	enum { isSame = 0 };
};

template<typename Tt>
struct Types<Tt, Tt>
{
	enum { isSame = 1 };
};

template<typename Tt>
inline constexpr bool is_preemptive_type();

template<typename Tt1, typename Tt2>
inline constexpr bool is_same_types();

template<class T>
T&& move(T &reference) noexcept;
template<class T>
T&& move(const T &reference) noexcept;

template<typename TIteratorInput, typename TIteratorOutput>
void copy(const TIteratorInput &start, const TIteratorInput &end,
                TIteratorOutput &out);

}}

template<typename Tt> inline constexpr
bool
flame_ide::templates::is_preemptive_type()
{
	typedef unsigned char unsigned_char;
	typedef unsigned short unsigned_short;
	typedef unsigned int unsigned_int;
	typedef unsigned long unsigned_long;
	
	typedef long long llong;
	typedef unsigned long long unsigned_llong;
	
	typedef Types<Tt, char> Type_char;
	typedef Types<Tt, unsigned_char> Type_unsigned_char;
	
	typedef Types<Tt, short> Type_short;
	typedef Types<Tt, unsigned_short> Type_unsigned_short;
	
	typedef Types<Tt, int> Type_int;
	typedef Types<Tt, unsigned_int> Type_unsigned_int;
	
	typedef Types<Tt, float> Type_float;
	
	typedef Types<Tt, long> Type_long;
	typedef Types<Tt, unsigned_long> Type_unsigned_long;

	typedef Types<Tt, llong> Type_llong;
	typedef Types<Tt, unsigned_llong> Type_unsigned_llong;
	
	typedef Types<Tt, double> Type_double;
	
	return (Type_char::isSame  || Type_unsigned_char::isSame
	     || Type_short::isSame || Type_unsigned_short::isSame
	     || Type_int::isSame   || Type_unsigned_int::isSame
	     || Type_long::isSame  || Type_unsigned_long::isSame
	     || Type_llong::isSame || Type_unsigned_llong::isSame
	     || Type_float::isSame || Type_double::isSame);
}

template<typename Tt1, typename Tt2> inline constexpr
bool flame_ide::templates::
is_same_types()
{
	return (Types<Tt1, Tt2>::isSame);
}

template<class T>
T&& flame_ide::templates::
move(T &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<class T>
T&& flame_ide::templates::
move(const T &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename TIteratorInput, typename TIteratorOutput, typename T>
void flame_ide::templates::
copy(const TIteratorInput &start, const TIteratorInput &end,
     TIteratorOutput &out)
{
	// определение типа
	// а дальше поробуем скопировать побайтово.
}

#endif // TEMPLATES_FOR_ALL
