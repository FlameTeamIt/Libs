#ifndef PIPEFUNCTIONS_HPP
#define PIPEFUNCTIONS_HPP

#include <FlameIDE/Templates/Expected.hpp>
#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{

struct PipeDescriptors
{
	DescriptorPair pair = DESCRIPTOR_PAIR_INITIALIZER;
};

Status createPipes(PipeDescriptors &pipes) noexcept;

void destroyPipes(PipeDescriptors &descriptors) noexcept;

}} // namespace flame_ide::os

#endif // PIPEFUNCTIONS_HPP
