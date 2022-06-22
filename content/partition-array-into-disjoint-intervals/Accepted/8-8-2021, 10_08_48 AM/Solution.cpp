// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int ma=nums[0];
        int l=0;
        int r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<ma){
                l=i;
                while(r<=l){
                    ma=max(ma,nums[r]);
                    r++;
                }
            }
        }
        return l+1;
    }
};