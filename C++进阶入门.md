# C++ 核心编程

本节点主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓



## 一、内存分区模型

C++程序在执行时，将内存大方向划分为**4个区域**

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
- 堆区：由程序员分配和释放，若程序员不释放，程序结束时由系统回收

==注：==代码区、全局区是程序运行前的区域，栈区、堆区是程序运行后的区域



**内存四区意义：**

不同区域存放的数据，赋予不同的生命周期，给我们最大的灵活编程



### 1.1 程序运行前

在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域

**代码区：**

​	存放CPU执行的机器指令

​	代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​	代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令

**全局区：**

​	全局变量和静态变量存放于此

​	全局区还包含了常量区，字符串常量和其他常量也存放在此

​	**==该区域的数据在程序结束后由操作系统释放==**



**示例代码：**

```c++
#include <iostream>

using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{

	//全局区
	//全局变量、静态变量、常量

	//创建一个普通的局部变量
	int a = 10;
	int b = 10;

	cout << "局部变量a的地址为：" << (int)&a << endl;
	cout << "局部变量b的地址为：" << (int)&b << endl;

	cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
	cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

	//静态变量	在普通变量面前加static，属于静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串常量的地址为：" << (int)&"Hello World" << endl;

	//const修饰的变量
	//const修饰的全局变量，const修饰的局部变量

	cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
	cout << "全局常量c_g_b的地址为：" << (int)&c_g_b << endl;

	const int c_l_a = 10; //c-const	g-global	l-local
	const int c_l_b = 10;

	cout << "局部常量c_l_a的地址为：" << (int)&c_l_a << endl;
	cout << "局部常量c_l_b的地址为：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}
```



**运行结果：**

![屏幕截图 2023-06-16 215640](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-06-16 215640.png)



**总结：**

