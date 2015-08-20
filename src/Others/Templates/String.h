#ifndef STRING
#define STRING

#define MAX_BUFFER_COUNT 1024

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
	if(str.getSize())
	{
		str.clear();
	}
	
	unsigned int buffer_count = 0;
	char buffer_c_str[MAX_BUFFER_COUNT];
	for(size_t i = 0; i < MAX_BUFFER_COUNT; i++)
	{
		buffer_c_str[i] = '\0';
	}
	
	input_stream.get(buffer_c_str[buffer_count]);
	while((buffer_c_str[buffer_count] != '\n')
		   || (buffer_c_str[buffer_count] != ' '))
	{
		buffer_count++;
		if(buffer_count == MAX_BUFFER_COUNT)
		{
			str += buffer_c_str;
			for(size_t i = 0; i < MAX_BUFFER_COUNT; i++)
			{
				buffer_c_str[i] = '\0';
			}
			buffer_count = 0;
		}
		
		input_stream.get(buffer_c_str[buffer_count]);
	}
	buffer_c_str[buffer_count] = '\0';
	
	str += buffer_c_str;
	
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
