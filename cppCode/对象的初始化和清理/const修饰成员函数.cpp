//#include <iostream>
//using namespace std;
//
////常函数
//class Person
//{
//public:
//
//	//本身 this指针的本质	是指针常量	指针的指向是不可以修改的
//	//this指针本质是：Person* const this;
//
//	//常函数表达式：void showPerson() const
//	//意味着this指针变成：const void showPerson() const		即指针不能改，指向的值也不能改
//	//在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
//
//	void showPerson() const
//	{
//		this->m_B = 100;
//		//this->m_A = 100;
//		//this->NULL; //this指针是不可以修改指针的指向的
//	}
//
//	int m_A;
//	mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值		mutable - 可变的
//
//	void func() 
//	{
//		m_A = 100;
//	}
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
////常对象
//void test02()
//{
//	const Person p; //在对象前加const，变为常对象
//	//p.m_A = 100; //常对象也不允许修改属性
//	p.m_B = 100; //m_B是特殊值，在常对象下也可以修改
//
//	//常对象只能调用常函数
//	p.showPerson();
//	//p.func(); //常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
//}
//
//int main()
//{
//
//	
//
//	system("pause");
//	return 0;
//}