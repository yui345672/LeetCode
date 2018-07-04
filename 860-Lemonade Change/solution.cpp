class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f[21]={0};
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5) f[5]++;
            else if(bills[i]==10){
				// 注意这里要写成 >= 0，而不是 !=0
                if(f[5]-1>=0) f[5]--,f[10]++;
                else{
                    return false;
                }
            }else if(bills[i]==20){
                if(f[10]-1>=0 && f[5]-1>=0){
                    f[10]--; f[5]--;
                }else if(f[5]-3>=0){
                    f[5] -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};