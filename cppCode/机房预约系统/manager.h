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
	virtual void operMenu(); //�˵�����
	void addPerson(); //����˺�
	void showPerson(); //�鿴�˺�
	void cleanFile(); //���ԤԼ
	void showComputer(); //�鿴������Ϣ
	//��ʼ������
	void initVector();
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//������Ϣ����
	vector<ComputerRoom> vCom;
	//����ظ� ������������id���������ͣ�����ֵ����true�ظ� false���ظ���
	bool checkRepeat(int id, int type);
};