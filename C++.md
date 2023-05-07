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

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 161445.png" alt="屏幕截图 2023-05-05 161445" style="zoom:50%;" />

流程图：

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 161751.png" alt="屏幕截图 2023-05-05 161751" style="zoom:50%;" />



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

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 170940.png" alt="屏幕截图 2023-05-05 170940" style="zoom:50%;" />

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

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 181224.png" alt="屏幕截图 2023-05-05 181224" style="zoom:50%;" />

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

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-05 182822.png" alt="屏幕截图 2023-05-05 182822" style="zoom:50%;" />



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//利用嵌套循环实现星图

	//打印一行星图

	//外层循环
	for (int i = 0; i < 10; i++)
	{
		//内层循环
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
```



**练习案例：乘法口诀表**

案例描述：利用嵌套循环，实现九九乘法表

<img src="E:\c.---c.---java-exercise\photo\669bc2f8c200491583e3e4088506f3a1.jpeg" alt="669bc2f8c200491583e3e4088506f3a1" style="zoom: 67%;" />



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//九九乘法表
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (j <= i)
			{
				cout << i << " * " << j << " = " << i * j << "\t";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
```



### 4.3 跳转语句

#### 4.3.1 break语句

**作用：**用于跳出==选择结构==或者==循环结构==

break使用的时机：

- 出现在switch条件语句中，作用是终止case并跳出switch
- 出现在循环语句中，作用是跳出当前的循环语句
- 出现在嵌套循环中，跳出最近的内层循环语句

**示例1：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//break的使用时机

	//1.出现在switch语句中
	cout << "请选择副本难度" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;
	
	int select = 0; //创建一个选择结果的变量

	cin >> select; //等待用户输入数据

	switch (select)
	{
	case 1:
		cout << "您选择的是普通难度" << endl;
		break;
	case 2:
		cout << "您选择的是中等难度" << endl;
		break;
	case 3:
		cout << "您选择的是困难难度" << endl;
		break;
	default:
		break;
	}

	//2.出现在循环语句中
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;

		//如果i = 5，退出循环，不再打印
		if (i == 5)
		{
			break;
		}
	}

	//3.出现在嵌套循环语句中
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
			if (j == 5)
			{
				break; //退出内层循环
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
```



#### 4.3.2 continue语句

**作用：**在==循环语句==中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//continue语句的用途

	for (int i = 0; i <= 100; i++)
	{
		//如果是奇数输出，偶数不输出
		if (i % 2 == 0)
		{
			continue; //可以筛选条件，执行到此就不再向下执行，执行下一次循环
		}
		cout << i << endl;
	}

	system("pause");
	return 0;
}
```



#### 4.3.3 goto语句

**作用：**可以无条件跳转语句

**语法：`goto 标记；`**

**解释：**如果标记的名称存在的话，执行到goto语句时，会跳转到标记的位置

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 162132.png" alt="屏幕截图 2023-05-06 162132" style="zoom:50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//goto语句

	cout << "1.XXXX" << endl;

	cout << "2.XXXX" << endl;

	goto FLAG;

	cout << "3.XXXX" << endl;

	cout << "4.XXXX" << endl;

	cout << "5.XXXX" << endl;

FLAG:

	cout << "6.XXXX" << endl;

	system("pause");
	return 0;
}
```

==注：不经常用，不建议用==



## 五、数组

### 5.1 概括

所谓数组，就是一个集合，里面存放了相同的数据元素



**特点1：**数组中的每个==数据元素都是相同的数据类型==

**特点2：**数组是由==连续的内存==位置组成的



### 5.2 一维数组

#### 5.2.1 一维数组定义方式

三种方式：

1. **`数据类型 数组名[数组长度];`**
2. **`数据类型 数组名[数组长度] = {值1,值2,...};`**
3. **`数据类型 数组名[] = {值1,值2,...};`**

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	/*
	1. 数据类型 数组名[数组长度];
	2. 数据类型 数组名[数组长度] = {值1,值2,...};
	3. 数据类型 数组名[] = {值1,值2,...};
	*/

	//1.数据类型 数组名[数组长度];
	int arr[5];
	//给数组中的元素进行赋值
	//数组元素的下标是从0开始的
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	//访问数据元素
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;

	//2.数据类型 数组名[数组长度] = {值1,值2,...};
	//如果初始化数据时，没全部填写完，会用0来填补数据
	int arr2[5] = { 10,20,30 };

	cout << arr2[0] << endl;
	cout << arr2[1] << endl;
	cout << arr2[2] << endl;
	cout << arr2[3] << endl;
	cout << arr2[4] << endl;

	//利用循环 输出数组中的元素
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}

	//3.数据类型 数组名[] = { 值1,值2,... };
	//定义数组的时候，必须有初始长度
	int arr3[] = { 90,80,70,60,50,40,30,20,10 };
	for (int j = 0; j < 9; j++)
	{
		cout << arr3[j] << endl;
	}

	system("pause");
	return 0;
}
```



