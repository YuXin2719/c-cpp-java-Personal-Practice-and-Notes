//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//1.����ָ��
//	int a = 10;
//	int b = 10;
//
//	const int* p = &a;
//	//ָ��ָ���ֵ���ܸģ�ָ����Ը�
//	//*p = 20; ����
//	p = &b; //��ȷ
//
//	//2.ָ�볣��
//	int* const p1 = &a;
//	*p1 = 20; //��ȷ
//	//p2 = &b; ����
//
//	//3.const���γ�����ָ��
//	const int* const p2 = &a;
//	//*p2 = 20; ����
//	//p2 = &b; ����
//
//	system("pause");
//	return 0;
//}