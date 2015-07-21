#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

#include <cstring>
#include <algorithm>

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Tt* string_compose<Tt>(const size_t &length_first, const Tt* &str_first
					   ,const size_t &length_last, const Tt* &str_last);


template<typename Tt> inline
Tt* string_get_substr<Tt>(const size_t &length_str, const Tt* &str
						  ,const size_t &pos, const size_t &length);

}}

template<typename Tt>
Tt*
flame_ide::templates::
string_compose(const size_t &length_first, const Tt* &str_first
			   ,const size_t &length_last, const Tt* &str_last)
{
	Tt* result_str = new Tt[length_first + length_last];
	
	std::copy_n(str_first, length_first, result_str);
	std::copy_n(str_last, length_last, result_str+length_first);
	
	return result_str;
}

template<typename Tt>
Tt*
flame_ide::templates::
string_get_substr(const size_t &length_str, const Tt* &str
				  ,const size_t &pos, const size_t &length)
{
	Tt* result_str = new Tt[length];
	
	std::copy_n(str+pos, length, result_str);
	
	return result_str;
}

#endif // STRING_FUNCTIONS

