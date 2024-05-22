#ifndef FLAMEIDE_OS_THREADS_CONDITIONVARIABLE_HPP
#define FLAMEIDE_OS_THREADS_CONDITIONVARIABLE_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Os/Threads/Counter.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

///
/// @brief Trivial condition variable without timers and counters
///
class ConditionVariable
{
public:
	///
	/// @brief Constructor
	/// @tparam Lock Synchronization object type
	/// @param locker Synchronization object in unlocked state
	///
	template<typename LockObject>
	ConditionVariable(LockObject &lock) noexcept;
	~ConditionVariable() noexcept;

	///
	/// @brief Wait for signal
	///
	void wait() noexcept;

	///
	/// @brief Wait for signal
	/// @note If condition is false, thread is blocking
	/// @tparam Functor Functional object type. Needs returning boolean
	/// @param functor Functional object. operator() needs returning boolean
	///
	template<typename Functor>
	void wait(Functor &&functor) noexcept;

	///
	/// @brief Trying wait for signal
	///
	bool tryWait() noexcept;

	///
	/// @brief Disable waiting (decrement counter)
	///
	void unwait() noexcept;

	///
	/// @brief isWait
	/// @return
	///
	bool isWait() const noexcept;

	///
	/// @brief Send notification for unblock
	///
	void notify() noexcept;

private:
	Counter<Spin, flame_ide::Types::uichar_t> counter;
	UniqueLocker locker;
};

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

template<typename LockObject>
ConditionVariable::ConditionVariable(LockObject &lock) noexcept :
		locker{ lock, UniqueLocker::LOCK }
{}

template<typename Functor>
void ConditionVariable::wait(Functor &&functor) noexcept
{
	static_assert(
			CompareTypesResult<bool, decltype(functor())>
			, "Return type of input fuctior must be boolean"
	);

	do
		wait();
	while (!functor());
}

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_CONDITIONVARIABLE_HPP
