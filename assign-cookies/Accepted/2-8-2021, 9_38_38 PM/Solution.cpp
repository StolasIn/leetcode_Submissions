// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m=g.size();
        int n=s.size();
        int fir=0;
        int las=0;
        int cnt=0;
        while(fir<m && las<n){
            if(g[fir]<=s[las]){
                cnt++;
                fir++;
                las++;
            }
            else{
                las++;
            }
        }
        return cnt;
    }
};