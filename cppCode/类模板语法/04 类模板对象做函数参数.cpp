//#include<iostream>
//using namespace std;
//#include<string>
//
////��ģ���������������
//template<class T1, class T2>
//class Person {
//public:
//	T1 name;
//	T2 age;
//	Person(T1 name, T2 age) {
//		this->name = name;
//		this->age = age;
//	}
//	void show() {
//		cout << "������" << this->name << " ���䣺" << this->age << endl;
//	}
//};
//
////1.ָ�����������
//void printPerson(Person<string, int>& p) {
//	p.show();
//}
//
//void test01() {
//	Person<string, int> p("����", 20);
//	printPerson(p);
//}
//
////2.����ģ�滯
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p) {
//	p.show();
//	cout << "ģ�滯������" << typeid(T1).name() << " " << typeid(T2).name() << endl;
//}
//
//void test02() {
//	Person<string, int> p("����", 20);
//	printPerson2(p);
//}
//
////3.������ģ�滯
//template<class T>
//void printPerson3(T& p) {
//	p.show();
//	cout << "ģ�滯������" << typeid(T).name() << endl;
//}
//void test03() {
//	Person<string, int> p("����", 20);
//	printPerson3(p);
//}
//
//int main() {
//
//	test01();
//	test02();
//	test03();
//
//	system("pause");
//	return 0;
//}