//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//	//switch语句
//	//给一个电影打分
//	//10~9	经典
//	//8~7	非常好
//	//6~5	一般
//	//5以下	烂
//
//	//1.提示用户评分
//	cout << "请给电影打分：" << endl;
//
//	//2.用户开始打分
//	int score = 0;
//	cin >> score;
//	cout << "您打出的分数为：" << score << endl;
//
//	//3.根据用户输入的分数提示用户最后的结果
//	switch (score)
//	{
//	case 10:
//		cout << "您认为是经典电影" << endl;
//		break;
//	case 9:
//		cout << "您认为是经典电影" << endl;
//		break;
//	case 8:
//		cout << "您认为是非常好电影" << endl;
//		break;
//	case 7:
//		cout << "您认为是非常好电影" << endl;
//		break;
//	case 6:
//		cout << "您认为是一般电影" << endl;
//		break;
//	case 5:
//		cout << "您认为是一般电影" << endl;
//		break;
//	default:
//		cout << "您认为是垃圾电影" << endl;
//		break;
//	}
//
//	//if 和 switch 区别？
//	//switch 缺点，判断只能是整型或者字符型，不可以是一个区间
//	//switch 优点，结构清晰，执行效率高
//
//	system("pause");
//	return 0;
//}