//#include <iostream>
//using namespace std;
//
////纯虚函数和抽象类
//class Base
//{
//public:
//	//纯虚函数
//	//只要有一个纯虚函数，这个类就是抽象类
//	//抽象类的特点：
//	//1.不能实例化对象
//	//2.抽象类的子类 必须重写父类的纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//
//class Son :public Base {
//public:
//	virtual void func() {
//		cout << "Son func" << endl;
//	}
//};
//
//void test01() {
//	//Base b; //抽象类无法实例化对象
//	//new Base; //抽象类无法实例化对象
//
//	//Son s; //子类必须重写父类的纯虚函数，否则无法实例化对象
//
//	Base* b = new Son; //可以通过父类指针指向子类对象
//	b->func(); //调用子类的重写函数
//
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}