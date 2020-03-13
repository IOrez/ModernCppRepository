#include <iostream>
#include <string>

using namespace std::literals::string_literals;

auto filename{ R"(C:\Users\Marius\Documents\)"s };
auto filename1{ R"(C:\\Users)\\Marius\\Documents\\)"s };



auto pattern{ R"((\w+)=(\d+)$)"s };

auto sqlselect{
	R"(SELECT * FROM Books WHERE Publisher='Paktpub' ORDER BY PubDate DESC)"s
};

int main()
{
	auto text{ R"!!(this text contains both "( and )".)!!"s };
	/* C:\Users\Marius\Documents\ */
	std::cout << filename << std::endl;
	/* C:\\Users\\Marius\\Document\\*/
	std::cout << filename1 << std::endl;

	std::cout << pattern << std::endl;
	std::cout << sqlselect << std::endl;
	std::cout << text << std::endl;


	auto t1{ LR"(text)" };					//const whar_t*
	auto t2{ u8R"(text)" };					//const char*
	auto t3{ uR"(text)" };					//const char16_t*;
	auto t4{ UR"(text)" };					//const char32_t*;

	auto t5{ LR"(text)"s };					//wstring
	auto t6{ u8R"(text)"s };				//string
	auto t7{ uR"(text)"s };					//u16string
	auto t8{ UR"(text)"s };					//u32string

}