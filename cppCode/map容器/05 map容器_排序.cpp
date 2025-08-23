//#include<iostream>
//using namespace std;
//#include<map>
//
////mapÈİÆ÷_ÅÅĞò
//
////Ä£°åÀà
//template<class T>
//void showMap(T m) {
//	for (typename T::iterator it = m.begin(); it != m.end(); it++) {
//		cout << "key:" << it->first << " value:" << it->second << endl;
//	}
//}
//
//class myCompare {
//public:
//	bool operator()(int v1, int v2) const {
//		return v1 > v2;
//	}
//};
//
//void test01() {
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(3, 30));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(4, 40));
//	//mapÈİÆ÷»á×Ô¶¯ÅÅĞò
//	showMap(m);
//	cout << "------------------" << endl;
//	map<int, int, myCompare>m2;
//	m2.insert(pair<int, int>(1, 10));
//	m2.insert(pair<int, int>(3, 30));
//	m2.insert(pair<int, int>(2, 20));
//	m2.insert(pair<int, int>(4, 40));
//	showMap(m2);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}