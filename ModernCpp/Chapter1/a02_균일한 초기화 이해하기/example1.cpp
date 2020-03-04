#include <string>
#include <vector>
#include <map>

std::string s1("test");			//�����ʱ�ȭ
std::string s2 = "test";		//�����ʱ�ȭ


/*
	Ÿ�Կ� ����� ��ü�� �����ϰ� �ʱ�ȭ �Ϸ��� ���� �ʱ�ȭ�� ���� �ʱ�ȭ ��ο� ����� �� �ִ� ��ȣ ���{}�� ����Ѵ�.
	��ȣ �ʱ�ȭ�� �Բ� ����� ��� �̸� �������(direct list) �ʱ�ȭ �� ���� ���(copylist) �ʱ�ȭ��� �θ���.

	T object {other}; //���� ��� �ʱ�ȭ
	T object = {other};//���� ��� �ʱ�ȭ
*/

//������ �ʱ�ȭ
//1. ǥ�� �����̳�
std::vector<int> v{ 1,2,3 };
std::map<int, std::string> m{ {1,"one"},{2,"two"} };

//2.�������� �Ҵ�� �迭
int* arr2 = new int[3]{ 1,2,3 };

//3.�迭
int arr1[3]{ 1,2,3 };

//4.����Ÿ��
int i{ 42 };
double d{ 1.2 };

//5.����� ���� Ÿ��
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

//6.����� ���� POD Ÿ��
struct bar { int a_; double b_; };
bar b{ 42,1.2 };