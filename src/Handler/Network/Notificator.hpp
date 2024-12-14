#ifndef HANDLERNOTIFICATOR_HPP
#define HANDLERNOTIFICATOR_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Common/ReferenceWrapper.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
#include <FlameIDE/Os/Threads/ConditionVariable.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Notificator: public os::async::network::NotificatorBase
{
public:
	Notificator(
			templates::StaticArray<
				ReferenceWrapper<os::threads::ConditionVariable>
				, generated::network::Config::HANDLER_NUMBER_OF_WORKERS
			> &&initCondvars
	);
	virtual ~Notificator();

	virtual void operator()() const noexcept override;

private:
	templates::StaticArray<
		ReferenceWrapper<os::threads::ConditionVariable>
		, generated::network::Config::HANDLER_NUMBER_OF_WORKERS
	> condvars;
	Types::size_t currentIndex = 0;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERNOTIFICATOR_HPP
