#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt" // 定义文件名常量

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();

	//显示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//增加职工信息
	void Add_Emp();
	//保存文件
	void save();
	//统计人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//按照职工编号判断职工是否存在，如果存在返回职工在数组中的位置，不存在返回-1
	int IsExist(int id);
	//修改职工信息
	void Mod_Emp();
	//查找职工信息
	void Find_Emp(); // 查找职工信息
	//排序职工信息
	void Sort_Emp(); // 按照职工编号排序职工信息
	//清空文件
	void Clean_File(); // 清空文件

	//记录文件中的人数个数
	int m_EmpNum; // 当前职工人数
	//员工数组的指针
	Worker** m_EmpArray; // 动态数组指针，用于存储职工对象
	//标志文件是否为空
	bool m_FileIsEmpty; // 标志文件是否为空
};