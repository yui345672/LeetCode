## Address-of Operator(取地址符)
- 一个变量中的地址可以通过在这个变量的名字前加一个取地址符来实现。例如：

```
foo = &myvar;
```

- 在这里呢，foo获取到的就是myvar的地址

```
myvar = 25;
foo = &myvar;
bar = myvar;
```

![image](https://user-images.githubusercontent.com/16880879/39744490-07712210-52d7-11e8-961a-3e458ea9ba06.png)

- 在C++中，保存其他变量的地址的那个变量叫做指针(pointer)。


## Dereference operator (*) (解引用符)
- pointer可以直接访问到它所指向的那个变量。通过在pointer前面加上*来实现（代表的意思就是所指向的值）。

```
baz = *foo;
```

- 上面这个意思就是： baz等于由foo所指向的那个值。

![image](https://user-images.githubusercontent.com/16880879/39744525-25c30f76-52d7-11e8-9feb-74271d32be1b.png)

- & is the address-of operator, and can be read simply as "address of" (取地址符)
- '*' is the dereference operator, and can be read as "value pointed to by" (获取到由这个地址指向的值)


## Declaring pointers(声明指针)
- 申明的格式如下：

```
type * name; 
```

- type是指针所指向的类型
- 这里的*号只能说明它是一个指针（pointer），而不要去和前面的dereference operator进行混淆。
- 虽然它们两个的符号是一样的，但是意义完全不同。
- 定义每个pointer的时候前面都要加上*号。

```
int * p1, * p2;
```

## Pointers and arrays
- array也可以和pointer进行关联。
- 这个时候pointer指向的是array的第一个元素。
- arrays work very much like pointers to their first elements, 

```
int myarray [20];
int * mypointer;

mypointer = myarray; // 注意这里不需要加取址符,和上面的不一样。
// 上面的也就是将myarray的第一个元素的地址赋给了mypointer
```

- 看一个例子
```
// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];
  int * p;
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  return 0;
}
// 最后输出是: 10, 20, 30, 40, 50, 
```

## Pointer initialization
- 它们可以在定义的时候就被指向一个特定的地址。
- Pointers can be initialized either to the address of a variable, or to the value of another pointer (or array). 【也就是相当于说指针只能被初始化为地址】

```
int myvar;
int * myptr = &myvar;

// 等同于
int myvar;
int * myptr;
myptr = &myvar;
```

## Pointer arithmetics
- 指针只有加减法。
- 它每次增加都是增加它在内存中的大小，并不是仅仅说加1就加1了，加的是它的一个内存大小。

![image](https://user-images.githubusercontent.com/16880879/39744548-37f88e96-52d7-11e8-9e1b-707f5662e3c3.png)

- 以下几个操作符的运算顺序要注意一下:
- 因为加减法比dereference（*）的优先级高，所以 *p++  等于  *(p++) 。
- 这里加了括号和不加括号是一样的，是因为i++是先赋值再自增，对于指针也是一样的。所以*p++是先取值，然后p再自增。加个括号还是一样的，*（p++）括号里面的内容还是p++，所以还是要先取值然后p再自增。

```
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 
```


## Pointers and const
- 这里到后面的结束部分还没有进行补完。。
- http://www.cplusplus.com/doc/tutorial/pointers/
