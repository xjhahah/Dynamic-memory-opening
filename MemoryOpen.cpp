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

	void* operator new(size_t size)   //��������ṩ��operator new ���㲻�����ǵ�������Ե����Լ�����ĺ���
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
//ģ��ʵ�� operator new
void* operator new(size_t size)
{
	return malloc(size);
}
int main()
{
	int array[10];
	array[0] = 0;

	//��λnew���ʽ������ռ��˷�
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

     //�ڵײ���һ��_callnnew����ָ�룬������Ӧ�Կռ䲻��Ĳ��ȴ�ʩ���׳��쳣
	


	//�õ������mallocû�е��ù��캯��������new�����˹��캯����˵����malloc��������Ŀռ䲻��һ������
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
	cout << *((int*)p2 - 1) << endl;   //����ڴ���ƫ�Ƶ�4���ֽڷŵ���ʲô
	delete p1;
	delete[] p2;
	return 0;
}
*/