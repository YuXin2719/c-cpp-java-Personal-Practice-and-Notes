# C++基础入门

## 一、C++初识

### 1.1 第一个C++程序

- 创建项目
- 创建文件
- 编写代码
- 运行程序

#### 1.1.1 创建项目

#### 1.1.2 创建文件

#### 1.1.3 编写代码

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{

	cout << "Hello World" << endl;

	system("pause");

	return 0;
}
```

#### 1.1.4 运行程序



### 1.2 注释

**作用：**在代码中加一些说明和解释，方便自己或其他程序员阅读代码

**两种格式**

1. 单行注释：**`// 描述信息`**
2. 多行注释： **`/* 描述信息 */`**



### 1.3 变量

**作用：**给一段制定的内存空间起名，方便操作这段内存，管理内存空间

**语法：`数据类型 变量名 = 初始值；`**

**示例：**

```c++
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{

	int a = 10;

	cout << "a = " << a << endl;

	system("pause");

	return 0;
}
```



### 1.4 常量

**作用：**用于记录程序中不可更改的数据

C++定义常量**两种**方式

1. **#define** 宏常量：`#define 常量名 常量值`
   - ​	==通常在文件上方定义==，表示一个常量
2. **const** 修饰的变量：`const 数据类型 常量名 = 常量值`
   - ​	==通常在变量定义前加关键字const==，修饰该变量为常量，不可修改

**示例**：

```c++
#include <iostream>
#define day 7 //1.#define 宏常量

using namespace std;

int main()
{

	cout << "一周共有" << day << "天" << endl;
	//day = 8;  会报错，不可修改

	//2.const修饰的变量
	const int month = 12;
	//month = 13; 报错，不可修改

	cout << "一年共有" << month << "月" << endl;

	system("pause");

	return 0;
}
```



### 1.5 关键字

**作用：**关键字是C++中预先保留的单词（标识符）

- ​	**在定义变量或者常量时，不要用关键字**



C++关键字如下：

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | esport       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

**`提示：在给变量或者常量起名的时候，不要用c++的关键字，否则或产生歧义`**



### 1.6 标识符命名规则

**作用：**C++规定给标识符（变量、常量）命名时，有一套自己的规则

- 标识符不能是关键字
- 标识符只能由**字母**，数字，**下划线**组成  ->  abc123_
- **第一个字符**必须是**字母**或者**下划线**
- 标识符中字母分大小写

> 建议：给标识符命名时，争取见名知义，方便阅读



## 二、数据类型

C++规定在创建一个变量或常量时，必须要指定出相应的数据类型，否则无法给变量分配内存

### 2.1 整型

**作用：**整型变量表示的是==整数类型==的数据

C++中能够表示整型的类型有以下几种方式，**区别在于所占的内存空间不同**

| 数据类型              | 占用空间                                             | 取值范围         |
| --------------------- | ---------------------------------------------------- | ---------------- |
| short（短整型）       | 2字节                                                | (-2^15 ~ 2^15-1) |
| int（整型）           | 4字节                                                | (-2^31 ~ 2^31-1) |
| long（长整型）        | Windows为四字节，Linux为4字节（32位），8字节（64位） | (-2^31 ~ 2^31-1) |
| long long（长长整型） | 8字节                                                | (-2^63 ~ 2^63-1) |

```c++
#include <iostream>

using namespace std;

int main()
{

	//整型 （int较常用）
	// 
	//1、短整型（-32768 ~ 32767）
	short num1 = 32768; //结果是-32768，循环回来了

	//2、整型 （...~...）
	int num2 = 10;

	//3、长整型 （...~...）
	long num3 = 10;

	//4、长长整型 （...~...）
	long long num4 = 10;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	return 0;
}
```



### 2.2 sizeof关键字

**作用：**利用sizeof关键字可以统计数据类型所占内存大小

**语法：**`sizeof（ 数据类型 /变量 ）`

**示例：**

```c++
#include <iostream>

using namespace std;

int main() {

    //sizeof可以求出数据类型占用内存的大小
    //语法：sizeof（ 数据类型 / 变量 ）
    
	cout << "short 类型所占内存空间为：" << sizeof(short) << endl;//2

	cout << "int 类型所占内存空间为：" << sizeof(int) << endl;//4

	cout << "long 类型所占内存空间为：" << sizeof(long) << endl;//4

	cout << "long long 类型所占内存空间为：" << sizeof(long) << endl;//8

    //整型大小比较
    // short < int <= long <= long long
    
	return 0;
}
```



