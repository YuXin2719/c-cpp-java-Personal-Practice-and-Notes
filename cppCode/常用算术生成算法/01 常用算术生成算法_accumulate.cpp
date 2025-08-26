//#include<iostream>
//using namespace std;
//#include<vector>
//#include<numeric> //包含accumulate头文件
//
////常用算法生成算法accumulate
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//计算容器内元素的和
//	//0是初始值,决定了计算结果数据类型
//	int sum = accumulate(v.begin(), v.end(), 0);//0表示初始值
//	cout << "sum=" << sum << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}