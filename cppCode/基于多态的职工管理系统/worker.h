#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ�����ࣺ��ͨԱ���������ϰ�
//������ְ������һ���ࣨworker���У����ö�̬����ְͬ������
//ְ�����ԣ�ְ����š�ְ��������ְ�����ڲ��ű��
//ְ����Ϊ����λְ����Ϣ��������ȡ��λ����

//�����ࣺWorker
class Worker {
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0; // ���麯����ǿ��������ʵ��
	//��ȡ��λ����
	virtual string GetDeptName() = 0; // ���麯����ǿ��������ʵ��

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ��ű��
};