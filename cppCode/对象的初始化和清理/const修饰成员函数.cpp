//#include <iostream>
//using namespace std;
//
////������
//class Person
//{
//public:
//
//	//���� thisָ��ı���	��ָ�볣��	ָ���ָ���ǲ������޸ĵ�
//	//thisָ�뱾���ǣ�Person* const this;
//
//	//���������ʽ��void showPerson() const
//	//��ζ��thisָ���ɣ�const void showPerson() const		��ָ�벻�ܸģ�ָ���ֵҲ���ܸ�
//	//�ڳ�Ա���������const�����ε���thisָ�룬��ָ��ָ���ֵҲ�������޸�
//
//	void showPerson() const
//	{
//		this->m_B = 100;
//		//this->m_A = 100;
//		//this->NULL; //thisָ���ǲ������޸�ָ���ָ���
//	}
//
//	int m_A;
//	mutable int m_B; //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ		mutable - �ɱ��
//
//	void func() 
//	{
//		m_A = 100;
//	}
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
////������
//void test02()
//{
//	const Person p; //�ڶ���ǰ��const����Ϊ������
//	//p.m_A = 100; //������Ҳ�������޸�����
//	p.m_B = 100; //m_B������ֵ���ڳ�������Ҳ�����޸�
//
//	//������ֻ�ܵ��ó�����
//	p.showPerson();
//	//p.func(); //������ �����Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
//}
//
//int main()
//{
//
//	
//
//	system("pause");
//	return 0;
//}