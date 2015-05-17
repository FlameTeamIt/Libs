#include "Array.h"

namespace flame_ide
{

JSON::
Array::Array()
	: JSON::Data(0, 1, 0)
{}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return &arr[index];
}

std::string
JSON::
Array::getAsString()
{
	return std::string("[]");
}

void
JSON::
Array::setAsString(const std::string &json_array)
{
	// парсинг вектора
}

}
