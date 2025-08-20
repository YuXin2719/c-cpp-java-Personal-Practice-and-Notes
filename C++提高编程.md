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



#### 1.3.2 类模板和函数模板的区别



类模板和函数模板区别主要有两点：

1. 类模板**没有自动类型推导**的使用方式
2. 类模板在模版参数列表中**可以有默认参数**



**示例：**

```c++
#include<iostream>
using namespace std;

//类模板和函数模板的区别
template <class NameType, class AgeType = int>
class Person {
public:
	NameType name;
	AgeType age;
	Person(NameType n, AgeType a) : name(n), age(a) {}
	void show() {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

//1.类模板没有自动类型推导的使用方式
void test01() {
	//Person p("孙悟空", 1000); //错误的，无法用自动类型推导
	Person<string, int> p("孙悟空", 1000); //正确的，只能用显示指定类型的方式
	p.show();
}
//2.类模板在模板参数列表中可以有默认参数
void test02() {
	Person<string> p1("猪八戒", 500); //只有类模板可以使用默认参数
	p1.show();
}

int main() {
	test01();
	test02();

	system("pause");
	return 0;
}
```

总结：

- 类模板只能用显示指定类型方式
- 类模板中的模版参数列表可以有默认参数



#### 1.3.3 类模板中成员函数创建时机



类模板中成员函数和普通类中成员函数创建时机是有区别的：

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用时才创建



**示例：**

```c++
#include<iostream>
using namespace std;

//类模板中成员函数创建时机
//类模板中成员函数在调用时才创建

class Person1 {
public:
	//成员函数
	void showPerson1() {
		cout << "showPerson1调用" << endl;
	}
};

class Person2 {
public:
	//成员函数
	void showPerson2() {
		cout << "showPerson2调用" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	//成员函数
	void func1() {
		cout << "func1调用" << endl;
		obj.showPerson1();
	}

	void func2() {
		cout << "func2调用" << endl;
		obj.showPerson2();
	}
};

void test01() {
	//创建类模板对象
	MyClass<Person1> myClass1;
	//调用成员函数
	myClass1.func1();

	//创建类模板对象
	MyClass<Person2> myClass2;
	//调用成员函数
	myClass2.func2();
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建



#### 1.3.4 类模板对象做函数参数

学习目标：

- 类模板实例化出的对象，向函数传参的方式



一共三种传入方式：

1. 指定传入的类型 --- 直接显示对象的数据类型
2. 参数模板化 --- 将对象中的参数变为模版进行传递
3. 整个类模版化 --- 将这个对象类型 模版化进行传递



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//类模板对象做函数参数
template<class T1, class T2>
class Person {
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
	void show() {
		cout << "姓名：" << this->name << " 年龄：" << this->age << endl;
	}
};

//1.指定传入的类型
void printPerson(Person<string, int>& p) {
	p.show();
}

void test01() {
	Person<string, int> p("张三", 20);
	printPerson(p);
}

//2.参数模版化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
	p.show();
	cout << "模版化参数：" << typeid(T1).name() << " " << typeid(T2).name() << endl;
}

void test02() {
	Person<string, int> p("张三", 20);
	printPerson2(p);
}

//3.整个类模版化
template<class T>
void printPerson3(T& p) {
	p.show();
	cout << "模版化参数：" << typeid(T).name() << endl;
}
void test03() {
	Person<string, int> p("张三", 20);
	printPerson3(p);
}

int main() {

	test01();
	test02();
	test03();

	system("pause");
	return 0;
}
```

总结：

- 通过类模板创建的对象，可以有三种方式向函数中进行传参
- 使用比较广泛是第一种：**指定传入的类型**



#### 1.3.5 类模板与继承



当类模板碰到继承时，需要注意以下几点：

- 当子类继承的父类是一个类模板时，子类在声明的时候，需要指出父类中T的类型
- 如果不指定，编译器无法给子类分配内存
- 如果想灵活指定出父类中R的类型，子类也需变为类模板



**示例：**

```C++
#include<iostream>
using namespace std;

//类模板与继承
template<class T>
class Base {
public:
	T m;
};

//必须知道父类中T的类型，才能继承给子类
class Son :public Base<int> {};

void test01() {
	Son s;
}

//如果想灵活指定父类中T的类型，子类也需要变成类模板
template<class T1, class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		cout << "T1的类型为:" << typeid(T1).name() << endl;
		cout << "T2的类型为:" << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test02() {
	Son2<int, char> s2;
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
```

总结：如果父类是类模板，子类需要指定出父类中T的数据类型



#### 1.3.6 类模板成员函数类外实现



学习目标：能够掌握类模板中的成员函数类外实现



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//类模板成员函数类外实现
template <class T1, class T2>
class Person {
public:
	Person(T1 name, T2 age);
	void show();
	T1 name;
	T2 age;
};

//构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::show() {
	cout << "name: " << this->name << endl;
	cout << "age: " << this->age << endl;
}

int main() {
	Person<string, int> p("Tom", 20);
	p.show();

	system("pause");
	return 0;
}
```

总结：类模板中成员函数类外实现时，需要加模版参数列表



#### 1.3.7 类模板分文件编写

学习目标：

- 掌握类模板成员函数分文件编写产生的问题以及解决方式



问题：

- 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：

- 解决方式1：直接包含.cpp源文件
- 解决方法2：将声明和实现写在同一个文件内，并更改后缀名为.hpp，hpp是约定的名称，并不是强制



**示例：**

person.hpp中代码：

```c++
#pragma once
#include<iostream>
using namespace std;
#include<string.h>

template<class T1, class T2>
class Person {
public:
	Person(T1 n, T2 a);
	void showPerson();
	T1 name;
	T2 age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 n, T2 a) {
	name = n;
	age = a;
}
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
}
```



类模板分文件编写.cpp中代码

```c++
#include<iostream>
using namespace std;
#include<string.h>

