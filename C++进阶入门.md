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

**==注：==释放数组要加[] —— `delete[] arr;`**



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
#include <iostream>
using namespace std;

//深拷贝与浅拷贝

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}

	//自己实现拷贝构造函数 解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "拷贝构造函数的调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height; //编译器默认就是这行代码
		
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//析构代码，将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL; //将m_Height设置为NULL是为了明确表明指针不再指向有效的内存区域，避免在后续代码中错误地使用悬空指针
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age; //年龄
	int* m_Height; //身高
};

void test01()
{
	Person p1(18,160);

	cout << "p1的年龄为：" << p1.m_Age << endl;

	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```

![屏幕截图 2023-07-15 220813](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-07-15 220813.png)

浅拷贝 导致的问题要利用 深拷贝 解决



#### 4.2.6 初始化列表



**作用：**

C++提供了初始化列表语法，用来初始化属性



**语法：`构造函数():属性1(值1),属性2(值2)...{}`**



**示例：**

```c++
#include <iostream>
using namespace std;

//初始化列表
class Person
{
public:

	//传统初始化操作
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表 初始化属性
	//Person() :m_A(10), m_B(20), m_C(30){
	//
	//}
	
	//初始化列表 另一种初始化方式
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {

	}

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	//Person p(10, 20, 30);
	
	//Person p;

	Person p(10, 20, 30);

	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.2.7 类对象作为类的成员



C++类中的成员可以作为另一个类的对象，我们称该成员为 对象成员



例如：

```c++
class A {}
class B
{
    A a;
}
```



B类中有对象A作为成员，A为对象成员



那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？



**示例：**

```c++
#include <iostream>
using namespace std;

//类对象作为类对象

class Phone
{
public:
	Phone(string pName) :m_PName(pName) {
		cout << "Phone 构造函数调用" << endl;
	}

	//手机品牌
	string m_PName;

	~Phone()
	{
		cout << "Phone 析构函数调用" << endl;
	}
};

class Person
{
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout <<"Person 构造函数调用" << endl;
	}

	//姓名
	string m_Name;
	//手机
	Phone m_Phone;

	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}
};

//当其他类的对象作为本类的成员，构造时候先构造类对象，再构造自身
//								析构的顺序与构造相反

void test01()
{
	Person p("张三", "iPhone");

	cout << p.m_Name << " 拿着 " << p.m_Phone.m_PName << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.2.8 静态对象

静态成员就是在成员变量和成员函数前加上关键字static，成为静态对象

静态对象分为：



- 静态成员变量
  - 所有成员共享同一份数据
  - 在编程阶段分配内存
  - 类内声明，类外初始化
- 静态成员函数
  - 所有对象共享用一个函数
  - 静态成员函数只能访问静态成员变量



**示例1：**静态成员变量

```c++
#include <iostream>
using namespace std;

//静态成员变量
class Person
{
public:
	//1.所有对象都共享同一份数据
	//2.编译阶段就分配内存
	//3.类内声明，类外初始化	必须
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01()
{
	Person p;
	//100
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;

	//100 ? 200		↓输出 200
	cout << p.m_A << endl;
	//cout << p2.m_A << endl;

}

void test02()
{
	//静态成员变量，不属于某一个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1.通过对象进行访问
	Person p;
	cout << p.m_A << endl;

	//2.通过类名进行访问
	cout << Person::m_A << endl;

	//cout << Person::m_B << endl; //私有权限类外访问不到
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}
```



**示例2：**静态成员函数

```c++
#include <iostream>
using namespace std;

//静态成员函数
//1.所有对象都共享同一个函数
//2.静态成员函数只能访问静态成员变量

class Person
{
public:

	//静态成员函数
	static void func()
	{
		m_A = 100; //静态成员函数可以访问 静态成员变量
		//m_B = 200; //静态成员函数 不可以访问 非静态成员变量，无法区分到底是那个对象的 m_B 属性
		cout << "static void func 调用" << endl;
	}

	static int m_A; //静态成员变量
	int m_B; //非静态成员变量

	//静态成员函数也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2 的调用" << endl;
	}
};

int Person::m_A = 0;

//有两种访问方式
void test01()
{
	//1.通过对象访问
	Person p;
	p.func();

	//2.通过类名访问
	Person::func();

	//Person::func2(); //类外不可以访问私有静态成员函数
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



### 4.3 C++对象模型和this指针



#### 4.3.1 成员变量和成员函数分开存储



在C++中，类内的成员变量和成员函数分开存储

**只有**非静态成员变量才属于类的对象上



```c++
#include <iostream>
using namespace std;

//成员变量 和 成员函数 是分开存储的

class Person
{
	int m_A; //非静态成员变量			属于类的对象上的

	static int m_B; //静态成员变量		不属于类的对象上

	void func() //非静态成员函数		不属于类的对象上
	{

	}

	static void func2() //静态成员函数	不属于类的对象上
	{

	}
};

int Person::m_B = 0;

void test01()
{
	Person p;
	//空对象占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "sizeof p = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "sizeof p = " << sizeof(p) << endl;
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}
```



#### 4.3.2 this指针概念

通过 4.3.1 我们知道在C++中成员变量和成员函数是分开储存的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分哪个对象调用自己的呢？



C++通过提供特殊的对象指针，this指针，解决上述问题。**this 指针指向被调用的成员函数所属的对象**



this 指针是隐含每一个非静态成员函数内的一种指针

this 指针不需要定义，直接使用即可



this 指针的用途：

- 当形参和成员变量同名时，可用this 指针来区分
- 在类的非静态成员函数中返回对象本身，可使用 return *this

```c++
#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//this指针指向的是 被调用的成员函数 所属的对象
		this->age = age;
	}

	Person& personAddAge(Person& p)
	{
		this->age += p.age;	//this 是指向 p2 的一个指针（示例中）

		//this 指向的是 p2 的指针，而 *this 指向的就是 p2 这个对象本体
		return *this;
	}

	int age;
};

//this 指针概念
//1.解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄：" << p1.age << endl;
}

//2.返回对象本身用 *this
void test02()
{
	Person p1(10);

	Person p2(10);

	//链式编程思想
	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);

	cout << "p2的年龄为：" << p2.age << endl;
}

int main()
{

	test01();

	test02();

	system("pause");
	return 0;
}
```



#### 4.3.3 空指针访问成员函数



C++中空指针也是可以调用成员函数的，但是也要注意有没有用到 this 指针



如果用到 this 指针，需要加以判断保证代码的健壮性



**示例：**

```c++
#include <iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showClassAge()
	{
		//报错原因是因为传入的指针是NULL空指针

		if (this == NULL)
		{
			return;
		}

		cout << "age = " << m_Age << endl; //属性前面都默认加了this，即 this->m_Age ,由于this在示例中是空指针，所以没属性
	}

	int m_Age;
};

void test01()
{
	Person* p = NULL;

	p->showClassName();

	p->showClassAge();
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.3.4 const修饰成员函数



**常函数：**

- 成员函数后加const后我们称这个函数为**常函数**
- 常函数不可以修改成员函数
- 成员函数声明时加关键字mutable后，在常函数中依然可以修改



**常对象：**

- 声明对象前加const称该对象为常对象
- 常对象只能调用常函数



**示例：**

```c++
#include <iostream>
using namespace std;

//常函数
class Person
{
public:

	//本身 this指针的本质	是指针常量	指针的指向是不可以修改的
	//this指针本质是：Person* const this;

	//常函数表达式：void showPerson() const
	//意味着this指针变成：const void showPerson() const		即指针不能改，指向的值也不能改
	//在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改

	void showPerson() const
	{
		this->m_B = 100;
		//this->m_A = 100;
		//this->NULL; //this指针是不可以修改指针的指向的
	}

	int m_A;
	mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值		mutable - 可变的

	void func() 
	{
		m_A = 100;
	}
};

void test01()
{
	Person p;
	p.showPerson();
}

//常对象
void test02()
{
	const Person p; //在对象前加const，变为常对象
	//p.m_A = 100; //常对象也不允许修改属性
	p.m_B = 100; //m_B是特殊值，在常对象下也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func(); //常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main()
{

	

	system("pause");
	return 0;
}
```



### 4.4 友元



生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

但是呢，你也可以与允许你的好闺蜜好基友进去



在程序中，有些私有属性 也想让类外特殊的一些函数或者类访问，就需要用到友元的技术



友元的目的就是让一个函数或者类 访问另一个类中的私有成员



友元的关键词为 ==friend==



友元的三种实现

- 全局函数做友元
- 类做友元
- 成员函数做友元



#### 4.4.1 全局函数做友元

```c++
#include <iostream>
using namespace std;

class Building
{
	//goodGay全局函数是 Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);

public:
	string m_SittingRoom; //客厅

	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

private:
	string m_BedRoom; //卧室
};

//全局函数
void goodGay(Building *building)
{
	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
}

int main()
{

	Building building;
	goodGay(&building);

	system("pause");
	return 0;
}
```

重点：

```c++
	//goodGay全局函数是 Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);
```



**类做友元：**

```c++
#include <iostream>
using namespace std;

//类做友元

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit(); //参观函数 访问Building中的属性

	Building* building;
};

class Building
{
	//GoodGay类是本类的好朋友，可以访问本类中的私有成员
	friend class GoodGay;

public:
	string m_SittingRoom; //客厅

	Building();

private:
	string m_BedRoom; //卧室
};

//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建一个建筑物对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```

重点：

```c++
	//GoodGay类是本类的好朋友，可以访问本类中的私有成员
	friend class GoodGay;
```



**成员函数做友元：**

```c++
#include <iostream>
using namespace std;

//成员函数做友元

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit(); //让visit函数可以访问Building中私有成员
	void visit2(); //让visit2函数不可以访问Building中私有成员

	Building* building;
};

class Building
{
	//告诉编译器 GoodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void GoodGay::visit();

public:
	string m_SittingRoom; //客厅

	Building();

private:
	string m_BedRoom; //卧室
};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit 函数正在访问：" << building->m_SittingRoom << endl;

	cout << "visit 函数正在访问：" << building->m_BedRoom << endl;

}

void GoodGay::visit2()
{
	cout << "visit2 函数正在访问：" << building->m_SittingRoom << endl;

	//cout << "visit 函数正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```

重点：

```c++
	//告诉编译器 GoodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void GoodGay::visit();
```



### 4.5 运算符重载



运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型



#### 4.5.1 加号运算符重载



作用：实现两个自定义数据类型相加的运算



![屏幕截图 2023-07-20 182322](https://gitee.com/YuXinHome/blogimg/raw/master/屏幕截图 2023-07-20 182322.png)



```c++
#include <iostream>
using namespace std;

//加号运算符重载

class Person
{
public:
	int m_A;
	int m_B;

	Person operator+ (Person& p);
};

Person operator+ (Person p1, Person p2);

//函数重载的版本
Person operator+(Person p, int i)
{
	Person temp;
	temp.m_A = p.m_A + i;
	temp.m_B = p.m_B + i;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;

	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载本质调用
	//Person p3 = p1.operator+(p2);

	//全局函数重载本质调用
	//Person p3 = operator+(p1, p2);

	//Person p3 = p1 + p2;
	//运算符重载 也可以发生函数重载

	Person p4 = p1 + 100; //Person + int

	//cout << "p3.m_A = " << p3.m_A << endl;
	//cout << "p3.m_B = " << p3.m_B << endl;

	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;
}

//1.成员函数重载+号
Person Person::operator+ (Person& p)
{
	Person temp;
	temp.m_A = this->m_A + p.m_A;
	temp.m_B = this->m_B + p.m_B;
	return temp;
}

//2.全局函数重载+号
Person operator+ (Person p1, Person p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```

​	**注：**

> 对于内置的数据类型的表达式的运算符是不可以改变的
>
> 不要滥用运算符重载（operator+函数中写两个数相减也是可以的，但是这是滥用）



#### 4.5.2 左移运算符重载



作用：可以输出自定义数据类型



```c++
#include <iostream>
using namespace std;

//左移运算符重载

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}

private:

	//利用成员函数重载 左移运算符	p.operator<<(cout)	简化版本 p << cout
	//通常不会利用成员函数重载<<运算符，因为无法实现 cout 在左侧
	//void operator<<(cout)
	//{

	//}

	int m_A;
	int m_B;
};

//cout 的数据类型是 ostream - 标准输出流对象。 o - out		stream - 流		并且全局只允许存在一个cout，即要用就引用

//只能利用全局函数重载左移运算符
//用引用的方式保证全局只有一个 cout
ostream& operator<<(ostream& out, Person& p) //本质 operator<<(cout,p) 简化版本 cout << p
{
	out << "m_A = " << p.m_A << endl << "m_B = " << p.m_B;
	return out;
}

void test01()
{
	Person p(10, 10);
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```

**注：**

> 重载左移运算符配合友元可以实现输出自定义数据类型



#### 4.5.3 递增运算符重载



作用：通过重载递增运算符，实现自己的整型数据



```c++
#include <iostream>
using namespace std;

//重载递增运算符

//自定义整型
class myInteger
{
	friend ostream& operator<<(ostream& cout, const myInteger& i);

public:
	myInteger()
	{
		m_Num = 0;
	}

	//重载前置++运算符	返回引用为了一直对一个数据进行操作
	myInteger& operator++()
	{
		//先进行++运算
		m_Num++;

		//再将自身作返回
		return *this;
	}

	//重载后置++运算符
	//int 代表的占位参数，可以用于区分前置和后置。 并且编译器只认int，编译器可以确认为这是在写后置递增
	myInteger operator++(int)
	{
		//先 记录当时的结果
		myInteger temp = *this; //这里返回的是值，如果返回的是引用，那就是返回的局部变量的引用，这个函数用完就释放了，在操作就是非法操作

		//后 递增操作
		m_Num++;

		//最后返回记录的结果返回
		return temp;
	}

private:
	int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, const myInteger& i)
{
	cout << i.m_Num;
	return cout;
}

void test01()
{
	myInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	myInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}
//注：后置报错的，把左移运算符第二个参数使const 再加引用，或者直接不使用引用

int main()
{

	//test01();

	test02();

	//一直在同一个数据上进行操作
	//int a = 0;
	//cout << ++(++a) << endl;
	//cout << a << endl;

	system("pause");
	return 0;
}
```

 **注：**

> 前置递增返回引用，后置递增返回值





#### 4.5.4 赋值运算符重载



C++编译器至少给一个类添加4个函数

1. 默认构造函数（无参，函数体为空）
2. 默认析构函数（无参，函数体为空）
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=，对属性进行拷贝



如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝的问题



**示例：**

```c++
#include <iostream>
using namespace std;

//赋值运算符重载

class Person
{
public:

	Person(int age) //把数据创建在堆区
	{
		m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age; //删除内存块的信息
			m_Age = NULL; //指向空指针
		}
	}

	//重载赋值运算符
	Person& operator=(Person &p) //不能用Person，因为返回的是利用拷贝构造函数构造的值，用引用返回的才是真正的自身
	{

		if (&p == this) //判断出现自赋值的情况，如p1 = p1
		{
			return p;
		}

		//编译器提供的浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		m_Age = new int(*p.m_Age);
	
		//返回对象本身
		return *this;
	}

	int* m_Age;
};

void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //赋值操作

	p1 = p1;

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a;

	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");
	return 0;
}
```



#### 4.5.5 关系运算符重载



**作用：**重载关系运算符，可以让两个自定义类型对象进行对比操作



**示例：**

```c++
#include <iostream>
using namespace std;

//重载关系运算符

class Person
{
public:
	Person(string name,int age):m_Name(name),m_Age(age){}

	//重载 == 号

	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return true;
		else
			return false;

	}

	bool operator!=(const Person& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return false;
		else
			return true;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	Person p1("Tom", 18);

	Person p2("Jerry", 18);

	if (p1 == p2)
	{
		cout << "p1 和 p2 是相等的！" << endl;
	}
	else
	{
		cout << "p1 和 p2 不相等！" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1 和 p2 不相等！" << endl;
	}
	else
	{
		cout << "p1 和 p2 是相等的！" << endl;
	}
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.5.6 函数调用运算符重载



- 函数调用运算符 () 也可以重载
- 由于重载后的使用方式非常像函数调用，因此称之为 仿函数
- 仿函数没有固定写法，非常灵活



**示例：**

```c++
#include <iostream>
using namespace std;

//函数调用运算符重载

//打印输出类
class myPrint
{
public:

	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void myPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	myPrint myprint;

	myprint("hello world"); //由于使用起来非常类似于函数调用，因此称之为仿函数

	myPrint02("hello world");
}

//仿函数非常灵活，没有固定写法

//加法类

class myAdd
{
public:

	int operator()(int a,int b)
	{
		return a + b;
	}
};

void test02()
{
	myAdd myadd;

	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	//匿名函数对象
	cout << myAdd()(100, 100) << endl; //myAdd() 创建出一个匿名对象，运行完这一行立即释放
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}
```



### 4.6 继承

**继承是面向对象三大特性之一**

有些类与类之间存在特殊的关系，例如下图中：

![Screenshot 2023-07-22 021747](E:\c.---c.---java-exercise\photo\Screenshot 2023-07-22 021747.png)

我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性

这个时候我们就可以考虑利用继承的技术，减少重复代码



#### 4.6.1 继承的基本语法



例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同

就下来们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处



**最大的好处：**==减少重复代码==

**语法：`class 子类 : 继承方式 父类`**	如：`class Java :public BasePage`



**普通实现：**

```c++
//普通实现页面

//Java页面
class Java
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//C++页面
class Cpp
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "Cpp学科视频" << endl;
	}
};
```



**继承实现：**

```c++
//继承实现页面

//公共页面类
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
};

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//Cpp页面
class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "Cpp学科视频" << endl;
	}
};
```

**注：**

> 子类 也称为 派生类
>
> 父类 也称为 基类



> **派生类中的成员，包含两大部分：**
>
> 一类是从基类继承过来的，一类是自己增加的成员
>
> 从基类继承过来的表现其共性，新增的成员体现其个性



本节全部示例代码：

```c++
#include <iostream>
using namespace std;

