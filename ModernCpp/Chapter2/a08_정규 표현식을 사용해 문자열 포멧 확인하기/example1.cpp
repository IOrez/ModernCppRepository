#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

using namespace std::string_literals;

auto pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s };
auto rx = std::regex{ pattern };
auto rx2 = std::regex{ pattern,std::regex_constants::icase };

auto valid = std::regex_match("marius@domain.com"s, rx2);


bool is_valid_email_format(std::string const& email)
{
	auto pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)" };
	
	/*
		auto rx = std::regex{ pattern};
	
	/*/
		auto rx = std::regex{ pattern,std::regex_constants::icase };
	
	//*/
	return std::regex_match(email, rx);
}


int main()
{
	auto ltest = [](std::string const& email)
	{
		std::cout << std::setw(30) << std::left << email << ":" <<
			(is_valid_email_format(email) ? "valid format" : "invalid format") << std::endl;
	};

	ltest("JOHN.DOE@DOMAIN.COM"s);
	ltest("JOHNDOE@DOMAIL.CO.UK"s);
	ltest("JOHNDOE@DOMAIL.INFO"s);
	ltest("J.O.H.N_D.O.E@DOMAIL.INFO"s);
	ltest("ROOT@LOCALHOST"s);
	ltest("john.doe@domain.com"s);

	return 0;
}