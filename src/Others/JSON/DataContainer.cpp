#include "JSON.h"

namespace flame_ide
{namespace JSON
{

DataContainer::DataContainer(const bool &is_object_type
							 , const bool &is_array_type)
	: Data(is_object_type, is_array_type, false)
{}

DataContainer::~DataContainer()
{}

templates::List<std::string>
DataContainer::split(const std::string &json_container)
{
	templates::List<std::string> list_json_str;
	unsigned short brace_level = 0;
	size_t pos_start = 0, pos_end = pos_start;
	
	for(std::string::const_iterator it = json_container.begin(),
		it_end = json_container.end();
		it != it_end;
		++it)
	{
		if(*it == '{' || *it == '[')
		{
			brace_level++;
			
			if(!pos_start)
			{
				pos_start = pos_end+1;
			}
		}
		
		if(*it == '}' || *it == ']')
		{
			brace_level--;
			
			if(brace_level == 0)
			{
				std::string temp_str(json_container.substr(pos_start, pos_end-pos_start));
				
				list_json_str.pushBack(temp_str);
			}
		}
		
		if(*it == ',' && brace_level == 1)
		{
			std::string temp_str(json_container.substr(pos_start, pos_end-pos_start));
			
			list_json_str.pushBack(temp_str);
			pos_start = pos_end+1;
		}
		
		pos_end++;
	}
	
	return list_json_str;
}


}}
