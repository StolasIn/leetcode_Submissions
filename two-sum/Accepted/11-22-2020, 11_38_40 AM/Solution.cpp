// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=0;j<nums.size();j++){
                sum=nums[i]+nums[j];
                if(sum==target){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        return ans;
    }
};