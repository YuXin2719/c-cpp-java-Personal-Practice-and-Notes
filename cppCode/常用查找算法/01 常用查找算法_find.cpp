//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//#include<string>
//
////���ò����㷨_find
//
////����������������
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//����5
//	vector<int>::iterator it = find(v.begin(), v.end(), 5);
//	if (it == v.end()) {
//		cout << "δ�ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ�Ԫ�أ�" << *it << endl;
//	}
//}
//
////�����Զ�����������
//class Person {
//public:
//	Person(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//	string name;
//	int age;
//	//����==�� �õײ��find�㷨���Զ�Person���ͽ��в���
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
//	//����
//	//������Person��������==��
//	Person p("bbb", 20); //����ֱ�Ӳ���p2
//	vector<Person>::iterator it = find(v.begin(), v.end(), p);
//	if (it == v.end()) {
//		cout << "δ�ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ�Ԫ�أ�" << it->name << "," << it->age << endl;
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