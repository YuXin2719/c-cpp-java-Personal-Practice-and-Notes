#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>
#include<string>

class OrderFile {
public:
	//���캯��
	OrderFile();
	//����ԤԼ��Ϣ
	void updateOrder();
	//ԤԼ��Ϣ����
	//key --- ��¼������ value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_OrderData;
	//ԤԼ��¼����
	int m_Size;
};