#include <initializer_list>

int i{ 1.2 };//오류
double d = 47 / 13;
float f1{ d };//오류
float f2{ 47 / 13 };//OK

int i{ static_cast<int>(1.2) };
double d = 47 / 13;
float f1{ static_cast<float>(d) };

auto a = { 42 };	//std::initializer_list<int>
auto b{ 42 };		//int
auto c = { 4,2 };	//std::initializer_list<int>
auto d{ 4,2 };		//오류: 인지가 너무 많음