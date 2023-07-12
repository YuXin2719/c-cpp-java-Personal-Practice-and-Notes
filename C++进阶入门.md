# C++ 核心编程

编译器使用：**VS2022**

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



## 三、函数提高

### 3.1 函数默认参数



在C++中，函数的形参列表中的形参是可以有默认值的

语法：`返回值类型 函数名 (参数 = 默认值){}`



**示例：**

```c++
#include <iostream>

using namespace std;

//函数默认参数

//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
//语法：返回值类型 函数名(形参 = 默认值){}
int func(int a, int b = 20, int c = 30)
{
	return a + b + c;
}

//注意事项
//1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//	假如 func2 中的 b 被初始化赋值，则 c 和 d 都需要初始化赋值
int func2(int a, int b = 10, int c = 10, int d = 10)
{
	return a + b + c;
}

//2.如果函数声明有默认参数，函数实现不能有默认参数
//	声明和实现只能有一个默认参数
int func3(int a, int b);

int func3(int a = 10, int b = 10)
{
	return a + b;
}

int main()
{

	cout << func(10,30) << endl;

	cout << func3(10, 10) << endl;

	system("pause");
	return 0;
}
```



### 3.2 函数占位参数



C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置



**语法：**`返回值类型 函数名  (数据类型){}`



在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术



**示例：**

```c++
#include <iostream>

using namespace std;

//占位参数
//返回值类型 函数名 (数据类型) {}

//目前阶段的占位参数，我们还用不到，后面的课程中会用到
//占位参数 还可以有默认参数
void func(int a,int = 10)
{
	cout << "this is function" << endl;
}

int main()
{

	func(10);

	system("pause");
	return 0;
}
```



### 3.3 函数重载

#### 3.3.1 函数重载概述



**作用：**函数名可以相同，提高复用性



**函数重载满足条件：**

- 同一个作用域下
- 函数名称相同
- 函数参数**类型不同** 或者 **个数不同** 或者 **顺序不同**



**注意：**函数的返回值不可以作为函数重载的条件



**示例：**

```c++
#include <iostream>

using namespace std;

//函数重载
//可以让函数名相同，提高复用性

//函数重载的满足条件
//1.同一个作用域下
//2.函数名称相同
//3.函数参数类型不同，或者个数不同，或者顺序不同
void func()
{
	cout << "func的调用" << endl;
}

void func(int a)
{
	cout << "func(int a)的调用" << endl;
}

void func(double a)
{
	cout << "func(double a)的调用" << endl;
}

void func(int a,double b)
{
	cout << "func(int a,double b)的调用" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b)的调用" << endl;
}

//注意事项
//函数的返回值不可以作为函数重载的条件，如下错误

//int func(double a, int b)
//{
//	cout << "func(double a, int b)的调用" << endl;
//}

int main()
{

	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14,10);

	system("pause");
	return 0;
}
```



#### 3.3.2 函数重载注意事项



- 引用作为重载条件
- 函数重载碰到函数默认参数



**示例：**

```c++
#include <iostream>

using namespace std;

//函数重载的注意事项
//1.引用作为重载的条件
void func(int& a) //int& a = 10; 不合法
{
	cout << "func(int& a)调用" << endl;
}

void func(const int& a) //const int& a = 10;
{
	cout << "func(const int& a)调用" << endl;
}

//2.函数重载碰到默认参数
void func2(int a,int b = 10)
{
	cout << "func2(int a,int b)调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a)调用" << endl;
}

int main()
{

	int a = 10;
	func(a); //func(int& a)调用

	const int b = 10;
	func(b); //func(const int& a)调用
	func(10); //func(const int& a)调用

	//func2(10); //当函数重载碰到默认参数，出现二义性，尽量避免这种情况

	system("pause");
	return 0;
}
```



## 四、类和对象



C++面向对象的三大特性为：==封装、继承、多态==



C++认为==万事万物都皆为对象==，对象上有其属性和行为



**例如：**

人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

车也可以作为对象，属性有轮胎、方向盘、车灯...，行为有载人、放音乐、放空调...

具有相同性质的==对象==，我们可以抽象称为==类==，人属于人类，车属于车类



### 4.1 封装

#### 4.1.1 封装的意义

封装是C++面向对象三大特性之一

封装的**意义：**

- 将属性和行为作为一个整体，表现生活中的事务
- 将属性和行为加以权限控制

**封装意义一：**

