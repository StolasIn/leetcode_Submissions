// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    unordered_map<int,int> dp;
    int re(vector<int>& v,int n){
        if(n<0){
            return 0;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        if(n<=1){
            return n * v[n];
        }
        return dp[n] = max(re(v,n-2),re(v,n-3)) + n * v[n];
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001,0);
        int n = nums.size();
        int ma = 0;
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
            ma = max(ma,nums[i]);
        }
        return max(re(v,ma),re(v,ma-1));
    }
};