#include "JSON.h"

#include "../Templates/List.h"

using namespace flame_ide;

JSON::
Array::Array()
	: JSON::DataContainer(0, 1)
{}

JSON::
Array::~Array()
{
	
}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return arr[index];
}

void
JSON::
Array::pushBack(Data *data)
{
	
}

void
JSON::
Array::pushFront(Data *data)
{
	
}

void
JSON::
Array::insert(const size_t &index, Data *data)
{
	
}

void 
JSON::
Array::insert(const size_t &index, const size_t &count, Data **data)
{
	
}

void
JSON::
Array::popBack()
{
	
}

void
JSON::
Array::popFront()
{
	
}

void
JSON::
Array::erase(const size_t &index)
{

}

void
JSON::
Array::erase(const size_t &index, const size_t &count)
{
	
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
