#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

//�����㷨�����㷨 fill
void test01() {
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}