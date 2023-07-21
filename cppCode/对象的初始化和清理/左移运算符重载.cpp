//#include <iostream>
//using namespace std;
//
////左移运算符重载
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//
//private:
//
//	//利用成员函数重载 左移运算符	p.operator<<(cout)	简化版本 p << cout
//	//通常不会利用成员函数重载<<运算符，因为无法实现 cout 在左侧
//	//void operator<<(cout)
//	//{
//
//	//}
//
//	int m_A;
//	int m_B;
//};
//
////cout 的数据类型是 ostream - 标准输出流对象。 o - out		stream - 流		并且全局只允许存在一个cout，即要用就引用
//
////只能利用全局函数重载左移运算符
////用引用的方式保证全局只有一个 cout
//ostream& operator<<(ostream& out, Person& p) //本质 operator<<(cout,p) 简化版本 cout << p
//{
//	out << "m_A = " << p.m_A << endl << "m_B = " << p.m_B;
//	return out;
//}
//
//void test01()
//{
//	Person p(10, 10);
//	//p.m_A = 10;
//	//p.m_B = 10;
//
//	cout << p << endl;
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