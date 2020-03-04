#include <iostream>
#include <string>
#include <type_traits>
using namespace std::string_literals;

class foo {
	int x_;
public:
	foo(int const x = 0) :x_{ x } {}
	int& get() { return x_; }
};

decltype(auto) proxy_get(foo& f) { return f.get(); }
auto ladd = [](auto const a, auto const b) {return a + b; };

struct
{
	template<typename T,typename U>
	auto operator()(T const a, U const b)const { return a + b; }
}L;

/*
	�̵��� �� ���� Ÿ���� ��� auto�� ����� �� ����.
	auto ai = std::atomic<int>(42);

	���� �ܾ� Ÿ�Կ� auto ����� �� ����
	auto l1 = long long{42};
*/


int main()
{
	foo f(42);
	auto& x = proxy_get(f);
	std::cout << f.get() << std::endl;

	auto i = ladd(40, 2);
	auto s = ladd("forty"s, "two"s);
}