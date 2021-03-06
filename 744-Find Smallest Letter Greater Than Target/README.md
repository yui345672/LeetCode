## 题意
   给你一个排好序的字符数组，和一个目标字符 target ，然后让你在这个字符数组中找到第一个比 target 大的字符（注意，没有等于！）。
   如果 target 被放到最后了，那么就返回该数组的第一个字符，因为题目中说这个字符数组是一个环形的，所以当 target 大于数组中的最后一个
   字符时，那么就返回数组中的第一个字符。
   
## 思路
   因为二分查找 (binary search) 很适合在有序的数组中找第一个比 target 大的字符，所以就用了这个算法。
   
   这里我觉得字符太麻烦，所以就将字符转化为了数字。
   
   然后二分的区间为 [0, n] ，最后是到 n 而不是 n-1 的原因是：有可能 target 会比数组中的所有字符都大，所以这个时候它就会被放在末尾，
   所以 n 也是一个可能会被取到的值。（二分的初始区间应当能够覆盖到所有可能返回的结果）
   
   然后每次对区间进行取中点 mid ，有以下 2 种情况。
   
   1）如果 A[mid] <= target，那么说明比 target 大的应该在 mid 右边部分，所以令 left = mid+1
   
   2）如果 A[mid] > target，说明比 target 大的在 mid 或是在 mid 左边，因为我们要找第一个比它大的，所以不妨再往左边去找找，所以此时令 right = mid
   
   然后判断二分结束的条件是： left == right
   
   因为当 left == right 的时候，说明指针已经根据上面两种情况限定好了范围，这个就是第一个比 target 大的字符。
   
   如果最后 left == n 的话，那么说明这个数是被放在了数组的最后，所以此时返回字符数组的第一个字符就好。
