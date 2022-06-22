// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0;
        int m=nums.size();
        for(int i=0;i<m;i++){
            int t=nums[i];
            int ma=-1,s,j;
            for(j=i;j<=i+nums[i];j++){
                if(j>=m) break;
                if(ma<j+nums[j]){
                    ma=j+nums[j];
                    s=j;
                }
            }
            i=j;
            cnt++;
        }
        return cnt;
    }
};