//#include<iostream>
//using namespace std;
//#include<string>
//
////类模板成员函数类外实现
//template <class T1, class T2>
//class Person {
//public:
//	Person(T1 name, T2 age);
//	void show();
//	T1 name;
//	T2 age;
//};
//
////构造函数类外实现
//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
////成员函数类外实现
//template <class T1, class T2>
//void Person<T1, T2>::show() {
//	cout << "name: " << this->name << endl;
//	cout << "age: " << this->age << endl;
//}
//
//int main() {
//	Person<string, int> p("Tom", 20);
//	p.show();
//
//	system("pause");
//	return 0;
//}