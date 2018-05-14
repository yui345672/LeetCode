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
                // 修改了一下，第二种将字符转化为数字的方式是使用STL的stoi
                int round = stoi(ops[i]);
                ans += round;
                points.push_back(round);
            }
        }
        return ans;
    }
};