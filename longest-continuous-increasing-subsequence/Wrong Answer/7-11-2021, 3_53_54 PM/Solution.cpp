// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int m=nums.size();
        int cnt=0;
        int ma=-1;
        bool flag=false;
        for(int i=1;i<m;i++){
            cnt++;
            ma=max(ma,cnt);
            if(nums[i]<=nums[i-1]){
                cnt=0;
                flag=true;
            }
        }
        if(flag==false) ma++;
        return ma;
    }
};