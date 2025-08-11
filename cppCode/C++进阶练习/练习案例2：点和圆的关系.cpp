#include <iostream>
#include <cmath>
#include "point.h"
#include "Circle.h"

using namespace std;

////���Բ��ϵ����
////����
//class Point
//{
//public:
//	//����x
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//��ȡx
//	int getX()
//	{
//		return m_X;
//	}
//
//	//����y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//
//	//��ȡy
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
////Բ��
//class Circle
//{
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_R;
//	}
//
//	//����Բ��
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R; //�뾶
//
//	Point m_Center; //Բ��
//};

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	//��������֮��ľ��� ƽ��
	double twoPointsDistance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);

	//����뾶��ƽ��
	double rDistance = pow(c.getR(), 2);

	//�жϹ�ϵ
	if (twoPointsDistance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (twoPointsDistance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{

	//����Բ
	Circle c1; //Բ
	Point c1Center; //Բ��

	//����Բ�Ĳ���
	c1Center.setX(10);
	c1Center.setY(0);

	//����Բ�뾶��Բ��
	c1.setR(10);
	c1.setCenter(c1Center);

	//������
	Point p1;

	p1.setX(10);
	p1.setY(9);

	Point p2;

	p2.setX(10);
	p2.setY(10);

	Point p3;

	p3.setX(10);
	p3.setY(11);

	//�жϹ�ϵ
	isInCircle(c1, p1);
	isInCircle(c1, p2);
	isInCircle(c1, p3);

	system("pause");
	return 0;
}