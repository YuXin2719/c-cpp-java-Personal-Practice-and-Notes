//#include<iostream>
//using namespace std;
//#include<deque>
//
////deque���� ��С����
//
//void printDeque(deque<int>& d) {
//	for (int i = 0; i < d.size(); i++) {
//		cout << d[i] << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	deque<int> d1;
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	if (d1.empty()) {
//		cout << "d1 is empty" << endl;
//	}
//	else {
//		cout << "d1 is not empty" << endl;
//		cout << "d1 size: " << d1.size() << endl;
//	}
//
//	//����ָ����С
//	//d1.resize(15);
//	d1.resize(15, 100); //ָ���´�СΪ15��������Ԫ��ֵΪ100
//	printDeque(d1);
//	d1.resize(5);
//	printDeque(d1);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}