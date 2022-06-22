// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
   int sumOddLengthSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += ((i + 1) * (n - i) + 1) / 2 * nums[i];
        }
        return ans;
    }
};