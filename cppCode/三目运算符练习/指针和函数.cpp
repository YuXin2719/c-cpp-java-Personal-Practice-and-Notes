//#include <iostream>
//#include <string>
//
//using namespace std;
//
////实现两个数字互换
//void swap1(int num1, int num2)
//{
//	int temp = num1;
//	num1 = num2;
//	num2 = temp;
//	
//	cout << "swap1 a = " << num1 << endl;
//	cout << "swap1 b = " << num2 << endl;
//}
//
//void swap2(int* p1, int* p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//int main()
//{
//
//	//指针和函数
//
//	int a = 10;
//	int b = 20;
//
//	//1.值传递
//	//swap1(a, b);
//
//	//2.地址传递
//	//如果是地址传递，可以修饰实参
//	//也就是说传进去地址，然后解地址直接操作地址指向的内存
//	swap2(&a, &b);
//
//	cout << "a = " << a << endl; //20
//	cout << "b = " << b << endl; //10
//
//	system("pause");
//	return 0;
//}