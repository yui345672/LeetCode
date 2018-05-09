class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans;
        for(int i=0; i<S.length(); i++){
            if(S[i] == C) ans.push_back(i);
        }
        vector<int> dis;
        int idx = 0;
        for(int i=0; i<S.length(); i++){
            int c_dis;
            if(i<=ans[idx]){
                if(idx == 0){
                    c_dis = ans[idx] - i;
                    dis.push_back(c_dis);
                }else{
                    c_dis = min(ans[idx]-i, i-ans[idx-1]);
                    dis.push_back(c_dis);
                }
            }else{
                // 这里边界条件忘记判断了..
                if(idx+1 < ans.size()){
                    idx++;
                    c_dis = min(i-ans[idx-1], ans[idx]-i);
                }else{
                    c_dis = i-ans[idx];
                }
                dis.push_back(c_dis);
            }
        }
        return dis;
    }
};