### 实型（浮点型）

**作用：**用于==表示小数==

浮点型变量分两种：

1. 单精度 float
2. 双精度 double

两者区别在于表示的有效数字范围不同：

| 数据类型 | 占用空间 | 有效数字范围    |
| -------- | -------- | --------------- |
| float    | 4字节    | 7位有效数字     |
| double   | 8字节    | 15~16位有效数字 |

**示例：**

```c++
#include <iostream>

using namespace std;

int main() {

	//1.单精度 float
	//2.双精度 double
	//默认情况下，输出一个小数，会显示出六位有效数字，五位小数

	float f1 = 3.141592653f;
	double d2 = 3.14;

	cout << "f1 = " << f1 << endl;
	cout << "d2 = " << d2 << endl;

	//统计float和double占用内存空间
	//	float 4
	//	double 8

	cout << "float占用的内存空间为" << sizeof(float) << endl;
	cout << "double占用的内存空间为" << sizeof(double) << endl;

	//科学计数法
	float f2 = 3e2; //3 * 10 ^ 2
	cout << "f2 = " << f2 << endl; //300

	float f3 = 3e-2; //3 * 0.1 ^ 2
	cout << "f3 = " << f3 << endl; //0.03

	system("pause");

	return 0;
}
```



### 2.4 字符型

**作用：**字符型变量用于显示单个字符

**语法：**`char ch = 'a';`



> 注意1：在显示字符型变量时，用单引号将字符括起来，不用双引号
>
> 注意2：单引号只能有一个字符，不可以是字符串



- C和C++中字符型变量只占用==一个字节==

- 字符型变量并不是把字符本身放在内存中存储，而是将对应的ASCII编码放入到存储单元

  

**示例：**

```c++
#include <iostream>

using namespace std;

int main() {

	//1.字符型变量创建方式
	char ch = 'a';
	cout << ch << endl;

	//2.字符型变量所占内存大小
	cout << "字符型变量占用内存:" << sizeof(ch) << endl; //1

	//3.字符型变量常见错误
	//char ch2 = "b";  用单引号
	//char ch2 = 'abc';  数量过多

	//4.字符型变量对应ASCII编码
	//a - 97
	//A - 65
	cout << (int)ch << endl; //97 就是 a 对应的ASCII码

	system("pause");
	return 0;
}
```

