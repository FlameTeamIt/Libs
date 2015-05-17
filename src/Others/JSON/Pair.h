#ifndef JSON_PAIR_H
#define JSON_PAIR_H

#include "Data.h"

namespace flame_ide
{namespace JSON
{

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

#endif // JSON_PAIR_H
