#include <iostream>

#include <string>
#include <string.h>
#include <memory>
class string_buffer
{
private:
	std::string str;
public:
	explicit string_buffer() {}
	explicit string_buffer(size_t const size) { str.reserve(size); }
	explicit string_buffer(char const* const ptr) 
	{
		int len = strlen(ptr);
		str.reserve(len + 1);
		str = ptr;
	}

	size_t size()const { return str.size(); }
	explicit  operator bool()const { return true; }
	explicit  operator char const*() { return str.c_str(); }
};

enum ItemSizes{DefaultHeight,Large,MaxSize};
int main()
{
	std::shared_ptr<char> obj = std::make_shared<char>();
	string_buffer b1;
	string_buffer b2(20);
	string_buffer b3(obj.get());

	string_buffer b4 = string_buffer('a');
	string_buffer b5 = static_cast<string_buffer>(MaxSize);
	string_buffer b6 = string_buffer{ "a" };

	std::cout << static_cast<bool>(b1) + static_cast<bool>(b2);
	if (static_cast<bool>(b1) == static_cast<bool>(b2)) {}
}