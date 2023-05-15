#include <iostream>
#include <string>
#include <graphics.h>

using namespace std;

int main()
{

	initgraph(640, 480, SHOWCONSOLE);
	cleardevice();

	//输出图片
	IMAGE img;//定义一个对象
	//加载图片
	//相对路径 ./表示当前文件夹下（源文件所在的目录），../是当前文件夹的上一级目录
	//绝对路径 
	loadimage(&img, "../666.jpg",640,480);
	putimage(0, 0, &img);//(0,0)图片锚点是左上角

	system("pause");
	return 0;
}