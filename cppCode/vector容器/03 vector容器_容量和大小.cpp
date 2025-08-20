//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////vector容器的容量和大小操作
//void test01() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	//判断容器是否为空
//	if (v1.empty()) {
//		cout << "v1 is empty" << endl;
//	}
//	else {
//		cout << "v1 is not empty" << endl;
//		//获取容量
//		cout << "v1 capacity: " << v1.capacity() << endl;
//		//获取大小
//		cout << "v1 size: " << v1.size() << endl;
//	}
//
//	//重新指定大小
//	v1.resize(15, 100); //如果指定的大小大于原来大小，则以100填充新位置
//	printVector(v1);
//	cout << "v1 capacity: " << v1.capacity() << endl;
//	cout << "v1 size: " << v1.size() << endl;
//
//	v1.resize(5); //如果指定的大小小于原来大小，则多余元素被删除
//	printVector(v1);
//	cout << "v1 capacity: " << v1.capacity() << endl;
//	cout << "v1 size: " << v1.size() << endl;
//
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}