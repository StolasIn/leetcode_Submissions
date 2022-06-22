// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        for(int i=sh.size()-1;i>0;i--){
            sh[i-1]=(sh[i]+sh[i-1])%26;
        }
        for(int i=0;i<s.size();i++){
            s[i]=((s[i]-'a')+sh[i])%26+'a';
        }
        return s;
    }
};