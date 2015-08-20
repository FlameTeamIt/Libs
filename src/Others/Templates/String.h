#ifndef STRING
#define STRING

#include <string.h>
#include <wchar.h>

#include "String_TString.h"

namespace flame_ide
{namespace templates
{

typedef TString<char> ParentCharStr;

class String : public TString<char>
{
public:
	inline size_t getCStrLength(const char* c_str) const;
	
public:
	String();
	String(const char* c_str);
	String(const String &str);
	
	inline String& operator =(const char *c_tstr);
	inline String& operator =(const String& tstring);
	inline String& operator +=(const char *c_tstr);
	inline String& operator +=(const String& tstring);
	
	// output and input
	friend
	std::ostream& operator<<(std::ostream &output_stream,
							  const String &str);
	friend
	std::istream& operator>>(std::istream &input_stream,
							  String &str);
	
	~String();
};

std::ostream& operator<<(std::ostream &output_stream,
						  const String &str)
{
	for(size_t i = 0; i < str.getSize(); ++i)
	{
		output_stream << str.at(i);
	}
	return output_stream;
}

std::istream& operator>>(std::istream &input_stream,
						  String &str)
{
	char *tmp_c_str;
	
	input_stream >> tmp_c_str;
	
	return input_stream;
}

}}

using namespace flame_ide::templates;

// constructors and destructor

String::String()
	: ParentCharStr()
{}
String::String(const char *c_str)
	: TString<char>(getCStrLength(c_str), c_str)
{}
String::String(const String &str)
	: ParentCharStr(static_cast<const ParentCharStr &>(str))
{}

String::~String()
{}

// methods

size_t
String::getCStrLength(const char *c_str) const
{
	return strlen(c_str);
}

// operators

String& 
String::operator =(const char *c_str)
{
	this->assign(c_str);
	return *this;
}

String&
String::operator =(const String& string)
{
	this->assign(string);
	return *this;
}

String& 
String::operator +=(const char *c_str)
{
	this->concatenation(c_str);
	return *this;
}

String&
String::operator +=(const String& string)
{
	this->concatenation(string);
	return *this;
}

#endif // STRING
