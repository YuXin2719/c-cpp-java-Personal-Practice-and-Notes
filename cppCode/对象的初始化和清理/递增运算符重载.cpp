//#include <iostream>
//using namespace std;
//
////���ص��������
//
////�Զ�������
//class myInteger
//{
//	friend ostream& operator<<(ostream& cout, const myInteger& i);
//
//public:
//	myInteger()
//	{
//		m_Num = 0;
//	}
//
//	//����ǰ��++�����	��������Ϊ��һֱ��һ�����ݽ��в���
//	myInteger& operator++()
//	{
//		//�Ƚ���++����
//		m_Num++;
//
//		//�ٽ�����������
//		return *this;
//	}
//
//	//���غ���++�����
//	//int �����ռλ������������������ǰ�úͺ��á� ���ұ�����ֻ��int������������ȷ��Ϊ������д���õ���
//	myInteger operator++(int)
//	{
//		//�� ��¼��ʱ�Ľ��
//		myInteger temp = *this; //���ﷵ�ص���ֵ��������ص������ã��Ǿ��Ƿ��صľֲ����������ã��������������ͷ��ˣ��ڲ������ǷǷ�����
//
//		//�� ��������
//		m_Num++;
//
//		//��󷵻ؼ�¼�Ľ������
//		return temp;
//	}
//
//private:
//	int m_Num;
//};
//
////����<<�����
//ostream& operator<<(ostream& cout, const myInteger& i)
//{
//	cout << i.m_Num;
//	return cout;
//}
//
//void test01()
//{
//	myInteger myint;
//
//	cout << ++(++myint) << endl;
//	cout << myint << endl;
//}
//
//void test02()
//{
//	myInteger myint;
//
//	cout << myint++ << endl;
//	cout << myint << endl;
//}
////ע�����ñ���ģ�������������ڶ�������ʹconst �ټ����ã�����ֱ�Ӳ�ʹ������
//
//int main()
//{
//
//	//test01();
//
//	test02();
//
//	//һֱ��ͬһ�������Ͻ��в���
//	//int a = 0;
//	//cout << ++(++a) << endl;
//	//cout << a << endl;
//
//	system("pause");
//	return 0;
//}