在设计类的时候，属性和行为写在一起，表现事物

**语法：**`class 类名{ 访问权限: 属性 / 行为 }`



**示例1：**设计一个圆类，求圆的周长

**示例代码：**

```c++
#include <iostream>

using namespace std;

const double PI = 3.14;

//设计一个圆类，求圆的周长
//圆求周长的公式： 2 * PI * 半径

//class 代表设计一个类，类后面紧跟着类的名称
class Circle
{
	//访问权限
	//公共权限
public:

	//属性
	//半径
	int m_r;

	//行为
	//获取圆的周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};

int main()
{

	//通过圆类 创建具体的圆（对象）
	//实例化	（通过一个类 创建一个对象的过程）
	Circle c1;
	//给圆对象的 属性 进行赋值
	c1.m_r = 10;

	cout << "圆的周长为：" << c1.calculateZC() << endl;

	system("pause");
	return 0;
}
```



**示例2：**设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号



**示例2代码：**

```c++
#include <iostream>

using namespace std;

//学生类	属性：姓名、学号，可以赋值，可以显示
class Student
{
public: //公共权限

	//类中的属性和行为	我们统一称为	成员
	//属性	成员属性 成员变量
	//行为	成员函数 成员方法

	//属性
	string m_Name; //姓名
	int m_Id; //学号

	//行为
	//显示姓名和学号
	void showStudent()
	{
		cout << "姓名：" << m_Name << endl << "学号：" << m_Id << endl;
	}

	//给姓名赋值
	void setName(string name)
	{
		m_Name = name;
	}

	//给学号赋值
	void setId(int id)
	{
		m_Id = id;
	}
};

int main()
{

	//创建一个具体的学生	实例化对象
	Student s1;
	//给s1对象 进行属性赋值操作
	//s1.m_Name = "张三";
	s1.setName("张三");
	s1.setId(1);

	//显示学生信息
	s1.showStudent();

	Student s2;
	s2.m_Name = "李四";
	s2.m_Id = 2;

	system("pause");
	return 0;
}
```



**封装意义二：**

类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种：



1. public          公共权限
2. protected    保护权限
3. private         私有权限



**示例：**

```c++
#include <iostream>

using namespace std;

//访问权限
//三种
//公共权限 public		成员	类内可以访问	类外可以访问
//保护权限 protected	成员	类内可以访问	类外不可以访问	儿子也可以访问父亲中的保护内容
//私有权限 private		成员	类内可以访问	类外不可以访问	儿子不可以访问父亲的私有内容

class Person
{
	//公共权限
public:
	string m_Name; //姓名

	//保护权限
protected:
	string m_Car; //汽车

	//私有权限
private:
	int m_Password; //银行卡密码

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

int main()
{

	//实例化具体对象
	Person p1;

	p1.m_Name = "李四";
	//p1.m_Car = "奔驰"; //保护权限的内容在类外访问不到
	//p1.m_Password = 123; //私有权限的内容类外也访问不到

	p1.func();

	system("pause");
	return 0;
}
```



#### 4.1.2 struct和class的区别



在C++中struct和class**唯一**的 **区别** 就在于 **默认的访问权限不同**

区别：

- struct     默认权限为公共
- class      默认权限为私有



```c++
#include <iostream>

using namespace std;

class C1
{
	int m_A; //默认权限为 私有
};

struct C2
{
	int m_A; //默认权限为 公共
};

int main()
{

	//struct 和 class 的区别
	//struct 默认权限是 公共 public
	//class  默认权限是 私有 private

	C1 c1;
	//c1.m_A = 100;

	C2 c2;
	c2.m_A = 100; //在struct默认的权限为公共，因此可以访问

	system("pause");
	return 0;
}
```



#### 4.1.3 成员属性设置为私有



**优点1：**将所有成员属性设置为私有，可以自己==控制读写权限==

**优点2：**对于写权限，我们可以==检测数据的有效性==



**示例：**

