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
////deque���������ɾ��
//void test01() {
//	deque<int> d;
//	//β������
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	printDeque(d);
//	//ͷ������
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//β��ɾ��
//	d.pop_back();
//	printDeque(d);
//	//ͷ��ɾ��
//	d.pop_front();
//	printDeque(d);
//	//�������
//	d.clear();
//	printDeque(d);
//}
//
//void test02() {
//	deque<int> d;
//	//β������
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	//ͷ������
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//insert����
//	d.insert(d.begin(), 1000); //��ͷ������1000
//	printDeque(d);
//	d.insert(d.begin(), 2, 1000); //��ͷ������2��1000
//	printDeque(d);
//	//�����������
//	deque<int> d2;
//	d2.push_back(10000);
//	d2.push_back(20000);
//	d2.push_back(30000);
//	d.insert(d.begin(), d2.begin(), d2.end()); //��ͷ������d2������Ԫ��
//	printDeque(d);
//}
//
//void test03() {
//	deque<int> d;
//	//β������
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	//ͷ������
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//eraseɾ��
//	d.erase(d.begin()); //ɾ��ͷ��Ԫ��
//	printDeque(d);
//	d.erase(d.begin(), d.end() - 1); //ɾ�������һ��Ԫ���������Ԫ��
//	printDeque(d);
//	//�������
//	d.clear();
//	printDeque(d);
//}
//
//int main() {
//	test01();
//	test02();
//	test03();
//	system("pause");
//	return 0;
//}