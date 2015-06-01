#include "JSON.h"

#include "../Templates/List.h"

using namespace flame_ide;

JSON::
Array::Array()
	: JSON::DataContainer(0, 1)
{}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return arr[index];
}

std::string
JSON::
Array::getAsString() const
{
	return std::string("[]");
}

void
JSON::
Array::setAsString(const std::string &json_array)
{
	unsigned int count_array_braces; // []
	unsigned int count_object_braces; // {}
	unsigned int count_string_braces; // "
	templates::List<char> char_list;
}
