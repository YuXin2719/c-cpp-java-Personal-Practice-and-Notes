//#include <iostream>
//using namespace std;
//
////虚析构和纯虚析构
//
//class Animal {
//public:
//	Animal() {
//		cout << "Animal构造函数调用" << endl;
//	}
//
//	//利用虚析构函数，确保子类的析构函数被调用
//	//virtual ~Animal() {
//	//	cout << "Animal析构函数调用" << endl;
//	//}
//
//	//纯虚析构 需要声明，也需要实现
//	//有了纯虚析构之后，这个类就变成了抽象类，不能实例化
//	virtual ~Animal() = 0;
//
//	//纯虚函数
//	virtual void speak() = 0;
//
//};
//
//Animal::~Animal() {
//	cout << "Animal纯虚析构函数调用" << endl;
//}
//
//class Cat : public Animal {
//public:
//
//	Cat(string name) {
//		cout << "Cat构造函数调用" << endl;
//		m_name = new string(name);
//	}
//
//	virtual void speak() override {
//		cout << *m_name << "小猫在说话" << endl;
//	}
//
//	~Cat() {
//		if (m_name != NULL) {
//			delete m_name;
//			m_name = NULL;
//		}
//		cout << "Cat析构函数调用" << endl;
//	}
//
//	string* m_name;
//};
//
//void test01() {
//	Animal* a = new Cat("Tom");
//	a->speak(); //调用Cat的speak函数
//	//父类指针在析构的时候 不会调用子类的析构函数，导致子类的资源没有释放
//	delete a; //释放内存
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