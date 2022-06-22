// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int fit(int x){
        long long int pro=1;
        for(int i=1;i<=x;i++) pro*=i;
        return pro;
    }
    int uniquePaths(int m, int n) {
        long long int a=fit(m+n-2);
        long long int b=fit(m-1);
        long long int c=fit(n-1);
        return a/(b*c);
    }
};