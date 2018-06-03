## 题意
   给你平面上的一些点，然后让你判断该平面上的点所能够组成的最大的三角形的面积是多少？
   
## 思路
   本来还想着找规律，后来发现点的数量最多只有 50 个，所以就直接暴力遍历就好了。
   
   因为我们遍历的时候获得是坐标，然后求三角形面积有 2 种比较便捷的方法。
   
   **1.海伦公式（solution-1）**
   ![image](https://user-images.githubusercontent.com/16880879/40882802-f56722ce-671f-11e8-8621-b5f93bc88c92.png)
   
   这里就需要利用坐标先计算边长，从而来计算半周长，然后再获得面积。
   
   </br>
   
   **2.Shoelace formula**
   
   Ref：https://en.wikipedia.org/wiki/Shoelace_formula
   
   它可以直接利用坐标来计算三角形的面积。
   
   总体的思路就是在三角形外面构建一个刚好能够包裹住它的矩形，然后再减去三角形到矩形之间的小三角形，最后得到的就是中间那个我们需要的三角形的面积了。
   
   如下图所示：
   
   ![image](https://user-images.githubusercontent.com/16880879/40882823-67d3cb6e-6720-11e8-8aaa-a06df33cee9d.png)
   
   然后它的计算公式如下：
   
   ![image](https://user-images.githubusercontent.com/16880879/40882825-772a1794-6720-11e8-8a11-2517e329a04c.png)
   
   注意那个不是括号，而是取绝对值的符号！
