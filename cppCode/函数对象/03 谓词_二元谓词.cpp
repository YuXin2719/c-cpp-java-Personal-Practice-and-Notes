#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//��Ԫν��
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void showVec(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "����" << endl;
	sort(v.begin(), v.end());
	showVec(v);

	//ʹ�ú�������,�ı��������,ʵ�ֽ���
	cout << "����" << endl;
	sort(v.begin(), v.end(), MyCompare());
	showVec(v);
}

int main() {
	test01();
	system("pause");
	return 0;
}