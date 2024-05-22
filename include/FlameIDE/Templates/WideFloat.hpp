#ifndef FLAMEIDE_TEMPLATES_WIDEFLOAT_HPP
#define FLAMEIDE_TEMPLATES_WIDEFLOAT_HPP

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Templates/Array.hpp>

/*
 * В данном файле представлен интерфейс WideFloat с
 * фиксированным количеством бит.
 * Что нужно сделать:
 * 1. Необходимо полностью реализовать класс.
 * 2. Обезательно всё noexcept.
 * 2.1. В случае, если это невозможно, можно изменить
 * интерфейс, добавив метод проверки состояния с
 * возвратом соотвествующего enum class.
 * 3. C++14 (если необходимо, можно и на 17-й стандарт
 * перейти - в настройках CMake стандарт не указан)
 * 4. Тест лежит в src/ (если не создан, то желательно бы создать)
 * 5. ... по вопросам, общаться ко мне @AntonKashcheev :)
 */

namespace flame_ide
{namespace templates
{

template<Types::ulong_t FRACTION, Types::ulong_t EXPANENT>
class WideFloat
{
public:
	static constexpr Types::ulong_t BITS = FRACTION + EXPANENT + 1; // + Sign

	using Me = WideFloat<FRACTION, EXPANENT>;

	WideFloat() = default;
	WideFloat(const Me&) = default;

	template<typename IntegerType>
	WideFloat(IntegerType value);

	WideFloat(const char *strValue);

	template<typename IntegerType>
	Me &operator=(IntegerType &value);
	Me &operator=(const Me &value);

	template<typename IntegerType>
	Me &operator=(const IntegerType &value);

	template<typename IntegerType>
	Me &operator+(IntegerType value);
	Me &operator+(const Me &value);

	template<typename IntegerType>
	Me &operator+=(IntegerType value);
	Me &operator+=(const Me &value);

	template<typename IntegerType>
	Me &operator-(IntegerType value);
	Me &operator-(const Me &value);

	template<typename IntegerType>
	Me &operator-=(IntegerType value);
	Me &operator-=(const Me &value);

	template<typename IntegerType>
	Me &operator*(IntegerType value);
	Me &operator*(const Me &value);

	template<typename IntegerType>
	Me &operator*=(IntegerType value);
	Me &operator*=(const Me &value);

	template<typename IntegerType>
	Me &operator/(IntegerType value);
	Me &operator/(const Me &value);

	template<typename IntegerType>
	Me &operator/=(IntegerType value);
	Me &operator/=(const Me &value);

	Me &operator++();
	Me &operator++(int);
	Me &operator--();
	Me &operator--(int);

private:
};

//using Float80 = WideFloat<80>;
//using Float128 = WideFloat<128>;

}}

#endif // WIDEFLOAT_HPP
