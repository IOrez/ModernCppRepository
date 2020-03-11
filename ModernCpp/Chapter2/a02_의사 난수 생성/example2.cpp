#include <iostream>
#include <random>
#include <chrono>


int main()
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto mtgen = std::mt19937{ static_cast<unsigned int>(seed)};


}