#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//�ϰ���
class Boss : public Worker {
public:
	Boss(int id, string name, int did); // ���캯��
	virtual void ShowInfo(); // ��ʾ������Ϣ
	virtual string GetDeptName(); // ��ȡ��λ����
};