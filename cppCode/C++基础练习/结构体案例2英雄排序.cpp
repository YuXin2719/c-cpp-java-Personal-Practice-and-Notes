//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct hero
//{
//	string name;//����
//	int age;//����
//	string sex;//�Ա�
//};
//
////ð�������㷨
//void bubbleSort(hero revenger[], int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			if (revenger[j].age > revenger[j + 1].age)
//			{
//				hero temp = revenger[j];
//				revenger[j] = revenger[j + 1];
//				revenger[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//
//	/*
//	���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա𣻴����ṹ�����飬�����д��5��Ӣ�ۡ�
//
//	ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
//	*/
//
//	hero revenger[5] =
//	{
//		{"����",18,"��"},
//		{"����",19,"Ů"},
//		{"����",20,"��"},
//		{"����",40,"��"},
//		{"���",23,"��"}
//	};
//	int len = sizeof(revenger) / sizeof(revenger[0]);
//
//	//ð������
//	bubbleSort(revenger, len);
//
//	//��ӡ�����Ľ��
//
//	cout << "����֮��Ľ��Ϊ��" << endl << endl;
//
//	for (int i = 0; i < len; i++)
//	{
//		cout << "Ӣ�����֣�" << revenger[i].name << endl;
//		cout << "Ӣ�����䣺" << revenger[i].age << endl;
//		cout << "Ӣ���Ա�" << revenger[i].sex << endl;
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}