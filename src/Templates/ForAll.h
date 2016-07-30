#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

#include <Others/PrimitiveTypes.h>

namespace flame_ide
{namespace templates
{

using namespace flame_ide::types::primitive;

struct TypeTraits
{
	typedef flame_ide::types::primitive::char_t   char_t;
	typedef flame_ide::types::primitive::short_t  short_t;
	typedef flame_ide::types::primitive::int_t    int_t;
	typedef flame_ide::types::primitive::long_t   long_t;
	typedef flame_ide::types::primitive::llong_t  llong_t;
	
	typedef flame_ide::types::primitive::uchar_t   uchar_t;
	typedef flame_ide::types::primitive::ushort_t  ushort_t;
	typedef flame_ide::types::primitive::uint_t    uint_t;
	typedef flame_ide::types::primitive::ullong_t  ullong_t;
	
	typedef flame_ide::types::primitive::size_t size_t;
	typedef flame_ide::types::primitive::ptr_t  ptr_t;
};

typedef TypeTraits TT;

template<typename T>
struct RemoveReference
{
	typedef T type;
};

template<typename T>
struct RemoveReference<T&>
{
	typedef T type;
};

template<typename T>
struct RemoveReference<T&&>
{
	typedef T type;
};

template<typename T>
struct Traits
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<T&>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<T&&>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<const T>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<const T&>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<T *>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<const T *>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

template<typename T>
struct Traits<T * const>
{
	typedef T          type;
	
	typedef T       &  reference;
	typedef T       && move_reference;
	typedef T const &  const_reference;
	
	typedef T       *  pointer;
	typedef T const *  const_pointer;
};

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
struct ObjectBytes
{
	union Bytes
	{
		Tt *r_obj;
		uchar_t *array;
		
		Bytes() : r_obj(nullptr) {}

		Bytes(Bytes &&) = delete;
		Bytes(Bytes const &) = delete;
		
		Bytes(Tt * p_obj)     : r_obj(p_obj) {}
	} bytes;
	
	static const unsigned long SIZE = sizeof(Tt);
	
	ObjectBytes() : bytes() {}
	
	ObjectBytes(ObjectBytes &&) = delete;
	ObjectBytes(ObjectBytes const &) = delete;
	
	ObjectBytes(Tt * p_obj)     : bytes(p_obj) {}
	ObjectBytes(Tt & obj)       : bytes(&obj) {}
	
	void nulling()
	{
		unsigned char *& ref_iterator = bytes.array;
		for(unsigned long i = 0; i < SIZE; ++i)
		{
			ref_iterator[i] = 0;
		}
	}
};

template<typename Tt>
inline constexpr bool is_primitive_type();

template<typename Tt1, typename Tt2>
inline constexpr bool is_same_types() noexcept;


template<typename T> constexpr
typename RemoveReference<T>::type&& move(T &&reference) noexcept;

template<class T> inline
T&& foward(T &&reference) noexcept;

// obj_input and obj_output not using!
template<typename TIteratorInput, typename TIteratorOutput>
void copy(TIteratorInput start, TIteratorInput end,
          TIteratorOutput out);
template<typename TIteratorInput, typename TIteratorOutput>
void copy_n(TIteratorInput start, TIteratorInput end,
          TIteratorOutput out);

template<typename TIterator>
flame_ide::types::primitive::ulong_t
count_iterations(const TIterator &start, const TIterator &end);

template<typename T>
void placement_new(T * const addr, const T & obj);

template<typename T>
void placement_new(T * const addr, T && obj);

template<typename TIterator1 , typename TIterator2>
bool is_equal(const TIterator1 &start1, const TIterator1 &end1,
              const TIterator2 &start2, const TIterator2 &end2);

}}

template<typename Tt> inline constexpr
bool flame_ide::templates::
is_primitive_type()
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
is_same_types() noexcept
{
	return (ComparingTypes<Tt1, Tt2>::IS_SAME);
}

template<typename T>
constexpr
typename flame_ide::templates::RemoveReference<T>::type&&
flame_ide::templates::
move(T &&reference) noexcept
{
	return static_cast<typename RemoveReference<T>::type&&>(reference);
}

template<class T>
T&& flame_ide::templates::
foward(T &&reference) noexcept
{
	return static_cast<T &&>(reference);
}

template<typename TIteratorInput, typename TIteratorOutput>
void flame_ide::templates::
copy(TIteratorInput start, TIteratorInput end,
     TIteratorOutput out)
{
	for(auto iterator = start; iterator != end; ++iterator, ++out)
	{
		*out = *iterator;
	}
}

template<typename TIterator>
flame_ide::types::primitive::ulong_t
flame_ide::templates::
count_iterations(const TIterator &start, const TIterator &end)
{
	unsigned long count = 0;
	for(auto iterator = start; iterator != end; ++iterator, ++count)
	{}
	
	return count;
}

template<typename T>
void flame_ide::templates::
placement_new(T * const addr, const T &obj)
{
	new (addr) T(obj);
}

template<typename T>
void flame_ide::templates::
placement_new(T * const addr, T && obj)
{
	new (addr) T(move(obj));
}

//#include <iostream>
template<typename TIterator1, typename TIterator2>
bool flame_ide::templates::
is_equal(const TIterator1 &start1, const TIterator1 &end1,
         const TIterator2 &start2, const TIterator2 &end2)
{
	bool b_is_equal = true;
	auto iterator1 = start1;
	auto iterator2 = start2;
	
	for(; iterator1 != end1 && iterator2 != end2 && b_is_equal; ++iterator1, ++iterator2)
	{
		b_is_equal = (b_is_equal && *iterator1 == *iterator2);
	}
	
	if(iterator1 == end1)
	{
		if(iterator2 == end2)
		{
			return b_is_equal;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
	return b_is_equal;
}

#endif // TEMPLATES_FOR_ALL
