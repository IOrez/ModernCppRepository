class Base
{
	virtual void foo() = 0;
	virtual void bar() {}
	virtual void foobar() = 0;
};

void Base::foobar() {}

class Derived1 :public Base
{
	virtual void foo() override = 0;
	virtual void bar()override {}
	virtual void foobar()override {}
};

class Derived2 :public Derived1
{
	virtual void foo()final {}
};

class Derived4 final :public Derived1
{
	virtual void foo()override {}
};