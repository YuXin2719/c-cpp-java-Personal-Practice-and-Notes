//#include <iostream>
//using namespace std;
//
////继承中的对象模型
//
//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son :public Base
//{
//public:
//	int m_D;
//};
//
////利用开发人员命令提示工具(Developer Command Prompt for VS 2022)查看对象模型	(开始菜单可以找到)
////跳转盘符	f:
////跳转文件路径	cd	具体路径下	E:\c.---c.---java-exercise\cppCode\对象的初始化和清理
////查看命名
//// cl(这是爱楼) /d1(这是一)  reportSingleClassLayou类名 文件名	||->	cl /d1 reportSingleClassLayoutSon 继承中的对象模型.cpp
//
//void test01()
//{
//	//16
//	//父类中所有的非静态成员属性都会被子类继承下去
//	//父类中私有成员属性 是被编译器给隐藏了，因此访问不到，但是被继承下去了
//	cout << "size of Son = " << sizeof(Son) << endl;
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