// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1){
            return {nums[0]};
        }
        sort(nums.begin(),nums.end());
        int m=nums.size();
        int ma=0;
        vector<int> tmp(m,0);
        vector<int> ind(m,-1);
        vector<int> ans;
        int t;
        for(int i=0;i<m;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(tmp[i]<(tmp[j]+1)){
                        tmp[i]=tmp[j]+1;
                        ind[i]=j;
                        if(ma<tmp[i]){
                            ma=tmp[i];
                            t=i;
                        }
                    }
                }
            }
        }
        while(t>=0){
            ans.emplace_back(nums[t]);
            t=ind[t];
        }
        return ans;
    }
};