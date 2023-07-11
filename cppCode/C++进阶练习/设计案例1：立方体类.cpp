//#include <iostream>
//
//using namespace std;
//
////立方体类设计
//class Cube
//{
//public:
//	//行为
//
//	//设置获取长宽高
//	//设置长
//	void setL(int l)
//	{
//		m_L = l;
//	}
//
//	//获取长
//	int getL()
//	{
//		return m_L;
//	}
//
//	//设置宽
//	void setW(int w)
//	{
//		m_W = w;
//	}
//
//	//获取宽
//	int getW()
//	{
//		return m_W;
//	}
//
//	//设置高
//	void setH(int h)
//	{
//		m_H = h;
//	}
//
//	//获取高
//	int getH()
//	{
//		return m_H;
//	}
//
//
//	//获取立方体面积
//	int calculateS()
//	{
//		return (2 * m_L * m_W) + (2 * m_L * m_H) + (2 * m_W * m_H);
//	}
//
//	//获取立方体体积
//	int calculateV()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//利用成员函数判断两个立方体是否相等
//	bool isSameByClass(Cube& c)
//	{
//		if (c.getL() == m_L && c.getW() == m_W && c.getH() == m_H)
//			return true;
//		else
//			return false;
//	}
//
//private:
//	//属性
//	int m_L, m_W, m_H; //m代表member,成员
//};
//
////利用全局函数判断 两个立方体是否相等
//bool isSame(Cube& c1, Cube& c2)
//{
//	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	//创建立方体对象
//	Cube c1;
//	c1.setL(10);
//	c1.setW(10);
//	c1.setH(10);
//
//	cout << "c1的面积为：" << c1.calculateS() << endl;
//	cout << "c1的体积为：" << c1.calculateV() << endl;
//
//	//创建第二个立方体
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(11);
//
//	//利用全局函数判断
//	bool ret = isSame(c1, c2);
//	cout << "全局函数判断：" << endl;
//	if (ret == true)
//		cout << "两个立方体相等" << endl;
//	else
//		cout << "两个立方体不相等" << endl;
//
//	//利用成员函数判断
//	//因为调用的是 c1 的函数，所以内部数据是 c1 的数据，所以只需要传入另一个立方体的数据即可
//	ret = c1.isSameByClass(c2);
//	cout << "成员函数判断：" << endl;
//	if (ret == true)
//		cout << "两个立方体相等" << endl;
//	else
//		cout << "两个立方体不相等" << endl;
//
//	system("pause");
//	return 0;
//}