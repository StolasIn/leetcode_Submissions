// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            pre[i+1] = pre[i] + nums[i];
        }
        for(int i=0;i<n+1;i++){
            ans += m[pre[i]-goal];
            m[pre[i]]++;
        }
        return ans;
    }
};