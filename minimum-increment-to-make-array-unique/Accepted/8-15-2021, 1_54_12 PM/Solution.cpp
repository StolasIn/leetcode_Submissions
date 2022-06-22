// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> s;
        sort(nums.begin(),nums.end());
        int m = nums.size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
            else{
                int t = *s.rbegin();
                ans+=(t-nums[i]+1);
                s.insert(t+1);
            }
        }
        return ans;
    }
};