//普通实现页面

//Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};

//Python页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};

//C++页面
//class Cpp
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...(公共分类列表)" << endl;
//	}
//	void content()
//	{
//		cout << "Cpp学科视频" << endl;
//	}
//};

//继承实现页面

//公共页面类
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
};

//继承的好处：减少重复代码
//语法：class 子类: 继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage //public公共继承
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//Cpp页面
class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "Cpp学科视频" << endl;
	}
};

void test01()
{
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "-----------------------------------" << endl;

	cout << "Python下载视频页面如下：" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "-----------------------------------" << endl;

	cout << "Cpp下载视频页面如下：" << endl;
	Cpp cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.6.2 继承方式



继承的语法：`class 子类 : 继承方式 父类`



继承方式一共有三种：

- 公共继承
- 保护继承
- 私有继承

![屏幕截图 2023-07-22 154030](E:\c.---c.---java-exercise\photo\屏幕截图 2023-07-22 154030.png)

即：

1. 父类 的 ==私有== 子类 都==不能访问==
2. 公有继承 父类 和 子类 ==除了私有权限都相同==
3. 保护继承 父类 的 ==公共== 和 ==保护== 在 子类 中==都变成了 保护权限==
4. 私有权限 父类 的 ==公共== 和 ==保护== 在 子类 中==都变成了 保护权限==



**示例代码：**

```c++
#include <iostream>
using namespace std;

//继承方式

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
		m_B = 10; //父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 10; //父类中的私有权限成员 到子类中访问不到
	}
};

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100; //父类中公共成员，到子类中变为保护权限
		m_B = 100; //父类中保护成员，到子类中变为保护权限
		//m_C = 100; //父类的私有成员访问不到
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; //继承到子类也是保护权限内容，所以类外不能访问
}

void test02()
{
	Son2 s1;
	//s1.m_A = 1000; //在Son2中 m_A变为保护权限，因此类外访问不到
	//s1.m_B = 1000; //在Son2中 m_B保护权限 不可以访问
}

void test03()
{
	Son3 s1;
	//s1.m_A = 1000; //到Son3中变为 私有成员 类外访问不到
	//s1.m_B = 1000; //到Son3中变为 私有成员 类外访问不到
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
	void func()
	{
		m_A = 100; //父类中公共成员 到子类中变为 私有成员
		m_B = 100; //父类中保护成员 到子类中变为 私有成员
		//m_C = 100; //父类中私有成员，子类访问不到
	}
};

class grandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 1000; //到了Son3中 m_A变为私有，即使是儿子，也访问不到
		//m_B = 1000; //到了Son3中 m_A变为私有，即使是儿子，也访问不到
	}
};

int main()
{

	test01();

	system("pause");
	return 0;
}
```



#### 4.6.3 继承中的对象模型



**问题：**从父类继承过来的成员，哪些属于子类对象中？



**示例：**

```c++
#include <iostream>
using namespace std;

//继承中的对象模型

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

//利用开发人员命令提示工具(Developer Command Prompt for VS 2022)查看对象模型	(开始菜单可以找到)
//跳转盘符	f:
//跳转文件路径	cd	具体路径下	E:\c.---c.---java-exercise\cppCode\对象的初始化和清理
//查看命名
// cl(这是爱楼) /d1(这是一)  reportSingleClassLayou类名 文件名	||->	cl /d1 reportSingleClassLayoutSon 继承中的对象模型.cpp

void test01()
{
	//16
	//父类中所有的非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器给隐藏了，因此访问不到，但是被继承下去了
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



![屏幕截图 2023-07-23 175919](E:\c.---c.---java-exercise\photo\屏幕截图 2023-07-23 175919.png)



> 结论：父类中的私有成员也是被子类继承下去了，只是由编译器给隐藏后 访问不到



#### 4.6.4 继承中构造和析构顺序



子类继承父类后，当创建子类对象，也会调用父类的构造函数



问题：父类和子类的构造和析构顺序是谁先谁后？



**示例：**

```c++
#include <iostream>
using namespace std;

//继承中的构造和析构顺序
class Base
{
public:
	Base()
	{
		cout << "Base的构造函数！" << endl;
	}
	~Base()
	{
		cout << "Base的析构函数！" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son的构造函数！" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数！" << endl;
	}
};

void test01()
{
	//Base b;

	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反	类似栈
	Son s;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



> 总结：继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反



#### 4.6.5 继承同名成员处理方式



问题：当子类和父类出现同名成员，如何通过子类成员，访问到子类或父类中的同名数据呢？



- 访问子类同名成员 直接访问即可
- 访问父类同名成员 需要加作用域   例如：**`s.Base::m_A`**（s为子类对象，Base为父类，m_A为父类成员）   父类同名函数调用同理**`s.Base::func()`**



**示例：**

```c++
#include <iostream>
using namespace std;

//继承同名成员处理方式
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base - func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}
	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
	int m_A;
};

//同名属性的处理方式
void test01()
{
	Son s;
	cout << "m_A = " << s.m_A << endl;
	//如果通过子类对象，访问到父类中的同名成员，需要加作用域
	cout << "s.Base::m_A = " << s.Base::m_A << endl;
}

//同名成员函数处理方式
void test02()
{
	Son s;
	s.func(); //直接调用 调用的是子类中的同名成员

	//如何调用到父类中同名成员函数
	s.Base::func();

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.Base::func(100);
}

int main()
{

	//test01();
	test02();

	system("pause");
	return 0;
}
```



总结：

1. 子类对象可以直接访问到子类中的同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类与父类拥有同名的成名函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数



#### 4.6.6 继承同名静态成员处理方式



问题：继承中同名的静态成员在子类对象上如何进行访问？



静态成员和非静态成员出现同名，处理方式一致



- 访问子类同名成员 直接访问即可
- 访问父类同名成员 需要加作用域



**示例：**

```c++
#include <iostream>
using namespace std;

//继承中同名静态成员处理方式

class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;

class Son :public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
};
int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	//1.通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	cout << "Son 下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//2.通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son 下 m_A = " << Son::m_A << endl;
	cout << "Base 下 m_A = " << Base::m_A << endl;
	//或者	第一个::代表通过类名的方式访问  第二个::表示访问父类作用域下
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

//同名静态成员函数
void test02()
{
	//1.通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问：" << endl;
	Son::func();
	Base::func();
	Son::Base::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类中所有的同名成员函数
	//如果想访问父类中被隐藏的同名成员，需要加作用域
	Son::Base::func(100);
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}
```



> 总结：同名静态成员处理方式和非静态成员处理方式一样，只不过有两种访问方式（通过对象 和 通过类名）



#### 4.6.7 多继承语法



C++允许**一个类继承多个类**



语法：`class 子类 : 继承方式 父类1 ， 继承方式 父类2 1...`



多继承可能会引发父类中有同名成员出现，需要加作用域区分



**C++实际开发中不建议用多继承**



**示例：**

```c++
#include <iostream>
using namespace std;

//多继承语法

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};

//子类 需要继承Base1和Base2
//语法：class 子类 ， 继承方式 父类1，继承方式 父类2 ...
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test01()
{
	Son s;

	cout << "sizeof Son = " << sizeof(s) << endl;
	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1::m_A = " << s.Base1::m_A << endl;
	cout << "Base2::m_A = " << s.Base2::m_A << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



> 总结：多继承中如果父类中出现了同名情况，子类使用时候要加作用域



#### 4.6.8 菱形继承



**菱形继承概念：**

两个派生类继承同一个基类

又有某个类同时继承着两个派生类

这种继承称为菱形继承，或者钻石继承



**典型的菱形继承案例：**

![屏幕截图 2023-07-24 162031](E:\c.---c.---java-exercise\photo\屏幕截图 2023-07-24 162031.png)



**菱形继承问题：**

1. 羊继承了动物的数据，驴同样继承了动物的数据，当草泥马使用数据时，就会产生二义性
2. 草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以



**示例：**

```c++
#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字 virtual 变为虚继承
//通过使用虚继承，可以确保在多重继承中，通过不同路径继承同一个基类的派生类只会存在一个共享的基类子对象
//换句话说，虚继承能够消除由于多重继承导致的 数据重复（只保存一份数据） 以及 二义性问题
//虚继承 只是继承了指针 指针通过偏移量去找到唯一的一份数据
//Animal类称为 虚基类

//羊类
class Sheep :virtual public Animal{};

//驼类
class Tuo :virtual public Animal{};

//羊驼类
class sheepTuo :public Sheep, public Tuo{};

void test01()
{
	sheepTuo st;

	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age<< endl;

	cout << "st.m_Age = "<< st.m_Age << endl;

	//这份数据我们知道 只有一份就可以，菱形继承导致数据有两份，资源浪费
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



总结：

- 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
- 利用虚继承可以解决菱形继承问题



### 4.7 多态

#### 4.7.1 多态的基本概念



**多态是C++面向对象三大特性之一**

多态分为两类

- 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：

- 静态多态的函数地址早绑定 - 编译阶段确定函数地址
- 动态多态的函数地址晚绑定 - 运行阶段确定函数地址



下面通过案例进行讲解多态

```c++
#include <iostream>
using namespace std;

//多态

//动物类
class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	//重写是	函数返回值类型	函数名	参数列表	完全相同
	void speak() //这里就是子类重写父类虚函数
	{
		cout << "小猫在说话" << endl;
	}
};

//狗类
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定	在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

//动态多态的满足条件
//1.有继承关系
//2.子类重写父类的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象

void doSpeak(Animal& animal) //Animal & animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main()
{

	test01();

	system("pause");
	return 0;
}
```



总结：

多态满足条件：

- 有继承关系
- 子类重写父类中的虚函数

多态使用条件：

- 父类指针或引用指向子类对象

重写：函数返回值类型  函数名  参数列表  完全一致称为重写

![屏幕截图 2023-07-26 022807](E:\c.---c.---java-exercise\photo\屏幕截图 2023-07-26 022807.png)



#### 4.7.2 多态案例一 - 计算机类



案例描述：

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算机类



多态的优点：

- 代码组织结构清晰
- 可读性强
- 利于前期和后期的拓展以及维护



**示例：**

```c++
#include <iostream>
using namespace std;

//分别利用普通写法和多态技术实现计算器

//普通写法
class Calculator
{
public:
	int m_Num1; //操作数1
	int m_Num2; //操作数2

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}
	//如果想拓展新的功能，需要修改源码
	//在真实的开发中，提倡 开闭原则
	//开闭原则：对拓展进行开放，对修改进行关闭
};


//利用多态实现计算器

//多态好处：
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期的拓展和维护性高


//实现计算器的抽象类
class abstractCalculator //abstract(抽象)Calculator(计算器)
{
public:
	int m_Num1;
	int m_Num2;

	virtual int getResult()
	{
		return 0;
	}
};

//加法计算器类
class addCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class subCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class mulCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test01()
{
	//创建计算器对象
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;

	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}

void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象


	//加法运算
	abstractCalculator* abc = new addCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;


	//减法运算
	abc = new subCalculator; //刚才销毁的是堆区的数据，指针的类型还没有变
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;


	//乘法运算
	abc = new mulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;

	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
}

int main()
{

	//test01();

	test02();

	system("pause");
	return 0;
}
```

> 总结：C++开发提倡利用多态设计程序架构，因为多态优点很多



#### 4.7.3 纯虚函数和抽象类



在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容



因此可以将函数改为**纯虚函数**



纯虚函数语法：**`virtual 返回值类型 函数名 （参数列表） = 0`**



当类中有了纯虚函数，这个类也称为==抽象类==



**抽象类特点：**

- 无法实例化对象
- 子类必须重写抽象类中的纯虚函数，否则也属于抽象类



**示例：**

```c++

```
