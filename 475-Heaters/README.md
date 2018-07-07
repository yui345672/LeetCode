## 题意
   给你房子和加热器的地理位置，然后叫你判断加热器的覆盖半径至少为多少才能覆盖全部的房屋，输出这个最小的半径。
   
## 思路
   首先对房子和加热器进行排序，使它们的位置保持有序。
   
   然后我们可以首先预判两种情况：
   
   1）当 heaters[0]>=houses[len1-1]，那么说明最小的半径肯定是 heaters[0]-houses[0]
   
   2）当 heaters[len2-1]<=houses[0]，那么说明最小的半径是 houses[len1-1]-heaters[len2-1]
   
   然后我们可以对加热器的半径进行二分查找的方式来确定，那么首先要确定二分的区间。显而易见的左区间 left=0，
   右区间，应该是 加热器的最左端点到房子的左右端点距离的最大值，以及加热器的最右端点到房子的左右端点距离的最大值，
   这两个值的较小值。
   
   因为要覆盖的话，肯定最极端的情况就是加热器的最左右端点去覆盖房子的左右端点，但是这两个端点只需要去较小值是因为其中一个如果
   能够覆盖极端情况的话，那么另一个就无所谓了。不理解的话可以画个图去理解一下。
   
   代码见下面：
   
   ```c++
   min(max(abs(heaters[0]-houses[0]), abs(houses[len1-1]-heaters[0])),
       max(abs(heaters[len2-1]-houses[len1-1]), abs(heaters[len2-1]-houses[0])));
   ```
   
   然后在二分的时候，要怎么判断加热器是不是全部覆盖了房子呢？
   
   使用 Two Pointers ，其中一个指针指向 houses[i] ，另一个指针指向 heaters[j] 。如果房子在加热器的半径范围内，那么将
   房子的指针 i++ ，否则将 j++ 。
   
   如果最后房子没有遍历完，则返回 -1 ，从而在二分中进行调整，使 left=mid+1 。
   
   最后返回的 left 就是最小的加热器的半径。
   
   在 Leetcode 的交流区还写了一个英文版的解释：https://leetcode.com/problems/heaters/discuss/146308/Detailed-Explanation-of-Binary-Search-+-Two-Pointers
   
   **Solution-2**
   
   还有另一种算法，是别人提出的。
   
   就是每次在当前房子 houses[i] 找与它距离最近的 heaters[index] ，其中 index 是指针。
   
   然后不断更新半径 radius = max(radius, abs(heaters[index]-houses[i]));
   
   为什么是 max ？因为这里我们得满足所有的啊，而 heaters[index] 又是离当前 house[i] 最近的加热器了，所以肯定得选择较大的。
   
   ```c++
   class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) {
            return 0;
        }
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        int index = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (index + 1 < heaters.size() && (abs(heaters[index+1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
                index++;
            }
            radius = max(radius, abs(heaters[index] - houses[i]));
        }
        return radius;
    }
};
   ```
