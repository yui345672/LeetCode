## 题意
   给你两个字符串数组，然后叫你找出他们的下标和加起来最小的相同字符串，
   如果有多个字符串相加的下标和相同，那么把它们全部都输出。
   
## 思路
   看了这道题的题解，又增加了些思路。
   
   1.暴力且直接的思路
   
   就是首先遍历第一个字符串数组，然后在里面遍历第二个数组；如果这两个字符串相等，那么就把它们的下标和和字符串都放入到 Map 中的数组中。
   然后再遍历找出整个 Map 中的下标和最小值。然后再遍历一遍，找出是最小值的那个数组。
   Java 参考代码如下：
   
   ```java
   public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        HashMap < Integer, List < String >> map = new HashMap < > ();
        for (int i = 0; i < list1.length; i++) {
            for (int j = 0; j < list2.length; j++) {
                if (list1[i].equals(list2[j])) {
                    if (!map.containsKey(i + j))
                        map.put(i + j, new ArrayList < String > ());
                    map.get(i + j).add(list1[i]);
                }
            }
        }
        int min_index_sum = Integer.MAX_VALUE;
        for (int key: map.keySet())
            min_index_sum = Math.min(min_index_sum, key);
        String[] res = new String[map.get(min_index_sum).size()];
        return map.get(min_index_sum).toArray(res);
      }
  }
   ```
   
   2.第二种方法是遍历它们的下标和
   
   因为这两个字符串的下标和的取值范围是 sum: 0 - len1+len2-1，所以我们首先遍历 sum 这个范围，然后在这个范围中再遍历 list1，这里我们选择
   list1 的遍历范围是在 i: 0 - sum，然后我们就可以得到相应的 list2 的下标，是 list2[sum-i]。（这里不要忘记加**下标的判断条件**）
   
   因为我们这里是遍历下标和，所以当 list2[sum-i] == list1[i] 时，我们就可以将其压入答案数组中，最后当遍历完 list1 后，如果答案
   数组不为空，我们就可以 break 返回答案数组，因为我们遍历的下标和是从小到大的，所以可以保证答案唯一。
   
   代码见 solution-2
   
   3.第三种方法是使用 Map
   
   最后一种方法就是使用 Map，首先先把 list1 的下标保存在 Map 中。
   
   然后再遍历 list2，如果当前 Map 中有存在 list2[i] 这个键，那么说明这个字符串在 list1 和 list2 中都存在，
   那么我们就开始求它们的下标和：
   
   a.如果当前求出来的下标和小于最小值，那么更新最小值，然后把之前保存的答案数组清空，然后将目前的字符串放进去。
   
   b.如果当前求出来的下标和等于最小值，那么就也把当前的字符串放进答案数组中去。
   
   c.如果当前求出来的下标和大于最小值，那么直接跳过就可以了
   
   代码见 solution-1
