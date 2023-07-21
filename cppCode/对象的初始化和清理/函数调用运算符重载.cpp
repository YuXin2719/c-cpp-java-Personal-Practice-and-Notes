//#include <iostream>
//using namespace std;
//
////函数调用运算符重载
//
////打印输出类
//class myPrint
//{
//public:
//
//	//重载函数调用运算符
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//};
//
//void myPrint02(string test)
//{
//	cout << test << endl;
//}
//
//void test01()
//{
//	myPrint myprint;
//
//	myprint("hello world"); //由于使用起来非常类似于函数调用，因此称之为仿函数
//
//	myPrint02("hello world");
//}
//
////仿函数非常灵活，没有固定写法
//
////加法类
//
//class myAdd
//{
//public:
//
//	int operator()(int a,int b)
//	{
//		return a + b;
//	}
//};
//
//void test02()
//{
//	myAdd myadd;
//
//	int ret = myadd(100, 100);
//	cout << "ret = " << ret << endl;
//
//	//匿名函数对象
//	cout << myAdd()(100, 100) << endl; //myAdd() 创建出一个匿名对象，运行完这一行立即释放
//}
//
//int main()
//{
//
//	//test01();
//
//	test02();
//
//	system("pause");
//	return 0;
//}