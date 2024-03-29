#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std::literals::string_literals;

namespace string_library
{
	template <typename CharT>
	using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

	template<typename CharT>
	using tstringstream = std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CHarT>>;


	template <typename CharT>
	inline tstring<CharT> to_upper(tstring<CharT> text)
	{
		std::transform(std::begin(text), std::end(text), std::begin(text), toupper);
		return text;
	}

	template <typename CharT>
	inline tstring<CharT> to_lower(tstring<CharT>text)
	{
		std::transform(std::begin(text), std::end(text), std::begin(text), tolower);
		return text;
	}

	template <typename CharT>
	inline tstring<CharT> reverse(tstring<CharT> text)
	{
		std::reverse(std::begin(text), std::end(text));
		return text;
	}

	template <typename CharT>
	inline tstring<CharT> trim(tstring<CharT> const& text)
	{
		auto first{ text.find_first_not_of(' ') };
		auto last{ text.find_last_not_of(' ') };
		return text.substr(first, (last - first + 1));
	}

	template <typename CharT>
	inline tstring<CharT> trimleft(tstring<CharT> const& text)
	{
		auto first{ text.find_first_not_of(' ') };
		return text.substr(first, text.size() - first);
	}

	template <typename CharT>
	inline tstring<CharT> trimright(tstring<CharT> const& text)
	{
		auto last{ text.find_last_not_of(' ') };
		return text.substr(0, last + 1);
	}

	template <typename CharT>
	inline tstring<CharT> trim(tstring<CharT> const& text, tstring<CharT> const& chars)
	{
		auto first{ text.find_first_not_of(chars) };
		auto last{ text.find_last_not_of(chars) };
		return text.substr(first, (last - first + 1));
	}

	template <typename CharT>
	inline tstring<CharT> trimleft(tstring<CharT> const& text, tstring<CharT> const& chars)
	{
		auto first{ text.find_first_not_of(chars) };
		return text.substr(first, text.size() - first);
	}

	template <typename CharT>
	inline tstring<CharT> trimright(tstring<CharT> const& text, tstring<CharT> const& chars)
	{
		auto last{ text.find_last_not_of(chars) };
		return text.substr(0, last + 1);
	}

	template <typename CharT>
	inline tstring<CharT> remove(tstring<CharT> text, CharT const ch)
	{
		auto start = std::remove_if(std::begin(text), std::end(text), [=](CharT const c) {return c == ch; });
		text.erase(start, std::end(text));
		return text;
	}
	template <typename CharT>
	inline std::vector<tstring<CharT>> split
	(tstring<CharT> text, CharT const delimiter)
	{
		auto sstr = tstringstream<CharT>{ text };
		auto tokens = std::vector<tstring<CharT>>{};
		auto token = tstring <CharT>{};

		while (std::getline(sstr, token, delimiter))
		{
			if (!token.empty())tokens.push_back(token);
		}
		return tokens;
	}
}
//#define MAIN
#ifdef MAIN
int main()
{
	auto ut{ string_library::to_upper("this is not UPPERCASE"s) };
	auto lt{ string_library::to_lower("THIS IS NOT lowercase"s )};
	auto rt{ string_library::reverse("cookbook"s) };
	auto text1{ " this is an example "s };
	auto t1{ string_library::trim(text1) };
	auto t2{ string_library::trimleft(text1) };
	auto t3{ string_library::trimright(text1) };
	auto chars1{ " !%\n\r"s };
	auto text3{"!! this % needs a lot\rof trimming !\n"s};
	auto t7{ string_library::trim(text3,chars1) };
	auto t8{ string_library::trimleft(text3,chars1) };
	auto t9{ string_library::trimright(text3,chars1) };
	auto text4{ "must remove all * from text**"s };
	auto t10{ string_library::remove(text4,'*') };
	auto t11{ string_library::remove(text4,'!') };

	auto text5{ "this text will be split "s };

	auto tokens1{ string_library::split(text5,' ' ) };
	auto tokens2{ string_library::split(""s,' ') };
}
#endif