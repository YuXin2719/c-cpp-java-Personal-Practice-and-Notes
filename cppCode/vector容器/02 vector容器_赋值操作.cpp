//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(const vector<int>& v) {
//	for (auto it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////vector赋值
//void test1() {
//	vector<int> v1;
//	for (int i = 0; i < 10; ++i) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//	cout << endl;
//
//	//赋值 operator=
//	vector<int> v2;
//	v2 = v1;
//	printVector(v2);
//
//	//赋值 assign
//	vector<int> v3;
//	v3.assign(v1.begin(), v1.end()); //end是最后一位的下一位
//	printVector(v3);
//
//	//赋值 assign
//	vector<int> v4;
//	v4.assign(10, 100);
//	printVector(v4);
//}
//
//int main() {
//
//	test1();
//
//	system("pause");
//	return 0;
//}