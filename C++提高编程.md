# C++提高编程



- 本阶段主要针对C++==泛型编程==和==STL==技术做详细讲解，探讨C++更深层的使用



## 1 模板

### 1.1 模版的概念

模版就是建立**通用的模具**，大大**提高复用性**

例如生活中的模板

一寸照片模版：

![image-20250815190032885](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250815190032885.png)

PPT模板（不放图了，大家都知道）



模板的特点：

- 模板不可以直接使用，他只是一个框架
- 模板的通用并不是万能的



### 1.2 函数模板



- C++另一种编程思想称为 ==泛型编程== ，主要利用的技术就是模板
- C++提供两种模板机制：**函数模板**和**类模板**

#### 1.2.1 函数模板语法

函数模板的作用：

建立一个通用函数，其返回值类型和形参类型可以不具体指定，用一个**虚拟的类型**来代表



**语法：**

```c++
template<typename T>
函数声明或定义
```

**解释：**

template --- 声明创建模板

typename --- 表明起后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母



**示例：**

```c++
#include<iostream>
using namespace std;

//函数模板

//交换两个整形交换的函数
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型的函数
void swap(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}

//函数模板的定义
template <typename T> //声明一个模板类型T，告诉编译器，T是一个类型参数
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10, b = 20;
	float c = 1.1f, d = 2.2f;

	//swap(a, b); //调用整形的交换函数
	//swap(c, d); //调用浮点型的交换函数

	//使用函数模板
	//两种方式使用函数模板
	//1.显示指定类型
	mySwap<int>(a, b); //显示指定类型为int
	//2.编译器自动推导类型
	mySwap(c, d); //编译器自动推导类型为float

	cout << "a=" << a << ",b=" << b << endl;
	cout << "c=" << c << ",d=" << d << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 函数模板利用关键字 template
- 使用函数模板有两种方式：自动类型推导、显示指定类型
- 模板的目的是为了提高复用性，将类型参数化



#### 1.2.2 函数模板注意事项

注意事项：

- 自动类型推导，必须推导出一致的数据类型T，才可以使用
- 模板必须要确定出T的数据类型，才可以使用

**示例：**

```c++
#include<iostream>
using namespace std;

//函数模板注意事项

template <typename T> //typename可以替换为class
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01() {
	int a = 10, b = 20;
	char c = 'A';
	mySwap(a, b); //编译器自动推导出T为int类型
	//mySwap(a, c); //编译器无法推导出T的类型，因为int和char类型不一致
	cout << "a=" << a << ",b=" << b << endl;
}

//2.模版必须确定出T的类型才能使用
template <typename T>
void func() {
	cout << "func() called" << endl;
}

void test02() {
	//func(); //编译器无法推导出T的类型
	func<int>(); //显示指定T的类型为int
	func<double>(); //显示指定T的类型为double
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
```

总结：

- 使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型



#### 1.2.3 函数模板案例

案例描述：

- 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
- 排序规则从大到小，排序算法为**选择算法**
- 分别利用**char数组**和**int数组**进行测试



**示例：**

```c++
#include<iostream>
using namespace std;

//实现通用对数组进行排序的函数
//规则 从大到小
//算法 选择排序
//测试 char数组,int数组

//排序算法,选择排序
template<typename T>
void sortArray(T arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		if (maxIndex != i) {
			T temp = arr[i];
			arr[i] = arr[maxIndex];
			arr[maxIndex] = temp;
		}
	}
}

//提供打印数组的模板
template<typename T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	//测试char数组
	char arr[] = "badcfe";
	int len = sizeof(arr) / sizeof(arr[0]) - 1; // -1是因为只有字面量定义的字符串的最后有'\0'，这个\0不需要排序,{'a','b','c'}这样定义的字符串没有'\0'
	sortArray(arr, len);
	printArray(arr, len);

	//测试int数组
	int arr2[] = { 5, 2, 9, 1, 5, 6 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	sortArray(arr2, len2);
	printArray(arr2, len2);
}

int main() {

	test01();

	system("pause");
	return 0;
}
```



#### 1.2.4 普通函数和函数模板的区别



**普通函数和函数模板的区别：**

- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用显示指定类型的方式，可以发生隐式类型转换

**示例：**

```c++
#include<iostream>
using namespace std;

