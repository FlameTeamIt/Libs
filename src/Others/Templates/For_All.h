#ifndef FOR_ALL
#define FOR_ALL

namespace flame_ide
{namespace templates
{

template<typename Tt1, typename Tt2>
struct Types
{
	enum { isSame = 0 };
};

template<typename Tt>
struct Types<Tt, Tt>
{
	enum { isSame = 1 };
};

}}

#endif // FOR_ALL