```c++
#include <iostream>

using namespace std;

//成员属性设置为私有
//1.可以自己控制读写的权限
//2.对于写可以检测数据的有效性

//设计人类
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}
	
	//获取年龄
	int getAge()
	{ 
		return m_Age;
	}
	//设置年龄	检测数据有效性
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "你这年龄不对劲啊，我给你改0了，重新设置" << endl;
		}
		else
			m_Age = age;
	}

	//设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	//控制读写权限

	//姓名	可读可写
	string m_Name;

	//年龄	可读可写
	int m_Age;

	//情人	只写
	string m_Lover;
};

int main()
{

	Person p;
	p.setName("张三");

	cout << "姓名为：" << p.getName() << endl;

	//设置年龄
	//p.setAge(155);
	p.setAge(18);
	cout << "年龄为：" << p.getAge() << endl;

	//设置情人为仓井女士
	p.setLover("仓井");

	system("pause");
	return 0;
}
```



**练习案例1：设计立方体类**

设计立方体类（Cube）

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等

![屏幕截图 2023-07-05 090926](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-07-05 090926.png)



**示例：**

```c++
#include <iostream>

using namespace std;

//立方体类设计
class Cube
{
public:
	//行为

	//设置获取长宽高
	//设置长
	void setL(int l)
	{
		m_L = l;
	}

	//获取长
	int getL()
	{
		return m_L;
	}

	//设置宽
	void setW(int w)
	{
		m_W = w;
	}

	//获取宽
	int getW()
	{
		return m_W;
	}

	//设置高
	void setH(int h)
	{
		m_H = h;
	}

	//获取高
	int getH()
	{
		return m_H;
	}


	//获取立方体面积
	int calculateS()
	{
		return (2 * m_L * m_W) + (2 * m_L * m_H) + (2 * m_W * m_H);
	}

	//获取立方体体积
	int calculateV()
	{
		return m_L * m_W * m_H;
	}

	//利用成员函数判断两个立方体是否相等
	bool isSameByClass(Cube& c)
	{
		if (c.getL() == m_L && c.getW() == m_W && c.getH() == m_H)
			return true;
		else
			return false;
	}

private:
	//属性
	int m_L, m_W, m_H; //m代表member,成员
};

//利用全局函数判断 两个立方体是否相等
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
		return true;
	else
		return false;
}

int main()
{
	//创建立方体对象
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;

	//创建第二个立方体
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(11);

	//利用全局函数判断
	bool ret = isSame(c1, c2);
	cout << "全局函数判断：" << endl;
	if (ret == true)
		cout << "两个立方体相等" << endl;
	else
		cout << "两个立方体不相等" << endl;

	//利用成员函数判断
	//因为调用的是 c1 的函数，所以内部数据是 c1 的数据，所以只需要传入另一个立方体的数据即可
	ret = c1.isSameByClass(c2);
	cout << "成员函数判断：" << endl;
	if (ret == true)
		cout << "两个立方体相等" << endl;
	else
		cout << "两个立方体不相等" << endl;

	system("pause");
	return 0;
}
```

这里有意思的是：

全局函数需要传入两个立方体的数据

成员函数只需要传入一个立方体的数据，因为判断判断是否相等的成员函数所在的类内已经有了它（c1）本身的数据

函数传入多用到引用，相较于形参（需要拷贝一份数据），可以节省内存



**练习案例2：点和圆的关系**

设计一个圆类（Circle），和一个点类（Point），计算点和圆的关系

![屏幕截图 2023-07-05 115836](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-07-05 115836.png)



**示例：**

**1.	练习案例2：点和圆的关系.cpp**

```c++
#include <iostream>
#include <cmath>
#include "point.h"
#include "Circle.h"

using namespace std;

////点和圆关系案例
//// 点类
//class Point
//{
//public:
//	//设置x
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取x
//	int getX()
//	{
//		return m_X;
//	}
//
//	//设置y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//
//	//获取y
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};

////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R; //半径
//
//	Point m_Center; //圆心
//};

//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间的距离 平方
	double twoPointsDistance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);

	//计算半径的平方
	double rDistance = pow(c.getR(), 2);

	//判断关系
	if (twoPointsDistance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (twoPointsDistance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{

	//创建圆
	Circle c1; //圆
	Point c1Center; //圆心

	//设置圆心参数
	c1Center.setX(10);
	c1Center.setY(0);

	//设置圆半径和圆心
	c1.setR(10);
	c1.setCenter(c1Center);

	//创建点
	Point p1;

	p1.setX(10);
	p1.setY(9);

	Point p2;

	p2.setX(10);
	p2.setY(10);

	Point p3;

	p3.setX(10);
	p3.setY(11);

	//判断关系
	isInCircle(c1, p1);
	isInCircle(c1, p2);
	isInCircle(c1, p3);

	system("pause");
	return 0;
}
```



