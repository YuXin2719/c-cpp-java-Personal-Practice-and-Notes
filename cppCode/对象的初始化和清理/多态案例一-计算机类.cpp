//#include <iostream>
//using namespace std;
//
////�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
//
////��ͨд��
//class Calculator
//{
//public:
//	int m_Num1; //������1
//	int m_Num2; //������2
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
//	//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
//	//����ʵ�Ŀ����У��ᳫ ����ԭ��
//	//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
//};
//
//
////���ö�̬ʵ�ּ�����
//
////��̬�ô���
////1.��֯�ṹ����
////2.�ɶ���ǿ
////3.����ǰ�ںͺ��ڵ���չ��ά���Ը�
//
//
////ʵ�ּ������ĳ�����
//class abstractCalculator //abstract(����)Calculator(������)
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
////�ӷ���������
//class addCalculator :public abstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////������������
//class subCalculator :public abstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////�˷���������
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
//	//��������������
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
//	//��̬ʹ������
//	//����ָ���������ָ���������
//
//
//	//�ӷ�����
//	abstractCalculator* abc = new addCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//
//	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	//�����ǵ�����
//	delete abc;
//
//
//	//��������
//	abc = new subCalculator; //�ղ����ٵ��Ƕ��������ݣ�ָ������ͻ�û�б�
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//
//	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//
//
//	//�˷�����
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