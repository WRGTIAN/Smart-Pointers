#include <iostream>
using namespace std;

template <typename T>            //管理权转移法
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& ap)        //拷贝构造
		:_ptr(ap._ptr)
	{
		delete ap->_ptr;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)  //赋值运算符重载
	{
		if (this != &ap) // this->_ptr= ap.ptr
		{
			delete _ptr;
			this->_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*()const 
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~AutoPtr()
	{
		if (NULL != _ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}
private:
	T* _ptr;
};

class AA
{
public:
	int a;
	int b;
};
void funtest1()
{
	AutoPtr<AA> ap1(new AA);
	(*ap1).a = 10;
	(*ap1).b = 20;
	ap1->a = 30;
	ap1->b = 40;
}
void funtest2()
{
	AutoPtr<int> ap3(new int[10]);
	AutoPtr<int> ap4(new int[5]);
	ap3 = ap4;
} 
int main()
{
	//funtest1();
	funtest2();
	system("pause");
	return 0;
}