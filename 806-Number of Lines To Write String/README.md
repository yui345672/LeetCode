## 题意
   给你一个字符串（里面含有的字母）和26个英文字母的出现长度。
   
   然后叫你根据这两个表，然后对字符串中的字母进行排列。
   
   如果在放置某一个字母时，使得一行中放置的长度超过了100，那么就将这个字母放到下一行去。
   
   最后问你把字符串中的字母全部放完，总共放置了多少行，以及最后一行里面放置的长度是多少？
   
## 思路
   并不难想，就是遍历字符串，然后去26个英文字母表中查找对应的出现长度。
   
   然后用lines记录行数，用另一个sum来记录最后一行放置的长度。
      
## 注意
   因为我没有看到题目中说字符串的长度是从1开始的，所以它这里是不可能为空串的，所以没有进行特判。
   
   所以如果字符串的长度是从0开始的话，那么别忘记进行一下特判。
