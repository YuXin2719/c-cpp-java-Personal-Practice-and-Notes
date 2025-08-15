#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt" // �����ļ�������

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();

	//��ʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	//����ְ����Ϣ
	void Add_Emp();
	//�����ļ�
	void save();
	//ͳ������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//����ְ������ж�ְ���Ƿ���ڣ�������ڷ���ְ���������е�λ�ã������ڷ���-1
	int IsExist(int id);
	//�޸�ְ����Ϣ
	void Mod_Emp();
	//����ְ����Ϣ
	void Find_Emp(); // ����ְ����Ϣ
	//����ְ����Ϣ
	void Sort_Emp(); // ����ְ���������ְ����Ϣ
	//����ļ�
	void Clean_File(); // ����ļ�

	//��¼�ļ��е���������
	int m_EmpNum; // ��ǰְ������
	//Ա�������ָ��
	Worker** m_EmpArray; // ��̬����ָ�룬���ڴ洢ְ������
	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty; // ��־�ļ��Ƿ�Ϊ��
};