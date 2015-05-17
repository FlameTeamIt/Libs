#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "Data.h"
#include "Single.h"

#include "../Templates/Array.h"

#include <string>

namespace flame_ide
{namespace JSON
{

class Array : public Data
{
	templates::Array<Data> arr;
	
public:
	Array();
	Array(const templates::Array<Single> &template_array);
	Array(const size_t& size);
	
	Data* operator[](const size_t &index);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	std::string getAsString();
	void        setAsString(const std::string &json_array);
};

}}
#endif // JSON_ARRAY_H
