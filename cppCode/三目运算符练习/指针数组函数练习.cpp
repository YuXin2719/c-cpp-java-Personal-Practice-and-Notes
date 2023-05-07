//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void bublleSort(int* arr,int length) //int* arr也可以写成int arr[]
//{
//	for (int i = 0; i < length-1; i++)
//	{
//		for (int j = 0; j < length-1; j++)
//		{
//			if (*(arr + j) > *(arr + 1 + j)) //也可以写成 arr[j] > arr[j + 1]
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
//	案例描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
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