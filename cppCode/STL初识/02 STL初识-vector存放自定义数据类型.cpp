//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<algorithm>
//
////vector存放自定义数据类型
//class Person {
//public:
//	string name;
//	int age;
//	Person(string n, int a) : name(n), age(a) {}
//};
//
//void test01() {
//	//定义一个vector存放Person对象
//	vector<Person> v;
//	//添加元素
//	v.push_back(Person("Alice", 30));
//	v.push_back(Person("Bob", 25));
//	//遍历输出
//	for_each(v.begin(), v.end(), [](const Person& p) {
//		cout << "Name: " << p.name << ", Age: " << p.age << endl;
//		});
//}
//
////存放自定义数据类型的指针
//void test02() {
//	//定义一个vector存放Person对象的指针
//	vector<Person*> v;
//	//添加元素
//	v.push_back(new Person("Alice", 30));
//	v.push_back(new Person("Bob", 25));
//	//遍历输出
//	for_each(v.begin(), v.end(), [](const Person* p) {
//		cout << "Name: " << p->name << ", Age: " << p->age << endl;
//		});
//	//释放内存
//	for (auto p : v) {
//		delete p;
//	}
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