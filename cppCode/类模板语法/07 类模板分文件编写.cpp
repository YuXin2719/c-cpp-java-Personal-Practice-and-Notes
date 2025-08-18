//#include<iostream>
//using namespace std;
//#include<string.h>
//
////第一种解决方式，直接包含源文件
////#include"person.cpp"
//
////第二种解决方式（常用），将.h和.cpp写到一起，将后缀名改为.hpp
//#include"person.hpp"
//
////类模板的分文件编写问题以及解决方式
//
////template<class T1, class T2>
////class Person {
////public:
////	Person(T1 n, T2 a);
////	void showPerson();
////	T1 name;
////	T2 age;
////};
////
////template<class T1, class T2>
////Person<T1, T2>::Person(T1 n, T2 a) {
////	name = n;
////	age = a;
////}
////template<class T1, class T2>
////void Person<T1, T2>::showPerson() {
////	cout << "name: " << name << endl;
////	cout << "age: " << age << endl;
////}
//
//void test() {
//	Person<string, int> p1("Tom", 20);
//	p1.showPerson();
//}
//
//int main() {
//
//	test();
//
//	system("pause");
//	return 0;
//}