//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(const vector<int>& v) {
//	//const_iterator��һ��ֻ���������������޸�Ԫ��
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////vector��������
//void test01() {
//	//Ĭ�Ϲ���
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	//n��elem�Ĺ���
//	vector<int> v2(10, 100);
//	printVector(v2);
//
//	//���䷽ʽ����
//	vector<int> v3(v2.begin(), v2.end());
//	printVector(v3);
//
//	//��������
//	vector<int> v4(v3);
//	printVector(v4);
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}