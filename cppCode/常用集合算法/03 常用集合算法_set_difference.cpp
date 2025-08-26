#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//常用集合算法_set_difference
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
	//差集：0~4
	//差集算法要求两个集合有序
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	//差集算法
	//set_difference(起始位置1，结束位置1，起始位置2，结束位置2，存储位置);
	//如果手动开辟空间
	v3.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	cout << "v1和v2的差集为：";
	for (vector<int>::iterator it = v3.begin(); it != itEnd; it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "v2和v1的差集为：";
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