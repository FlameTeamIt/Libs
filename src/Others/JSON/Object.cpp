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
	set(data);
}

JSON::
Object::Object(const Object &object)
	: Object()
{
	set(object);
}

JSON::
Object::Object(const std::string &json_object)
	: Object()
{
	this->setAsString(json_object);
}

JSON::
Object::~Object()
{
	clear();
}

void
JSON::
Object::set(const Data *data)
{
	if(data->getType() == OBJECT)
	{
		const Object* object = static_cast<const Object*>(data);
		set(*object);
	}
}

void
JSON::
Object::set(const Object &object)
{
	const size_t length = object.inc_arr.getSize();
	this->inc_arr = object.inc_arr;
	
	for(size_t i = 0; i < length; i++)
	{
		inc_arr[i] = (Pair*)object.inc_arr[i]->getCopy();
	}
}

void 
JSON::
Object::pushBack(const Data *data)
{
	if(data->getType() != PAIR)
	{ return; }
	
	inc_arr.pushFront((Pair*)data->getCopy());
}

void
JSON::
Object::pushFront(const Data *data)
{
	if(data->getType() != PAIR)
	{ return; }
	
	inc_arr.pushFront((Pair*)data->getCopy());
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
	if(data->getType() != PAIR)
	{ return; }
	
	inc_arr.insert(index, (Pair*)data->getCopy());
}

void
JSON::
Object::insert(const size_t &index, const size_t &count, const Data **data)
{
	Pair *new_data[count];
	size_t real_count = count;
	
	for(size_t i = 0, j = 0; i < count; i++)
	{
		if(data[i]->getType() == PAIR)
		{
			new_data[j] = (Pair*)data[i]->getCopy();
			new_data[j]->setLevel(this->level+1);
			j++;
		}
		else
		{ --real_count; }
		
	}
	
	inc_arr.insert(index, real_count, new_data);
}

void
JSON::
Object::popBack()
{
	delete inc_arr[inc_arr.getSize()-1];
	inc_arr.popBack();
}

void
JSON::
Object::popFront()
{
	delete inc_arr[0];
	inc_arr.popFront();
}

void
JSON::
Object::erase(const size_t &index)
{
	if(index >= inc_arr.getSize())
	{ return; }
	
	delete inc_arr[index];
	inc_arr.erase(index);
}

void
JSON::
Object::erase(const size_t &index, const size_t &count)
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
			out_json_str += inc_arr[i]->getAsString() + ",";
		}
		out_json_str += inc_arr[length]->getAsString();
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
	const size_t &length = obj_json_str.getSize();
	
	for(size_t i = 0; i < length; i++)
	{
		Data *data = getData(obj_json_str[i]);
		if(getDataType(obj_json_str[i]) == PAIR)
		{
			if(data != nullptr)
			{
				Pair* pair= static_cast<Pair*>(data);
				inc_arr.pushBack(pair);
			}
		}
	}
}
