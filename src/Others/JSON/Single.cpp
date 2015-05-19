#include "JSON.h"

using namespace flame_ide::JSON;

Single::Single()
	: JSON::Data(0, 0, 1)
{}

Single::Single(const JSON::Single& single)
	: JSON::Data(0, 0, 1)
{
	this->str_data = single.str_data;
}

Single::Single(const std::string& value)
	: JSON::Single()
{	this->str_data = value;}


Single::~Single() {}

const Single &
Single::operator =(const JSON::Single &single)
{
	this->str_data = single.str_data;
	return *this;
}

std::string
Single::getAsString()
{	return this->str_data;}

void
Single::setAsString(const std::string &json_single)
{	str_data = json_single;}
