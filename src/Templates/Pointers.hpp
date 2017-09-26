#ifndef TEMPLATES_POINTERS_HPP
#define TEMPLATES_POINTERS_HPP

namespace flame_ide
{namespace templates
{

template<class T>
class BasicPointer;

template<class T>
class SharedPointer;

template<class T>
class UniquePointer;

template<class T, class U> inline
BasicPointer<T> static_pointer_cast(const BasicPointer<U>& pointer) noexcept;
template<class T, class U> inline
SharedPointer<T> static_pointer_cast(const SharedPointer<U>& pointer) noexcept;
template<class T, class U> inline
UniquePointer<T> static_pointer_cast(UniquePointer<U>& pointer) noexcept;

template<class T, class U> inline
BasicPointer<T> dynamic_pointer_cast(const BasicPointer<U>& pointer) noexcept;
template<class T, class U> inline
SharedPointer<T> dynamic_pointer_cast(const SharedPointer<U>& pointer) noexcept;
template<class T, class U> inline
UniquePointer<T> dynamic_pointer_cast(UniquePointer<U>& pointer) noexcept;

template<class T, class U> inline
BasicPointer<T> reiterpret_pointer_cast(const BasicPointer<U>& pointer) noexcept;
template<class T, class U> inline
SharedPointer<T> reiterpret_pointer_cast(const SharedPointer<U>& pointer) noexcept;
template<class T, class U> inline
UniquePointer<T> reiterpret_pointer_cast(UniquePointer<U>& pointer) noexcept;

}}

#endif // TEMPLATES_POINTERS_HPP
