// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
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