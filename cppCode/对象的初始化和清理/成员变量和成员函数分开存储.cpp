#include <iostream>
using namespace std;

//��Ա���� �� ��Ա���� �Ƿֿ��洢��

class Person
{
	int m_A;
};

void test01()
{
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ��1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "sizeof p = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "sizeof p = " << sizeof(p) << endl;
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}