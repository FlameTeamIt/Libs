#include "JSON.h"

using namespace flame_ide;

JSON::
Object::Object()
	: JSON::DataContainer(true, false)
{}

JSON::
Object::Object(const templates::Array<Pair> &template_array)
	: JSON::Object()
{
	this->arr = template_array;
}

JSON::
Object::~Object() {}

void 
JSON::
Object::pushBack(Data *data)
{
	
}

void
JSON::
Object::pushFront(Data *data)
{
	
}

void
JSON::
Object::insert(const size_t &index, Data *data)
{
	
}

void
JSON::
Object::insert(const size_t &index, const size_t &count, Data **data)
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

JSON::Data*
JSON::
Object::getCopy() const
{
	return nullptr;
}

std::string
JSON::
Object::getAsString() const
{	return std::string("{}");}

void
JSON::
Object::setAsString(const std::string &json_object)
{
	// парсинг объекта
	
	Data* tmp_data;
	unsigned short is_key = 0, is_data;
	
	for(std::string::const_iterator it = json_object.begin(),
		it_end = json_object.end();
		it != it_end;
		++it)
	{
		// варианты
		
		/*
		 1. встречаем " (кавычка) 
		 1.1. если ключ -- посимвольно записываем в ключ
		 1.2. если значение то определяем, что это за объект.
		 1.2.1. если встречаем ",true,false,number -- Это Single
		 1.2.2. если встречаем { -- Это Object
		 1.2.3. если встречаем [ -- Это Array
		        
		*/
	}
}
