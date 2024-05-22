#ifndef FLAMEIDE_TEMPLATES_THREADSAFEOBJECT_HPP
#define FLAMEIDE_TEMPLATES_THREADSAFEOBJECT_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>
#include <FlameIDE/Threads/Mutex.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = DefaultTraits<T>
>
class ThreadSafeWrapper
{
public:
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using Reference = typename Traits::Reference;

	ThreadSafeWrapper(ThreadSafeWrapper<T, Traits> &&) noexcept = default;

	/// @brief Constructor
	/// @param objectReference
	/// @param mutex
	ThreadSafeWrapper(Reference objectReference, threads::Mutex &mutex) noexcept;

	~ThreadSafeWrapper() noexcept = default;

	/// @brief operator ->
	/// @return
	Reference operator->() noexcept;

private:
	Pointer objectPtr; ///<
	threads::Mutex::UniqueLocker locker; ///<
};


/// @brief The ThreadSafeObject class
/// @tparam T
/// @tparam Traits
/// @tparam Allocator
template<typename T
	, typename Traits = DefaultTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T>
>
class ThreadSafeObject
{
public:
	using UniquePointer = templates::UniquePointer<T, Traits, Allocator>;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using Reference = typename Traits::Reference;
	using MoveReference = typename Traits::MoveReference;
	using ConstReference = typename Traits::ConstReference;

	using ThreadSafeWrapper = flame_ide::templates::ThreadSafeWrapper<T, Traits>;
	using ConstThreadSafeWrapper = flame_ide::templates::ThreadSafeWrapper<const T, Traits>;

	/// @brief ThreadSafeObject
	/// @param objectPointer
	ThreadSafeObject(UniquePointer &&objectPointer) noexcept;

	/// @brief ThreadSafeObject
	/// @tparam Args
	/// @param args
	template<typename ...Args>
	ThreadSafeObject(Args &&...args) noexcept;

	/// @brief operator ->
	/// @return
	ThreadSafeWrapper operator->() noexcept;

private:
	UniquePointer objectPtr; ///<
	threads::Mutex mutex; ///<
};

template<typename T>
ThreadSafeObject<T> createThreadSafeObject() noexcept;

}}

namespace flame_ide
{namespace templates
{

// ThreadSafeObject

template<typename T, typename Traits, typename Allocator>
ThreadSafeObject<T, Traits, Allocator>::ThreadSafeObject(
		UniquePointer &&objectPointer) noexcept : objectPtr(move(objectPointer))
{}

template<typename T, typename Traits, typename Allocator>
template<typename ...Args>
ThreadSafeObject<T, Traits, Allocator>::ThreadSafeObject(Args &&...args) noexcept :
		objectPtr(makeUnique<Type>(forward<Args>(args)...))
{}

template<typename T, typename Traits, typename Allocator>
typename ThreadSafeObject<T, Traits, Allocator>::ThreadSafeWrapper
ThreadSafeObject<T, Traits, Allocator>::operator->() noexcept
{
	ThreadSafeWrapper ThreadSafeWrapper {objectPtr.operator->(), mutex};
	return ThreadSafeWrapper;
}

// ThreadSafeObject::ThreadSafeWrapper

template<typename T, typename Traits>
ThreadSafeWrapper<T, Traits>::ThreadSafeWrapper(Reference objectReference
	, threads::Mutex &mutex)  noexcept :
	objectPtr(&objectReference), locker(mutex)
{}

template<typename T, typename Traits>
typename ThreadSafeWrapper<T, Traits>::Reference
ThreadSafeWrapper<T, Traits>::operator->() noexcept
{
	return *objectPtr;
}

// createThreadSafeObject

template<typename T, typename ...Args>
ThreadSafeObject<T> createThreadSafeObject(Args &&...args) noexcept
{
	return ThreadSafeObject<T>(forward<Args>(args)...);
}

}}

#endif // THREADSAFEOBJECT_HPP
