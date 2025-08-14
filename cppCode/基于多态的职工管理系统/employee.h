#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//员工类
class Employee : public Worker {
public:
	Employee(int id, string name, int did); // 构造函数
	virtual void ShowInfo(); // 显示个人信息
	virtual string GetDeptName(); // 获取岗位名称
};