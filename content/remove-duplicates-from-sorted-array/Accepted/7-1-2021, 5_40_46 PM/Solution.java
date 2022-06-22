// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int indexToSet = 0;
        int prev = -101;
        for (int i = 0 ; i < nums.length ; i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            nums[indexToSet] = nums[i];
            indexToSet++;
        }
        return indexToSet;
    }
}