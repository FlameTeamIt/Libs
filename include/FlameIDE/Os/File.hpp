#ifndef FLAMEIDE_OS_FILE_HPP
#define FLAMEIDE_OS_FILE_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

class File
{
public:
	enum class Access
	{
		READ = 1 << 0
		, WRITE = 1 << 1
	};

private:
};

inline File::Access operator|(File::Access access1, File::Access access2)
{
	using UnderlyingType = int;
	return static_cast<File::Access>(
			static_cast<UnderlyingType>(access1) | static_cast<UnderlyingType>(access2)
	);
}

inline File::Access operator&(File::Access access1, File::Access access2)
{
	using UnderlyingType = int;
	return static_cast<File::Access>(
			static_cast<UnderlyingType>(access1) & static_cast<UnderlyingType>(access2)
	);
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_FILE_HPP
