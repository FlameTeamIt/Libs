#ifndef FLAMEIDE_TEMPLATES_RAIICALLER_HPP
#define FLAMEIDE_TEMPLATES_RAIICALLER_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<typename DestructorCall>
struct RaiiCaller
{
	template<typename ConstructorCall>
	RaiiCaller(ConstructorCall &&ctorCall, DestructorCall &&initDtorCall) noexcept :
			RaiiCaller(move(initDtorCall))
	{
		ctorCall();
	}

	RaiiCaller(DestructorCall &&initDtorCall) noexcept :
			dtorCall(move(initDtorCall))
	{}

	~RaiiCaller() noexcept
	{
		dtorCall();
	}

private:
	DestructorCall dtorCall;
};

template<typename ConstructorCall, typename DestructorCall>
RaiiCaller<DestructorCall>
makeRaiiCaller(ConstructorCall &&initCtorCall, DestructorCall &&initDtorCall)
{
	return RaiiCaller<DestructorCall>(move(initCtorCall), move(initDtorCall));
}

template<typename DestructorCall>
RaiiCaller<DestructorCall>
makeRaiiCaller(DestructorCall &&initDtorCall)
{
	return RaiiCaller<DestructorCall>(move(initDtorCall));
}

}}

#endif // FLAMEIDE_TEMPLATES_RAIICALLER_HPP
