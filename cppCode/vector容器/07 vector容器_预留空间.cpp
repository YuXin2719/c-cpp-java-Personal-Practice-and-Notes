//#include<iostream>
//using namespace std;
//#include<vector>
//
////vector���� Ԥ���ռ�
//void test01() {
//	vector<int> v; //Ĭ�Ϲ��캯��
//
//	//����reserve����Ԥ���ռ�
//	v.reserve(100000); //Ԥ��100000���ռ�
//
//	int num = 0; //ͳ�ƿ��ٵĴ���
//	int* p = NULL; //ָ��vector���׵�ַ
//	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//		if (p != &v[0]) {
//			p = &v[0];
//			num++;
//		}
//	}
//	cout << "���ٴ�����" << num << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}