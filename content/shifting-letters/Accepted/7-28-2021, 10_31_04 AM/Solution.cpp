// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string& s, vector<int>& sh) {
        int i;
        for(i=sh.size()-1;i>0;i--){
            sh[i-1]=(sh[i]+sh[i-1])%26;
        }
        for(i=0;i<s.size();i++){
            s[i]=((s[i]-97)+sh[i])%26+97;
        }
        return s;
    }
};