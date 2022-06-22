// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        vector<int> v;
        int f,m,ans=0;
        for(int i=g.size()-1;i>=0;i--){
            v.emplace_back(g[i][0]);
        }
        f=lower_bound(v.begin(),v.end(),0)-v.begin();
        cout<<f<<endl;
        for(int i=0;i<v.size()-f;i++){
            ans+=lower_bound(g[i].begin(),g[i].end(),0)-g[i].begin();
        }
        ans+=f*g[0].size();
        return ans;
    }
};