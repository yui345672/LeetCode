class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        // 就是利用如果两个数不一样，那么它们就进行相互的抵消
        // 然后最后剩下来的那个数肯定是超过 n/2 次的
        int count=0;
        int candidate=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                candidate=nums[i];
                count++;
            }else{
                if(candidate==nums[i]) count++;
                else count--;
            }
        }
        return candidate;
    }
};