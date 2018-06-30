class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        int n=nums.size() / 2;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            if((it->second)>n){
                return (it->first);
            }
        }
    }
};