#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	//1.引用必须初始化
	//int& b;	错误
	int& b = a;


	//2.引用一旦初始化，就不可以改变
	int c = 20;

	b = c; //赋值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	return 0;
}