//#include<iostream>
//using namespace std;
//
////��ģ��ͺ���ģ�������
//template <class NameType, class AgeType = int>
//class Person {
//public:
//	NameType name;
//	AgeType age;
//	Person(NameType n, AgeType a) : name(n), age(a) {}
//	void show() {
//		cout << "Name: " << name << ", Age: " << age << endl;
//	}
//};
//
////1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//void test01() {
//	//Person p("�����", 1000); //����ģ��޷����Զ������Ƶ�
//	Person<string, int> p("�����", 1000); //��ȷ�ģ�ֻ������ʾָ�����͵ķ�ʽ
//	p.show();
//}
////2.��ģ����ģ������б��п�����Ĭ�ϲ���
//void test02() {
//	Person<string> p1("��˽�", 500); //ֻ����ģ�����ʹ��Ĭ�ϲ���
//	p1.show();
//}
//
//int main() {
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}