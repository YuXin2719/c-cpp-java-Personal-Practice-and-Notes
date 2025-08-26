//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////常用的拷贝和替换算法_copy
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	vector<int>v2;
//	v2.resize(v.size());
//	//拷贝
//	copy(v.begin(), v.end(), v2.begin());
//	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
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