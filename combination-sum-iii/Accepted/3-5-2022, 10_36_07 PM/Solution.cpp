// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int>& now,int n,int k,int s){
        if(k<0 || s>9){
            return;
        }
        if(n==0 && k==0){
            ans.emplace_back(now);
        }
        for(int i=s+1;i<=9;i++){
            if(n-i<0){
                break;
            }
            now.emplace_back(i);
            re(now,n-i,k-1,i);
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> now;
        re(now,n,k,0);
        return ans;
    }
};