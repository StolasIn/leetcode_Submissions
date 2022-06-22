// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int m=nums.size();
        int l,r;
        for(int i=0;i<m;i++){
            l=i+1;
            r=m-1;
            while(r>l){
                if(nums[i]+nums[l]>nums[r]){
                    cnt+=(r-l);
                    break;
                }
                else{
                    int r1=r;
                    int l1=l;
                    while(nums[i]+nums[l]<=nums[r1]){
                        r1--;
                    }
                    while(nums[i]+nums[l1]<=nums[r]){
                        l1++;
                    }
                    cnt+=(max(r-l1,r1-l)+1);
                    break;
                }
            }
        }
        return cnt;
    }
};