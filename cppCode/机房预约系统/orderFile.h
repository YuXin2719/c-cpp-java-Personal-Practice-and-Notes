#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>
#include<string>

class OrderFile {
public:
	//构造函数
	OrderFile();
	//更新预约信息
	void updateOrder();
	//预约信息容器
	//key --- 记录的条数 value --- 具体记录的键值对信息
	map<int, map<string, string>> m_OrderData;
	//预约记录条数
	int m_Size;
};