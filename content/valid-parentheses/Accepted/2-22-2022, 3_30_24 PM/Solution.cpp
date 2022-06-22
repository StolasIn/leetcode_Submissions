// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        vector<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.emplace_back(s[i]);
            }
            else if(st.size()!=0 && s[i]==')' && st.back()=='('){
                st.pop_back();
            }
            else if(st.size()!=0 && s[i]=='}' && st.back()=='{'){
                st.pop_back();
            }
            else if(st.size()!=0 && s[i]==']' && st.back()=='['){
                st.pop_back();
            }
            else{
                return false;
            }
        }
        return st.size()==0 ? true : false;
    }
};