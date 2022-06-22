// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int ma=-1;
        int mi=1e9;
        for(int i=0;i<nums.size();i++){
            ma=max(ma,nums[i]);
            mi=min(mi,nums[i]);
        }
        if(ma-mi<=2*k) return 0;
        return ma-mi-2*k;
    }
};