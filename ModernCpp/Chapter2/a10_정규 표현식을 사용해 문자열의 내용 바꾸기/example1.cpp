#include <iostream>
#include <regex>
#include <string>

using namespace std::string_literals;


auto text1{ "abc aa bca ca bbbb"s };
auto rx1 = std::regex{ R"(\b[a|b|c]{3}\b)"s };
auto newtext1 = std::regex_replace(text1, rx1, "---"s,std::regex_constants::format_first_only);

auto text2{ "bancila, marius"s };
auto rx2 = std::regex{ R"((\w+),\s*(\w+))"s };
auto newtext2 = std::regex_replace(text2, rx2, "$2 $1"s);

auto text3{ "this is a example with a errors" };
auto rx3 = std::regex{ R"(\ba ((a|e|i|u|o)\w+))"s };
auto newtext3 = std::regex_replace(text3, rx3, "an $1");

auto text4{ "today is 1.06.2016!!"s };
auto rx4 = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))"s };	//today is 2016.06.1!!
auto newtext4 = std::regex_replace(text4, rx4, R"($5$4$3$2$1)");
auto newtext5 = std::regex_replace(text4, rx4, R"([$'][$&][$'])");

int main()
{
	std::cout << newtext1 << std::endl;
	std::cout << newtext2 << std::endl;
	std::cout << newtext3 << std::endl;
	std::cout << newtext4 << std::endl;
	std::cout << newtext5 << std::endl;
	return 0;
}