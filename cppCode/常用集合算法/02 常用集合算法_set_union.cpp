//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用集合算法_set_union
//void test01() {
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	v1.push_back(1);
//	v1.push_back(3);
//	v1.push_back(5);
//	v1.push_back(7);
//	v1.push_back(9);
//	v2.push_back(0);
//	v2.push_back(2);
//	v2.push_back(4);
//	v2.push_back(6);
//	v2.push_back(8);
//	//并集
//	//前提：两个集合必须是有序序列
//	//目标容器必须开辟空间，且空间要足够大
//	v3.resize(v1.size() + v2.size());
//	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for (vector<int>::iterator it = v3.begin(); it != itEnd; it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}