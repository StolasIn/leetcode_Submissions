// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    int n1;
    vector<vector<int>> ans;
    void all(vector<int>& nums,vector<int> now,vector<bool> vis){
        if(now.size()==n1){
            ans.push_back(now);
            return;
        }
        for(int i=0;i<n1;i++){
            if(!vis[i]){
                vis[i]=true;
                now.emplace_back(nums[i]);
                all(nums,now,vis);
                now.pop_back();
                vis[i] = false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<char> c;
        string str;
        n1=n;
        for(int i=0;i<n;i++){
             nums.push_back(i+1);
        }
        vector<bool> vis(9,false);
        vector<int> now;
        all(nums,now,vis);
        for(int i=ans[k+1].size()-1;i>=0;i--){
            c.push_back(ans[k+1][i]+48);
        }
        for(int i=0;i<c.size();i++){
            str+=c[i];
        }
        return str;
    }
};