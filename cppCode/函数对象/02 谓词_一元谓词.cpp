//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////һԪν��
////�º��� ����ֵΪbool����
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
//	//���������д���5������
//	//GreaterFive����������
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