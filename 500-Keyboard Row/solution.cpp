class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char l1[15] = {'q','w','e','r','t','y','u','i','o','p'};
        char l2[15] = {'a','s','d','f','g','h','j','k','l'};
        char l3[15] = {'z','x','c','v','b','n','m'};
        map<int,int> mp;
        mp.clear();
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            mp.clear();
            for(int j=0; j<words[i].size(); j++){
                int ff=0;
                for(int k=0; k<strlen(l1); k++){
                    if(l1[k]==tolower(words[i][j])) ff++;
                }
                if(ff) {
                    mp[1]++;
                    continue;
                }
                ff=0;
                for(int k=0; k<strlen(l2); k++){
                    if(l2[k]==tolower(words[i][j])) ff++;
                }
                if(ff) {
                    mp[2]++;
                    continue;
                }
                ff=0;
                for(int k=0; k<strlen(l3); k++){
                    if(l3[k]==tolower(words[i][j])) ff++;
                }
                if(ff){
                    mp[3]++;
                    continue;
                }
            }
            if(mp.size()>1) continue;
            ans.push_back(words[i]);
        }
        return ans;
    }
};