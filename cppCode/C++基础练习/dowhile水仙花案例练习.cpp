//#include <iostream>
//#include <string>
//
//using namespace std;
//
///*
//案例描述：水仙花是指一个三位数，它的每个位上的数字的三次幂之和等于它本身
//
//例如：1^3 + 5^3 + 3^3 = 153
//
//请用do...while语句，求出所有三位数中的水仙花数
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
//			cout << num << "是水仙花数" << endl;
//		}
//		num++;
//	} while (num < 1000);
//
//	system("pause");
//	return 0;
//}
//
////或者取余
////ge = num % 10;
////shi = num / 10 % 10;
////bai = num / 100;