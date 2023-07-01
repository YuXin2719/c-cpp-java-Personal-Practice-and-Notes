//#include <iostream>
//
//using namespace std;
//
////成员属性设置为私有
////1.可以自己控制读写的权限
////2.对于写可以检测数据的有效性
//
////设计人类
//class Person
//{
//public:
//	//设置姓名
//	void setName(string name)
//	{
//		m_Name = name;
//	}
//	//获取姓名
//	string getName()
//	{
//		return m_Name;
//	}
//	
//	//获取年龄
//	int getAge()
//	{ 
//		return m_Age;
//	}
//	//设置年龄	检测数据有效性
//	void setAge(int age)
//	{
//		if (age < 0 || age>150)
//		{
//			m_Age = 0;
//			cout << "你这年龄不对劲啊，我给你改0了，重新设置" << endl;
//		}
//		else
//			m_Age = age;
//	}
//
//	//设置情人
//	void setLover(string lover)
//	{
//		m_Lover = lover;
//	}
//
//private:
//	//控制读写权限
//
//	//姓名	可读可写
//	string m_Name;
//
//	//年龄	可读可写
//	int m_Age;
//
//	//情人	只写
//	string m_Lover;
//};
//
//int main()
//{
//
//	Person p;
//	p.setName("张三");
//
//	cout << "姓名为：" << p.getName() << endl;
//
//	//设置年龄
//	//p.setAge(155);
//	p.setAge(18);
//	cout << "年龄为：" << p.getAge() << endl;
//
//	//设置情人为仓井女士
//	p.setLover("仓井");
//
//	system("pause");
//	return 0;
//}