//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////�����������滻�㷨_replace_if
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//�������д���5��Ԫ���滻Ϊ100
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