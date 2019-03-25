#ifndef FLAMEIDE_THREADS_MUTEX_HPP
#define FLAMEIDE_THREADS_MUTEX_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace threads
{

///
/// @brief The Mutex class
///
class Mutex
{
public:
	///
	/// @brief The State enum
	///
	enum class State
	{
		INVALID ///<
		, UNLOCKED ///<
		, LOCKED ///<
	};

	///
	/// @brief The Locker class
	///
	class Locker
	{
	public:
		///
		/// @brief Locker
		/// @param initMutex
		///
		Locker(Mutex &initMutex) noexcept;
		~Locker() noexcept;

	private:
		Mutex &mtx; ///<
	};

	Mutex() noexcept;
	Mutex(const Mutex &) = delete;
	Mutex(Mutex &&mutex) noexcept;
	~Mutex() noexcept;
	Mutex &operator=(const Mutex &) = delete;
	Mutex &operator=(Mutex &&mutex) noexcept;

	///
	/// @brief lock
	///
	void lock() noexcept;

	///
	/// @brief unlock
	///
	void unlock() noexcept;

	///
	/// @brief getState
	/// @return
	///
	Mutex::State getState() const noexcept;

	///
	/// @brief getStatus
	/// @return
	///
	os::Status getStatus() const noexcept;

private:
	mutable os::MutexContext context; ///<
	mutable os::Status status; ///<
};

}}

#endif // MUTEX_HPP