[ASCII码对照表 —在线工具 (sojson.com)](https://www.sojson.com/asciitable.html)

ASCII 码大致由以下**两部分**组成：

- ASCII 非打印字符：ASCII表上的数字 **0-31** 分配给了控制字符，用于控制像打印机等一些外围设备
- ASCII 打印字符：数字 **32-126** 分配给了能在键盘上找到的字符，当查看或打印文档时就会出现



### 2.5 转移字符

**作用：**用于表示一些==不能显示出来的ASCII字符==

现阶段我们常用的转义字符有：`\n \\ \t`

| 转义字符 | 含义                    | ASCII码 |
| -------- | ----------------------- | ------- |
| \a       | 响铃7                   | 7       |
| \b       | 退格                    | 8       |
| \f       | 换页                    | 12      |
| **\n**   | **换行**                | **10**  |
| \r       | 回车                    | 13      |
| **\t**   | **横向制表符**          | **9**   |
| \v       | 纵向制表符              | 11      |
| \\       | 反斜杠                  | 92      |
| \'       | 单引号                  | 39      |
| \"       | 双引号                  | 34      |
| \?       | 问号                    | 63      |
| \0       | 空字符                  | 0       |
| **\\\\** | **代表一个反斜线\'\\'** | **92**  |

```c++
#include <iostream>

using namespace std;

int main() {

	//转义字符

	//换行符 \n

	cout << "hello world\n" << endl;

	//反斜杠 \\
	
	cout << "\\" << endl;
	
	//水平制表符 \t
	//作用：可以整齐地输出数据

	cout << "a\thello" << endl;
	cout << "aaaaa\thello" << endl;

	system("pause");
	return 0;
}
```



### 2.6 字符串型

**作用：**用于表示一串字符

**两种风格**

1. ​	**C风格字符串：`char 变量名[] = "字符串值"`**

   示例：

   ```c++
   #include <iostream>
   
   using namespace std;
   
   int main()
   {
   
   	char ch[] = "Hello World";
   
   	cout << ch << endl;
   
   	return 0;
   }
   ```

   > 注意：C风格的字符串要用双引号括起来
   >
   > ​			char 字符串名 []

2. **C++风格字符串：`string 变量名 = "字符串值"`**

   示例：

   ```c++
   #include <iostream>
   #include <string>
   
   using namespace std;
   
   int main()
   {
   
   	string ch = "Hello World";
   
   	cout << ch << endl;
   
   	return 0;
   }
   ```

   > 注意：需要包含一个头文件 **`#include <string>`**  vs2022貌似不用



### 2.7 布尔数据类型

**作用：**布尔数据类型代表真和假的值

bool 类型只有两个值：

- true --- 真（本质是1）(非0的其实都为真)

- false --- 假（本质是0）

  **bool类型占==1个字节==大小**

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.创建bool数据类型
	bool flag = true; //true代表真
	cout << flag << endl;

	bool flag2 = false; //假
	cout << flag2 << endl;

	//本质上  1代表真  0代表假

	//2.查看bool类型所占内存空间
	cout << "bool类型所占的内存空间：" << sizeof(bool) << endl; //1

	return 0;
}
```



### 2.8 数据的输入



**作用：用于从键盘获取数据**

**关键字：**cin

**语法：` cin >> 变量`**



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.整型
	//int a = 0;
	//cout << "请给整型变量a赋值：" << endl;
	//cin >> a;
	//cout << "整型变量a = " << a << endl;

	//2.浮点型
	//float b = 3.14f;
	//cout << "请给浮点型变量b赋值：" << endl;
	//cin >> b;
	//cout << "浮点型变量b = " << b << endl;

	//3.字符型
	//char ch = 'a';
	//cout << "请给字符型变量ch赋值：" << endl;
	//cin >> ch;
	//cout << "字符型变量ch = "<< ch << endl;

	//4.字符串型
	//string str = "hello";
	//cout << "请给字符串型变量str赋值：" << endl;
	//cin >> str;
	//cout << "字符串变量str = " << str << endl;

	//5.布尔类型（非0的值都为真）
	bool flag = false;
	cout << "请给布尔类型的flag赋值：" << endl;
	cin >> flag;
	cout << "布尔类型的flag为" << flag << endl;

	return 0;
}
```



## 三、运算符

**作用：**用于执行代码的运算

本章我们主要讲解一下几类运算符

| 运算符类型 | 作用                                     |
| ---------- | ---------------------------------------- |
| 算术运算符 | 用于四则运算                             |
| 赋值运算符 | 用于将表达式的值赋给变量                 |
| 比较运算符 | 用于表达式的比较，并返回一个真值或者假值 |
| 逻辑运算符 | 用于根据表达式的值返回真值或者假值       |



### 3.1 算数运算符

**作用：**用于四则运算

算数运算符包括以下符号：

| 运算符 | 术语         | 示例       | 结果     |
| ------ | ------------ | ---------- | -------- |
| +      | 正号         | +3         | 3        |
| -      | 负号         | -3         | -3       |
| +      | 加           | 10+5       | 15       |
| -      | 减           | 10-5       | 5        |
| *      | 乘           | 10*5       | 50       |
| /      | 除           | 10/5       | 2        |
| %      | 取模（取余） | 10%3       | 1        |
| ++     | 前置递增     | a=2;b=++a; | a=3;b=3; |
| ++     | 后置递增     | a=2;b=a++; | a=3;b=2; |
| --     | 前置递减     | a=2;b=--a; | a=1;b=1; |
| --     | 后置递减     | a=2;b=a--; | a=1;b=2; |

