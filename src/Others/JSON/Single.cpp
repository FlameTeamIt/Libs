#include "Single.h"

namespace flame_ide
{

JSON::
Single::Single()
	: JSON::Data(0, 0, 1)
{}

JSON::
Single::Single(const std::string& value)
	: JSON::Single()
{	this->str = value;}


JSON::
Single::~Single() {}

std::string
JSON::
Single::getAsString()
{	return this->str;}

void
JSON::
Single::setAsString(const std::string &json_single)
{	str = json_single;}

}

