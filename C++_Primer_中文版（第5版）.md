# C++ Primer 中文版（第5版）

学习一门新的程序设计语言的最好方法就是练习编写程序

## 1.1 编写一个简单的C++程序

每个C++程序都包含一个或多个函数（function），其中一个必须命名为 **main**

一个函数的定义包含四部分：返回类型（return type）、函数名（function name）、一个括号包围的**形参列表**（parameter list）、以及函数体（function body）

main函数的返回类型必须是int，即整数类型。int类型是一种**内置类型**（build-in type），即语言自身定义的类型

函数体是以**左花括号**（curly brace）开始，以**右花括号**结束的**语句块**（block of statements）

***Note***：在C++中，大多数C++语句以分号表示结束

**重要概念：类型**

类型是程序设计最基本的概念之一。一种类型不仅定义了数据元素的内容，还定义了这类数据上可以进行的运算

### 1.1.1 编译、运行程序

**集成开发环境（Integrated Developed Environment, IDE）**

程序文件通常被称为**源文件**（source file）

## 1.2 初识输入输出

C++语言并未定义任何输入输出（IO）语句，取而代之，包含了一个全面的**标准库**（standard library）来提供IO机制（以及其他很多设施）

iostream库包含两个基础类型 **istream** 和 **ostream** ，分别表示输入流和输出流。一个流就是一个字符序列，是从IO设备读出或写入IO设备的。术语“流”（stream）想要表达的是，随着时间的推移，字符是顺序生成或消耗的

标准库定义了4个IO对象

**cin**：istream类型，称为**标准输入**（standard input）

**cout**：ostream类型，称为**标准输出**（standard output）

**cerr**：ostream类型，称为**标准错误**（standard error），用来输出警告和错误信息

**clog**：ostream类型，用来输出程序运行时的一般性信息

系统通常将程序所运行的窗口与这些对象关联起来

每个使用标准库设施的程序都必须包含相关的**头文件**（header）

#include指令必须出现在所有函数之外。我们一般将一个程序的所有#include指令都放在源文件的开始位置

**表达式**（expression）

**输出运算符**（<<）

<<运算符接受两个运算对象：左侧的运算对象必须是一个ostream对象，右侧的运算对象是要打印的值。输出运算符的计算结果就是其左侧运算对象

**字符串字面值常量**（string literal），用一对双引号包围的字符序列

**操纵符**（manipulator）：endl的效果是结束当前行，并将与设备关联的**缓冲区**（buffer）中的内容刷到设备中。缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅停留在内存中等待写入流

**Warning**：程序员常在调试时添加打印语句。这类语句应该保证“一直”刷新流。否则，如果程序崩溃，输出可能还留在缓冲区中，从而导致关于程序崩溃位置的错误推断

前缀std::指出名字是定义在名为 **std** 的**命名空间**（namespace）中的。命名空间可以帮助我们避免不经意的名字定义冲突，以及使用库中相同名字导致的冲突。标准库定义的所有名字都在命名空间std中

通过命名空间使用使用标准库有一个副作用：当使用标准库中的一个名字时，必须显示说明我们想使用来自命名空间std中的名字。例如，需要写出std::cout，通过使用**作用域运算符**（::）来指出我们想使用定义在命名空间中的名字cout

**变量**（variable）

**初始化**（initialize）

**输入运算符**（>>）

\>>运算符接受两个运算对象：左侧的运算对象必须是一个istream对象，右侧的运算对象是要存入的对象。输出运算符的计算结果就是其左侧运算对象

## 1.3 注释简介

C++是如何处理**注释**（comments）的？

> **C++中注释的种类**

C++中有两种注释：单行注释和界定符对注释

单行注释以双斜线（//）开始，以换行符结束。当前行双斜线右侧的所有内容都会被编译器忽略，这种注释可以包含任何文本，包括额外的双斜线

对于界定符对注释，我们所采用的风格是，注释内的每行都以一个星号开头

> 注释界定符不能嵌套

## 1.4 控制流

### 1.4.1 while语句

while语句的形式为

while (*condition*)

​	*statement*

所谓**条件**（condition）就是一个产生真或假的结果的表达式

**小于等于运算符**（<=）

**语句块**（block）

**复合赋值运算符**（+=）

**赋值**（assignment）

**前缀递增运算符**（++）

1.4.2 for语句

每个for语句都包含两部分：循环头和循环体

循环头控制循环体的执行次数，它由三部分组成：一个初始化语句（*init-statement*）、一个循环条件（*condition*）以及一个表达式（*expression*）

初始化语句中定义的变量仅在for循环内部存在，它在循环结束之后是不能使用的

> The main difference between the `for`'s and the `while`'s is a matter of pragmatics: we usually use `for` when there is a known number of iterations, and use `while` constructs when the number of iterations in not known in advance. The `while` vs `do ... while` issue is also of pragmatics, the second executes the instructions once at start, and afterwards it behaves just like the simple while.

for与while和do-while的比较https://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming

### 1.4.3 读取数量不定的输入数据

```
while (std::cin >> value)
```

此循环实际上检测的是std::cin，其效果是检测流的状态，如果流是有效的，即流未遇到错误，那么检测成功。当遇到**文件结束符**（end-of-file），或遇到一个无效输入时（例如读入的值不是一个整数），istream对象的状态会变为无效，处于无效状态的istream对象会使条件变为假

Windows中输入文件结束符的方式是敲Ctrl+Z

UNIX和Mac OS X系统中，是Ctrl+D

> 编辑器可以检查**形式**（form）上的错误
>
> **语法错误**（syntax error）
>
> **类型错误**（type error）
>
> **声明错误**（declaration error）
>
> **编辑-编译-调试**（edit-compile-debug）

### 1.4.4 if语句

**相等运算符**（==）

> C++程序的缩进与格式，不存在唯一正确，但要保持一致性
>
> 左花括号必须是main的形参列表后第一个非空、非注释的字符

## 1.5 类简介

**数据结构**（data structure）

**类**（class），一个类定义了一个类型，以及与其关联的一组操作

**类类型**（class type）

通常使用.h作为头文件的后缀，标准库文件通常不带后缀

> 使用文件重定向