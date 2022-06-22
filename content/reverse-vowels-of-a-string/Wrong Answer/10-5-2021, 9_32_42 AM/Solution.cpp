// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    bool isv(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while(r>l){
            while(!isv(s[l])) l++;
            while(!isv(s[r])) r--;
            if(r<l) break;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};