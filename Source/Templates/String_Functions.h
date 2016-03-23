#ifndef TEMPLATES_STRING_FUNCTIONS
#define TEMPLATES_STRING_FUNCTIONS

#include <algorithm>

#include "ForAll.h"


namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Tt* string_compose(const size_t &length_first, const Tt* str_first
				   ,const size_t &length_last, const Tt* str_last);


template<typename Tt> inline
Tt* string_get_substr(const Tt* str, const size_t &pos, const size_t &length);


//template<typename Tt> inline
//size_t get_cstr_len(const Tt* c_tstr)
//{
//		if(Types<char, Tt>::isSame)
//		{
//			return strlen(c_tstr);
//		} 
//		if(Types<wchar_t, Tt>::isSame)
//		{
//			return wcslen();
//		}
//}

//template<typename T>
//class StrLenFunc
//{
//	typedef	size_t(*FuncStrLength)(const T*);
//	FuncStrLength str_len;
//	inline FuncStrLength set()
//	{
//		if(Types<char, T>::isSame)
//		{
//			return &strlen;
//		} 
//		if(Types<wchar_t, T>::isSame)
//		{
//			return &wcslen;
//		}

//		return nullptr;
//	}
	
//public:
//	StrLenFunc() { str_len = set(); }
	
//	size_t operator ()(const T* c_tstr)
//	{
//		return str_len(c_tstr);
//	}
//};


}}

template<typename Tt>
Tt*
flame_ide::templates::
string_compose(const size_t &length_first, const Tt* str_first
			   ,const size_t &length_last, const Tt* str_last)
{
	Tt* result_str = new Tt[length_first + length_last]();
	
	std::copy_n(str_first, length_first, result_str);
	std::copy_n(str_last, length_last, result_str+length_first);
	
	return result_str;
}

template<typename Tt>
Tt*
flame_ide::templates::
string_get_substr(const Tt* str, const size_t &pos, const size_t &length)
{
	Tt* result_str = new Tt[length];
	
	std::copy_n(str+pos, length, result_str);
//	result_str[length] = NULL;
	
	return result_str;
}

// ---------------------------------------------

//typedef	size_t(*FuncStrLength_char)(const char*);
//typedef	size_t(*FuncStrLength_wchar)(const wchar_t*);

#endif // STRING_FUNCTIONS

