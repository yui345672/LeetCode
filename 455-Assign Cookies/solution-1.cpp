class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        map<int,int> mp;
        mp.clear();
        int ans=0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(s[j]>=g[i] && mp[j]==0){
                    mp[j]=1;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};