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
#define day 7 //1.#define 宏常量

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

```