//第一种解决方式，直接包含源文件
//#include"person.cpp"

//第二种解决方式（常用），将.h和.cpp写到一起，将后缀名改为.hpp
#include"person.hpp"

//类模板的分文件编写问题以及解决方式

//template<class T1, class T2>
//class Person {
//public:
//	Person(T1 n, T2 a);
//	void showPerson();
//	T1 name;
//	T2 age;
//};
//
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 n, T2 a) {
//	name = n;
//	age = a;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "name: " << name << endl;
//	cout << "age: " << age << endl;
//}

void test() {
	Person<string, int> p1("Tom", 20);
	p1.showPerson();
}

int main() {

	test();

	system("pause");
	return 0;
}
```

总结：主流的解决方法是第二种，将类模版成员函数写在一起，并将后缀名改为.hpp



#### 1.3.8 类模板与友元



学习目标：

- 掌握类模版配合友元函数的类内和类外实现



全局函数类内实现 - 直接在类内声明友元即可

全局函数类外实现 - 需要提前让编译器知道全局函数的存在（挺复杂）



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//通过全局函数打印Person的信息

//提前让编译器直到Person类的存在
template<class T1, class T2>
class Person;

//类外实现
//需要写在Person类的前面
template<class T1, class T2>
void printPerson2(const Person<T1, T2>& p) {
	cout << "类外实现 --- Name: " << p.name << ", Age: " << p.age << endl;
}

template<class T1, class T2>
class Person {
	//全局函数 类内实现
	//为什么它是全局函数:
	// 成员函数默认有一个 this指针（指向调用它的对象），但这个函数需要显式传入 Person对象（p），说明它不依赖 this。
	// 如果它是成员函数，应该能直接访问 name和 age，而不需要 p.前缀。
	// 重点就是需要传入一个Person对象，说明它不属于某个特定的 Person实例，因此是全局函数。
	//加friend后，Person类的私有成员可以被printPerson访问
	friend void printPerson(const Person<T1, T2>& p) {
		cout << "类内实现 --- Name: " << p.name << ", Age: " << p.age << endl;
	}

	//全局函数 类外实现
	//加空模板参数列表<>，表示这是一个模板函数
	//如果全局函数是类外实现,需要让编译器提前知道这是一个模板函数
	friend void printPerson2<>(const Person<T1, T2>& p);

public:
	Person(T1 n, T2 a) : name(n), age(a) {}
private:
	T1 name;
	T2 age;
};

//1.全局函数在类内实现
void test01() {
	Person<string, int> p("Tom", 20);
	printPerson(p); //调用全局函数
}

//2.全局函数在类外实现
void test02() {
	Person<string, int> p("Jerry", 22);
	printPerson2(p); //调用全局函数
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
```

总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别



#### 1.3.9 类模板案例

案例描述：实现一个通用的数组类，要求如下：



- 可以对内置数据类型以及自定义数据类型的数据进行存储
- 将数组中的数据存储到堆区
- 构造函数中可以传入数组的容量
- 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
- 提供尾插法和尾删法对数组中的元素进行增加和删除
- 可以通过下标的方式访问数组中的元素
- 可以获取数组中当前元素个数和数组的容量



**示例：**

myArray.hpp中代码

```c++
//自己的通用的数组类
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
	//有参构造
	MyArray(int capacity) {
		//cout << "MyArray(int capacity)构造函数调用" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr) {
		//cout << "MyArray(const MyArray& arr)拷贝构造函数调用" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		//深拷贝
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=重载
	MyArray& operator=(const MyArray& arr) {
		//cout << "MyArray& operator=(const MyArray& arr)赋值运算符重载函数调用" << endl;
		if (this != &arr) { //防止自赋值
			if (this->pAddress != NULL) {
				delete[] this->pAddress; //释放原有内存
				this->pAddress = NULL; //避免野指针
				this->capacity = 0; //重置容量
				this->size = 0; //重置大小
			}
			this->capacity = arr.capacity;
			this->size = arr.size;
			//深拷贝
			this->pAddress = new T[arr.capacity];
			for (int i = 0; i < this->size; i++) {
				this->pAddress[i] = arr.pAddress[i];
			}
		}
		return *this;
	}

	//尾插法
	void push_back(const T& value) {
		if (this->size >= this->capacity) {
			cout << "数组已满，无法添加新元素" << endl;
			return;
		}
		this->pAddress[this->size] = value; //将值添加到数组末尾
		this->size++; //更新数组大小
	}

	//尾删法
	void pop_back() {
		if (this->size <= 0) {
			cout << "数组为空，无法删除元素" << endl;
			return;
		}
		//让用户访问不到最后一个元素,逻辑删除
		this->size--; //减少数组大小
	}

	//通过下标访问元素
	T& operator[](int index) {
		if (index < 0 || index >= this->size) {
			cout << "下标越界" << endl;
			exit(-1); //异常处理
		}
		return this->pAddress[index]; //返回对应下标的元素
	}

	//返回数组的大小
	int getSize() const {
		return this->size; //返回数组的大小
	}

	//返回数组的容量
	int getCapacity() const {
		return this->capacity; //返回数组的容量
	}

	//析构函数
	~MyArray() {
		//cout << "~MyArray()析构函数调用" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress; //存放数组的首地址
	int capacity; //数组的容量
	int size; //数组的大小
};
```



类模板案例-数组类封装.cpp中

```c++
#include<iostream>
using namespace std;
#include "MyArray.hpp"

void printArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " "; //利用重载的[]访问元素
	}
	cout << endl;
}

void test01() {
	//创建一个MyArray对象
	MyArray<int> arr(10);

	for (int i = 0; i < 10; i++) {
		//利用push_back方法向数组中添加元素
		arr.push_back(i); //向数组中添加元素
	}
	printArray(arr);
	//打印容量和大小
	cout << "容量为：" << arr.getCapacity() << endl;
	cout << "大小为：" << arr.getSize() << endl;

	//测试尾删法
	MyArray<int> arr2(10);
	for (int i = 0; i < 10; i++) {
		arr2.push_back(i + 10); //向数组中添加元素
	}
	arr2.pop_back(); //删除最后一个元素
	printArray(arr2);
	//打印容量和大小
	cout << "容量为：" << arr2.getCapacity() << endl;
	cout << "大小为：" << arr2.getSize() << endl;

	////使用拷贝构造函数
	//MyArray<int> arr2(arr);
	////使用赋值运算符重载
	//MyArray<int> arr3(100);
	//arr3 = arr2;
}

//测试自定义数据类型
class Person {
public:
	string name;
	int age;
	Person() {};
	Person(string name, int age) : name(name), age(age) {}
};

void printPersonArray(MyArray<Person>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "Name: " << arr[i].name << ", Age: " << arr[i].age << endl; //利用重载的[]访问元素
	}
}

void test02() {
	MyArray<Person> arr(10);
	arr.push_back(Person("Alice", 20));
	arr.push_back(Person("Bob", 25));
	arr.push_back(Person("Charlie", 30));

	printPersonArray(arr);
	//打印容量和大小
	cout << "容量为：" << arr.getCapacity() << endl;
	cout << "大小为：" << arr.getSize() << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

总结：能够利用所学知识点实现通用的数组



## 2 STL初识

### 2.1 STL的诞生



- 长久以来，软件界一直希望建立一种可以重复利用的东西
- C++的**面向对象**和**泛型编程**思想，目的就是**复用性**提升
- 大多数情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
- 为了建立数据结构和算法的一套标准，诞生了**STL**



### 2.2 STL基本概念



- STL（Standard Template Library，**标准模板库**）
- STL从广义上分为：**容器（container）算法（algorithm）迭代器（iterator）**
- **容器**和**算法**之间通过**迭代器**进行无缝连接
- STL几乎所有的代码都采用了模版类或者模板函数



### 2.3 STL六大组件

STL大体分为六大组件，分别是：**容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器**



1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器和算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
6. 空间适配器：负责空间的配置和管理



### 2.4 STL中容器、算法、迭代器



**容器**：置物之所也

STL**容器**就是将运用**最广泛的一些数据结构**实现出来

常用的数据结构：数组、链表、树、栈、队列、集合、映射表 等

这些容器分为**序列式容器**和**关联式容器**两种：

1. **序列式容器**：强调值的排序，序列式容器中的每个元素均有固定的位置
2. **关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系



**算法**：问题之解法也

有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法（Algorithms）

算法分为：**质变算法**和**非质变算法**

1. 质变算法：是指运算过程中会改变区间内的元素的内容，例如拷贝、替换、删除等等
2. 非质变算法：是指运算过程中不会改变区间内的元素内容，例如查找、计数、遍历、寻找极值等等



**迭代器**：容器和算法之间的粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针



迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、！=                   |
| 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！=                   |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++、--                        |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器和随机访问迭代器



### 2.5 容器算法迭代器初识



了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力

STL中最常用的容器为Vector，可以理解为数组、下面我们将学习如何向这个容器中插入数据、并遍历这个容器



#### 2.5.1 vector存放内置数据类型



容器：`vector`

算法：`for_each`

迭代器：`vector<int>::iterator`



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm> //for_each需要包含的头文件


//打印函数
void myPrint(int val) {
	cout << val << " ";
}

//vector容器存放内置数据类型

void test01() {
	vector<int> v; //定义一个int类型的vector容器
	//向容器中添加数据
	v.push_back(10); //在容器末尾添加数据
	v.push_back(20);
	v.push_back(30);
	//通过迭代器访问容器中的数据
	//第一种遍历方式
	vector<int>::iterator it = v.begin(); //起始迭代器，指向容器的第一个元素
	while (it != v.end()) { //end()返回一个迭代器，指向容器的末尾
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//第三种遍历方式
	for (int i = 0; i < v.size(); i++) { //size()返回容器中元素的个数
		cout << v[i] << " "; //通过[]访问容器中的元素
	}
	cout << endl;

	//第四种遍历方式（C++11新特性）
	for (auto e : v) { //e依次表示容器中的每个元素
		cout << e << " ";
	}
	cout << endl;

	//第五种遍历方式，利用STL提供的算法for_each
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() {

	test01(); //调用测试函数

	system("pause");
	return 0;
}
```



#### 2.5.2 Vector存放自定义数据类型



学习目标：vector中存放自定义数据类型，并打印输出



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

//vector存放自定义数据类型
class Person {
public:
	string name;
	int age;
	Person(string n, int a) : name(n), age(a) {}
};

void test01() {
	//定义一个vector存放Person对象
	vector<Person> v;
	//添加元素
	v.push_back(Person("Alice", 30));
	v.push_back(Person("Bob", 25));
	//遍历输出
	for_each(v.begin(), v.end(), [](const Person& p) {
		cout << "Name: " << p.name << ", Age: " << p.age << endl;
		});
}

//存放自定义数据类型的指针
void test02() {
	//定义一个vector存放Person对象的指针
	vector<Person*> v;
	//添加元素
	v.push_back(new Person("Alice", 30));
	v.push_back(new Person("Bob", 25));
	//遍历输出
	for_each(v.begin(), v.end(), [](const Person* p) {
		cout << "Name: " << p->name << ", Age: " << p->age << endl;
		});
	//释放内存
	for (auto p : v) {
		delete p;
	}
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
```



#### 2.5.3 Vector容器嵌套容器



学习目标：容器中嵌套容器，我们将所有数据进行遍历输出



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//容器嵌套容器
void test01() {
	vector<vector<int>> v; //二维数组
	//向二维数组中添加数据
	for (int i = 0; i < 10; i++) {
		vector<int> temp;
		for (int j = 0; j < 10; j++) {
			temp.push_back(i + j);
		}
		v.push_back(temp);
	}
	//遍历二维数组
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main() {
	test01();

	system("pause");
	return 0;
}
```



#### 3.1.1 string基本概念

**本质：**

- string是C++风格的字符串，而string本质上是一个类

**string和char*的区别**

- char*是一个指针
- string是一个类，类内部封装了char\*，管理这个字符串，是一个char\*型的容器

**特点：**

string类内部封装了很多成员方法

例如：查找find，拷贝copy，删除delete，替换replace，插入insert

string管理char*所分配的内存，不用担心复制越界和取值越界，由类内部进行负责



####  3.1.2 string构造函数

构造函数原型：

- `string();` //创建一个空的字符串，例如string str;
  `string(const char* s);` //使用字符串s初始化

- `string(const string& str);` //使用一个string对象初始化另一个string对象

  `string(int n,char c);` //使用n个字符c初始化

**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//string的构造函数
void test01() {
	string str1; // 默认构造
	string str2("hello"); // 字符串常量构造
	string str3(str2); // 拷贝构造
	string str4(10, 'a'); // 重复字符构造
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：string的多种构造方式没有可比性，灵活使用即可



3.1.3 string赋值操作

功能描述：

- 给string字符串进行赋值



赋值的函数原型：

- `string& operator=(const char* s);` //char*类型字符串 赋值给当前字符串
- `string& operator=(const char& s);` //把字符串s赋给当前字符串
- `string& operator=(char c);` //把字符赋值给当前字符串
- `string& assign(const char* s);` //把字符串s赋给当前字符串
- `string& assign(const char* s,int n);` //把字符串s的前n个字符赋给当前字符串
- `string& assign(const char& s);` //把字符串s赋给当前字符串
- `string& assign(int n, char c);` //用n个字符c赋给当前字符串



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//string的赋值操作
//- `string& operator=(const char* s); ` //char*类型字符串 赋值给当前字符串
//- `string& operator=(const char& s); ` //把字符串s赋给当前字符串
//- `string& operator=(char c); ` //把字符赋值给当前字符串
//- `string& assign(const char* s); ` //把字符串s赋给当前字符串
//- `string& assign(const char* s, int n); ` //把字符串s的前n个字符赋给当前字符串
//- `string& assign(const char& s); ` //把字符串s赋给当前字符串
//- `string& assign(int n, char c); ` //用n个字符c赋给当前字符串

void test01() {
	string str1; //默认构造函数
	str1 = "hello"; //char*类型字符串 赋值给当前字符串
	cout << "str1: " << str1 << endl;

	string str2; //默认构造函数
	str2 = str1; //把字符串str1赋给当前字符串
	cout << "str2: " << str2 << endl;

	string str3; //默认构造函数
	str3 = 'a'; //把字符'a'赋值给当前字符串
	cout << "str3: " << str3 << endl;

	string str4; //默认构造函数
	str4.assign("world"); //把字符串"world"赋给当前字符串
	cout << "str4: " << str4 << endl;

	string str5; //默认构造函数
	str5.assign("hello world", 5); //把字符串"hello world"的前5个字符赋给当前字符串
	cout << "str5: " << str5 << endl;

	string str6; //默认构造函数
	str6.assign(str1); //把字符串str1赋给当前字符串
	cout << "str6: " << str6 << endl;

	string str7; //默认构造函数
	str7.assign(5, 'x'); //用5个字符'x'赋给当前字符串
	cout << "str7: " << str7 << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

string的赋值方式很多`operator=`这种方式比较实用



#### 3.1.4 string字符串拼接

**功能描述：**

- 实现在字符串末尾拼接字符串



**函数原型：**

- `string& operator+=(const char* str);` //重载+=操作符
- `string& operator+=(const char c);` //重载+=操作符
- `string& operator+=(const string& str);` //重载+=操作符
- `string& append(const char* s);` //把字符串s连接到当前字符串结尾
- `string& append(const char* s,int n);` /把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const char& s);` 同operator+=(const string& str)
- `string& append(const char& s, int pos, int n);` //把字符串s中从pos开始的n个字符连接到字符串结尾



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串拼接
//- `string& operator+=(const char* str); ` //重载+=操作符
//- `string& operator+=(const char c); ` //重载+=操作符
//- `string& operator+=(const string & str); ` //重载+=操作符
//- `string& append(const char* s); ` //把字符串s连接到当前字符串结尾
//- `string& append(const char* s, int n); ` / 把字符串s的前n个字符连接到当前字符串结尾
//- `string& append(const char& s); ` 同operator += (const string & str)
//- `string& append(const char& s, int pos, int n); ` //把字符串s中从pos开始的n个字符连接到字符串结尾

void test01() {
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << str1 << endl; // 输出: 我爱玩游戏

	str1 += '!';
	cout << str1 << endl; // 输出: 我爱玩游戏!

	string str2 = "hello bro";
	str1 += str2;
	cout << str1 << endl; // 输出: 我爱玩游戏!你

	string str3 = "编程";
	str3.append("很有趣");
	cout << str3 << endl; // 输出: 编程很有趣

	str3.append("game", 2);
	cout << str3 << endl; // 输出: 编程很有趣好玩

	str3.append(str2);
	cout << str3 << endl; // 输出: 编程很有趣好玩你

	str3.append(str2, 6, 3); //参数含义: 从str2的第6个位置开始,取3个字符
	cout << str3 << endl; // 输出: 编程很有趣好玩你好
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：字符串拼接的重载版本很多，初学阶段记住几种即可



#### 3.1.5 string查找和替换

**功能描述：**

- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串

**函数原型：**

- `int find(const string& str, int pos = 0) const;` //查找str第一次出现的位置，从pos开始查找
- `int find(const char* s, int pos = 0) const;` //查找s第一次出现位置，从pos开始查找
- `int find(const char* s, int pos, int n) const;` //从pos位置查找s的前n个字符第一次位置
- `int find(const char c, int pos = 0) const;` //查找字符c第一次出现位置
- `int rfind(const string& str, int pos = npos) const;` //查找str最后一次位置，送pos开始查找
- `int rfind(const char* s, int pos = npos) const;` //查找s最后一次位置，从pos开始查找
- `int rfind(const char* s, int pos, int n) const;` //从pos查找s的前n个字符最后一次位置
- `int rfind(const char c, int pos = 0) const;` //查找字符c最后一次出现的位置
- `string& replace(int pos, int n, const string& str);` //替换从pos开始n个字符为字符串str
- `string& replace(int pos, int n, const char* s);` /替换从pos开始的n个字符为字符串s



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串查找和替换

//1.查找
void test01() {
	string str = "hello world";
	//查找字符串
	int pos = str.find("world");
	if (pos != string::npos) {
		cout << "找到字符串 'world'，位置：" << pos << endl;
	}
	else {
		cout << "未找到字符串 'world'" << endl;
	}

	//rfind 从后向前查找
	pos = str.rfind("hello");
	if (pos != string::npos) {
		cout << "从后向前找到字符串 'hello'，位置：" << pos << endl;
	}
	else {
		cout << "未找到字符串 'hello'" << endl;
	}
}

//2.替换
void test02() {
	string str = "hello world";
	//替换字符串
	str.replace(6, 5, "C++"); //从位置6开始，替换5个字符为"C++"
	cout << "替换后的字符串：" << str << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

总结：

- find查找是从左往后，rfind是从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串



#### 3.1.6 string字符串比较

**功能描述：**

- 字符串之间的比较

**比较方式：**

- 字符串比较是按字符的ASCII码进行对比

= 返回 0

\> 返回 1

< 返回 -1



**函数原型：**

- `int compare(const string& s) const;` //与字符串s比较
- `int compare(const char* s)const;` //与字符串s比较



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串比较

void test01() {
	string str1 = "xello";
	string str2 = "hello";

	if (str1.compare(str2) == 0) {
		cout << "str1和str2相等" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "str1大于str2" << endl;
	}
	else {
		cout << "str1小于str2" << endl;
	}
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大



#### 3.1.7 string字符存取



string中单个字符存取方式有两种



- `char& operator[] (int n);` //通过[]方式取字符
- `char& at(int n);` //通过at方式获取字符



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//字符存取
void test01() {
	string str = "hello world";

	//1.通过[]访问单个字符
	cout << str[0] << endl; //h
	cout << str[1] << endl; //e
	cout << str[2] << endl; //l
	cout << str[3] << endl; //l
	cout << str[4] << endl; //o

	//通过at方式访问单个字符
	cout << str.at(0) << endl; //h
	cout << str.at(1) << endl; //e
	cout << str.at(2) << endl; //l
	cout << str.at(3) << endl; //l
	cout << str.at(4) << endl; //o

	//修改字符串中的字符
	str[0] = 'H';
	cout << str << endl; //Hello world
	str.at(1) = 'E';
	cout << str << endl; //HEllo world
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：string字符串中单个字符存取有两种方式，利用 [] 和 at



#### 3.1.8 string插入和删除

**功能描述：**

- 对string字符串进行插入和删除字符操作

**函数原型：**

- `string& insert(int pos, const char* s);` //插入字符串
- `string& insert(int pos, const string& str);` //插入字符串
- `string& insert(int pos, int n, char c);` //在指定位置插入n个字符c
- `string& insert(int pos, int n = npos);` //删除从pos开始的n个字符



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//字符串 插入和删除
void test01() {
	string str1 = "hello";

	//插入
	str1.insert(1, "xx"); //在索引1的位置插入"xx"
	cout << "str1 = " << str1 << endl;

	//删除
	str1.erase(1, 2); //从索引1的位置开始删除2个字符
	cout << "str1 = " << str1 << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

**总结：**插入和删除的起始下标都是从0开始



#### 3.1.9 string子串

**功能描述：**

- 从字符串中获取想要的子串



**函数原型：**

- `string substr(int pos = 0, int n = npos)const;` //返回由pos开始的n个字符组成的字符串



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//string求子串
void test1() {
	string str = "hello world";
	string subStr = str.substr(0, 5); // 从索引0开始，长度为5
	cout << subStr << endl; // 输出: hello
}

//实用操作
void test2() {
	string email = "zhangsan@sina.com";
	//从邮件地址中获取用户名信息
	int pos = email.find('@'); // 查找'@'的位置
	if (pos != string::npos) { // 如果找到了
		string username = email.substr(0, pos); // 截取从0到'@'的子串
		cout << "Username: " << username << endl; // 输出用户名
	}
	else {
		cout << "No '@' found in the email." << endl;
	}
}

int main() {
	test1();
	test2();
	system("pause");
	return 0;
}
```

**总结：**灵活的运用求子串功能，可以在实际开发中获取有效的信息



### 3.2 vector容器



#### 3.2.1 vector基本概念

**功能：**

- vector数据结构和**数组非常相似**，也成为**单端数组**



**vector与普通数组区别：**

- 不同之处在于数组是静态空间，而vector可以**动态扩展**



**动态扩展：**

- 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

![image-20250820100224949](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250820100224949.png)

- vector容器的迭代器是支持随机访问的迭代器



#### 3.2.2 vector构造函数



**功能描述：**

- 创建vector容器



**函数原型：**

- `vector<T> v;` //采用模板实现类实现，默认构造函数
- `vector(v.begin(),v.end());` //将 v[begin(),end()) 区间中的元素拷贝给本身
- `vector(n, elem);` //构造函数将n个elem拷贝给本身
- `vector(const vector& vec);` //拷贝构造函数



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int>& v) {
	//const_iterator是一个只读迭代器，不能修改元素
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器构造
void test01() {
	//默认构造
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//n个elem的构造
	vector<int> v2(10, 100);
	printVector(v2);

	//区间方式构造
	vector<int> v3(v2.begin(), v2.end());
	printVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	printVector(v4);

}

int main() {

	test01();

	system("pause");
	return 0;
}
```

**总结：**vector的多种构造方式没有可比性，灵活使用即可



#### 3.2.3 vector赋值操作



**功能描述：**

1. 给vector容器进行赋值



**函数原型：**

- `vector& operator=(const vector& vec);` //重载等号操作符
- `assign(beg, end);` //将[beg,end)区间中的数据拷贝赋值给本身
- `assign(n, elem);` //将n个elem拷贝赋值给本身



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int>& v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector赋值
void test1() {
	vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
	}
	printVector(v1);
	cout << endl;

	//赋值 operator=
	vector<int> v2;
	v2 = v1;
	printVector(v2);

	//赋值 assign
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); //end是最后一位的下一位
	printVector(v3);

	//赋值 assign
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

int main() {

	test1();

	system("pause");
	return 0;
}
```

总结：vector赋值方式比较简单，使用operator=，或者assign都可以



#### 3.2.4 vector容器和大小

**功能描述：**

- 对vector容器的容量和大小操作



**函数原型：**

- `empty();` //判断容器是否为空
- `capacity();` //容器的容量
- `size();` //返回容器中元素的个数
- `resize(int num);` //1.重新指定容器的长度为num，若容器变长，则以默认值填充新位置   2.如果容器变短，则末尾超出容器长度的元素被删除
- `resize(int num, elem);` //1.重新指定容器的长度为num，若容器变长，则以elem值填充新位置   2.如果容器变短，则末尾超出容器长度的元素被删除



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器的容量和大小操作
void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//判断容器是否为空
	if (v1.empty()) {
		cout << "v1 is empty" << endl;
	}
	else {
		cout << "v1 is not empty" << endl;
		//获取容量
		cout << "v1 capacity: " << v1.capacity() << endl;
		//获取大小
		cout << "v1 size: " << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15, 100); //如果指定的大小大于原来大小，则以100填充新位置
	printVector(v1);
	cout << "v1 capacity: " << v1.capacity() << endl;
	cout << "v1 size: " << v1.size() << endl;

	v1.resize(5); //如果指定的大小小于原来大小，则多余元素被删除
	printVector(v1);
	cout << "v1 capacity: " << v1.capacity() << endl;
	cout << "v1 size: " << v1.size() << endl;

}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 判断是否为空 --- empty
- 返回元素个数 --- size
- 返回容器容量 --- capacity
- 重新指定大小 --- resize



#### 3.2.5 vector插入和删除

**功能描述：**

- 对vector容器进行插入、删除操作



**函数原型：**

- `push_back(ele);` //尾部插入元素ele
- `pop_back();` //删除最后一个元素
- `insert(const_iterator pos, ele);` //迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count, ele);` //迭代器指向位置pos插入count个元素ele
- `erase(const_iterator pos);` //删除迭代器只想的元素
- `erase(const_iterator start, const_iterator end);` //删除迭代器从start到end之间的元素
- `clear();` //删除容器中所有的元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

//插入和删除元素
/*
- `push_back(ele);` //尾部插入元素ele
- `pop_back();` //删除最后一个元素
- `insert(const_iterator pos, ele);` //迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count, ele);` //迭代器指向位置pos插入count个元素ele
- `erase(const_iterator pos);` //删除迭代器指向的元素
- `erase(const_iterator start, const_iterator end);` //删除迭代器从start到end之间的元素
- `clear();` //删除容器中所有的元素
*/

void printVector(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector<int> v;
	//尾部插入元素
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	printVector(v); // 10 20 30

	//删除最后一个元素
	v.pop_back();
	printVector(v); // 10 20

	//迭代器指向位置pos插入元素ele
	vector<int>::iterator it = v.begin();
	v.insert(it, 100); //在第一个位置插入100
	printVector(v); // 100 10 20

	//迭代器指向位置pos插入count个元素ele
	it = v.begin(); // 重新获取迭代器
	v.insert(it, 2, 200); //在第一个位置插入两个200
	printVector(v); // 200 200 100 10 20

	//删除迭代器指向的元素
	it = v.begin(); // 重新获取迭代器
	v.erase(it);
	printVector(v); // 200 100 10 20

	//删除迭代器从start到end之间的元素
	vector<int>::iterator start = v.begin();
	vector<int>::iterator end = v.end();
	v.erase(start, end);
	printVector(v); // (空行)

	//删除容器中所有的元素
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.clear();
	printVector(v); // (空行)
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

- 尾插 --- push_back
- 尾删 --- pop_back
- 插入 --- insert（位置迭代器）
- 删除 --- erase（位置迭代器）
- 清空 --- clear



#### 3.2.6vector数据存取



**功能描述：**

- 对vector中的数据的存取操作



**函数原型：**

- `at(int idx);` //返回索引idx所指的数据
- `operator[];` //返回索引idx所指的数据
- `front();` //返回容器中第一个数据元素
- `back();` //返回容器中最后一个数据元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

//vector容器 数据存取

void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//通过[]方式访问容器中的数据
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	//通过at方式访问容器中的数据
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	//获取第一个元素
	cout << "第一个元素为：" << v.front() << endl;
	//获取最后一个元素
	cout << "最后一个元素为：" << v.back() << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

- 除了用迭代器获取vector容器中元素，[]和at都可以
- front返回容器第一个元素
- back返回容器最后一个元素



##### 3.2.7 vector互换容器

**功能描述：**

- 实现两个容器内元素进行互换



**函数原型：**

- `swap(vec);` //将vec与本身的元素互换



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

//vector容器互换

void printVector(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//1.基本使用
void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "v1容器内容：";
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i < 20; i++) {
		v2.push_back(i);
	}
	cout << "v2容器内容：";
	printVector(v2);

	//交换容器内容
	v1.swap(v2);
	cout << "交换后：\n";
	printVector(v1);
	printVector(v2);
}

//2.实际用途
//可以巧用swap函数收缩内存空间
void test02() {
	vector<int> v1;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
	}
	cout << "v1容器容量：" << v1.capacity() << endl;
	//清空容器
	v1.clear();
	cout << "清空后v1容器容量：" << v1.capacity() << endl;
	//收缩内存空间
	vector<int>(v1).swap(v1);
	cout << "收缩后v1容器容量：" << v1.capacity() << endl;
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
```

总结：swap可以使两个容器互换，可以达到实用的收缩内存效果



#### 3.2.8 vector预留空间

**功能描述：**

- 减少vector在动态扩展容量时的扩展次数



**函数原型：**

- `reserve(int len);` //容器预留len个元素长度，预留位置不初始化，元素不可访问



**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>

//vector容器 预留空间
void test01() {
	vector<int> v; //默认构造函数

	//利用reserve函数预留空间
	v.reserve(100000); //预留100000个空间

	int num = 0; //统计开辟的次数
	int* p = NULL; //指向vector的首地址
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "开辟次数：" << num << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：如果数据量较大，可以一开始利用reserve预留空间



### 3.3 deque容器

#### 3.3.1 deque容器基本概念



**功能：**

- 双端数组，可以对头端进行插入删除操作



**deque与vector区别：**

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度会比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关

![image-20250820152100384](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250820152100384.png)

deque内部工作原理：

deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

![image-20250820152523768](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250820152523768.png)

- deque容器的迭代器也是支持随机访问的



#### 3.3.2 deque构造函数

**功能描述：**

- deque容器构造



**函数原型：**

- `deque<T> deqT;` //默认构造形式
- `deque(beg, end);` //构造函数将[beg, end]区间中的元素拷贝给自身
- `deque(n, elem);` //构造函数将n个elem拷贝给本身
- `deque(const deque& deq);` //拷贝构造函数



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque容器 构造函数
void test() {
	deque<int> d1; //默认构造 无参构造
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1); //拷贝构造
	printDeque(d2);
	deque<int> d3(d2.begin(), d2.end()); //区间构造
	printDeque(d3);
	deque<int> d4(10, 100); //n个elem
	printDeque(d4);
}

int main() {
	test();
	system("pause");
	return 0;
}
```

**总结：**deque容器和vector容器的构造方式几乎一致，灵活使用即可



#### 3.3.3 deque赋值操作



**功能描述：**

- 给deque容器进行赋值



**函数原型：**

- `deque& operator=(const deque& deq);` //重载等号操作符
- `assign(beg, end);` //将[beg, end)区间这种的数据拷贝赋值给本身
- `assign(n, elem);` //将n个elem拷贝赋值给本身



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>

//vector容器 赋值操作

void print(deque<int>& dq) {
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << " ";
	}
	cout << endl;
}

void test01() {
	deque<int> dq1;
	for (int i = 0; i < 10; i++) {
		dq1.push_back(i);
	}
	print(dq1);
	deque<int> dq2;
	dq2 = dq1; //赋值操作
	print(dq2);
	deque<int> dq3;
	dq3.assign(dq1.begin(), dq1.end()); //区间赋值
	print(dq3);
	deque<int> dq4;
	dq4.assign(10, 100); //重复赋值
	print(dq4);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：deque赋值操作也与vector相同，需熟练掌握



#### 3.3.4 deque大小操作

**功能描述：**

- 对deque容器的大小进行操作



**函数原型：**

- `deque.empty();` //判断容器是否为空
- `deque.size();` //返回容器中元素的个数
- `deque.resize(num);` //1.重新指定容器的长度为num，若容器变长，则以默认值填充新位置    2.如果容器变短，则末尾超出容器长度的元素被删除
- `deque.resize(num, elem);` //1.重新指定容器的长度为num，若容器变长，则以elem填充新位置    2.如果容器变短，则末尾超出容器长度的元素被删除



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>

//deque容器 大小操作

void printDeque(deque<int>& d) {
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;
}

void test01() {
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) {
		cout << "d1 is empty" << endl;
	}
	else {
		cout << "d1 is not empty" << endl;
		cout << "d1 size: " << d1.size() << endl;
	}

	//重新指定大小
	//d1.resize(15);
	d1.resize(15, 100); //指定新大小为15，新增的元素值为100
	printDeque(d1);
	d1.resize(5);
	printDeque(d1);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- deque没有容量的概念
- 判断是否为空 --- empty
- 返回元素个数 --- size
- 重新指定个数 --- resize



#### 3.3.5 deque插入和删除

**功能描述：**

- 向deque容器中插入和删除数据



**函数原型：**

两段插入操作：

- `push_back(elem);` //在容器尾部添加一个数据
- `push_front(elem);` //在容器头部插入一个数据
- `pop_back();` //删除容器最后一个数据
- `pop_front();` //删除容器第一个数据

指定位置操作：

- `insert(pos, elem);` //在pos位置插入一个elem元素的拷贝，返回新数据的位置
- `insert(pos, n, elem);` //在pos位置插入n个elem数据，无返回值
- `insert(pos, beg, elem);` //在pos位置插入[beg, end)区间的数据，无返回值
- `clear();` //清空容器的所有数据
- `erase(beg, end);` //删除[beg, end)区间的数据，返回下一个数据的位置
- `erase(pos);` //删除pos位置的数据，返回下一个数据的位置



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque容器插入和删除
void test01() {
	deque<int> d;
	//尾部插入
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	printDeque(d);
	//头部插入
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);
	//尾部删除
	d.pop_back();
	printDeque(d);
	//头部删除
	d.pop_front();
	printDeque(d);
	//清空容器
	d.clear();
	printDeque(d);
}

void test02() {
	deque<int> d;
	//尾部插入
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	//头部插入
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);
	//insert插入
	d.insert(d.begin(), 1000); //在头部插入1000
	printDeque(d);
	d.insert(d.begin(), 2, 1000); //在头部插入2个1000
	printDeque(d);
	//按照区间插入
	deque<int> d2;
	d2.push_back(10000);
	d2.push_back(20000);
	d2.push_back(30000);
	d.insert(d.begin(), d2.begin(), d2.end()); //在头部插入d2的所有元素
	printDeque(d);
}

