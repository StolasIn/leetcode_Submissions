// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> ans;
    void dfs(string& s,int ind){
        if(ind>=s.size()) return;
        if(isdigit(s[ind])==true){
            dfs(s,ind+1);
        }
        else{
            dfs(s,ind+1);
            if(s[ind]>='a') s[ind]-=32;
            else if(s[ind]<='Z') s[ind]+=32;
            ans.emplace_back(s);
            dfs(s,ind+1);
            if(s[ind]>='a') s[ind]-=32;
            else if(s[ind]<='Z') s[ind]+=32;
        }
    }
    vector<string> letterCasePermutation(string s) {
        dfs(s,0);
        ans.emplace_back(s);
        return ans;
    }
};