//#include <iostream>
//using namespace std;
//
////��ָ����ó�Ա����
//
//class Person
//{
//public:
//
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//
//	void showClassAge()
//	{
//		//����ԭ������Ϊ�����ָ����NULL��ָ��
//
//		if (this == NULL)
//		{
//			return;
//		}
//
//		cout << "age = " << m_Age << endl; //����ǰ�涼Ĭ�ϼ���this���� this->m_Age ,����this��ʾ�����ǿ�ָ�룬����û����
//	}
//
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//
//	p->showClassName();
//
//	p->showClassAge();
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