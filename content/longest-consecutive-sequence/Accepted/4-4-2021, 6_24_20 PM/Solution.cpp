// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        unique(nums.begin(),nums.end());
        int m=nums.size();
        int cnt=1;
        int ma=1;
        for(int i=1;i<m;i++){
            if(nums[i]==nums[i-1]+1){
                cnt++;
                ma=max(ma,cnt);
            }
            else{
                cnt=1;
            }
        }
        return ma;
    }
};