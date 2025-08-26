#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>

//设计演讲管理类
class SpeechManager
{
public:
	SpeechManager(); //构造函数
	~SpeechManager(); //析构函数
	void showMenu(); //显示菜单
	void exitSpeech(); //退出比赛程序
	void initSpeech(); //初始化比赛
	void startSpeech(); //开始比赛
	void speechDraw(); //抽签
	void speechContest(); //比赛

	//比赛选手容器 12人
	vector<int> v1;
	//第一轮晋级容器 6人
	vector<int> v2;
	//胜利前三名容器 3人
	vector<int> vVictory;
	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;
	//存放比赛轮数
	int m_Index;
};