//#include<iostream>
//using namespace std;
//#include<vector>
//
////vector容器互换
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////1.基本使用
//void test01() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	cout << "v1容器内容：";
//	printVector(v1);
//
//	vector<int> v2;
//	for (int i = 10; i < 20; i++) {
//		v2.push_back(i);
//	}
//	cout << "v2容器内容：";
//	printVector(v2);
//
//	//交换容器内容
//	v1.swap(v2);
//	cout << "交换后：\n";
//	printVector(v1);
//	printVector(v2);
//}
//
////2.实际用途
////可以巧用swap函数收缩内存空间
//void test02() {
//	vector<int> v1;
//	for (int i = 0; i < 100000; i++) {
//		v1.push_back(i);
//	}
//	cout << "v1容器容量：" << v1.capacity() << endl;
//	//清空容器
//	v1.clear();
//	cout << "清空后v1容器容量：" << v1.capacity() << endl;
//	//收缩内存空间
//	vector<int>(v1).swap(v1);
//	cout << "收缩后v1容器容量：" << v1.capacity() << endl;
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}