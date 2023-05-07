//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//指针和数组
//	//利用指针访问数组
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << "第一个元素是：" << arr[0] << endl;
//
//	int* p = arr; //arr存放了数组的首地址
//
//	cout << "利用指针来访问第一个元素：" << *p << endl;
//
//	p++; //往后推四个字节，整型指针直接++就行
//
//	cout << "利用指针来访问第二个元素：" << *p << endl;
//
//
//	cout << "利用指针遍历数组：" << endl;
//	int* p2 = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "数组中第" << i + 1 << "个元素为：" << *p2 << endl;
//		p2++;
//	}
//
//	system("pause");
//	return 0;
//}