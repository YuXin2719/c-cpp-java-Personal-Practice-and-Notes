//#include<iostream>
//using namespace std;
//#include<list>
//
////list�������ݴ�ȡ
//void test01() {
//	list<int> l1;
//	l1.push_back(10);
//	l1.push_back(20);
//	l1.push_back(30);
//	l1.push_back(40);
//	//l1[0] = 100; //��֧���±����
//	//l1.at(0) = 100; //��֧��at����
//	//ԭ����list�ײ���˫������ṹ����֧��������ʣ�ֻ��˳����ʡ�
//	cout << "��һ��Ԫ��Ϊ��" << l1.front() << endl; //���ʵ�һ��Ԫ��
//	cout << "���һ��Ԫ��Ϊ��" << l1.back() << endl; //�������һ��Ԫ��
//
//	//��֤�������Ƿ�֧���������
//	list<int>::iterator it = l1.begin();
//	it++; //������ǰ��һ��λ��
//	it--; //����������һ��λ��
//	//it += 2; //��֧���������,��Ϊ����������Ծ�ķ���,������
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}