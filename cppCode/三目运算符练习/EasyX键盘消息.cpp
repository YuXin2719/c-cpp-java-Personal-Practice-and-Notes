//#include <iostream>
//#include <string>
//#include <easyx.h>
//#include <conio.h>//使用getch()
//
//using namespace std;
//
//int main()
//{
//	int x = 0, y = 0;
//	initgraph(640, 480, EX_SHOWCONSOLE);
//	while(1)//不断的获取键盘消息
//	{
//		cleardevice();
//		setfillcolor(BROWN);
//		fillcircle(x, y, 20);
//		char key = _getch();
//		printf("%d,%c\n", key, key);
//		switch (key)
//		{
//		case 72:
//		case 'w':
//		case 'W':
//			y-=5;
//			break;
//		case 80:
//		case 's':
//		case 'S':
//			y+=5;
//			break;
//		case 75:
//		case 'a':
//		case 'A':
//			x-=5;
//			break;
//		case 77:
//		case 'd':
//		case 'D':
//			x+=5;
//			break;
//		default:
//			break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}