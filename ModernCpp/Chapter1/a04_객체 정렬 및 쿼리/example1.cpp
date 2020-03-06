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

struct foo1 //크기 = 1, 정렬 = 1
{
	char a;
};

struct foo2 //크기 = 2, 정렬 = 1
{
	char a;
	char b;
};

struct foo3 //크기 = 8, 정렬 = 4
{
	char a;
	int	 b;
};