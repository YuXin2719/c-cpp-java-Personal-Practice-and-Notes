#pragma once
#include"identity.h"
#include"orderFile.h"
#include<vector>

class Teacher : public Identity {
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int id, string name, int pwd);
	//菜单界面
	virtual void operMenu();
	//审核预约
	void validOrder();
	//查看所有预约
	void showAllOrder();
	//教师职工号
	int m_EmpId;
};