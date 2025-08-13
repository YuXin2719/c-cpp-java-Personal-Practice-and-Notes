#include <iostream>
using namespace std;

//����ͬ�������
//����CPU��
class CPU {
public:
	//������㺯��
	virtual void calculate() = 0;
};

//�����Կ���
class GPU {
public:
	//������ʾ����
	virtual void display() = 0;
};

//�����ڴ���
class RAM {
public:
	//����洢����
	virtual void store() = 0;
};

//������
class Computer {
public:
	//���캯��
	Computer(CPU* cpu, GPU* gpu, RAM* ram) : cpu(cpu), gpu(gpu), ram(ram) {}
	//��װ����,��������
	void assemble() {
		cpu->calculate();
		gpu->display();
		ram->store();
	}
	//��������,�ͷ���������������ڴ�
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
	CPU* cpu; // CPUָ��
	GPU* gpu; // GPUָ��
	RAM* ram; // RAMָ��
};

//���峧��
//IntelCPU����
class IntelCPU : public CPU {
public:
	void calculate() override {
		cout << "Intel CPU is calculating." << endl;
	}
};

//IntelGPU����
class IntelGPU : public GPU {
public:
	void display() override {
		cout << "Intel GPU is displaying." << endl;
	}
};

//IntelRAM����
class IntelRAM : public RAM {
public:
	void store() override {
		cout << "Intel RAM is storing." << endl;
	}
};

//LenovoCPU����
class LenovoCPU : public CPU {
public:
	void calculate() override {
		cout << "Lenovo CPU is calculating." << endl;
	}
};

//LenovoGPU����
class LenovoGPU : public GPU {
public:
	void display() override {
		cout << "Lenovo GPU is displaying." << endl;
	}
};

//LenovoRAM����
class LenovoRAM : public RAM {
public:
	void store() override {
		cout << "Lenovo RAM is storing." << endl;
	}
};

void test01() {
	//��һ̨�������
	CPU* intelCpu = new IntelCPU(); //���IntelCPU������Ĭ�Ϲ��캯�������ߵȼۣ�C++�У�
	GPU* intelGpu = new IntelGPU();
	RAM* intelRam = new IntelRAM();

	cout << "��װ��һ̨����" << endl;
	//��װ��һ̨����
	Computer* computer1 = new Computer(intelCpu, intelGpu, intelRam);
	computer1->assemble();
	//�ͷŵ�һ̨���Ե��ڴ�
	delete computer1;

	cout << "------------------------" << endl;
	cout << "��װ�ڶ�̨����" << endl;
	//�ڶ�̨������װ
	Computer* computer2 = new Computer(new LenovoCPU(), new LenovoGPU(), new LenovoRAM());
	computer2->assemble();
	//�ͷŵڶ�̨���Ե��ڴ�
	delete computer2;

	cout << "------------------------" << endl;
	cout << "��װ����̨����" << endl;
	//����̨������װ
	Computer* computer3 = new Computer(new LenovoCPU(), new IntelGPU(), new LenovoRAM());
	computer3->assemble();
	//�ͷŵ���̨���Ե��ڴ�
	delete computer3;
}

int main()
{

	test01();

	system("pause");
	return 0;
}