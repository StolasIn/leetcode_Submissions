// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        int n=s.size();
        int n1=n/2;
        for(int i=0;i<n1;i++){
            swap(s[i],s[n-i-1]);
        }
    }
};