// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int m=nums.size();
        vector<int> v;
        int ch[m];
        memset(ch,0,sizeof(ch));
        v.emplace_back(nums[0]);
        for(int i=1;i<m;i++){
            if(v.back()<nums[i]){
                v.emplace_back(nums[i]);
            }
            else{
                int tmp=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[tmp]=nums[i];
                ch[tmp]++;
            }
        }
        int ans=1;
        for(int i=0;i<m;i++){
            if(ch[i]!=0) ans*=ch[i]+1;
        }
        return ans;
    }
};