#### 5.2.2 一维数组数组名

一维数组名称的**用途**：

1. 可以统计整个数组在内存中的长度  **`sizeof(arr)`**
2. 可以获取数组在内存中的首地址  **`cout << arr <<endl;`**



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//数组名的用途

	//1.可以通过数组名统计整个数组占用内存大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "整个数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "数组中元素个数是多少：" << sizeof(arr)/sizeof(arr[0]) << endl;

	//2.可以通过数组名查看数组首地址
	cout << "数组的首地址为：" << (int)arr << endl;
	cout << "数组中第一个元素的地址：" << (int) & arr[0] << endl;
	cout << "数组中第二个元素的地址：" << (int) & arr[1] << endl;

	//数组名是常量，不可以进行赋值操作，它就等于他的首地址（初始是16进制的）

	system("pause");
	return 0;
}
```



**练习案例1：**

**案例描述：**

在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};

**要求**：找出并打印最重的小猪的体重

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	/*
	在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};
	要求：找出并打印最重的小猪的体重
	*/

	//定义数组
	int arr[5] = { 300,350,200,400,250 };

	//判断最重的小猪
	int max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	//输出最重小猪体重
	cout << "最重的小猪体重为：" << max << endl;

	system("pause");
	return 0;
}
```



**练习案例2：**数组元素逆置

**案例描述：**请声明一个5个元素的数组，并且将元素逆置

（如原数组为 1,2,3,4,5; 逆置输出后为 5,4,3,2,1; )

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	/*
	请声明一个5个元素的数组，并且将元素逆置
	（如原数组为 1,2,3,4,5; 逆置输出后为 5,4,3,2,1; )
	*/

	//定义数组
	int arr[] = { 1,2,3,4,5 };

	//计算数组长度
	int length = sizeof(arr) / sizeof(arr[0]);

	cout << "数组逆置前：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "数组逆置后：" << endl;
	for (int i = 0; i < length; i++) //例子中，长度5，循环5次
	{
		cout << arr[length - (i + 1)] << endl; //最后的元素就是 arr[length-1]
	}

	system("pause");
	return 0;
}
```



#### 5.2.3 冒泡排序

**作用：**最常用的排序算法，对数组内的元素进行排序

1. 比较相邻的元素，如果第一个比第二个大，就交换他们两个
2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值
3. 重复以上的步骤，每次比较次数-1，直到不需要比较

![屏幕截图 2023-05-06 180114](E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 180114.png)

**示例：**将数组{4,2,8,0,5,7,1,3,9}进行升序排序

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//冒泡排序
	//题目：将数组{4,2,8,0,5,7,1,3,9}进行升序排序
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int a = 0;
	int b = 0;
	
	for (int j = 0; j < length - 1; j++) //3.总共需要排序 length-1 次
	{
		for (int i = 0; i < length - (j + 1); i++) //2.总共有length个元素，那就调换 length-1 次
		{
			if (arr[i] > arr[i + 1]) //1.如果前一个元素比后一个元素大，就调换一下它俩的位置，最后挑一个最大的到最右边
			{
				a = arr[i];
				b = arr[i + 1];
				arr[i + 1] = a;
				arr[i] = b;
			}
		}
	}

	//输出最终数组
	cout << "最终数组为：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " " ;
	}

	system("pause");
	return 0;
}
```



### 5.3 二维数组

二位数组就是在一维数组的基础上，多加一个维度

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 192827.png" alt="屏幕截图 2023-05-06 192827" style="zoom:50%;" />



#### 5.3.1 二维数组定义方式

四种方式：

