// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int ma = -1,s = 0,e = 0;
        int m = nums.size();
        int cnt = 0;
        while(e<m-1){
            cnt++;
            ma = -1;
            for(int i=s;i<=e;i++){
                if(ma<i+nums[i]){
                    ma=i+nums[i];
                    s = i;
                }
            }
            e = s+nums[s];
        }
        return cnt;
    }
};