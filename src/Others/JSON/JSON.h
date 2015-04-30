#ifndef JSON_H
#define JSON_H

#include <string>

#include "../Templates/Array.h"

namespace flame_ide
{namespace JSON
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
	
	// 100 -- object
	// 10 -- array
	// 1 -- single
	unsigned char status;
protected:
	
public:
	Data();
	Data(const bool& is_object_type
		 ,const bool& is_array_type
		 ,const bool& is_single_type);
	
	virtual ~Data();
	
	bool isObject();
	bool isArray();
	bool isSingle();
	
	unsigned char getStatus();
	
	virtual std::string getAsString() = 0;
	virtual void        setAsString(const std::string&) = 0;
};

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

class Single : public Data
{
	std::string str;
	
public:
	Single();
	Single(const std::string &value);
	
	~Single();
	// future
//	int           getInt();
//	unsigned int  getUInt();
	
//	long          getLong();
//	unsigned long getULong();
	
//	float         getFloat();
//	double        getDouble();
	
//	bool          getBool();
	
//	bool          isNull();
	
	std::string getAsString();
	void        setAsString(const std::string &single);
	
};

class Pair
{
public:
	std::string key;
	Data* data;
	
	Pair();
	~Pair();
	
	Pair& operator=(const Pair& pair);
};

}}

#endif // JSON_H
