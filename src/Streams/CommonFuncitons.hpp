#ifndef COMMONFUNCTIONS_HPP
#define COMMONFUNCTIONS_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The Descriptors struct
///
struct Descriptors
{
	constexpr Descriptors() : reader{}, writer{}
	{}

	struct ResultValue
	{
		constexpr ResultValue() noexcept : fd{}, status{}
		{}

		constexpr ResultValue(
				os::FileDescriptor initFd
				, os::Status initStatus) noexcept
			: fd{initFd}, status{initStatus}
		{}

		os::FileDescriptor fd;
		os::Status status;
	};
	ResultValue reader;
	ResultValue writer;
};

///
/// @brief Create named pipe for reading.
/// @warning Platform-depend function.
/// @param[in] pipeName Name of pipe.
/// @return Struct with file descriptor or result.
///
Descriptors::ResultValue makeNamedReader(const char *pipeName) noexcept;

///
/// @brief Create named pipe for writing.
/// @warning Platform-depend function.
/// @param[in] pipeName Name of pipe.
/// @return Struct with file descriptor or result.
///
Descriptors::ResultValue makeNamedWriter(const char *pipeName) noexcept;

///
/// @brief Create pair of named pipes.
/// @param[in] pipeName Name of pipe.
/// @return Struct with reader and writer or error of creation.
///
Descriptors makeNamedBidirectional(const char *pipeName) noexcept;

///
/// @brief makeNamedPipe
/// @param pipeName
/// @param action
/// @return
///
Descriptors makeNamedPipe(const char *pipeName, os::ActionType action) noexcept;

}}

#endif // COMMONFUNCTIONS_HPP
