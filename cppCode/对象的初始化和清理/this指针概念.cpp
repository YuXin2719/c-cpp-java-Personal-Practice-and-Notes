//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		//this指针指向的是 被调用的成员函数 所属的对象
//		this->age = age;
//	}
//
//	Person& personAddAge(Person& p)
//	{
//		this->age += p.age;	//this 是指向 p2 的一个指针（示例中）
//
//		//this 指向的是 p2 的指针，而 *this 指向的就是 p2 这个对象本体
//		return *this;
//	}
//
//	int age;
//};
//
////this 指针概念
////1.解决名称冲突
//void test01()
//{
//	Person p1(18);
//	cout << "p1的年龄：" << p1.age << endl;
//}
//
////2.返回对象本身用 *this
//void test02()
//{
//	Person p1(10);
//
//	Person p2(10);
//
//	//链式编程思想
//	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
//
//	cout << "p2的年龄为：" << p2.age << endl;
//}
//
//int main()
//{
//
//	test01();
//
//	test02();
//
//	system("pause");
//	return 0;
//}