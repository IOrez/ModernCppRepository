#include <string_view>
#include <string>

std::string_view get_filename(std::string_view str)
{
	auto const pos1{ str.find_last_of('\\') };
	auto const pos2{ str.find_last_of('.') };
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

std::string_view trim_view(std::string_view str)
{
	auto const pos1{ str.find_first_not_of(" ") };
	auto const pos2{ str.find_last_not_of(" ") };
	str.remove_suffix(str.length() - pos2 - 1);
	str.remove_prefix(pos1);
	return str;
}

char const file1[]{ R"(c:\test\example1.doc)" };
auto name1 = get_filename(file1);

std::string file2{ R"(c:\test\exampel2)" };
auto name2 = get_filename(file2);

auto name3 = get_filename(std::string_view{file1,16});

int main()
{
	auto sv1{ trim_view("sample") };
	auto sv2{ trim_view(" sample") };
	auto sv3{ trim_view("sample ") };
	auto sv4{ trim_view(" sample ") };

	auto s1{ std::string(sv1.data())};
	auto s2{ sv2.data() };
	auto s3{ sv3.data() };
	auto s4{ sv4.data() };
}