// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        vector<int> ver(n+1,0);
        vector<vector<int>> g(n+1);
        for(int i=0;i<m;i++){
            ver[trust[i][1]]++;
            g[trust[i][0]].emplace_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(ver[i]==n-1 && g[i].empty()){
                return i;
            }
        }
        return -1;
    }
};