1. **`数据类型 数组名[行数][列数];`**
2. **`数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};`**
3. **`数据类型 数组名[行数][列数] = {数据1,数据2,数据3,数据4};`**
4. **`数据类型 数组名[ ][列数] = {数据1,数据2,数据3,数据4};`**

> 建议：以上4种定义方式，利用==**第二种**更加直观，提高代码的可读性==

图例：**`arr[2][3]`↓**

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 193934.png" alt="屏幕截图 2023-05-06 193934" style="zoom:50%;" />

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//2.二维数组的定义方式

	/*
	1. 数据类型 数组名[行数][列数];
	2. 数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};
	3. 数据类型 数组名[行数][列数] = {数据1,数据2,数据3,数据4};
	4. 数据类型 数组名[ ][列数] = {数据1,数据2,数据3,数据4};
	*/

	//1. 数据类型 数组名[行数][列数];
	int arr[2][3] = { 0 };

	arr[0][1] = 2;
	cout << arr[0][1] << endl;

	//遍历方法：外层循环打印行数，内层循环打印列数
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//2.数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};
	int arr1[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}

	//3.数据类型 数组名[ ][列数] = {数据1,数据2,数据3,数据4};
	int arr2[2][3] = {1,2,3,4,5,6};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	//4.数据类型 数组名[ ][列数] = {数据1,数据2,数据3,数据4};
	int arr3[][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}
```

> ==第二种==最直观最常用



#### 5.3.2 二维数组数组名



- 查看二维数组所占内存空间
- 获取二维数组首地址

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//二维数组名称用途

	//1.可以查看占用的内存空间大小
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	cout << "二维数组占用的内存：" << sizeof(arr) << endl;
	cout << "二维数组第一行占用的内存：" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素所占用的内存：" << sizeof(arr[0][0]) << endl;

	cout << "二维数组的行数：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组的列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//2.可以查看二位数组的首地址
	cout << "二维数组首地址：" << (int)arr << endl;
	cout << "二维数组第一行的首地址：" << (int)arr[0] << endl;
	cout << "二维数组第二行的首地址：" << (int)arr[1] << endl;

	cout << "二维数组第一个元素的首地址：" << (int)&arr[0][0] << endl; // &！！！


	system("pause");
	return 0;
}
```



#### 5.3.3 二维数组应用案例

**考试成绩统计：**

案例描述：有三民同学（张三，李四，王五），在一次考试中的成绩分别如下表，**请分别输出三名同学的总成绩**

|      | 语文 | 数学 | 英语 |
| ---- | ---- | ---- | ---- |
| 张三 | 100  | 100  | 100  |
| 李四 | 90   | 50   | 100  |
| 王五 | 60   | 70   | 80   |



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	/*
	案例描述：有三民同学（张三，李四，王五），在一次考试中的成绩分别如下表
				请分别输出三名同学的总成绩
	*/

	int sum = 0;

	int arr[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};

	string name[3] = { "张三","李四","王五" };

	for (int j = 0; j < 3 ; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			sum = sum + arr[j][i];
		}
		
		cout << name[j] << "同学的总成绩为：" << sum << endl;

		sum = 0;
	}

	system("pause");
	return 0;
}
```



## 六、函数

### 6.1 概述

**作用：**讲一段经常使用的代码封装起来，减少重复代码

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能

### 6.2 函数的定义

函数的定义一般主要有5个步骤：

1. 返回值类型
2. 函数名
3. 参数列表
4. 函数体语句
5. return 表达式

**语法：**

```c++
返回值类型 函数名 (参数列表)
{
    
    函数体语句
        
    return表达式
        
}
```

**图例：**

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 222220.png" alt="屏幕截图 2023-05-06 222220" style="zoom:50%;" />

<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-06 223422.png" alt="屏幕截图 2023-05-06 223422" style="zoom:50%;" />

**加法示例代码：**

```c++
#include <iostream>
#include <string>

using namespace std;

