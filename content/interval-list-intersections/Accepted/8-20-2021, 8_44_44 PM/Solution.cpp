// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int l=0,r=0;
        vector<vector<int>> ans;
        while(l<f.size() && r<s.size()){
            int p1=max(f[l][0],s[r][0]);
            int p2=min(f[l][1],s[r][1]);
            if(p1<=p2)ans.emplace_back(vector<int>{p1,p2});
            if(p2==f[l][1]){
                l++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};