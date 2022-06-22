// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> ans;
    set<string> s;
    void gen(int n,string& now){
        if(n==0) s.insert(now);
        else{
            string tmp = "()"+now;
            gen(n-1,tmp);
            string tmp1 = "("+now+")";
            gen(n-1,tmp1);
            string tmp2 = now + "()";
            gen(n-1,tmp2);
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