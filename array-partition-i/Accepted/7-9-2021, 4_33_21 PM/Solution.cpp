// https://leetcode.com/problems/array-partition-i

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int sum=0;
        for(int i=0;i<nums.size();i+=2){
            sum+=min(nums[i],nums[i+1]);
        }
        return sum;
    }
};