//#include <iostream>
//using namespace std;
//
////空指针调用成员函数
//
//class Person
//{
//public:
//
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//
//	void showClassAge()
//	{
//		//报错原因是因为传入的指针是NULL空指针
//
//		if (this == NULL)
//		{
//			return;
//		}
//
//		cout << "age = " << m_Age << endl; //属性前面都默认加了this，即 this->m_Age ,由于this在示例中是空指针，所以没属性
//	}
//
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//
//	p->showClassName();
//
//	p->showClassAge();
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