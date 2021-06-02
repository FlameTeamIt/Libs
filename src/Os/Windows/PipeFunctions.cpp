#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Os/PipeFunctions.hpp>

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{

Status createPipes(PipeDescriptors &descriptors) noexcept
{
	Status status = ::CreatePipe(
			&descriptors.descriptors[<int32_t>(os::ActionType::READER)].handle
			, &descriptors.descriptors[<int32_t>(os::ActionType::WRITER)].handle
			, nullptr
			, flame_ide::Constants::MAX_PIPE_BUFFER_SIZE
	);
	if (!status)
	{
		return ::GetLastError();
	}
	else
	{
		return 0;
	}
}

Status destroyPipes(PipeDescriptors &descriptors) noexcept
{
	::CloseHandle(descriptors.descriptors[<int32_t>(os::ActionType::READER)].handle);
	::CloseHandle(descriptors.descriptors[<int32_t>(os::ActionType::WRITER)].handle);
	return 0;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
