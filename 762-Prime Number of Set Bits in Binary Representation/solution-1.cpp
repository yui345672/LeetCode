class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int flag[21];
        memset(flag,0,sizeof(flag));
        flag[2]=flag[3]=flag[5]=flag[7]=flag[11]=flag[13]=flag[17]=flag[19]=1;
        int ans=0;
        for(int i=L; i<=R; i++){
            int num=0,tmp=i;
            while(tmp){
                int wei=tmp%2;
                if(wei==1) num++;
                tmp /= 2;
            }
            if(flag[num]) ans++;
        }
        return ans;
    }
};