**2.	point.cpp**

```c++
#include <iostream>
#include "point.h"

//点和圆关系案例
// 点类

//设置x
void Point::setX(int x)
{
	m_X = x;
}
//获取x
int Point::getX()
{
	return m_X;
}

//设置y
void Point::setY(int y)
{
	m_Y = y;
}

//获取y
int Point::getY()
{
	return m_Y;
}
```



**3.	point.h**

```c++
#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;

//点和圆关系案例
// 点类
class Point
{
public:
	//设置x
	void setX(int x);

	//获取x
	int getX();


	//设置y
	void setY(int y);


	//获取y
	int getY();


private:
	int m_X;
	int m_Y;
};
```



**4.	Circle.cpp**

```c++
#include "Circle.h"

//设置半径
void Circle::setR(int r)
{
	m_R = r;
}

//获取半径
int Circle::getR()
{
	return m_R;
}

//设置圆心
void Circle::setCenter(Point center)
{
	m_Center = center;
}

//获取圆心
Point Circle::getCenter()
{
	return m_Center;
}

```



**5.	Circle.h**

```c++
#pragma once
#include "point.h"
//圆类
class Circle
{
public:
	//设置半径
	void setR(int r);


	//获取半径
	int getR();


	//设置圆心
	void setCenter(Point center);


	//获取圆心
	Point getCenter();


private:
	int m_R; //半径

	Point m_Center; //圆心
};
```



**重点：**

1. 在类中可以让另一个类	作为本来中的成员
2. 如何把一个类拆到不同的文件中 - 分文件开发



### 4.2 对象的初始化和清理



- 生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用的时候也会删除一些信息数据保证信息安全
- C++中的面向对象来源于生活，每个对象也都会有初始设置以及对象销毁前的清理数据的设置



#### 4.2.1 构造函数和析构函数

对象的**初始化和清理**也是两个非常重要的安全问题

​	一个对象或者变量没有初始状态，对其使用后果是未知的

​	同样的使用完一个对象或者变量，没有及时清理，也会造成一定的安全问题



C++利用了**构造函数**和**析构函数**解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。对象的初始化和清理工作是编译器强制要我们做的事情，因此如果**我们不提供构造和析构，编译器会提供编译器提供的构造函数和析构函数是空实现。**



- 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
- 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作



**构造函数语法：`类名(){}`**

1. 构造函数，没有返回值也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象的时候会自动调用构造，无需手动调用，而且只会调用一次



**析构函数语法：`~类名(){}`**

1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同，在名称前加上符号~
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次



```c++
#include <iostream>
using namespace std;

//对象的初始化和清理
//1.构造函数	进行初始化操作
class Person
{
public:
	//1.1	构造函数
	//没有返回值 不用写void
	//函数名与类的名称相同
	//构造函数可以有参数，可以发生重载
	//创建对象的时候，会自动调用，而且只调用一次
	Person()
	{
		cout << "Person 构造函数的调用" << endl;
	}

	//2.析构函数	进行清理的操作
	//没有返回值	不写 void
	//函数名和类名相同 在名称前加 ~
	//析构函数不可以有参数的，不可以发生重载
	//对象在销毁前 会自动调用析构函数，而且只会调用一次
	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
};

//析构和构造都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01()
{
	Person p; //在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{

	//test01();

	Person p;

	system("pause");
	return 0;
}
```



#### 4.2.2 构造函数的分类及调用

两种分类方式：

- 按参数分为：有参构造和无参构造
- 按类型分为：普通构造和拷贝构造

三种调用方式：

- 括号法
- 显示法
- 隐式转换法



**示例：**

```c++
#include <iostream>
using namespace std;

//1.构造函数的分类和调用
//分类
//按照参数来分类	无参构造（默认构造） 和 有参构造
class Person
{
public:
	//构造函数

	//无参构造
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	//有参构造
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	//以上是普通构造
	
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int age;
};

void test01()
{
	//1.括号法
	//Person p1; //默认构造函数调用
	//Person p2(10); //有参构造函数
	//Person p3(p2); //拷贝构造函数

	//注意事项1
	//调用默认构造函数的时候，不要加()
	//因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	//Person p1();
	//比如
	//void func();

	//cout << "p2的年龄：" << p2.age << endl;
	//cout << "p3的年龄：" << p3.age << endl;

	//2.显示法
	Person p1;
	Person p2 = Person(10); //有参构造
	Person p3 = Person(p2); //拷贝构造

	//Person(10); //匿名对象	特点：当前行执行结束后，系统会立即回收掉匿名对象
	//cout << "aaaaa" << endl;

	//注意事项2
	//不要利用拷贝构造函数 初始化匿名对象	编译器会认为 Person(p3) === Person p3; 对象的声明
	//Person(p3);

	//3.隐式转换法
	Person p4 = 10; //相当于 写了 Person p4 = Person(10);	有参构造
	Person p5 = p4; //拷贝构造
}

//调用

int main()
{

	test01();

	system("pause");
	return 0;
}
```



