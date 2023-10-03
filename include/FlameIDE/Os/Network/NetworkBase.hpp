#ifndef FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP
#define FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP

#include <FlameIDE/Os/Network/Ipv4.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class NetworkBase: public NonCopy
{
public:
	enum class SocketType: int
	{
		UNKNOWN = -1
		, STREAM = SOCK_STREAM
		, DATAGRAM = SOCK_DGRAM
	};

	using Range = templates::Range<byte_t *>;
	using ConstRange = templates::Range<const byte_t *>;

	struct NativeControl
	{
		NativeControl() noexcept = default;
		NativeControl(const NativeControl &) noexcept = default;
		NativeControl(NativeControl &&) noexcept = default;
		~NativeControl() noexcept = default;
		NativeControl &operator=(const NativeControl &) noexcept = default;
		NativeControl &operator=(NativeControl &&) noexcept = default;

		Status (*destroy)(Socket &socket) noexcept = nullptr;
		Types::ssize_t (*receivingBytesNumber)(const Socket &socket) noexcept = nullptr;
		Ipv4 (*getIpv4)(const Socket &socket) noexcept = nullptr;
		SocketType (*type)(const Socket &socket) noexcept = nullptr;
		int (*error)(const Socket &socket) noexcept = nullptr;
		bool (*isListener)(const Socket &socket) noexcept = nullptr;
		bool (*isServer)(const Socket &socket) noexcept = nullptr;
	};

public:
	~NetworkBase() noexcept;
	operator bool() const noexcept;

	Status getStatus() const noexcept;
	const Socket &native() const;

public:
	static const NativeControl &nativeControl() noexcept;

protected:
	NetworkBase(Socket socket) noexcept;
	NetworkBase(NetworkBase &&base) noexcept;

	NetworkBase &operator=(NetworkBase &&base) noexcept;

	void setStatus(Status status) noexcept;

	SocketType getType() const;
	os::Status getError() const;
	bool isServer() const;
	bool isAcceptor() const;

protected:
	static Types::int_t checkStatus(Status status) noexcept;

protected:
	Socket socket;

private:
	Status status = 0;
};

}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_NETWORKBASE_HPP
