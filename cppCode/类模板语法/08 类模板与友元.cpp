//#include<iostream>
//using namespace std;
//#include<string>
//
////ͨ��ȫ�ֺ�����ӡPerson����Ϣ
//
////��ǰ�ñ�����ֱ��Person��Ĵ���
//template<class T1, class T2>
//class Person;
//
////����ʵ��
////��Ҫд��Person���ǰ��
//template<class T1, class T2>
//void printPerson2(const Person<T1, T2>& p) {
//	cout << "����ʵ�� --- Name: " << p.name << ", Age: " << p.age << endl;
//}
//
//template<class T1, class T2>
//class Person {
//	//ȫ�ֺ��� ����ʵ��
//	//Ϊʲô����ȫ�ֺ���:
//	// ��Ա����Ĭ����һ�� thisָ�루ָ��������Ķ��󣩣������������Ҫ��ʽ���� Person����p����˵���������� this��
//	// ������ǳ�Ա������Ӧ����ֱ�ӷ��� name�� age��������Ҫ p.ǰ׺��
//	// �ص������Ҫ����һ��Person����˵����������ĳ���ض��� Personʵ���������ȫ�ֺ�����
//	//��friend��Person���˽�г�Ա���Ա�printPerson����
//	friend void printPerson(const Person<T1, T2>& p) {
//		cout << "����ʵ�� --- Name: " << p.name << ", Age: " << p.age << endl;
//	}
//
//	//ȫ�ֺ��� ����ʵ��
//	//�ӿ�ģ������б�<>����ʾ����һ��ģ�庯��
//	//���ȫ�ֺ���������ʵ��,��Ҫ�ñ�������ǰ֪������һ��ģ�庯��
//	friend void printPerson2<>(const Person<T1, T2>& p);
//
//public:
//	Person(T1 n, T2 a) : name(n), age(a) {}
//private:
//	T1 name;
//	T2 age;
//};
//
////1.ȫ�ֺ���������ʵ��
//void test01() {
//	Person<string, int> p("Tom", 20);
//	printPerson(p); //����ȫ�ֺ���
//}
//
////2.ȫ�ֺ���������ʵ��
//void test02() {
//	Person<string, int> p("Jerry", 22);
//	printPerson2(p); //����ȫ�ֺ���
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}