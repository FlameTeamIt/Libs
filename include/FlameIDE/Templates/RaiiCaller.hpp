#ifndef FLAMEIDE_TEMPLATES_RAIICALLER_HPP
#define FLAMEIDE_TEMPLATES_RAIICALLER_HPP

#include <FlameIDE/Common/Traits.hpp>

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

}}

#endif // FLAMEIDE_TEMPLATES_RAIICALLER_HPP
