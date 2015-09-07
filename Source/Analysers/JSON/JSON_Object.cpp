#include <Analysers/JSON/JSON.h>

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
	if(!isTemporary())
	{
		clear();
	}
	else
	{
		setTemporary(false);
	}
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
	if(data->getType() == PAIR)
	{
		inc_arr.pushBack((Pair*)data->getCopy());
	}
}

void
JSON::
Object::pushFront(const Data *data)
{
	if(data->getType() == PAIR)
	{
		inc_arr.pushFront((Pair*)data->getCopy());
	}
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

JSON::Data*
JSON::
Object::at(const size_t &index)
{
	return (inc_arr.getSize()) ? inc_arr[index] : nullptr;
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

	templates::List<std::string> &&obj_json_str = split(json_object);
	
	for(templates::List<std::string>::iterator it = obj_json_str.begin();
		!it.isEnd();)
	{
		if(getDataType(it.getData()) != PAIR)
		{
			templates::List<std::string>::iterator old_it = it;
			it++;
			obj_json_str.erase(old_it);
		}
		else
		{
			it++;
		}
	}
	
	inc_arr.setSize(obj_json_str.getSize());
	size_t i = 0;
	for(templates::List<std::string>::iterator it = obj_json_str.begin();
		!it.isEnd();
		++it)
	{
			Pair* pair= static_cast<Pair*>(getData(it.getData()));
			inc_arr[i] = pair;
			i++;
	}
}

void
JSON::
Object::setTemporary(bool is_temp) const
{
	this->inc_arr.setTemporary(is_temp);
}

bool
JSON::
Object::isTemporary() const
{
	return inc_arr.isTemporary();
}
