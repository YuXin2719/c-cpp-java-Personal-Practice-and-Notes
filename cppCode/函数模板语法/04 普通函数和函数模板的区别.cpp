//#include<iostream>
//using namespace std;
//
////普通函数和函数模板的区别
//
////1.普通函数可以发生隐式类型转换，而函数模板不可以
////2.函数模板 用自动类型推导,不可以发生隐式类型转换
////2.函数模版 用显示指定类型,可以发生隐式类型转换
//
////普通函数
//int add1(int a, int b) {
//	return a + b;
//}
//
////函数模板
//template<typename T>
//T add2(T a, T b) {
//	return a + b;
//}
//
//void test01() {
//	int a = 10;
//	int b = 20;
//	char c = 'A'; //char类型的'A'对应的ASCII码是65
//	//cout << add(a, b) << endl; //30
//	cout << add1(a, c) << endl; //30
//
//	//自动类型推导,不会发生隐式类型转换
//	cout << add2(a, b) << endl; //30
//	//显示指定类型,可以发生隐式类型转换
//	cout << add2<int>(a, c) << endl; //75
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}