//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//
////常用查找算法_count
//
////1.统计内置数据类型
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(40);
//	v.push_back(50);
//	//统计20的个数
//	int num = count(v.begin(), v.end(), 20);
//	cout << "20的个数为：" << num << endl;
//}
//
////2.统计自定义数据类型
//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//	bool operator==(const Person& p) const {
//		if (this->m_Age == p.m_Age) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//};
//void test02() {
//	vector<Person>v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("bbb", 20);
//	Person p5("eee", 50);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	//统计年龄为20的人数
//	int num = count_if(v.begin(), v.end(), [](Person& p) {
//		return p.m_Age == 20;
//		});
//	cout << "年龄为20的人数为：" << num << endl;
//	//或者通过重载==号来实现
//	int num2 = count(v.begin(), v.end(), p2);
//	cout << "年龄为20的人数为：" << num2 << endl;
//}
//
//int main() {
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}