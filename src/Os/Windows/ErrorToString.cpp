#include <FlameIDE/../../src/Os/ErrorToString.hpp>

#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode0.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode1.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode2.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode3.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode4.hpp> // ?
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode5.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode6.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode7.hpp> // +
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode8.hpp> // + | WSA
#include <FlameIDE/../../src/Os/Windows/Errors/SystemCode9.hpp> //
#include <FlameIDE/../../src/Os/Windows/Errors/WsaError.hpp>

namespace flame_ide
{namespace os
{namespace error
{

const char *errorInfo(flame_ide::os::Status status) noexcept
{
	const char *(*functions[])(os::Status) = {
			systemCodeToString0
			, systemCodeToString1
			, systemCodeToString2
			, systemCodeToString3
			, systemCodeToString4
			, systemCodeToString5
			, systemCodeToString6
			, systemCodeToString7
			, systemCodeToString8
			, wsaCodeToString
			, systemCodeToString9
	};

	const char *result = nullptr;
	for (auto i : functions)
	{
		result = i(status);
		if (result)
		{
			break;
		}
	}
	return result;
}

}}} // flame_ide::os::error
