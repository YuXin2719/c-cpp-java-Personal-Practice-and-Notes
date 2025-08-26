//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<functional>
//
////常用排序算法_sort
//void test01() {
//	vector<int> arr = { 5, 2, 9, 1, 5, 6 };
//	sort(arr.begin(), arr.end());
//	for (auto i : arr) {
//		cout << i << " ";
//	}
//	cout << endl;
//	//for_each也可以实现排序后的遍历
//	for_each(arr.begin(), arr.end(), [](int val) {cout << val << " "; });
//	cout << endl;
//
//	//降序
//	sort(arr.begin(), arr.end(), greater<int>());
//	for_each(arr.begin(), arr.end(), [](int val) {cout << val << " "; });
//	cout << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}