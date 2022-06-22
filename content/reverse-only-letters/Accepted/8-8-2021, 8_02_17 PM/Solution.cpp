// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string& s) {
        string str="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                str+=s[i];
            }
        }
        reverse(str.begin(),str.end());
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                s[i]=str[cnt++];
            }
        }
        return s;
    }
};