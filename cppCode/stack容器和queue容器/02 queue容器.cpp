#include<iostream>
using namespace std;
#include<queue>
#include<string>

//���� queue
class Person {
public:
	Person(string n, int a) : name(n), age(a) {}
	string name;
	int age;
};

void test01() {
	//��������
	queue<Person> q;
	//�������
	q.push(Person("����", 20));
	q.push(Person("����", 22));
	q.push(Person("����", 25));
	//�ж�ֻҪ���в�Ϊ��,�鿴��ͷ,�鿴��β,����
	while (!q.empty()) {
		//�鿴��ͷ
		cout << "��ͷ����: " << q.front().name << " ����: " << q.front().age << endl;
		//�鿴��β
		cout << "��β����: " << q.back().name << " ����: " << q.back().age << endl;
		//����
		q.pop();
		cout << "���Ӻ���д�СΪ: " << q.size() << endl;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}