#include "JSON.h"

using namespace flame_ide::JSON;


Data::Data()
{
	is_object = false;
	is_array = false;
	is_single = false;
	
	level = 0;
}

Data::Data(bool is_object_type
		   , bool is_array_type
		   , bool is_single_type)
{
	this->is_object = is_object_type;
	this->is_array  = is_array_type;
	this->is_single = is_single_type;
	
	this->type = 100 * this->is_object
				 + 10 * this->is_array
				 + this->is_single;
	
	if(!this->is_single)
	{ is_container = true; }
	else
	{ is_container = false; }
}

Data::~Data() {}

bool
Data::isObject() const
{	return is_object; }

bool
Data::isArray() const
{	return is_array; }

bool
Data::isSingle() const
{	return is_single; }

bool
Data::isPair() const
{ return (!type); }

bool
Data::isContainer() const
{	return is_container; }

void
Data::setLevel(unsigned long new_level)
{ level = new_level; }

unsigned int
Data::getType() const
{	return type; }
