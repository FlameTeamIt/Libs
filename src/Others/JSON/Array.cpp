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
	const size_t &array_length = array.inc_arr.getSize();
	this->inc_arr = array.inc_arr;
	
	for(size_t i = 0; i < array_length; ++i)
	{
		this->inc_arr[i] = array.inc_arr[i]->getCopy();
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
	for(size_t i = 0, arr_length = inc_arr.getSize();
		i < arr_length;
		++i)
	{ delete inc_arr[i]; }
	
	inc_arr.clear();
}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return inc_arr[index];
}

void
JSON::
Array::setSize(const size_t &new_size)
{
	inc_arr.setSize(new_size);
}

size_t
JSON::
Array::getSize()
{
	return inc_arr.getSize();
}

void
JSON::
Array::pushBack(const Data *data)
{
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	inc_arr.pushBack(new_data);
}

void
JSON::
Array::pushFront(const Data *data)
{
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	inc_arr.pushFront(new_data);
}

void
JSON::
Array::insert(const size_t &index, const Data *data)
{
	Data *new_data = data->getCopy();
	new_data->setLevel(this->level+1);
	
	inc_arr.insert(index, new_data);
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
	
	inc_arr.insert(index, count, new_data);
}

void
JSON::
Array::popBack()
{
	delete inc_arr[inc_arr.getSize()-1];
	inc_arr.popBack();
}

void
JSON::
Array::popFront()
{
	delete inc_arr[0];
	inc_arr.popFront();
}

void
JSON::
Array::erase(const size_t &index)
{
	if(index > inc_arr.getSize()) return;
	delete inc_arr[index];
	
	inc_arr.erase(index);
}

void
JSON::
Array::erase(const size_t &index, const size_t &count)
{
	size_t max = index+count;
	if(max > inc_arr.getSize()) return;
	for(size_t i = index; i < max; i++)
	{
		delete inc_arr[i];
	}
	
	inc_arr.erase(index, count);
}

void
JSON::
Array::clear()
{
	size_t length = inc_arr.getSize();
	for(size_t i = 0; i < length; i++)
	{
		delete inc_arr[i];
	}
	
	inc_arr.clear();
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
	size_t &&length = inc_arr.getSize();
	
	// пока без форматирования
	if(length)
	{
		length--;
		
		for(size_t i = 0; i < length; i++)
		{
			if(inc_arr[i]->getType() == PAIR)
			{ out_json_str += '{' + inc_arr[i]->getAsString() + '}'; }
			else
			{ out_json_str += inc_arr[i]->getAsString(); }
				
			out_json_str += ",";
		}
		
		if(inc_arr[length]->getType() == PAIR)
		{ out_json_str += '{' + inc_arr[length]->getAsString() + '}'; }
		else
		{ out_json_str += inc_arr[length]->getAsString(); }
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
	const size_t &length = arr_json_str.getSize();
	inc_arr.setSize(length);
	
	for(size_t i = 0; i < length; i++)
	{
		Data *data = getData(arr_json_str[i]);
		
		if(data != nullptr)
		{ inc_arr[i] = data; }
		
	}
}
