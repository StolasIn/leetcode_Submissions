// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool c1(string& s){
        int m=s.size();
        for(int i=0;i<m;i++){
            if('a'<=s[i] && s[i]<='z'){
                return false;
            }
        }
        return true;
    }
    bool c2(string& s){
        int m=s.size();
        for(int i=0;i<m;i++){
            if('A'<=s[i] && s[i]<='Z'){
                return false;
            }
        }
        return true;
    }
    bool c3(string& s){
        int m=s.size();
        if('a'<=s[0] && s[0]<='a'){
            return false;
        }
        for(int i=1;i<m;i++){
            if('A'<=s[i] && s[i]<='Z'){
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        return c1(word)|c2(word)|c3(word);
    }
};