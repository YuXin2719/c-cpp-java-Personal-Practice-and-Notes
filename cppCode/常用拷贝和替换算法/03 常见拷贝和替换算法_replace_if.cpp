//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////常见拷贝和替换算法_replace_if
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//把容器中大于5的元素替换为100
//	replace_if(v.begin(), v.end(), [](int val) {
//		return val > 5;
//		}, 100);
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
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