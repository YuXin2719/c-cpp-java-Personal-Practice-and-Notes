//#include <iostream>
//#include <string>
//
//using namespace std;
//
////const��ʹ�ó���
//
//struct student
//{
//	string name;//����
//	int age;//����
//	int score;//����
//};
//
////�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������
//void printStudent(const student* p) //ָ��ֻռ4���ֽ�
//{
//	//p->name = "����"; ���� ����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ���������
//	cout << "ѧ������Ϊ��" << p->name << endl; // (*p).name Ҳ����
//	cout << "ѧ������Ϊ��" << p->age << endl;
//	cout << "ѧ������Ϊ��" << p->score << endl;
//}
//
//int main()
//{
//
//	//�����ṹ�����
//	student s = { "����",15,70 };
//
//	//ͨ��������ӡ�ṹ���������Ϣ
//	printStudent(&s);
//
//	system("pause");
//	return 0;
//}