//#include<iostream>
//using namespace std;
//#include<deque>
//#include<algorithm> //����sort������ͷ�ļ�
//
////deque��������
//void test01() {
//	deque<int> d;
//	d.push_back(10);
//	d.push_back(40);
//	d.push_back(50);
//	d.push_back(20);
//	d.push_back(30);
//	//ʹ��sort������deque������������,Ĭ���Ǵ�С��������
//	//����֧��������ʵĵ�����������������ʹ��sort�㷨
//	//vector��deque��array������ʹ��sort�㷨
//	sort(d.begin(), d.end());
//	//��������Ľ��
//	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}