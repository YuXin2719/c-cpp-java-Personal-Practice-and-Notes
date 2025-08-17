//#include<iostream>
//using namespace std;
//
////类模板和函数模板的区别
//template <class NameType, class AgeType = int>
//class Person {
//public:
//	NameType name;
//	AgeType age;
//	Person(NameType n, AgeType a) : name(n), age(a) {}
//	void show() {
//		cout << "Name: " << name << ", Age: " << age << endl;
//	}
//};
//
////1.类模板没有自动类型推导的使用方式
//void test01() {
//	//Person p("孙悟空", 1000); //错误的，无法用自动类型推导
//	Person<string, int> p("孙悟空", 1000); //正确的，只能用显示指定类型的方式
//	p.show();
//}
////2.类模板在模板参数列表中可以有默认参数
//void test02() {
//	Person<string> p1("猪八戒", 500); //只有类模板可以使用默认参数
//	p1.show();
//}
//
//int main() {
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}