class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nmax=0,tmp=0;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(nums[i]==1){
                    tmp=1;
                    nmax=max(nmax,tmp);
                }
                continue;
            }
            if(nums[i]==nums[i-1] && nums[i]==1){
                tmp++;
                nmax=max(nmax,tmp);
            }else if(nums[i]==1){
                tmp=1;
                nmax=max(nmax,tmp);
            }
        }
        return nmax;
    }
};