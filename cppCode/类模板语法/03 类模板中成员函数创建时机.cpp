//#include<iostream>
//using namespace std;
//
////类模板中成员函数创建时机
////类模板中成员函数在调用时才创建
//
//class Person1 {
//public:
//	//成员函数
//	void showPerson1() {
//		cout << "showPerson1调用" << endl;
//	}
//};
//
//class Person2 {
//public:
//	//成员函数
//	void showPerson2() {
//		cout << "showPerson2调用" << endl;
//	}
//};
//
//template<class T>
//class MyClass {
//public:
//	T obj;
//	//成员函数
//	void func1() {
//		cout << "func1调用" << endl;
//		obj.showPerson1();
//	}
//
//	void func2() {
//		cout << "func2调用" << endl;
//		obj.showPerson2();
//	}
//};
//
//void test01() {
//	//创建类模板对象
//	MyClass<Person1> myClass1;
//	//调用成员函数
//	myClass1.func1();
//
//	//创建类模板对象
//	MyClass<Person2> myClass2;
//	//调用成员函数
//	myClass2.func2();
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}