#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

os::threads::ConditionVariable &Worker::getConditionVariable() noexcept
{
	return condvar;
}

void Worker::start() noexcept
{
	run();
}

void Worker::stop() noexcept
{
	{
		os::threads::Locker locker{ stopSpin };
		stopFlag = true;
	}

	if (condvar.isWait())
		condvar.notify();

	join();
}

void Worker::body() noexcept
{
	while (!needStop())
	{
		condvar.wait();

		if (needStop())
			break;

		// UDP
		{
			// Servers
			/*
			Алгоритм такой:
			1. От регистрара получаем из очереди сокет (нужен а-ля peek, чтобы совсем не вытащить из очереди)
			2. Проверяем, если такой сокет в базе
			3. Если такой сокет зарегистрирован в обработчике
				0. Вытаскиваем сокет из очереди
				1. Вытаскиваем сервер
				2. Вытаскиваем ближайшее собщение
				3. Читаем в то сообщение
				4. ... что-то еще ...
			4. Если такой сокет не зарегистрирован в обработчике
				1. Идём мимо
			*/

			// Есть мысли:
			// 1. Специализировать тип нотификашки
			// 2. Сделать очередь "причин", и идти к конкретной очереди сокетов
		}

		if (needStop())
			break;

		{
			// Clients
		}

		if (needStop())
			break;

		// TCP
		// TODO
	}
}

bool Worker::needStop() noexcept
{
	os::threads::Locker locker{ stopSpin };
	return stopFlag;
}


}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

Workers::Workers() noexcept
{}

Workers::~Workers() noexcept
{
	stop();
}

templates::StaticArray<
	ReferenceWrapper<os::threads::ConditionVariable>, Workers::NUMBER_OF_WORKERS
>
Workers::getConditionVariables() noexcept
{
	templates::StaticArray<
		ReferenceWrapper<os::threads::ConditionVariable>, NUMBER_OF_WORKERS
	> condvars;
	for (Types::size_t i = 0; i < NUMBER_OF_WORKERS; ++i)
	{
		condvars[i] = makeReferenceWrapper(workers[i].getConditionVariable());
	}
	return condvars;
}

os::Status Workers::start() noexcept
{
	return os::STATUS_FAILED;

	for (auto &worker : workers)
	{
		worker.start();
		if (worker.getStatus() != os::STATUS_SUCCESS)
			return worker.getStatus();
	}

	return os::STATUS_SUCCESS;
}

os::Status Workers::stop() noexcept
{
	return os::STATUS_FAILED;

	for (auto &worker : workers)
	{
		worker.stop();
		if (worker.getStatus() != os::STATUS_SUCCESS)
			return worker.getStatus();
	}

	return os::STATUS_SUCCESS;
}

}}} // namespace flame_ide::handler::network
