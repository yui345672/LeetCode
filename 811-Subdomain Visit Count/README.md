## 题意
   给你一串字符串，然后问你每个子串出现的次数。注意，这里子串是以“.”来进行分割的，最后让你输出所有种类的子串出现的次数。
   
## 思路
   一开始想着遍历。。但是这明显是不行的嘛。
   
   后来就想到用map来记录每个子串出现的次数，并进行累加，这样我们要做的事情就是对字符串进行分割啦！（这也是这道题唯一需要做的细心一点的地方吧）
   
## 收获
   C++ 方面： 学会了使用map，以及map的迭代iterator。
   ```
   it=mp.begin(); it!=mp.end(); it++
   ```
   
   python 方面： 学习了使用Counter，类似于dict一样的东西。
   
   字符串的分割，反转（reverse），join（合并字符串）[http://www.runoob.com/python/att-string-join.html]
   
   Counter的key，value 遍历，利用c.items() 即可。
