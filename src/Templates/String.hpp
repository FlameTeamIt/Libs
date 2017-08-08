#ifndef TEMPLATES_STRING
#define TEMPLATES_STRING 1

//#warning Hello!

#ifndef MAX_BUFFER_COUNT
#define MAX_BUFFER_SIZE 1024
#endif
/*
#include <string.h>
#include <wchar.h>
#include <iostream>

#include <Templates/String_TString.hpp>

namespace flame_ide
{namespace templates
{

class String : public TString<char>
{
	size_t getCStrLength(const char* c_str);
	size_t getCStrLength(const char* c_str) const;

protected:
//	using TString<char>::concatenation;

//	using TString<char>::assign;
//	using TString<char>::is_equal;
//	using TString<char>::is_not_equal;

public:
	static const unsigned long _MAX_BUFFER_SIZE = MAX_BUFFER_SIZE;

	String();
	String(const char* c_str);
	String(const String &str);

	String getSubstr(size_t pos, size_t length);
	String getSubstr(size_t pos, size_t length) const;

	static unsigned long getHash(const char* c_tstr);
	unsigned long getHash() const;

	const String& operator =(const char *c_tstr);
	const String& operator =(char ch);
	const String& operator =(const String &tstring);
	const String& operator =(String &&tstring);
	const String& operator +=(const char *c_tstr);
	const String& operator +=(char ch);
	const String& operator +=(const String &tstring);
	const String& operator +=(String &&tstring);

	// concatenation
	friend String operator +(char ch, const String& tstring);
	friend String operator +(const String &tstring, char ch);
	friend String operator +(const char *c_tstr, const String& tstring);
	friend String operator +(const String &tstring, const char *c_tstr);
	friend String operator +(const String &tstring1, const String &tstring2);

	// equal
	friend bool operator ==(const char *c_tstr, const String &tstring);
	friend bool operator ==(const String& tstring, const char *c_tstr);
	friend bool operator ==(const String& tstring1, const String &tstring2);

	// not equal
	friend bool operator !=(const char *c_tstr, const String &tstring);
	friend bool operator !=(const String &tstring, const char *c_tstr);
	friend bool operator !=(const String &tstring1, const String &tstring2);

	// output and input
	friend
	std::ostream& operator <<(std::ostream &output_stream,
							  const String &str);
	friend
	std::istream& operator >>(std::istream &input_stream,
							  String &str);

	~String();
};

// concatenation
String operator +(char ch, const String& tstring);
String operator +(const String& tstring, char ch);
String operator +(const char *c_tstr, const String& tstring);
String operator +(const String& tstring, const char *c_tstr);
String operator +(const String& tstring1, const String& tstring2);

// equal
bool operator ==(const char *c_tstr, const String& tstring);
bool operator ==(const String& tstring, const char *c_tstr);
bool operator ==(const String& tstring1, const String& tstring2);

// not equal
bool operator !=(const char *c_tstr, const String& tstring);
bool operator !=(const String& tstring, const char *c_tstr);
bool operator !=(const String& tstring1, const String& tstring2);

// output and input
std::ostream& operator <<(std::ostream &output_stream,
						  const String &str);

std::istream& operator >>(std::istream &input_stream,
						  String &str);

}}

#undef MAX_BUFFER_SIZE
*/
#endif // TEMPLATES_STRING
