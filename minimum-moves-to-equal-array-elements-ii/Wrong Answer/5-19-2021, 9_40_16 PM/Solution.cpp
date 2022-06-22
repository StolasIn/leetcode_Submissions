// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        int m=nums.size();
        for(int i=0;i<m;i++){
            sum+=nums[i];
        }
        double d=sum/m;
        int best;
        if(d-floor(d)>0.5){
            best=(int)d+1;
        }
        else{
            best=(int)d;
        }
        sum=0;
        for(int i=0;i<m;i++){
            sum+=abs(nums[i]-best);
        }
        return sum;
    }
};