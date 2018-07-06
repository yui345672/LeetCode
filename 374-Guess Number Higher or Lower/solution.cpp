// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number should be lower, 1 if my number should be higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left=1, right=n, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            int flag=guess(mid);
            if(flag==1){
                left=mid+1;
            }else if(flag==-1){
                right=mid-1;
            }else if(flag==0){
                return mid;
            }
        }
        return -1;
    }
};