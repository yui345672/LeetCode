class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return getMaxSum(nums, 0, nums.size()-1);
    }
    int getMergeMaxSum(vector<int>& nums, int mid, int l, int r){
        int lmax=-99999999,lsum=0;
        for(int i=mid; i>=l; i--){
            lsum+=nums[i];
            lmax=max(lmax, lsum);
        }
        int rmax=-99999999,rsum=0;
        for(int i=mid+1; i<=r; i++){
            rsum+=nums[i];
            rmax=max(rmax, rsum);
        }
        return (lmax+rmax);
    }
    int getMaxSum(vector<int>& nums, int l, int r){
        if(l==r){
            return nums[l];
        }
        int mid=(l+r)/2;
        int leftMax=getMaxSum(nums, l, mid);
        int rightMax=getMaxSum(nums, mid+1, r);
        int mergeMax=getMergeMaxSum(nums, mid, l, r);
        return max(mergeMax, max(leftMax, rightMax));
    }
};