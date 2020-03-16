#include <iostream>
#include <string>
#include <regex>

using namespace std::literals::string_literals;

auto text
{ R"(
	#remove # to uncomment the following lines
	timeout=120
	server=127.0.0.1

	#retrycount=3
)"s};


int main()
{
	auto pattern{ R"(^(?!#)(\w+)\s*=\s*([\w\d]+[\w\d._,\-:]*)$)"s };
	auto rx = std::regex{ pattern};
	auto match = std::smatch{};

	if (std::regex_search(text, match, rx))
	{
		std::cout << match[1] << '=' << match[2] << std::endl;
	}
	{
		auto end = std::sregex_iterator{};
		for (auto it = std::sregex_iterator{ std::begin(text), std::end(text), rx};it != end;++it)
		{
			std::cout <<'\''<<(*it)[1]<<"' = '"<<(*it)[2]<<'\'' << std::endl;
		}
	}

	{
		auto end = std::sregex_token_iterator{};
		for (auto it = std::sregex_token_iterator{
			std::begin(text),std::end(text),rx,};
			it != end; ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	return 0;
}
