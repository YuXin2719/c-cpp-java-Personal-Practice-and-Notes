#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工分类：普通员工、经理、老板
//将三种职工抽象到一个类（worker）中，利用多态管理不同职工种类
//职工属性：职工编号、职工姓名、职工所在部门编号
//职工行为：岗位职责信息描述，获取岗位名称

//抽象类：Worker
class Worker {
public:
	//显示个人信息
	virtual void ShowInfo() = 0; // 纯虚函数，强制派生类实现
	//获取岗位名称
	virtual string GetDeptName() = 0; // 纯虚函数，强制派生类实现

	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //职工所在部门编号
};