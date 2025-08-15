//#include<iostream>
//using namespace std;
//#include<string>
//
////模版的局限性
////模板不是万能的，有些特定的数据类型，需要用具体化的方式做特殊实现
//
//class Person {
//public:
//	Person(string name, int age) : name(name), age(age) {}
//	//姓名，年龄
//	string name;
//	int age;
//};
//
////对比两个数据的函数
//template<typename T>
//bool compare(T& a, T& b) {
//	if (a == b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
////利用具体化的方式，给Person类型做一个特殊实现
//template<>
//bool compare<Person>(Person& p1, Person& p2) { //<Person>可省略，因为编译器可以通过参数类型推导出来这个模板函数特化用于Person类型
//	if (p1.name == p2.name && p1.age == p2.age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void test02() {
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	//compare(p1, p2);//error,没有可用的==运算符重载
//	if (compare(p1, p2)) {
//		cout << "p1和p2相等" << endl;
//	}
//	else {
//		cout << "p1和p2不相等" << endl;
//	}
//}
//
//int main() {
//	test02();
//	system("pause");
//	return 0;
//}