//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////����Ƕ������
//void test01() {
//	vector<vector<int>> v; //��ά����
//	//���ά�������������
//	for (int i = 0; i < 10; i++) {
//		vector<int> temp;
//		for (int j = 0; j < 10; j++) {
//			temp.push_back(i + j);
//		}
//		v.push_back(temp);
//	}
//	//������ά����
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
//			cout << *vit << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}