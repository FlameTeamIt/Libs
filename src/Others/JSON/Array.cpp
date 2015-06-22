#include "JSON.h"

#include "../Templates/List.h"

using namespace flame_ide;

JSON::
Array::Array()
	: JSON::DataContainer(0, 1)
{}

JSON::
Array::Array(const Data *data)
	: Array()
{
	if(data->getType() == ARRAY)
	{ Array(*((Array*)data)); }
}

JSON::
Array::Array(const Array &array)
	: Array()
{
	JSON::Data* temp_data;
	size_t array_length = array.arr.getLength();
	
	for(size_t i = 0; i < array_length; ++i)
	{
		temp_data = array.arr[i]->getCopy();
		arr.pushBack(temp_data);
	}
}

JSON::
Array::Array(const std::string &json_array)
	: Array()
{
	this->setAsString(json_array);
}

JSON::
Array::~Array()
{
	for(size_t i = 0, arr_length = arr.getLength();
		i < arr_length;
		++i)
	{ delete arr[i]; }
	
	arr.clear();
}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return arr[index];
}

void
JSON::
Array::setSize(const size_t &new_size)
{
	arr.setLength(new_size);
}

size_t
JSON::
Array::getSize()
{
	return arr.getLength();
}

void
JSON::
Array::pushBack(const Data *data)
{
}

void
JSON::
Array::pushFront(const Data *data)
{
}

void
JSON::
Array::insert(const size_t &index, const Data *data)
{
}

void 
JSON::
Array::insert(const size_t &index, const size_t &count, const Data **data)
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

JSON::Data*
JSON::
Array::getCopy() const
{
	return nullptr;
}

std::string
JSON::
Array::getAsString() const
{
	std::string out_json_str("[");
	size_t length = arr.getLength()-1;
	
	// пока без форматирования
	for(size_t i = 0; i < length; i++)
	{
		out_json_str += arr[i]->getAsString();
		out_json_str += ",";
	}
	out_json_str += arr[length]->getAsString();
	out_json_str += "]";
	
	return out_json_str;
}

void
JSON::
Array::setAsString(const std::string &json_array)
{
	if(getDataType(json_array) != ARRAY)
	{ return; }
	
	templates::Array<std::string> arr_json_str = split(json_array);
	size_t length = arr_json_str.getLength();
	
	for(size_t i = 0; i < length; i++)
	{
		Data *data = getData(arr_json_str[i]);
		
		if(data != nullptr)
		{ arr.pushBack(data); }
	}
}
