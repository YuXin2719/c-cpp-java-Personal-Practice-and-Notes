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



## 3 STL-常用容器

### 3.1 string容器

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

像不透明的桶

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
#include<iostream>
using namespace std;
#include<stack> // 引入栈容器头文件

//栈stack容器
void test01() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "栈顶元素: " << s.top() << endl; // 输出栈顶元素
	s.pop(); // 弹出栈顶元素
	cout << "弹出栈顶元素后，新的栈顶元素: " << s.top() << endl; // 输出新的栈顶元素
	cout << "栈的大小: " << s.size() << endl; // 输出栈的大小
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 入栈 --- push
- 出栈 --- pop
- 返回栈顶 --- top
- 判断栈是否为空 --- empty
- 返回栈大小 --- size



### 3.6 queue容器

#### 3.6.1 queue基本概念



**概念：**Queue是一种先进先出（First In First Out，FIFO）的数据结构，他有两个出口

像不透明的管道

![image-20250821091120110](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250821091120110.png)

队列容器允许从一端新增元素，从另一端移除元素

队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为

队列中进数据称为 --- **入队**`push`

队列中出数据称为 --- **出队**`pop`



生活中的队列：

![image-20250821092111400](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250821092111400.png)



#### 3.6.2 queue常用借口



功能描述：栈容器常用的对外接口



构造函数：

- `queue<T> que;` //queue采用模版类实现，queue对象的默认构造形式
- `queue(const queue& que);` //拷贝构造函数

赋值操作：

- `queue& operator=(const queue& que);` //重载等号操作符

数据存取：

- `push(elem);` //往队尾添加元素
- `pop();` //从队头移除第一个元素
- `back();` //返回最后一个元素
- `front();` //返回第一个元素

大小操作：

- `empty();` //判断堆栈是否为空
- `size();` //返回栈的大小

**示例：**

```c++
#include<iostream>
using namespace std;
#include<queue>
#include<string>

//队列 queue
class Person {
public:
	Person(string n, int a) : name(n), age(a) {}
	string name;
	int age;
};

void test01() {
	//创建队列
	queue<Person> q;
	//添加数据
	q.push(Person("张三", 20));
	q.push(Person("李四", 22));
	q.push(Person("王五", 25));
	//判断只要队列不为空,查看队头,查看队尾,出队
	while (!q.empty()) {
		//查看队头
		cout << "队头姓名: " << q.front().name << " 年龄: " << q.front().age << endl;
		//查看队尾
		cout << "队尾姓名: " << q.back().name << " 年龄: " << q.back().age << endl;
		//出队
		q.pop();
		cout << "出队后队列大小为: " << q.size() << endl;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 入队 --- push
- 出队 --- pop
- 返回队头元素 --- front
- 返回队尾元素 --- back
- 判断队是否为空 --- empty
- 返回队列大小 --- size



### 3.7 list容器

#### 3.7.1 list基本概念



**功能：**将数据进行链式存储

**链表**（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的



链表的组成：链表由一系列**结点**组成



结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**



**数组和链表的优缺点：**

1. 数组优点：可以对任意位置进行快速插入或删除元素
2. 链表缺点：容器遍历速度，没有数组快，占用空间比数组大



STL中的链表是一个双向循环链表（STL是循环的，图中不准确，不是循环的）

![image-20250821150445654](https://gitee.com/YuXinHome/blogimg/raw/master/img/image-20250821150445654.png)

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于**双向迭代器**



list的优点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：

- 链表灵活，但是空间（指针域）和时间（遍历）额外耗费比较大

List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的



总结：STL中**List和vector是两个最常被使用的容器**，各有优缺点



#### 3.7.2 list构造函数

**功能描述：**

- 创建list容器



**函数原型：**

- `list<T> lst;` //list采用模版类实现，对象的默认构造方式
- `list(beg, ned);` //构造函数将[beg,end)区间中的元素拷贝给本身
- `list(n, elem);` //构造函数将n个elem拷贝给本身
- `list(const list& lst);` //拷贝构造函数



**示例：**

```c++
#include<iostream>
using namespace std;
#include<list> //list容器头文件

