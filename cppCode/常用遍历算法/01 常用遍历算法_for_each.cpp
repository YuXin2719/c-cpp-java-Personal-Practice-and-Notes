//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////���ñ����㷨_for_each
//
////��ͨ����
//void myPrint(int val) {
//	cout << val << " ";
//}
//
////�º���
//class MyPrint {
//public:
//	void operator()(int val) {
//		cout << val << " ";
//	}
//};
//
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//����for�͵�������������
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//����STL�ṩ�ı����㷨_for_each
//	for_each(v.begin(), v.end(), [](int val) {
//		cout << val << " ";
//		}); //�����﷨:[](int val){}; ����һ����������,û������,ֻ��ʹ��һ��
//	cout << endl;
//	//ʹ���Լ�д����ͨ��������
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//	//ʹ���Լ�д�ķº�������
//	for_each(v.begin(), v.end(), MyPrint());
//	cout << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}