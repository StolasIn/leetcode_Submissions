// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        int m = s.size();
        for(int i=0;i<m/2;i++){
            swap(s[i],s[m-i-1]);
        }
    }
};