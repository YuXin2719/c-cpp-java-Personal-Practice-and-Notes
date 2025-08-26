//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////常用排序算法_merge
//void test01() {
//	vector<int>v1;
//	v1.push_back(10);
//	v1.push_back(30);
//	v1.push_back(50);
//	v1.push_back(70);
//	vector<int>v2;
//	v2.push_back(20);
//	v2.push_back(40);
//	v2.push_back(60);
//	v2.push_back(80);
//	vector<int>vTarget;
//	//目标容器必须开辟足够空间
//	vTarget.resize(v1.size() + v2.size());
//	//合并两个有序序列，前提是两个序列都是有序的
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}