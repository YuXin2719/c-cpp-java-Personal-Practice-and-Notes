//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//1.常量指针
//	int a = 10;
//	int b = 10;
//
//	const int* p = &a;
//	//指针指向的值不能改，指向可以改
//	//*p = 20; 错误
//	p = &b; //正确
//
//	//2.指针常量
//	int* const p1 = &a;
//	*p1 = 20; //正确
//	//p2 = &b; 错误
//
//	//3.const修饰常量和指针
//	const int* const p2 = &a;
//	//*p2 = 20; 错误
//	//p2 = &b; 错误
//
//	system("pause");
//	return 0;
//}