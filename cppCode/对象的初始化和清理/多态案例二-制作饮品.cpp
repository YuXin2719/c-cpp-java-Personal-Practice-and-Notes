//#include <iostream>
//using namespace std;
//
////多态案例二-制作饮品
//class AbstractDrinking {
//public:
//	//煮水
//	virtual void boilWater() = 0;
//
//	//冲泡
//	virtual void brew() = 0;
//
//	//倒入杯中
//	virtual void pourInCup() = 0;
//
//	//添加配料
//	virtual void addCondiments() = 0;
//
//	//制作饮品
//	void makeDrink() {
//		boilWater();
//		brew();
//		pourInCup();
//		addCondiments();
//	}
//
//};
//
////制作咖啡
//class Coffee : public AbstractDrinking {
//public:
//	void boilWater() override {
//		cout << "煮水" << endl;
//	}
//	void brew() override {
//		cout << "冲泡咖啡" << endl;
//	}
//	void pourInCup() override {
//		cout << "倒入杯中" << endl;
//	}
//	void addCondiments() override {
//		cout << "添加糖和牛奶" << endl;
//	}
//};
//
////制作茶
//class Tea : public AbstractDrinking {
//public:
//	void boilWater() override {
//		cout << "煮水" << endl;
//	}
//	void brew() override {
//		cout << "冲泡茶叶" << endl;
//	}
//	void pourInCup() override {
//		cout << "倒入杯中" << endl;
//	}
//	void addCondiments() override {
//		cout << "添加枸杞" << endl;
//	}
//};
//
////制作函数
//void doWork(AbstractDrinking* drink) {
//	if (drink != nullptr) {
//		drink->makeDrink();
//		delete drink; //释放内存
//	}
//}
//
//void test01() {
//	//制作咖啡
//	doWork(new Coffee);
//
//	cout << "------------------------" << endl;
//
//	//制作茶
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