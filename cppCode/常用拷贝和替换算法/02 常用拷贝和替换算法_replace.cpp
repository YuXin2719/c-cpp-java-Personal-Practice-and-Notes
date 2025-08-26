//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////常用拷贝和替换算法_replace
//void test01() {
//	vector<int>v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//替换
//	//替换掉容器中所有的5，替换成50
//	replace(v1.begin(), v1.end(), 5, 50);
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
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