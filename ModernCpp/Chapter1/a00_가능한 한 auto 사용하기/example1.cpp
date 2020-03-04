#include <initializer_list>
#include <string>
#include <vector>
#include <memory>

/*Ư�� Ÿ�Կ� Ŀ��X*/
auto i = 43;				//int
auto d = 42.5;				//double
auto s = "text";			//char const*
auto v = { 1,2,3 };			//std::initializer_list<int>

/*Ư�� Ÿ�Կ� Ŀ��*/
auto b = new char[10]{ 0 };				//char*
auto s1 = std::string{ "text" };		//std::string
auto v1 = std::vector<int>{ 1,2,3 };	//std::vector
auto p = std::make_shared<int>(42);		//std::shared_ptr<int>


/*auto name = lamdaexpression*/
auto upper = [](char const c) {return toupper(c); };
auto add = [](auto const a, auto const b) {return a + b; };

//Ư�� Ÿ�Կ� Ŀ���ϰ� ���� ���� �� �Լ� ��ȯ Ÿ���� �����Ϸ��� ������ ���� �����Ѵ�.
template<typename F,typename T>
auto apply(F&& f, T value)
{
	return f(value);
}