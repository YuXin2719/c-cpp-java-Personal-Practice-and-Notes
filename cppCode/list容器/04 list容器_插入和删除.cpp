//#include<iostream>
//using namespace std;
//#include<list>
//
////list���������ɾ��
//
///*
//- `push_back(elem);`//������β������һ��Ԫ��
//- `pop_back();`//ɾ�����������һ��Ԫ��
//- `push_front(elem);`//��������ͷ����һ��Ԫ��
//- `pop_front();`//��������ͷ�Ƴ���һ��Ԫ��
//- `insert(pos,elem);`//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
//- `insert(pos,n,elem);`//��posλ�ò���n��elem���ݣ��޷���ֵ��
//- `insert(pos,beg,end);`//��posλ�ò���[beg,end]��������ݣ��޷���ֵ��
//- `clear();`//�Ƴ���������������
//- `erase(beg,end);`//ɾ��[beg,end]��������ݣ�������һ�����ݵ�λ�á�
//- `erase(pos);`//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//- `remove(elem);`//ɾ��������������elemֵƥ���Ԫ�ء�
//*/
//
//void printList(const list<int>& L) {
//	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	list<int> l;
//	//β��
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	//ͷ��
//	l.push_front(100);
//	l.push_front(200);
//	l.push_front(300);
//	printList(l); //300 200 100 10 20 30
//	//βɾ
//	l.pop_back();
//	printList(l); //300 200 100 10 20
//	//ͷɾ
//	l.pop_front();
//	printList(l); //200 100 10 20
//	//����
//	l.insert(l.begin(), 1000);
//	printList(l); //1000 200 100 10 20
//	l.insert(l.begin(), 2, 888);
//	printList(l); //888 888 1000 200 100 10 20
//	//ɾ��
//	l.erase(l.begin());
//	printList(l); //888 1000 200 100 10 20
//	//�Ƴ�
//	l.remove(888);
//	printList(l); //1000 200 100 10 20
//	//���
//	l.clear();
//	printList(l); //��
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}