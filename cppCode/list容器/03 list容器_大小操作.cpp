//#include<iostream>
//using namespace std;
//#include<list>
//
////list������С����
//
//void printList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	list<int>l;
//	//β��
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	printList(l);
//	//1.�ж������Ƿ�Ϊ��
//	if (l.empty()) {
//		cout << "����Ϊ��" << endl;
//	}
//	else {
//		cout << "������Ϊ��" << endl;
//	}
//	//2.����������С
//	cout << "������СΪ��" << l.size() << endl;
//	//3.����ָ��������С
//	l.resize(10); //Ĭ�����0
//	printList(l);
//	l.resize(15, 100); //ָ���������100
//	printList(l);
//	l.resize(5);
//	printList(l);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}