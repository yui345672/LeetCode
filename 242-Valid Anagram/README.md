## 题意
   给你两个字符串 S 和 T，让你判断 T 是不是 S 的一个变化串（就是说字符串中的字符都是一样的，只是顺序不同而已）。
   
## 思路
   也是一道可以利用 Hash Table，也就是 map 来做的题目。
   
   1.直接使用 unordered_map 记录两个字符串中的字符，然后判断它们出现的次数是不是相等。
   
   这里虽然可以使用 unordered_map，但是其实也还可以使用我们自己的数组来标记字符的出现次数，
   我们可以开一个 int 数组，然后在里面记录每个字符出现的次数，当然这里可以以数字的形式保留字符，就像（'c'-'a'）这样。
   
   但是呢，这里判断相等我们还有另一种方法，就是对 S 中的字符，我们把它放进 map 中的时候是执行 ++ 的操作；
   然后对于 T 的字符，我们将其放入 map 的时候是执行 -- 的操作；最后遍历完了，我们将 map 中遍历一遍，
   发现它其中还存在有计数不为 0 的，那么就返回 false。这个思路也相当不错！！！
   
   代码参考如下：
   ```c++
   public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
  }
   ```
   
   2.对字符串进行排序
   
   因为 T 只是 S 的乱序，所以如果排完序对 T 进行遍历的时候，发现和 S 不一致，那么就返回 false。
   