//函数的定义
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main()
{
	system("pause");
	return 0;
}
```

- 返回值类型：一个函数可以返回一个值，在函数定义中
- 函数名：给函数起个名称
- 参数列表：使用该函数时，传入的数据
- 函数体语句：花括号内的代码，函数内需要执行的语句
- return 表达式：和返回值类型挂钩，函数执行完后，返回相应的数据



### 6.3 函数的调用

**功能：**使用定义好的函数

**语法：`函数名(参数)`**

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

//函数的定义
//函数定义时，num1和num2并没有真的数据，他只是一个形式上的参数，简称形参
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main()
{
	cout << "加法计算，请输入两个数字，中间用空格隔开：" << endl;
	int b, c;
	cin >> b;
	cin >> c;

	// a 和 b 称为 实际参数，简称实参
	//当调用函数的时候，实参的值会传递给形参
	int a = add(b,c);
	cout << "两数相加为:" << a << endl;

	system("pause");
	return 0;
}
```



### 6.4 值传递

- 所谓值传递，就是参数调用时实参将数值传入给形参
- 值传递时，==如果形参发生，并不会影响实参==

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

//值传递
//定义函数，实现两个数字交换的函数

//如果函数不需要返回值，声明的时候可以写 void（翻译：无效）
void swap(int num1, int num2)
{

	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	return;
}

int main()
{

	int a = 10;
	int b = 20;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//当我们做值传递的时候，函数的形参发生改变，不会影响到实参
	swap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}
```



### 6.5 函数的常见样式

常见样式有4种

1. 无参无返
2. 有参无返
3. 无参有返
4. 有参有返

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

//函数的常见样式

//1.无参无返
void test01()
{
	cout << "helloworld" << endl;
}

//2.有参无返
void test02(int a)
{
	cout << "test02 a = " << a << endl;
}

//3.无参有返
int test03()
{
	cout << "test03" << endl;

	return 1000;
}

//4.有参有返
int test04(int num1)
{
	int sum = num1 + 10;
	return sum;
}

int main()
{

	//无参无返的函数调用
	test01();

	//有参无返的函数调用
	test02(100);

	//无参有返函数调用
	int num1 = test03();
	cout << "num1 = " << num1 << endl;

	//有参有返函数调用
	int num2 = 10;
	cout << "num2 + 10 = " << test04(num2) << endl;

	system("pause");
	return 0;
}
```



### 6.6 函数的声明

**作用：**告诉编译器函数名称及如何调用函数，函数的实际主体可以单独定义



- 函数的**声明可以多次**，但是函数的**定义只能有一次**



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

//函数的声明
//比较函数，实现两个整型数字进行比较，返回较大的值

//定义
//int max(int a, int b)
//{
//	//int Max = (a >= b ? a : b);
//	//return Max;
//
//	return a >= b ? a : b;
//
//}

//提前告诉编译器函数的存在，可以利用函数的声明（如果定义在main前可以不用声明）
//声明可以多次，定义只能有一次
int max(int a, int b);
//这一步其实vs2022可以不用了

int main()
{

	//声明可以多次，定义只能有一次

	int a = 10;
	int b = 20;

	cout << max(a, b) << endl;

	system("pause");
	return 0;
}


int max(int a, int b)
{
	//int Max = (a >= b ? a : b);
	//return Max;

	return a >= b ? a : b;

}
```



### 6.7 函数的分文件编写

**作用：**让代码结构更加清晰

函数分文件编写一般有4个步骤

1. 创建后缀名.h的头文件
2. 创建后缀名为.cpp的源文件
3. 在头文件中写函数的声明
4. 在源文件中写函数的定义

**示例：**

**头文件 swap.h**

```c++
//声明
void swap(int a, int b);
```

**源文件 swap.cpp**

```c++
#include <iostream>
#include "swap.h" //双引号代表自定义

using namespace std;

//定义
void swap(int a, int b)
{
	int c = a;
	a = b;
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
```

**主文件 函数的分文件编写**

```c++
#include <iostream>
#include <string>

#include "swap.h"

using namespace std;

//函数的分文件编写
//实现两个数字交换的函数

//函数的声明
//void swap(int a, int b);

//函数的定义
//void swap(int a, int b)
//{
//	int c = a;
//	a = b;
//	b = c;
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}

