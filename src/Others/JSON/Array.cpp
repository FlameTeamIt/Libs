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
	size_t &&array_length = array.arr.getLength();
	
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
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	arr.pushBack(new_data);
}

void
JSON::
Array::pushFront(const Data *data)
{
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	arr.pushFront(new_data);
}

void
JSON::
Array::insert(const size_t &index, const Data *data)
{
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	arr.insert(index, new_data);
}

void 
JSON::
Array::insert(const size_t &index, const size_t &count, const Data **data)
{
	Data *new_data[count];
	for(size_t i = 0; i < count; i++)
	{
		new_data[i] = data[i]->getCopy();
		new_data[i]->setLevel(this->level+1);
	}
	
	arr.insert(index, count, new_data);
}

void
JSON::
Array::popBack()
{
	delete arr[arr.getLength()-1];
	arr.popBack();
}

void
JSON::
Array::popFront()
{
	delete arr[0];
	arr.popFront();
}

void
JSON::
Array::erase(const size_t &index)
{
	if(index > arr.getLength()) return;
	delete arr[index];
	
	arr.erase(index);
}

void
JSON::
Array::erase(const size_t &index, const size_t &count)
{
	size_t max = index+count;
	if(max > arr.getLength()) return;
	for(size_t i = index; i < max; i++)
	{
		delete arr[i];
	}
	
	arr.erase(index, count);
}

void
JSON::
Array::clear()
{
	size_t length = arr.getLength();
	for(size_t i = 0; i < length; i++)
	{
		delete arr[i];
	}
	
	arr.clear();
}

JSON::Data*
JSON::
Array::getCopy() const
{
	return new Array(*this);
}

std::string
JSON::
Array::getAsString() const
{
	std::string out_json_str("[");
	size_t &&length = arr.getLength();
	
	// пока без форматирования
	if(length)
	{
		length--;
		
		for(size_t i = 0; i < length; i++)
		{
			if(arr[i]->getType() == PAIR)
			{ out_json_str += '{' + arr[i]->getAsString() + '}'; }
			else
			{ out_json_str += arr[i]->getAsString(); }
				
			out_json_str += ",";
		}
		
		if(arr[length]->getType() == PAIR)
		{ out_json_str += '{' + arr[length]->getAsString() + '}'; }
		else
		{ out_json_str += arr[length]->getAsString(); }
	}
	
	out_json_str += "]";
	
	return out_json_str;
}

void
JSON::
Array::setAsString(const std::string &json_array)
{
	if(getDataType(json_array) != ARRAY)
	{ return; }
	
	templates::Array<std::string> &&arr_json_str = split(json_array);
	size_t &&length = arr_json_str.getLength();
	
	for(size_t i = 0; i < length; i++)
	{
		Data *data = getData(arr_json_str[i]);
		
		if(data != nullptr)
		{ arr.pushBack(data); }
	}
}
