#pragma once

#if __has_include(<common_time.h>)
#include <common_time.h>
#endif

#include <cstdint>
#include <ostream>

template <typename Type>
struct Message : public Type {
	std::uint64_t timestamp;
	std::string src;
};

template <typename Type>
std::ostream& operator<<(std::ostream& os, Message<Type> const& msg) {
#if __has_include(<common_time.h>)
	os << "{'timestamp': " << common::from_uint64_t(msg.timestamp) << ", 'src': " << msg.src << ", 'data': " << static_cast<Type const&>(msg) << "}";
#else
	os << "{'timestamp': " << msg.timestamp << ", 'src': " << msg.src << ", 'data': " << static_cast<Type const&>(msg) << "}";
#endif
	return os;
}