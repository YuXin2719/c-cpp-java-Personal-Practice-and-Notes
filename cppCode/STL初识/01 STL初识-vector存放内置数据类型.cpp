//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm> //for_each��Ҫ������ͷ�ļ�
//
//
////��ӡ����
//void myPrint(int val) {
//	cout << val << " ";
//}
//
////vector�������������������
//
//void test01() {
//	vector<int> v; //����һ��int���͵�vector����
//	//���������������
//	v.push_back(10); //������ĩβ�������
//	v.push_back(20);
//	v.push_back(30);
//	//ͨ�����������������е�����
//	//��һ�ֱ�����ʽ
//	vector<int>::iterator it = v.begin(); //��ʼ��������ָ�������ĵ�һ��Ԫ��
//	while (it != v.end()) { //end()����һ����������ָ��������ĩβ
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//�ڶ��ֱ�����ʽ
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//�����ֱ�����ʽ
//	for (int i = 0; i < v.size(); i++) { //size()����������Ԫ�صĸ���
//		cout << v[i] << " "; //ͨ��[]���������е�Ԫ��
//	}
//	cout << endl;
//
//	//�����ֱ�����ʽ��C++11�����ԣ�
//	for (auto e : v) { //e���α�ʾ�����е�ÿ��Ԫ��
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//�����ֱ�����ʽ������STL�ṩ���㷨for_each
//	for_each(v.begin(), v.end(), myPrint);
//}
//
//int main() {
//
//	test01(); //���ò��Ժ���
//
//	system("pause");
//	return 0;
//}