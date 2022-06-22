// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> ans;
    unordered_set<string> s;
    void gen(int n,string& now){
        if(n==0) s.insert(now);
        else{
            string tmp = "()"+now;
            gen(n-1,tmp);
            tmp = "("+now+")";
            gen(n-1,tmp);
            tmp = now + "()";
            gen(n-1,tmp);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str;
        gen(n,str);
        for(auto& i : s){
            ans.emplace_back(i);
        }
        return ans;
    }
};