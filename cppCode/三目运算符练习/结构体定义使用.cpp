//#include <iostream>
//#include <string>
//
//using namespace std;
//
////1.����ѧ���������ͣ����������������䣬������
////�Զ����������ͣ�һЩ���ͼ�����ɵ�һ������
////�﷨ struct �������� {��Ա�б�}
//struct Student //�����Ե�
//{
//	//��Ա�б�
//
//	//����
//	string name;
//
//	//����
//	int age;
//
//	//����
//	double score;
//}s3; //˳�㴴���ṹ�����
//
////2.ͨ��ѧ���������ʹ��������ѧ��
//
////2.1 struct Student s1;
////2.2 struct Student s2 = {...};
////2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����
//
//int main()
//{
//
////2.1 struct Student s1
//	//struct�ؼ��ֿ���ʡ��
//	/*struct*/ Student s1; //s1���ǳ�Ա
//	//�� s1 ���Ը�ֵ��ͨ�� . ���ʽṹ������е�����
//	s1.name = "����";
//	s1.age = 18;
//	s1.score = 100;
//
//	cout << "������" << s1.name << endl;
//	cout << "���䣺" << s1.age << endl;
//	cout << "�ɼ���" << s1.score << endl;
//
////2.2 struct Student s2 = {...}
////struct����ʡ��
//	struct Student s2 = { "����",20,80 };
//	cout << "������" << s2.name << endl;
//	cout << "���䣺" << s2.age << endl;
//	cout << "�ɼ���" << s2.score << endl;
//
////2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ���������������ʾ�������棩
////һ�㲻��
//	s3.name = "����";
//	s3.age = 19;
//	s3.score = 90;
//
//	system("pause");
//	return 0;
//}