//#include <iostream>
//using namespace std;
//
////��̬������-������Ʒ
//class AbstractDrinking {
//public:
//	//��ˮ
//	virtual void boilWater() = 0;
//
//	//����
//	virtual void brew() = 0;
//
//	//���뱭��
//	virtual void pourInCup() = 0;
//
//	//�������
//	virtual void addCondiments() = 0;
//
//	//������Ʒ
//	void makeDrink() {
//		boilWater();
//		brew();
//		pourInCup();
//		addCondiments();
//	}
//
//};
//
////��������
//class Coffee : public AbstractDrinking {
//public:
//	void boilWater() override {
//		cout << "��ˮ" << endl;
//	}
//	void brew() override {
//		cout << "���ݿ���" << endl;
//	}
//	void pourInCup() override {
//		cout << "���뱭��" << endl;
//	}
//	void addCondiments() override {
//		cout << "����Ǻ�ţ��" << endl;
//	}
//};
//
////������
//class Tea : public AbstractDrinking {
//public:
//	void boilWater() override {
//		cout << "��ˮ" << endl;
//	}
//	void brew() override {
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	void pourInCup() override {
//		cout << "���뱭��" << endl;
//	}
//	void addCondiments() override {
//		cout << "������" << endl;
//	}
//};
//
////��������
//void doWork(AbstractDrinking* drink) {
//	if (drink != nullptr) {
//		drink->makeDrink();
//		delete drink; //�ͷ��ڴ�
//	}
//}
//
//void test01() {
//	//��������
//	doWork(new Coffee);
//
//	cout << "------------------------" << endl;
//
//	//������
//	doWork(new Tea);
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