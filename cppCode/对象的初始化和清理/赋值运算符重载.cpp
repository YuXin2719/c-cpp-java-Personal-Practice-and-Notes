//#include <iostream>
//using namespace std;
//
////��ֵ���������
//
//class Person
//{
//public:
//
//	Person(int age) //�����ݴ����ڶ���
//	{
//		m_Age = new int(age);
//	}
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age; //ɾ���ڴ�����Ϣ
//			m_Age = NULL; //ָ���ָ��
//		}
//	}
//
//	//���ظ�ֵ�����
//	Person& operator=(Person &p) //������Person����Ϊ���ص������ÿ������캯�������ֵ�������÷��صĲ�������������
//	{
//
//		if (&p == this) //�жϳ����Ը�ֵ���������p1 = p1
//		{
//			return p;
//		}
//
//		//�������ṩ��ǳ����
//		//m_Age = p.m_Age;
//
//		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//
//		m_Age = new int(*p.m_Age);
//	
//		//���ض�����
//		return *this;
//	}
//
//	int* m_Age;
//};
//
//void test01()
//{
//	Person p1(18);
//
//	Person p2(20);
//
//	Person p3(30);
//
//	p3 = p2 = p1; //��ֵ����
//
//	p1 = p1;
//
//	cout << "p1������Ϊ��" << *p1.m_Age << endl;
//
//	cout << "p2������Ϊ��" << *p2.m_Age << endl;
//
//	cout << "p3������Ϊ��" << *p3.m_Age << endl;
//}
//
//int main()
//{
//
//	test01();
//
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//
//	//c = b = a;
//
//	//cout << "a = " << a << endl;
//	//cout << "b = " << b << endl;
//	//cout << "c = " << c << endl;
//
//	system("pause");
//	return 0;
//}