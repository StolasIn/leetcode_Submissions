// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int fit(int x){
        long long int pro=1;
        for(int i=1;i<=x;i++) pro*=i;
        return pro;
    }
    int uniquePaths(int m, int n) {
        long long int pro=1;
        bool flag=0;
        if(n>m) {swap(m,n); flag=1;}
        for(int i=m+n-2;i>m-1;i--) {pro*=i;}
        return pro/(n-1);
    }
};