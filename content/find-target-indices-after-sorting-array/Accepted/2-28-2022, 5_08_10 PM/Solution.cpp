// https://leetcode.com/problems/find-target-indices-after-sorting-array

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        int cnt = 0;
        int sml = 0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==t){
                cnt++;
            }
            if(nums[i]<t){
                sml++;
            }
        }
        for(int i=sml;i<sml+cnt;i++){
            ans.emplace_back(i);
        }
        return ans;
    }
};