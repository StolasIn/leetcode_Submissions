// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        set<int,greater<int>> s;
        int m=nums.size();
        for(int i=0;i<m;i++){
            s.insert(nums[i]);
        }
        int cnt=0;
        for(auto i : s){
            cnt++;
            if(cnt==3){
                return i;
            }
        }
        return 0;
    }
};