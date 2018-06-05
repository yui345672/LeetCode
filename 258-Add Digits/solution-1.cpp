class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        while(num){
            ans+=num%10;
            num=num/10;
        }
        int wei1=ans%10;
        int wei2=(ans/10)%10;
        int wei=wei1+wei2;
        if(wei/10){
            wei1=wei%10;
            wei2=(wei/10)%10;
            wei=wei1+wei2;
        }
        return wei;
    }
};