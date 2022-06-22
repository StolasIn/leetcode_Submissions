// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        long long int pro=1;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            sum+=pro*(s[i]-64);
            pro*=26;
        }
        return sum;
    }
};