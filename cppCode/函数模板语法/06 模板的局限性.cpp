//#include<iostream>
//using namespace std;
//#include<string>
//
////ģ��ľ�����
////ģ�岻�����ܵģ���Щ�ض����������ͣ���Ҫ�þ��廯�ķ�ʽ������ʵ��
//
//class Person {
//public:
//	Person(string name, int age) : name(name), age(age) {}
//	//����������
//	string name;
//	int age;
//};
//
////�Ա��������ݵĺ���
//template<typename T>
//bool compare(T& a, T& b) {
//	if (a == b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
////���þ��廯�ķ�ʽ����Person������һ������ʵ��
//template<>
//bool compare<Person>(Person& p1, Person& p2) { //<Person>��ʡ�ԣ���Ϊ����������ͨ�����������Ƶ��������ģ�庯���ػ�����Person����
//	if (p1.name == p2.name && p1.age == p2.age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void test02() {
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	//compare(p1, p2);//error,û�п��õ�==���������
//	if (compare(p1, p2)) {
//		cout << "p1��p2���" << endl;
//	}
//	else {
//		cout << "p1��p2�����" << endl;
//	}
//}
//
//int main() {
//	test02();
//	system("pause");
//	return 0;
//}