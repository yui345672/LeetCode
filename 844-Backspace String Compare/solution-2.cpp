class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string newS, newT;
        for(int i=0; i<S.length(); i++){
            if(S[i]=='#'){
                if(!newS.empty()) newS.pop_back();
            }else{
                newS += S[i];
            }
        }
        for(int i=0; i<T.length(); i++){
            if(T[i]=='#'){
                if(!newT.empty()) newT.pop_back();
            }else{
                newT += T[i];
            }
        }
        if(newS==newT) return true;
        else return false;
    }
};