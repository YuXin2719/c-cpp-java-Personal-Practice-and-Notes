#pragma once
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager :public Identity {
public:
	Manager();
	Manager(string name, int pwd);
	virtual void operMenu(); //菜单界面
	void addPerson(); //添加账号
	void showPerson(); //查看账号
	void cleanFile(); //清空预约
	void showComputer(); //查看机房信息
	//初始化容器
	void initVector();
	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;
	//机房信息容器
	vector<ComputerRoom> vCom;
	//检测重复 参数：（传入id，传入类型）返回值：（true重复 false不重复）
	bool checkRepeat(int id, int type);
};