//#include<iostream>
//using namespace std;
//
////函数模板
//
////交换两个整形交换的函数
//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////交换两个浮点型的函数
//void swap(float& a, float& b) {
//	float temp = a;
//	a = b;
//	b = temp;
//}
//
////函数模板的定义
//template <typename T> //声明一个模板类型T，告诉编译器，T是一个类型参数
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test01() {
//	int a = 10, b = 20;
//	float c = 1.1f, d = 2.2f;
//
//	//swap(a, b); //调用整形的交换函数
//	//swap(c, d); //调用浮点型的交换函数
//
//	//使用函数模板
//	//两种方式使用函数模板
//	//1.显示指定类型
//	mySwap<int>(a, b); //显示指定类型为int
//	//2.编译器自动推导类型
//	mySwap(c, d); //编译器自动推导类型为float
//
//	cout << "a=" << a << ",b=" << b << endl;
//	cout << "c=" << c << ",d=" << d << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}