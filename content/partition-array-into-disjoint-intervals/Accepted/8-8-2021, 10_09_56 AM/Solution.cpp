// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ma=nums[0];
        int l=0;
        int ma1=0;
        for(int i=0;i<nums.size();i++){
            ma1=max(ma1,nums[i]);
            if(nums[i]<ma){
                l=i;
                ma=ma1;
            }
        }
        return l+1;
    }
};