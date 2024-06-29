#ifndef FILEFUNCTIONS_HPP
#define FILEFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Common/Expected.hpp>

namespace flame_ide
{namespace os
{namespace file
{

enum class Access
{
	READ = 1 << 0
	, WRITE = 1 << 1
};

using ExpectedFile = flame_ide::os::Expected<os::FileDescriptor>;
using ExpectedFileSize = flame_ide::os::Expected<flame_ide::Types::ssize_t>;

ExpectedFile open(const char *name, Access access) noexcept;

ExpectedFile create(const char *name, Access access) noexcept;

bool close(os::FileDescriptor &descriptor) noexcept;

bool remove(const char *name) noexcept;

ExpectedFileSize size(os::FileDescriptor descriptor) noexcept;

void read(os::FileDescriptor descriptor) noexcept;

void write(os::FileDescriptor descriptor) noexcept;

void position(os::FileDescriptor descriptor) noexcept;

}}} // namespace flame_ide::os::file

#endif // FILEFUNCTIONS_HPP
