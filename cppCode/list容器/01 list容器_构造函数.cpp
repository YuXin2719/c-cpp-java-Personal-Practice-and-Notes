//#include<iostream>
//using namespace std;
//#include<list> //list����ͷ�ļ�
//
//void showList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////list����_���캯��
//void test01() {
//	//Ĭ�Ϲ���
//	list<int> l1;
//	showList(l1);
//	//���䷽ʽ����
//	int arr[] = { 1,2,3,4,5 };
//	list<int> l2(arr, arr + sizeof(arr) / sizeof(int));
//	showList(l2);
//	list<int> l5(l1.begin(), l1.end()); //ʹ��l1�ĵ��������乹��
//	showList(l5);
//	//��������
//	list<int> l3(l2);
//	showList(l3);
//	//n��elem��ʽ����
//	list<int> l4(10, 100); //10��100
//	showList(l4);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}