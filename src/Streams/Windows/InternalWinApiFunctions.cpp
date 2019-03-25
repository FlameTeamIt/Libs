#include "InternalWinApiFunctions.hpp"

#include <iostream>

namespace flame_ide
{namespace streams
{

namespace
{

DWORD getPageSize() noexcept
{
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	return info.dwPageSize;
}

inline os::FileDescriptor makeNamedPipeClient(const char *pipeName)
{
	os::FileDescriptor pipe = CreateFileA(
			pipeName
			, GENERIC_WRITE // only need write access
			, FILE_SHARE_WRITE
			, nullptr
			, OPEN_EXISTING
			, FILE_ATTRIBUTE_NORMAL
			, nullptr
	);

	if (!pipe.handle || pipe == os::INVALID_DESCRIPTOR)
	{
		auto err = GetLastError();
		return pipe;
	}

	return pipe;
}

inline os::FileDescriptor makeNamedPipeServer(const char *pipeName)
{
	os::FileDescriptor pipe = CreateNamedPipeA(
			pipeName // name of the pipe
			, PIPE_ACCESS_INBOUND | PIPE_NOWAIT // 1-way pipe -- receive only
			, PIPE_TYPE_BYTE // receive data as a byte stream
			, 1 // only allow 1 instance of this pipe
			, 0, 0, 0 // no outbound buffer, no inbound buffer, use default wait time
			, nullptr // use default security attributes
	);

	if (!pipe.handle || pipe == os::INVALID_DESCRIPTOR)
	{
		auto err = GetLastError();
		return pipe;
	}

	return pipe;
}

}

Descriptors makeNamedPipe(const char *pipeName, os::ActionType action) noexcept
{
	Descriptors descriptors = { os::INVALID_DESCRIPTOR, os::INVALID_DESCRIPTOR };

	switch (action)
	{
		case os::ActionType::READER:
		{
			descriptors.reader = makeNamedPipeClient(pipeName);
			break;
		}
		case os::ActionType::WRITER:
		{
			descriptors.writer = makeNamedPipeServer(pipeName);
			break;
		}
		case os::ActionType::BIDIRECTIONAL:
		{
			descriptors = Descriptors{
					makeNamedPipeServer(pipeName)
					, makeNamedPipeClient(pipeName)
			};
			break;
		}
	}

	return descriptors;
}

}}

