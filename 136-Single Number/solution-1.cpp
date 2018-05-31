class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        int num;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]<=1){
                num=nums[i];
                break;
            }
        }
        return num;
    }
};