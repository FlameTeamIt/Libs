#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

typedef unsigned long size_t;

namespace flame_ide
{namespace templates
{

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

template<typename TIteratorInput, typename TIteratorOutput>
void copy(const TIteratorInput &start, const TIteratorInput &end,
                TIteratorOutput &out);

}}

template<typename Tt> inline constexpr
bool
flame_ide::templates::is_preemptive_type()
{
	typedef unsigned char u_char;
	typedef unsigned short u_short;
	typedef unsigned int u_int;
	typedef unsigned long u_long;
	
	typedef long long llong;
	typedef unsigned long long u_llong;
	
	typedef Types<Tt, char> Type_char;
	typedef Types<Tt, u_char> Type_u_char;
	
	typedef Types<Tt, short> Type_short;
	typedef Types<Tt, u_short> Type_u_short;
	
	typedef Types<Tt, int> Type_int;
	typedef Types<Tt, u_int> Type_u_int;
	
	typedef Types<Tt, float> Type_float;
	
	typedef Types<Tt, long> Type_long;
	typedef Types<Tt, u_long> Type_u_long;

	typedef Types<Tt, llong> Type_llong;
	typedef Types<Tt, u_llong> Type_u_llong;
	
	typedef Types<Tt, double> Type_double;
	
	return (Type_char::isSame  || Type_u_char::isSame
	     || Type_short::isSame || Type_u_short::isSame
	     || Type_int::isSame   || Type_u_int::isSame
	     || Type_long::isSame  || Type_u_long::isSame
	     || Type_llong::isSame || Type_u_llong::isSame
	     || Type_float::isSame || Type_double::isSame);
}

template<typename Tt1, typename Tt2> inline constexpr
bool
flame_ide::templates::is_same_types()
{
	return (Types<Tt1, Tt2>::isSame);
}

template<class T>
T&& flame_ide::templates::
move(T &reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename TIteratorInput, typename TIteratorOutput, typename T>
void flame_ide::templates::
copy(const TIteratorInput &start, const TIteratorInput &end,
     TIteratorOutput &out)
{
	// нужно:
	// От входных итераторов -- реализованный оператор operator*()
	// От выходных итератора -- реализованный оператор operator*()
	
	for(auto it = start; it != end; ++it)
	{
		out.operator*().~T(); // спорно. А вдруг ничего там нет.
		
		                      // надо разобраться, как это в stl реализовано,
		                      // а то это слишком упорото.
		
		new (out.operator->()) T(*it);
		++out;
	}
}

#endif // FOR_ALL
