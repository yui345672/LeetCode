class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(), l2=nums2.size();
        sort(nums1.begin(), nums1.begin()+l1);
        sort(nums2.begin(), nums2.begin()+l2);
        set<int> st;
        vector<int> ans;
        int i=0, j=0;
        while(i<l1 && j<l2){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] == nums2[j]){
                st.insert(nums1[i]);
                i++; j++;
            }
        }
        ans.assign(st.begin(), st.end());
        return ans;
    }
};