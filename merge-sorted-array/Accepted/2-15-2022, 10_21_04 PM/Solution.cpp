// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int l=0,r=0;
        while(l<m || r<n){
            if(l<m && r<n){
                if(nums1[l] < nums2[r]){
                    ans.emplace_back(nums1[l]);
                    l++;
                }
                else{
                    ans.emplace_back(nums2[r]);
                    r++;
                }
            }
            else if(l<m){
                ans.emplace_back(nums1[l]);
                l++;
            }
            else{
                ans.emplace_back(nums2[r]);
                r++;
            }
        }
        nums1 = ans;
    }
};