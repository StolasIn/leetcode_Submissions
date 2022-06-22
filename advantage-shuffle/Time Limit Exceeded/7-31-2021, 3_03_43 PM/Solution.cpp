// https://leetcode.com/problems/advantage-shuffle

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<int> ans(nums1.size());
        for(int i=0;i<nums2.size();i++){
            auto tmp = upper_bound(nums1.begin(),nums1.end(),nums2[i]);
            if(tmp==nums1.end()){
                ans[i]=*nums1.begin();
                nums1.erase(nums1.begin());
                continue;
            }
            ans[i]=*tmp;
            nums1.erase(tmp);
        }
        return ans;
    }
};