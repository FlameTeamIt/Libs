#include "JSON.h"

namespace flame_ide
{ namespace JSON
{

// Data -----------------------------------

Data::Data()
{
	is_object = false;
	is_array = false;
	is_single = false;
}

Data::Data(const bool &is_object_type
		   ,const bool &is_array_type
		   ,const bool &is_single_type)
{
	this->is_object = is_object_type;
	this->is_array  = is_array_type;
	this->is_single = is_single_type;
}

bool
Data::isObject()
{	return is_object;}

bool
Data::isArray()
{	return is_array;}
bool

Data::isSingle()
{	return is_single;}

// Object ----------------------------------

Object::Object() : Data(1, 0, 0)
{}

Object::Object(const templates::Array<Pair> &template_array) : Object()
{
	
}

// Array -----------------------------------

Array::Array() : Data(0, 1, 0)
{}


// Single ----------------------------------

Single::Single() : Data(0, 0, 1)
{}



// Pair ------------------------------------
// -----------------------------------------

}}
