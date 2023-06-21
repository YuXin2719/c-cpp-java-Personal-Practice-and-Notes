//#include <iostream>
//#include <string>
//#include <easyx.h>
//
//using namespace std;
//
//void button(int x, int y, int w, int h,const char arr[])
//{
//	setbkmode(TRANSPARENT);
//	setfillcolor(BROWN);
//	settextstyle(30, 0, "黑体");
//	fillroundrect(x, y, x + w, x + h, 10, 10);//10是圆角有多圆
//
//	int width = textwidth(arr);
//	int height = textheight(arr);
//
//	outtextxy(w / 2 - width / 2 + x, h / 2 - height / 2 + y, arr);
//}
//
//int main()
//{
//
//	initgraph(640, 480, EX_SHOWCONSOLE);
//	button(50,50,150,150,"botton");
//
//	ExMessage msg;
//	while (1)
//	{
//		if (peekmessage(&msg, EX_MOUSE))
//		{
//			switch (msg.message)
//			{
//			case WM_LBUTTONDOWN:
//				if (msg.x >= 50 && msg.x <= 50 + 150 && msg.y >= 50 && msg.y <= 50 + 150)
//				{
//					cout << "我是按钮，我被点击了" << endl;
//				}
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}