//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	/*
//	������һ��5��Ԫ�ص����飬���ҽ�Ԫ������
//	����ԭ����Ϊ 1,2,3,4,5; ���������Ϊ 5,4,3,2,1; )
//	*/
//
//	//��������
//	int arr[] = { 1,2,3,4,5 };
//
//	//�������鳤��
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	cout << "��������ǰ��" << endl;
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//	cout << "�������ú�" << endl;
//	for (int i = 0; i < length; i++) //�����У�����5��ѭ��5��
//	{
//		cout << arr[length - (i + 1)] << endl; //����Ԫ�ؾ��� arr[length-1]
//	}
//
//	system("pause");
//	return 0;
//}