//#include<iostream>
//using namespace std;
//#include<algorithm>
//#include<vector>
//
////���������㷨_merge
//void test01() {
//	vector<int>v1;
//	v1.push_back(10);
//	v1.push_back(30);
//	v1.push_back(50);
//	v1.push_back(70);
//	vector<int>v2;
//	v2.push_back(20);
//	v2.push_back(40);
//	v2.push_back(60);
//	v2.push_back(80);
//	vector<int>vTarget;
//	//Ŀ���������뿪���㹻�ռ�
//	vTarget.resize(v1.size() + v2.size());
//	//�ϲ������������У�ǰ�����������ж��������
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}