//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		//thisָ��ָ����� �����õĳ�Ա���� �����Ķ���
//		this->age = age;
//	}
//
//	Person& personAddAge(Person& p)
//	{
//		this->age += p.age;	//this ��ָ�� p2 ��һ��ָ�루ʾ���У�
//
//		//this ָ����� p2 ��ָ�룬�� *this ָ��ľ��� p2 ���������
//		return *this;
//	}
//
//	int age;
//};
//
////this ָ�����
////1.������Ƴ�ͻ
//void test01()
//{
//	Person p1(18);
//	cout << "p1�����䣺" << p1.age << endl;
//}
//
////2.���ض������� *this
//void test02()
//{
//	Person p1(10);
//
//	Person p2(10);
//
//	//��ʽ���˼��
//	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
//
//	cout << "p2������Ϊ��" << p2.age << endl;
//}
//
//int main()
//{
//
//	test01();
//
//	test02();
//
//	system("pause");
//	return 0;
//}