#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//���ü����㷨_set_difference
void test01() {
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	//v1:0~9
	//v2:5~14
	//���0~4
	//��㷨Ҫ��������������
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	//��㷨
	//set_difference(��ʼλ��1������λ��1����ʼλ��2������λ��2���洢λ��);
	//����ֶ����ٿռ�
	v3.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	cout << "v1��v2�ĲΪ��";
	for (vector<int>::iterator it = v3.begin(); it != itEnd; it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "v2��v1�ĲΪ��";
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for (vector<int>::iterator it = v3.begin(); it != itEnd; it++) {
		cout << *it << " ";
	}
	cout << endl;
}


int main() {
	test01();
	system("pause");
	return 0;
}