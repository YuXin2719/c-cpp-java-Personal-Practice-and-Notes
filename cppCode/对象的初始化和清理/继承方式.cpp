//#include <iostream>
//using namespace std;
//
////�̳з�ʽ
//
////�����̳�
//class Base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son1 :public Base1
//{
//public:
//	void func()
//	{
//		m_A = 10; //�����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
//		m_B = 10; //�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
//		//m_C = 10; //�����е�˽��Ȩ�޳�Ա �������з��ʲ���
//	}
//};
//
////�����̳�
//class Base2
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son2 :protected Base2
//{
//public:
//	void func()
//	{
//		m_A = 100; //�����й�����Ա���������б�Ϊ����Ȩ��
//		m_B = 100; //�����б�����Ա���������б�Ϊ����Ȩ��
//		//m_C = 100; //�����˽�г�Ա���ʲ���
//	}
//};
//
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 100;
//	//s1.m_B = 100; //�̳е�����Ҳ�Ǳ���Ȩ�����ݣ��������ⲻ�ܷ���
//}
//
//void test02()
//{
//	Son2 s1;
//	//s1.m_A = 1000; //��Son2�� m_A��Ϊ����Ȩ�ޣ����������ʲ���
//	//s1.m_B = 1000; //��Son2�� m_B����Ȩ�� �����Է���
//}
//
//void test03()
//{
//	Son3 s1;
//	//s1.m_A = 1000; //��Son3�б�Ϊ ˽�г�Ա ������ʲ���
//	//s1.m_B = 1000; //��Son3�б�Ϊ ˽�г�Ա ������ʲ���
//}
//
////˽�м̳�
//class Base3
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son3 :private Base3
//{
//	void func()
//	{
//		m_A = 100; //�����й�����Ա �������б�Ϊ ˽�г�Ա
//		m_B = 100; //�����б�����Ա �������б�Ϊ ˽�г�Ա
//		//m_C = 100; //������˽�г�Ա��������ʲ���
//	}
//};
//
//class grandSon3 :public Son3
//{
//public:
//	void func()
//	{
//		//m_A = 1000; //����Son3�� m_A��Ϊ˽�У���ʹ�Ƕ��ӣ�Ҳ���ʲ���
//		//m_B = 1000; //����Son3�� m_A��Ϊ˽�У���ʹ�Ƕ��ӣ�Ҳ���ʲ���
//	}
//};
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}