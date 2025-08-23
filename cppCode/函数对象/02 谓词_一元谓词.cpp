//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////一元谓词
////仿函数 返回值为bool类型
//class GreaterFive {
//public:
//	bool operator()(int val) {
//		return val > 5;
//	}
//};
//
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//查找容器中大于5的数字
//	//GreaterFive是匿名对象
//	auto it = find_if(v.begin(), v.end(), GreaterFive());
//	while (it != v.end()) {
//		cout << *it << " ";
//		it++;
//		it = find_if(it, v.end(), GreaterFive());
//	}
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}