**加减乘除代码示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//加减乘除
	int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl; //两个整数相除，结果依然是整数，将小数部分去除

	double f1 = 10;
	double f2 = 3;
	cout << f1 / f2 << endl; //这样结果就有小数

	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl; //0

	//int a3 = 10;
	//int b3 = 0; //除数不能为0
	//cout << a3 / b3 << endl;  非法操作

	system("pause");

	return 0;
}
```

**取模运算示例：**

> 注意：两个小数是不可以做取模运算的

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//取模运算本质
	int a1 = 10;
	int b1 = 3;

	cout << a1 % b1 << endl; //1

	int a2 = 10;
	int b2 = 20;
	cout << a2 % b2 << endl; //10

	//int a3 = 10;
	//int b3 = 0;
	//cout << a3 % b3 << endl;  非法

	//两个小数是不可以做取模运算的
	//double d1 = 3.14;
	//double d2 = 1.1;
	//cout << d1 % d2 << endl;

	system("pause");

	return 0;
}
```

**递增递减示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.前置递增
	int a = 10;
	++a; //让变量进行+1的操作
	cout << "a = " << a << endl;

	//2.后置递增
	int b = 10;
	b++; //让变量进行+1的操作
	cout << "b = " << b << endl;

	//3.前置和后置的区别
	//前置递增，先让变量+1，然后进行表达式运算

	int a2 = 10;
	int b2 = ++a2 * 10;

	cout << "a2 = " << a2 << endl << "b2 = " << b2 << endl; //a2=11,b2=110

	//后置递增，先进行表达式运算，然后变量+1

	int a3 = 10;
	int b3 = a3++ * 10;

	cout << "a3 = " << a3 << endl << "b3 = " << b3 << endl; //a3=11,b3=100

	system("pause");

	return 0;
}
```



### 3.2 赋值运算符

**作用：**用于将表达式的值赋给变量

赋值运算符包括以下几种符号：

| 运算符 | 术语   | 示例      | 结果     |
| ------ | ------ | --------- | -------- |
| =      | 赋值   | a=2;b=3;  | a=2;b=3; |
| +=     | 加等于 | a=0;a+=2; | a=2;     |
| -=     | 减等于 | a=5;a-=3; | a=2;     |
| *=     | 乘等于 | a=2;a*2;  | a=4;     |
| /=     | 除等于 | a=4;a/=2; | a=2;     |
| %=     | 模等于 | a=3;a%2;  | a=1;     |

> 注：a+=2 就是 a=a+2 其他同理

**简略示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a = 10;
	a += 2;
	cout << "a = " << a << endl; //12

	system("pause");

	return 0;
}
```



### 3.3 比较运算符

**作用：**用于表达式的比较，并返回一个真值或假值（用于判断！）

比较运算符有以下符号：

| 运算符 | 术语     | 示例   | 结果 |
| ------ | -------- | ------ | ---- |
| ==     | 相等于   | 4 == 3 | 0    |
| !=     | 不相等   | 4 != 3 | 1    |
| <      | 小于     | 4 < 3  | 0    |
| >      | 大于     | 4 > 3  | 1    |
| <=     | 小于等于 | 4 <= 3 | 0    |
| >=     | 大于等于 | 4>= 1  | 1    |

**简略示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	bool bo = true;
	bo = 4 == 3;
	cout << bo << endl; //0

	//比较运算符
	//==
	int a = 10;
	int b = 20;
	cout << (a == b) << endl; //0 加()是先运算a == b再运算endl

	//!=
	cout << (a != b) << endl; //1

	//...

	system("pause");

	return 0;
}
```



### 3.4 逻辑运算符

**作用：**用于根据表达式的值返回真值或假值

逻辑运算符有以下符号：

| 运算符 | 术语 | 示例   | 结果                                                   |
| ------ | ---- | ------ | ------------------------------------------------------ |
| !      | 非   | !a     | 如果a为假，则!a为真；如果a为真，则!a为假               |
| &&     | 与   | a&&b   | 如果a和b都为真，则结果为真，否则为假                   |
| \|\|   | 或   | a\|\|b | 如果a和b有一个为真，则结果为真，二者都为假时，结果为假 |

**示例1：**逻辑非

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//逻辑运算符 非 !
	int a = 10;

	cout << !a << endl; //0
	cout << !!a << endl; //1

	system("pause");

	return 0;
}
```

> 总结：==真变假，假变真==

