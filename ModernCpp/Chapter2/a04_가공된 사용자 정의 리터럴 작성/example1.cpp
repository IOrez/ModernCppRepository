#include <array>
namespace compunits
{
	constexpr size_t operator "" _KB(unsigned long long const size)
	{
		return static_cast<size_t>(size * 1024);
	}

}

using namespace compunits;

auto size{ 4_KB };
using byte = unsigned char;
auto buffer = std::array<byte, 1_KB>{};