#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

namespace flame_ide

{namespace templates
{

template<typename Tt1, typename Tt2>
struct ComparingTypes
{
	static const bool IS_SAME = false;
};

template<typename Tt>
struct ComparingTypes<Tt, Tt>
{
	static const bool IS_SAME = true;
};

template<typename Tt>
struct TypeSize
{
	union Bytes
	{
		Tt &r_obj;
		unsigned char array[sizeof(Tt)];
		
		Bytes() = delete;
		Bytes(Bytes &&) = delete;
		Bytes(Bytes const &) = delete;
		
		Bytes(Tt * p_obj)     : r_obj(*p_obj) {}
		Bytes(Tt const & obj) : r_obj(obj)    {}
	} bytes;
	
	const unsigned long SIZE;
	
	TypeSize() = delete;
	TypeSize(TypeSize &&) = delete;
	TypeSize(TypeSize const &) = delete;
	
	TypeSize(Tt * p_obj)     : SIZE(sizeof(Tt)), bytes(p_obj) {}
	TypeSize(Tt const & obj) : SIZE(sizeof(Tt)), bytes(obj) {}
};

template<typename Tt>
inline constexpr bool is_preemptive_type();

template<typename Tt1, typename Tt2>
inline constexpr bool is_same_types();

template<class T> inline
T&& move(T &reference) noexcept;
template<class T> inline
T&& move(const T &reference) noexcept;

template<class T> inline
const T& not_move(T &&reference) noexcept;

// obj_input and obj_output not using!
template<typename TIteratorInput, typename TIteratorOutput,
         typename TInput, typename TOutput>
void copy(const TIteratorInput &start, const TIteratorInput &end,
                TIteratorOutput &out,
          const TInput &obj_input /*= *start*/, const TOutput &obj_output /*= *out*/);
template<typename TIteratorInput, typename TIteratorOutput,
         typename TInput, typename TOutput>
void copy(TIteratorInput &&start, TIteratorInput &&end,
          TIteratorOutput &out,
          TInput &obj_input /*= *start*/, TOutput &obj_output /*= *out*/);

template<typename TIterator>
unsigned long count_iterations(const TIterator &start, const TIterator &end);

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
	
	typedef ComparingTypes<Tt, char> Type_char;
	typedef ComparingTypes<Tt, unsigned_char> Type_unsigned_char;
	
	typedef ComparingTypes<Tt, short> Type_short;
	typedef ComparingTypes<Tt, unsigned_short> Type_unsigned_short;
	
	typedef ComparingTypes<Tt, int> Type_int;
	typedef ComparingTypes<Tt, unsigned_int> Type_unsigned_int;
	
	typedef ComparingTypes<Tt, float> Type_float;
	
	typedef ComparingTypes<Tt, long> Type_long;
	typedef ComparingTypes<Tt, unsigned_long> Type_unsigned_long;

	typedef ComparingTypes<Tt, llong> Type_llong;
	typedef ComparingTypes<Tt, unsigned_llong> Type_unsigned_llong;
	
	typedef ComparingTypes<Tt, double> Type_double;
	
	return (Type_char::IS_SAME  || Type_unsigned_char::IS_SAME
	     || Type_short::IS_SAME || Type_unsigned_short::IS_SAME
	     || Type_int::IS_SAME   || Type_unsigned_int::IS_SAME
	     || Type_long::IS_SAME  || Type_unsigned_long::IS_SAME
	     || Type_llong::IS_SAME || Type_unsigned_llong::IS_SAME
	     || Type_float::IS_SAME || Type_double::IS_SAME);
}

template<typename Tt1, typename Tt2> inline constexpr
bool flame_ide::templates::
is_same_types()
{
	return (ComparingTypes<Tt1, Tt2>::IS_SAME);
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

template<class T>
const T& flame_ide::templates::
not_move(T &&reference) noexcept
{
	return static_cast<const T &>(reference);
}

template<typename TIteratorInput, typename TIteratorOutput,
         typename TInput,         typename TOutput>
void flame_ide::templates::
copy(const TIteratorInput &start, const TIteratorInput &end,
           TIteratorOutput &out,
     const TInput &, const TOutput &)
{
	if(is_same_types<TInput, TOutput>)
	for(auto iterator = start; iterator != end; ++iterator, ++out)
	{
		new (out.operator ->()) TInput(*iterator);
	}
}

template<typename TIteratorInput, typename TIteratorOutput,
         typename TInput,         typename TOutput>
void flame_ide::templates::
copy(TIteratorInput &&start, TIteratorInput &&end,
     TIteratorOutput &out,
     TInput &, TOutput &)
{
	if(is_same_types<TInput, TOutput>)
	for(auto iterator = start; iterator != end; ++iterator, ++out)
	{
		new (out.operator ->()) TInput(move(*iterator));
	}
}

template<typename TIterator>
unsigned long flame_ide::templates::
count_iterations(const TIterator &start, const TIterator &end)
{
	unsigned long count = 0;
	for(auto iterator = start; iterator != end; ++iterator, ++count)
	{}
	
	return count;
}

#endif // TEMPLATES_FOR_ALL
