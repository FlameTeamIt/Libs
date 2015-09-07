#ifndef JSON_ARRAY
#define JSON_ARRAY

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

class Array
		: public DataContainer
{
	templates::Array<Data*> inc_arr;
	
protected:
	void set(const Data *data);
	void set(const Array &array);
	
public:
	Array();
	Array(const Data *data);
	Array(const Array &array);
	Array(const std::string &json_array);
	
	~Array();
	
	Data* operator[](const size_t &index);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	void pushBack(const Data *data);
	void pushFront(const Data *data);
	
	void insert(const size_t &index, const Data *data);
	void insert(const size_t &index, const size_t &count, const Data **data);
	
	Data* at(const size_t &index);
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_array);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;
};

}}

#endif // JSON_ARRAY
