class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper=0, lower=0;
        int flag=0;
        for(int i=0; i<word.size(); i++){
            if(i==0 && isupper(word[i])){
                flag=1;
                continue;
            }
            if(isupper(word[i])) upper=1;
            else if(islower(word[i])) lower=1;
        }
        if(word.size()>1 && flag && !upper) return true;
        if((upper || flag) && lower) return false;
        else return true;
    }
};