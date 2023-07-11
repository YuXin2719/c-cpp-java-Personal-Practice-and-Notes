//#include <iostream>
//using namespace std;
//
////拷贝构造函数调用时机
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person默认构造函数调用" << endl;
//	}
//
//	Person(int age)
//	{
//		m_Age = age;
//		cout << "Person有参函数调用" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "Person拷贝构造函数" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person析构函数调用" << endl;
//	}
//
//	int m_Age;
//};
//
////1.使用一个已经创建完毕的对象来初始化一个新对象
//void test01()
//{
//	Person p1(20);
//	Person p2(p1);
//
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//}
//
////2.值传递的方式给函数参数传值	值就是拷贝的新的数据
//void doWork(Person p)
//{
//
//}
//
//void test02()
//{
//	Person p;
//	doWork(p);
//}
//
////3.值方式返回局部对象
////如果直接写 return p1; 就会返回p1本身，也就是 p 和 p1 地址一样
//Person doWork2()
//{
//	Person p1;
//	cout << (int)&p1 << endl; //查看 p1 地址
//	return Person(p1);
//}
//
//void test03()
//{
//	Person p = doWork2();
//	cout << (int)&p << endl; //查看 p 地址
//}
//
//int main()
//{
//
//	//test01();
//	
//	//test02();
//
//	test03();
//
//	system("pause");
//	return 0;
//}