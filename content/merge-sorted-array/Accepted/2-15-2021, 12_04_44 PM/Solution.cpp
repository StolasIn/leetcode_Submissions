// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> com(nums1.begin(),nums1.begin()+m);
        vector<int> ans;
        int cnt=0,l=0,r=0;
        com.emplace_back(INT_MAX);
        nums2.emplace_back(INT_MAX);
        while(cnt<=m+n){
            if(com[l]<=nums2[r]){
                ans.emplace_back(com[l]);
                l++;
            }
            else{
                ans.emplace_back(nums2[r]);
                r++;
            }
            cnt++;
        }
        ans.pop_back();
        nums1.clear();
        nums1.assign(ans.begin(),ans.end());
    }
};