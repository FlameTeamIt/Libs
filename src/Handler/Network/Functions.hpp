#ifndef HANDLERINTERNALFUNCTIONS_HPP
#define HANDLERINTERNALFUNCTIONS_HPP

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

template<typename Pointer>
inline bool initPointer(Pointer &pointer, os::threads::Spin &spin) noexcept
{
	os::threads::Locker lock{ spin };
	if (!pointer)
		pointer = Pointer{};
	return pointer;
}

template<typename Pointer, typename LambdaCheck, typename LambdaAssign>
inline auto *pushData(Pointer &pointer, os::threads::Spin &spin
		, LambdaCheck &&check, LambdaAssign &&assignTo) noexcept
{
	using DataPointer = flame_ide::RemoveAllType<decltype(*pointer->begin())>;
	using Data = flame_ide::RemoveAllType<decltype(*(*pointer->begin()))>;

	os::threads::Locker lock{ spin };
	Data *data = nullptr;
	for (DataPointer &i : *pointer)
	{
		if (check(*i))
			continue;

		data = i.pointer();
		break;
	}
	assignTo(*data);
	return data;
}

template<
	typename Pointer, typename Data, typename LambdaCheck
	, typename LambdaReturn
>
inline auto popData(Pointer &pointer, os::threads::Spin &spin, Data &data
		, LambdaCheck &&check, LambdaReturn &&returnData) noexcept
{
	using DataPointer = flame_ide::RemoveAllType<decltype(*pointer->begin())>;
	using ReturnData = decltype(returnData(*data));

	os::threads::Locker lock{ spin };
	for (DataPointer &i : *pointer)
	{
		if (!check(*data, *i))
			continue;

		return returnData(*i);
	}
	return ReturnData{};
}

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNALFUNCTIONS_HPP
