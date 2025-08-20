//#include<iostream>
//using namespace std;
//#include<deque>
//
////vector容器 赋值操作
//
//void print(deque<int>& dq) {
//	for (int i = 0; i < dq.size(); i++) {
//		cout << dq[i] << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	deque<int> dq1;
//	for (int i = 0; i < 10; i++) {
//		dq1.push_back(i);
//	}
//	print(dq1);
//	deque<int> dq2;
//	dq2 = dq1; //赋值操作
//	print(dq2);
//	deque<int> dq3;
//	dq3.assign(dq1.begin(), dq1.end()); //区间赋值
//	print(dq3);
//	deque<int> dq4;
//	dq4.assign(10, 100); //重复赋值
//	print(dq4);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}