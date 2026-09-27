#ifndef FLAMEIDE_OS_THREADS_COUNTER_HPP
#define FLAMEIDE_OS_THREADS_COUNTER_HPP

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

template<typename LockType, typename ValueType>
class Counter
{
public:
	using Me = Counter<LockType, ValueType>;
	using Lock = LockType;
	using Value = ValueType;

	Counter() noexcept = default;
	Counter(const Me &) noexcept = delete;
	Counter(Me &&) noexcept = default;

	Counter(Value initValue) noexcept;

	~Counter() noexcept = default;

	Me &operator=(const Me &) noexcept = delete;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++() noexcept;
	Me &operator--() noexcept;

	Value current() const noexcept;

private:
	Value value = {};
	mutable Lock lock = {};
};

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

template<typename LockType, typename ValueType>
Counter<LockType, ValueType>::Counter(
		Counter<LockType, ValueType>::Value initValue
) noexcept : value{ initValue }
{}

template<typename LockType, typename ValueType>
Counter<LockType, ValueType> &Counter<LockType, ValueType>::operator++() noexcept
{
	Locker locker{ lock };
	++value;
	return *this;
}

template<typename LockType, typename ValueType>
Counter<LockType, ValueType> &Counter<LockType, ValueType>::operator--() noexcept
{
	Locker locker{ lock };
	--value;
	return *this;
}

template<typename LockType, typename ValueType>
typename Counter<LockType, ValueType>::Value
Counter<LockType, ValueType>::current() const noexcept
{
	Locker locker{ lock };
	return value;
}

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_COUNTER_HPP
