class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=1, j=1, len=nums.size();
        if(len==0 || len==1) return len;
        while(j<len){
            if(nums[j]!=nums[i-1]){
                nums[i]=nums[j];
                i++; j++;
            }else if(nums[j]==nums[i-1]){
                j++;
            }
        }
        return i;
    }
};