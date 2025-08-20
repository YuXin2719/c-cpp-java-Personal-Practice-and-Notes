//#include<iostream>
//using namespace std;
//#include<vector>
//
////vector容器 预留空间
//void test01() {
//	vector<int> v; //默认构造函数
//
//	//利用reserve函数预留空间
//	v.reserve(100000); //预留100000个空间
//
//	int num = 0; //统计开辟的次数
//	int* p = NULL; //指向vector的首地址
//	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//		if (p != &v[0]) {
//			p = &v[0];
//			num++;
//		}
//	}
//	cout << "开辟次数：" << num << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}