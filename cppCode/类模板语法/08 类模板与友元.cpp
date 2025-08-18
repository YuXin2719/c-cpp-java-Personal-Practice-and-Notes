//#include<iostream>
//using namespace std;
//#include<string>
//
////通过全局函数打印Person的信息
//
////提前让编译器直到Person类的存在
//template<class T1, class T2>
//class Person;
//
////类外实现
////需要写在Person类的前面
//template<class T1, class T2>
//void printPerson2(const Person<T1, T2>& p) {
//	cout << "类外实现 --- Name: " << p.name << ", Age: " << p.age << endl;
//}
//
//template<class T1, class T2>
//class Person {
//	//全局函数 类内实现
//	//为什么它是全局函数:
//	// 成员函数默认有一个 this指针（指向调用它的对象），但这个函数需要显式传入 Person对象（p），说明它不依赖 this。
//	// 如果它是成员函数，应该能直接访问 name和 age，而不需要 p.前缀。
//	// 重点就是需要传入一个Person对象，说明它不属于某个特定的 Person实例，因此是全局函数。
//	//加friend后，Person类的私有成员可以被printPerson访问
//	friend void printPerson(const Person<T1, T2>& p) {
//		cout << "类内实现 --- Name: " << p.name << ", Age: " << p.age << endl;
//	}
//
//	//全局函数 类外实现
//	//加空模板参数列表<>，表示这是一个模板函数
//	//如果全局函数是类外实现,需要让编译器提前知道这是一个模板函数
//	friend void printPerson2<>(const Person<T1, T2>& p);
//
//public:
//	Person(T1 n, T2 a) : name(n), age(a) {}
//private:
//	T1 name;
//	T2 age;
//};
//
////1.全局函数在类内实现
//void test01() {
//	Person<string, int> p("Tom", 20);
//	printPerson(p); //调用全局函数
//}
//
////2.全局函数在类外实现
//void test02() {
//	Person<string, int> p("Jerry", 22);
//	printPerson2(p); //调用全局函数
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