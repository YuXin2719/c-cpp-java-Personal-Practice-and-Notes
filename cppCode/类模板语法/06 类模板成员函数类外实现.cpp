//#include<iostream>
//using namespace std;
//#include<string>
//
////��ģ���Ա��������ʵ��
//template <class T1, class T2>
//class Person {
//public:
//	Person(T1 name, T2 age);
//	void show();
//	T1 name;
//	T2 age;
//};
//
////���캯������ʵ��
//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
////��Ա��������ʵ��
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