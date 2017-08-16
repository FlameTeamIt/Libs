#ifndef TEMPLATES_ARRAYBLOCKS
#define TEMPLATES_ARRAYBLOCKS

namespace flame_ide
{namespace templates
{

typedef enum
{
	FROM_NULL  = char(0),
	FROM_FRONT = char(1),
	FROM_BACK  = char(2)
} FromBlock;

template<typename T>
class ArrayBlocks
{
};

}}

#endif // TEMPLATES_ARRAYBLOCKS
