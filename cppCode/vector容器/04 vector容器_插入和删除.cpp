//#include<iostream>
//using namespace std;
//#include<vector>
//
////�����ɾ��Ԫ��
///*
//- `push_back(ele);` //β������Ԫ��ele
//- `pop_back();` //ɾ�����һ��Ԫ��
//- `insert(const_iterator pos, ele);` //������ָ��λ��pos����Ԫ��ele
//- `insert(const_iterator pos, int count, ele);` //������ָ��λ��pos����count��Ԫ��ele
//- `erase(const_iterator pos);` //ɾ��������ָ���Ԫ��
//- `erase(const_iterator start, const_iterator end);` //ɾ����������start��end֮���Ԫ��
//- `clear();` //ɾ�����������е�Ԫ��
//*/
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	vector<int> v;
//	//β������Ԫ��
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	printVector(v); // 10 20 30
//
//	//ɾ�����һ��Ԫ��
//	v.pop_back();
//	printVector(v); // 10 20
//
//	//������ָ��λ��pos����Ԫ��ele
//	vector<int>::iterator it = v.begin();
//	v.insert(it, 100); //�ڵ�һ��λ�ò���100
//	printVector(v); // 100 10 20
//
//	//������ָ��λ��pos����count��Ԫ��ele
//	it = v.begin(); // ���»�ȡ������
//	v.insert(it, 2, 200); //�ڵ�һ��λ�ò�������200
//	printVector(v); // 200 200 100 10 20
//
//	//ɾ��������ָ���Ԫ��
//	it = v.begin(); // ���»�ȡ������
//	v.erase(it);
//	printVector(v); // 200 100 10 20
//
//	//ɾ����������start��end֮���Ԫ��
//	vector<int>::iterator start = v.begin();
//	vector<int>::iterator end = v.end();
//	v.erase(start, end);
//	printVector(v); // (����)
//
//	//ɾ�����������е�Ԫ��
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.clear();
//	printVector(v); // (����)
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}