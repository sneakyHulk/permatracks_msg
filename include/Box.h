#pragma once

#include <ostream>
#include <tuple>

template <typename Type, typename... Types>
struct Box : public std::tuple<Type, Types...> {};

template <typename... Types>
std::ostream& operator<<(std::ostream& os, Box<Types...> const& msg) {
	os << '(';

	static auto apply = []<std::size_t... I>(std::ostream& os, Box<Types...> const& msg, std::index_sequence<I...>) { ((os << (I == 0 ? "" : ", ") << std::get<I>(msg)), ...); };
	apply(os, msg, std::index_sequence_for<Types...>{});

	os << ')';
	return os;
}