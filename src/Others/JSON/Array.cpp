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
