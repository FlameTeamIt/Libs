#ifndef JSON_DATACONTAINER
#define JSON_DATACONTAINER

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

class DataContainer
		: public Data
{
protected:
	static templates::List<std::string> split(const std::string &json_container);
	
public:
	DataContainer(const bool& is_object_type
				  ,const bool& is_array_type);
	
	virtual void pushBack(const Data *data) = 0;
	virtual void pushFront(const Data *data) = 0;
	
	virtual void insert(const size_t &index, const Data *data) = 0;
	virtual void insert(const size_t &index, const size_t &count, const Data **data) = 0;
	
	virtual Data* at(const size_t &index) = 0;
	
	virtual void popBack() = 0;
	virtual void popFront() = 0;
	
	virtual void erase(const size_t &index) = 0;
	virtual void erase(const size_t &index, const size_t &count) = 0;
	
	virtual void clear() = 0;
	
	~DataContainer();
};

}}

#endif // JSON_DATACONTAINER
