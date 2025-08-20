#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>

//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί�е���ͷ֣�ȡƽ����

//ѡ����
class Person {
public:
	string name;
	int scores;
	Person(string name, int scores) {
		this->name = name;
		this->scores = scores;
	}
};

void createPersons(vector<Person>& persons) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += nameSeed[i];
		Person p(name, 0);
		persons.push_back(p);
	}
}

void setScores(vector<Person>& persons) {
	//ģ��10����ί���
	for (int i = 0; i < persons.size(); i++) {
		deque<int> scores;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60; //60-100��
			scores.push_back(score);
		}
		//���ÿ��ѡ�ֵķ���
		cout << persons[i].name << "�ķ���Ϊ��";
		for (int k = 0; k < scores.size(); k++) {
			cout << scores[k] << " ";
		}
		cout << endl;
		//ȥ����߷�
		sort(scores.begin(), scores.end());
		scores.pop_back();
		//ȥ����ͷ�
		scores.pop_front();
		//����ƽ����
		int sum = 0;
		for (int k = 0; k < scores.size(); k++) {
			sum += scores[k];
		}
		persons[i].scores = sum / scores.size();
	}
}

//��ʾÿ��ѡ�ֵ�ƽ����
void showScores(const vector<Person>& persons) {
	cout << "ѡ��ƽ���֣�" << endl;
	for (vector<Person>::const_iterator it = persons.begin(); it != persons.end(); it++) {
		cout << it->name << "��ƽ����Ϊ��" << it->scores << endl;
	}
}

int main() {

	//���������
	srand((unsigned int)time(NULL));

	//1.����5��ѡ��
	vector<Person> persons;
	createPersons(persons);
	//����
	//for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++) {
	//	cout << "name:" << it->name << " scores:" << it->scores << endl;
	//}

	//2.��ÿ��ѡ�ִ��
	setScores(persons);

	//3.��ʾÿ��ѡ�ֵ�ƽ����
	showScores(persons);

	system("pause");
	return 0;
}