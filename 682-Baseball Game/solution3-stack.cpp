class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> sk;
        int ans=0;
        for(int i=0; i<ops.size(); i++){
            if(ops[i]=="+"){
                int sktop1 = sk.top();
                sk.pop();
                int sktop2 = sk.top();
                ans += sktop1 + sktop2;
                sk.push(sktop1);
                sk.push(sktop1 + sktop2);
            }else if(ops[i]=="D"){
                ans += sk.top()*2;
                sk.push(sk.top()*2);
            }else if(ops[i]=="C"){
                ans -= sk.top();
                sk.pop();
            }else{
                ans += stoi(ops[i]);
                sk.push(stoi(ops[i]));
            }
        }
        return ans;
    }
};