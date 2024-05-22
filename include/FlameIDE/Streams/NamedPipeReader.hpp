#ifndef FLAMEIDE_STREAMS_NAMEDPIPEREADER_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPEREADER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/FileStreamReader.hpp>

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeReader class
///
class NamedPipeReader: public FileStreamReader
{
public:
	using Parent = FileStreamReader;

	NamedPipeReader() noexcept;
	NamedPipeReader(const NamedPipeReader &) noexcept = delete;
	NamedPipeReader(NamedPipeReader &&reader) noexcept;

	///
	/// @brief NamedPipeReader
	/// @param name
	/// @param deletePipe
	///
	NamedPipeReader(const char *name) noexcept;

	virtual ~NamedPipeReader() noexcept;

	NamedPipeReader &operator=(const NamedPipeReader &) noexcept = delete;
	NamedPipeReader &operator=(NamedPipeReader &&reader) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	///
	/// @brief open
	/// @param name
	/// @param deletePipe
	/// @return
	///
	os::Status open(const char *name) noexcept;

	///
	/// @brief getName
	/// @return
	///
	const templates::String &getName() const noexcept;

protected:
	templates::String fname; ///<
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPEREADER_HPP
