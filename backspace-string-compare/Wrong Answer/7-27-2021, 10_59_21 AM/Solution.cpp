// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st1;
        string st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st1.empty()){
                    st1.pop_back();
                }
            }
            else{
                st1+=s[i];
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!st2.empty()){
                    st2.pop_back();
                }
            }
            else{
                st2+=s[i];
            }
        }
        return st1==st2;
    }
};