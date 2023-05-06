//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//冒泡排序
//	//题目：将数组{4,2,8,0,5,7,1,3,9}进行升序排序
//	int arr[] = { 4,2,8,0,5,7,1,3,9 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	int b = 0;
//	
//	for (int j = 0; j < length - 1; j++) //3.总共需要排序 length-1 次
//	{
//		for (int i = 0; i < length - (j + 1); i++) //2.总共有length个元素，那就调换 length-1 次
//		{
//			if (arr[i] > arr[i + 1]) //1.如果前一个元素比后一个元素大，就调换一下它俩的位置，最后挑一个最大的到最右边
//			{
//				a = arr[i];
//				b = arr[i + 1];
//				arr[i + 1] = a;
//				arr[i] = b;
//			}
//		}
//	}
//
//	//输出最终数组
//	cout << "最终数组为：" << endl;
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << " " ;
//	}
//
//	system("pause");
//	return 0;
//}