class Solution {
public:
    int arrangeCoins(int n) {
        // 边界条件不要忘记处理
        if(n==0) return 0;
        if(n==1) return 1;
        // 要注意 n*2 可能会超出 int 的范围，所以这里就要进行强制转化了
        long long tmp=(long long)n*2;
        int left=0, right=sqrt(tmp)+1, mid;
        while(left<right){
            mid=left+(right-left)/2;
            long long tmp=f(mid);
            if(tmp<=n){
                left=mid+1;
            }else if(tmp>n){
                right=mid;
            }
        }
        return left-1;
    }
    long long f(int n){
        // 注意这里在乘的时候也会超过 int 的范围!!! 要注意!!!
        return ((long long)n*n + n)/2;
    }
};