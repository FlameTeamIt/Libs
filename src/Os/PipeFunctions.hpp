#ifndef PIPEFUNCTIONS_HPP
#define PIPEFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

struct PipeDescriptors
{
	FileDescriptor descriptors[2];
};

Status createPipes(PipeDescriptors &descriptors) noexcept;

Status destroyPipes(PipeDescriptors &descriptors) noexcept;

}} // namespace flame_ide::os

#endif // PIPEFUNCTIONS_HPP
