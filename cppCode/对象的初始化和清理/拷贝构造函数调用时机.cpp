//#include <iostream>
//using namespace std;
//
////�������캯������ʱ��
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "PersonĬ�Ϲ��캯������" << endl;
//	}
//
//	Person(int age)
//	{
//		m_Age = age;
//		cout << "Person�вκ�������" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "Person�������캯��" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person������������" << endl;
//	}
//
//	int m_Age;
//};
//
////1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//void test01()
//{
//	Person p1(20);
//	Person p2(p1);
//
//	cout << "p2������Ϊ��" << p2.m_Age << endl;
//}
//
////2.ֵ���ݵķ�ʽ������������ֵ	ֵ���ǿ������µ�����
//void doWork(Person p)
//{
//
//}
//
//void test02()
//{
//	Person p;
//	doWork(p);
//}
//
////3.ֵ��ʽ���ؾֲ�����
////���ֱ��д return p1; �ͻ᷵��p1����Ҳ���� p �� p1 ��ַһ��
//Person doWork2()
//{
//	Person p1;
//	cout << (int)&p1 << endl; //�鿴 p1 ��ַ
//	return Person(p1);
//}
//
//void test03()
//{
//	Person p = doWork2();
//	cout << (int)&p << endl; //�鿴 p ��ַ
//}
//
//int main()
//{
//
//	//test01();
//	
//	//test02();
//
//	test03();
//
//	system("pause");
//	return 0;
//}