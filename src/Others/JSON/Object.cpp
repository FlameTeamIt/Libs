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
	const size_t &&length = object.inc_arr.getSize();
	this->inc_arr = object.inc_arr;
	
	for(size_t i = 0; i < length; i++)
	{
		inc_arr[i] = (Pair*)object.inc_arr[i]->getCopy();
		
//		tmp_pair = (Pair*)object.inc_arr[i]->getCopy();
//		this->inc_arr.pushBack(tmp_pair);
		// как вариант, засовывать массив.
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
	
	Pair *pair = (Pair*)data->getCopy();
	inc_arr.pushBack(pair);
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
	Pair *pair = new Pair(key, data);
	inc_arr.pushBack(pair);
}

void
JSON::
Object::pushFront(const std::string &key, const Data *data)
{
	Pair *pair = new Pair(key, data);
	inc_arr.pushFront(pair);
}

void
JSON::
Object::insert(const size_t &index, const Data *data)
{
//	if
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
	size_t length = inc_arr.getSize();
	for(size_t i = 0; i < length; i++)
	{
		delete inc_arr[i];
	}
	
	inc_arr.clear();
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
	size_t &&length = obj_json_str.getSize();
	
	for(size_t i = 0; i < length; i++)
	{
		if(getDataType(obj_json_str[i]) == PAIR)
		{
			Data *data = getData(obj_json_str[i]);
			if(data != nullptr)
			{ inc_arr.pushBack((Pair*)data); }
		}
	}
}
