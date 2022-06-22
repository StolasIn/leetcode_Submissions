// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<m;i++){
            map[nums1[i]]++;
        }
        for(int i=0;i<n;i++){
            if((map[nums2[i]]--)>=1){
                ans.emplace_back(nums2[i]);
            }
        }
        return ans;
    }
};