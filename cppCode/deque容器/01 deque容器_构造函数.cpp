//#include<iostream>
//using namespace std;
//#include<deque>
//
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////deque���� ���캯��
//void test() {
//	deque<int> d1; //Ĭ�Ϲ��� �޲ι���
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//	deque<int> d2(d1); //��������
//	printDeque(d2);
//	deque<int> d3(d2.begin(), d2.end()); //���乹��
//	printDeque(d3);
//	deque<int> d4(10, 100); //n��elem
//	printDeque(d4);
//}
//
//int main() {
//	test();
//	system("pause");
//	return 0;
//}