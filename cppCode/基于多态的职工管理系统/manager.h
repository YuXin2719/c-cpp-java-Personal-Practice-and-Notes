#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//������
class Manager : public Worker {
public:
	Manager(int id, string name, int did); // ���캯��
	virtual void ShowInfo(); // ��ʾ������Ϣ
	virtual string GetDeptName(); // ��ȡ��λ����
};