#include "Pair.h"

#include "Single.h"

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

