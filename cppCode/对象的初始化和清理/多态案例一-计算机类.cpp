//#include <iostream>
//using namespace std;
//
////分别利用普通写法和多态技术实现计算器
//
////普通写法
//class Calculator
//{
//public:
//	int m_Num1; //操作数1
//	int m_Num2; //操作数2
//
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//	}
//	//如果想拓展新的功能，需要修改源码
//	//在真实的开发中，提倡 开闭原则
//	//开闭原则：对拓展进行开放，对修改进行关闭
//};
//
//
////利用多态实现计算器
//
////多态好处：
////1.组织结构清晰
////2.可读性强
////3.对于前期和后期的拓展和维护性高
//
//
////实现计算器的抽象类
//class abstractCalculator //abstract(抽象)Calculator(计算器)
//{
//public:
//	int m_Num1;
//	int m_Num2;
//
//	virtual int getResult()
//	{
//		return 0;
//	}
//};
//
////加法计算器类
//class addCalculator :public abstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////减法计算器类
//class subCalculator :public abstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////乘法计算器类
//class mulCalculator :public abstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//void test01()
//{
//	//创建计算器对象
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
//	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
//}
//
//void test02()
//{
//	//多态使用条件
//	//父类指针或者引用指向子类对象
//
//
//	//加法运算
//	abstractCalculator* abc = new addCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//
//	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	//用完后记得销毁
//	delete abc;
//
//
//	//减法运算
//	abc = new subCalculator; //刚才销毁的是堆区的数据，指针的类型还没有变
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//
//	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//
//
//	//乘法运算
//	abc = new mulCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//
//	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
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