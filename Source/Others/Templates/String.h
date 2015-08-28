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
	inline size_t getCStrLength(const char* c_str) const;
	
	using Array<char>::set;
	
public:
	String();
	String(const char* c_str);
	String(const String &str);
	
	String getSubstr(size_t pos, size_t length);
	const String getSubstr(size_t pos, size_t length) const;
	
	static inline unsigned long getHash(const char* c_tstr);
	unsigned long getHash() const;
	
	inline String& operator =(const char *c_tstr);
	inline String& operator =(const String& tstring);
	inline String& operator +=(const char *c_tstr);
	inline String& operator +=(const String& tstring);
	
	// concatenation
	friend String operator +(const char *c_tstr, const String& tstring);
	friend String operator +(const String& tstring, const char *c_tstr);
	friend String operator +(const String& tstring1, const String& tstring2);
	
	// equal
	friend bool operator ==(const char *c_tstr, const String& tstring);
	friend bool operator ==(const String& tstring, const char *c_tstr);
	friend bool operator ==(const String& tstring1, const String& tstring2);
	
	// not equal
	friend bool operator !=(const char *c_tstr, const String& tstring);
	friend bool operator !=(const String& tstring, const char *c_tstr);
	friend bool operator !=(const String& tstring1, const String& tstring2);
	
	// output and input
	friend
	std::ostream& operator<<(std::ostream &output_stream,
							  const String &str);
	friend
	std::istream& operator>>(std::istream &input_stream,
							  String &str);
	
	~String();
};

// concatenation
String
operator +(const char *c_tstr, const String& tstring)
{
	String tmp_str = tstring;
	tmp_str.concatenation(c_tstr, false);
	
	return tmp_str;
}
String
operator +(const String& tstring, const char *c_tstr)
{
	String tmp_str = tstring;
	tmp_str.concatenation(c_tstr);
	
	return tmp_str;
}
String
operator +(const String& tstring1, const String& tstring2)
{
	String tmp_str = tstring1;
	tmp_str.concatenation(tstring2);
	
	return tmp_str;
}

// equal
inline bool
operator ==(const char *c_tstr, const String& tstring)
{
	return tstring.is_equal(c_tstr);
}
inline bool
operator ==(const String& tstring, const char *c_tstr)
{
	return tstring.is_equal(c_tstr);
}
inline bool
operator ==(const String& tstring1, const String& tstring2)
{
	return tstring1.is_equal(tstring2);
}

// not equal
inline bool
operator !=(const char *c_tstr, const String& tstring)
{
	return tstring.is_not_equal(c_tstr);
}
inline bool
operator !=(const String& tstring, const char *c_tstr)
{
	return tstring.is_not_equal(c_tstr);
}
inline bool
operator !=(const String& tstring1, const String& tstring2)
{
	return tstring1.is_not_equal(tstring2);
}

std::ostream&
operator<<(std::ostream &output_stream,
		   const String &str)
{
	for(size_t i = 0; i < str.getSize(); ++i)
	{
		output_stream << str.at(i);
	}
	return output_stream;
}

std::istream&
operator>>(std::istream &input_stream,
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
		   && (buffer_c_str[buffer_count] != ' '))
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

String
String::getSubstr(size_t pos, size_t length)
{
	String str; str = "";
	if(pos + length < this->arr_size)
	{
		str.set(length, string_get_substr(this->inc_arr, pos, length));
	}
	
	return str;
}

const String
String::getSubstr(size_t pos, size_t length) const
{
	String str;
	if(pos + length < this->arr_size)
	{
		// leak -- double 'new char[length]'
		str = string_get_substr(this->inc_arr, pos, length);
	}
	
	return str;
}

unsigned long
String::getHash() const
{
	if(!is_actual_hash)
	{
		this->hash = 0;
		// FAQ6
		for (size_t i = 0; i < this->arr_size; i++)
		{
				this->hash += (unsigned char)(this->inc_arr[i]);
				this->hash += (this->hash << 10);
				this->hash ^= (this->hash >> 6);
		}
		this->hash += (this->hash << 3);
		this->hash ^= (this->hash >> 11);
		this->hash += (this->hash << 15);
		
		this->is_actual_hash = true;
	}
	
	return this->hash;
}

unsigned long
String::getHash(const char *c_str)
{
	size_t len_c_tstr = strlen(c_str);
	unsigned long hash = 0;
	// FAQ6
	for (size_t i = 0; i < len_c_tstr; i++)
	{
		hash += (unsigned char)(c_str[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	
	return hash;
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
