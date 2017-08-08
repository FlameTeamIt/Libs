#include <Templates/String.hpp>

/*
namespace flame_ide
{namespace templatess
{
// concatenation
String
operator +(char ch, const String& tstring)
{
	String tmp_str = tstring;
	tmp_str.pushFront(ch);

	return tmp_str;
}
String
operator +(const String& tstring, char ch)
{
	String tmp_str = tstring;
	tmp_str.pushBack(ch);

	return tmp_str;
}
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
bool
operator ==(const char *c_tstr, const String& tstring)
{
	return tstring.is_equal(c_tstr);
}
bool
operator ==(const String& tstring, const char *c_tstr)
{
	return tstring.is_equal(c_tstr);
}
bool
operator ==(const String& tstring1, const String& tstring2)
{
	return tstring1.is_equal(tstring2);
}

// not equal
bool
operator !=(const char *c_tstr, const String& tstring)
{
	return tstring.is_not_equal(c_tstr);
}
bool
operator !=(const String& tstring, const char *c_tstr)
{
	return tstring.is_not_equal(c_tstr);
}
bool
operator !=(const String& tstring1, const String& tstring2)
{
	return tstring1.is_not_equal(tstring2);
}

std::ostream&
operator<<(std::ostream &output_stream,
		   const String &str)
{
	for(size_t i = 0, length = str.getSize(); i < length; ++i)
	{
		output_stream << str.inc_arr[i];
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
	char buffer_c_str[String::_MAX_BUFFER_SIZE];
	for(size_t i = 0; i < String::_MAX_BUFFER_SIZE; i++)
	{
		buffer_c_str[i] = '\0';
	}

	input_stream.get(buffer_c_str[buffer_count]);
	while((buffer_c_str[buffer_count] != '\n')
		   && (buffer_c_str[buffer_count] != ' '))
	{
		buffer_count++;
		if(buffer_count == String::_MAX_BUFFER_SIZE)
		{
			str += buffer_c_str;
			for(size_t i = 0; i < String::_MAX_BUFFER_SIZE; i++)
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

// constructors and destructor

using namespace flame_ide::templates;

String::String()
	: TString<char>()
{}
String::String(const char *c_str)
	: TString<char>(getCStrLength(c_str), c_str)
{}
String::String(const String &str)
	: TString<char>(static_cast<const TString<char> &>(str))
{}

String::~String()
{}

// methods

size_t
String::getCStrLength(const char *c_str)
{
	return strlen(c_str);
}
size_t
String::getCStrLength(const char *c_str) const
{
	return strlen(c_str);
}

String
String::getSubstr(size_t pos, size_t length)
{
	String str;
	char *arr_ch = nullptr;
	if(pos + length < this->arr_size)
	{
		// leak -- double 'new char[length]'
		arr_ch = string_get_substr(this->inc_arr, pos, length);
		str = arr_ch;
	}

	return str;
}

String
String::getSubstr(size_t pos, size_t length) const
{
	String str;
	if(pos + length <= this->arr_size)
	{
		// leak -- double 'new char[length]'
		str.inc_arr = string_get_substr(this->inc_arr, pos, length);
		str.arr_size = length;
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

const String&
String::operator =(const char *c_str)
{
	this->assign(c_str);
	return *this;
}

const String&
String::operator =(char ch)
{
	this->pushBack(ch);
	return *this;
}

const String&
String::operator =(const String &string)
{
	this->assign(string);
	return *this;
}

const String&
String::operator =(String &&string)
{
	clear();
	this->inc_arr = string.inc_arr;
	this->arr_size = string.arr_size;

	string.arr_size = 0;

	return *this;
}

const String&
String::operator +=(const char *c_str)
{
	this->concatenation(c_str);
	return *this;
}

const String&
String::operator +=(char ch)
{
	this->pushBack(ch);
	return *this;
}

const String&
String::operator +=(const String &string)
{
	this->concatenation(string);
	return *this;
}

const String&
String::operator +=(String &&string)
{
	this->concatenation(string);
	string.clear();
	return *this;
}
*/
