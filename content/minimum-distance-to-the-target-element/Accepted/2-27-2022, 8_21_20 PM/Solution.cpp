// https://leetcode.com/problems/minimum-distance-to-the-target-element

class Solution {
public:
    int getMinDistance(vector<int>& nums, int t, int start) {
        int i = 0, sz = nums.size();
        while (nums[max(0, start - i)] != t && nums[min(start + i, sz - 1)] != t)
            ++i;
        return i;
    }
};