![image-20230616220147908](https://gitee.com/YuXinHome/blogimg/raw/master/image-20230616220147908.png)

- C++中在程序运行前分为全局区和代码区
- 代码区特点是**共享**和**只读**
- 全局区中存放全局变量、静态变量、常量
- 常量区中存放const修饰的全局变量和字符串常量



### 1.2 程序运行后

**栈区：**

​	由编译器自动分配释放，存放函数的参数值，局部变量等

​	注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放



**示例：**

```c++
#include <iostream>

using namespace std;

//栈区数据注意事项 --- 不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放

int* func()
{
	int a = 10; //局部变量	存放在栈区，栈区的数据在函数执行完后自动释放
	return  &a; //返回局部变量的地址
}

main()
{
	//接受func函数的返回值
	int *p = func();

	cout << *p << endl; //如果第一次打印了正确的数字，是因为编译器做了保留
	cout << *p << endl; //第二次这个数据不再保留

	system("pause");
	return 0;
}
```



**堆区：**

​	由程序员分配释放，若程序员不释放，程序结束时由操作系统回收

​	由C++中主要利用new在堆区开辟内存



**示例：**

```c++
#include <iostream>

using namespace std;

int* func()
{
	//利用new关键字	可以将数据开辟到堆区
	//指针本身也是局部变量，他也是放在栈上，指针保存的数据放在堆区
	int* p = new int(10); //new 返回的是这个数据开辟的地址位置
	return p;
}

int main()
{

	//在堆区开辟数据
	int* p = func();

	cout << *p << endl;


	system("pause");
	return 0;
}
```

![屏幕截图 2023-06-20 224350](E:\c.---c.---java-exercise\photo\屏幕截图 2023-06-20 224350.png)

**总结：**

堆区数据由程序员管理开辟和释放

堆区数据利用new关键字进行开辟内存



### 1.3 new操作符

C++中利用==new==操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符==delete==

语法：`new 数据类型`

利用new创建的变量，会返回数据对应类型的指针



**示例：基本语法 & 开辟数组**

```c++
#include <iostream>

using namespace std;

//1.new基本语法

int* func()
{
	//在堆区创建整型数据
	//new返回的是 该数据类型的指针
	int* p = new int(10);
	return p;
}

void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据	由程序员管理开辟，程序员管理释放
	//如果想释放堆区的数据，利用关键字 delete

	delete p;

	//cout << *p << endl;	内存已释放，再次访问就是非法操作，或者报错
}

//2.在堆区用new开辟数组
void test02()
{
	//创建10整型类型的数组，在堆区
	int* arr = new int[10]; //10代表数组有10个元素

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组
	//释放数组的时候，要加[]才可以
	delete[] arr;
}

int main()
{

	test01();

	test02();

	system("pause");
	return 0;
}
```

**总结：**

基本语法

```c++
int* func()
{
	//在堆区创建整型数据
	//new返回的是 该数据类型的指针
	int* p = new int(10);
	return p;
}
void test01()
{
	int* p = func();
	delete p;
}
```

开辟数组

```c++
void test02()
{
	//创建10整型类型的数组，在堆区
	int* arr = new int[10]; //10代表数组有10个元素

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组
	//释放数组的时候，要加[]才可以
	delete[] arr;
}
```

==注：==释放数组要加[] —— `delete[] arr;`



## 二、引用

### 2.1 引用的基本使用

**作用：**给变量起别名

**语法：**`数据类型 &别名 = 原名`



![屏幕截图 2023-06-21 180954](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-06-21 180954.png)

**示例：**

```c++
#include <iostream>

using namespace std;

int main()
{
	//引用基本语法
	//数据类型 &别名 = 原名

	int a = 10;
	//创建引用
	int& b = a;

	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}
```



### 2.2 引用注意事项

- 引用必须初始化
- 引用在初始化后，不可以改变



![屏幕截图 2023-06-21 183409](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-06-21 183409.png)

**示例：**

```c++
#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	//1.引用必须初始化
	//int& b;	错误
	int& b = a;


	//2.引用一旦初始化，就不可以改变
	int c = 20;

	b = c; //赋值操作，不是更改引用

  	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	return 0;
}
```



### 2.3 引用做函数参数

**作用：**函数传参时，可以利用==引用==的技术让形参修饰形参

**优点：**可以简化指针修改实参                                                                                                                                                                                                                            



**示例：**

```c++
#include <iostream>

using namespace std;

//交换函数

//1.值传递
void mySwap01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01 a = " << a << endl;
	cout << "swap01 b = " << b << endl;
}

//2.地址传递
void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3.引用传递
void mySwap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{

	int a = 10;
	int b = 20;

	mySwap01(a, b); //值传递，形参不会修饰实参

	mySwap02(&a, &b); //地址传递，修饰实参
	cout << "swap02 a = " << a << endl;
	cout << "swap02 b = " << b << endl;

	a = 10;
	b = 20;
	mySwap03(a, b); //引用传递，形参也会修饰实参
	cout << "swap03 a = " << a << endl;
	cout << "swap03 b = " << b << endl;

	system("pause");
	return 0;
}
```

**总结：**	通过引用参数产生的效果同按地址传递是一样的，引用的语法更清楚简单

1. 值传递，形参==不会修饰实参==
2. 地址传递，==修饰实参==
3. 引用传递，形参也==会修饰实参==



### 2.4 引用做函数返回值

作用：引用是可以作为函数的返回值存在的



注意：**不要返回局部变量引用**

用法：函数调用作为左值



**示例：**

```c++
#include <iostream>

using namespace std;

//引用做函数返回值
//1.不要返回局部变量的引用
int& test01()
{
	int a = 10; //局部变量 存放在 栈区
	return a;
}

//2.函数的调用可以作为左值
int& test02()
{
	static int a = 10; //静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
	return a;
}

int main()
{

	//int& ref = test01(); //&ref = a

	//cout << "ref = " << ref << endl; //第一次结果正确，因为编译器做了保留
	//cout << "ref = " << ref << endl; //第二次结果错误，因为a的内存已经释放

	int& ref2 = test02();
	
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl; //均正确

	//如果函数作左值，那么必须返回引用
	test02() = 1000; //如果函数的返回值是引用（返回的是 a 的本身），则这个函数调用可作为左值

	cout << "ref2 = " << ref2 << endl;


	system("pause");
	return 0;
}
```



### 2.5 引用的本质

本质：**引用的本质在C++内部实现是一个指针常量**

讲解示例：

```c++
#include <iostream>

using namespace std;

//发现是引用，转换为 int* const ref = &a;
void func(int& ref)
{
	ref = 100; //ref是引用，转换为*ref = 100
}

int main()
{

	int a = 10;

	//自动转换为 int* cosnt ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动帮我们转换为:*ref = 20;

	cout << "a = " << a << endl;
	cout << "ref = " << ref << endl;

	system("pause");
	return 0;
}
```

![屏幕截图 2023-06-30 202117](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-06-30 202117.png)

==结论：==C++推荐使用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针编译器都帮我们做了

1. 引用的本质 就是一个指针常量
2. 引用一旦初始化后，就不可以发生改变



### 2.6 常量引用

**作用：**常量引用主要用来修饰实参，防止误操作

在函数形参列表中，可以加==const修饰形参==，防止形参改变实参

**示例：**

```c++
#include <iostream>

using namespace std;

//打印数据函数
void showValue(const int& val)
{
	//val = 1000;
	cout << "val = " << val << endl;
}

int main()
{

	//常量引用
	//使用场景，用来修饰形参，防止误操作

	//int a = 10;

	//加上const之后 编译器将代码修改为 int temp = 10; const int& ref = temp;
	//const int& ref = 10; //引用必须引一块合法的内存空间
	//ref = 20; //加入const之后变为只读，不可以修改

	//int& ref = a;

	int a = 100;
	showValue(a);

	cout << "a = " << a << endl;

	system("pause");
	return 0;
}
```

==重点：==`void showValue(const int& val)`中的`const int& val`