//#include <iostream>
//#include <string>
//
//using namespace std;
//
///*
//����������ˮ�ɻ���ָһ����λ��������ÿ��λ�ϵ����ֵ�������֮�͵���������
//
//���磺1^3 + 5^3 + 3^3 = 153
//
//����do...while��䣬���������λ���е�ˮ�ɻ���
//*/
//
//int main()
//{
//
//	double num = 100;
//	int bai = 0, shi = 0, ge = 0;
//
//
//	do {
//		bai = (int)(num * 0.01);
//		shi = (int)((num-bai*100) * 0.1);
//		ge = (int)(num - bai * 100 - shi * 10);
//		if ((bai * bai * bai + shi * shi * shi + ge * ge * ge) == num)
//		{
//			cout << num << "��ˮ�ɻ���" << endl;
//		}
//		num++;
//	} while (num < 1000);
//
//	system("pause");
//	return 0;
//}
//
////����ȡ��
////ge = num % 10;
////shi = num / 10 % 10;
////bai = num / 100;