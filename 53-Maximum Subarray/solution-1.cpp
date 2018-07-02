class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, lmax=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]<0){
                lmax=max(lmax,sum+nums[i]);
                sum=0;
                continue;
            }
            if(sum+nums[i]>=0){
                sum += nums[i];
                lmax=max(lmax, sum);
            }
        }
        return lmax;
    }
};