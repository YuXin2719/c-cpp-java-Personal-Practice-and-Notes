//#include<iostream>
//using namespace std;
//#include<map>
//
////map�����Ĳ����ɾ��
//
//void showMap(map<int, int>m) {
//	for (auto it = m.begin(); it != m.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}
//
//void test01() {
//	map<int, int>m1;
//	//��������
//	//��ʽ1
//	m1.insert(pair<int, int>(1, 10));
//	//��ʽ2,�Ƽ�,�Զ������Ƶ�
//	m1.insert(make_pair(2, 20));
//	//��ʽ3,���Ƽ�,Ч�ʵ�
//	m1.insert(map<int, int>::value_type(3, 30));
//	//��ʽ4,�����±����,������
//	// ��Ϊ���key����,�Ḳ��ԭ����value,�������key������,�ᴴ��һ���µ�key,valueĬ��ֵΪ0
//	// ��;,��������key���ʵ�value
//	m1[4] = 40;
//	//����map
//	showMap(m1);
//
//	//ɾ��Ԫ��
//	m1.erase(m1.begin());
//	m1.erase(2); //����keyɾ��
//	cout << "ɾ��Ԫ�غ�" << endl;
//	showMap(m1);
//	m1.erase(m1.begin(), m1.end()); //ɾ������
//	cout << "����ɾ��Ԫ�غ�" << endl;
//	showMap(m1);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}