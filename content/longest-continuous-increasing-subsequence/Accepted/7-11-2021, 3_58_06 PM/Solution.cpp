// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int m=nums.size();
        if(m==1) return 1;
        int cnt=0;
        int ma=-1;
        nums.emplace_back(-INT_MAX);
        for(int i=1;i<m+1;i++){
            cnt++;
            ma=max(ma,cnt);
            if(nums[i]<=nums[i-1]){
                cnt=0;
            }
        }
        return ma;
    }
};