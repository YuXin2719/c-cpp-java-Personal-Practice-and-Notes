//#include<iostream>
//using namespace std;
//#include<list>
//
////list������ת������
//
//void showList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//bool myCompare(int v1, int v2) {
//	return v1 > v2; //����true,����Ԫ��
//}
//
//void test01() {
//	list<int> l;
//	l.push_back(1);
//	l.push_back(3);
//	l.push_back(2);
//	l.push_back(4);
//	l.push_back(5);
//	showList(l);
//	//��ת����
//	l.reverse();
//	showList(l);
//	//���в�֧��������ʵ�����������,�������ñ�׼�㷨 #include<algorithm>
//	//��֧��������ʵ���������,�ڲ����ṩ��Ӧ��һЩ�㷨
//	//�������
//	l.sort(); //Ĭ���������,��С��������
//	showList(l);
//	//��������
//	l.sort(myCompare);
//	showList(l);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}