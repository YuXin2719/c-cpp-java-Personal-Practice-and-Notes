//#include<iostream>
//using namespace std;
//#include<set>
//
//// Set�����Ĳ����ɾ������
//
//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	//ɾ������
//	s1.erase(20); //ɾ��ָ��Ԫ��
//	s1.erase(s1.begin()); //ɾ����һ��Ԫ��
//	//��������
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//�������
//	s1.clear();
//	if (s1.empty()) {
//		cout << "s1 is empty!" << endl;
//	} else {
//		cout << "s1 is not empty!" << endl;
//	}
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}