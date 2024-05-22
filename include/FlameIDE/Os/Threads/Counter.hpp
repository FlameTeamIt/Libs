#ifndef FLAMEIDE_OS_THREADS_COUNTER_HPP
#define FLAMEIDE_OS_THREADS_COUNTER_HPP

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

template<typename Lock, typename Value>
class Counter
{
public:
	using Me = Counter<Lock, Value>;

	Counter() noexcept = default;
	Counter(const Me &) noexcept = delete;
	Counter(Me &&) noexcept = default;

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

template<typename Lock, typename Value>
Counter<Lock, Value> &Counter<Lock, Value>::operator++() noexcept
{
	Locker locker{ lock };
	++value;
	return *this;
}

template<typename Lock, typename Value>
Counter<Lock, Value> &Counter<Lock, Value>::operator--() noexcept
{
	Locker locker{ lock };
	--value;
	return *this;
}

template<typename Lock, typename Value>
Value Counter<Lock, Value>::current() const noexcept
{
	Locker locker{ lock };
	return value;
}

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_COUNTER_HPP
