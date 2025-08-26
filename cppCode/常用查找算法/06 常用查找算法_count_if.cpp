#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//���ò����㷨_count_if
//ͳ��������������
void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	//ͳ�������д���30��Ԫ�ظ���
	int num = count_if(v.begin(), v.end(), [](int val) {
		return val > 30;
		});
	cout << "num = " << num << endl;
	//����ͨ���º���ͳ��
	class Greater30 {
	public:
		bool operator()(int val) {
			return val > 30;
		}
	};
	num = count_if(v.begin(), v.end(), Greater30());
	cout << "num = " << num << endl;
}

//ͳ���Զ�����������
void test02() {
	//����ѧ����
	class Student {
	public:
		Student(string name, int age) {
			this->name = name;
			this->age = age;
		}
		string name;
		int age;
	};
	vector<Student> v;
	Student s1("����", 20);
	Student s2("����", 30);
	Student s3("����", 40);
	Student s4("����", 50);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	//ͳ���������30��ѧ������
	int num = count_if(v.begin(), v.end(), [](Student s) {
		return s.age > 30;
		});
	cout << "num = " << num << endl;
	//����ͨ���º���ͳ��
	class Greater30 {
	public:
		bool operator()(Student s) {
			return s.age > 30;
		}
	};
	num = count_if(v.begin(), v.end(), Greater30());
	cout << "num = " << num << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}