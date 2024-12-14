#include <FlameIDE/../../src/Handler/Network/Notificator.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Notificator::Notificator(
		templates::StaticArray<
			ReferenceWrapper<os::threads::ConditionVariable>
			, generated::network::Config::HANDLER_NUMBER_OF_WORKERS
		> &&initCondvars
) : condvars{ move(initCondvars) }
{}

Notificator::~Notificator() = default;

void Notificator::operator()() const noexcept
{}

}}} // namespace flame_ide::handler::network
