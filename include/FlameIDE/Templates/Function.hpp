#ifndef FLAMEIDE_TEMPLATES_FUNCTION_HPP
#define FLAMEIDE_TEMPLATES_FUNCTION_HPP

#include <FlameIDE/Templates/Tuple.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{namespace templates
{

/// TODO
/// Предполагается, что внутри будут храниться аргументы + сам контекст функтора.
/// Вопросы, которые возникают:
/// 1. Типизация функутора? -> скорее всего отдельный аргумент шаблона.
/// 2. Создание этого говна -> если нет функтора, то как его типизировать?
/// 3. Разворачивание кортежа в список параметров.
/// 4. Может какие-то дополнительные классы надо -> думаем.
/// 5. ...
/// 6. PROFIT!

namespace function_utils
{

} // namespace function_utils

template<typename Signature>
class Function
{};

template<typename ResultType, typename ...ArgumetTypes>
class Function<ResultType(ArgumetTypes...)>
{
	class AbstractCaller;

public:

private:
	class AbstractCaller
	{
	public:
		virtual ~AbstractCaller() = default;

		virtual void call() = 0;
	};

	template<typename CallContext>
	class Caller : public AbstractCaller
	{
	};

private:
	UniquePointer<AbstractCaller> callerptr;
};



}}

#endif // FLAMEIDE_TEMPLATES_FUNCTION_HPP
