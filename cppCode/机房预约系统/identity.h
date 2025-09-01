#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"globalFile.h"

//身份抽象类
class Identity {
public:
	//操作菜单
	virtual void operMenu() = 0; //纯虚函数

	string m_Name; //姓名
	int m_Pwd; //密码
};