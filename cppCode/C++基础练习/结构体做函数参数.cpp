//#include <iostream>
//#include <string>
//
//using namespace std;
//
////ѧ���ṹ�嶨��
//struct student
//{
//	//����
//	string name;
//	//����
//	int age;
//	//����
//	int score;
//};
//
////��ӡѧ����Ϣ�ĺ���
////1.ֵ����
//void printStudent1(student s)
//{
//	s.score = 100;
//	cout << "���Ӻ����� ������" << s.name << endl;
//	cout << "���Ӻ����� ���䣺" << s.age << endl;
//	cout << "���Ӻ����� ������" << s.score << endl; //100
//}
//
////2.��ַ����
//void printStudent2(student* p)
//{
//	p->score = 100;
//	cout << "���Ӻ���2�� ������" << p->name << endl;
//	cout << "���Ӻ���2�� ���䣺" << p->age << endl;
//	cout << "���Ӻ���2�� ������" << p->score << endl; //100
//}
//
//int main()
//{
//
//	//�ṹ������������
//	//��ѧ�����뵽һ��������,��ӡѧ�����ϵ�������Ϣ
//
//	//�����ṹ�����
//	student s;
//	s.name = "����";
//	s.age = 20;
//	s.score = 85;
//
//	printStudent1(s);
//	cout << "main�����д�ӡ ������" << s.name << endl;
//	cout << "main�����д�ӡ ���䣺" << s.age << endl;
//	cout << "main�����д�ӡ ������" << s.score << endl; //85
//
//	printStudent2(&s);
//	cout << "main�����д�ӡ ������" << s.name << endl;
//	cout << "main�����д�ӡ ���䣺" << s.age << endl;
//	cout << "main�����д�ӡ ������" << s.score << endl;  //100
//
//	system("pause");
//	return 0;
//}