#pragma once

#include <cstdint>
#include <ostream>

template <typename Type>
struct Message : public Type {
	std::uint64_t timestamp;
	std::string src;
};

template <typename Type>
std::ostream& operator<<(std::ostream& os, Message<Type> const& msg) {
	os << "{'timestamp': " << msg.timestamp << ", 'src': " << msg.src << ", 'data': " << static_cast<Type const&>(msg) << "}";

	return os;
}