**无参构造函数**

```c++
	//无参构造
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}
```

**有参构造函数**

```c++
	//有参构造
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
```

**拷贝构造函数**

```c++
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}
```

**析构函数**

```c++
	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
```

**调用法：1.括号法**

```c++
	//1.括号法
	Person p1; //默认构造函数调用
	Person p2(10); //有参构造函数
	Person p3(p2); //拷贝构造函数
```

**调用法：2.显示法**

```c++
	//2.显示法
	Person p1;
	Person p2 = Person(10); //有参构造
	Person p3 = Person(p2); //拷贝构造
```

**调用法：3.隐式转换法**

```c++
	//3.隐式转换法
	Person p4 = 10; //相当于 写了 Person p4 = Person(10);	有参构造
	Person p5 = p4; //拷贝构造
```

**调用法：匿名对象**

```c++
	Person(10); //匿名对象	特点：当前行执行结束后，系统会立即回收掉匿名对象
```



**注意事项：**

```c++
注意事项1
调用默认构造函数的时候，不要加()
因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
Person p1();
比如
void func();
```
```c++
注意事项2
不要利用拷贝构造函数 初始化匿名对象	编译器会认为 Person(p3) === Person p3; 对象的声明
Person(p3);
```


#### 4.2.3 拷贝构造函数调用时机



C++中拷贝构造函数调用时机通常由三种情况

- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值
- 以值方式返回局部对象

**示例：**

```c++
#include <iostream>
using namespace std;

//拷贝构造函数调用时机

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "Person有参函数调用" << endl;
	}

	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person拷贝构造函数" << endl;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}

	int m_Age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}

//2.值传递的方式给函数参数传值	值就是拷贝的新的数据
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);
}

//3.值方式返回局部对象
//如果直接写 return p1; 就会返回p1本身，也就是 p 和 p1 地址一样
Person doWork2()
{
	Person p1;
	cout << (int)&p1 << endl; //查看 p1 地址
	return Person(p1);
}

void test03()
{
	Person p = doWork2();
	cout << (int)&p << endl; //查看 p 地址
}

int main()
{

	//test01();
	
	//test02();

	test03();

	system("pause");
	return 0;
}
```



#### 4.2.4 构造函数调用规则

默认情况下，C++编译器至少给一个类添加3个函数

1. 默认构造函数（无参，函数体为空）
2. 默认析构函数（无参，函数体为空）
3. 默认拷贝函数，对属性进行值拷贝



构造函数调用规则如下：

- 如果用户定义有参构造函数，C++不在提供默认无参构造，但是会提供默认拷贝构造
- 如果用户定义拷贝构造函数，C++不会再提供其他构造函数

**示例：**

```c++
#include <iostream>
using namespace std;

//构造函数的调用规则

//1.创建一个类，C++编译器会给每个类都添加至少3个函数
//默认函数	（空实现）
//析构函数	（空实现）
//拷贝构造	（值拷贝）

//2.如果我们写了有参构造函数，编译器就不会提供默认构造，依然提供拷贝构造
//	如果我们写了拷贝构造函数，编译器就不再提供其他普通构造函数了

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
	}

	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
};

void test01()
{
	Person p;
	p.m_Age = 18;

	Person p2(p);
	cout << "p2的年龄为：" << p2.m_Age << endl;
}

void test02()
{
	Person p(28);

	Person p2(p);
	cout << "p2的年龄为：" << p2.m_Age << endl;
}

int main()
{

	test01();

	test02();

	system("pause");
	return 0;
}
```



#### 4.2.5 深拷贝和浅拷贝



深浅拷贝是面试的经典问题，也是一个常见的坑



浅拷贝：简单的赋值拷贝操作



深拷贝：在堆区重新申请空间，进行拷贝操作



**示例：**

```c++

```

