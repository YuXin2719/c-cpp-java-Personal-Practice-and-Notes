//#include <iostream>
//using namespace std;
//
////动物类
//class Animal
//{
//public:
//	int m_Age;
//};
//
////利用虚继承 解决菱形继承的问题
////继承之前 加上关键字 virtual 变为虚继承
////通过使用虚继承，可以确保在多重继承中，通过不同路径继承同一个基类的派生类只会存在一个共享的基类子对象
////换句话说，虚继承能够消除由于多重继承导致的 数据重复（只保存一份数据） 以及 二义性问题
////虚继承 只是继承了指针 指针通过偏移量去找到唯一的一份数据
////Animal类称为 虚基类
//
////羊类
//class Sheep :virtual public Animal{};
//
////驼类
//class Tuo :virtual public Animal{};
//
////羊驼类
//class sheepTuo :public Sheep, public Tuo{};
//
//void test01()
//{
//	sheepTuo st;
//
//	st.Sheep::m_Age = 18;
//	st.Tuo::m_Age = 28;
//	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
//	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
//	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age<< endl;
//
//	cout << "st.m_Age = "<< st.m_Age << endl;
//
//	//这份数据我们知道 只有一份就可以，菱形继承导致数据有两份，资源浪费
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