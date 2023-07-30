#ifndef FLAMEIDE_TEMPLATES_ITERATOR_CALLBACKITERATOR_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_CALLBACKITERATOR_HPP

#include <FlameIDE/Templates/Iterator/BaseIterator.hpp>

namespace flame_ide
{namespace templates
{

template<
	typename IteratorType
	, IteratorCategory ITERATOR_CATEGORY
	, IteratorAccess ITERATOR_ACCESS
	, typename Traits
	, typename MetaType = void
>
class CallbackIterator: public iterator_utils::BaseIterator<
	IteratorType, ITERATOR_CATEGORY, ITERATOR_ACCESS, Traits, MetaType
>
{};

}} // flame_ide::templates

#endif // FLAMEIDE_TEMPLATES_ITERATOR_CALLBACKITERATOR_HPP
