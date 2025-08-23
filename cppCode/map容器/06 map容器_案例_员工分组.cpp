#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>

//map����_Ա������
/*
- ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾����Ҫָ��Ա�����ĸ����Ź���
- Ա����Ϣ�У�������������ɣ����ŷ�Ϊ���߻����������з�
- �����10��Ա�����䲿�ź͹�˾
- ͨ��multimap������Ϣ�Ĳ��� key�����ű�ţ�value��Ա����
- �ֲ�����ʾԱ����Ϣ
*/

//1.����Ա����
class Worker {
public:
	string m_Name;
	int m_Salary; //����
	Worker(string name, int salary) {
		this->m_Name = name;
		this->m_Salary = salary;
	}
};

void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "Ա��";
		name += nameSeed[i];
		int salary = rand() % 10000 + 10000; //10000-19999
		Worker w(name, salary);
		v.push_back(w);
	}
}

void insertWorkerToMap(multimap<int, Worker>& m, vector<Worker>& v) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//������䲿��
		int deptId = rand() % 3; //0 1 2
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByDeptId(multimap<int, Worker>& m, int deptId) {
	//0�߻� 1���� 2�з�
	string deptName;
	if (deptId == 0) {
		deptName = "�߻�";
	}
	else if (deptId == 1) {
		deptName = "����";
	}
	else if (deptId == 2) {
		deptName = "�з�";
	}
	else
	{
		cout << "���Ų�����" << endl;
		return;
	}
	cout << deptName << "����Ա����Ϣ��" << endl;
	multimap<int, Worker>::iterator it = m.find(deptId);
	int count = m.count(deptId); //ͳ��ĳ�����ŵ�����
	for (int i = 0; i < count; i++) {
		cout << "������" << it->second.m_Name << " ���ʣ�" << it->second.m_Salary << endl;
		it++;
	}
	cout << endl;
}

int main() {
	//���������
	srand((unsigned int)time(NULL));

	//2.����10��Ա��,�ŵ�vector��
	vector<Worker>v;
	createWorker(v);

	//3.����multimap������Ա����Ϣ���뵽������
	multimap<int, Worker>m; //key���ű��  valueԱ��
	insertWorkerToMap(m, v);

	//4.�ֲ�����ʾԱ����Ϣ
	for (int i = 0; i < 3; i++) {
		showWorkerByDeptId(m, i);
	}

	system("pause");
	return 0;
}