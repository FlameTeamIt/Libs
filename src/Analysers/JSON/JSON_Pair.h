#ifndef JSON_PAIR
#define JSON_PAIR

//#include <Analysers/JSON/JSON.h>
#include <Analysers/JSON/JSON_Data.h>

namespace flame_ide
{namespace JSON
{

class Pair
		: public Data
{
	Data* inc_data;
	
protected:
	void set(const Data *data);
	void set(const Pair &pair);
	
public:
	std::string inc_key;
	
	Pair();
	Pair(const std::string &json_pair);
	Pair(const Pair &pair);
	Pair(const Data* data);
	Pair(const std::string &json_key, const Data *data);
	Pair(const char* key, const Data *data);
	
	~Pair();
	
	Data* getData() const;
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string& json_pair);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;
	
	const Pair& operator=(const Pair& pair);
};

}}

#endif // JSON_PAIR
