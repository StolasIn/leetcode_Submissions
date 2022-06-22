// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        int m0 = 0;
        int cnt0 = 0;
        int m1 = 0;
        int cnt1 = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0') cnt1 = 0;
            else cnt1++;
            if(s[i] == '1') cnt0 = 0;
            else cnt0++;
            m0 = max(cnt0,m0);
            m1 = max(cnt1,m1);
        }
        if(m1 > m0) return true;
        else return false;
    }
};