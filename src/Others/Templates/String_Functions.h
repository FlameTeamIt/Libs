#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

#include <cstring>
#include <algorithm>

namespace flame_ide
{namespace templates
{

template<typename Tt>
Tt* string_add<Tt>(size_t length_first, Tt* str_first
				 ,size_t length_last, Tt* str_last);


template<typename Tt>
Tt* string_get_substr<Tt>(size_t length_str, Tt* str
						,size_t pos, size_t length);

}}


#endif // STRING_FUNCTIONS

