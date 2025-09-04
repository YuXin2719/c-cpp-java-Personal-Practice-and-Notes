using namespace std;
#include <iostream>
#include<thread>

void myPrint() {
	cout << "Hello from thread!" << endl;
}

int main() {
	//cout << "Hello, World!" << endl;

	thread t(myPrint);

	cout << "Goodbye from main!" << endl;

	t.join();

	return 0;
}