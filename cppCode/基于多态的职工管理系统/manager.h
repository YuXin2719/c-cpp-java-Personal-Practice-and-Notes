#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//经理类
class Manager : public Worker {
public:
	Manager(int id, string name, int did); // 构造函数
	virtual void ShowInfo(); // 显示个人信息
	virtual string GetDeptName(); // 获取岗位名称
};