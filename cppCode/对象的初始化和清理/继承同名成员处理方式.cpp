//#include <iostream>
//using namespace std;
//
////�̳�ͬ����Ա����ʽ
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base - func()����" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base - func(int a)����" << endl;
//	}
//	int m_A;
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son - func()����" << endl;
//	}
//	int m_A;
//};
//
////ͬ�����ԵĴ���ʽ
//void test01()
//{
//	Son s;
//	cout << "m_A = " << s.m_A << endl;
//	//���ͨ��������󣬷��ʵ������е�ͬ����Ա����Ҫ��������
//	cout << "s.Base::m_A = " << s.Base::m_A << endl;
//}
//
////ͬ����Ա��������ʽ
//void test02()
//{
//	Son s;
//	s.func(); //ֱ�ӵ��� ���õ��������е�ͬ����Ա
//
//	//��ε��õ�������ͬ����Ա����
//	s.Base::func();
//
//	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������е�ͬ����Ա����
//	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
//	s.Base::func(100);
//}
//
//int main()
//{
//
//	//test01();
//	test02();
//
//	system("pause");
//	return 0;
//}