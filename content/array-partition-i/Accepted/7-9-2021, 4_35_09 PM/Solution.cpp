// https://leetcode.com/problems/array-partition-i

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i+=2) {
            res += nums[i];
        }
        return res;
    }
};