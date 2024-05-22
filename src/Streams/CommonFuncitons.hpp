#ifndef COMMONFUNCTIONS_HPP
#define COMMONFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The Descriptors struct
///
struct Descriptors
{
	struct ResultValue
	{
		constexpr ResultValue() noexcept : fd{}, status{}
		{}

		constexpr ResultValue(os::FileDescriptor initFd
				, os::Status initStatus) noexcept :
				fd{initFd}, status{initStatus}
		{}

		os::FileDescriptor fd;
		os::Status status;
	};

	constexpr Descriptors() noexcept : reader{}, writer{}
	{}

	constexpr Descriptors(ResultValue initReader, ResultValue initWriter) noexcept :
			reader{ initReader }, writer{ initWriter }
	{}

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
/// @warning Platform-depend function.
/// @param pipeName
/// @param action
/// @return
///
Descriptors makeNamedPipe(const char *pipeName, os::ActionType action) noexcept;

///
/// @brief destroyNamedReader
/// @warning Platform-depend function.
/// @param descriptor
/// @return
///
os::Status destroyNamedReader(Descriptors::ResultValue descriptor) noexcept;

///
/// @brief destroyNamedWriter
/// @warning Platform-depend function.
/// @param descriptor
/// @return
///
os::Status destroyNamedWriter(Descriptors::ResultValue descriptor) noexcept;

///
/// @brief destroyNamedPipe
/// @param descriptors
///
Descriptors destroyNamedPipe(Descriptors descriptors) noexcept;

}}

#endif // COMMONFUNCTIONS_HPP
