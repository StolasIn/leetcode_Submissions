// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                sta.push(s[i]);
            }
            else{
                if(sta.size()!=0 && sta.top()=='(' && s[i]==')'){
                    sta.pop();
                }
                else if(sta.size()!=0 &&sta.top()=='[' && s[i]==']'){
                    sta.pop();
                }
                else if(sta.size()!=0 &&sta.top()=='{' && s[i]=='}')
                {
                    sta.pop();
                }
                else{
                    break;
                }
            }
        }
        if(sta.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};