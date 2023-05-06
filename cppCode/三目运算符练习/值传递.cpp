//#include <iostream>
//#include <string>
//
//using namespace std;
//
////值传递
////定义函数，实现两个数字交换的函数
//
////如果函数不需要返回值，声明的时候可以写 void（翻译：无效）
//void swap(int num1, int num2)
//{
//
//	cout << "交换前：" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//
//	int temp = num1;
//	num1 = num2;
//	num2 = temp;
//
//	cout << "交换后：" << endl;
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//
//	return;
//}
//
//int main()
//{
//
//	int a = 10;
//	int b = 20;
//	
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	//当我们做值传递的时候，函数的形参发生改变，不会影响到实参
//	swap(a, b);
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	system("pause");
//	return 0;
//}