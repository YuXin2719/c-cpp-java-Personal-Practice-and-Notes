//#include<iostream>
//using namespace std;
//#include<set>
//
////set��������͸�ֵ
//void showSet(const set<int>& s) {
//	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	set<int> s1; //Ĭ�Ϲ��캯��
//
//	//��������,ֻ��insert�ķ�ʽ
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	s1.insert(40);
//	//��������
//	//set�����ص㣺�Զ������Ҳ������ظ�Ԫ��
//	showSet(s1);
//
//	set<int> s2(s1); //�������캯��
//	showSet(s2);
//	set<int> s3 = s1; //�������캯��
//	showSet(s3);
//	set<int> s4(s1.begin(), s1.end()); //��������Χ���캯��
//	showSet(s4);
//	set<int> s5{ 10,20,30 }; //�б��ʼ��
//	showSet(s5);
//	//��ֵ����
//	s1 = s2; //��ֵ�����
//	showSet(s1);
//	s1 = { 100,200,300 }; //�б�ֵ
//	showSet(s1);
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}