void test03() {
	deque<int> d;
	//尾部插入
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	//头部插入
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);
	//erase删除
	d.erase(d.begin()); //删除头部元素
	printDeque(d);
	d.erase(d.begin(), d.end() - 1); //删除除最后一个元素外的所有元素
	printDeque(d);
	//清空容器
	d.clear();
	printDeque(d);
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
```

 总结：

- 插入和删除提供的位置是迭代器！
- 尾插 --- push_back
- 尾删 --- pop_back
- 头插 --- push_front
- 头删 --- pop_front



#### 3.3.6 deque数据存取



**功能描述：**

- 对deque中的数据存取操作



**函数原型：**

- `at(int idx);` //返回索引idx所指的数据
- `operator[];` //返回索引idx所指的数据
- `front();` //返回容器中第一个数据元素
- `back();` //返回容器中最后一个数据元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>

//deque容器数据存取
void test01() {
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	//遍历容器
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//使用下标访问元素
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout << endl;
	//使用at()访问元素
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << " ";
	}
	cout << endl;
	//使用front()和back()访问首尾元素
	cout << "首元素: " << d1.front() << endl;
	cout << "尾元素: " << d1.back() << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

- 除了用迭代器获取deque容器中元素，[]和at也可以
- front返回容器第一个元素
- back返回容器最后一个元素



#### 3.3.7 deque排序

**功能描述：**

- 利用算法实现对deque容器进行排序



**算法：**

- `sort(iterator beg, iterator end)` //对beg和end区间内元素进行排序



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm> //包含sort函数的头文件

//deque容器排序
void test01() {
	deque<int> d;
	d.push_back(10);
	d.push_back(40);
	d.push_back(50);
	d.push_back(20);
	d.push_back(30);
	//使用sort函数对deque容器进行排序,默认是从小到大排序
	//对于支持随机访问的迭代器的容器都可以使用sort算法
	//vector、deque、array都可以使用sort算法
	sort(d.begin(), d.end());
	//输出排序后的结果
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：sort算法非常实用，使用时包含头文件algorithm即可



### 3.4 案例-评委打分



#### 3.4.1 案例描述

有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中的最低分，取平均分



#### 3.4.2 实现步骤

1. 创造五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评委打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分



**示例：**

```c++
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中的最低分，取平均分

