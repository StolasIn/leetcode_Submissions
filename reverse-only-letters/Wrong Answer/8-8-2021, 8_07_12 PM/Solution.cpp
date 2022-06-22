// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string& s) {
        int j=s.size()-1;
        int m=s.size()/2;
        for(int i=0;i<m;i++){
            if(isalpha(s[i])){
                while(!isalpha(s[j]) && j>i){
                    j--;
                }
                swap(s[i],s[j]);
                j--;
            }
        }
        return s;
    }
};