//#include<iostream>
//using namespace std;
//#include<string>
//#include<functional>
//#include<vector>
//#include<algorithm>
//
////内建函数对象_关系仿函数
//
//void showVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////大于 greater
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(40);
//	//默认是升序
//	sort(v.begin(), v.end());
//	showVec(v);
//	//降序
//	//greater<int>() 内建仿函数对象
//	sort(v.begin(), v.end(), greater<int>());
//	showVec(v);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}