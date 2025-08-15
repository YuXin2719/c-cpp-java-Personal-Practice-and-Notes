//#include<iostream>
//using namespace std;
//
////函数模板注意事项
//
//template <typename T> //typename可以替换为class
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////1.自动类型推导，必须推导出一致的数据类型T才可以使用
//void test01() {
//	int a = 10, b = 20;
//	char c = 'A';
//	mySwap(a, b); //编译器自动推导出T为int类型
//	//mySwap(a, c); //编译器无法推导出T的类型，因为int和char类型不一致
//	cout << "a=" << a << ",b=" << b << endl;
//}
//
////2.模版必须确定出T的类型才能使用
//template <typename T>
//void func() {
//	cout << "func() called" << endl;
//}
//
//void test02() {
//	//func(); //编译器无法推导出T的类型
//	func<int>(); //显示指定T的类型为int
//	func<double>(); //显示指定T的类型为double
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}