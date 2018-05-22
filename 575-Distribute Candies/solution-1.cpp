class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,int> mp;
        for(int i=0; i<candies.size(); i++){
            mp[candies[i]]++;
        }
        int mpSize = mp.size();
        int candSize = candies.size();
        int ans = 0;
        if(mpSize*2 >= candSize){
            ans = candSize/2;
        }else if(mpSize*2 < candSize){
            ans = mpSize;
        }
        return ans;
    }
};