//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void bublleSort(int* arr,int length) //int* arrҲ����д��int arr[]
//{
//	for (int i = 0; i < length-1; i++)
//	{
//		for (int j = 0; j < length-1; j++)
//		{
//			if (*(arr + j) > *(arr + 1 + j)) //Ҳ����д�� arr[j] > arr[j + 1]
//			{
//				int temp = *(arr + 1 + j);
//				*(arr + 1 + j) = *(arr + j);
//				*(arr + j) = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//
//	/*
//	������������װһ������������ð������ʵ�ֶ������������������
//	int arr[10] = {4,3,6,9,1,2,10,8,7,5};
//	*/
//
//	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
//
//	bublleSort(arr, 10);
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//	system("pause");
//	return 0;
//}