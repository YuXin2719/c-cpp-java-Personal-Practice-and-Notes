//#include <iostream>
//#include <string>
//
//using namespace std;
//
////ʵ���������ֻ���
//void swap1(int num1, int num2)
//{
//	int temp = num1;
//	num1 = num2;
//	num2 = temp;
//	
//	cout << "swap1 a = " << num1 << endl;
//	cout << "swap1 b = " << num2 << endl;
//}
//
//void swap2(int* p1, int* p2)
//{
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//int main()
//{
//
//	//ָ��ͺ���
//
//	int a = 10;
//	int b = 20;
//
//	//1.ֵ����
//	//swap1(a, b);
//
//	//2.��ַ����
//	//����ǵ�ַ���ݣ���������ʵ��
//	//Ҳ����˵����ȥ��ַ��Ȼ����ֱַ�Ӳ�����ַָ����ڴ�
//	swap2(&a, &b);
//
//	cout << "a = " << a << endl; //20
//	cout << "b = " << b << endl; //10
//
//	system("pause");
//	return 0;
//}