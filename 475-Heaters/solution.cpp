class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int len1=houses.size(), len2=heaters.size();
        if(heaters[0]>=houses[len1-1]) return (heaters[0]-houses[0]);
        if(heaters[len2-1]<=houses[0]) return (houses[len1-1]-heaters[len2-1]);
        int left=0, right=min(max(abs(heaters[0]-houses[0]), abs(houses[len1-1]-heaters[0])),
                              max(abs(heaters[len2-1]-houses[len1-1]), abs(heaters[len2-1]-houses[0])));
        while(left<right){
            long long mid=left+(right-left)/2;
            int valid=checkValid(mid, houses, heaters);
            // 说明半径还不够大
            if(valid==-1) left=mid+1;
            else right=mid;
        }
        return left;
    }
    int checkValid(long long radius, vector<int>& houses, vector<int>& heaters){
        int l1=houses.size(), l2=heaters.size(), i=0, j=0;
        while(i<l1 && j<l2){
            if(heaters[j]>=houses[i]){
                if(heaters[j]-radius<=houses[i]) i++;
                else j++;
            }else if(heaters[j]<=houses[i]){
                if((long long)heaters[j]+radius>=houses[i]) i++;
                else j++;
            }
        }
        // 说明房子没有全部遍历完
        if(i!=l1) return -1;
        else return 0;
    }
};