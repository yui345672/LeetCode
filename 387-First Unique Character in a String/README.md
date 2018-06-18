## 题意
   给你一个字符串，找出它的第一个未重复的字符，并返回它的下标，如果不存在，则返回 -1。
   
## 思路
   用 Map 记录下每个字符出现的次数，然后再遍历一次字符串，如果出现的次数为 1，则返回该字符的下标。
   否则，遍历结束后，返回 -1 。