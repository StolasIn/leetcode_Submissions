// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int m=nums.size();
        vector<int> tmp;
        vector<int> ans;
        bool vis[m];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<m;i++){
            if(vis[i]==true) continue;
            tmp.clear();
            tmp.emplace_back(nums[i]);
            vis[i]=true;
            for(int j=i+1;j<m;j++){
                if(nums[j]%tmp.back()==0){
                    tmp.emplace_back(nums[j]);
                    vis[j]=true;
                }
            }
            if(ans.size()<tmp.size()){
                ans.assign(tmp.begin(),tmp.end());
            }
        }
        return ans;
    }
};