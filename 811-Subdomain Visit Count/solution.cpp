class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> mp;
        mp.clear();
        for(int i=0; i<cpdomains.size(); i++){
            vector<int> nums;
            int idx = -2;
            for(int j=0; j<cpdomains[i].size(); j++){
                if(cpdomains[i][j] == ' ') {
                    idx = j;
                    break;
                }
                nums.push_back(cpdomains[i][j]-'0');
            }
            int jj=1, sum=0;
            for(int j=nums.size()-1; j>=0; j--){
                sum += nums[j] * jj;
                jj = jj * 10;
            }
            string str="";
            int point1=-999, point2=-999;
            for(int j=idx+1; j<cpdomains[i].size(); j++){
                str += cpdomains[i][j];
                if(cpdomains[i][j] == '.'){
                    if(point1==-999) point1 = j;
                    else if(point2==-999) point2 = j;
                }
            }
            mp[str] += sum;
            if(point2!=-999){
                str="";
                for(int j=point2+1; j<cpdomains[i].size(); j++){
                    str += cpdomains[i][j];
                }
                mp[str] += sum;
            }
            if(point1!=-999){
                str="";
                for(int j=point1+1; j<cpdomains[i].size(); j++){
                    str += cpdomains[i][j];
                }
                mp[str] += sum;
            }
        }
        map<string,int>::iterator it;
        vector<string> ans;
        for(it=mp.begin(); it!=mp.end(); it++){
            string str="";
            // 下面那个我一开始忘记把int转成string了,所以一直乱码..
            str=to_string(it->second);
            str += " ";
            str += it->first;
            ans.push_back(str);
        }
        return ans;
    }
};