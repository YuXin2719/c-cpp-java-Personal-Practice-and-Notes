//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//ð������
//	//��Ŀ��������{4,2,8,0,5,7,1,3,9}������������
//	int arr[] = { 4,2,8,0,5,7,1,3,9 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	int b = 0;
//	
//	for (int j = 0; j < length - 1; j++) //3.�ܹ���Ҫ���� length-1 ��
//	{
//		for (int i = 0; i < length - (j + 1); i++) //2.�ܹ���length��Ԫ�أ��Ǿ͵��� length-1 ��
//		{
//			if (arr[i] > arr[i + 1]) //1.���ǰһ��Ԫ�رȺ�һ��Ԫ�ش󣬾͵���һ��������λ�ã������һ�����ĵ����ұ�
//			{
//				a = arr[i];
//				b = arr[i + 1];
//				arr[i + 1] = a;
//				arr[i] = b;
//			}
//		}
//	}
//
//	//�����������
//	cout << "��������Ϊ��" << endl;
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << " " ;
//	}
//
//	system("pause");
//	return 0;
//}