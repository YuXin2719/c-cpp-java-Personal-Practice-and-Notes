#include<iostream>
using namespace std;
#include"speechManager.h"

int main() {
	//创建管理类对象
	SpeechManager sm;

	//测试12名选手状态
	//for (auto v : sm.m_Speaker) {
	//	cout << "选手编号：" << v.first << " 姓名：" << v.second.m_Name << " 成绩：" << v.second.m_Score[0] << endl;
	//}

	int select = 0; //用来存储用户的选择
	while (true) {
		sm.showMenu();
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1: //开始演讲比赛
			sm.startSpeech();
			sm.initSpeech();
			break;
		case 2: //查看往届记录
			sm.loadRecord();
			sm.showRecord();
			break;

		case 3: //清空比赛记录
			sm.clearRecord();
			break;

		case 0: //退出程序
			sm.exitSpeech();
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}