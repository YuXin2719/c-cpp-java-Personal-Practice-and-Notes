//#include<iostream>
//using namespace std;
//#include<string>
//
////类模板对象做函数参数
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
//		cout << "姓名：" << this->name << " 年龄：" << this->age << endl;
//	}
//};
//
////1.指定传入的类型
//void printPerson(Person<string, int>& p) {
//	p.show();
//}
//
//void test01() {
//	Person<string, int> p("张三", 20);
//	printPerson(p);
//}
//
////2.参数模版化
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p) {
//	p.show();
//	cout << "模版化参数：" << typeid(T1).name() << " " << typeid(T2).name() << endl;
//}
//
//void test02() {
//	Person<string, int> p("张三", 20);
//	printPerson2(p);
//}
//
////3.整个类模版化
//template<class T>
//void printPerson3(T& p) {
//	p.show();
//	cout << "模版化参数：" << typeid(T).name() << endl;
//}
//void test03() {
//	Person<string, int> p("张三", 20);
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