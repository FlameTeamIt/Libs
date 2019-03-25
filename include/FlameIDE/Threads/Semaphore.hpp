#ifndef FLAMEIDE_THREADS_SEMAPHORE_HPP
#define FLAMEIDE_THREADS_SEMAPHORE_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace threads
{

///
/// @brief The Semaphore class
///
class Semaphore
{
public:
	///
	/// @brief The Poster class
	///
	class Poster
	{
	public:
		///
		/// @brief Poster
		/// @param semaphore
		///
		Poster(Semaphore &semaphore) noexcept;
		~Poster() noexcept;
	private:
		Semaphore &sem; ///<
	};

	///
	/// @brief The Waiter class
	///
	class Waiter
	{
	public:
		///
		/// @brief Waiter
		/// @param semaphore
		///
		Waiter(Semaphore &semaphore) noexcept;
		~Waiter() noexcept;
	private:
		Semaphore &sem; ///<
	};

	Semaphore() noexcept;
	Semaphore(const Semaphore &) = delete;
	Semaphore(Semaphore &&semaphore) noexcept;

	///
	/// @brief Semaphore
	/// @param initValue
	///
	Semaphore(os::SemaphoreValue initValue) noexcept;

	~Semaphore() noexcept;
	Semaphore &operator=(const Semaphore &) = delete;
	Semaphore &operator=(Semaphore &&semaphore) noexcept;

	///
	/// @brief post
	///
	void post() noexcept;

	///
	/// @brief wait
	///
	void wait() noexcept;

	///
	/// @brief getValue
	/// @return
	///
	os::SemaphoreValue getValue() const noexcept;

	///
	/// @brief getStatus
	/// @return
	///
	os::Status getStatus() const noexcept;

private:
	mutable os::SemaphoreContext context; ///<
	mutable os::Status status; ///<
};

}}

#endif // FLAMEIDE_THREADS_SEMAPHORE_HPP
