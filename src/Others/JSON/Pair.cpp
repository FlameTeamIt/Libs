#include "JSON.h"

using namespace flame_ide::JSON;

Pair::Pair()
{	data = nullptr;}

Pair::~Pair()
{
	if(data != nullptr)
	{	delete data;}
}

const Pair&
Pair::operator=(const JSON::Pair& pair)
{
	Data* tmp = this->data;
	
	if(pair.data != nullptr)
	{
		switch (pair.data->getType())
		{
		case SINGLE:   // single
			this->data = new JSON::Single(pair.data->getAsString());
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
}
