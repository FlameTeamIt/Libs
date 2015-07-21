#ifndef STRING
#define STRING

#include "Array.h"
#include "String_Functions.h"

namespace flame_ide
{namespace templates
{

class String : public Array<char>
{
	using Array<wchar_t>::inc_arr;
	using Array<wchar_t>::arr_size;
public:
	String();
	String(const char *);
	
	String& operator+=(const char *c_str);
	String& operator+=(const String& string);
	
	String& operator+(const char *c_str);
	String& operator+(const String& string);
};

class WString : public Array<wchar_t>
{
	using Array<wchar_t>::inc_arr;
	using Array<wchar_t>::arr_size;
public:
	WString();
	WString(const wchar_t *);
	
	WString& operator+=(const wchar_t *c_str);
	WString& operator+=(const WString& string);
	
	WString& operator+(const wchar_t *c_str);
	WString& operator+(const WString& string);
};

}}

#endif // STRING
