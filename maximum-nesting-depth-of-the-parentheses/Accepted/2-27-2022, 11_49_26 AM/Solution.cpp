// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        string cs = "";
        stack<char> st;
        int ma = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                cs+=s[i];
            }
        }
        for(int i=0;i<cs.size();i++){
            if(cs[i] == '('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
            ma = max(ma,(int)st.size());
        }
        return ma;
    }
};