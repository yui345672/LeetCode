class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len=points.size();
        int num=0;
        map<int,int> mp;
        for(int i=0; i<len; i++){
            mp.clear();
            for(int j=0; j<len; j++){
                if(i==j) continue;
                int delX = (points[i].first-points[j].first)*(points[i].first-points[j].first);
                int delY = (points[i].second-points[j].second)*(points[i].second-points[j].second);
                int del = delX+delY;
                mp[del]++;
            }
            for(auto it=mp.begin(); it!=mp.end(); ++it){
                int ans = it->second;
                ans = ans*(ans-1);
                num += ans;
            }
        }
        return num;
    }
};