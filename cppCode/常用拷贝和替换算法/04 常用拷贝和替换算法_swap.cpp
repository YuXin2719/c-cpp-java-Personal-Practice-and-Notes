//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////常用拷贝和替换算法_swap
//void test01() {
//	vector<int>v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	vector<int>v2;
//	for (int i = 10; i < 20; i++) {
//		v2.push_back(i);
//	}
//	cout << "交换前：" << endl;
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	v1.swap(v2);//交换
//	//或者swap(v1,v2);
//	cout << "交换后：" << endl;
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
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