//普通函数和函数模板的区别

//1.普通函数可以发生隐式类型转换，而函数模板不可以
//2.函数模板 用自动类型推导,不可以发生隐式类型转换
//2.函数模版 用显示指定类型,可以发生隐式类型转换

//普通函数
int add1(int a, int b) {
	return a + b;
}

//函数模板
template<typename T>
T add2(T a, T b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'A'; //char类型的'A'对应的ASCII码是65
	//cout << add(a, b) << endl; //30
	cout << add1(a, c) << endl; //30

	//自动类型推导,不会发生隐式类型转换
	cout << add2(a, b) << endl; //30
	//显示指定类型,可以发生隐式类型转换
	cout << add2<int>(a, c) << endl; //75
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T



#### 1.2.5 普通函数和函数模板的调用规则



调用规则如下：

1. 如果函数模板和普通函数都可以实现，优先调用普通函数
2. 可以通过空模板参数列表来强调调用函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配，优先调用函数模板



**示例：**

```c++
#include<iostream>
using namespace std;

//普通函数和函数模板的调用规则
//1.如果函数模板和普通函数都可以匹配，优先调用普通函数
//2.可以通过空模版参数列表的方式，强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配，编译器会优先选择函数模板

//假如普通函数只是声明,没有定义,编译器依旧会选择普通函数,导致报错
void myPrint(int a, int b) {
	cout << "普通函数调用" << endl;
}

template<typename T>
void myPrint(T a, T b) {
	cout << "函数模板调用" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) {
	cout << "重载的函数模板调用" << endl;
}


void test01() {
	myPrint(10, 20); //普通函数调用
	myPrint<>(10, 20); //函数模板调用
	myPrint(10, 20, 30); //重载的函数模板调用
	//如果函数模板产生更好的匹配，编译器会优先选择函数模板
	char a = 'a';
	char b = 'b';
	myPrint(a, b); //函数模板调用
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性



#### 1.2.6 模版的局限性

**局限性：**

- 模版的通用性并不是万能的



**例如：**

```c++
template<typename T>
void f(T a , T b) {
	a = b;
}
```

在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了



**再例如：**

```c++
template<typename T>
void f(T a , T b) {
	if(a>b) { ... }
}
```

在上述代码中，如果T的数据类型传入的是想Person这样的自定义数据类型，也无法正常运行



因此C++为了解决这种问题，提供模版的重载，可以为这些**特定的类型**提供**具体化的模板**



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//模版的局限性
//模板不是万能的，有些特定的数据类型，需要用具体化的方式做特殊实现

class Person {
public:
	Person(string name, int age) : name(name), age(age) {}
	//姓名，年龄
	string name;
	int age;
};

//对比两个数据的函数
template<typename T>
bool compare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//利用具体化的方式，给Person类型做一个特殊实现
template<>
bool compare<Person>(Person& p1, Person& p2) { //<Person>可省略，因为编译器可以通过参数类型推导出来这个模板函数特化用于Person类型
	if (p1.name == p2.name && p1.age == p2.age) {
		return true;
	}
	else {
		return false;
	}
}

void test02() {
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	//compare(p1, p2);//error,没有可用的==运算符重载
	if (compare(p1, p2)) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}
}

int main() {
	test02();
	system("pause");
	return 0;
}
```

总结：

- 利用具体化的模板，可以解决自定义类型的通用化
- 学习模板并不是为了写模版，而是能在STL中运用系统提供的模板



### 1.3 类模板

#### 1.3.1 类模板语法

类模板作用：

- 建立一个通用类，类中的成员数据类型可以不具体指定，用一个**虚拟的类型**来代表



**语法：**

```c++
template<typename T>
类
```

**解释：**

template --- 声明创建模板

typename --- 表明起后面的符号是一种数据类型，可以用class代替

T --- 通用的数据类型，名称可以替换，通常为大写字母



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//类模板
template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) : name(name), age(age) {
		cout << "Name: " << name << ", Age: " << age << endl;
	}

	NameType name;
	AgeType age;
};

int main() {
	Person<string, int> person("Alice", 30);

	system("pause");
	return 0;
}
```

总结：类模板和函数模版语法相似，在声明模板template后面加类，此类称为类模板
