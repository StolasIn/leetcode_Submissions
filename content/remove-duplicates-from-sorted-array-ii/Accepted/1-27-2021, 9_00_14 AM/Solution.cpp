// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int vis=0;
        vector<int> ans;
        int k;
        int cnt=0;
        int n=nums.size();
        k=nums[0];
        //ans.emplace_back(nums[0]);
        for(int i=0;i<n;i++){
            if(k==nums[i] && vis<=1) ans.emplace_back(nums[i]);
            if(k!=nums[i]){
                vis=1;
                k=nums[i];
                ans.emplace_back(nums[i]);
            }
            else{
                vis++;
            }
        }
        nums.clear();
        nums.assign(ans.begin(),ans.end());
        return ans.size();
    }
};