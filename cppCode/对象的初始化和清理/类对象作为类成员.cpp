//#include <iostream>
//using namespace std;
//
////�������Ϊ�����
//
//class Phone
//{
//public:
//	Phone(string pName) :m_PName(pName) {
//		cout << "Phone ���캯������" << endl;
//	}
//
//	//�ֻ�Ʒ��
//	string m_PName;
//
//	~Phone()
//	{
//		cout << "Phone ������������" << endl;
//	}
//};
//
//class Person
//{
//public:
//	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
//		cout <<"Person ���캯������" << endl;
//	}
//
//	//����
//	string m_Name;
//	//�ֻ�
//	Phone m_Phone;
//
//	~Person()
//	{
//		cout << "Person ������������" << endl;
//	}
//};
//
////��������Ķ�����Ϊ����ĳ�Ա������ʱ���ȹ���������ٹ�������
////								������˳���빹���෴
//
//void test01()
//{
//	Person p("����", "iPhone");
//
//	cout << p.m_Name << " ���� " << p.m_Phone.m_PName << endl;
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