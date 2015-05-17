#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <string>

#include "Data.h"
#include "Pair.h"

#include "../Templates/Array.h"

namespace flame_ide
{namespace JSON
{

class Object : public Data
{
	templates::Array<Pair> arr;
public:
	Object();
	Object(const templates::Array<Pair> &template_array);
	Object(const size_t& size);
	
	~Object();
	
	Data* operator [](const std::string &str_index) const;
	Data* operator [](const char *c_str_index) const;
	Data* operator [](const size_t &index);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	std::string getAsString();
	void        setAsString(const std::string &json_object);
};

}
}
#endif // JSON_OBJECT_H
