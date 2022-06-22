// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        int m = s.size();
        int n = m>>1;
        for(int i=0;i<n;i++){
            swap(s[i],s[m-i-1]);
        }
    }
};