//#include <iostream>
//using namespace std;
//
////�����������������
//
////��ӡ�����
//class myPrint
//{
//public:
//
//	//���غ������������
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//};
//
//void myPrint02(string test)
//{
//	cout << test << endl;
//}
//
//void test01()
//{
//	myPrint myprint;
//
//	myprint("hello world"); //����ʹ�������ǳ������ں������ã���˳�֮Ϊ�º���
//
//	myPrint02("hello world");
//}
//
////�º����ǳ���û�й̶�д��
//
////�ӷ���
//
//class myAdd
//{
//public:
//
//	int operator()(int a,int b)
//	{
//		return a + b;
//	}
//};
//
//void test02()
//{
//	myAdd myadd;
//
//	int ret = myadd(100, 100);
//	cout << "ret = " << ret << endl;
//
//	//������������
//	cout << myAdd()(100, 100) << endl; //myAdd() ������һ������������������һ�������ͷ�
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