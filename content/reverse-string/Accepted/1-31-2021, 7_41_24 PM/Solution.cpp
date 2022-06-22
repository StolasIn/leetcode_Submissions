// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        int n=s.size();
        for(int i=0;i<(n)/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
};