#ifndef FLAMEIDE_THREADS_MUTEX_HPP
#define FLAMEIDE_THREADS_MUTEX_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace threads
{

///
/// @brief The Mutex class
///
class Mutex
{
public:
	enum class Type
	{
		COMMON
		, RECURSIVE
		, TIMED
		, TIMED_RECURSIVE
	};

	///
	/// @brief The State enum
	///
	enum class State
	{
		INVALID ///<
		, UNLOCKED ///<
		, LOCKED ///<
	};

	/// @brief The Locker class
	class Locker
	{
	public:
		/// @brief Locker
		/// @param initMutex
		Locker(Mutex &initMutex) noexcept;
		~Locker() noexcept;

	private:
		Mutex &mtx; ///<
	};

	class UniqueLocker
	{
	public:
		UniqueLocker(UniqueLocker &&locker) noexcept = default;

		/// @brief UniqueLocker
		/// @param initMutex
		UniqueLocker(Mutex &initMutex) noexcept;

		~UniqueLocker() noexcept;

	private:
		Mutex *mtx; ///<
	};

	Mutex() noexcept;
	Mutex(const Mutex &) = delete;
	Mutex(Mutex &&mutex) noexcept;

	/// @brief Mutex
	/// @param type
	Mutex(Mutex::Type type) noexcept;

	~Mutex() noexcept;

	Mutex &operator=(const Mutex &) = delete;
	Mutex &operator=(Mutex &&mutex) noexcept;

	/// @brief lock
	void lock() noexcept;

	/// @brief unlock
	void unlock() noexcept;

	/// @brief getType
	/// @return
	Mutex::Type getType() noexcept;

	/// @brief getState
	/// @return
	Mutex::State getState() const noexcept;

	/// @brief getStatus
	/// @return
	os::Status getStatus() const noexcept;

private:
	mutable os::MutexContext context; ///<
	mutable os::Status status; ///<
};

}}

#endif // MUTEX_HPP
