#ifndef FLAMEIDE_STREAMS_NAMEDPIPEWRITER_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPEWRITER

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/FileStreamWriter.hpp>
#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeWriter class
///
class NamedPipeWriter: public FileStreamWriter
{
public:
	using Parent = FileStreamWriter;

	NamedPipeWriter() noexcept;
	NamedPipeWriter(const NamedPipeWriter &) = delete;
	NamedPipeWriter(NamedPipeWriter &&writer) noexcept;

	///
	/// @brief NamedPipeWriter
	/// @param name
	/// @param deletePipe
	///
	NamedPipeWriter(const char *name, bool deletePipe = true) noexcept;

	~NamedPipeWriter() noexcept;

	NamedPipeWriter &operator=(const NamedPipeWriter &) = delete;
	NamedPipeWriter &operator=(NamedPipeWriter &&reader) noexcept;

	///
	/// @brief open
	/// @param name
	/// @param deletePipe
	/// @return
	///
	os::Status open(const char *name, bool deletePipe = true) noexcept;

	///
	/// @brief getName
	/// @return
	///
	const templates::String &getName() const noexcept;

private:
	templates::String fname; ///<
	bool delPipe; ///<
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPEWRITER
