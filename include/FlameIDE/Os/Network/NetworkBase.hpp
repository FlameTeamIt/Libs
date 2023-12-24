#ifndef FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP
#define FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP

#include <FlameIDE/Os/Network/Ipv4.hpp>
#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class NetworkBase: public NonCopy
{
public:
	using Range = templates::Range<byte_t *>;
	using ConstRange = templates::Range<const byte_t *>;

public:
	enum class SocketType: int
	{
		UNKNOWN = -1
		, STREAM = SOCK_STREAM
		, DATAGRAM = SOCK_DGRAM
	};

	struct NativeCallbacks;

public:
	~NetworkBase() noexcept;
	operator bool() const noexcept;

	Status getStatus() const noexcept;
	const Socket &native() const;

public:
	static const NativeCallbacks &callbacks() noexcept;

protected:
	NetworkBase() noexcept = default;
	NetworkBase(Socket socket) noexcept;
	NetworkBase(NetworkBase &&base) noexcept;

	NetworkBase &operator=(NetworkBase &&base) noexcept;

	void setStatus(Status status) noexcept;

	SocketType getType() const;
	os::Status getError() const;
	bool isServer() const;
	bool isListener() const;

protected:
	static Types::int_t checkStatus(Status status) noexcept;

protected:
	Socket socket = SOCKET_INVALID;

private:
	Status status = STATUS_SUCCESS;
};

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

struct NetworkBase::NativeCallbacks
{
	NativeCallbacks() noexcept = default;
	NativeCallbacks(const NativeCallbacks &) noexcept = default;
	NativeCallbacks(NativeCallbacks &&) noexcept = default;
	~NativeCallbacks() noexcept = default;
	NativeCallbacks &operator=(const NativeCallbacks &) noexcept = default;
	NativeCallbacks &operator=(NativeCallbacks &&) noexcept = default;

	Status (*destroy)(Socket &socket) noexcept = {};
	Types::ssize_t (*receivingBytesNumber)(const Socket &socket) noexcept = {};
	Ipv4 (*getIpv4)(const Socket &socket) noexcept = {};
	NetworkBase::SocketType (*type)(const Socket &socket) noexcept = {};
	int (*error)(const Socket &socket) noexcept = {};
	bool (*isListener)(const Socket &socket) noexcept = {};
	bool (*isServer)(const Socket &socket) noexcept = {};
};

}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP
