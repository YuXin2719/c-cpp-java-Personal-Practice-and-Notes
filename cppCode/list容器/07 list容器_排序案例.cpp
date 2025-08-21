#include<iostream>
using namespace std;
#include<list>

//list����������,���Զ���������������
//���������С��������,������ͬ������ߴӴ�С����
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
		cout << "����:" << it->m_Name << " ����:" << it->m_Age << " ���:" << it->m_Height << endl;
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

//�������,�����С����
void test01() {
	list<Person> l;
	Person p1("����", 22, 175);
	Person p2("����", 22, 180);
	Person p3("�ŷ�", 22, 180);
	Person p4("����", 21, 190);
	Person p5("�ܲ�", 24, 170);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	cout << "����ǰ" << endl;
	showList(l);

	//����
	cout << "�����" << endl;
	l.sort(myCompare); //�Զ����������
	showList(l);
}

int main() {

	test01();

	system("pause");
	return 0;
}