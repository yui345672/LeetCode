class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> st;
        for(int i=0; i<candies.size(); i++){
            st.insert(candies[i]);
        }
        int mpSize = st.size();
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