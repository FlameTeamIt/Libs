#ifndef STRING
#define STRING

#include "String_TString.h"

namespace flame_ide
{namespace templates
{

typedef TString<char> ParentCharStr;

class String : TString<char>
{
protected:
	size_t getCStrLength(const char* c_str) const;
	
public:
	String();
	String(const char* c_str);
	String(const String &str);
	
	~String();
};

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

#endif // STRING
