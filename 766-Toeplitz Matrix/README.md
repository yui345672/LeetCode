## 题意
   一个矩阵是「Toeplitz」矩阵，如果它的每一条对角线（只要从左上角到右下角的那条）从最上面到最下面的元素都是一样的。
   然后，让你判断该矩阵是否是「Toeplitz」矩阵。
   
   
## 思路
   那么就只有遍历行和列，然后判断当前的元素是否和左上角的一样，如果不一样，那么就不是「Toeplitz」矩阵。
   
   ![image](https://user-images.githubusercontent.com/16880879/40839203-0b90af4a-65d4-11e8-961f-c61f4424eb5a.png)
