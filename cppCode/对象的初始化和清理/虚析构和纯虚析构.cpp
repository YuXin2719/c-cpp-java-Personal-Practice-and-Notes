//#include <iostream>
//using namespace std;
//
////�������ʹ�������
//
//class Animal {
//public:
//	Animal() {
//		cout << "Animal���캯������" << endl;
//	}
//
//	//����������������ȷ���������������������
//	//virtual ~Animal() {
//	//	cout << "Animal������������" << endl;
//	//}
//
//	//�������� ��Ҫ������Ҳ��Ҫʵ��
//	//���˴�������֮�������ͱ���˳����࣬����ʵ����
//	virtual ~Animal() = 0;
//
//	//���麯��
//	virtual void speak() = 0;
//
//};
//
//Animal::~Animal() {
//	cout << "Animal����������������" << endl;
//}
//
//class Cat : public Animal {
//public:
//
//	Cat(string name) {
//		cout << "Cat���캯������" << endl;
//		m_name = new string(name);
//	}
//
//	virtual void speak() override {
//		cout << *m_name << "Сè��˵��" << endl;
//	}
//
//	~Cat() {
//		if (m_name != NULL) {
//			delete m_name;
//			m_name = NULL;
//		}
//		cout << "Cat������������" << endl;
//	}
//
//	string* m_name;
//};
//
//void test01() {
//	Animal* a = new Cat("Tom");
//	a->speak(); //����Cat��speak����
//	//����ָ����������ʱ�� ���������������������������������Դû���ͷ�
//	delete a; //�ͷ��ڴ�
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}