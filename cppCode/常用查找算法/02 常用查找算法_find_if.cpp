//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//#include<string>
//
////���ò����㷨_find_if
//
////1.����������������
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//���������е�һ������5������
//	vector<int>::iterator it = find_if(v.begin(), v.end(), [](int val) {
//		return val > 5;
//		});
//	if (it == v.end()) {
//		cout << "δ�ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ��ˣ���һ������5������Ϊ��" << *it << endl;
//	}
//}
//
////2.�����Զ�����������
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
//	//���ҵ�һ���������20����
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), [](Person p) {
//		return p.age > 20;
//		});
//	if (it == v.end()) {
//		cout << "δ�ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ��ˣ���һ���������20����Ϊ��" << it->name << endl;
//	}
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}