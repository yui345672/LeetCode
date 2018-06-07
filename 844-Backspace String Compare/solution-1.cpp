class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.length()-1, j=T.length()-1;
        int numS=0, numT=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(S[i]=='#') numS++, i--;
                else if(numS) numS--, i--;
                else break;
            }
            while(j>=0){
                if(T[j]=='#') numT++, j--;
                else if(numT) numT--, j--;
                else break;
            }
            // 如果两个实际的数字不相同的话
            if(i>=0 && j>=0 && S[i]!=T[j]) return false;
            if((i>=0 && j<0) || (i<0 && j>=0)) return false;
            i--, j--;
        }
        return true;
    }
};