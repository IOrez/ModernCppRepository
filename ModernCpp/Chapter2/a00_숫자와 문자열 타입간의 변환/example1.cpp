#include <iostream>
#include <string>
#include <stdexcept>

auto si = std::to_string(42);						//si = "42"
auto sl = std::to_string(42l);						//sl = "42"
auto su = std::to_string(42u);						//su = "42"
auto sd = std::to_wstring(42.0);					//sd = "42.000000"
auto sld = std::to_wstring(42.0l);					//sld = "42.000000"

auto i1 = std::stoi("42");
auto i2 = std::stoi("101010", nullptr, 2);			//i2 = 42
auto i3 = std::stoi("052", nullptr, 8);				//i3 = 42	
auto i4 = std::stoi("0x2A", nullptr, 16);			//i4 = 42
auto pos = size_t{ 0 };
auto i5 = std::stoi("42", &pos);					//pos = 2
auto i6 = std::stoi("-42", &pos);					//pos = 3
auto i7 = std::stoi(" +42dec", &pos);				//pos = 5
auto i8 = std::stoi("-42");							//i8 = -42


auto d1 = std::stod("123.45");						//d1 = 123.45000000000000
auto d2 = std::stod("1.2345e+2");					//d2 = 123.45000000000000
auto d3 = std::stod("0xF.6E6666p3");				//d3 = 123.44999980926514				p-> 2의 거듭제곱을 나타내는 접미사 p3은 3의 거듭제곱
																							//15.4312499 * 2^3 = 15.4312499 * 8 = 123.44999980926514
auto d4 = std::stod("INF");							//d4 = inf
auto d5 = std::stod("-infinity");					//d5 = -inf
auto d6 = std::stod("NAN");							//d6 = nan
auto d7 = std::stod("-nanabc");						//d7 = nan

int main()
{
	try
	{
		auto i16 = std::stoi("");
	}
	catch (std::exception const& e)
	{
		//"invalid stoi argument" 출력
		std::cout << e.what() << std::endl;
	}

	try
	{
		//OK
		auto i17 = std::stoll("12345678901234");
		//std::out_of_range
		auto i18 = std::stoi("12345678901234");
	}
	catch (std::out_of_range const& e)
	{
		//"stoi argument out of range"
		std::cout << e.what() << std::endl;
	}
}