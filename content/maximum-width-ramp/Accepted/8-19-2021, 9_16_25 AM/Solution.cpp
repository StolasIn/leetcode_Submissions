// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int m = nums.size();
        int l[m],r[m];
        l[0]=nums[0];
        r[m-1]=nums[m-1];
        for(int i=1;i<m;i++){
            l[i]=min(l[i-1],nums[i]);
        }
        for(int i=m-2;i>=0;i--){
            r[i]=max(r[i+1],nums[i]);
        }
        int i=0,j=0;
        int ans=-1;
        while(i<=j && j<m){
            if(l[i]<=r[j]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};