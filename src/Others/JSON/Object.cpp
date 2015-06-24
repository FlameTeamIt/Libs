#include "JSON.h"

using namespace flame_ide;

JSON::
Object::Object()
	: JSON::DataContainer(1, 0)
{}

JSON::
Object::Object(const Data *data)
	: Object()
{
	if(data->getType() == OBJECT)
	{
		Object(*((Object*)data));
	}
}

JSON::
Object::Object(const Object &object)
	: Object()
{
	size_t &&length = object.arr.getLength();
	Pair *tmp_pair;
	
	for(size_t i = 0; i < length; i++)
	{
		tmp_pair = (Pair*)object.arr[i]->getCopy();
		this->arr.pushBack(tmp_pair);
	}
}

JSON::
Object::Object(const std::string &json_object)
	: Object()
{
	this->setAsString(json_object);
}

JSON::
Object::~Object() {}

void 
JSON::
Object::pushBack(const Data *data)
{
	if(data->getType() != PAIR)
	{ return; }
}

void
JSON::
Object::pushFront(const Data *data)
{
	if(data->getType() != PAIR)
	{ return; }
}

void
JSON::
Object::pushBack(const std::string &key, const Data *data)
{
	
}

void
JSON::
Object::pushFront(const std::string &key, const Data *data)
{
	
}

void
JSON::
Object::insert(const size_t &index, const Data *data)
{
	
}

void
JSON::
Object::insert(const size_t &index, const size_t &count, const Data **data)
{
	
}

void
JSON::
Object::popBack()
{
	
}

void
JSON::
Object::popFront()
{
	
}

void
JSON::
Object::erase(const size_t &index)
{
	
}

void
JSON::
Object::erase(const size_t &index, const size_t &count)
{
	
}

void
JSON::
Object::clear()
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
Object::getCopy() const
{
	return new Object(*this);
}

std::string
JSON::
Object::getAsString() const
{
	std::string out_json_str("{");
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
	
	out_json_str += "}";	
	
	return out_json_str;
}

void
JSON::
Object::setAsString(const std::string &json_object)
{
	if(getDataType(json_object) != OBJECT)
	{ return; }

	templates::Array<std::string> &&obj_json_str = split(json_object);
	size_t &&length = obj_json_str.getLength();
	
	for(size_t i = 0; i < length; i++)
	{
		if(getDataType(obj_json_str[i]) == PAIR)
		{
			Data *data = getData(obj_json_str[i]);
			if(data != nullptr)
			{ arr.pushBack((Pair*)data); }
		}
	}
}
