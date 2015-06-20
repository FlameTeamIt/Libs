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

templates::Array<std::string>
DataContainer::split(const std::string &json_container)
{
	// разбиваем каждый объект на подъобъекты
	
	/* нужно учитывать глубину вложенности скобок
	 * из-за того, что могут быть вложенные объекты
     */
	
	templates::Array<std::string> arr_json_str;
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
			
			// чтобы не захватить первую скобку скобку
			if(!pos_start)
			{
				pos_start = pos_end+1;
			}
		}
		
		if(*it == '}' || *it == ']')
		{
			brace_level--;
			
			// конец
			if(brace_level == 0)
			{
				std::string temp_str(json_container.substr(pos_start, pos_end-pos_start));
				
				arr_json_str.pushBack(temp_str);
			}
		}
		
		if(*it == ',' && brace_level == 1)
		{
			std::string temp_str(json_container.substr(pos_start, pos_end-pos_start));
			
			arr_json_str.pushBack(temp_str);
			pos_start = pos_end+1;
		}
		
		pos_end++;
	}
	
	return arr_json_str;
}


}}


