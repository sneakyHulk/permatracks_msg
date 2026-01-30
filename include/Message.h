#pragma once

#include <common_time.h>

#include <cstdint>
#include <ostream>

template <typename Type>
struct Message : public Type {
	std::uint64_t timestamp;
	std::string src;
};

template <typename Type>
std::ostream& operator<<(std::ostream& os, Message<Type> const& msg) {
	os << "{'timestamp': " << common::from_uint64_t(msg.timestamp) << ", 'src': " << msg.src << ", 'data': " << static_cast<Type const&>(msg) << "}";

	return os;
}