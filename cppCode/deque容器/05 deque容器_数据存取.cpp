//#include<iostream>
//using namespace std;
//#include<deque>
//
////deque�������ݴ�ȡ
//void test01() {
//	deque<int> d1;
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	//��������
//	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//ʹ���±����Ԫ��
//	for (int i = 0; i < d1.size(); i++) {
//		cout << d1[i] << " ";
//	}
//	cout << endl;
//	//ʹ��at()����Ԫ��
//	for (int i = 0; i < d1.size(); i++) {
//		cout << d1.at(i) << " ";
//	}
//	cout << endl;
//	//ʹ��front()��back()������βԪ��
//	cout << "��Ԫ��: " << d1.front() << endl;
//	cout << "βԪ��: " << d1.back() << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}