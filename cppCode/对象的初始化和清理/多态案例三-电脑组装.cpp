#include <iostream>
using namespace std;

//抽象不同零件的类
//抽象CPU类
class CPU {
public:
	//抽象计算函数
	virtual void calculate() = 0;
};

//抽象显卡类
class GPU {
public:
	//抽象显示函数
	virtual void display() = 0;
};

//抽象内存类
class RAM {
public:
	//抽象存储函数
	virtual void store() = 0;
};

//电脑类
class Computer {
public:
	//构造函数
	Computer(CPU* cpu, GPU* gpu, RAM* ram) : cpu(cpu), gpu(gpu), ram(ram) {}
	//组装电脑,工作函数
	void assemble() {
		cpu->calculate();
		gpu->display();
		ram->store();
	}
	//析构函数,释放三个电脑零件的内存
	~Computer() {
		if (cpu != nullptr) {
			delete cpu;
			cpu = nullptr;
		}
		if (gpu != nullptr) {
			delete gpu;
			gpu = nullptr;
		}
		if (ram != nullptr) {
			delete ram;
			ram = nullptr;
		}
	}
private:
	CPU* cpu; // CPU指针
	GPU* gpu; // GPU指针
	RAM* ram; // RAM指针
};

//具体厂商
//IntelCPU厂商
class IntelCPU : public CPU {
public:
	void calculate() override {
		cout << "Intel CPU is calculating." << endl;
	}
};

//IntelGPU厂商
class IntelGPU : public GPU {
public:
	void display() override {
		cout << "Intel GPU is displaying." << endl;
	}
};

//IntelRAM厂商
class IntelRAM : public RAM {
public:
	void store() override {
		cout << "Intel RAM is storing." << endl;
	}
};

//LenovoCPU厂商
class LenovoCPU : public CPU {
public:
	void calculate() override {
		cout << "Lenovo CPU is calculating." << endl;
	}
};

//LenovoGPU厂商
class LenovoGPU : public GPU {
public:
	void display() override {
		cout << "Lenovo GPU is displaying." << endl;
	}
};

//LenovoRAM厂商
class LenovoRAM : public RAM {
public:
	void store() override {
		cout << "Lenovo RAM is storing." << endl;
	}
};

void test01() {
	//第一台电脑零件
	CPU* intelCpu = new IntelCPU(); //如果IntelCPU定义了默认构造函数，两者等价（C++中）
	GPU* intelGpu = new IntelGPU();
	RAM* intelRam = new IntelRAM();

	cout << "组装第一台电脑" << endl;
	//组装第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelGpu, intelRam);
	computer1->assemble();
	//释放第一台电脑的内存
	delete computer1;

	cout << "------------------------" << endl;
	cout << "组装第二台电脑" << endl;
	//第二台电脑组装
	Computer* computer2 = new Computer(new LenovoCPU(), new LenovoGPU(), new LenovoRAM());
	computer2->assemble();
	//释放第二台电脑的内存
	delete computer2;

	cout << "------------------------" << endl;
	cout << "组装第三台电脑" << endl;
	//第三台电脑组装
	Computer* computer3 = new Computer(new LenovoCPU(), new IntelGPU(), new LenovoRAM());
	computer3->assemble();
	//释放第三台电脑的内存
	delete computer3;
}

int main()
{

	test01();

	system("pause");
	return 0;
}