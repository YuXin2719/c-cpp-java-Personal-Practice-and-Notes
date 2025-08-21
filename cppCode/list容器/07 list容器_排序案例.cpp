#include<iostream>
using namespace std;
#include<list>

//list容器排序案例,对自定义数据类型排序
//按照年龄从小到大排序,年龄相同按照身高从大到小排序
class Person {
public:
	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

void showList(const list<Person>& l) {
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名:" << it->m_Name << " 年龄:" << it->m_Age << " 身高:" << it->m_Height << endl;
	}
	cout << endl;
}

bool myCompare(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}

//排序规则,年龄从小到大
void test01() {
	list<Person> l;
	Person p1("刘备", 22, 175);
	Person p2("关羽", 22, 180);
	Person p3("张飞", 22, 180);
	Person p4("赵云", 21, 190);
	Person p5("曹操", 24, 170);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	cout << "排序前" << endl;
	showList(l);

	//排序
	cout << "排序后" << endl;
	l.sort(myCompare); //自定义排序规则
	showList(l);
}

int main() {

	test01();

	system("pause");
	return 0;
}