## 题意
就是给你两棵二叉树，然后让你将一棵树放到另一棵树上，然后看重叠的效果，最后叫你输出合并后的二叉树的样子。

## 思路
遍历一遍二叉树，利用递归来写比较直观，就是首先往左边遍历，如果左边遍历完了，然后向上返回，然后再向右边进行遍历。

## 收获
1. 关于指针的问题进行了了解，具体的总结写在了另一份文件里。 </br>
   可以看到这里代码中传入进来的是指向TreeNode的一个指针，而指针中只能存放的是地址，所以就相当于是传入了一个指向TreeNode的指针的地址。 </br>
   然后不是对于一般指针来说，需要访问其地址所指向的值的时候需要这样写： (*p).val，但是注意了！！！ 因为这里是结构体struct </br>
   所以我又特意去看了一下官方文档 [具体见Pointers to structures内容](http://www.cplusplus.com/doc/tutorial/structures/) ，发现说：
   > The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members. 
   > This operator serves to access the member of an object directly from its address.
   
   什么意思呢？</br>
   就是说对于那些指针指向的对象中还有元素的objects，我们可以直接用 -> 操作来访问object的member，从它的地址（也就是指针）那儿。</br>
   所以说，只需要使用p->val 就可以访问元素了，而不用写成我上面的 (*p).val。

2. 引用传递
   在引用传递过程中，传入的是主调函数放进来的实参变量的地址。</br>
   被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。</br>
   正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。</br>
   引用引入了对象的一个同义词。定义引用的表示方法与定义指针相似，只是用&代替了*。</br>
   使用引用机制后，以上程序的c++版本为：</br>
   ```
   void swapint(int &a,int &b)
   {
      int temp;
      temp=a;
      a=b;
      b=temp;
   }
   ```
   
   调用该函数的c++方法为：swapint（x,y); c++自动把x,y的地址作为参数传递给swapint函数。 </br>
   [参考1](http://xinklabi.iteye.com/blog/653643)  [参考2](https://www.cnblogs.com/yanlingyin/archive/2011/12/07/2278961.html) </br>
   所以在我的代码中，我也使用了引用传递的方式，将TreeNode* t的地址传递到函数中。 </br>
   
3. 递归思考
   条件的判断不够仔细，所以交了之后错了好多发。if - else if 记住是执行了一个就不会再去执行另一个的。
   
## Question：
1. 还是没明白为什么TreeNode* t要是指针的形式？ 
