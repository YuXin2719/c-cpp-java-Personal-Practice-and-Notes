//#include <iostream>
//
//using namespace std;
//
////��Ա��������Ϊ˽��
////1.�����Լ����ƶ�д��Ȩ��
////2.����д���Լ�����ݵ���Ч��
//
////�������
//class Person
//{
//public:
//	//��������
//	void setName(string name)
//	{
//		m_Name = name;
//	}
//	//��ȡ����
//	string getName()
//	{
//		return m_Name;
//	}
//	
//	//��ȡ����
//	int getAge()
//	{ 
//		return m_Age;
//	}
//	//��������	���������Ч��
//	void setAge(int age)
//	{
//		if (age < 0 || age>150)
//		{
//			m_Age = 0;
//			cout << "�������䲻�Ծ������Ҹ����0�ˣ���������" << endl;
//		}
//		else
//			m_Age = age;
//	}
//
//	//��������
//	void setLover(string lover)
//	{
//		m_Lover = lover;
//	}
//
//private:
//	//���ƶ�дȨ��
//
//	//����	�ɶ���д
//	string m_Name;
//
//	//����	�ɶ���д
//	int m_Age;
//
//	//����	ֻд
//	string m_Lover;
//};
//
//int main()
//{
//
//	Person p;
//	p.setName("����");
//
//	cout << "����Ϊ��" << p.getName() << endl;
//
//	//��������
//	//p.setAge(155);
//	p.setAge(18);
//	cout << "����Ϊ��" << p.getAge() << endl;
//
//	//��������Ϊ�־�Ůʿ
//	p.setLover("�־�");
//
//	system("pause");
//	return 0;
//}