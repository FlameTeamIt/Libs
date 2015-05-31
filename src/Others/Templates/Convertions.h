#ifndef TEMPLATES_CONVERTIONS
#define TEMPLATES_CONVERTIONS

#include "Array.h"
#include "List.h"

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Array<Tt> convert_list_to_array(const List<Tt> &list);

template<typename Tt> inline
List<Tt> convert_array_to_list(const Array<Tt> &array);

}}

using namespace flame_ide::templates;

template<typename Tt> inline
Array<Tt>
convert_list_to_array(const List<Tt> &list)
{
}

template<typename Tt> inline
List<Tt>
convert_array_to_list(const Array<Tt> &array)
{
}

#endif // TEMPLATES_CONVERTIONS

