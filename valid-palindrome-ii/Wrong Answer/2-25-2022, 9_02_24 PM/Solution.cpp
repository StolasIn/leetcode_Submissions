// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int m = s.size();
        int l=0,r=m-1;
        int cnt=0;
        while(r>l){
            if(s[l]!=s[r]){
                cnt++;
                if(l+1<m && s[l+1]==s[r]){
                    l++;
                }
                else{
                    r--;
                }
            }
            else{
                l++;
                r--;
            }
            if(cnt>=2){
                return false;
            }
        }
        return true;
    }
};