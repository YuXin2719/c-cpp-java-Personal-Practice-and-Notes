#pragma once
#include"identity.h"
#include"computerRoom.h"
#include<vector>
#include"orderFile.h"
#include<vector>

//ѧ����
class Student : public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, int pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};
