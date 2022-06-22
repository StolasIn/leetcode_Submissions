// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> ans;
    void gen(string& now,int l,int r){
        if(l==0 && r==0){
            ans.emplace_back(now);
            return;
        }
        if(l>0){
            string s1=now+'(';
            gen(s1,l-1,r);
        }
        if(r>l){
            string s2=now+')';
            gen(s2,l,r-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str;
        gen(str,n,n);
        return ans;
    }
};