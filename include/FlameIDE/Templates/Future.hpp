#ifndef FLAMEIDE_TEMPLATES_FUTURE_HPP
#define FLAMEIDE_TEMPLATES_FUTURE_HPP

#include <FlameIDE/Common/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<
	typename ValueType
	, template<typename = ValueType>
		class AtomicValueType
	, typename Traits = DefaultTraits<ValueType>
>
class Future
{
public:
	using AtomicValue = AtomicValueType<ValueType>;

	Future() noexcept;

	ValueType *get() noexcept;
	ValueType *get() const noexcept;

	ValueType *operator->() noexcept;
	ValueType *operator->() const noexcept;
};

template<
	typename PromiseType
	, template<typename = PromiseType>
		class AtomicValueType
>
class Promise
{
public:
	using AtomicValue = AtomicValueType<PromiseType>;

	Promise();

	void set();
};

}}

#endif // FLAMEIDE_TEMPLATES_FUTURE_HPP
