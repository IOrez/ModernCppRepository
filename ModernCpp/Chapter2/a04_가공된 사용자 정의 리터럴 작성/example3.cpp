#include <string>
using namespace std::string_literals;

auto s1{ "text"s };		//std::string
auto s2{ L"text"s };	//std::wstring
auto s3{ u"text"s };	//std::u16string
auto s4{ U"text"s };	//std::u32string


#include <chrono>
using namespace std::literals::chrono_literals;

//std::chrono::duration<long long>
auto timer{ 2h + 42min + 15s };

#include <complex>
using namespace std::literals::complex_literals;

auto c{ 12.0 + 4.5i };//std::complex<double>