#pragma once
#include"identity.h"
#include"orderFile.h"
#include<vector>

class Teacher : public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int id, string name, int pwd);
	//�˵�����
	virtual void operMenu();
	//���ԤԼ
	void validOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//��ʦְ����
	int m_EmpId;
};