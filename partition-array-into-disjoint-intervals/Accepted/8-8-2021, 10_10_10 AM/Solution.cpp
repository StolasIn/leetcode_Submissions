// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int partitionIdx = 0, maxInLeft = nums[0], maxSoFar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            // 'maxInLeft' is the max value in the left partition [0, partitionIdx]
            // If it is a valid partition, then every value from 'partitionIdx + 1' to end
            // should be >= 'maxInLeft'. But if nums[i] < maxInLeft, it means we have to
            // incorporate nums[i] to the left partition and update 'partitionIdx' to i.
            if (nums[i] < maxInLeft) {
                maxInLeft = maxSoFar;
                partitionIdx = i;
            }
        }
        return partitionIdx + 1;
    }
};