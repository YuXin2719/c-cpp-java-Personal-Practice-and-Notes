//#include<iostream>
//using namespace std;
//#include<set>
//#include<string>
//
////set��������,����Զ�����������
//
//class Person {
//public:
//	Person(int a, string n) : age(a), name(n) {}
//	//Ĭ�Ϲ��캯��
//	Person() : age(0), name("Unknown") {}
//	int age;
//	string name;
//	//����<�����,����set��������
//	bool operator<(const Person& p) const {
//		return this->age < p.age; //��������������
//	}
//	//����<<�����,�������
//	friend ostream& operator<<(ostream& os, const Person& p) {
//		os << "Name: " << p.name << ", Age: " << p.age;
//		return os;
//	}
//};
//
////��ӡset�����е�Person����
//void printSet(const set<Person>& s) {
//	for (const auto& person : s) { //ʹ�÷�Χforѭ������set,auto�ؼ����Զ��Ƶ�����
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