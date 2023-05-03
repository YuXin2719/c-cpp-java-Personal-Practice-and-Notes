#include <iostream>
#define day 7 //1.#define 宏常量

using namespace std;

int main()
{

	//整型 （int较常用）
	// 
	//1、短整型（-32768 ~ 32767）
	short num1 = 32768; //结果是-32768，循环回来了

	//2、整型 （...~...）
	int num2 = 10;

	//3、长整型 （...~...）
	long num3 = 10;

	//4、长长整型 （...~...）
	long long num4 = 10;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	return 0;
}