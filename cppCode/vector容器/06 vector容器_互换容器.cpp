//#include<iostream>
//using namespace std;
//#include<vector>
//
////vector��������
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////1.����ʹ��
//void test01() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	cout << "v1�������ݣ�";
//	printVector(v1);
//
//	vector<int> v2;
//	for (int i = 10; i < 20; i++) {
//		v2.push_back(i);
//	}
//	cout << "v2�������ݣ�";
//	printVector(v2);
//
//	//������������
//	v1.swap(v2);
//	cout << "������\n";
//	printVector(v1);
//	printVector(v2);
//}
//
////2.ʵ����;
////��������swap���������ڴ�ռ�
//void test02() {
//	vector<int> v1;
//	for (int i = 0; i < 100000; i++) {
//		v1.push_back(i);
//	}
//	cout << "v1����������" << v1.capacity() << endl;
//	//�������
//	v1.clear();
//	cout << "��պ�v1����������" << v1.capacity() << endl;
//	//�����ڴ�ռ�
//	vector<int>(v1).swap(v1);
//	cout << "������v1����������" << v1.capacity() << endl;
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}