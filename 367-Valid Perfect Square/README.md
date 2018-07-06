## 题意
   给你一个数，叫你判断它是不是完全平方数。（不使用 sqrt 函数来进行判断）
   
## 思路
   这道题和书上的求根的那题很像。
   
   令 f(mid) = mid*mid ，如果 f(mid) > n ，那么说明当前的数大了， right=mid-1；
   
   如果 f(mid) < n ，说明当前数小了， left=mid+1；
   
   f(mid) == n ，Congratulations!!! 你找到了一个数，它的平方等于 n ，所以 n 就是完全平方数了！！