int main()
{

	int a = 10;
	int b = 20;

	swap(a, b);

	system("pause");
	return 0;
}
```

> 注：#include "swap.h" //==双引号代表自定义==



## 七、指针

### 7.1 指针的基本概念

**指针的作用：**可以通过指针间接访问内存



- 内存编号是从0开始记录的，一般用十六进制数字表示
- 可以利用指针变量保存地址



<img src="E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-07 014454.png" alt="屏幕截图 2023-05-07 014454" style="zoom:50%;" />



> 可以认为，指针就是一个地址
>
> 实际上，指针是一个变量，其中保存着地址



### 7.2 指针变量的定义和使用

指针变量定义语法：**`数据类型 * 变量名`**

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.定义指针
	int a = 10;
	//指针定义的语法：数据类型 * 指针变量名;
	int* p = &a; //让指针记录变量a的地址

	cout << "a的地址为：" << &a << endl;
	cout << "指针p为：" << p << endl;

	//2.使用指针
	//可以通过解引用的方式来找到指针指向的内存
	//指针前加一个 * 代表解引用，找到指针指向的内存中的数据

	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	system("pause");
	return 0;
}
```



### 7.3 指针所占空间



提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？

1. 在**32位**操作系统下，任何类型的指针都是**4个字节**
2. 在**64位**操作系统下，占**8个字节**

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//指针所占内存空间
	int a = 10;
	//int* p;
	//p = &a;

	int* p = &a;

	cout << "sizeof int *p = " << sizeof(int*) << endl;
	cout << "sizeof float *p = " << sizeof(float*) << endl;
	cout << "sizeof double *p = " << sizeof(double*) << endl;
	cout << "sizeof char *p = " << sizeof(char*) << endl;

	system("pause");
	return 0;
}
```



### 7.4 空指针和野指针

**空指针：**指针变量指向内存中编号为0的空间

**用途：**初始化指针变量

**注意：**空指针指向的内存是不可以访问的，0-255的内存是系统占用的，我们不能访问



**示例1：空指针**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//空指针
	//1.用于给指针变量初始化
	int* p = NULL; //NULL = 0;

	//2.空指针是不能用于访问的
	//0~255之间的内存编号是系统占用的，因此不可以访问
	 
	//*p = 100;

	int a = 10;
	p = &a;

	cout << "*p = " << *p << endl;

	system("pause");
	return 0;
}
```



**野指针：**指针变量指向非法的内存空间（你无法操控的内存空间等）

**示例2：野指针**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//野指针
	//在程序中，尽量避免出现野指针
	int* p = (int*)0x1100;

	//cout << *p << endl;

	system("pause");
	return 0;
}
```

> 总结：空指针和野指针都不是我们申请的空间，因此不要访问



### 7.5 const修饰指针

const修饰指针的三种情况：

1. const 修饰指针 --- 常量指针
2. const 修饰常量 --- 指针常量
3. const 既修饰指针，又修饰常量



![屏幕截图 2023-05-07 175813](E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-07 175813.png)

- 常量指针：**`const int* p = &a;`**
- 特点：指针的指向可以改，但是指针指向的值不能改，即const作用在指向的变量上



![屏幕截图 2023-05-07 180925](E:\c.---c.---java-exercise\photo\屏幕截图 2023-05-07 180925.png)

- 指针常量：**`int* const p = &a;`**
- 特点：指针的指向不能改，指向的值可以改



- const即修饰指针，又修饰常量
- **`const int* const p = &a;`**
- 特点：指针的指向和指针的值都不能改



**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//1.常量指针
	int a = 10;
	int b = 10;

	const int* p = &a;
	//指针指向的值不能改，指向可以改
	//*p = 20; 错误
	p = &b; //正确

	//2.指针常量
	int* const p1 = &a;
	*p1 = 20; //正确
	//p2 = &b; 错误

	//3.const修饰常量和指针
	const int* const p2 = &a;
	//*p2 = 20; 错误
	//p2 = &b; 错误

	system("pause");
	return 0;
}
```



### 7.6 指针和数组

**作用：**利用指针访问数组中的元素

**示例：**

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{

	//指针和数组
	//利用指针访问数组

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "第一个元素是：" << arr[0] << endl;

	int* p = arr; //arr存放了数组的首地址

	cout << "利用指针来访问第一个元素：" << *p << endl;

	p++; //往后推四个字节，整型指针直接++就行

	cout << "利用指针来访问第二个元素：" << *p << endl;


	cout << "利用指针遍历数组：" << endl;
	int* p2 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << "数组中第" << i + 1 << "个元素为：" << *p2 << endl;
		p2++;
	}

	system("pause");
	return 0;
}
```

