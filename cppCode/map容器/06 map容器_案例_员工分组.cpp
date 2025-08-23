#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>

//map案例_员工分组
/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
- 员工信息有：姓名，工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和公司
- 通过multimap进行信息的插入 key（部门编号）value（员工）
- 分部门显示员工信息
*/

//1.定义员工类
class Worker {
public:
	string m_Name;
	int m_Salary; //工资
	Worker(string name, int salary) {
		this->m_Name = name;
		this->m_Salary = salary;
	}
};

void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "员工";
		name += nameSeed[i];
		int salary = rand() % 10000 + 10000; //10000-19999
		Worker w(name, salary);
		v.push_back(w);
	}
}

void insertWorkerToMap(multimap<int, Worker>& m, vector<Worker>& v) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//随机分配部门
		int deptId = rand() % 3; //0 1 2
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByDeptId(multimap<int, Worker>& m, int deptId) {
	//0策划 1美术 2研发
	string deptName;
	if (deptId == 0) {
		deptName = "策划";
	}
	else if (deptId == 1) {
		deptName = "美术";
	}
	else if (deptId == 2) {
		deptName = "研发";
	}
	else
	{
		cout << "部门不存在" << endl;
		return;
	}
	cout << deptName << "部门员工信息：" << endl;
	multimap<int, Worker>::iterator it = m.find(deptId);
	int count = m.count(deptId); //统计某个部门的人数
	for (int i = 0; i < count; i++) {
		cout << "姓名：" << it->second.m_Name << " 工资：" << it->second.m_Salary << endl;
		it++;
	}
	cout << endl;
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	//2.创建10名员工,放到vector中
	vector<Worker>v;
	createWorker(v);

	//3.创建multimap容器，员工信息插入到容器中
	multimap<int, Worker>m; //key部门编号  value员工
	insertWorkerToMap(m, v);

	//4.分部门显示员工信息
	for (int i = 0; i < 3; i++) {
		showWorkerByDeptId(m, i);
	}

	system("pause");
	return 0;
}