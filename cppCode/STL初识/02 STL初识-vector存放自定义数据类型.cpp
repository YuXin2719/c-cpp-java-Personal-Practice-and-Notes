//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//#include<algorithm>
//
////vector����Զ�����������
//class Person {
//public:
//	string name;
//	int age;
//	Person(string n, int a) : name(n), age(a) {}
//};
//
//void test01() {
//	//����һ��vector���Person����
//	vector<Person> v;
//	//���Ԫ��
//	v.push_back(Person("Alice", 30));
//	v.push_back(Person("Bob", 25));
//	//�������
//	for_each(v.begin(), v.end(), [](const Person& p) {
//		cout << "Name: " << p.name << ", Age: " << p.age << endl;
//		});
//}
//
////����Զ����������͵�ָ��
//void test02() {
//	//����һ��vector���Person�����ָ��
//	vector<Person*> v;
//	//���Ԫ��
//	v.push_back(new Person("Alice", 30));
//	v.push_back(new Person("Bob", 25));
//	//�������
//	for_each(v.begin(), v.end(), [](const Person* p) {
//		cout << "Name: " << p->name << ", Age: " << p->age << endl;
//		});
//	//�ͷ��ڴ�
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