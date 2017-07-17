#ifndef JSON_OBJECT
#define JSON_OBJECT

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

class Object
		: public DataContainer
{
	templates::Array<Pair*> inc_arr;
	
protected:
	void set(const Data *data);
	void set(const Object &object);
	
public:
	Object();
	Object(const Data *data);
	Object(const Object &object);
	Object(const std::string& json_object);
	
	~Object();
	
	const Object & operator=(const Object& object);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	void pushBack(const Data *data);
	void pushFront(const Data *data);
	
	void pushBack(const std::string &key, const Data *data);
	void pushFront(const std::string &key, const Data *data);
	
	void insert(const size_t &index, const Data *data);
	void insert(const size_t &index, const size_t &count, const Data **data);
	
#ifdef FUTURE // пока думаю, как с этим быть
	void insert(const size_t &index, const Pair *pair);
	void insert(const size_t &index, const size_t &count, const Pair **pairs);
#endif

	inline Data* at(const size_t &index);
#ifdef FUTURE // пока думаю, как с этим быть
	Data* at(const std::string &str_index) const;
	Data* at(const char *c_str_index)      const;
#endif
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_object);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;	
	
	inline Data* operator [](const size_t &index);
#ifdef FUTURE // пока думаю, как с этим быть
	Data* operator [](const std::string &str_index) const;
	Data* operator [](const char *c_str_index)      const;
#endif
};

}}

#endif // JSON_OBJECT