**示例2：**逻辑与

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//逻辑运算符 与 &&
	
	int a = 10;
	int b = 10;
	cout << (a && b) << endl; //1

	int c = 10;
	int d = 0;
	cout << (c && d) << endl; //0

	int e = 0;
	int f = 0;
	cout << (e && f) << endl; //0

	system("pause");

	return 0;
}
```

> 总结：==都真为真，其余为假==

**示例3：**逻辑或

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//逻辑运算符 或 ||

	int a = 10;
	int b = 10;
	cout << (a || b) << endl;

	int c = 10;
	int d = 0;
	cout << (c || d) << endl;

	int e = 0;
	int f = 0;
	cout << (e || f) << endl;

	system("pause");

	return 0;
}
```

> 总结：==都假为假，其余为真==



## 四、程序流程结构

C/C++支持最基本的三种程序运行结构：==顺序结构==、==选择结构==、==循环结构==

- 顺序结构：程序按顺序执行，不发生跳转
- 选择结构：依据条件是否满足，有选择的执行相应的功能
- 循环结构：依据条件是否满足，循环多次执行某段代码



### 4.1 选择语句

#### 4.1.1 if语句

**作用：**执行满足条件的语句

if语句的三种形式

- 单行格式if语句
- 多行格式if语句
- 多条件的if语句



1.单行格式的if语句：**`if(条件){条件满足的语句}`**

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-04 182131.png" alt="屏幕截图 2023-05-04 182131" style="zoom: 50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a = 0;
	cout << "请输入你的分数：";
	cin >> a;

	if (a > 503) //这里不能有分号
	{
		cout << "你能考上一所一本大学" << endl;
	}

	system("pause");

	return 0;
}
```



2.多行格式if语句：**`if(条件){条件满足的语句}else{条件不能满足的语句};`**

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-04 183531.png" alt="屏幕截图 2023-05-04 183531" style="zoom:50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a = 0;
	cout << "请输入你的分数：";
	cin >> a;

	if (a >= 503) //这里不能有分号
	{
		cout << "你能考上一所一本大学" << endl;
	}
	else
	{
		cout << "你不能考上一本大学" << endl;
	}


	system("pause");

	return 0;
}
```



3.多条件的if语句：**`if(条件1){条件1满足执行的语句} else if(条件2){条件2满足执行的语句}... else{都不满足执行的语句}`**

![屏幕截图 2023-05-04 211605](E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-04 211605.png)

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a = 0;
	cout << "请输入你的分数：";
	cin >> a;

	if (a>=0&&a<446) //这里不能有分号
	{
		cout << "你啥也考不上，去专科吧" << endl;
	}
	else if(a>=446&&a<503)
	{
		cout << "你能考上二本大学" << endl;
	}
	else if(a>=503&&a<700)
	{
		cout << "一本啊一本" << endl;
	}
	else if(a>=700&&a<=750)
	{
		cout << "你牛逼" << endl;
	}
	else
	{
		cout << "啥？" << endl;
	}

	system("pause");

	return 0;
}
```

> 注意 与&& 或|| 符号的运用



**嵌套if语句：**在if语句中，可以嵌套使用if语句，达到更精确的条件判断

案例需求：

- 提示用户输入一个高考考试分数，根据分数做如下判断
- 分数如果大于600分视为考上一本，大于500分考上二本，大于400分考上三本，其余视为未考上本科
- 在一本分数中，如果大于700分，考入北大，大于650，考入清华，大于600考入人大

示例：

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

/*
要求：
	- 提示用户输入一个高考考试分数，根据分数做如下判断
	- 分数如果大于600分视为考上一本，大于500分考上二本，大于400分考上三本，其余视为未考上本科
	- 在一本分数中，如果大于700分，考入北大，大于650，考入清华，大于600，考入人大
*/

	//输入分数
	int fen = 0;
	cout << "请输入你的分数：" << endl;
	cin >> fen;
	cout << "你输入的分数为 " << fen << endl;

	//判断一本600
	if (fen > 600)
	{
		cout << "恭喜你可以考上一本" << endl;

		//判断北大
		if (fen > 700)
		{
			cout << "恭喜你可以考上北大！" << endl;
		}

		//判断清华
		else if (fen > 650)
		{
			cout << "恭喜你可以考上清华！" << endl;
		}

		//判断人大
		else if (fen > 600)
		{
			cout << "恭喜你可以考上人大！" << endl;
		}
	}

	//判断二本500
	else if (fen > 500)
	{
		cout << "恭喜你可以考上二本" << endl;
	}

	//判断三本400
	else if (fen > 400)
	{
		cout << "恭喜你可以考上二本" << endl;
	}
	else
	{
		cout << "你啥jb也没考上兄弟" << endl;
	}

	system("pause");

	return 0;
}
```



