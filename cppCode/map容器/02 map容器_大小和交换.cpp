//#include<iostream>
//using namespace std;
//#include<map>
//
////map容器_大小和交换
//void test01() {
//	map<int, int>m1;
//	//插入数据
//	m1.insert(pair<int, int>(1, 10));
//	m1.insert(pair<int, int>(2, 20));
//	m1.insert(pair<int, int>(3, 30));
//	m1.insert(pair<int, int>(4, 40));
//	m1.insert(pair<int, int>(5, 50));
//	//通过size()函数获取容器中元素的个数
//	cout << "m1 size = " << m1.size() << endl;
//	//通过empty()函数判断容器是否为空
//	if (m1.empty()) {
//		cout << "m1为空" << endl;
//	}
//	else {
//		cout << "m1不为空" << endl;
//	}
//	//交换两个容器
//	map<int, int>m2;
//	m2.insert(pair<int, int>(10, 100));
//	m2.insert(pair<int, int>(20, 200));
//	cout << "交换前：" << endl;
//	cout << "m1 size = " << m1.size() << endl;
//	cout << "m2 size = " << m2.size() << endl;
//	m1.swap(m2);//交换
//	cout << "交换后：" << endl;
//	cout << "m1 size = " << m1.size() << endl;
//	cout << "m2 size = " << m2.size() << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}