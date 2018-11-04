#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		_t = 0;
		cout << "Test():" << this << endl;
	}

	void* operator new(size_t size)   //如果库里提供的operator new 满足不了我们的需求可以调用自己定义的函数
	{
		return malloc(size);
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};
//模拟实现 operator new
void* operator new(size_t size)
{
	return malloc(size);
}
int main()
{
	int array[10];
	array[0] = 0;

	//定位new表达式，避免空间浪费
	new(array + 3) int(3);
	return 0;
}
/*
int  main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
*/
/*
int main()
{
	Test* pt1 = (Test*)malloc(sizeof(Test));
	Test* pt2 = new Test; 
	Test* pt3 = new Test[3];

     //在底层有一个_callnnew函数指针，是用来应对空间不足的补救措施，抛出异常
	


	//得到结果是malloc没有调用构造函数，但是new调用了构造函数，说明用malloc申请出来的空间不是一个对象
	free(pt1);
	delete pt2;
	delete[] pt3;
	return 0;
}
*/

/*
int main()
{
	Test* p1 = new Test;
	Test* p2 = new Test[10];
	cout << *((int*)p2 - 1) << endl;   //检测内存中偏移得4个字节放的是什么
	delete p1;
	delete[] p2;
	return 0;
}
*/