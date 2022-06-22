// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int m = s.size();
        int ans = 0;
        long long int cnt = 1;
        for(int i=m-1;i>=0;i--){
            ans+=(s[i]-'A'+1) * cnt;
            cnt *= 26;
        }
        return ans;
    }
};