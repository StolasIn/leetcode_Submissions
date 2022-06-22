// https://leetcode.com/problems/thousand-separator

class Solution {
public:
    string thousandSeparator(int n) {
        string ans = "";
        int cnt = 0;
        while(n!=0){
            if(cnt!=0 && cnt%3==0){
                ans = '.' + ans;
            }
            ans = (char)(n%10 + '0') + ans;
            cnt++;
            n/=10;
        }
        return ans;
    }
};