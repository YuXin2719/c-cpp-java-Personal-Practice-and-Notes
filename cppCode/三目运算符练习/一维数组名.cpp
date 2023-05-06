//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//数组名的用途
//
//	//1.可以通过数组名统计整个数组占用内存大小
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	cout << "整个数组占用的内存空间为：" << sizeof(arr) << endl;
//	cout << "整个数组占用的内存空间为：" << sizeof(arr) << endl;
//	cout << "数组中元素个数是多少：" << sizeof(arr)/sizeof(arr[0]) << endl;
//
//	//2.可以通过数组名查看数组首地址
//	cout << "数组的首地址为：" << (int)arr << endl;
//	cout << "数组中第一个元素的地址：" << (int) & arr[0] << endl;
//	cout << "数组中第二个元素的地址：" << (int) & arr[1] << endl;
//
//	//数组名是常量，不可以进行赋值操作，它就等于他的首地址（初始是16进制的）
//
//	system("pause");
//	return 0;
//}