#### if语句练习案例：三只小猪称体重

有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 131212.png" alt="屏幕截图 2023-05-05 131212" style="zoom:50%;" />

```c++
#include <string>
#include <iostream>

using namespace std;

int main()
{

	//有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
	
	//1.输入三只小猪的体重
	int arr[3] = {0};

	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "只小猪的体重：" << endl;
		cin >> arr[i];
		cout << "您输入的第" << i + 1 << "个小猪的体重为：" << arr[i] << endl;
	}

	//2.判断三只小猪哪只最重
	int max = arr[0];
	for (i = 1; i < 3; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (arr[i] == max)
		{
			cout << "第" << i + 1 << "只小猪最重，它的体重为" << arr[i] << endl;
		}
	}

	system("pause");
	return 0;
}
```



#### 4.1.2 三目运算符

**作用：**通过三目运算符实现简单的判断

**语法：`表达式1 ? 表达式2 : 表达式3`**

**解释：**

如果表达式1为真，执行表达式2，并返回表达式2的结果

如果表达式1为假，执行表达式3，并返回表达式3的结果

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//三目运算符
	//创建三个变量 abc
	//将a和b比较，将变量大的值赋给c
	int a = 10;
	int b = 20;
	int c = 0;

	c = (a > b ? a : b);

	cout << "max1 = " <<c << endl;

	//在C++中三目运算符返回的是变量，可以继续赋值
	(a < b ? a : b) = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
```



#### 4.1.3 switch语句

**作用：**执行多条件的分支语句

**语法：**

```c++
switch(表达式)
{
        
    case 结果1:执行语句;break;
    
    case 结果2:执行语句;break;
        
    ...
        
    default:执行语句;break;
    
}
```

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//switch语句
	//给一个电影打分
	//10~9	经典
	//8~7	非常好
	//6~5	一般
	//5以下	烂

	//1.提示用户评分
	cout << "请给电影打分：" << endl;

	//2.用户开始打分
	int score = 0;
	cin >> score;
	cout << "您打出的分数为：" << score << endl;

	//3.根据用户输入的分数提示用户最后的结果
	switch (score)
	{
	case 10:
		cout << "您认为是经典电影" << endl;
		break;
	case 9:
		cout << "您认为是经典电影" << endl;
		break;
	case 8:
		cout << "您认为是非常好电影" << endl;
		break;
	case 7:
		cout << "您认为是非常好电影" << endl;
		break;
	case 6:
		cout << "您认为是一般电影" << endl;
		break;
	case 5:
		cout << "您认为是一般电影" << endl;
		break;
	default:
		cout << "您认为是垃圾电影" << endl;
		break;
	}

	//if 和 switch 区别？
	//switch 缺点，判断只能是整型或者字符型，不可以是一个区间
	//switch 优点，结构清晰，执行效率高

	system("pause");
	return 0;
}
```

> switch优缺点：
>
> 1. ==缺点==：判断只能是整型或者字符型，==不可以是一个区间==
> 2. ==优点==：结构清晰，==执行效率高==



### 4.2 循环结构

#### 4.2.1 while循环语句

**作用：**满足循环条件，执行循环语句

**语法：`while(循环条件){循环语句}`**

