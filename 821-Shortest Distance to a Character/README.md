## 题意
   给你一个字符串和一个字符C，叫你计算该字符串中的字符到该串中字符C的距离。
   
## 思路
   首先计算出该串中字符C存在的位置。
   
   然后分情况进行计算距离就可以了。
   
   计算距离肯定是贪心，肯定是找当前位置两边的字符C，然后进行比较哪个距离短。
   
   要注意的是：
   
   1. 字符 C 在其他字符的右边，那么当前肯定是离这个字符最近了。
   
   2. 其他字符在字符 C 的中间，那么就要进行比较，看离哪个距离比较近。
   
   3. 字符 C 在其他字符的左边，（这个我一开始忘记判断了），那么也肯定是离这个字符 C 最近。
   
## 收获
   看到了解析那边的想法没我的这么复杂，不用向我一样进行分类了，这样容易弄错。
   
   首先线左边扫一遍，然后记录下每个坐标点到左边那个 C 的距离。
   
   要注意的是，一开始可能最左边没有 C， 所以一开始要将prev设为一个很小的负数值，这样才能保证不会出错。
   
   同理，从右边开始可能最右边没有 C，所以一开始要将prev设为很大的值，因为是prev-i。
   
   然后两边进行比较，看哪个小就用哪个。
   
   ```java
   
   class Solution {
    public int[] shortestToChar(String S, char C) {
        int N = S.length();
        int[] ans = new int[N];
        int prev = Integer.MIN_VALUE / 2;

        for (int i = 0; i < N; ++i) {
            if (S.charAt(i) == C) prev = i;
            ans[i] = i - prev;
        }

        prev = Integer.MAX_VALUE / 2;
        for (int i = N-1; i >= 0; --i) {
            if (S.charAt(i) == C) prev = i;
            ans[i] = Math.min(ans[i], prev - i);
        }

        return ans;
    }
}
   ```
