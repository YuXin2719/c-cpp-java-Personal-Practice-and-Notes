//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
///*
//ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ���������£�
//
//���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
//
//ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
//
//���մ�ӡ����ʦ�����Լ���ʦ������ѧ������
//*/
//
////������ʦ�ṹ��
//struct student
//{
//	string name;//ѧ������
//	int score;//ѧ������
//};
//
////����ѧ���ṹ��
//struct teacher
//{
//	string name;//��ʦ����
//	student student[5];
//};
//
////������ֵ����
//void assign(teacher teacher[], int len)
//{
//	string nameSeed = "ABCDE";
//	//����ʦ��ֵ
//	for (int i = 0; i < len; i++)
//	{
//		teacher[i].name = "teacher_";
//		teacher[i].name += nameSeed[i];
//
//		//��ѧ����ֵ
//		for (int j = 0; j < 5; j++)
//		{
//			teacher[i].student[j].name = "student_";
//			teacher[i].student[j].name += nameSeed[j];
//
//			int random = rand() % 101; //�����
//
//			teacher[i].student[j].score = random;
//		}
//	}
//}
//
//
////��ӡ������Ϣ
//void printInfo(teacher teacher[], int len)
//{
//	for (int i = 0; i < 3; i++)
//	{
//
//		cout << "��ʦ������" << teacher[i].name << endl;
//		cout << "ѧ����Ϣ��" << endl;
//
//		for (int j = 0; j < 5; j++)
//		{
//			cout << "ѧ��������" << teacher[i].student[j].name << endl;
//			cout << "ѧ���ɼ���" << teacher[i].student[j].score << endl;
//		}
//	}
//}
//
//int main()
//{
//	//���������
//	srand((unsigned int)time(NULL));
//	//srand��C�����е���������Ӻ���������rand()����һͬʹ�ã����������������
//	//�޷���������Unsigned Integer����һ���������ͣ����ڴ洢���������㡣�����з��������������ƣ�����һ����Ҫ�����𣬼���������洢������
//	//time(NULL)�������ص�ǰʱ���UTCʱ���������Ϊ��λ��
//	//�ǵð���ͷ�ļ� #include <ctime>
//
//	//��ѧ������ʦ��ֵ
//	teacher teacher[3];
//	int len = sizeof(teacher) / sizeof(teacher[0]);
//	assign(teacher,len);
//	
//	//��ӡ������ʦ��ѧ������Ϣ
//	printInfo(teacher, len);
//
//	system("pause");
//	return 0;
//}