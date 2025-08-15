//#include<iostream>
//using namespace std;
//
////普通函数和函数模板的调用规则
////1.如果函数模板和普通函数都可以匹配，优先调用普通函数
////2.可以通过空模版参数列表的方式，强制调用函数模板
////3.函数模板也可以发生重载
////4.如果函数模板可以产生更好的匹配，编译器会优先选择函数模板
//
////假如普通函数只是声明,没有定义,编译器依旧会选择普通函数,导致报错
//void myPrint(int a, int b) {
//	cout << "普通函数调用" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b) {
//	cout << "函数模板调用" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b, T c) {
//	cout << "重载的函数模板调用" << endl;
//}
//
//
//void test01() {
//	myPrint(10, 20); //普通函数调用
//	myPrint<>(10, 20); //函数模板调用
//	myPrint(10, 20, 30); //重载的函数模板调用
//	//如果函数模板产生更好的匹配，编译器会优先选择函数模板
//	char a = 'a';
//	char b = 'b';
//	myPrint(a, b); //函数模板调用
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}