**解释：**只要循环条件为真，就执行语句

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 155135.png" alt="屏幕截图 2023-05-05 155135" style="zoom:50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//while循环
	//在屏幕中打印 0~9 这十个数字
	int num = 0;
	while (num < 10)
	{
		cout << num << endl;
		num++;
	}

	system("pause");
	return 0;
}
```

> 注意：记得提供挑出循环的出口，否则会出现死循环



**while循环练习案例：==猜数字==**

**案例描述：**系统随机生成一个1-100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或者过小，如果猜对恭喜玩家胜利，并且退出游戏

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20230505161450687.png" alt="image-20230505161450687" style="zoom:50%;" />

流程图：

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20230505161804461.png" alt="image-20230505161804461" style="zoom:50%;" />



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.系统生成随机数
	int num = rand() % 100 + 1;	//生成 0 + 1 ~ 99 + 1 的随机数

	cout << "随机数 = " << num << endl;  //可屏蔽，这里做示范

	//2.玩家进行猜测
	int val = 0;
	
	//3.判断玩家的猜测
	while (1)
	{
		cin >> val;

		if (val < num)
		{
			cout << "你输入的数字小了，请重新输入" << endl;
		}
		else if (val > num)
		{
			cout << "你输入的数字大了，请重新输入" << endl;
		}
		else
		{
			cout << "对溜！" << endl;
			break;
		}
	}
	//猜错	提示猜的结果	过大或者过小
	//猜对	恭喜

	system("pause");
	return 0;
}
```

**注：添加随机数种子（小方法）**

```c++
#include <iostream>
#include <string>
//time系统时间头文件包含
#include <ctime>

using namespace std;

int main()
{

	//添加随机数种子，作用利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));

	int num = rand() % 100;

	cout << "随机数：" << num << endl;

	system("pause");
	return 0;
}
```



#### 4.2.2 do...while循环语句

**作用：**满足循环条件，执行循环语句

**语法：`do{循环语句}while(循环条件);`**

**注意：**与while的区别在于==do...while会先执行一次循环语句==，再判断循环条件

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20230505170946144.png" alt="image-20230505170946144" style="zoom:50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//do...while语句
	//在屏幕中输出 0 到 9 这十个数字

	int num = 0;

	do
	{
		cout << num << endl;
		num++;
	}
	while (num < 10);

	//do...while和while循环的区别在于do...while会先执行一次循环语句

	system("pause");
	return 0;
}
```

> 总结：do...while和while循环的区别在于do...while会先执行一次循环语句



**练习案例：水仙花数**

**案例描述：**水仙花是指一个三位数，它的每个位上的数字的三次幂之和等于它本身

例如：1^3 + 5^3 + 3^3 = 153

请用do...while语句，求出所有三位数中的水仙花数

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

/*
案例描述：水仙花是指一个三位数，它的每个位上的数字的三次幂之和等于它本身

例如：1^3 + 5^3 + 3^3 = 153

请用do...while语句，求出所有三位数中的水仙花数
*/

int main()
{

	double num = 100;
	int bai = 0, shi = 0, ge = 0;


	do {
		bai = (int)(num * 0.01);
		shi = (int)((num-bai*100) * 0.1);
		ge = (int)(num - bai * 100 - shi * 10);
		if ((bai * bai * bai + shi * shi * shi + ge * ge * ge) == num)
		{
			cout << num << "是水仙花数" << endl;
		}
		num++;
	} while (num < 1000);

	system("pause");
	return 0;
}

//或者取余
//ge = num % 10;
//shi = num / 10 % 10;
//bai = num / 100;
```



#### 4.2.3 for循环语句

**作用：**满足循环条件，执行循环语句

**语法：`for(起始表达式;条件表达式;末尾循环体)`**



**示例:**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int i = 0;
	
	for (i = 0; i < 10; i++) //或者在内部定义i for (int i = 0 ; i < 10 ; i++)
	{
		cout << i << endl;
	}

	system("pause");
	return 0;
}


//for循环可拆分为以下形式

//int i = 0;
//for ( ; ; )
//{
//	if (i >= 10)
//	{
//		break;
//	}
//	i++;
//}
```

**详解：**

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20230505181237337.png" alt="image-20230505181237337" style="zoom:50%;" />

> 注意：for循环中的表达式，要用分号进行分隔

> 总结：while,do...while,for都是开发中常用的循环语句，for循环结构比较清晰，比较常用



**练习案例：敲桌子**

案例描述：从1开始数到数字100，如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出

<img src="E:\c.---c.---java-exercise\photo\c6d7ce76d327e87a.gif" alt="c6d7ce76d327e87a"  />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}
```



#### 4.2.4 嵌套循环

**作用：**在循环体中再嵌套一层循环，解决一些实际问题

例如我们想在屏幕中打印如下图片，就需要利用嵌套循环

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20230505182827121.png" alt="image-20230505182827121" style="zoom: 50%;" />

