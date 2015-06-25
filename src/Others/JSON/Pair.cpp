#include "JSON.h"

using namespace flame_ide::JSON;

Pair::Pair()
	: Data(false, false, false)
{	inc_data = nullptr;}

Pair::Pair(const Data *data)
	: Data(false, false, false)
{
	if(data->getType() == PAIR)
	{
		Pair(*((Pair*)data));
	}
}

Pair::Pair(const std::string &json_pair)
	: Data(false, false, false)
{
	setAsString(json_pair);
}

Pair::Pair(const Pair &pair)
	: Data(false, false, false)
{
	this->key = pair.key;
	inc_data = pair.inc_data->getCopy();
}

Pair::Pair(const std::string &json_key, const Data *data)
	: Data(false, false, false)
{
	this->key = json_key;
	this->inc_data = data->getCopy();
}

Pair::Pair(const char* key, const Data *data)
	: Data(false, false, false)
{
	this->key = key;
	this->inc_data = data->getCopy();
}

Pair::~Pair()
{
	if(inc_data != nullptr)
	{ delete inc_data;}
}

Data*
Pair::getData() const
{
	return inc_data;
}

Data*
Pair::getCopy() const
{
	return new Pair(*this);
}

std::string
Pair::getAsString() const
{
	// тут нужно подумать.
	std::string string_out = '"' + key + "\":";
	
	if(inc_data->getType() == PAIR)
	{
		// частный вид объекта
		string_out += "{" + inc_data->getAsString() + ";}";
	}
	else
	{
		string_out += inc_data->getAsString();
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
	
	// нужно переделать
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
	this->inc_data = Data::getData(json_data);
	
	if(inc_data == nullptr)
	{
		key = "";
		return;
	}
	
}

const Pair&
Pair::operator=(const Pair& pair)
{
	if(this->inc_data != nullptr)
		delete this->inc_data;
	
	this->key = pair.key;
	this->inc_data = pair.inc_data->getCopy();
	
	return *this;
}
