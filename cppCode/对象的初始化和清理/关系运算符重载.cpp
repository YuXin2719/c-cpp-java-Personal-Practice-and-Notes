//#include <iostream>
//using namespace std;
//
////���ع�ϵ�����
//
//class Person
//{
//public:
//	Person(string name,int age):m_Name(name),m_Age(age){}
//
//	//���� == ��
//
//	bool operator==(const Person& p)
//	{
//		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
//			return true;
//		else
//			return false;
//
//	}
//
//	bool operator!=(const Person& p)
//	{
//		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
//			return false;
//		else
//			return true;
//	}
//
//	string m_Name;
//	int m_Age;
//};
//
//void test01()
//{
//	Person p1("Tom", 18);
//
//	Person p2("Jerry", 18);
//
//	if (p1 == p2)
//	{
//		cout << "p1 �� p2 ����ȵģ�" << endl;
//	}
//	else
//	{
//		cout << "p1 �� p2 ����ȣ�" << endl;
//	}
//
//	if (p1 != p2)
//	{
//		cout << "p1 �� p2 ����ȣ�" << endl;
//	}
//	else
//	{
//		cout << "p1 �� p2 ����ȵģ�" << endl;
//	}
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}