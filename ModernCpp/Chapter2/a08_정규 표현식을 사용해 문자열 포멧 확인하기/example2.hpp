#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <tuple>

using namespace std::string_literals;

template <typename CharT>
using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template <typename CharT>
bool is_valid_format(tstring<CharT> const& pattern, tstring<CharT> const& text)
{
	auto rx = std::basic_regex<CharT>{
		pattern,std::regex_constants::icase};
	return std::regex_match(text, rx);
}

bool is_vaild_email_format_w(std::wstring const& text)
{
	return is_valid_format(
		LR"(^[A-Z0-9._%+=]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s, text
	);
}

std::tuple<bool,std::string,std::string,std::string>
is_valid_email_format_with_result(std::string const& email)
{
	auto rx = std::regex{
		R"(^([A-Z0-9._%+=]+)@([A-Z0-9.-]+)\.([A-Z]{2,})$)"s,std::regex_constants::icase
	};
	auto result = std::smatch{};
	auto success = std::regex_match(email, result, rx);

	return std::make_tuple(
		success,
		success ? result[1].str() : ""s,
		success ? result[2].str() : ""s,
		success ? result[3].str() : ""s
	);
}

auto ltest2 = [](auto const& email)
{
	std::wcout << std::setw(30) << std::left <<
		email << ":" << (is_vaild_email_format_w(email) ? "valid format" : "invalid format") << std::endl;
};

auto ltest3 = [](std::string const& email)
{
	auto [valid, localpart, hostname, dnslabel] =
		is_valid_email_format_with_result(email);

	std::cout << std::setw(30) << std::left <<
		email << ":" << (valid ? "valid format " : "invalid format ") << "local=" << localpart << ";domain=" << hostname << ";dns=" << dnslabel << std::endl;

};

int main()
{
	ltest2(L"JOHN.DOE@DOMAIN.COM"s);
	ltest2(L"JOHNDOE@DOMAIL.CO.UK"s);
	ltest2(L"JOHNDOE@DOMAIL.INFO"s);
	ltest2(L"J.O.H.N_D.O.E@DOMAIL.INFO"s);
	ltest2(L"ROOT@LOCALHOST"s);
	ltest2(L"john.doe@domain.com"s);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	ltest3("JOHN.DOE@DOMAIN.COM"s);
	ltest3("JOHNDOE@DOMAIL.CO.UK"s);
	ltest3("JOHNDOE@DOMAIL.INFO"s);
	ltest3("J.O.H.N_D.O.E@DOMAIL.INFO"s);
	ltest3("ROOT@LOCALHOST"s);
	ltest3("john.doe@domain.com"s);

	return 0;
}