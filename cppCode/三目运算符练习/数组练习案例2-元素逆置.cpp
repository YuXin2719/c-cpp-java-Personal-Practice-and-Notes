//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	/*
//	请声明一个5个元素的数组，并且将元素逆置
//	（如原数组为 1,2,3,4,5; 逆置输出后为 5,4,3,2,1; )
//	*/
//
//	//定义数组
//	int arr[] = { 1,2,3,4,5 };
//
//	//计算数组长度
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	cout << "数组逆置前：" << endl;
//	for (int i = 0; i < length; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//	cout << "数组逆置后：" << endl;
//	for (int i = 0; i < length; i++) //例子中，长度5，循环5次
//	{
//		cout << arr[length - (i + 1)] << endl; //最后的元素就是 arr[length-1]
//	}
//
//	system("pause");
//	return 0;
//}