// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int fit(int x){
        long long int pro=1;
        for(int i=1;i<=x;i++) pro*=i;
        return pro;
    }
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        long long int pro=1;
        if(n>m) {swap(m,n);}
        for(int i=m+n-2;i>m-1;i--) {pro*=i;}
        return pro/fit(n-1);
    }
};