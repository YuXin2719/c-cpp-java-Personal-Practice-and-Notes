#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//常用遍历算法_transform
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//利用STL提供的变换算法_transform
	vector<int> v2;
	//back_inserter(v2) 适配器 将v2容器变为迭代器
	//std::back_inserter会创建一个特殊的输出迭代器，当通过这个迭代器赋值时，会自动调用容器的 push_back()方法
	//在算法操作中（如 transform, copy等），如果目标容器是空的或大小不足，比如在这里我们就没有给v2开辟空间,直接使用普通迭代器会导致未定义行为。back_inserter解决了这个问题。
	transform(v.begin(), v.end(), back_inserter(v2), [](int val) {
		return val * 2; //搬运期间还可以做逻辑运算
		});
	for (auto& it : v2) {
		cout << it << " ";
	}
	cout << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}