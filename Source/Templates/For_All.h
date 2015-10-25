#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

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
constexpr bool is_preemptive_type();

}}

template<typename Tt>
constexpr bool
flame_ide::templates::is_preemptive_type()
{
	typedef unsigned char u_char;
	typedef unsigned short u_short;
	typedef unsigned int u_int;
	typedef unsigned long u_long;
	
	typedef Types<Tt, char> Type_char;
	typedef Types<Tt, u_char> Type_u_char;
	
	typedef Types<Tt, short> Type_short;
	typedef Types<Tt, u_short> Type_u_short;
	
	typedef Types<Tt, int> Type_int;
	typedef Types<Tt, u_int> Type_u_int;
	
	typedef Types<Tt, float> Type_float;
	
	typedef Types<Tt, long> Type_long;
	typedef Types<Tt, u_long> Type_u_long;

	typedef Types<Tt, double> Type_double;
	
	return (Type_char::isSame || Type_u_char::isSame
		|| Type_short::isSame || Type_u_short::isSame
		|| Type_int::isSame   || Type_u_int::isSame
		|| Type_long::isSame  || Type_u_long::isSame
		|| Type_float::isSame || Type_double::isSame);
}

#endif // FOR_ALL

