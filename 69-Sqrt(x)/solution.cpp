class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int left=0, right=x, mid;
        while(right>left){
            mid=left+(right-left)/2;
            if(f(mid)-x>0) right=mid;
            else{
                left=mid+1;
            }
        }
        return left-1;
    }
    double f(double x){
        return x*x;
    }
};