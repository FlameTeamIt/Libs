#ifndef POINTERS
#define POINTERS

namespace flame_ide
{namespace templates
{

template<class T>
class BasicPointer;

template<class T>
class SharedPointer;

template<class T>
class UniquePointer;

template<class T, class U>
BasicPointer<T> static_pointer_cast(const BasicPointer<U>& pointer) noexcept;
template<class T, class U>
SharedPointer<T> static_pointer_cast(const SharedPointer<U>& pointer) noexcept;
template<class T, class U>
UniquePointer<T> static_pointer_cast(UniquePointer<U>& pointer) noexcept;

template<class T, class U>
BasicPointer<T> dynamic_pointer_cast(const BasicPointer<U>& pointer) noexcept;
template<class T, class U>
SharedPointer<T> dynamic_pointer_cast(const SharedPointer<U>& pointer) noexcept;
template<class T, class U>
UniquePointer<T> dynamic_pointer_cast(UniquePointer<U>& pointer) noexcept;

}}

#include <Templates/Pointers_BasicPointer.h>
#include <Templates/Pointers_SharedPointer.h>
#include <Templates/Pointers_UniquePointer.h>
#include <Templates/Pointers_Functions.h>

#endif // POINTERS
