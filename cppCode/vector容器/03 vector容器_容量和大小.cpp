//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////vector�����������ʹ�С����
//void test01() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	//�ж������Ƿ�Ϊ��
//	if (v1.empty()) {
//		cout << "v1 is empty" << endl;
//	}
//	else {
//		cout << "v1 is not empty" << endl;
//		//��ȡ����
//		cout << "v1 capacity: " << v1.capacity() << endl;
//		//��ȡ��С
//		cout << "v1 size: " << v1.size() << endl;
//	}
//
//	//����ָ����С
//	v1.resize(15, 100); //���ָ���Ĵ�С����ԭ����С������100�����λ��
//	printVector(v1);
//	cout << "v1 capacity: " << v1.capacity() << endl;
//	cout << "v1 size: " << v1.size() << endl;
//
//	v1.resize(5); //���ָ���Ĵ�СС��ԭ����С�������Ԫ�ر�ɾ��
//	printVector(v1);
//	cout << "v1 capacity: " << v1.capacity() << endl;
//	cout << "v1 size: " << v1.size() << endl;
//
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}