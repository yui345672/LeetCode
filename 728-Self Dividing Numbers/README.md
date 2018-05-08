## 题意
   给你一个数字范围区间，让你输出满足以下条件的数字：不包含0，能够被这个数字中的每一位整除。
   
## 思路
   因为最大才10000，所以最多才5位，直接for范围，然后分解数字就好了。暴力模拟。
   
## 收获
   看一下别人的简洁代码。
   
```
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i = left; i <= right; ++i) {
            int tmp = i;
            while(tmp) {
                int mod = tmp%10;
                
                if (mod == 0 || i%mod != 0) {
                    break;
                }
                tmp = tmp/10;
            }
            if (!tmp) res.push_back(i);
        }
        return res;
        
    }
};
```
