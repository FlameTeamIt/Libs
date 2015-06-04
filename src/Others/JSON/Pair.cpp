#include "JSON.h"

using namespace flame_ide::JSON;

Pair::Pair()
{	data = nullptr;}

Pair::Pair(const Pair &pair)
{	
}

Pair::~Pair()
{
	if(data != nullptr)
	{	delete data;}
}

Data*
Pair::getCopy() const
{
	return nullptr;
}

std::string
Pair::getAsString() const
{
	// тут нужно подумать.
	std::string string_out = '"' + key + "\":";
	
	if(data->getType() == PAIR)
	{
		// частный вид объекта
		string_out += "{\n" + data->getAsString() + ";\n}";
	}
	else
	{
		string_out += data->getAsString();
	}
	
	return string_out;
}

void
Pair::setAsString(const std::string &json_pair)
{
	
}

const Pair&
Pair::operator=(const Pair& pair)
{
	Data* tmp = this->data;
	
	if(pair.data != nullptr)
	{
		switch (pair.data->getType())
		{
		case PAIR:   // pair
			break;
			
		case SINGLE: // single
			break;
			
		case ARRAY:  // array
			
			break;
			
		case OBJECT: // object
			
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
	
	return *this;
}
