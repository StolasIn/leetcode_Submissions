// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
     int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int i=0;i<nums.size();i++) {
            curMax = max(curMax + nums[i], nums[i]);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + nums[i], nums[i]);
            minSum = min(minSum, curMin);
            total += nums[i];
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};