// https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long int now=0;
        for(int i=0;i<nums.size();i++){
            now=now*2+nums[i];
            if(now%5==0){
                ans.emplace_back(true);
            }
            else{
                ans.emplace_back(false);
            }
            now%=5;
        }
        return ans;
    }
};