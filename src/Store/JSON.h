#ifndef JSON_H
#define JSON_H

#include <string>

#include "../Others/Array.h"

namespace flame_ide
{

namespace JSON
{

class Data;

class Object;
class Array;
class Single;

struct Pair;

class Data
{
	bool is_object;
	bool is_array;
	bool is_single;
	
protected:
	
public:
	Data();
	Data(const bool& is_object_type
		 ,const bool& is_array_type
		 ,const bool& is_single_type);
	
	bool isObject();
	bool isArray();
	bool isSingle();
	
	virtual std::string getAsString() = 0;
	virtual void        setAsString(std::string&) = 0;
};

class Object : public Data
{
	templates::Array<Pair> arr;
public:
	Object();
	Object(const templates::Array<Pair>& template_array);
	Object(const size_t& size);
	
	Data* operator [](const std::string& str_index);
	Data* operator [](const char* c_str_index);
	Data* operator [](const size_t& index);
	
	void   setSize(const size_t& new_size);
	size_t getSize();
};

class Array : public Data
{
	templates::Array<Data> arr;
	
public:
	Array();
	Array(const templates::Array<Single>& template_array);
	Array(const size_t& size);
	
	Data* operator [](const size_t& index);
	
	void   setSize(size_t& new_size);
	size_t getSize();
};

class Single : public Data
{
	std::string str;
	
public:
	Single();
	Single(const std::string& value);
	
	void          setString(const std::string& value);
	std::string   getString();
	
	int           getInt();
	unsigned int  getUInt();
	
	long          getLong();
	unsigned long getULong();
	
	float		  getFloat();
	double        getDouble();
	
	bool          getBool();
	
	bool          isNull();
};

struct Pair
{
	std::string key;
	Data* data;
};

}

}

#endif // JSON_H
