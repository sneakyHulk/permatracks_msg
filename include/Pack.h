#pragma once

#include <ostream>

// for Pack<Value<int>, Value<double>>
template <typename T>
struct Value {
	T value;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Value<T> const& v) {
	return os << v.value;
}

template <typename... Types>
requires(std::is_class_v<Types> && ...) struct Pack : public Types... {};

template <typename... Types>
std::ostream& operator<<(std::ostream& os, Pack<Types...> const& msg) {
	char space[]{0, 0, 0};
	os << '{';
	(... << (os << space << static_cast<Types const&>(msg), space[0] = ',', space[1] = ' '));
	os << '}';
	return os;
}