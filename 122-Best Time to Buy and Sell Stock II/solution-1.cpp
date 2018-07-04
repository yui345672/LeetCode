class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int lmin=prices[0], lmax=prices[0];
        int sum=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>=lmax){
                // 如果它是一个递增的序列
                lmax=prices[i];
                if(i==prices.size()-1){
                    sum+=lmax-lmin;
                }
            }else if(prices[i]<lmax){
                // 突然递减了
                sum+=lmax-lmin;
                lmin=prices[i];
                lmax=prices[i];
            }
        }
        return sum;
    }
};