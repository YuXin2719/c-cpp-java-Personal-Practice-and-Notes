//#include<iostream>
//using namespace std;
//#include<string>
//#include<functional>
//#include<vector>
//#include<algorithm>
//
////�ڽ���������_��ϵ�º���
//
//void showVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////���� greater
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(40);
//	//Ĭ��������
//	sort(v.begin(), v.end());
//	showVec(v);
//	//����
//	//greater<int>() �ڽ��º�������
//	sort(v.begin(), v.end(), greater<int>());
//	showVec(v);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}