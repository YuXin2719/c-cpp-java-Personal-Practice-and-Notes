//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//��ά����������;
//
//	//1.���Բ鿴ռ�õ��ڴ�ռ��С
//	int arr[2][3] =
//	{
//		{1,2,3},
//		{4,5,6}
//	};
//	cout << "��ά����ռ�õ��ڴ棺" << sizeof(arr) << endl;
//	cout << "��ά�����һ��ռ�õ��ڴ棺" << sizeof(arr[0]) << endl;
//	cout << "��ά�����һ��Ԫ����ռ�õ��ڴ棺" << sizeof(arr[0][0]) << endl;
//
//	cout << "��ά�����������" << sizeof(arr) / sizeof(arr[0]) << endl;
//	cout << "��ά�����������" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
//
//	//2.���Բ鿴��λ������׵�ַ
//	cout << "��ά�����׵�ַ��" << (int)arr << endl;
//	cout << "��ά�����һ�е��׵�ַ��" << (int)arr[0] << endl;
//	cout << "��ά����ڶ��е��׵�ַ��" << (int)arr[1] << endl;
//
//	cout << "��ά�����һ��Ԫ�ص��׵�ַ��" << (int)&arr[0][0] << endl; // &������
//
//
//	system("pause");
//	return 0;
//}