//#include <iostream>
//
//using namespace std;
//
//int* func()
//{
//	//利用new关键字	可以将数据开辟到堆区
//	//指针本身也是局部变量，他也是放在栈上，指针保存的数据放在堆区
//	int* p = new int(10); //new 返回的是这个数据开辟的地址位置
//	return p;
//}
//
//int main()
//{
//
//	//在堆区开辟数据
//	int* p = func();
//
//	cout << *p << endl;
//
//
//	system("pause");
//	return 0;
//}