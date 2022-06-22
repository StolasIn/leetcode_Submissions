// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        for(int i=0;i<n+1;i++){
            ans += m[pre[i]+k] + m[pre[i]-k];
            m[pre[i]]++;
        }
        return ans;
    }
};