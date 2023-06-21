//#include <iostream>
//#include <string>
//#include <graphics.h>
//
//using namespace std;
//
//int main()
//{
//	//创建一个窗口，确定窗口大小，show console 显示控制台
//	initgraph(640,480,SHOWCONSOLE);
//
//	//设置背景以下两步必不可少
//	//设置背景颜色
//	setbkcolor(YELLOW);
//	cleardevice();//清屏，清除黑色背景
//
//	//画粑粑，圆
//	setlinestyle(PS_SOLID, 5);//设置线条样式
//	setfillcolor(GREEN);//设置填充颜色
//	setlinecolor(BLUE);//设置线条颜色
//	circle(50, 50, 50);
//	fillcircle(50, 150, 50);
//	solidcircle(50, 250, 50);
//
//	//设置字体颜色
//	settextcolor(BLACK);
//
//	//设置字体样式，大小，字体..
//	settextstyle(20, 0, "楷体");
//
//	//设置背景模式 transparent-透明
//	setbkmode(TRANSPARENT);
//
//	//设置字体颜色
//	settextcolor(RGB(85, 177, 85));
//
//	//绘制文字
//	outtextxy(50, 50, 'a');//绘制字符
//
//	outtextxy(60, 50, "大家好");//绘制字符串
//
//	//把文字居中
//	fillrectangle(200, 50, 500, 100);//填充一个矩形，参数为 左上角坐标+右下角坐标
//	settextcolor(RGB(30, 30, 30));
//	char arr[] = "居中显示测试";
//
//	int width = textwidth(arr);//像素所占宽度
//	int height = textheight(arr);//像素所占高度
//
//	outtextxy(300 / 2 - width / 2 + 200, 50 / 2 - height / 2 + 50, "居中显示测试");//绘制字符串
//
//
//	//如果参数错误，找不到对应的函数
//	//是由于字符集导致的，那么解决方案有三种
//	// 
//	//1.在字符串前面加大写的L           常用
//	//outtextxy(50, 50, L"大家好");
//	// 
//	//2.用TEXT()把字符串包起来
//	//outtextxy(50, 50, TEXT("大家好"));
//	//
//	//3.用__TEXT()把字符串包起来
//	//
//	//实际上 TEXT() -> __TEXT() -> L"文本"
//	//
//	//4.不用添加任何代码，进 项目 -> 属性 -> 配置属性 -> 常规 -> 字符集 -> 改为多字节字符集    推荐使用这个！
//	int maye = 0;
//	cin >> maye;
//	cout << maye << endl;
//
//	//关闭窗口
//	closegraph();
//
//	system("pause");
//	return 0;
//}