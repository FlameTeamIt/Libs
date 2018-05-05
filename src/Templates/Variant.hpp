#ifndef TEMPLATES_VARIANT_HPP
#define TEMPLATES_VARIANT_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

namespace variant_utils
{

template<typename ...Args>
struct VariantStruct
{};

template<typename Arg, typename ...Args>
struct VariantStruct<Arg, Args...>
{
	union
	{
		Arg arg;
		VariantStruct<Args...> pack;
	} data;
};

template<>
struct VariantStruct<>
{};

}

template<typename ...Args>
class Variant
{};

template<typename Arg, typename ...Args>
class Variant<Arg, Args...>
{
public:
	using Me = Variant<Arg, Args...>;
	using VariantStruct = variant_utils::VariantStruct<Arg, Args...>;

	template<Types::size_t INDEX>
	using TypeGetter = flame_ide::templates::TypeGetter<INDEX, Arg, Args...>;

	Variant() noexcept;
	Variant(const Me &me) noexcept;
	Variant(Me &&me) noexcept;

	template<typename T>
	explicit Variant(const T &initObject) noexcept;

	template<typename T>
	explicit Variant(T &&initObject);

	Me &operator=(const Me &me);
	Me &operator=(Me &&me) noexcept;

	operator bool() const noexcept;

	bool isSet() const;

	void reset() noexcept;

	template<Types::size_t INDEX>
	typename TypeGetter<INDEX>::Type *get();

	template<Types::size_t INDEX>
	const typename TypeGetter<INDEX>::Type *get() const;

	template<typename T>
	Types::ssize_t set(T &&object);

	template<typename T>
	Types::ssize_t set(const T &object);

	Types::ssize_t getCurrentIndex() const;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	bool get(T &object) const;

private:
	struct Getter
	{
		template<Types::size_t INDEX>
		typename TypeGetter<INDEX>::Type *data(Me &me) noexcept;

		template<typename T>
		T *data(Me &me) noexcept;
	};

	struct GetterConst
	{
		template<Types::size_t INDEX>
		const typename TypeGetter<INDEX>::Type *data(const Me &me) noexcept;

		template<typename T>
		const T *data(const Me &me) noexcept;
	};

	struct Setter
	{
		template<typename T>
		bool data(Me &me, T &&) noexcept;

		template<typename T>
		bool data(Me &me, const T &) noexcept;
	};

	static constexpr bool VALUE = IsUniqueParameterPack<Arg, Args...>::VALUE;
	static_assert(VALUE, "Paramter pack is not unique.");

	VariantStruct value;
	Types::ssize_t currentIndex;
};

}}

namespace flame_ide
{namespace templates
{

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant() noexcept
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(const Me &me) noexcept
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(Me &&me) noexcept
{}

template<typename Arg, typename ...Args>
template<typename T>
Variant<Arg, Args...>::Variant(const T &initObject) noexcept
{}

template<typename Arg, typename ...Args>
template<typename T>
Variant<Arg, Args...>::Variant(T &&initObject)
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(const Me &me)
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(Me &&me) noexcept
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::operator bool() const noexcept
{}

template<typename Arg, typename ...Args>
bool Variant<Arg, Args...>::isSet() const
{}

template<typename Arg, typename ...Args>
void Variant<Arg, Args...>::reset() noexcept
{}

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
typename TypeGetter<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get()
{}

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
const typename TypeGetter<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get() const
{}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(T &&object)
{}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(const T &object)
{}

template<typename Arg, typename ...Args>
Types::ssize_t Variant<Arg, Args...>::getCurrentIndex() const
{}

template<typename Arg, typename ...Args>
template<typename T>
T *Variant<Arg, Args...>::get()
{}

template<typename Arg, typename ...Args>
template<typename T>
const T *Variant<Arg, Args...>::get() const
{}

template<typename Arg, typename ...Args>
template<typename T>
bool Variant<Arg, Args...>::get(T &object) const
{}

// Getter

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
typename TypeGetter<INDEX, Arg, Args...>::Type *
Variant<Arg, Args...>::Getter::data(Me &me) noexcept
{}

template<typename Arg, typename ...Args>
template<typename T>
T *Variant<Arg, Args...>::Getter::data(Me &me) noexcept
{}

// GetterConst

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
const typename TypeGetter<INDEX, Arg, Args...>::Type *
Variant<Arg, Args...>::GetterConst::data(const Me &me) noexcept
{}

template<typename Arg, typename ...Args>
template<typename T>
const T *Variant<Arg, Args...>::GetterConst::data(const Me &me) noexcept
{}

// Setter

template<typename Arg, typename ...Args>
template<typename T>
bool Variant<Arg, Args...>::Setter::data(Me &me, T &&) noexcept
{}

template<typename Arg, typename ...Args>
template<typename T>
bool Variant<Arg, Args...>::Setter::data(Me &me, const T &) noexcept
{}

}}

#endif // TEMPLATES_VARIANT_HPP
