#include <iostream>
#include <cmath>
#include "point.h"
#include "Circle.h"

using namespace std;

////点和圆关系案例
////点类
//class Point
//{
//public:
//	//设置x
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取x
//	int getX()
//	{
//		return m_X;
//	}
//
//	//设置y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//
//	//获取y
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};
//
////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R; //半径
//
//	Point m_Center; //圆心
//};

//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间的距离 平方
	double twoPointsDistance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);

	//计算半径的平方
	double rDistance = pow(c.getR(), 2);

	//判断关系
	if (twoPointsDistance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (twoPointsDistance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{

	//创建圆
	Circle c1; //圆
	Point c1Center; //圆心

	//设置圆心参数
	c1Center.setX(10);
	c1Center.setY(0);

	//设置圆半径和圆心
	c1.setR(10);
	c1.setCenter(c1Center);

	//创建点
	Point p1;

	p1.setX(10);
	p1.setY(9);

	Point p2;

	p2.setX(10);
	p2.setY(10);

	Point p3;

	p3.setX(10);
	p3.setY(11);

	//判断关系
	isInCircle(c1, p1);
	isInCircle(c1, p2);
	isInCircle(c1, p3);

	system("pause");
	return 0;
}