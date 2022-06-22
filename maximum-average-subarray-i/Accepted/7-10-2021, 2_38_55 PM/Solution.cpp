// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum=0;
        int ma;
        int m=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ma=sum;
        for(int i=0;i+k<m;i++){
            sum-=nums[i];
            sum+=nums[i+k];
            ma=max(ma,sum);
        }
        return (double)ma/k;
    }
};