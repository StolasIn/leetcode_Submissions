// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> ans;
    int s1;
    void per(vector<int>& n,int x,set<vector<int>>& s){
        if(x==s1) s.insert(n);
        for(int i=x;i<s1;i++){
            if(i>x && n[i]==n[i-1]) continue;
            swap(n[i],n[x]);
            per(n,x+1,s);
            swap(n[i],n[x]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& n) {
        set<vector<int>> s;
        s1=n.size();
        per(n,0,s);
        for(auto i:s){
            ans.emplace_back(i);
        }
        return ans;
    }
};