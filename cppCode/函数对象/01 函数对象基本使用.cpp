//#include<iostream>
//using namespace std;
//#include<string>
//
////函数对象（仿函数）
///*
//- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//- 函数对象超出普通函数的概念，函数对象可以有自己的状态
//- 函数对象可以作为参数传递
//*/
//
////1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
////普通函数
//int add(int a, int b) {
//	return a + b;
//}
////函数对象
//class Add {
//public:
//	int operator()(int a, int b) {
//		return a + b;
//	}
//};
//
//void test01() {
//	cout << add(10, 20) << endl;
//
//	Add add2;
//	cout << add2(10, 20) << endl;
//}
//
////2.函数对象超出普通函数的概念，函数对象可以有自己的状态
//class myPrint {
//public:
//	myPrint() {
//		count = 0;
//	}
//	void operator()(string str) {
//		cout << str << endl;
//		count++;
//	}
//	int count; //内部状态
//};
//
//void test02() {
//	myPrint p;
//	p("hello world");
//	p("hello world");
//	cout << "p函数对象被调用了：" << p.count << "次" << endl;
//}
//
////3.函数对象可以作为参数传递
//void doPrint(myPrint& p, string str) {
//	p(str);
//}
//
//void test03() {
//	myPrint p;
//	doPrint(p, "hello");
//	doPrint(p, "world");
//	cout << "p函数对象被调用了：" << p.count << "次" << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	test03();
//	system("pause");
//	return 0;
//}