//选手类
class Person {
public:
	string name;
	int scores;
	Person(string name, int scores) {
		this->name = name;
		this->scores = scores;
	}
};

void createPersons(vector<Person>& persons) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		Person p(name, 0);
		persons.push_back(p);
	}
}

void setScores(vector<Person>& persons) {
	//模拟10个评委打分
	for (int i = 0; i < persons.size(); i++) {
		deque<int> scores;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60; //60-100分
			scores.push_back(score);
		}
		//输出每名选手的分数
		cout << persons[i].name << "的分数为：";
		for (int k = 0; k < scores.size(); k++) {
			cout << scores[k] << " ";
		}
		cout << endl;
		//去除最高分
		sort(scores.begin(), scores.end());
		scores.pop_back();
		//去除最低分
		scores.pop_front();
		//计算平均分
		int sum = 0;
		for (int k = 0; k < scores.size(); k++) {
			sum += scores[k];
		}
		persons[i].scores = sum / scores.size();
	}
}

//显示每名选手的平均分
void showScores(const vector<Person>& persons) {
	cout << "选手平均分：" << endl;
	for (vector<Person>::const_iterator it = persons.begin(); it != persons.end(); it++) {
		cout << it->name << "的平均分为：" << it->scores << endl;
	}
}

int main() {

	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建5名选手
	vector<Person> persons;
	createPersons(persons);
	//测试
	//for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++) {
	//	cout << "name:" << it->name << " scores:" << it->scores << endl;
	//}

	//2.给每名选手打分
	setScores(persons);

	//3.显示每名选手的平均分
	showScores(persons);

	system("pause");
	return 0;
}
```



### 3.5 stack容器

#### 3.5.1 stack基本概念



**概念：**stack是一种**先进后出**（First In Last Out，FILO）的数据结构，他只有一个出口

![image-20250820190749482](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250820190749482.png)

栈中只有顶端的元素才可以被外界使用，因此**栈不允许有遍历行为**

栈中进入数据称为 --- **入栈**`push`

栈中弹出数据称为 --- **出栈**`pop`



生活中的栈：

![image-20250820192725408](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250820192725408.png)



#### 3.5.2 stack常用接口

功能描述：栈容器常用的对外接口



构造函数：

- `stack<T> stk;` //stack采用模版类实现，stack对象的默认构造形式
- `stack(const stack& stk);` //重载等号操作符

赋值操作：

- `stack& operator=(const stack& stk);` //重载等号操作符

数据存取：

- `push(elem);` //向栈顶添加元素
- `pop();` //从栈顶移除第一个元素
- `top();` //返回栈顶元素

大小操作：

- `empty();` //判断对战是否为空
- `size();` //返回栈的大小



**示例：**

```c++

```