void showList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//list容器_构造函数
void test01() {
	//默认构造
	list<int> l1;
	showList(l1);
	//区间方式构造
	int arr[] = { 1,2,3,4,5 };
	list<int> l2(arr, arr + sizeof(arr) / sizeof(int));
	showList(l2);
	list<int> l5(l1.begin(), l1.end()); //使用l1的迭代器区间构造
	showList(l5);
	//拷贝构造
	list<int> l3(l2);
	showList(l3);
	//n个elem方式构造
	list<int> l4(10, 100); //10个100
	showList(l4);
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：list构造方式同其他几个STL常用容器，熟练掌握即可



#### 3.7.3 list赋值和交换

**功能描述：**

- 给list容器进行赋值，以及交换list容器

**函数原型：**

- `assign(beg, end);` //将[beg,end)区间中的数据拷贝赋值给本身
- `assign(n, elem);` //将n个elem拷贝赋值给本身
- `list& operator=(const list& lst);` //重载等号操作符
- `swap(lst);` //将lst与本身的元素互换

**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器赋值和交换

void show(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	//list容器赋值和交换
	//创建一个list容器
	list<int> l1;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	show(l1);

	//赋值操作
	list<int> l2;
	l2.assign(l1.begin(), l1.end());
	show(l2);

	//等号赋值操作
	list<int> l4;
	l4 = l1; //等号赋值
	show(l4);

	//赋值操作
	list<int> l3;
	l3.assign(5, 100);
	show(l1);
	show(l3);

	//交换操作
	l1.swap(l3);
	show(l1);
	show(l3);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：list赋值和交换操作能够灵活运用即可



#### 3.7.4 list大小操作

**功能描述：**

- 对list容器的大小进行操作



**函数原型：**

- `size();` //返回容器中元素个数
- `empty();` //判断容器是否为空
- `resize(num);` //1.重新指定容器的长度为num，若容器变长，则以默认值填充新位置   2.如果容器变短，则末尾超出容器长度的元素被删除
- `resize(num, elem);` //1.重新指定容器的长度为num，若容器变长，则以elem填充新位置   2.如果容器变短，则末尾超出容器长度的元素被删除

**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器大小操作

void printList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	list<int>l;
	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	printList(l);
	//1.判断容器是否为空
	if (l.empty()) {
		cout << "容器为空" << endl;
	}
	else {
		cout << "容器不为空" << endl;
	}
	//2.返回容器大小
	cout << "容器大小为：" << l.size() << endl;
	//3.重新指定容器大小
	l.resize(10); //默认填充0
	printList(l);
	l.resize(15, 100); //指定填充数字100
	printList(l);
	l.resize(5);
	printList(l);
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
- 重新指定个数 --- resize



#### 3.7.5 list插入和删除

**功能描述：**

- 对list容器进行数据的插入和删除



**函数原型：**

- `push_back(elem);`//在容器尾部加入一个元素
- `pop_back();`//删除容器中最后一个元素
- `push_front(elem);`//在容器开头插入一个元素
- `pop_front();`//从容器开头移除第一个元素
- `insert(pos,elem);`//在pos位置插elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);`//在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);`//在pos位置插入[beg,end]区间的数据，无返回值。
- `clear();`//移除容器的所有数据
- `erase(beg,end);`//删除[beg,end]区间的数据，返回下一个数据的位置。
- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置。
- `remove(elem);`//删除容器中所有与elem值匹配的元素。



**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器插入和删除

/*
- `push_back(elem);`//在容器尾部加入一个元素
- `pop_back();`//删除容器中最后一个元素
- `push_front(elem);`//在容器开头插入一个元素
- `pop_front();`//从容器开头移除第一个元素
- `insert(pos,elem);`//在pos位置插elem元素的拷贝，返回新数据的位置。
- `insert(pos,n,elem);`//在pos位置插入n个elem数据，无返回值。
- `insert(pos,beg,end);`//在pos位置插入[beg,end]区间的数据，无返回值。
- `clear();`//移除容器的所有数据
- `erase(beg,end);`//删除[beg,end]区间的数据，返回下一个数据的位置。
- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置。
- `remove(elem);`//删除容器中所有与elem值匹配的元素。
*/

void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	list<int> l;
	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	//头插
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	printList(l); //300 200 100 10 20 30
	//尾删
	l.pop_back();
	printList(l); //300 200 100 10 20
	//头删
	l.pop_front();
	printList(l); //200 100 10 20
	//插入
	l.insert(l.begin(), 1000);
	printList(l); //1000 200 100 10 20
	l.insert(l.begin(), 2, 888);
	printList(l); //888 888 1000 200 100 10 20
	//删除
	l.erase(l.begin());
	printList(l); //888 1000 200 100 10 20
	//移除
	l.remove(888);
	printList(l); //1000 200 100 10 20
	//清空
	l.clear();
	printList(l); //空
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
- 头插 --- push_front
- 头删 --- pop_front
- 插入 --- insert
- 删除 --- erase
- 移除 --- remove
- 清空 --- clear



#### 3.7.6 list数据存取

**功能描述：**

- 对list容器中数据进行存取



**函数原型：**

- `front();` //返回第一个元素
- `back();` //返回最后一个元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器数据存取
void test01() {
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	//l1[0] = 100; //不支持下标访问
	//l1.at(0) = 100; //不支持at访问
	//原因是list底层是双向链表结构，不支持随机访问，只能顺序访问。
	cout << "第一个元素为：" << l1.front() << endl; //访问第一个元素
	cout << "最后一个元素为：" << l1.back() << endl; //访问最后一个元素

	//验证迭代器是否支持随机访问
	list<int>::iterator it = l1.begin();
	it++; //迭代器前进一个位置
	it--; //迭代器后退一个位置
	//it += 2; //不支持随机访问,因为这样属于跳跃的访问,不允许
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- list容器中不可以通过[]或者at方式访问数据
- 返回第一个元素 --- front
- 返回最后一个元素 --- back



#### 3.7.7 list反转和排序

**功能描述：**

- 将容器中的元素反转，以及将容器中的数据进行排序



**函数原型：**

- `reverse();` //反转链表
- `sort();` //链表排序



**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器反转和排序

void showList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1, int v2) {
	return v1 > v2; //返回true,交换元素
}

void test01() {
	list<int> l;
	l.push_back(1);
	l.push_back(3);
	l.push_back(2);
	l.push_back(4);
	l.push_back(5);
	showList(l);
	//反转操作
	l.reverse();
	showList(l);
	//所有不支持随机访问迭代器的容器,不可以用标准算法 #include<algorithm>
	//不支持随机访问迭代器容器,内部会提供对应的一些算法
	//排序操作
	l.sort(); //默认排序规则,从小到大升序
	showList(l);
	//降序排序
	l.sort(myCompare);
	showList(l);
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

- 反转 --- reverse
- 排序 --- sort（成员函数）



#### 3.7.8 排序案例

案例描述：将Person自定义数据类型进行排序，Person中属性有姓名，年龄，身高

排序规则：按照年龄进行排序，如果年龄相同按照身高进行降序



**示例：**

```c++
#include<iostream>
using namespace std;
#include<list>

//list容器排序案例,对自定义数据类型排序
//按照年龄从小到大排序,年龄相同按照身高从大到小排序
class Person {
public:
	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

void showList(const list<Person>& l) {
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名:" << it->m_Name << " 年龄:" << it->m_Age << " 身高:" << it->m_Height << endl;
	}
	cout << endl;
}

bool myCompare(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}

//排序规则,年龄从小到大
void test01() {
	list<Person> l;
	Person p1("刘备", 22, 175);
	Person p2("关羽", 22, 180);
	Person p3("张飞", 22, 180);
	Person p4("赵云", 21, 190);
	Person p5("曹操", 24, 170);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	cout << "排序前" << endl;
	showList(l);

	//排序
	cout << "排序后" << endl;
	l.sort(myCompare); //自定义排序规则
	showList(l);
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

1. 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
2. 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂



### 3.8 set/multiset容器

#### 3.8.1 set基本概念

**简介：**

- 所有元素都会在插入时自动被排序



**本质：**

- set/multiset属于**关联式容器**，底层结构是用**二叉树**实现，通常是红黑树（自动排序，自平衡，set-唯一性）



**set和multiset区别：**

- set不允许容器里有重复元素
- multiset允许容器里有重复元素



#### 3.8.2 set构造和赋值

功能描述：创建set容器以及赋值



构造：

- `set<T> st;`  //默认构造函数
- `set(const set& st;)` //拷贝构造函数

赋值：

- `set& operator=(const set& st);` //重载等号运算符

**示例：**

```c++
#include<iostream>
using namespace std;
#include<set>

//set容器构造和赋值
void showSet(const set<int>& s) {
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	set<int> s1; //默认构造函数

	//插入数据,只有insert的方式
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(40);
	//遍历容器
	//set容器特点：自动排序，且不允许重复元素
	showSet(s1);

	set<int> s2(s1); //拷贝构造函数
	showSet(s2);
	set<int> s3 = s1; //拷贝构造函数
	showSet(s3);
	set<int> s4(s1.begin(), s1.end()); //迭代器范围构造函数
	showSet(s4);
	set<int> s5{ 10,20,30 }; //列表初始化
	showSet(s5);
	//赋值操作
	s1 = s2; //赋值运算符
	showSet(s1);
	s1 = { 100,200,300 }; //列表赋值
	showSet(s1);
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

- set容器插入数据时用insert
- set容器插入数据时的数据会自动排序



#### 3.8.3 set大小和交换

**功能描述：**

- 统计set容器大小以及交换set容器



**函数原型：**

- `size();` //返回容器中元素的数目
- `empty();` //判断容器是否为空
- `swap(st);` //交换两个集合容器

**示例：**

```c++
#include<iostream>
using namespace std;
#include<set>

//set容器_大小和交换
void test01() {
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	//是否为空
	cout << "s1 empty:" << s1.empty() << endl;
	cout << "s2 empty:" << s2.empty() << endl;
	//大小
	cout << "s1 size:" << s1.size() << endl;
	cout << "s2 size:" << s2.size() << endl;
	//交换
	s1.swap(s2);
	cout << "s1 size:" << s1.size() << endl;
	cout << "s2 size:" << s2.size() << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

- 统计大小 --- size
- 判断是否为空 --- empty
- 交换容器 --- swap



#### 3.8.4 set插入和函数

**功能描述：**

- set容器进行插入数据和删除数据



**函数原型：**

- `insert(elem);` //在容器中插入元素
- `clear();` //清除所有元素
- `erase(pos); `//删除pos迭代器所指的元素，返回下一个元素的迭代器
- `erase(beg, end);` //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
- `erase(elem);` //删除容器中值为elem的元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<set>

// Set容器的插入和删除操作

void test01() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	//删除操作
	s1.erase(20); //删除指定元素
	s1.erase(s1.begin()); //删除第一个元素
	//遍历容器
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//清空容器
	s1.clear();
	if (s1.empty()) {
		cout << "s1 is empty!" << endl;
	} else {
		cout << "s1 is not empty!" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 插入 --- insert
- 删除 --- erase
- 清空 --- clear



#### 3.8.5 set查找和统计

**功能描述：**

- 对set容器进行查找数据已经统计数据

**函数原型：**

- `find(key);` //查找key是否存在，如果存在，返回该键元素的迭代器，如果不存在，返回set.end();
- `count(key);` //统计key的元素个数



**示例：**

```c++
#include<iostream>
using namespace std;
#include<set>

//set容器 查找和统计
void test01() {
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end()) {
		cout << "找到元素:" << *pos << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}
	int num = s1.count(30);
	//对于set来说，统计的结果要么是0，要么是1
	cout << "30的个数为:" << num << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 查找 --- find（返回的是迭代器，有就是元素位置，没有就是结尾位置）
- 统计 --- count（对于set，结果就是0或者1）



#### 3.8.6 set和multisetset区别

**学习目标：**

- 掌握set和multiset的区别



**区别：**

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据



**示例：**

```c++
#include<iostream>
using namespace std;
#include<set>

//set和multiset的区别

//模板函数
template<typename T>
void show(const T& s) {
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	set<int> s1;
	s1.insert(10);
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second) {
		cout << "插入成功:" << *ret.first << endl;
	}
	else {
		cout << "插入失败:" << *ret.first << endl;
	}
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	cout << "set容器中的元素为:";
	show(s1);

	multiset<int> s2;
	//multiset允许插入重复元素
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	s2.insert(30);
	cout << "multiset容器中的元素为:";
	show(s2);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 如果不允许插入重复数据可以利用set
- 如果需要插入重复数据利用multiset



#### 3.8.7 pair对组创建

**功能描述：**

- 成对出现的数据，利用对组可以返回两个数据



**两种创建方式：**

- `pair<type, type> p (value1, value2);`
- `pair<type, type> p = make_pair(value1, value2);`



**示例：**

```c++
#include<iostream>
using namespace std;

//pair对组的创建
void test01() {
	//创建一个pair对组
	pair<int, int> p1(10, 20);
	cout << "p1的第一个元素为：" << p1.first << endl;
	cout << "p1的第二个元素为：" << p1.second << endl;
	//使用make_pair函数创建pair对组
	pair<int, int> p2 = make_pair(30, 40);
	cout << "p2的第一个元素为：" << p2.first << endl;
	cout << "p2的第二个元素为：" << p2.second << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

两种方式都可以创建对组，记住一种即可



#### 3.8.8 set容器排序

学习目标：

- set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则



**示例一：**set存放内置数据类型

```c++
#include<iostream>
using namespace std;
#include<set>

//set容器 排序

class myCompare {
public:
	bool operator()(int v1, int v2) const { //重载()运算符
		return v1 > v2;
	}
};

void test01() {
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	//set容器默认是升序排列
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//降序排列
	//set<int, greater<int>> s2; //greater是一个函数对象 仿函数,系统提供的,可以直接使用
	//或者自己定义一个仿函数
	set<int, myCompare> s2; //放数据类型,仿函数本质上是一个数据类型
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
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

总结：利用仿函数可以指定set容器的排序规则



**示例二：**set存放自定义数据类型

```c++
#include<iostream>
using namespace std;
#include<set>
#include<string>

//set容器排序,存放自定义数据类型

class Person {
public:
	Person(int a, string n) : age(a), name(n) {}
	//默认构造函数
	Person() : age(0), name("Unknown") {}
	int age;
	string name;
	//重载<运算符,用于set容器排序
	bool operator<(const Person& p) const {
		return this->age < p.age; //按年龄升序排列
	}
	//重载<<运算符,用于输出
	friend ostream& operator<<(ostream& os, const Person& p) {
		os << "Name: " << p.name << ", Age: " << p.age;
		return os;
	}
};

//打印set容器中的Person对象
void printSet(const set<Person>& s) {
	for (const auto& person : s) { //使用范围for循环遍历set,auto关键字自动推导类型
		cout << person << endl;
	}
}

void test01() {
	set<Person> s;
	Person p1{ 25, "Alice" };
	Person p2{ 30, "Bob" };
	Person p3{ 20, "Charlie" };
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	cout << "Set contents (sorted by age):" << endl;
	printSet(s);
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

对于自定义数据类型，set必须指定排序规则才能插入数据



### 3.9 map/multimap容器

#### 3.9.1 map基本概念

**简介：**

- map中所有的元素都是pair
- pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
- 所有元素都会根据元素的键值自动排序

**本质：**

- map/multimap属于**关联式容器**，底层结构是用二叉树实现

**优点：**

- 可以根据key值快速找到value值

map和multimap**区别**：

- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素



#### 3.9.2 map构造和赋值

**功能描述：**

- 对map容器进行构造和赋值操作

**函数原型：**

**构造：**

- `map<T1,T2> mp;` //map默认构造函数
- `map(const map& mp);` //拷贝构造函数

**赋值：**

- `map& operator=(const map& mp);` //重载等号运算符

**示例：**

```c++
#include<iostream>
using namespace std;
#include<map>

//map容器的构造和赋值

void printMap(const map<int, int>& m) {
	//这里的auto是C++11引入的类型推断关键字，表示自动推断变量类型
	//auto在这里会被推断为map<int, int>::const_iterator
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

void test01() {
	//1.默认构造,两个参数分别表示键值类型和值类型，会按照键值进行排序
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));
	printMap(m1);
	//2.指定范围构造
	map<int, int> m2(m1.begin(), m1.end());
	printMap(m2);
	//3.复制构造
	map<int, int> m3(m2); //和 m3 = m2; 等价
	printMap(m3);
	//4.指定比较函数构造,less<int>是一个函数对象，表示使用小于号进行比较
	map<int, int, less<int>> m4;
	//5.指定比较函数和分配器构造,allocator是一个分配器，这里表示使用默认的内存分配器
	map<int, int, less<int>, allocator<pair<const int, int>>> m5;
}

int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：map中所有元素都是成对出现，插入数据时要使用对组



#### 3.9.3 map大小和交换

**功能描述：**

- 统计map容器大小以及交换map容器



**函数原型：**

- `size();` //返回容器中元素的数目
- `empty();` //判断容器是否为空
- `swap(st); `//交换两个集合容器



**示例：**

```c++
#include<iostream>
using namespace std;
#include<map>

//map容器_大小和交换
void test01() {
	map<int, int>m1;
	//插入数据
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));
	//通过size()函数获取容器中元素的个数
	cout << "m1 size = " << m1.size() << endl;
	//通过empty()函数判断容器是否为空
	if (m1.empty()) {
		cout << "m1为空" << endl;
	}
	else {
		cout << "m1不为空" << endl;
	}
	//交换两个容器
	map<int, int>m2;
	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 200));
	cout << "交换前：" << endl;
	cout << "m1 size = " << m1.size() << endl;
	cout << "m2 size = " << m2.size() << endl;
	m1.swap(m2);//交换
	cout << "交换后：" << endl;
	cout << "m1 size = " << m1.size() << endl;
	cout << "m2 size = " << m2.size() << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

- 统计大小 --- size
- 判断是否为空 --- empty
- 交换容器 --- swap



#### 3.9.4 map插入和删除

**功能描述：**

- map容器进行插入和删除数据



**函数原型：**

- `insert(elem);` //在容器中插入元素
- `clear(); `//清除所有元素
- `erase(pos); `//删除pos迭代器所指的元素，返回下一个元素的迭代器
- `erase(beg, end);` //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
- `erase(key);` //删除容器中值为key的元素



**示例：**

```c++
#include<iostream>
using namespace std;
#include<map>

//map容器的插入和删除

void showMap(map<int, int>m) {
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

void test01() {
	map<int, int>m1;
	//插入数据
	//方式1
	m1.insert(pair<int, int>(1, 10));
	//方式2,推荐,自动类型推导
	m1.insert(make_pair(2, 20));
	//方式3,不推荐,效率低
	m1.insert(map<int, int>::value_type(3, 30));
	//方式4,利用下标插入,不建议
	// 因为如果key存在,会覆盖原来的value,而且如果key不存在,会创建一个新的key,value默认值为0
	// 用途,可以利用key访问到value
	m1[4] = 40;
	//遍历map
	showMap(m1);

	//删除元素
	m1.erase(m1.begin());
	m1.erase(2); //根据key删除
	cout << "删除元素后：" << endl;
	showMap(m1);
	m1.erase(m1.begin(), m1.end()); //删除区间
	cout << "区间删除元素后：" << endl;
	showMap(m1);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- map插入方式很多，记住其一即可
- 插入 --- insert
- 删除 --- erase
- 清空 --- clear



#### 3.9.5 map查找和统计

**功能描述：**

- 对map容器进行查找数据以及统计数据

**函数原型：**

- `find(key);` //查找key是否存在，如果存在，返回该键的元素的迭代器，如果不存在，返回map.end();
- `count(key);` //统计key的元素个数

**示例：**

```c++
#include<iostream>
using namespace std;
#include<map>

//map容器_查找和统计
void test01() {
	map<int, int>m;
	//插入数据
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	m[5] = 50;
	//查找元素find(key)
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "找到元素 key = " << pos->first << " value = " << pos->second << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}
	//统计元素count(key)
	//map不允许有重复key,所以统计结果要么是0要么是1
	int num = m.count(3);
	cout << "num = " << num << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}
```

总结：

- 查找 --- find（返回的是迭代器）
- 统计 --- count（对于map，结果为0或者1）



#### 3.9.6 map容器排序

**学习目标：**

- map容器默认排序规则为 按照key值进行 从小到大的排序，掌握如何改变排序规则



**主要技术点：**

- 利用仿函数，可以改变排序规则



**示例：**

```c++
#include<iostream>
using namespace std;
#include<map>

//map容器_排序

//模板类
template<class T>
void showMap(T m) {
	for (typename T::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

class myCompare {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void test01() {
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	//map容器会自动排序
	showMap(m);
	cout << "------------------" << endl;
	map<int, int, myCompare>m2;
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(4, 40));
	showMap(m2);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

- 利用仿函数可以指定map容器的排序规则
- 对于自定义数据类型，map必须要指定排序规则，同set容器



### 3.10 案例-员工分组

#### 3.10.1 案例描述

- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
- 员工信息有：姓名，工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和公司
- 通过multimap进行信息的插入 key（部门编号）value（员工）
- 分部门显示员工信息



#### 3.10.2 实现步骤

1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
4. 分部门显示员工信息



**案例代码：**

```c++
#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>

//map案例_员工分组
/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
- 员工信息有：姓名，工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和公司
- 通过multimap进行信息的插入 key（部门编号）value（员工）
- 分部门显示员工信息
*/

//1.定义员工类
class Worker {
public:
	string m_Name;
	int m_Salary; //工资
	Worker(string name, int salary) {
		this->m_Name = name;
		this->m_Salary = salary;
	}
};

void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "员工";
		name += nameSeed[i];
		int salary = rand() % 10000 + 10000; //10000-19999
		Worker w(name, salary);
		v.push_back(w);
	}
}

void insertWorkerToMap(multimap<int, Worker>& m, vector<Worker>& v) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//随机分配部门
		int deptId = rand() % 3; //0 1 2
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByDeptId(multimap<int, Worker>& m, int deptId) {
	//0策划 1美术 2研发
	string deptName;
	if (deptId == 0) {
		deptName = "策划";
	}
	else if (deptId == 1) {
		deptName = "美术";
	}
	else if (deptId == 2) {
		deptName = "研发";
	}
	else
	{
		cout << "部门不存在" << endl;
		return;
	}
	cout << deptName << "部门员工信息：" << endl;
	multimap<int, Worker>::iterator it = m.find(deptId);
	int count = m.count(deptId); //统计某个部门的人数
	for (int i = 0; i < count; i++) {
		cout << "姓名：" << it->second.m_Name << " 工资：" << it->second.m_Salary << endl;
		it++;
	}
	cout << endl;
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	//2.创建10名员工,放到vector中
	vector<Worker>v;
	createWorker(v);

	//3.创建multimap容器，员工信息插入到容器中
	multimap<int, Worker>m; //key部门编号  value员工
	insertWorkerToMap(m, v);

	//4.分部门显示员工信息
	for (int i = 0; i < 3; i++) {
		showWorkerByDeptId(m, i);
	}

	system("pause");
	return 0;
}
```



## 4 STL-函数对象

### 4.1 函数对象

#### 4.1.1 函数对象概念

**概念：**

- 重载**函数调用操作符**的类，其对象常称为**函数对象**
- **函数对象**使用重载的()时，行为类似函数调用，也称为**仿函数**

**本质：**

函数对象（仿函数）是一个**类**，不是一个函数



#### 4.1.2 函数对象使用

**特点：**

- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递



**示例：**

```c++
#include<iostream>
using namespace std;
#include<string>

//函数对象（仿函数）
/*
- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递
*/

//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//普通函数
int add(int a, int b) {
	return a + b;
}
//函数对象
class Add {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void test01() {
	cout << add(10, 20) << endl;

	Add add2;
	cout << add2(10, 20) << endl;
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class myPrint {
public:
	myPrint() {
		count = 0;
	}
	void operator()(string str) {
		cout << str << endl;
		count++;
	}
	int count; //内部状态
};

void test02() {
	myPrint p;
	p("hello world");
	p("hello world");
	cout << "p函数对象被调用了：" << p.count << "次" << endl;
}

//3.函数对象可以作为参数传递
void doPrint(myPrint& p, string str) {
	p(str);
}

void test03() {
	myPrint p;
	doPrint(p, "hello");
	doPrint(p, "world");
	cout << "p函数对象被调用了：" << p.count << "次" << endl;
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

- 仿函数写法非常灵活，可以作为参数进行传递



### 4.2 谓词

#### 4.2.1 谓词概念

**概念：**

- 返回bool类型的仿函数称为**谓词**
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词



#### 4.2.2 一元谓词

**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//一元谓词
//仿函数 返回值为bool类型
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//查找容器中大于5的数字
	//GreaterFive是匿名对象
	auto it = find_if(v.begin(), v.end(), GreaterFive());
	while (it != v.end()) {
		cout << *it << " ";
		it++;
		it = find_if(it, v.end(), GreaterFive());
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：参数只有一个的谓词，称为一元谓词



#### 4.2.3 二元谓词

**示例：**

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//二元谓词
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void showVec(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "升序：" << endl;
	sort(v.begin(), v.end());
	showVec(v);

	//使用函数对象,改变排序规则,实现降序
	cout << "降序：" << endl;
	sort(v.begin(), v.end(), MyCompare());
	showVec(v);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：参数只有两个的谓词，称为二元谓词



### 4.3 内建函数对象

#### 4.3.1 内建函数对象意义

**概念：**

- STL内建了一些函数对象

**分类：**

- 算术仿函数
- 关系仿函数
- 逻辑仿函数

**用法：**

- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件`#include<functional>`



#### 4.3.2 算术仿函数

**功能描述：**

- 实现四则运算
- 其中negate是一元运算，其他都是二元运算

**仿函数原型：**

- `template<class T> T plus<T>` //加法仿函数
- `template<class T> T minus<T>` //减法仿函数
- `template<class T> T multiplies<T>` //乘法仿函数
- `template<class T> T divides<T> `//除法放函数
- `template<class T> T modulus<T>` //取模仿函数
- `template<class T> T negate<T>` //取反仿函数

**示例：**

```c++
#include<iostream>
using namespace std;
#include<functional> //内建函数对象头文件

//内建函数对象_算术仿函数

//negate 一元仿函数 取反
void test01() {
	negate<int> n;
	cout << n(50) << endl;
}

//plus 二元仿函数 加法
void test02() {
	plus<int> p;
	cout << p(10, 20) << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

总结：使用内建函数对象时，需要引入头文件 `#include <functional>`

