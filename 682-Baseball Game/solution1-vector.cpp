class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        vector<int> points;
        for(int i=0; i<ops.size(); i++){
            char c=ops[i].at(0);
            if(c=='+'){
                int len=points.size();
                int round=points[len-1]+points[len-2];
                ans += round;
                points.push_back(round);
            }else if(c=='D'){
                int round=points.back()*2;
                ans += round;
                points.push_back(round);
            }else if(c=='C'){
                ans -= points.back();
                points.pop_back();
            }else{
                int round=0, jj=1, ff=0;
                for(int j=ops[i].size()-1; j>=0; j--){
                    if(ops[i][j]=='-'){
                        ff=1; continue;
                    }
                    round += (ops[i][j]-'0')*jj;
                    jj=jj*10;
                }
                if(ff) round = -round;
                ans += round;
                points.push_back(round);
            }
        }
        return ans;
    }
};