#include "JSON.h"

#include <string>

// Data -----------------------------------

namespace flame_ide
{

JSON::
Data::Data()
{
	is_object = false;
	is_array = false;
	is_single = false;
}

JSON::
Data::Data(const bool &is_object_type
		   ,const bool &is_array_type
		   ,const bool &is_single_type)
{
	this->is_object = is_object_type;
	this->is_array  = is_array_type;
	this->is_single = is_single_type;
	
	this->status = 100 * this->is_object
				 + 10 * this->is_array
				 + this->is_single;
}

JSON::
Data::~Data() {}

bool
JSON::
Data::isObject()
{	return is_object;}

bool
JSON::
Data::isArray()
{	return is_array;}

bool
JSON::
Data::isSingle()
{	return is_single;}

unsigned char
JSON::
Data::getStatus()
{	return status;}

}

// Object ----------------------------------

/*
 *  не хватает:
 *  Array<T>::push_back
 *  Array<T>::push_front
 *  Array<T>::pop_back
 *  Array<T>::pop_front
 *  class List<T> для того, чтобы не считать количество
записей предварительно (накланые расходы, да и не нужно)
 *  что-то еще...
 * 
 */

namespace flame_ide
{

JSON::
Object::Object()
	: JSON::Data(1, 0, 0)
{}

JSON::
Object::Object(const templates::Array<Pair> &template_array)
	: JSON::Object()
{
	this->arr = template_array;
}

JSON::
Object::~Object() {}

std::string 
JSON::
Object::getAsString()
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

// Array -----------------------------------

JSON::
Array::Array()
	: JSON::Data(0, 1, 0)
{}

JSON::Data*
JSON::
Array::operator [](const size_t &index)
{
	return &arr[index];
}

std::string
JSON::
Array::getAsString()
{
	return std::string("[]");
}

void
JSON::
Array::setAsString(const std::string &json_array)
{
	// парсинг вектора
}

}

// Single ----------------------------------

namespace flame_ide
{

JSON::
Single::Single()
	: JSON::Data(0, 0, 1)
{}

JSON::
Single::Single(const std::string& value)
	: JSON::Single()
{	this->str = value;}


JSON::
Single::~Single() {}

std::string
JSON::
Single::getAsString()
{	return this->str;}

void
JSON::
Single::setAsString(const std::string &json_single)
{	str = json_single;}

}

// Pair ------------------------------------

namespace flame_ide
{

JSON::
Pair::Pair()
{	data = nullptr;}

JSON::
Pair::~Pair()
{
	if(data != nullptr)
	{	delete data;}
}

JSON::Pair&
JSON::Pair::operator=(const JSON::Pair& pair)
{
	Data* tmp = this->data;
	
	if(pair.data != nullptr)
	{
		switch (pair.data->getStatus())
		{
		case 1:   // single
			this->data = new JSON::Single(pair.data->getAsString());
			break;
			
		case 10:  // array
			
			break;
			
		case 100: // object
			
			break;
			
		default:
			break;
		}
	}
	
	if(tmp != this->data)
	{
		this->key = pair.key;
		delete tmp;
	}
}

}

