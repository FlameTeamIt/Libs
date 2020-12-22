#ifndef FLAMEIDE_STREAMS_TESTS_NAMEDPIPETHEAD_HPP
#define FLAMEIDE_STREAMS_TESTS_NAMEDPIPETHEAD_HPP

#include <FlameIDE/Threads/Thread.hpp>
#include <FlameIDE/Templates/Variant.hpp>

#include <FlameIDE/Streams/NamedPipeReader.hpp>
#include <FlameIDE/Streams/NamedPipeWriter.hpp>

#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class NamedPipeThreadCreation : public threads::Thread
{
public:
	NamedPipeThreadCreation(const char *initName, os::ActionType initAction) noexcept :
			pipeName{ initName }, action{ initAction }
	{}

	templates::Variant<NamedPipeReader, NamedPipeWriter> &getResult()
	{
		return pipe;
	}

private:
	void vRun()
	{
		pipe.reset();
		if (action == os::ActionType::READER)
		{
			pipe.set(NamedPipeReader{ pipeName });
		}
		else if (action == os::ActionType::WRITER)
		{
			pipe.set(NamedPipeWriter{ pipeName });
		}
	}

	const char *pipeName;
	os::ActionType action;
	templates::Variant<NamedPipeReader, NamedPipeWriter> pipe;
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_NAMEDPIPETHEAD_HPP
