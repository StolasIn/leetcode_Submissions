// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& nums, int l, int r) {
        int v[52] = {0};
        for(int i=0;i<nums.size();i++){
            v[nums[i][0]]++;
            v[nums[i][1]+1]--;
        }
        for(int i=1;i<=r;i++){
            v[i] += v[i-1];
        }
        for(int i=l;i<=r;i++){
            if(v[i]<=0){
                return false;
            }
        }
        return true;
    }
};