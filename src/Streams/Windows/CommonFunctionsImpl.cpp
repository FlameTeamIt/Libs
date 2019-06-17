#include "../CommonFuncitons.hpp"
#include <FlameIDE/Threads/Thread.hpp>

#include <iostream>

namespace flame_ide
{namespace streams
{

namespace
{

Descriptors::ResultValue makeNamedPipeClient(const char *pipeName)
{
	os::FileDescriptor pipe = ::CreateFileA(
			pipeName
			, GENERIC_WRITE // only need write access
			, FILE_SHARE_READ | FILE_SHARE_WRITE
			, nullptr
			, OPEN_EXISTING
			, FILE_ATTRIBUTE_NORMAL
			, nullptr
	);

	if (!pipe.handle || pipe == os::INVALID_DESCRIPTOR)
	{
		auto err = ::GetLastError();
		return { pipe, err };
	}

	return { pipe, os::STATUS_SUCCESS };
}

Descriptors::ResultValue makeNamedPipeServer(const char *pipeName)
{
	os::FileDescriptor pipe = ::CreateNamedPipeA(
			pipeName // name of the pipe
			, PIPE_ACCESS_INBOUND // 1-way pipe -- receive only
			, PIPE_TYPE_BYTE // receive data as a byte stream
			, 1 // only allow 1 instance of this pipe
			, 0 // no outbound buffer
			, os::windows::OS_INBOUND_BUFFER_SIZE // inbound buffer
			, 0 // use default wait time
			, nullptr // use default security attributes
	);

	if (!pipe.handle || pipe == os::INVALID_DESCRIPTOR)
	{
		auto err = ::GetLastError();
		return { pipe, err };
	}

	if (!::ConnectNamedPipe(pipe, nullptr))
	{
		auto err = ::GetLastError();
		::CloseHandle(pipe);
		return { os::INVALID_DESCRIPTOR, err };
	}

	return { pipe, os::STATUS_SUCCESS };
}

}

Descriptors::ResultValue makeNamedReader(const char *pipeName) noexcept
{
	Descriptors::ResultValue fdResult = makeNamedPipeServer(pipeName);
	return fdResult;
}

Descriptors::ResultValue makeNamedWriter(const char *pipeName) noexcept
{
	Descriptors::ResultValue fdResult = makeNamedPipeClient(pipeName);
	return fdResult;
}

os::Status destroyNamedReader(Descriptors::ResultValue descriptor) noexcept
{
	if (!::DisconnectNamedPipe(descriptor.fd))
	{
		return -::GetLastError();
	}

	if (!CloseHandle(descriptor.fd))
	{
		return -::GetLastError();
	}

	return os::STATUS_SUCCESS;
}

os::Status destroyNamedWriter(Descriptors::ResultValue descriptor) noexcept
{
	if (!CloseHandle(descriptor.fd))
	{
		return -::GetLastError();
	}

	return os::STATUS_SUCCESS;
}

}}

