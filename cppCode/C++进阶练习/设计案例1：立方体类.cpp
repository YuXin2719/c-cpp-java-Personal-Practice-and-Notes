//#include <iostream>
//
//using namespace std;
//
////�����������
//class Cube
//{
//public:
//	//��Ϊ
//
//	//���û�ȡ�����
//	//���ó�
//	void setL(int l)
//	{
//		m_L = l;
//	}
//
//	//��ȡ��
//	int getL()
//	{
//		return m_L;
//	}
//
//	//���ÿ�
//	void setW(int w)
//	{
//		m_W = w;
//	}
//
//	//��ȡ��
//	int getW()
//	{
//		return m_W;
//	}
//
//	//���ø�
//	void setH(int h)
//	{
//		m_H = h;
//	}
//
//	//��ȡ��
//	int getH()
//	{
//		return m_H;
//	}
//
//
//	//��ȡ���������
//	int calculateS()
//	{
//		return (2 * m_L * m_W) + (2 * m_L * m_H) + (2 * m_W * m_H);
//	}
//
//	//��ȡ���������
//	int calculateV()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//���ó�Ա�����ж������������Ƿ����
//	bool isSameByClass(Cube& c)
//	{
//		if (c.getL() == m_L && c.getW() == m_W && c.getH() == m_H)
//			return true;
//		else
//			return false;
//	}
//
//private:
//	//����
//	int m_L, m_W, m_H; //m����member,��Ա
//};
//
////����ȫ�ֺ����ж� �����������Ƿ����
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
//	//�������������
//	Cube c1;
//	c1.setL(10);
//	c1.setW(10);
//	c1.setH(10);
//
//	cout << "c1�����Ϊ��" << c1.calculateS() << endl;
//	cout << "c1�����Ϊ��" << c1.calculateV() << endl;
//
//	//�����ڶ���������
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(11);
//
//	//����ȫ�ֺ����ж�
//	bool ret = isSame(c1, c2);
//	cout << "ȫ�ֺ����жϣ�" << endl;
//	if (ret == true)
//		cout << "�������������" << endl;
//	else
//		cout << "���������岻���" << endl;
//
//	//���ó�Ա�����ж�
//	//��Ϊ���õ��� c1 �ĺ����������ڲ������� c1 �����ݣ�����ֻ��Ҫ������һ������������ݼ���
//	ret = c1.isSameByClass(c2);
//	cout << "��Ա�����жϣ�" << endl;
//	if (ret == true)
//		cout << "�������������" << endl;
//	else
//		cout << "���������岻���" << endl;
//
//	system("pause");
//	return 0;
//}