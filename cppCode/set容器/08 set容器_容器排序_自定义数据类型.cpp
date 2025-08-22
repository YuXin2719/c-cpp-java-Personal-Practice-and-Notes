//#include<iostream>
//using namespace std;
//#include<set>
//#include<string>
//
////set容器排序,存放自定义数据类型
//
//class Person {
//public:
//	Person(int a, string n) : age(a), name(n) {}
//	//默认构造函数
//	Person() : age(0), name("Unknown") {}
//	int age;
//	string name;
//	//重载<运算符,用于set容器排序
//	bool operator<(const Person& p) const {
//		return this->age < p.age; //按年龄升序排列
//	}
//	//重载<<运算符,用于输出
//	friend ostream& operator<<(ostream& os, const Person& p) {
//		os << "Name: " << p.name << ", Age: " << p.age;
//		return os;
//	}
//};
//
////打印set容器中的Person对象
//void printSet(const set<Person>& s) {
//	for (const auto& person : s) { //使用范围for循环遍历set,auto关键字自动推导类型
//		cout << person << endl;
//	}
//}
//
//void test01() {
//	set<Person> s;
//	Person p1{ 25, "Alice" };
//	Person p2{ 30, "Bob" };
//	Person p3{ 20, "Charlie" };
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	cout << "Set contents (sorted by age):" << endl;
//	printSet(s);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}