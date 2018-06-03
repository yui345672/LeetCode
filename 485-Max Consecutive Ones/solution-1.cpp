class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int dp[11111];
        memset(dp,0,sizeof(dp));
        int nmax=0;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(nums[i]==1){
                    dp[i]=1;
                    nmax=max(nmax,dp[i]);
                }
                continue;
            }
            if(nums[i]==nums[i-1] && nums[i]==1){
                dp[i]=dp[i-1]+1;
                nmax=max(nmax,dp[i]);
            }else if(nums[i]==1){
                dp[i]=1;
                nmax=max(nmax,dp[i]);
            }
        }
        return nmax;
    }
};