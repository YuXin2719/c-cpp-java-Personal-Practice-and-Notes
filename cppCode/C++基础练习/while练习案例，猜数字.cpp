//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//1.系统生成随机数
//	int num = rand() % 100 + 1;	//生成 0 + 1 ~ 99 + 1 的随机数
//
//	cout << "随机数 = " << num << endl;  //可屏蔽，这里做示范
//
//	//2.玩家进行猜测
//	int val = 0;
//	
//	//3.判断玩家的猜测
//	while (1)
//	{
//		cin >> val;
//
//		if (val < num)
//		{
//			cout << "你输入的数字小了，请重新输入" << endl;
//		}
//		else if (val > num)
//		{
//			cout << "你输入的数字大了，请重新输入" << endl;
//		}
//		else
//		{
//			cout << "对溜！" << endl;
//			break;
//		}
//	}
//	//猜错	提示猜的结果	过大或者过小
//	//猜对	恭喜
//
//	system("pause");
//	return 0;
//}