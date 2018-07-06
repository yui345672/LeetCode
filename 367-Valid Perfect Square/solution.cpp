class Solution {
public:
    bool isPerfectSquare(int num) {
        int flag=judgeSquare(0, num, num);
        if(flag==-1) return false;
        else return true;
    }
    long long f(long long x){
        return x*x;
    }
    int judgeSquare(int left, int right, int num){
        long long mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(f(mid)>num){
                right=mid-1;
            }else if(f(mid)<num){
                left=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};