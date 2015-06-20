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
{}

JSON::
Array::Array(const Array &array)
	: Array()
{}

JSON::
Array::Array(const std::string &json_array)
	: Array()
{
	
}

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
Array::pushBack(const Data *data)
{
	switch (data->getType())
	{
	case SINGLE:
		
		break;
	case PAIR:
		
		break;
	case ARRAY:
		
		break;
	case OBJECT:
		
		break;
	default:
		break;
	}
}

void
JSON::
Array::pushFront(const Data *data)
{
	switch (data->getType())
	{
	case SINGLE:
		
		break;
	case PAIR:
		
		break;
	case ARRAY:
		
		break;
	case OBJECT:
		
		break;
	default:
		break;
	}
}

void
JSON::
Array::insert(const size_t &index, const Data *data)
{
	switch (data->getType())
	{
	case SINGLE:
		
		break;
	case PAIR:
		
		break;
	case ARRAY:
		
		break;
	case OBJECT:
		
		break;
	default:
		break;
	}
}

void 
JSON::
Array::insert(const size_t &index, const size_t &count, const Data **data)
{
	for(size_t i = 0; i < count; i++)
	{
		switch (data[i]->getType())
		{
		case SINGLE:
			
			break;
		case PAIR:
			
			break;
		case ARRAY:
			
			break;
		case OBJECT:
			
			break;
		default:
			break;
		}
	}
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
	if(!( getDataType(json_array) == ARRAY ))
	{ return; }
	
	templates::Array<std::string> arr_json_str = split(json_array);
	size_t length = arr_json_str.getLength();
	
	this->arr.setLength(length);
	
	for(size_t i = 0; i < length; i++)
	{
		Data *data = getData(arr_json_str[i]);
		
		if(data != nullptr)
		{ arr[i] = data; }
	}
}
