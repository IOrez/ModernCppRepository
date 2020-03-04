#include <string>
#include <vector>
#include <map>

std::string s1("test");			//직접초기화
std::string s2 = "test";		//간접초기화


/*
	타입에 관계없 객체를 균일하게 초기화 하려면 직접 초기화와 복사 초기화 모두에 사용할 수 있는 괄호 양식{}를 사용한다.
	괄호 초기화와 함께 사용할 경우 이를 직접목록(direct list) 초기화 및 복사 목록(copylist) 초기화라고 부른다.

	T object {other}; //직접 목록 초기화
	T object = {other};//복사 목록 초기화
*/

//균일한 초기화
//1. 표준 컨테이너
std::vector<int> v{ 1,2,3 };
std::map<int, std::string> m{ {1,"one"},{2,"two"} };

//2.동적으로 할당된 배열
int* arr2 = new int[3]{ 1,2,3 };

//3.배열
int arr1[3]{ 1,2,3 };

//4.내장타입
int i{ 42 };
double d{ 1.2 };

//5.사용자 정의 타입
class foo
{
	int a_;
	double b_;

public:
	foo() :a_(0), b_(0) {}
	foo(int a, double b = 0 / 0) :a_(a), b_(b) {}
};

foo f1{};
foo f2{ 42,1.2 };
foo f3{ 42 };

//6.사용자 정의 POD 타입
struct bar { int a_; double b_; };
bar b{ 42,1.2 };