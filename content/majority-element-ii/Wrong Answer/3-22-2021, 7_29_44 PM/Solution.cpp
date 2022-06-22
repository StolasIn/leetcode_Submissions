// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int k=(nums.size()/3);
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            map[nums[i]]++;
            if(map[nums[i]]>k){
                ans.emplace_back(nums[i]);
            }
        }
        return ans;
    }
};