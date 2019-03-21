#ifndef FLAMEIDE_THREADS_THREAD_HPP
#define FLAMEIDE_THREADS_THREAD_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace threads
{

class Thread
{
public:

	/* something */

protected:
	using Result = DefaultTraits<void>::Pointer;
	using Arg = DefaultTraits<void>::Pointer;
	using CallBack = Result(*)(Arg);

private:
	static Result task(Arg arg);
};

}}

#endif // FLAMEIDE_THREADS_THREAD_HPP
