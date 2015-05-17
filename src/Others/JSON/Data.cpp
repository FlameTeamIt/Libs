#include "Data.h"

using namespace flame_ide;

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

