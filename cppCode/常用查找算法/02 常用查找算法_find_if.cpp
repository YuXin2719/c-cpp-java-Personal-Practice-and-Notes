//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//#include<string>
//
////常用查找算法_find_if
//
////1.查找内置数据类型
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//查找容器中第一个大于5的数字
//	vector<int>::iterator it = find_if(v.begin(), v.end(), [](int val) {
//		return val > 5;
//		});
//	if (it == v.end()) {
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到了，第一个大于5的数字为：" << *it << endl;
//	}
//}
//
////2.查找自定义数据类型
//class Person {
//public:
//	Person(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//	string name;
//	int age;
//};
//void test02() {
//	vector<Person>v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	//查找第一个年龄大于20的人
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), [](Person p) {
//		return p.age > 20;
//		});
//	if (it == v.end()) {
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到了，第一个年龄大于20的人为：" << it->name << endl;
//	}
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}