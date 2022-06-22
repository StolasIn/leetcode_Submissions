// https://leetcode.com/problems/count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        map<int,int> map;
        int m = nums.size();
        int ans = 0;
        map[nums[m-1] - nums[m-2]] = 1;
        for(int i=m-3;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                ans+=map[nums[i]+nums[j]];
            }
            for(int j=m-1;j>i;j--){
                map[nums[j]-nums[i]]++;
            }
        }
        return ans;
    }
};