// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> two_sum(vector<int>& v,int l,int r,int t){
        vector<vector<int>> ans;
        int l1=l;
        while(r>l){
            if(v[l]+v[r]>t || (r<v.size()-1 && v[r]==v[r+1])){
                r--;
            }
            else if(v[l]+v[r]<t || (l>l1 && v[l]==v[l-1])){
                l++;
            }
            else{
                ans.emplace_back(vector<int>{v[l],v[r]});
                l++;
                r--;
            }
        }
        return ans;
    }
    vector<vector<int>> k_sum(vector<int>& v,int l,int r,int k,int t){
        vector<vector<int>> ans;
        if(l==v.size() || v[l]*k>t || v[r]*k<t) return ans;
        if(k==2) return two_sum(v,l,r,t);
        for(int i=l;i<=r;i++){
            if(i==l || v[i-1]!=v[i]){
                for(auto& j : k_sum(v,i+1,r,k-1,t-v[i])){
                    ans.emplace_back(vector<int>{v[i]});
                    ans.back().insert(ans.back().end(), j.begin(),j.end());
                }
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return k_sum(nums,0,nums.size()-1,4,target);
    }
};