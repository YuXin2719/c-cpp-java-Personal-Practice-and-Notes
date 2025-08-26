//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//#include<string>
//
////常用查找算法_find
//
////查找内置数据类型
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//查找5
//	vector<int>::iterator it = find(v.begin(), v.end(), 5);
//	if (it == v.end()) {
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到元素：" << *it << endl;
//	}
//}
//
////查找自定义数据类型
//class Person {
//public:
//	Person(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//	string name;
//	int age;
//	//重载==号 让底层的find算法可以对Person类型进行查找
//	bool operator==(const Person& p) const {
//		if (this->name == p.name && this->age == p.age) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//};
//void test02() {
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	//查找
//	//必须在Person类中重载==号
//	Person p("bbb", 20); //或者直接查找p2
//	vector<Person>::iterator it = find(v.begin(), v.end(), p);
//	if (it == v.end()) {
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到元素：" << it->name << "," << it->age << endl;
//	}
//}
//
//int main() {
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}