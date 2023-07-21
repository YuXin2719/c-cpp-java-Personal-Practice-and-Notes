//#include <iostream>
//using namespace std;
//
////重载递增运算符
//
////自定义整型
//class myInteger
//{
//	friend ostream& operator<<(ostream& cout, const myInteger& i);
//
//public:
//	myInteger()
//	{
//		m_Num = 0;
//	}
//
//	//重载前置++运算符	返回引用为了一直对一个数据进行操作
//	myInteger& operator++()
//	{
//		//先进行++运算
//		m_Num++;
//
//		//再将自身作返回
//		return *this;
//	}
//
//	//重载后置++运算符
//	//int 代表的占位参数，可以用于区分前置和后置。 并且编译器只认int，编译器可以确认为这是在写后置递增
//	myInteger operator++(int)
//	{
//		//先 记录当时的结果
//		myInteger temp = *this; //这里返回的是值，如果返回的是引用，那就是返回的局部变量的引用，这个函数用完就释放了，在操作就是非法操作
//
//		//后 递增操作
//		m_Num++;
//
//		//最后返回记录的结果返回
//		return temp;
//	}
//
//private:
//	int m_Num;
//};
//
////重载<<运算符
//ostream& operator<<(ostream& cout, const myInteger& i)
//{
//	cout << i.m_Num;
//	return cout;
//}
//
//void test01()
//{
//	myInteger myint;
//
//	cout << ++(++myint) << endl;
//	cout << myint << endl;
//}
//
//void test02()
//{
//	myInteger myint;
//
//	cout << myint++ << endl;
//	cout << myint << endl;
//}
////注：后置报错的，把左移运算符第二个参数使const 再加引用，或者直接不使用引用
//
//int main()
//{
//
//	//test01();
//
//	test02();
//
//	//一直在同一个数据上进行操作
//	//int a = 0;
//	//cout << ++(++a) << endl;
//	//cout << a << endl;
//
//	system("pause");
//	return 0;
//}