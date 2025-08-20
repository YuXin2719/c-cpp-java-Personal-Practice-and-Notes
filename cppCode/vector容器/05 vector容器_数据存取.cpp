//#include<iostream>
//using namespace std;
//#include<vector>
//
////vector容器 数据存取
//
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//通过[]方式访问容器中的数据
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	//通过at方式访问容器中的数据
//	for (int i = 0; i < v.size(); i++) {
//		cout << v.at(i) << " ";
//	}
//	cout << endl;
//	//获取第一个元素
//	cout << "第一个元素为：" << v.front() << endl;
//	//获取最后一个元素
//	cout << "最后一个元素为：" << v.back() << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}