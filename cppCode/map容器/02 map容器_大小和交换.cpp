//#include<iostream>
//using namespace std;
//#include<map>
//
////map����_��С�ͽ���
//void test01() {
//	map<int, int>m1;
//	//��������
//	m1.insert(pair<int, int>(1, 10));
//	m1.insert(pair<int, int>(2, 20));
//	m1.insert(pair<int, int>(3, 30));
//	m1.insert(pair<int, int>(4, 40));
//	m1.insert(pair<int, int>(5, 50));
//	//ͨ��size()������ȡ������Ԫ�صĸ���
//	cout << "m1 size = " << m1.size() << endl;
//	//ͨ��empty()�����ж������Ƿ�Ϊ��
//	if (m1.empty()) {
//		cout << "m1Ϊ��" << endl;
//	}
//	else {
//		cout << "m1��Ϊ��" << endl;
//	}
//	//������������
//	map<int, int>m2;
//	m2.insert(pair<int, int>(10, 100));
//	m2.insert(pair<int, int>(20, 200));
//	cout << "����ǰ��" << endl;
//	cout << "m1 size = " << m1.size() << endl;
//	cout << "m2 size = " << m2.size() << endl;
//	m1.swap(m2);//����
//	cout << "������" << endl;
//	cout << "m1 size = " << m1.size() << endl;
//	cout << "m2 size = " << m2.size() << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}