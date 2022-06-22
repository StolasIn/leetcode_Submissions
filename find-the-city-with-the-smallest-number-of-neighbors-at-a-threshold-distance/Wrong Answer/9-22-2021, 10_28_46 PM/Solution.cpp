// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

struct node{
    int to,d;
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int dis) {
        int d[n][n];
        int c,ans,mi=INT_MAX;
        memset(d,0,sizeof(d));
        for(int i=0;i<e.size();i++){
            d[e[i][0]][e[i][1]]=d[e[i][1]][e[i][0]]=e[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(d[j][k]>d[j][i]+d[i][k]){
                        d[j][k]=d[j][i]+d[i][k];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(d[i][j]<=dis){
                    c++;
                }
            }
            if(c<=mi){
                mi=c;
                ans=i;
            }
        }
        return ans;
    }
};