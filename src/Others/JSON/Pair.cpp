#include "JSON.h"

using namespace flame_ide::JSON;

Pair::Pair()
	: Data(false, false, false)
{	data = nullptr;}

Pair::Pair(const Data *new_data)
{
	data = new_data->getCopy();
}

Pair::Pair(const std::string &json_pair)
{
	setAsString(json_pair);
}

Pair::Pair(const Pair &pair)
	: Data(false, false, false)
{
	this->key = pair.key;
	data = pair.data->getCopy();
}

Pair::~Pair()
{
	if(data != nullptr)
	{	delete data;}
}

Data*
Pair::getCopy() const
{
	Data *copy_data = new Pair(*this);
	
	return copy_data;
}

std::string
Pair::getAsString() const
{
	// тут нужно подумать.
	std::string string_out = '"' + key + "\":";
	
	if(data->getType() == PAIR)
	{
		// частный вид объекта
		string_out += "{" + data->getAsString() + ";}";
	}
	else
	{
		string_out += data->getAsString();
	}
	
	return string_out;
}

void
Pair::setAsString(const std::string &json_pair)
{
	// getting key
	bool end = false;
	bool search_colon = false;
	unsigned short count_braces = 0;
	size_t pos = 0;
	
	std::string::const_iterator it, it_prevend, it_end = json_pair.end();
	
	// without catching errors
	if(json_pair.length() > 3)
	{
		for(it = json_pair.begin(), it_prevend = (json_pair.end() - 3);
			it != it_end && !end;
			++it, ++pos)
		{
			if(*it == '"' && it != it_prevend)
			{
				count_braces++;
				if(count_braces == 2)
				{
					end = true;
				}
			}
			else
			if(count_braces && count_braces < 2)
			{
				if(it != it_prevend)
				{
					key += *it;
				}
				else
				{
					key = "";
					end = true;
				}
			}
		}
		
		end = false;
	}
	
	if(!key.length())
	{
		return;
	}
	
	for(it = (json_pair.begin()+pos), it_prevend = json_pair.end()-2;
		it != it_end && !end;
		++it)
	{
		if(*it == ':')
		{
			search_colon = true;
			end = true;
		}
		else
		{
			if(it == it_prevend)
			{
				end = true;
			}
			
			pos++;
		}
	}
	pos++;
	
	if(!search_colon && pos >= json_pair.length() )
	{
		key = "";
		return;
	}
	
	// получаем остаток от строки и парсим другой функцией
	std::string json_data = json_pair.substr(pos, json_pair.length()-pos);
	
	// получаем сразу
	this->data = getData(json_data);
	
	if(data == nullptr)
	{
		key = "";
		return;
	}
	
}

const Pair&
Pair::operator=(const Pair& pair)
{
	Data* tmp = this->data;
	
	if(pair.data != nullptr)
	{
		switch (pair.data->getType())
		{
		case PAIR:   // pair
			break;
			
		case SINGLE: // single
			break;
			
		case ARRAY:  // array
			
			break;
			
		case OBJECT: // object
			
			break;
			
		default:
			break;
		}
	}
	
	if(tmp != this->data)
	{
		this->key = pair.key;
		delete tmp;
	}
	
	return *this;
}
