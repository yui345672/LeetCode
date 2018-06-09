class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, len=nums.size();
        if(len==0 || len==1) return len;
        for(int j=1; j<len; j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};