#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"globalFile.h"

//��ݳ�����
class Identity {
public:
	//�����˵�
	virtual void operMenu() = 0; //���麯��

	string m_Name; //����
	int m_Pwd; //����
};