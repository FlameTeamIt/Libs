#ifndef WSTRING_H
#define WSTRING_H

#include "String_TString.h"

namespace flame_ide
{namespace templates
{

class WString : public TString<wchar_t>
{
public:
	WString();
	WString(const wchar_t *);
	
	~WString();
	
	WString& operator+(const wchar_t *c_str);
	WString& operator+(const WString& string);
	
	WString& operator+=(const wchar_t *c_str);
	WString& operator+=(const WString& string);
	
	bool operator==(const wchar_t *c_str);
	bool operator==(const WString& string);
	
	bool operator!=(const wchar_t *c_str);
	bool operator!=(const WString& string);
};

}}

using namespace flame_ide::templates;

WString::WString()
	: TString<wchar_t>()
{}

WString::WString(const WString &wstring)
	: TString<wchar_t>(static_cast<const TString<wchar_t>&>(wstring))
{}

WString::~WString()
{}


#endif // WSTRING_H

