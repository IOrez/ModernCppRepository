struct alignas(4) foo
{
	char a;
	char b;
};

struct  bar
{
	alignas(2) char a;
	alignas(8) int b;
};

alignas(8) int a;
alignas(256) long b[4];

auto align = alignof(foo);

struct foo1 //ũ�� = 1, ���� = 1
{
	char a;
};

struct foo2 //ũ�� = 2, ���� = 1
{
	char a;
	char b;
};

struct foo3 //ũ�� = 8, ���� = 4
{
	char a;
	int	 b;
};