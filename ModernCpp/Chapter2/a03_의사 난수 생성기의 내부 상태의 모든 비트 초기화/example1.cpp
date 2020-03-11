#include <random>
#include <array>

std::random_device rd;
std::array<int, std::mt19937::state_size>seed_data{};

int main()
{
	std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
	std::seed_seq seq(std::begin(seed_data), std::end(seed_data));

	auto eng = std::mt19937{ seq };

	auto dist = std::uniform_real_distribution<>{ 0,1 };
}