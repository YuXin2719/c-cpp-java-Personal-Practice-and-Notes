//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	/*
//	在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};
//	要求：找出并打印最重的小猪的体重
//	*/
//
//	//定义数组
//	int arr[5] = { 300,350,200,400,250 };
//
//	//判断最重的小猪
//	int max = arr[0];
//	for (int i = 1; i < 5; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//		//或者
//		//max = ( max < arr[i] ? arr[i] : max );
//	}
//
//	//输出最重小猪体重
//	cout << "最重的小猪体重为：" << max << endl;
//
//	system("pause");
//	return 0;
//}