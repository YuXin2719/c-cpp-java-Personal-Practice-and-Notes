#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//Ա����
class Employee : public Worker {
public:
	Employee(int id, string name, int did); // ���캯��
	virtual void ShowInfo(); // ��ʾ������Ϣ
	virtual string GetDeptName(); // ��ȡ��λ����
};