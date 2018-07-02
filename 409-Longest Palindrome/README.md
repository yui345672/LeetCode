## 题意
   给你一个字符串包含大小写字符，然后叫你找出由这些字符可以组成的最长的回文字符串的长度。
   
   注意：回文字符串是大小写敏感的，也就是说 Aa 和 aa 是不一样的。
   
## 思路
   并没有很难，但是有很多细节需要注意。
   
   因为回文字符串是需要两两对应的，所以一般是偶数次出现次数。
   
   然后最多可能的情况是中间再插一个字符，形成奇数的情况。
   
   所以这里对于出现次数是偶数次数的，那么就加入长度中，因为它们肯定能够组成回文串的一部分。
   
   对于出现次数是奇数次的，一开始我想错了，以为是把它扔掉比较好，但是不是，你想，我们可以只取它的偶数次啊，这样不就又能够组成回文字符串了吗？
   所以这里我们取出 奇数次 -1 来组成回文字符串。
   
   如果在字符串中出现过有奇数次出现的字符，那么我们可以在最后的长度上再加上一个 1，因为这个字符可以被放在中间部分，所以不需要成对出现。